

//1. add a filename into config.m4,
//this will add your external file into extension Makefile
//ext_name, external_file.c extension_file.c, $ext_shared,, -DZEND_ENABLE_STATIC_TSRMLS_CACHE=1
//NOTE that c files splitted with space WITHOUT comma!!!
PHP_NEW_EXTENSION(test_include, library/get_string.c test_include.c, $ext_shared,, -DZEND_ENABLE_STATIC_TSRMLS_CACHE=1)

//2. add a library header into an extension file
#include "library/get_string.h"

//3. call an external function inside your extension function
PHP_FUNCTION(test_include)
{
	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	char *ptr = get_string();
    zend_printf("%s\n", ptr);
}

//4. build
make clean && phpize && ./configure && make

//5. test
php -d extension=modules/test_include.so -a
>> test_include();
