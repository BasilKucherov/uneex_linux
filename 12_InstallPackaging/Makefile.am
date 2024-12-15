SUBDIRS = src

bin_PROGRAMS = temperature_converter

temperature_converter_SOURCES = \
    src/main.c \
    src/temperature.c \
    include/temperature.h \
    include/constants.h

temperature_converter_CFLAGS = -I$(srcdir)/include

include_HEADERS = \
    include/temperature.h \
    include/constants.h

demo: all
	./src/temperature_converter
