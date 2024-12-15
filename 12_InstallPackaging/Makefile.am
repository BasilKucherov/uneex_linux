SUBDIRS = src tests po

@DX_RULES@

all-local:	doxygen-doc

doxygen-doc/man/man1/temperature_converter.1:	doxygen-doc

man1_MANS = doxygen-doc/man/man1/temperature_converter.1

bin_PROGRAMS = temperature_converter

install-data-local:
	mkdir -p $(DESTDIR)/$(docdir)
	cp -a doxygen-doc/html $(DESTDIR)/$(docdir)


temperature_converter_SOURCES = \
    src/main.c \
    src/temperature.c \
    include/temperature.h \
    include/constants.h

temperature_converter_CFLAGS = -I$(srcdir)/include -D'LOCALE_PATH="$(localedir)"'

include_HEADERS = \
    include/temperature.h \
    include/constants.h

demo: all
	./src/temperature_converter
ACLOCAL_AMFLAGS = -I m4

http:	doxygen-doc
	python3 -m http.server --directory $</html 5000