#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.71])
AC_INIT([temperature_converter], [0.1], [basilkucherov@gmail.com])
AM_INIT_AUTOMAKE([foreign subdir-objects])

DX_HTML_FEATURE(ON)
DX_PDF_FEATURE(OFF)
DX_PS_FEATURE(OFF)
DX_INIT_DOXYGEN([temperature_converter])

AM_GNU_GETTEXT([external])
AM_GNU_GETTEXT_REQUIRE_VERSION(0.21)
LT_INIT([disable-static])
AC_CONFIG_SRCDIR([src/main.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC
IT_PROG_INTLTOOL

# Joint pkgconfig library/include tests
PKG_CHECK_MODULES([CHECK],[check])

# Variable definitions
AC_SUBST(CK_VERBOSITY, verbose)
AC_ARG_VAR(CK_VERBOSITY, [Default: "verbose", can be "silent", "minimal" or "normal"])

# Enable/disable things
AC_ARG_ENABLE([gcov],
              [AS_HELP_STRING([--enable-gcov], [use Gcov to test the test suite])],
              [], [enable_gcov=no])
AM_CONDITIONAL([COND_GCOV],[test '!' "$enable_gcov" = no])

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h string.h])

# Checks for library functions.
AC_CHECK_FUNCS([strcspn])

# Configure Doxygen

AC_CONFIG_FILES([ po/Makefile.in
    Makefile
    src/Makefile
    tests/Makefile
	Doxyfile
])

AC_OUTPUT
