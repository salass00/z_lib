#!/bin/sh
#
# Script for generating a release archive.
#

HOST="${1:-m68k-amigaos}"
FORMAT="${2:-lha}"

if [ "$HOST" = "m68k-amigaos" ]; then
  make -f makefile all
else
  CPU=`echo "${HOST}" | cut -d'-' -f1`
  make -f makefile.aros CPU=${CPU} all
fi;

ZLIBDIR='src/zlib-1.2.13'
DESTDIR='tmp'

rm -rf ${DESTDIR}
mkdir -p ${DESTDIR}/z_lib/Libs
mkdir -p ${DESTDIR}/z_lib/Developer/include/sfd
mkdir -p ${DESTDIR}/z_lib/Developer/include/fd
mkdir -p ${DESTDIR}/z_lib/Developer/include/include_h/clib
mkdir -p ${DESTDIR}/z_lib/Developer/include/include_h/defines
mkdir -p ${DESTDIR}/z_lib/Developer/include/include_h/inline
mkdir -p ${DESTDIR}/z_lib/Developer/include/include_h/libraries
mkdir -p ${DESTDIR}/z_lib/Developer/include/include_h/pragmas
mkdir -p ${DESTDIR}/z_lib/Developer/include/include_h/proto

if [ "$HOST" = "m68k-amigaos" ]; then
  cp -p Install ${DESTDIR}/z_lib
else
  cp -p Install-AROS ${DESTDIR}/z_lib/Install
fi;
cp -p README ${DESTDIR}/z_lib
cp -p LICENSE ${DESTDIR}/z_lib
cp -p ${ZLIBDIR}/LICENSE ${DESTDIR}/z_lib/LICENSE-zlib
cp -p releasenotes ${DESTDIR}/z_lib
if [ "$HOST" = "m68k-amigaos" ]; then
  cp -p bin/z.library.000 ${DESTDIR}/z_lib/Libs
  cp -p bin/z.library.020 ${DESTDIR}/z_lib/Libs
else
  cp -p bin/z.library.${CPU} ${DESTDIR}/z_lib/Libs/z.library
fi;
cp -p z_lib.sfd ${DESTDIR}/z_lib/Developer/include/sfd
cp -p include/fd/z_lib.fd ${DESTDIR}/z_lib/Developer/include/fd
cp -p include/clib/z_protos.h ${DESTDIR}/z_lib/Developer/include/include_h/clib
cp -p include/defines/z.h ${DESTDIR}/z_lib/Developer/include/include_h/defines
cp -p include/inline/z.h ${DESTDIR}/z_lib/Developer/include/include_h/inline
cp -p include/libraries/z.h ${DESTDIR}/z_lib/Developer/include/include_h/libraries
cp -p include/pragmas/z_pragmas.h ${DESTDIR}/z_lib/Developer/include/include_h/pragmas
cp -p include/proto/z.h ${DESTDIR}/z_lib/Developer/include/include_h/proto

cp -p icons/def_drawer.info ${DESTDIR}/z_lib.info
cp -p icons/def_install.info ${DESTDIR}/z_lib/Install.info
cp -p icons/def_doc.info ${DESTDIR}/z_lib/README.info
cp -p icons/def_doc.info ${DESTDIR}/z_lib/LICENSE.info
cp -p icons/def_doc.info ${DESTDIR}/z_lib/LICENSE-zlib.info
cp -p icons/def_doc.info ${DESTDIR}/z_lib/releasenotes.info

case "${FORMAT}" in
  "7z")
    rm -f z_lib.${HOST}.7z
    7za u z_lib.${HOST}.7z ./${DESTDIR}/*
    echo "z_lib.${HOST}.7z created"
    ;;
  "iso")
    rm -f z_lib.${HOST}.iso
    PREVDIR=`pwd`
    cd ${DESTDIR} && mkisofs -R -o ../z_lib.${HOST}.iso -V ZLIB .
    cd ${PREVDIR}
    echo "z_lib.${HOST}.iso created"
    ;;
  "lha")
    rm -rf z_lib.${HOST}.lha
    PREVDIR=`pwd`
    cd ${DESTDIR} && lha ao5 ../z_lib.${HOST}.lha *
    cd ${PREVDIR}
    echo "z_lib.${HOST}.lha created"
    ;;
esac

rm -rf ${DESTDIR}

