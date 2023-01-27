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
#include <zlib.h>
#include "../z_vectors.h"

#ifdef __AROS__
AROS_LH3(ULONG, Adler32Combine,
	AROS_LHA(ULONG, adler1, D0),
	AROS_LHA(ULONG, adler2, D1),
	AROS_LHA(LONG, len2, D2),
	struct ZBase *, libBase, 35, Zlib)
{
	AROS_LIBFUNC_INIT
#else
ULONG Zlib_Adler32Combine(REG(d0, ULONG adler1), REG(d1, ULONG adler2), REG(d2, LONG len2))
{
#endif
	return adler32_combine(adler1, adler2, len2);
#ifdef __AROS__
	AROS_LIBFUNC_EXIT
#endif
}

