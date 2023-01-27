/* Automatically generated header (sfdc 1.11e)! Do not edit! */

#ifndef _INLINE_Z_H
#define _INLINE_Z_H

#ifndef _SFDC_VARARG_DEFINED
#define _SFDC_VARARG_DEFINED
#ifdef __HAVE_IPTR_ATTR__
typedef APTR _sfdc_vararg __attribute__((iptr));
#else
typedef ULONG _sfdc_vararg;
#endif /* __HAVE_IPTR_ATTR__ */
#endif /* _SFDC_VARARG_DEFINED */

#ifndef AROS_LIBCALL_H
#include <aros/libcall.h>
#endif /* !AROS_LIBCALL_H */

#ifndef Z_BASE_NAME
#define Z_BASE_NAME ZBase
#endif /* !Z_BASE_NAME */

#define ZlibVersion() \
      AROS_LC0(CONST_STRPTR, ZlibVersion, \
     struct Library *, Z_BASE_NAME, 5, Z)

#define DeflateInit(___strm, ___level) \
      AROS_LC2(LONG, DeflateInit, \
 AROS_LCA(z_streamp, (___strm), A0), \
 AROS_LCA(LONG, (___level), D0), \
     struct Library *, Z_BASE_NAME, 6, Z)

#define Deflate(___strm, ___flush) \
      AROS_LC2(LONG, Deflate, \
 AROS_LCA(z_streamp, (___strm), A0), \
 AROS_LCA(LONG, (___flush), D0), \
     struct Library *, Z_BASE_NAME, 7, Z)

#define DeflateEnd(___strm) \
      AROS_LC1(LONG, DeflateEnd, \
 AROS_LCA(z_streamp, (___strm), A0), \
     struct Library *, Z_BASE_NAME, 8, Z)

#define InflateInit(___strm) \
      AROS_LC1(LONG, InflateInit, \
 AROS_LCA(z_streamp, (___strm), A0), \
     struct Library *, Z_BASE_NAME, 9, Z)

#define Inflate(___strm, ___flush) \
      AROS_LC2(LONG, Inflate, \
 AROS_LCA(z_streamp, (___strm), A0), \
 AROS_LCA(LONG, (___flush), D0), \
     struct Library *, Z_BASE_NAME, 10, Z)

#define InflateEnd(___strm) \
      AROS_LC1(LONG, InflateEnd, \
 AROS_LCA(z_streamp, (___strm), A0), \
     struct Library *, Z_BASE_NAME, 11, Z)

#define DeflateInit2(___strm, ___level, ___method, ___windowBits, ___memLevel, ___strategy) \
      AROS_LC6(LONG, DeflateInit2, \
 AROS_LCA(z_streamp, (___strm), A0), \
 AROS_LCA(LONG, (___level), D0), \
 AROS_LCA(LONG, (___method), D1), \
 AROS_LCA(LONG, (___windowBits), D2), \
 AROS_LCA(LONG, (___memLevel), D3), \
 AROS_LCA(LONG, (___strategy), D4), \
     struct Library *, Z_BASE_NAME, 12, Z)

#define DeflateSetDictionary(___strm, ___dictionary, ___dictLength) \
      AROS_LC3(LONG, DeflateSetDictionary, \
 AROS_LCA(z_streamp, (___strm), A0), \
 AROS_LCA(CONST_APTR, (___dictionary), A1), \
 AROS_LCA(ULONG, (___dictLength), D0), \
     struct Library *, Z_BASE_NAME, 13, Z)

#define DeflateCopy(___dest, ___source) \
      AROS_LC2(LONG, DeflateCopy, \
 AROS_LCA(z_streamp, (___dest), A0), \
 AROS_LCA(z_streamp, (___source), A1), \
     struct Library *, Z_BASE_NAME, 14, Z)

#define DeflateReset(___strm) \
      AROS_LC1(LONG, DeflateReset, \
 AROS_LCA(z_streamp, (___strm), A0), \
     struct Library *, Z_BASE_NAME, 15, Z)

#define DeflateParams(___strm, ___level, ___strategy) \
      AROS_LC3(LONG, DeflateParams, \
 AROS_LCA(z_streamp, (___strm), A0), \
 AROS_LCA(LONG, (___level), D0), \
 AROS_LCA(LONG, (___strategy), D1), \
     struct Library *, Z_BASE_NAME, 16, Z)

#define InflateInit2(___strm, ___windowBits) \
      AROS_LC2(LONG, InflateInit2, \
 AROS_LCA(z_streamp, (___strm), A0), \
 AROS_LCA(LONG, (___windowBits), D0), \
     struct Library *, Z_BASE_NAME, 17, Z)

