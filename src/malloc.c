/*
 * Zlib implemented as an AmigaOS shared library
 *
 * Copyright (C) 2007-2023 Fredrik Wikstrom <fredrik@a500.org>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS `AS IS'
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include <proto/exec.h>
#include <stdlib.h>
#include <stdint.h> /* For SIZE_MAX */
#include <string.h>
#include <SDI/SDI_compiler.h>

#ifdef __VBCC__
#define bzero(ptr,size) memset(ptr, 0, size)
#endif

#define BASE_PTR(ptr) ((void *)((size_t *)ptr - 1))
#define ALLOC_SIZE(ptr) (*((size_t *)ptr - 1))

static struct SignalSemaphore LibPoolSemaphore;
static APTR LibPool;

int malloc_init(void) {
	InitSemaphore(&LibPoolSemaphore);
	LibPool = CreatePool(MEMF_ANY, 4096, 1024);
	if (LibPool == NULL)
		return FALSE;
	return TRUE;
}

void malloc_exit(void) {
	DeletePool(LibPool);
}

STDARGS void *malloc(size_t size) {
	size_t *ptr;
	if (size > (SIZE_MAX - sizeof(size_t))) {
		return NULL;
	}
	ObtainSemaphore(&LibPoolSemaphore);
	ptr = AllocPooled(LibPool, sizeof(size_t) + size);
	ReleaseSemaphore(&LibPoolSemaphore);
	if (ptr) {
		*ptr++ = size;
	}
	return ptr;
}

STDARGS void *calloc(size_t num, size_t es) {
	size_t size = num * es;
	void *ptr;
	if (num != 0 && es != 0 && (size / es) != num) {
		return NULL;
	}
	ptr = malloc(size);
	if (ptr != NULL) {
		bzero(ptr, size);
	}
	return ptr;
}

STDARGS void free(void *ptr) {
	if (ptr) {
		ObtainSemaphore(&LibPoolSemaphore);
		FreePooled(LibPool, BASE_PTR(ptr), sizeof(size_t) + ALLOC_SIZE(ptr));
		ReleaseSemaphore(&LibPoolSemaphore);
	}
}
