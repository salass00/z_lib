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

#ifndef __INLINE_MACROS_H
#include <inline/macros.h>
#endif /* !__INLINE_MACROS_H */

#ifndef Z_BASE_NAME
#define Z_BASE_NAME ZBase
#endif /* !Z_BASE_NAME */

#define ZlibVersion() \
      LP0(0x1e, CONST_STRPTR, ZlibVersion ,\
      , Z_BASE_NAME)

#define DeflateInit(___strm, ___level) \
      LP2(0x24, LONG, DeflateInit , z_streamp, ___strm, a0, LONG, ___level, d0,\
      , Z_BASE_NAME)

#define Deflate(___strm, ___flush) \
      LP2(0x2a, LONG, Deflate , z_streamp, ___strm, a0, LONG, ___flush, d0,\
      , Z_BASE_NAME)

#define DeflateEnd(___strm) \
      LP1(0x30, LONG, DeflateEnd , z_streamp, ___strm, a0,\
      , Z_BASE_NAME)

#define InflateInit(___strm) \
      LP1(0x36, LONG, InflateInit , z_streamp, ___strm, a0,\
      , Z_BASE_NAME)

#define Inflate(___strm, ___flush) \
      LP2(0x3c, LONG, Inflate , z_streamp, ___strm, a0, LONG, ___flush, d0,\
      , Z_BASE_NAME)

#define InflateEnd(___strm) \
      LP1(0x42, LONG, InflateEnd , z_streamp, ___strm, a0,\
      , Z_BASE_NAME)

#define DeflateInit2(___strm, ___level, ___method, ___windowBits, ___memLevel, ___strategy) \
      LP6(0x48, LONG, DeflateInit2 , z_streamp, ___strm, a0, LONG, ___level, d0, LONG, ___method, d1, LONG, ___windowBits, d2, LONG, ___memLevel, d3, LONG, ___strategy, d4,\
      , Z_BASE_NAME)

#define DeflateSetDictionary(___strm, ___dictionary, ___dictLength) \
      LP3(0x4e, LONG, DeflateSetDictionary , z_streamp, ___strm, a0, CONST_APTR, ___dictionary, a1, ULONG, ___dictLength, d0,\
      , Z_BASE_NAME)

#define DeflateCopy(___dest, ___source) \
      LP2(0x54, LONG, DeflateCopy , z_streamp, ___dest, a0, z_streamp, ___source, a1,\
      , Z_BASE_NAME)

#define DeflateReset(___strm) \
      LP1(0x5a, LONG, DeflateReset , z_streamp, ___strm, a0,\
      , Z_BASE_NAME)

#define DeflateParams(___strm, ___level, ___strategy) \
      LP3(0x60, LONG, DeflateParams , z_streamp, ___strm, a0, LONG, ___level, d0, LONG, ___strategy, d1,\
      , Z_BASE_NAME)

#define InflateInit2(___strm, ___windowBits) \
      LP2(0x66, LONG, InflateInit2 , z_streamp, ___strm, a0, LONG, ___windowBits, d0,\
      , Z_BASE_NAME)

#define InflateSetDictionary(___strm, ___dictionary, ___dictLength) \
      LP3(0x6c, LONG, InflateSetDictionary , z_streamp, ___strm, a0, CONST_APTR, ___dictionary, a1, ULONG, ___dictLength, d0,\
      , Z_BASE_NAME)

#define InflateReset(___strm) \
      LP1(0x72, LONG, InflateReset , z_streamp, ___strm, a0,\
      , Z_BASE_NAME)

#define Compress(___dest, ___destLen, ___source, ___sourceLen) \
      LP4(0x78, LONG, Compress , APTR, ___dest, a0, ULONG *, ___destLen, a1, CONST_APTR, ___source, a2, ULONG, ___sourceLen, d0,\
      , Z_BASE_NAME)

#define Uncompress(___dest, ___destLen, ___source, ___sourceLen) \
      LP4(0x7e, LONG, Uncompress , APTR, ___dest, a0, ULONG *, ___destLen, a1, CONST_APTR, ___source, a2, ULONG, ___sourceLen, d0,\
      , Z_BASE_NAME)

#define Adler32(___adler, ___buf, ___len) \
      LP3(0x84, ULONG, Adler32 , ULONG, ___adler, d0, CONST_APTR, ___buf, a0, ULONG, ___len, d1,\
      , Z_BASE_NAME)

#define CRC32(___crc, ___buf, ___len) \
      LP3(0x8a, ULONG, CRC32 , ULONG, ___crc, d0, CONST_APTR, ___buf, a0, ULONG, ___len, d1,\
      , Z_BASE_NAME)

#define InflateSync(___strm) \
      LP1(0x90, LONG, InflateSync , z_streamp, ___strm, a0,\
      , Z_BASE_NAME)

#define DeflateTune(___strm, ___good_length, ___max_lazy, ___nice_length, ___max_chain) \
      LP5(0x96, LONG, DeflateTune , z_streamp, ___strm, a0, LONG, ___good_length, d0, LONG, ___max_lazy, d1, LONG, ___nice_length, d2, LONG, ___max_chain, d3,\
      , Z_BASE_NAME)

