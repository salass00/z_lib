/* Automatically generated header (sfdc 1.11e)! Do not edit! */

#ifndef CLIB_Z_PROTOS_H
#define CLIB_Z_PROTOS_H

/*
**   $VER: z_protos.h 1.0 (14.02.2008)
**
**   C prototypes. For use with 32 bit integers only.
**
**   Copyright (c) 2001 Amiga, Inc.
**       All Rights Reserved
*/

#include <exec/types.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

CONST_STRPTR ZlibVersion(void);
LONG DeflateInit(z_streamp strm, LONG level);
LONG Deflate(z_streamp strm, LONG flush);
LONG DeflateEnd(z_streamp strm);
LONG InflateInit(z_streamp strm);
LONG Inflate(z_streamp strm, LONG flush);
LONG InflateEnd(z_streamp strm);
LONG DeflateInit2(z_streamp strm, LONG level, LONG method, LONG windowBits, LONG memLevel, LONG strategy);
LONG DeflateSetDictionary(z_streamp strm, CONST_APTR dictionary, ULONG dictLength);
LONG DeflateCopy(z_streamp dest, z_streamp source);
LONG DeflateReset(z_streamp strm);
LONG DeflateParams(z_streamp strm, LONG level, LONG strategy);
LONG InflateInit2(z_streamp strm, LONG windowBits);
LONG InflateSetDictionary(z_streamp strm, CONST_APTR dictionary, ULONG dictLength);
LONG InflateReset(z_streamp strm);
LONG Compress(APTR dest, ULONG * destLen, CONST_APTR source, ULONG sourceLen);
LONG Uncompress(APTR dest, ULONG * destLen, CONST_APTR source, ULONG sourceLen);
ULONG Adler32(ULONG adler, CONST_APTR buf, ULONG len);
ULONG CRC32(ULONG crc, CONST_APTR buf, ULONG len);
LONG InflateSync(z_streamp strm);
LONG DeflateTune(z_streamp strm, LONG good_length, LONG max_lazy, LONG nice_length, LONG max_chain);
ULONG DeflateBound(z_streamp strm, ULONG sourceLen);
LONG DeflatePrime(z_streamp strm, LONG bits, LONG value);
LONG DeflateSetHeader(z_streamp strm, gz_headerp head);
LONG InflateCopy(z_streamp dest, z_streamp source);
LONG InflatePrime(z_streamp strm, LONG bits, LONG value);
LONG InflateGetHeader(z_streamp strm, gz_headerp head);
LONG InflateBackInit(z_streamp strm, LONG windowBits, UBYTE * window);
LONG InflateBack(z_streamp strm, in_func in, void * in_desc, out_func out, void * out_desc);
LONG InflateBackEnd(z_streamp strm);
ULONG Adler32Combine(ULONG adler1, ULONG adler2, LONG len2);
ULONG CRC32Combine(ULONG crc1, ULONG crc2, LONG len2);
LONG Compress2(APTR dest, ULONG * destLen, CONST_APTR source, ULONG sourceLen, LONG level);
ULONG CompressBound(ULONG sourceLen);
LONG InflateGetDictionary(z_streamp strm, UBYTE * dictionary, ULONG * dictLength);
CONST_STRPTR ZError(LONG err);
LONG Uncompress2(APTR dest, ULONG * destLen, CONST_APTR source, ULONG * sourceLen);
LONG InflateReset2(z_streamp strm, LONG windowBits);
LONG InflateValidate(z_streamp strm, LONG check);
ULONG CRC32CombineGen(LONG len2);
ULONG CRC32CombineOp(ULONG crc1, ULONG crc2, ULONG op);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CLIB_Z_PROTOS_H */
