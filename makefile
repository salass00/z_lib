TARGET  = z.library
VERSION = 1

ZLIBDIR = zlib-1.2.13

CC    = m68k-amigaos-gcc
STRIP = m68k-amigaos-strip

OPTIMIZE = -O2 -fomit-frame-pointer
DEBUG    = -g
INCLUDES = -I./include -I./$(ZLIBDIR)
DEFINES  = -DSTDC -DAMIGA -DZLIB_CONST -DHAVE_STDARG_H

CFLAGS  = -noixemul $(OPTIMIZE) $(DEBUG) $(INCLUDES) $(DEFINES)
LDFLAGS = -noixemul -nostartfiles
LIBS    = 

STRIPFLAGS = -R.comment

ZLIB_SRCS = $(addprefix $(ZLIBDIR)/, \
            adler32.c compress.c crc32.c deflate.c inffast.c inflate.c \
            inftrees.c trees.c uncompr.c zutil.c)

SRCS = init.c malloc.c

OBJS = $(SRCS:.c=.o) $(ZLIB_SRCS:.c=.o)

.PHONY: all
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -o $@.debug $^ $(LIBS)
	$(STRIP) $(STRIPFLAGS) -o $@ $@.debug

init.o: $(TARGET)_rev.h

clean:
	rm -f $(TARGET) $(TARGET).debug *.o $(ZLIBDIR)/*.o

revision:
	bumprev -e is $(VERSION) $(TARGET)

