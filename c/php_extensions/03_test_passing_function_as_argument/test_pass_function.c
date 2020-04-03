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
#include "php_test_pass_function.h"

/* If you declare any globals in php_test_pass_function.h uncomment this:
ZEND_DECLARE_MODULE_GLOBALS(test_pass_function)
*/

/* True global resources - no need for thread safety here */
static int le_test_pass_function;

/* {{{ PHP_INI
 */
/* Remove comments and fill if you need to have entries in php.ini
PHP_INI_BEGIN()
    STD_PHP_INI_ENTRY("test_pass_function.global_value",      "42", PHP_INI_ALL, OnUpdateLong, global_value, zend_test_pass_function_globals, test_pass_function_globals)
    STD_PHP_INI_ENTRY("test_pass_function.global_string", "foobar", PHP_INI_ALL, OnUpdateString, global_string, zend_test_pass_function_globals, test_pass_function_globals)
PHP_INI_END()
*/
/* }}} */

/* Remove the following function when you have successfully modified config.m4
   so that your module can be compiled into PHP, it exists only for testing
   purposes. */

/* Every user-visible function in PHP should document itself in the source */
/* {{{ proto string confirm_test_pass_function_compiled(string arg)
   Return a string to confirm that the module is compiled in */
PHP_FUNCTION(confirm_test_pass_function_compiled)
{
	char *arg = NULL;
	size_t arg_len, len;
	zend_string *strg;

	if (zend_parse_parameters(ZEND_NUM_ARGS(), "s", &arg, &arg_len) == FAILURE) {
		return;
	}

	strg = strpprintf(0, "Congratulations! You have successfully modified ext/%.78s/config.m4. Module %.78s is now compiled into PHP.", "test_pass_function", arg);

	RETURN_STR(strg);
}
/* }}} */
/* The previous line is meant for vim and emacs, so it can correctly fold and
   unfold functions in source code. See the corresponding marks just before
   function definition, where the functions purpose is also documented. Please
   follow this convention for the convenience of others editing your code.
*/

/* {{{ proto  test_pass_function(mixed callback_func)
    */
PHP_FUNCTION(test_pass_function)
{
    zval retval;
    zend_fcall_info fci;
    zend_fcall_info_cache fci_cache;

    ZEND_PARSE_PARAMETERS_START(1, -1)
            Z_PARAM_FUNC(fci, fci_cache)
            Z_PARAM_VARIADIC('*', fci.params, fci.param_count)
    ZEND_PARSE_PARAMETERS_END();

    fci.retval = &retval;

    if (zend_call_function(&fci, &fci_cache) == SUCCESS && Z_TYPE(retval) != IS_UNDEF) {
        if (Z_ISREF(retval)) {
            zend_unwrap_reference(&retval);
        }
        ZVAL_COPY_VALUE(return_value, &retval);
    }
}
/* }}} */


/* {{{ php_test_pass_function_init_globals
 */
/* Uncomment this function if you have INI entries
static void php_test_pass_function_init_globals(zend_test_pass_function_globals *test_pass_function_globals)
{
	test_pass_function_globals->global_value = 0;
	test_pass_function_globals->global_string = NULL;
}
*/
/* }}} */

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(test_pass_function)
{
	/* If you have INI entries, uncomment these lines
	REGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(test_pass_function)
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
PHP_RINIT_FUNCTION(test_pass_function)
{
#if defined(COMPILE_DL_TEST_PASS_FUNCTION) && defined(ZTS)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(test_pass_function)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(test_pass_function)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "test_pass_function support", "enabled");
	php_info_print_table_end();

	/* Remove comments if you have entries in php.ini
	DISPLAY_INI_ENTRIES();
	*/
}
/* }}} */

/* {{{ test_pass_function_functions[]
 *
 * Every user visible function must have an entry in test_pass_function_functions[].
 */
const zend_function_entry test_pass_function_functions[] = {
	PHP_FE(confirm_test_pass_function_compiled,	NULL)		/* For testing, remove later. */
	PHP_FE(test_pass_function,	NULL)
	PHP_FE_END	/* Must be the last line in test_pass_function_functions[] */
};
/* }}} */

/* {{{ test_pass_function_module_entry
 */
zend_module_entry test_pass_function_module_entry = {
	STANDARD_MODULE_HEADER,
	"test_pass_function",
	test_pass_function_functions,
	PHP_MINIT(test_pass_function),
	PHP_MSHUTDOWN(test_pass_function),
	PHP_RINIT(test_pass_function),		/* Replace with NULL if there's nothing to do at request start */
	PHP_RSHUTDOWN(test_pass_function),	/* Replace with NULL if there's nothing to do at request end */
	PHP_MINFO(test_pass_function),
	PHP_TEST_PASS_FUNCTION_VERSION,
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_TEST_PASS_FUNCTION
#ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
#endif
ZEND_GET_MODULE(test_pass_function)
#endif

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
