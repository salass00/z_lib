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

#include "z_vectors.h"

#ifdef __AROS__
#define LIB_ENTRY(name,index) AROS_SLIB_ENTRY(name, Zlib, index)
#else
#define LIB_ENTRY(name,index) (Zlib_##name)
#endif

CONST_APTR LibVectors[] = {
	(APTR)LIB_ENTRY(LibOpen, 1),
	(APTR)LIB_ENTRY(LibClose, 2),
	(APTR)LIB_ENTRY(LibExpunge, 3),
	(APTR)LIB_ENTRY(LibReserved, 4),
	(APTR)LIB_ENTRY(ZlibVersion, 5),
	(APTR)LIB_ENTRY(DeflateInit, 6),
	(APTR)LIB_ENTRY(Deflate, 7),
	(APTR)LIB_ENTRY(DeflateEnd, 8),
	(APTR)LIB_ENTRY(InflateInit, 9),
	(APTR)LIB_ENTRY(Inflate, 10),
	(APTR)LIB_ENTRY(InflateEnd, 11),
	(APTR)LIB_ENTRY(DeflateInit2, 12),
	(APTR)LIB_ENTRY(DeflateSetDictionary, 13),
	(APTR)LIB_ENTRY(DeflateCopy, 14),
	(APTR)LIB_ENTRY(DeflateReset, 15),
	(APTR)LIB_ENTRY(DeflateParams, 16),
	(APTR)LIB_ENTRY(InflateInit2, 17),
	(APTR)LIB_ENTRY(InflateSetDictionary, 18),
	(APTR)LIB_ENTRY(InflateReset, 19),
	(APTR)LIB_ENTRY(Compress, 20),
	(APTR)LIB_ENTRY(Uncompress, 21),
	(APTR)LIB_ENTRY(Adler32, 22),
	(APTR)LIB_ENTRY(CRC32, 23),
	(APTR)LIB_ENTRY(InflateSync, 24),
	(APTR)LIB_ENTRY(DeflateTune, 25),
	(APTR)LIB_ENTRY(DeflateBound, 26),
	(APTR)LIB_ENTRY(DeflatePrime, 27),
	(APTR)LIB_ENTRY(DeflateSetHeader, 28),
	(APTR)LIB_ENTRY(InflateCopy, 29),
	(APTR)LIB_ENTRY(InflatePrime, 30),
	(APTR)LIB_ENTRY(InflateGetHeader, 31),
	(APTR)LIB_ENTRY(InflateBackInit, 32),
	(APTR)LIB_ENTRY(InflateBack, 33),
	(APTR)LIB_ENTRY(InflateBackEnd, 34),
	(APTR)LIB_ENTRY(Adler32Combine, 35),
	(APTR)LIB_ENTRY(CRC32Combine, 36),
	(APTR)LIB_ENTRY(Compress2, 37),
	(APTR)LIB_ENTRY(CompressBound, 38),
	(APTR)LIB_ENTRY(InflateGetDictionary, 39),
	(APTR)LIB_ENTRY(ZError, 40),
	(APTR)LIB_ENTRY(Uncompress2, 41),
	(APTR)LIB_ENTRY(InflateReset2, 42),
	(APTR)LIB_ENTRY(InflateValidate, 43),
	(APTR)LIB_ENTRY(CRC32CombineGen, 44),
	(APTR)LIB_ENTRY(CRC32CombineOp, 45),
	(APTR)-1
};

