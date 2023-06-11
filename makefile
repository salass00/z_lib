TARGET  = z.library
VERSION = 1

ZLIBDIR = src/zlib-1.2.13

CC     = m68k-amigaos-gcc
STRIP  = m68k-amigaos-strip
AR     = m68k-amigaos-ar
RANLIB = m68k-amigaos-ranlib

OPTIMIZE = -O2 -fomit-frame-pointer
DEBUG    = -g
INCLUDES = -I./include -I./$(ZLIBDIR) -I.
DEFINES  = -DSTDC -DAMIGA -DZLIB_CONST -DHAVE_UNISTD_H -DHAVE_STDARG_H
WARNINGS = -Werror -Wall -Wwrite-strings -Wno-pointer-sign

CFLAGS  = -noixemul $(OPTIMIZE) $(DEBUG) $(INCLUDES) $(DEFINES) $(WARNINGS)
LDFLAGS = -noixemul -nostartfiles
LIBS    = 

STRIPFLAGS = -R.comment

ZLIB_SRCS = $(addprefix $(ZLIBDIR)/, \
            adler32.c compress.c crc32.c deflate.c infback.c inffast.c inflate.c \
            inftrees.c trees.c uncompr.c zutil.c)

main_SRCS = $(wildcard src/main/*.c)

SRCS = $(addprefix src/,dummy_start.c init.c malloc.c)

ARCH_000 = -m68000
OBJS_000 = $(subst src/,obj-000/,$(main_SRCS:.c=.o) $(SRCS:.c=.o) $(ZLIB_SRCS:.c=.o))
DEPS_000 = $(OBJS_000:.o=.d)

ARCH_020 = -m68020
OBJS_020 = $(subst src/,obj-020/,$(main_SRCS:.c=.o) $(SRCS:.c=.o) $(ZLIB_SRCS:.c=.o))
DEPS_020 = $(OBJS_020:.o=.d)

STATIC_SRCS = src/static/autoinit_z_base.c $(wildcard src/static/stubs/*.c) \
              $(addprefix $(ZLIBDIR)/,gzclose.c gzread.c gzlib.c gzwrite.c)

STATIC_OBJS_000 = $(subst src/,obj-000/,$(STATIC_SRCS:.c=.o))
STATIC_OBJS_020 = $(subst src/,obj-020/,$(STATIC_SRCS:.c=.o))

.PHONY: all
all: $(TARGET).000 $(TARGET).020 libz.a.000 libz.a.020

-include $(DEPS_000)
-include $(DEPS_020)

obj-000/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) -MM -MP -MT $(@:.o=.d) -MT $@ -MF $(@:.o=.d) $(ARCH_000) $(CFLAGS) $<
	$(CC) $(ARCH_000) $(CFLAGS) -c -o $@ $<

obj-020/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) -MM -MP -MT $(@:.o=.d) -MT $@ -MF $(@:.o=.d) $(ARCH_020) $(CFLAGS) $<
	$(CC) $(ARCH_020) $(CFLAGS) -c -o $@ $<

$(OBJS_000): OPTIMIZE += -mregparm
$(OBJS_020): OPTIMIZE += -mregparm

$(TARGET).000: $(OBJS_000)
	$(CC) $(ARCH_000) $(LDFLAGS) -o $@.debug $^ $(LIBS)
	$(STRIP) $(STRIPFLAGS) -o $@ $@.debug

$(TARGET).020: $(OBJS_020)
	$(CC) $(ARCH_020) $(LDFLAGS) -o $@.debug $^ $(LIBS)
	$(STRIP) $(STRIPFLAGS) -o $@ $@.debug

libz.a.000: $(STATIC_OBJS_000)
	$(AR) -crv $@ $^
	$(RANLIB) $@

libz.a.020: $(STATIC_OBJS_020)
	$(AR) -crv $@ $^
	$(RANLIB) $@

minigzip: obj-000/minigzip.o libz.a.000
	$(CC) $(ARCH_000) -noixemul -o $@.debug $^
	$(STRIP) $(STRIPFLAGS) -o $@ $@.debug

clean:
	rm -rf $(TARGET).000 $(TARGET).000.debug obj-000
	rm -rf $(TARGET).020 $(TARGET).020.debug obj-020
	rm -f libz.a.000 libz.a.020
	rm -f minigzip minigzip.debug

revision:
	bumprev -e is $(VERSION) $(TARGET)

