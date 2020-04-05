dnl $Id$
dnl config.m4 for extension test_setting_zval_value

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

dnl PHP_ARG_WITH(test_setting_zval_value, for test_setting_zval_value support,
dnl Make sure that the comment is aligned:
dnl [  --with-test_setting_zval_value             Include test_setting_zval_value support])

dnl Otherwise use enable:

PHP_ARG_ENABLE(test_setting_zval_value, whether to enable test_setting_zval_value support,
dnl Make sure that the comment is aligned:
[  --enable-test_setting_zval_value           Enable test_setting_zval_value support])

if test "$PHP_TEST_SETTING_ZVAL_VALUE" != "no"; then
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
  dnl PHP_EVAL_LIBLINE($LIBFOO_LIBDIR, TEST_SETTING_ZVAL_VALUE_SHARED_LIBADD)
  dnl PHP_EVAL_INCLINE($LIBFOO_CFLAGS)

  dnl # --with-test_setting_zval_value -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/test_setting_zval_value.h"  # you most likely want to change this
  dnl if test -r $PHP_TEST_SETTING_ZVAL_VALUE/$SEARCH_FOR; then # path given as parameter
  dnl   TEST_SETTING_ZVAL_VALUE_DIR=$PHP_TEST_SETTING_ZVAL_VALUE
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for test_setting_zval_value files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       TEST_SETTING_ZVAL_VALUE_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$TEST_SETTING_ZVAL_VALUE_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the test_setting_zval_value distribution])
  dnl fi

  dnl # --with-test_setting_zval_value -> add include path
  dnl PHP_ADD_INCLUDE($TEST_SETTING_ZVAL_VALUE_DIR/include)

  dnl # --with-test_setting_zval_value -> check for lib and symbol presence
  dnl LIBNAME=test_setting_zval_value # you may want to change this
  dnl LIBSYMBOL=test_setting_zval_value # you most likely want to change this 

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $TEST_SETTING_ZVAL_VALUE_DIR/$PHP_LIBDIR, TEST_SETTING_ZVAL_VALUE_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_TEST_SETTING_ZVAL_VALUELIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong test_setting_zval_value lib version or lib not found])
  dnl ],[
  dnl   -L$TEST_SETTING_ZVAL_VALUE_DIR/$PHP_LIBDIR -lm
  dnl ])
  dnl
  dnl PHP_SUBST(TEST_SETTING_ZVAL_VALUE_SHARED_LIBADD)

  PHP_NEW_EXTENSION(test_setting_zval_value, test_setting_zval_value.c, $ext_shared,, -DZEND_ENABLE_STATIC_TSRMLS_CACHE=1)
fi
