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

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef DOS_DOS_H
#include <dos/dos.h>
#endif
#ifndef LIBRARIES_Z_H
#include <libraries/z.h>
#endif

#ifdef __AROS__

#include <aros/libcall.h>

AROS_LD1(struct ZBase *, LibOpen,
	AROS_LPA(ULONG, version, D0),
	struct ZBase *, libBase, 1, Zlib);
AROS_LD0(BPTR, LibClose,
	struct ZBase *, libBase, 2, Zlib);
AROS_LD0(BPTR, LibExpunge,
	struct ZBase *, libBase, 3, Zlib);
AROS_LD0(APTR, LibReserved,
	struct ZBase *, libBase, 4, Zlib);
AROS_LD0(const char *, ZlibVersion,
	struct ZBase *, libBase, 5, Zlib);
AROS_LD2(LONG, DeflateInit,
	AROS_LPA(z_streamp, strm, A0),
	AROS_LPA(LONG, level, D0),
	struct ZBase *, libBase, 6, Zlib);
AROS_LD2(LONG, Deflate,
	AROS_LPA(z_streamp, strm, A0),
	AROS_LPA(LONG, flush, D0),
	struct ZBase *, libBase, 7, Zlib);
AROS_LD1(LONG, DeflateEnd,
	AROS_LPA(z_streamp, strm, A0),
	struct ZBase *, libBase, 8, Zlib);
AROS_LD1(LONG, InflateInit,
	AROS_LPA(z_streamp, strm, A0),
	struct ZBase *, libBase, 9, Zlib);
AROS_LD2(LONG, Inflate,
	AROS_LPA(z_streamp, strm, A0),
	AROS_LPA(LONG, flush, D0),
	struct ZBase *, libBase, 10, Zlib);
AROS_LD1(LONG, InflateEnd,
	AROS_LPA(z_streamp, strm, A0),
	struct ZBase *, libBase, 11, Zlib);
AROS_LD6(LONG, DeflateInit2,
	AROS_LPA(z_streamp, strm, A0),
	AROS_LPA(LONG, level, D0),
	AROS_LPA(LONG, method, D1),
	AROS_LPA(LONG, windowBits, D2),
	AROS_LPA(LONG, memLevel, D3),
	AROS_LPA(LONG, strategy, D4),
	struct ZBase *, libBase, 12, Zlib);
AROS_LD3(LONG, DeflateSetDictionary,
	AROS_LPA(z_streamp, strm, A0),
	AROS_LPA(APTR, dictionary, A1),
	AROS_LPA(ULONG, dictLength, D0),
	struct ZBase *, libBase, 13, Zlib);
AROS_LD2(LONG, DeflateCopy,
	AROS_LPA(z_streamp, dest, A0),
	AROS_LPA(z_streamp, source, A1),
	struct ZBase *, libBase, 14, Zlib);
AROS_LD1(LONG, DeflateReset,
	AROS_LPA(z_streamp, strm, A0),
	struct ZBase *, libBase, 15, Zlib);
AROS_LD3(LONG, DeflateParams,
	AROS_LPA(z_streamp, strm, A0),
	AROS_LPA(LONG, level, D0),
	AROS_LPA(LONG, strategy, D1),
	struct ZBase *, libBase, 16, Zlib);
AROS_LD2(LONG, InflateInit2,
	AROS_LPA(z_streamp, strm, A0),
	AROS_LPA(LONG, windowBits, D0),
	struct ZBase *, libBase, 17, Zlib);
AROS_LD3(LONG, InflateSetDictionary,
	AROS_LPA(z_streamp, strm, A0),
	AROS_LPA(APTR, dictionary, A1),
	AROS_LPA(ULONG, dictLength, D0),
	struct ZBase *, libBase, 18, Zlib);
AROS_LD1(LONG, InflateReset,
	AROS_LPA(z_streamp, strm, A0),
	struct ZBase *, libBase, 19, Zlib);
