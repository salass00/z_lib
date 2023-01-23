#!/bin/sh
#
# Script for generating a release archive.
#

HOST="${1:-m68k-amigaos}"

if [ "$HOST" = "m68k-amigaos" ]; then
  make -f makefile all
else
  make -f makefile.aros all
fi;

DESTDIR='tmp'

rm -rf ${DESTDIR}
mkdir -p ${DESTDIR}/z_lib/Libs

cp -p LICENSE ${DESTDIR}/z_lib
cp -p releasenotes ${DESTDIR}/z_lib
cp -p z.library.000 ${DESTDIR}/z_lib/Libs
cp -p z.library.020 ${DESTDIR}/z_lib/Libs

cp -p icons/def_drawer.info ${DESTDIR}/z_lib.info
cp -p icons/def_doc.info ${DESTDIR}/z_lib/LICENSE.info
cp -p icons/def_doc.info ${DESTDIR}/z_lib/releasenotes.info

rm -rf z_lib.${HOST}.lha
PREVDIR=`pwd`
cd ${DESTDIR} && lha ao5 ../z_lib.${HOST}.lha *
cd ${PREVDIR}

rm -rf ${DESTDIR}

echo "z_lib.${HOST}.lha created"

