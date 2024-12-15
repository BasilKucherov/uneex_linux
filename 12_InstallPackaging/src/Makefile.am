CFLAGS = -ansi -pedantic -Wall -Wextra
if COND_GCOV
CFLAGS += -O0 -g -fprofile-arcs -ftest-coverage
else
CFLAGS += -O3 -g3
endif

lib_LTLIBRARIES = libtemperature.la
bin_PROGRAMS = temperature_converter

temperature_converter_LDADD = libtemperature.la
temperature_converter_SOURCES = main.c

libtemperature_la_SOURCES = \
    temperature.c \
    ../include/temperature.h \
    ../include/constants.h

libtemperature_la_CFLAGS = -I$(top_srcdir)/include

# Optional: Add gcov target
gcov:
	gcov -o .libs libtemperature -t -k -b | egrep -v '[[:digit:]]:[ /][*]'