AROS_LD4(LONG, Compress,
	AROS_LPA(APTR, dest, A0),
	AROS_LPA(ULONG *, destLen, A1),
	AROS_LPA(APTR, source, A2),
	AROS_LPA(ULONG, sourceLen, D0),
	struct ZBase *, libBase, 20, Zlib);
AROS_LD4(LONG, Uncompress,
	AROS_LPA(APTR, dest, A0),
	AROS_LPA(ULONG *, destLen, A1),
	AROS_LPA(APTR, source, A2),
	AROS_LPA(ULONG, sourceLen, D0),
	struct ZBase *, libBase, 21, Zlib);
AROS_LD3(ULONG, Adler32,
	AROS_LPA(ULONG, adler, D0),
	AROS_LPA(APTR, buf, A0),
	AROS_LPA(ULONG, len, D1),
	struct ZBase *, libBase, 22, Zlib);
AROS_LD3(ULONG, CRC32,
	AROS_LPA(ULONG, crc, D0),
	AROS_LPA(APTR, buf, A0),
	AROS_LPA(ULONG, len, D1),
	struct ZBase *, libBase, 23, Zlib);
AROS_LD1(LONG, InflateSync,
	AROS_LPA(z_streamp, strm, A0),
	struct ZBase *, libBase, 24, Zlib);

#else

#include <SDI/SDI_compiler.h>

struct ZBase *Zlib_LibOpen (REG(a6, struct ZBase *libBase), REG(d0, ULONG version));
BPTR Zlib_LibClose (REG(a6, struct ZBase *libBase));
BPTR Zlib_LibExpunge (REG(a6, struct ZBase *libBase));
APTR Zlib_LibReserved (REG(a6, struct ZBase *libBase));
const char *Zlib_ZlibVersion(void);
LONG Zlib_DeflateInit(REG(a0, z_streamp strm), REG(d0, LONG level));
LONG Zlib_Deflate(REG(a0, z_streamp strm), REG(d0, LONG flush));
LONG Zlib_DeflateEnd(REG(a0, z_streamp strm));
LONG Zlib_InflateInit(REG(a0, z_streamp strm));
LONG Zlib_Inflate(REG(a0, z_streamp strm), REG(d0, LONG flush));
LONG Zlib_InflateEnd(REG(a0, z_streamp strm));
LONG Zlib_DeflateInit2(REG(a0, z_streamp strm), REG(d0, LONG level), REG(d1, LONG method),
	REG(d2, LONG windowBits), REG(d3, LONG memLevel), REG(d4, LONG strategy));
LONG Zlib_DeflateSetDictionary(REG(a0, z_streamp strm), REG(a1, APTR dictionary),
	REG(d0, ULONG dictLength));
LONG Zlib_DeflateCopy(REG(a0, z_streamp dest), REG(a1, z_streamp source));
LONG Zlib_DeflateReset(REG(a0, z_streamp strm));
LONG Zlib_DeflateParams(REG(a0, z_streamp strm), REG(d0, LONG level), REG(d1, LONG strategy));
LONG Zlib_InflateInit2(REG(a0, z_streamp strm), REG(d0, LONG windowBits));
LONG Zlib_InflateSetDictionary(REG(a0, z_streamp strm), REG(a1, APTR dictionary),
	REG(d0, ULONG dictLength));
LONG Zlib_InflateReset(REG(a0, z_streamp strm));
LONG Zlib_Compress(REG(a0, APTR dest), REG(a1, ULONG *destLen), REG(a2, APTR source),
	REG(d0, ULONG sourceLen));
LONG Zlib_Uncompress(REG(a0, APTR dest), REG(a1, ULONG *destLen), REG(a2, APTR source),
	REG(d0, ULONG sourceLen));
ULONG Zlib_Adler32(REG(d0, ULONG adler), REG(a0, APTR buf), REG(d1, ULONG len));
ULONG Zlib_CRC32(REG(d0, ULONG crc), REG(a0, APTR buf), REG(d1, ULONG len));
LONG Zlib_InflateSync(REG(a0, z_streamp strm));

#endif

