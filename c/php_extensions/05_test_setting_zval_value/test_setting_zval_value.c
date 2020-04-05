/*
  +----------------------------------------------------------------------+
  | PHP Version 7                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2018 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:                                                              |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_test_setting_zval_value.h"

/* If you declare any globals in php_test_setting_zval_value.h uncomment this:
ZEND_DECLARE_MODULE_GLOBALS(test_setting_zval_value)
*/

/* True global resources - no need for thread safety here */
static int le_test_setting_zval_value;

/* {{{ PHP_INI
 */
/* Remove comments and fill if you need to have entries in php.ini
PHP_INI_BEGIN()
    STD_PHP_INI_ENTRY("test_setting_zval_value.global_value",      "42", PHP_INI_ALL, OnUpdateLong, global_value, zend_test_setting_zval_value_globals, test_setting_zval_value_globals)
    STD_PHP_INI_ENTRY("test_setting_zval_value.global_string", "foobar", PHP_INI_ALL, OnUpdateString, global_string, zend_test_setting_zval_value_globals, test_setting_zval_value_globals)
PHP_INI_END()
*/
/* }}} */

/* Remove the following function when you have successfully modified config.m4
   so that your module can be compiled into PHP, it exists only for testing
   purposes. */

/* Every user-visible function in PHP should document itself in the source */
/* {{{ proto string confirm_test_setting_zval_value_compiled(string arg)
   Return a string to confirm that the module is compiled in */
PHP_FUNCTION(confirm_test_setting_zval_value_compiled)
{
	char *arg = NULL;
	size_t arg_len, len;
	zend_string *strg;

	if (zend_parse_parameters(ZEND_NUM_ARGS(), "s", &arg, &arg_len) == FAILURE) {
		return;
	}

	strg = strpprintf(0, "Congratulations! You have successfully modified ext/%.78s/config.m4. Module %.78s is now compiled into PHP.", "test_setting_zval_value", arg);

	RETURN_STR(strg);
}
/* }}} */
/* The previous line is meant for vim and emacs, so it can correctly fold and
   unfold functions in source code. See the corresponding marks just before
   function definition, where the functions purpose is also documented. Please
   follow this convention for the convenience of others editing your code.
*/

/* {{{ proto  test_setting_zval_value()
    */

PHP_FUNCTION(test_setting_zval_value)
{
	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

    ZVAL_STRING(return_value, "hello world!");
}

PHP_FUNCTION(test_setting_zval_null)
{
    if (zend_parse_parameters_none() == FAILURE) {
        return;
    }

    ZVAL_NULL(return_value);
}

PHP_FUNCTION(test_setting_zval_false)
{
    if (zend_parse_parameters_none() == FAILURE) {
        return;
    }

    ZVAL_FALSE(return_value);
}

PHP_FUNCTION(test_setting_zval_true)
{
    if (zend_parse_parameters_none() == FAILURE) {
        return;
    }

    ZVAL_TRUE(return_value);
}

PHP_FUNCTION(test_setting_zval_long)
{
    if (zend_parse_parameters_none() == FAILURE) {
        return;
    }

    ZVAL_LONG(return_value, 42);
}

PHP_FUNCTION(test_setting_zval_double)
{
    if (zend_parse_parameters_none() == FAILURE) {
        return;
    }

    ZVAL_DOUBLE(return_value, 4.2);
}

//PHP_FUNCTION(test_setting_zval_resource)
//{
//    if (zend_parse_parameters_none() == FAILURE) {
//        return;
//    }
//
//    ZVAL_RES(return_value, zend_resource *);
//}

PHP_FUNCTION(test_setting_zval_empty_string)
{
    if (zend_parse_parameters_none() == FAILURE) {
        return;
    }

    ZVAL_EMPTY_STRING(return_value);
}

PHP_FUNCTION(test_setting_zval_string)
{
    if (zend_parse_parameters_none() == FAILURE) {
        return;
    }

    ZVAL_STRING(return_value, "string");
/* = ZVAL_NEW_STR(z, zend_string_init("string", strlen("string"), 0)); */
}

PHP_FUNCTION(test_setting_zval_stringl)
{
    if (zend_parse_parameters_none() == FAILURE) {
        return;
    }

    ZVAL_STRINGL(return_value, "nul\0string", 10);
/* = ZVAL_NEW_STR(z, zend_string_init("nul\0string", 10, 0)); */
}
/* }}} */


/* {{{ php_test_setting_zval_value_init_globals
 */
/* Uncomment this function if you have INI entries
static void php_test_setting_zval_value_init_globals(zend_test_setting_zval_value_globals *test_setting_zval_value_globals)
{
	test_setting_zval_value_globals->global_value = 0;
	test_setting_zval_value_globals->global_string = NULL;
}
*/
/* }}} */

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(test_setting_zval_value)
{
	/* If you have INI entries, uncomment these lines
	REGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(test_setting_zval_value)
{
	/* uncomment this line if you have INI entries
	UNREGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request start */
/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(test_setting_zval_value)
{
#if defined(COMPILE_DL_TEST_SETTING_ZVAL_VALUE) && defined(ZTS)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(test_setting_zval_value)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(test_setting_zval_value)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "test_setting_zval_value support", "enabled");
	php_info_print_table_end();

	/* Remove comments if you have entries in php.ini
	DISPLAY_INI_ENTRIES();
	*/
}
/* }}} */

/* {{{ test_setting_zval_value_functions[]
 *
 * Every user visible function must have an entry in test_setting_zval_value_functions[].
 */
const zend_function_entry test_setting_zval_value_functions[] = {
	PHP_FE(confirm_test_setting_zval_value_compiled,	NULL)		/* For testing, remove later. */
	PHP_FE(test_setting_zval_value,	NULL)
    PHP_FE(test_setting_zval_false,	NULL)
    PHP_FE(test_setting_zval_true,	NULL)
    PHP_FE(test_setting_zval_long,	NULL)
    PHP_FE(test_setting_zval_double,	NULL)
//    PHP_FE(test_setting_zval_resource,	NULL)
    PHP_FE(test_setting_zval_empty_string,	NULL)
    PHP_FE(test_setting_zval_string,	NULL)
    PHP_FE(test_setting_zval_stringl,	NULL)
	PHP_FE_END	/* Must be the last line in test_setting_zval_value_functions[] */
};
/* }}} */

/* {{{ test_setting_zval_value_module_entry
 */
zend_module_entry test_setting_zval_value_module_entry = {
	STANDARD_MODULE_HEADER,
	"test_setting_zval_value",
	test_setting_zval_value_functions,
	PHP_MINIT(test_setting_zval_value),
	PHP_MSHUTDOWN(test_setting_zval_value),
	PHP_RINIT(test_setting_zval_value),		/* Replace with NULL if there's nothing to do at request start */
	PHP_RSHUTDOWN(test_setting_zval_value),	/* Replace with NULL if there's nothing to do at request end */
	PHP_MINFO(test_setting_zval_value),
	PHP_TEST_SETTING_ZVAL_VALUE_VERSION,
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_TEST_SETTING_ZVAL_VALUE
#ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
#endif
ZEND_GET_MODULE(test_setting_zval_value)
#endif

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
