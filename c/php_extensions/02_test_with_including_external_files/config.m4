dnl $Id$
dnl config.m4 for extension test_include

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

dnl PHP_ARG_WITH(test_include, for test_include support,
dnl Make sure that the comment is aligned:
dnl [  --with-test_include             Include test_include support])

dnl Otherwise use enable:

PHP_ARG_ENABLE(test_include, whether to enable test_include support,
dnl Make sure that the comment is aligned:
[  --enable-test_include           Enable test_include support])

if test "$PHP_TEST_INCLUDE" != "no"; then
  dnl Write more examples of tests here...

  dnl # get library FOO build options from pkg-config output
  dnl AC_PATH_PROG(PKG_CONFIG, pkg-config, no)
  dnl AC_MSG_CHECKING(for libfoo)
  dnl if test -x "$PKG_CONFIG" && $PKG_CONFIG --exists foo; then
  dnl   if $PKG_CONFIG foo --atleast-version 1.2.3; then
  dnl     LIBFOO_CFLAGS=`$PKG_CONFIG foo --cflags`
  dnl     LIBFOO_LIBDIR=`$PKG_CONFIG foo --libs`
  dnl     LIBFOO_VERSON=`$PKG_CONFIG foo --modversion`
  dnl     AC_MSG_RESULT(from pkgconfig: version $LIBFOO_VERSON)
  dnl   else
  dnl     AC_MSG_ERROR(system libfoo is too old: version 1.2.3 required)
  dnl   fi
  dnl else
  dnl   AC_MSG_ERROR(pkg-config not found)
  dnl fi
  dnl PHP_EVAL_LIBLINE($LIBFOO_LIBDIR, TEST_INCLUDE_SHARED_LIBADD)
  dnl PHP_EVAL_INCLINE($LIBFOO_CFLAGS)

  dnl # --with-test_include -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/test_include.h"  # you most likely want to change this
  dnl if test -r $PHP_TEST_INCLUDE/$SEARCH_FOR; then # path given as parameter
  dnl   TEST_INCLUDE_DIR=$PHP_TEST_INCLUDE
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for test_include files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       TEST_INCLUDE_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$TEST_INCLUDE_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the test_include distribution])
  dnl fi

  dnl # --with-test_include -> add include path
  dnl PHP_ADD_INCLUDE($TEST_INCLUDE_DIR/include)

  dnl # --with-test_include -> check for lib and symbol presence
  dnl LIBNAME=test_include # you may want to change this
  dnl LIBSYMBOL=test_include # you most likely want to change this 

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $TEST_INCLUDE_DIR/$PHP_LIBDIR, TEST_INCLUDE_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_TEST_INCLUDELIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong test_include lib version or lib not found])
  dnl ],[
  dnl   -L$TEST_INCLUDE_DIR/$PHP_LIBDIR -lm
  dnl ])
  dnl
  dnl PHP_SUBST(TEST_INCLUDE_SHARED_LIBADD)

  PHP_NEW_EXTENSION(test_include, library/get_string.c test_include.c, $ext_shared,, -DZEND_ENABLE_STATIC_TSRMLS_CACHE=1)

fi
