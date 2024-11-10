#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.71])
AC_INIT([rhasher], [0.00], [basilkucherov@gmail.com])
AC_CONFIG_SRCDIR([rhasher.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC
AM_INIT_AUTOMAKE([foreign])

# Checks for libraries.
AC_CHECK_LIB([rhash], [rhash_library_init], [], AC_MSG_ERROR([rhash not found]))
AC_CHECK_LIB([readline], [readline])

# Checks for header files.

# Optional clues
AC_ARG_ENABLE([readline],
    AS_HELP_STRING([--enable-readline], [Use readline]),
    AC_DEFINE([USE_READLINE], [], [Use readline])
)

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_SIZE_T

# Checks for library functions.
AC_FUNC_MALLOC
AC_CHECK_FUNCS([strcasecmp strcspn strerror])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