#define InflateSetDictionary(___strm, ___dictionary, ___dictLength) \
      AROS_LC3(LONG, InflateSetDictionary, \
 AROS_LCA(z_streamp, (___strm), A0), \
 AROS_LCA(CONST_APTR, (___dictionary), A1), \
 AROS_LCA(ULONG, (___dictLength), D0), \
     struct Library *, Z_BASE_NAME, 18, Z)

#define InflateReset(___strm) \
      AROS_LC1(LONG, InflateReset, \
 AROS_LCA(z_streamp, (___strm), A0), \
     struct Library *, Z_BASE_NAME, 19, Z)

#define Compress(___dest, ___destLen, ___source, ___sourceLen) \
      AROS_LC4(LONG, Compress, \
 AROS_LCA(APTR, (___dest), A0), \
 AROS_LCA(ULONG *, (___destLen), A1), \
 AROS_LCA(CONST_APTR, (___source), A2), \
 AROS_LCA(ULONG, (___sourceLen), D0), \
     struct Library *, Z_BASE_NAME, 20, Z)

#define Uncompress(___dest, ___destLen, ___source, ___sourceLen) \
      AROS_LC4(LONG, Uncompress, \
 AROS_LCA(APTR, (___dest), A0), \
 AROS_LCA(ULONG *, (___destLen), A1), \
 AROS_LCA(CONST_APTR, (___source), A2), \
 AROS_LCA(ULONG, (___sourceLen), D0), \
     struct Library *, Z_BASE_NAME, 21, Z)

#define Adler32(___adler, ___buf, ___len) \
      AROS_LC3(ULONG, Adler32, \
 AROS_LCA(ULONG, (___adler), D0), \
 AROS_LCA(CONST_APTR, (___buf), A0), \
 AROS_LCA(ULONG, (___len), D1), \
     struct Library *, Z_BASE_NAME, 22, Z)

#define CRC32(___crc, ___buf, ___len) \
      AROS_LC3(ULONG, CRC32, \
 AROS_LCA(ULONG, (___crc), D0), \
 AROS_LCA(CONST_APTR, (___buf), A0), \
 AROS_LCA(ULONG, (___len), D1), \
     struct Library *, Z_BASE_NAME, 23, Z)

#define InflateSync(___strm) \
      AROS_LC1(LONG, InflateSync, \
 AROS_LCA(z_streamp, (___strm), A0), \
     struct Library *, Z_BASE_NAME, 24, Z)

#define DeflateTune(___strm, ___good_length, ___max_lazy, ___nice_length, ___max_chain) \
      AROS_LC5(LONG, DeflateTune, \
 AROS_LCA(z_streamp, (___strm), A0), \
 AROS_LCA(LONG, (___good_length), D0), \
 AROS_LCA(LONG, (___max_lazy), D1), \
 AROS_LCA(LONG, (___nice_length), D2), \
 AROS_LCA(LONG, (___max_chain), D3), \
     struct Library *, Z_BASE_NAME, 25, Z)

#define DeflateBound(___strm, ___sourceLen) \
      AROS_LC2(ULONG, DeflateBound, \
 AROS_LCA(z_streamp, (___strm), A0), \
 AROS_LCA(ULONG, (___sourceLen), D0), \
     struct Library *, Z_BASE_NAME, 26, Z)

#define DeflatePrime(___strm, ___bits, ___value) \
      AROS_LC3(LONG, DeflatePrime, \
 AROS_LCA(z_streamp, (___strm), A0), \
 AROS_LCA(LONG, (___bits), D0), \
 AROS_LCA(LONG, (___value), D1), \
     struct Library *, Z_BASE_NAME, 27, Z)

#define DeflateSetHeader(___strm, ___head) \
      AROS_LC2(LONG, DeflateSetHeader, \
 AROS_LCA(z_streamp, (___strm), A0), \
 AROS_LCA(gz_headerp, (___head), A1), \
     struct Library *, Z_BASE_NAME, 28, Z)

#define InflateCopy(___dest, ___source) \
      AROS_LC2(LONG, InflateCopy, \
 AROS_LCA(z_streamp, (___dest), A0), \
 AROS_LCA(z_streamp, (___source), A1), \
     struct Library *, Z_BASE_NAME, 29, Z)

#define InflatePrime(___strm, ___bits, ___value) \
      AROS_LC3(LONG, InflatePrime, \
 AROS_LCA(z_streamp, (___strm), A0), \
 AROS_LCA(LONG, (___bits), D0), \
 AROS_LCA(LONG, (___value), D1), \
     struct Library *, Z_BASE_NAME, 30, Z)

#define InflateGetHeader(___strm, ___head) \
      AROS_LC2(LONG, InflateGetHeader, \
 AROS_LCA(z_streamp, (___strm), A0), \
 AROS_LCA(gz_headerp, (___head), A1), \
     struct Library *, Z_BASE_NAME, 31, Z)

