TESTS_ENVIRONMENT = CK_VERBOSITY=$(CK_VERBOSITY)
TESTS = dummy temperature_tests
check_PROGRAMS = dummy temperature_tests

SUFFIXES = .ts .c
.ts.c:
	checkmk $< > $@

AM_CFLAGS = -I$(top_builddir)/include @CHECK_CFLAGS@
LDADD = $(top_builddir)/src/libtemperature.la @CHECK_LIBS@