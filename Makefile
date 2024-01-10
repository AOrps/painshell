#OBJS = losh.o
SHELL = /bin/sh
CC = gcc

# -Wno-format is needed because mismatched formats are a feature to get an alphanumeric character
CFLAGS = -g -Wall -pedantic -Og -Wno-format
# Hardening Flags Resources : https://github.com/ossf/wg-best-practices-os-developers/blob/main/docs/Compiler-Hardening-Guides/Compiler-Options-Hardening-Guide-for-C-and-C%2B%2B.md
CFLAGS_HARDEN = -Wall -Wextra -Wformat=2 -Wconversion -Wtrampolines -Werror -O1 -D_FORTIFY_SOURCE=3 -fstack-clash-protection -fstack-protector-strong -Wl,-z,noexecstack -fPIE -pie
OBJS = src/main.c src/logging.c src/sigs.c src/lockshell.h
PROGS = compile


all: $(PROGS)

compile: clean 
	$(CC) $(CFLAGS) -o losh $(OBJS)

run: compile
	./losh

harden: clean
	$(CC) $(CFLAGS_HARDEN) -o loshh $(OBJS)

test: compile
	./losh&
	@sleep 1.5
	./kill-debug.sh

clean:
ifneq (,$(wildcard ./losh))
	rm ./losh
endif
ifneq (,$(wildcard ./loshh))
	rm ./loshh
endif
ifneq (,$(wildcard ./a.out))
	rm ./a.out
endif
ifneq (,$(wildcard *.o))
	rm *.o
endif
ifneq (,$(wildcard *~))
	rm *~
endif

prune: clean
ifneq (,$(wildcard *.log))
	rm *.log
endif

#[ -f {} ] && rm {} && echo 'rm *.log'

clean-all: clean
ifneq (,$(wildcard ./*.log))
	rm ./*.log
endif
