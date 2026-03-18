PROG=yeehaw
CC=clang
CFLAGS=-static -O2 -g -march=native -ffast-math -Wall -Wextra
SRCS=$(wildcard src/*.c)
OUTDIR=out
OBJDIR=obj
NAMESPACE=/usr/local/bin

OBJS=$(patsubst src/%.c, $(OBJDIR)/%.o, $(SRCS))

all: $(OUTDIR)/$(PROG)

$(OUTDIR)/$(PROG): $(OBJS) | $(OUTDIR)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJDIR)/%.o: src/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OUTDIR) $(OBJDIR):
	mkdir -p $@

clean:
	rm -rf $(OUTDIR) $(OBJDIR)

install: all
	install -m 755 $(OUTDIR)/$(PROG) $(NAMESPACE)

.PHONY: all clean install
