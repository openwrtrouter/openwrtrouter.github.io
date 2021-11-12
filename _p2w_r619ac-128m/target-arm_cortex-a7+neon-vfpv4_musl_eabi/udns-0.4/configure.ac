# Copyright 2016 Yousong Zhou

AC_PREREQ([2.67])
AC_INIT([libudns], [0.4])
AC_CONFIG_HEADERS([config.h])

AM_INIT_AUTOMAKE([foreign])
LT_INIT

dnl Checks for programs.
AC_PROG_CC
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_LIBTOOL

dnl Checks for library functions.
AC_CHECK_LIB(socket, connect)
AC_CHECK_FUNCS([malloc memset socket])
AC_CHECK_FUNCS([getopt poll])
AC_CHECK_FUNCS([inet_pton inet_ntop],
			   [AC_DEFINE([HAVE_INET_PTON_NTOP], [1], [Have inet_pton and inet_ntop])])

AC_ARG_ENABLE(ipv6,
  AC_HELP_STRING([--disable-ipv6],[disable IPv6 support]),
  [case "${enable_ipv6}" in
    no)
      AC_MSG_NOTICE([disabling IPv6 at user request])
      ipv6=no
      ;;
    yes)
      ipv6=yes
	  force_ipv6=yes
      ;;
    *)
      AC_MSG_ERROR([Invalid --enable-ipv6 argument \`$enable_ipv6'])
      ;;
    esac
  ], [
    dnl If nothing is specified, assume auto-detection.
    ipv6=yes
	force_ipv6=no
  ]
)

if test "x$ipv6" = "xyes"; then
  AC_CHECK_TYPE([struct sockaddr_in6],
    [AC_DEFINE([HAVE_IPv6], [1], [Have ipv6 support])],
    [if test "x$force_ipv6" = "xyes"; then
      AC_MSG_ERROR([ipv6 support requested but cannot be fulfilled])
     fi],
    [#include <sys/socket.h>
     #include <netinet/in.h>])
fi

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