#define DeflateBound(___strm, ___sourceLen) \
      LP2(0x9c, ULONG, DeflateBound , z_streamp, ___strm, a0, ULONG, ___sourceLen, d0,\
      , Z_BASE_NAME)

#define DeflatePrime(___strm, ___bits, ___value) \
      LP3(0xa2, LONG, DeflatePrime , z_streamp, ___strm, a0, LONG, ___bits, d0, LONG, ___value, d1,\
      , Z_BASE_NAME)

#define DeflateSetHeader(___strm, ___head) \
      LP2(0xa8, LONG, DeflateSetHeader , z_streamp, ___strm, a0, gz_headerp, ___head, a1,\
      , Z_BASE_NAME)

#define InflateCopy(___dest, ___source) \
      LP2(0xae, LONG, InflateCopy , z_streamp, ___dest, a0, z_streamp, ___source, a1,\
      , Z_BASE_NAME)

#define InflatePrime(___strm, ___bits, ___value) \
      LP3(0xb4, LONG, InflatePrime , z_streamp, ___strm, a0, LONG, ___bits, d0, LONG, ___value, d1,\
      , Z_BASE_NAME)

#define InflateGetHeader(___strm, ___head) \
      LP2(0xba, LONG, InflateGetHeader , z_streamp, ___strm, a0, gz_headerp, ___head, a1,\
      , Z_BASE_NAME)

#define InflateBackInit(___strm, ___windowBits, ___window) \
      LP3(0xc0, LONG, InflateBackInit , z_streamp, ___strm, a0, LONG, ___windowBits, d0, UBYTE *, ___window, a1,\
      , Z_BASE_NAME)

#define InflateBack(___strm, ___in, ___in_desc, ___out, ___out_desc) \
      LP5(0xc6, LONG, InflateBack , z_streamp, ___strm, a0, in_func, ___in, a1, void *, ___in_desc, d0, out_func, ___out, a2, void *, ___out_desc, d1,\
      , Z_BASE_NAME)

#define InflateBackEnd(___strm) \
      LP1(0xcc, LONG, InflateBackEnd , z_streamp, ___strm, a0,\
      , Z_BASE_NAME)

#define Adler32Combine(___adler1, ___adler2, ___len2) \
      LP3(0xd2, ULONG, Adler32Combine , ULONG, ___adler1, d0, ULONG, ___adler2, d1, LONG, ___len2, d2,\
      , Z_BASE_NAME)

#define CRC32Combine(___crc1, ___crc2, ___len2) \
      LP3(0xd8, ULONG, CRC32Combine , ULONG, ___crc1, d0, ULONG, ___crc2, d1, LONG, ___len2, d2,\
      , Z_BASE_NAME)

#define Compress2(___dest, ___destLen, ___source, ___sourceLen, ___level) \
      LP5(0xde, LONG, Compress2 , APTR, ___dest, a0, ULONG *, ___destLen, a1, CONST_APTR, ___source, a2, ULONG, ___sourceLen, d0, LONG, ___level, d1,\
      , Z_BASE_NAME)

#define CompressBound(___sourceLen) \
      LP1(0xe4, ULONG, CompressBound , ULONG, ___sourceLen, d0,\
      , Z_BASE_NAME)

#define InflateGetDictionary(___strm, ___dictionary, ___dictLength) \
      LP3(0xea, LONG, InflateGetDictionary , z_streamp, ___strm, a0, UBYTE *, ___dictionary, a1, ULONG *, ___dictLength, a2,\
      , Z_BASE_NAME)

#define ZError(___err) \
      LP1(0xf0, CONST_STRPTR, ZError , LONG, ___err, d0,\
      , Z_BASE_NAME)

#define Uncompress2(___dest, ___destLen, ___source, ___sourceLen) \
      LP4(0xf6, LONG, Uncompress2 , APTR, ___dest, a0, ULONG *, ___destLen, a1, CONST_APTR, ___source, a2, ULONG *, ___sourceLen, a3,\
      , Z_BASE_NAME)

#define InflateReset2(___strm, ___windowBits) \
      LP2(0xfc, LONG, InflateReset2 , z_streamp, ___strm, a0, LONG, ___windowBits, d0,\
      , Z_BASE_NAME)

#define InflateValidate(___strm, ___check) \
      LP2(0x102, LONG, InflateValidate , z_streamp, ___strm, a0, LONG, ___check, d0,\
      , Z_BASE_NAME)

#define CRC32CombineGen(___len2) \
      LP1(0x108, ULONG, CRC32CombineGen , LONG, ___len2, d0,\
      , Z_BASE_NAME)

#define CRC32CombineOp(___crc1, ___crc2, ___op) \
      LP3(0x10e, ULONG, CRC32CombineOp , ULONG, ___crc1, d0, ULONG, ___crc2, d1, ULONG, ___op, d2,\
      , Z_BASE_NAME)

#endif /* !_INLINE_Z_H */
