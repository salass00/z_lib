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

#define LIBRARIES_Z_H
#include <exec/exec.h>
#include <dos/dos.h>
#include <proto/exec.h>
#include <zlib.h>
#include <SDI/SDI_compiler.h>

#include "zbase.h"
#include "z.library_rev.h"

static const char USED_VAR verstag[] = VERSTAG;

#ifndef __AROS__
#define IPTR ULONG
#endif

struct ExecBase *SysBase;

extern int malloc_init(void);
extern void malloc_exit(void);

#ifdef __AROS__
static AROS_UFP3(struct ZBase *, LibInit,
	AROS_UFPA(struct ZBase *, libBase, D0),
	AROS_UFPA(BPTR, seglist, A0),
	AROS_UFPA(struct ExecBase *, exec_base, A6)
);
#else
static struct ZBase *LibInit (REG(d0, struct ZBase *libBase), REG(a0, BPTR seglist),
	REG(a6, struct ExecBase *exec_base));
#endif

#include "z_vectors.c"

const IPTR LibInitTab[] = {
	sizeof(struct ZBase),
	(IPTR)LibVectors,
	(IPTR)NULL,
	(IPTR)LibInit
};

const struct Resident USED_VAR ROMTag = {
	RTC_MATCHWORD,
	(struct Resident *)&ROMTag,
	(APTR)(&ROMTag + 1),
	RTF_AUTOINIT,
	VERSION,
	NT_LIBRARY,
	0,
	(STRPTR)LIBNAME,
	(STRPTR)VSTRING,
	(APTR)LibInitTab
};

static void DeleteLibrary(struct Library *lib)
{
	if (lib == NULL)
		return;

	FreeMem((BYTE *)lib - lib->lib_NegSize, lib->lib_NegSize + lib->lib_PosSize);
}

#ifdef __AROS__
static AROS_UFH3(struct ZBase *, LibInit,
	AROS_UFHA(struct ZBase *, libBase, D0),
	AROS_UFHA(BPTR, seglist, A0),
	AROS_UFHA(struct ExecBase *, exec_base, A6)
)
{
	AROS_USERFUNC_INIT
#else
static struct ZBase *LibInit (REG(d0, struct ZBase *libBase), REG(a0, BPTR seglist),
	REG(a6, struct ExecBase *exec_base))
{
#endif
	libBase->libNode.lib_Node.ln_Type = NT_LIBRARY;
	libBase->libNode.lib_Node.ln_Pri  = 0;
	libBase->libNode.lib_Node.ln_Name = LIBNAME;
	libBase->libNode.lib_Flags        = LIBF_SUMUSED|LIBF_CHANGED;
	libBase->libNode.lib_Version      = VERSION;
	libBase->libNode.lib_Revision     = REVISION;
	libBase->libNode.lib_IdString     = VSTRING;

	libBase->seglist = seglist;
	SysBase = exec_base;

	if (malloc_init()) {
#ifdef DYNAMIC_CRC_TABLE
		get_crc_table();
#endif
		return libBase;
	}

	DeleteLibrary((struct Library *)libBase);

	return NULL;
#ifdef __AROS__
	AROS_USERFUNC_EXIT
#endif
}

#ifdef __AROS__
AROS_LH1(struct ZBase *, LibOpen,
	AROS_LHA(ULONG, version, D0),
	struct ZBase *, libBase, 1, Zlib
)
{
	AROS_LIBFUNC_INIT
#else
struct ZBase *Zlib_LibOpen (REG(a6, struct ZBase *libBase), REG(d0, ULONG version)) {
#endif
	libBase->libNode.lib_OpenCnt++;
	libBase->libNode.lib_Flags &= ~LIBF_DELEXP;
	return libBase;
#ifdef __AROS__
	AROS_LIBFUNC_EXIT
#endif
}

#ifdef __AROS__
AROS_LH0(BPTR, LibClose,
	struct ZBase *, libBase, 2, Zlib
)
{
	AROS_LIBFUNC_INIT
#else
BPTR Zlib_LibClose (REG(a6, struct ZBase *libBase)) {
#endif
	libBase->libNode.lib_OpenCnt--;
	return 0;
#ifdef __AROS__
	AROS_LIBFUNC_EXIT
#endif
}

#ifdef __AROS__
AROS_LH0(BPTR, LibExpunge,
	struct ZBase *, libBase, 3, Zlib
)
{
	AROS_LIBFUNC_INIT
#else
BPTR Zlib_LibExpunge (REG(a6, struct ZBase *libBase)) {
#endif
	BPTR result = 0;

	if (libBase->libNode.lib_OpenCnt > 0) {
		libBase->libNode.lib_Flags |= LIBF_DELEXP;
		return 0;
	}

	Remove(&libBase->libNode.lib_Node);

	result = libBase->seglist;

	malloc_exit();

	DeleteLibrary((struct Library *)libBase);

	return result;
#ifdef __AROS__
	AROS_LIBFUNC_EXIT
#endif
}

#ifdef __AROS__
AROS_LH0(APTR, LibReserved,
	struct ZBase *, libBase, 4, Zlib
)
{
	AROS_LIBFUNC_INIT
	return NULL;
	AROS_LIBFUNC_EXIT
}
#else
APTR Zlib_LibReserved (REG(a6, struct ZBase *libBase)) {
	return NULL;
}
#endif