#define InflateBackInit(___strm, ___windowBits, ___window) \
      AROS_LC3(LONG, InflateBackInit, \
 AROS_LCA(z_streamp, (___strm), A0), \
 AROS_LCA(LONG, (___windowBits), D0), \
 AROS_LCA(UBYTE *, (___window), A1), \
     struct Library *, Z_BASE_NAME, 32, Z)

#define InflateBack(___strm, ___in, ___in_desc, ___out, ___out_desc) \
      AROS_LC5(LONG, InflateBack, \
 AROS_LCA(z_streamp, (___strm), A0), \
 AROS_LCA(in_func, (___in), A1), \
 AROS_LCA(void *, (___in_desc), D0), \
 AROS_LCA(out_func, (___out), A2), \
 AROS_LCA(void *, (___out_desc), D1), \
     struct Library *, Z_BASE_NAME, 33, Z)

#define InflateBackEnd(___strm) \
      AROS_LC1(LONG, InflateBackEnd, \
 AROS_LCA(z_streamp, (___strm), A0), \
     struct Library *, Z_BASE_NAME, 34, Z)

#define Adler32Combine(___adler1, ___adler2, ___len2) \
      AROS_LC3(ULONG, Adler32Combine, \
 AROS_LCA(ULONG, (___adler1), D0), \
 AROS_LCA(ULONG, (___adler2), D1), \
 AROS_LCA(LONG, (___len2), D2), \
     struct Library *, Z_BASE_NAME, 35, Z)

#define CRC32Combine(___crc1, ___crc2, ___len2) \
      AROS_LC3(ULONG, CRC32Combine, \
 AROS_LCA(ULONG, (___crc1), D0), \
 AROS_LCA(ULONG, (___crc2), D1), \
 AROS_LCA(LONG, (___len2), D2), \
     struct Library *, Z_BASE_NAME, 36, Z)

#define Compress2(___dest, ___destLen, ___source, ___sourceLen, ___level) \
      AROS_LC5(LONG, Compress2, \
 AROS_LCA(APTR, (___dest), A0), \
 AROS_LCA(ULONG *, (___destLen), A1), \
 AROS_LCA(CONST_APTR, (___source), A2), \
 AROS_LCA(ULONG, (___sourceLen), D0), \
 AROS_LCA(LONG, (___level), D1), \
     struct Library *, Z_BASE_NAME, 37, Z)

#define CompressBound(___sourceLen) \
      AROS_LC1(ULONG, CompressBound, \
 AROS_LCA(ULONG, (___sourceLen), D0), \
     struct Library *, Z_BASE_NAME, 38, Z)

#define InflateGetDictionary(___strm, ___dictionary, ___dictLength) \
      AROS_LC3(LONG, InflateGetDictionary, \
 AROS_LCA(z_streamp, (___strm), A0), \
 AROS_LCA(UBYTE *, (___dictionary), A1), \
 AROS_LCA(ULONG *, (___dictLength), A2), \
     struct Library *, Z_BASE_NAME, 39, Z)

#define ZError(___err) \
      AROS_LC1(CONST_STRPTR, ZError, \
 AROS_LCA(LONG, (___err), D0), \
     struct Library *, Z_BASE_NAME, 40, Z)

#define Uncompress2(___dest, ___destLen, ___source, ___sourceLen) \
      AROS_LC4(LONG, Uncompress2, \
 AROS_LCA(APTR, (___dest), A0), \
 AROS_LCA(ULONG *, (___destLen), A1), \
 AROS_LCA(CONST_APTR, (___source), A2), \
 AROS_LCA(ULONG *, (___sourceLen), A3), \
     struct Library *, Z_BASE_NAME, 41, Z)

#define InflateReset2(___strm, ___windowBits) \
      AROS_LC2(LONG, InflateReset2, \
 AROS_LCA(z_streamp, (___strm), A0), \
 AROS_LCA(LONG, (___windowBits), D0), \
     struct Library *, Z_BASE_NAME, 42, Z)

#define InflateValidate(___strm, ___check) \
      AROS_LC2(LONG, InflateValidate, \
 AROS_LCA(z_streamp, (___strm), A0), \
 AROS_LCA(LONG, (___check), D0), \
     struct Library *, Z_BASE_NAME, 43, Z)

#define CRC32CombineGen(___len2) \
      AROS_LC1(ULONG, CRC32CombineGen, \
 AROS_LCA(LONG, (___len2), D0), \
     struct Library *, Z_BASE_NAME, 44, Z)

#define CRC32CombineOp(___crc1, ___crc2, ___op) \
      AROS_LC3(ULONG, CRC32CombineOp, \
 AROS_LCA(ULONG, (___crc1), D0), \
 AROS_LCA(ULONG, (___crc2), D1), \
 AROS_LCA(ULONG, (___op), D2), \
     struct Library *, Z_BASE_NAME, 45, Z)

#endif /* !_INLINE_Z_H */
