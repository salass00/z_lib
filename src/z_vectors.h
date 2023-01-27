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
AROS_LD0(CONST_STRPTR, ZlibVersion,
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
AROS_LD5(LONG, DeflateTune,
	AROS_LPA(z_streamp, strm, A0),
	AROS_LPA(LONG, good_length, D0),
	AROS_LPA(LONG, max_lazy, D1),
	AROS_LPA(LONG, nice_length, D2),
	AROS_LPA(LONG, max_chain, D3),
	struct ZBase *, libBase, 25, Zlib);
AROS_LD2(ULONG, DeflateBound,
	AROS_LPA(z_streamp, strm, A0),
	AROS_LPA(ULONG, sourceLen, D0),
	struct ZBase *, libBase, 26, Zlib);
AROS_LD3(LONG, DeflatePrime,
	AROS_LPA(z_streamp, strm, A0),
	AROS_LPA(LONG, bits, D0),
	AROS_LPA(LONG, value, D1),
	struct ZBase *, libBase, 27, Zlib);
AROS_LD2(LONG, DeflateSetHeader,
	AROS_LPA(z_streamp, strm, A0),
	AROS_LPA(gz_headerp, head, A1),
	struct ZBase *, libBase, 28, Zlib);
AROS_LD2(LONG, InflateCopy,
	AROS_LPA(z_streamp, dest, A0),
	AROS_LPA(z_streamp, source, A1),
	struct ZBase *, libBase, 29, Zlib);
AROS_LD3(LONG, InflatePrime,
	AROS_LPA(z_streamp, strm, A0),
	AROS_LPA(LONG, bits, D0),
	AROS_LPA(LONG, value, D1),
	struct ZBase *, libBase, 30, Zlib);
AROS_LD2(LONG, InflateGetHeader,
	AROS_LPA(z_streamp, strm, A0),
	AROS_LPA(gz_headerp, head, A1),
	struct ZBase *, libBase, 31, Zlib);
AROS_LD3(LONG, InflateBackInit,
	AROS_LPA(z_streamp, strm, A0),
	AROS_LPA(LONG, windowBits, d0),
	AROS_LPA(UBYTE *, window, A1),
	struct ZBase *, libBase, 32, Zlib);
AROS_LD5(LONG, InflateBack,
	AROS_LPA(z_streamp, strm, A0),
	AROS_LPA(in_func, in, A1),
	AROS_LPA(void *, in_desc, D0),
	AROS_LPA(out_func, out, A2),
	AROS_LPA(void *, out_desc, D1),
	struct ZBase *, libBase, 33, Zlib);
AROS_LD1(LONG, InflateBackEnd,
	AROS_LPA(z_streamp, strm, A0),
	struct ZBase *, libBase, 34, Zlib);
AROS_LD3(ULONG, Adler32Combine,
	AROS_LPA(ULONG, adler1, D0),
	AROS_LPA(ULONG, adler2, D1),
	AROS_LPA(LONG, len2, D2),
	struct ZBase *, libBase, 35, Zlib);
AROS_LD3(ULONG, CRC32Combine,
	AROS_LPA(ULONG, crc1, D0),
	AROS_LPA(ULONG, crc2, D1),
	AROS_LPA(LONG, len2, D2),
	struct ZBase *, libBase, 36, Zlib);
AROS_LD5(LONG, Compress2,
	AROS_LPA(APTR, dest, A0),
	AROS_LPA(ULONG *, destLen, A1),
	AROS_LPA(CONST_APTR, source, A2),
	AROS_LPA(ULONG, sourceLen, D0),
	AROS_LPA(LONG, level, D1),
	struct ZBase *, libBase, 37, Zlib);
AROS_LD1(ULONG, CompressBound,
	AROS_LPA(ULONG, sourceLen, D0),
	struct ZBase *, libBase, 38, Zlib);
AROS_LD3(LONG, InflateGetDictionary,
	AROS_LPA(z_streamp, strm, A0),
	AROS_LPA(UBYTE *, dictionary, A1),
	AROS_LPA(ULONG *, dictLength, A2),
	struct ZBase *, libBase, 39, Zlib);
AROS_LD1(CONST_STRPTR, ZError,
	AROS_LPA(LONG, err, D0),
	struct ZBase *, libBase, 40, Zlib);
AROS_LD4(LONG, Uncompress2,
	AROS_LPA(APTR, dest, A0),
	AROS_LPA(ULONG *, destLen, A1),
	AROS_LPA(CONST_APTR, source, A2),
	AROS_LPA(ULONG *, sourceLen, A3),
	struct ZBase *, libBase, 41, Zlib);
AROS_LD2(LONG, InflateReset2,
	AROS_LPA(z_streamp, strm, A0),
	AROS_LPA(LONG, windowBits, D0),
	struct ZBase *, libBase, 42, Zlib);
AROS_LD2(LONG, InflateValidate,
	AROS_LPA(z_streamp, strm, A0),
	AROS_LPA(LONG, check, D0),
	struct ZBase *, libBase, 43, Zlib);
AROS_LD1(ULONG, CRC32CombineGen,
	AROS_LPA(LONG, len2, D0),
	struct ZBase *, libBase, 44, Zlib);
AROS_LD3(ULONG, CRC32CombineOp,
	AROS_LPA(ULONG, crc1, D0),
	AROS_LPA(ULONG, crc2, D1),
	AROS_LPA(ULONG, op, D2),
	struct ZBase *, libBase, 45, Zlib);

#else

#include <SDI/SDI_compiler.h>

struct ZBase *Zlib_LibOpen (REG(a6, struct ZBase *libBase), REG(d0, ULONG version));
BPTR Zlib_LibClose (REG(a6, struct ZBase *libBase));
BPTR Zlib_LibExpunge (REG(a6, struct ZBase *libBase));
APTR Zlib_LibReserved (REG(a6, struct ZBase *libBase));
CONST_STRPTR Zlib_ZlibVersion(void);
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
LONG Zlib_DeflateTune(REG(a0, z_streamp strm), REG(d0, LONG good_length), REG(d1, LONG max_lazy),
	REG(d2, LONG nice_length), REG(d3, LONG max_chain));
ULONG Zlib_DeflateBound(REG(a0, z_streamp strm), REG(d0, ULONG sourceLen));
LONG Zlib_DeflatePrime(REG(a0, z_streamp strm), REG(d0, LONG bits), REG(d1, LONG value));
LONG Zlib_DeflateSetHeader(REG(a0, z_streamp strm), REG(a1, gz_headerp head));
LONG Zlib_InflateCopy(REG(a0, z_streamp dest), REG(a1, z_streamp source));
LONG Zlib_InflatePrime(REG(a0, z_streamp strm), REG(d0, LONG bits), REG(d1, LONG value));
LONG Zlib_InflateGetHeader(REG(a0, z_streamp strm), REG(a1, gz_headerp head));
LONG Zlib_InflateBackInit(REG(a0, z_streamp strm), REG(d0, LONG windowBits), REG(a1, UBYTE *window));
LONG Zlib_InflateBack(REG(a0, z_streamp strm), REG(a1, in_func in), REG(d0, void *in_desc),
	REG(a2, out_func out), REG(d1, void *out_desc));
LONG Zlib_InflateBackEnd(REG(a0, z_streamp strm));
ULONG Zlib_Adler32Combine(REG(d0, ULONG adler1), REG(d1, ULONG adler2), REG(d2, LONG len2));
ULONG Zlib_CRC32Combine(REG(d0, ULONG crc1), REG(d1, ULONG crc2), REG(d2, LONG len2));
LONG Zlib_Compress2(REG(a0, APTR dest), REG(a1, ULONG *destLen), REG(a2, CONST_APTR source),
	REG(d0, ULONG sourceLen), REG(d1, LONG level));
ULONG Zlib_CompressBound(REG(d0, ULONG sourceLen));
LONG Zlib_InflateGetDictionary(REG(a0, z_streamp strm), REG(a1, UBYTE *dictionary),
	REG(a2, ULONG *dictLength));
CONST_STRPTR Zlib_ZError(REG(d0, LONG err));
LONG Zlib_Uncompress2(REG(a0, APTR dest), REG(a1, ULONG *destLen), REG(a2, CONST_APTR source),
	REG(a3, ULONG *sourceLen));
LONG Zlib_InflateReset2(REG(a0, z_streamp strm), REG(d0, LONG windowBits));
LONG Zlib_InflateValidate(REG(a0, z_streamp strm), REG(d0, LONG check));
ULONG Zlib_CRC32CombineGen(REG(d0, LONG len2));
ULONG Zlib_CRC32CombineOp(REG(d0, ULONG crc1), REG(d1, ULONG crc2), REG(d2, ULONG op));

#endif

