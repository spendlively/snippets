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
#include "php_test_figure_arg_types.h"

/* If you declare any globals in php_test_figure_arg_types.h uncomment this:
ZEND_DECLARE_MODULE_GLOBALS(test_figure_arg_types)
*/

/* True global resources - no need for thread safety here */
static int le_test_figure_arg_types;

/* {{{ PHP_INI
 */
/* Remove comments and fill if you need to have entries in php.ini
PHP_INI_BEGIN()
    STD_PHP_INI_ENTRY("test_figure_arg_types.global_value",      "42", PHP_INI_ALL, OnUpdateLong, global_value, zend_test_figure_arg_types_globals, test_figure_arg_types_globals)
    STD_PHP_INI_ENTRY("test_figure_arg_types.global_string", "foobar", PHP_INI_ALL, OnUpdateString, global_string, zend_test_figure_arg_types_globals, test_figure_arg_types_globals)
PHP_INI_END()
*/
/* }}} */

/* Remove the following function when you have successfully modified config.m4
   so that your module can be compiled into PHP, it exists only for testing
   purposes. */

/* Every user-visible function in PHP should document itself in the source */
/* {{{ proto string confirm_test_figure_arg_types_compiled(string arg)
   Return a string to confirm that the module is compiled in */
PHP_FUNCTION(confirm_test_figure_arg_types_compiled)
{
	char *arg = NULL;
	size_t arg_len, len;
	zend_string *strg;

	if (zend_parse_parameters(ZEND_NUM_ARGS(), "s", &arg, &arg_len) == FAILURE) {
		return;
	}

	strg = strpprintf(0, "Congratulations! You have successfully modified ext/%.78s/config.m4. Module %.78s is now compiled into PHP.", "test_figure_arg_types", arg);

	RETURN_STR(strg);
}
/* }}} */
/* The previous line is meant for vim and emacs, so it can correctly fold and
   unfold functions in source code. See the corresponding marks just before
   function definition, where the functions purpose is also documented. Please
   follow this convention for the convenience of others editing your code.
*/

/* {{{ proto  test_figure_arg_types(mixed some_var)
    */
PHP_FUNCTION(test_figure_arg_types)
{
    zval *some_var;

    if (zend_parse_parameters(ZEND_NUM_ARGS(), "z", &some_var) == FAILURE) {
        return;
    }

    switch (Z_TYPE_P(some_var)) {
        case IS_NULL:
            php_printf("NULL: null\n");
            break;
        case IS_TRUE:
            php_printf("BOOL: true\n");
            break;
        case IS_FALSE:
            php_printf("BOOL: false\n");
            break;
        case IS_LONG:
            php_printf("LONG: %ld\n", Z_LVAL_P(some_var));
            break;
        case IS_DOUBLE:
            php_printf("DOUBLE: %g\n", Z_DVAL_P(some_var));
            break;
        case IS_STRING:
            php_printf("STRING: value=\"");
            PHPWRITE(Z_STRVAL_P(some_var), Z_STRLEN_P(some_var));
            php_printf("\", length=%zd\n", Z_STRLEN_P(some_var));
            break;
        case IS_RESOURCE:
            php_printf("RESOURCE: id=%d\n", Z_RES_HANDLE_P(some_var));
            break;
        case IS_ARRAY:
            php_printf("ARRAY: hashtable=%p\n", Z_ARRVAL_P(some_var));
            break;
        case IS_OBJECT:
            php_printf("OBJECT: object=%p\n", Z_OBJ_P(some_var));
            break;
    }
}
/* }}} */


/* {{{ php_test_figure_arg_types_init_globals
 */
/* Uncomment this function if you have INI entries
static void php_test_figure_arg_types_init_globals(zend_test_figure_arg_types_globals *test_figure_arg_types_globals)
{
	test_figure_arg_types_globals->global_value = 0;
	test_figure_arg_types_globals->global_string = NULL;
}
*/
/* }}} */

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(test_figure_arg_types)
{
	/* If you have INI entries, uncomment these lines
	REGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(test_figure_arg_types)
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
PHP_RINIT_FUNCTION(test_figure_arg_types)
{
#if defined(COMPILE_DL_TEST_FIGURE_ARG_TYPES) && defined(ZTS)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(test_figure_arg_types)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(test_figure_arg_types)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "test_figure_arg_types support", "enabled");
	php_info_print_table_end();

	/* Remove comments if you have entries in php.ini
	DISPLAY_INI_ENTRIES();
	*/
}
/* }}} */

/* {{{ test_figure_arg_types_functions[]
 *
 * Every user visible function must have an entry in test_figure_arg_types_functions[].
 */
const zend_function_entry test_figure_arg_types_functions[] = {
	PHP_FE(confirm_test_figure_arg_types_compiled,	NULL)		/* For testing, remove later. */
	PHP_FE(test_figure_arg_types,	NULL)
	PHP_FE_END	/* Must be the last line in test_figure_arg_types_functions[] */
};
/* }}} */

/* {{{ test_figure_arg_types_module_entry
 */
zend_module_entry test_figure_arg_types_module_entry = {
	STANDARD_MODULE_HEADER,
	"test_figure_arg_types",
	test_figure_arg_types_functions,
	PHP_MINIT(test_figure_arg_types),
	PHP_MSHUTDOWN(test_figure_arg_types),
	PHP_RINIT(test_figure_arg_types),		/* Replace with NULL if there's nothing to do at request start */
	PHP_RSHUTDOWN(test_figure_arg_types),	/* Replace with NULL if there's nothing to do at request end */
	PHP_MINFO(test_figure_arg_types),
	PHP_TEST_FIGURE_ARG_TYPES_VERSION,
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_TEST_FIGURE_ARG_TYPES
#ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
#endif
ZEND_GET_MODULE(test_figure_arg_types)
#endif

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
