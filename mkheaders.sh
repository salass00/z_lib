#!/bin/sh
#
# Script for generating the SDK headers.
#

sfdc --mode=clib -o include/clib/z_protos.h z_lib.sfd
sfdc --mode=fd -o include/fd/z_lib.fd z_lib.sfd
sfdc --mode=pragmas -o include/pragmas/z_pragmas.h z_lib.sfd
sfdc --mode=macros --target=i386-pc-aros -o include/defines/z.h z_lib.sfd
sfdc --mode=macros --target=m68k-amigaos -o include/inline/z.h z_lib.sfd
sfdc --mode=proto -o include/proto/z.h z_lib.sfd
