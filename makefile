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

ARCH_000 = -mcpu=68000 -mtune=68000
OBJS_000 = $(subst src/,obj/68000/,$(main_SRCS:.c=.o) $(SRCS:.c=.o) $(ZLIB_SRCS:.c=.o))
DEPS_000 = $(OBJS_000:.o=.d)

ARCH_020 = -mcpu=68020 -mtune=68020-60
OBJS_020 = $(subst src/,obj/68020/,$(main_SRCS:.c=.o) $(SRCS:.c=.o) $(ZLIB_SRCS:.c=.o))
DEPS_020 = $(OBJS_020:.o=.d)

STATIC_SRCS = src/static/autoinit_z_base.c $(wildcard src/static/stubs/*.c) \
              $(addprefix $(ZLIBDIR)/,gzclose.c gzread.c gzlib.c gzwrite.c)

STATIC_OBJS_000 = $(subst src/,obj/68000/,$(STATIC_SRCS:.c=.o))
STATIC_OBJS_020 = $(subst src/,obj/68020/,$(STATIC_SRCS:.c=.o))

.PHONY: all
all: bin/$(TARGET).000 bin/$(TARGET).020 bin/libz.a.000 bin/libz.a.020 \
     bin/minigzip

-include $(DEPS_000)
-include $(DEPS_020)

obj/68000/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) -MM -MP -MT $(@:.o=.d) -MT $@ -MF $(@:.o=.d) $(ARCH_000) $(CFLAGS) $<
	$(CC) $(ARCH_000) $(CFLAGS) -c -o $@ $<

obj/68020/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) -MM -MP -MT $(@:.o=.d) -MT $@ -MF $(@:.o=.d) $(ARCH_020) $(CFLAGS) $<
	$(CC) $(ARCH_020) $(CFLAGS) -c -o $@ $<

$(OBJS_000): OPTIMIZE += -mregparm
$(OBJS_020): OPTIMIZE += -mregparm

bin/$(TARGET).000: $(OBJS_000)
	@mkdir -p $(dir $@)
	$(CC) $(ARCH_000) $(LDFLAGS) -o $@.debug $^ $(LIBS)
	$(STRIP) $(STRIPFLAGS) -o $@ $@.debug

bin/$(TARGET).020: $(OBJS_020)
	@mkdir -p $(dir $@)
	$(CC) $(ARCH_020) $(LDFLAGS) -o $@.debug $^ $(LIBS)
	$(STRIP) $(STRIPFLAGS) -o $@ $@.debug

bin/libz.a.000: $(STATIC_OBJS_000)
	@mkdir -p $(dir $@)
	$(AR) -crv $@ $^
	$(RANLIB) $@

bin/libz.a.020: $(STATIC_OBJS_020)
	@mkdir -p $(dir $@)
	$(AR) -crv $@ $^
	$(RANLIB) $@

bin/minigzip: obj/68000/minigzip.o bin/libz.a.000
	@mkdir -p $(dir $@)
	$(CC) $(ARCH_000) -noixemul -o $@.debug $^
	$(STRIP) $(STRIPFLAGS) -o $@ $@.debug

clean:
	rm -rf bin obj

revision:
	bumprev -e is $(VERSION) $(TARGET)

