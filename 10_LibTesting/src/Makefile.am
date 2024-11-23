CFLAGS = -ansi -pedantic -Wall -Wextra
if COND_GCOV
CFLAGS  += -O0 -g -fprofile-arcs -ftest-coverage -std=c99
else
CFLAGS  += -O3 -g3 -std=c99
endif

lib_LTLIBRARIES = libbuf.la
libbuf_la_SOURCES = libbuf.c buf.h

gcov:
	gcov -o .libs libbuf -t -k -b | egrep -v '[[:digit:]]:[ /][*]'
