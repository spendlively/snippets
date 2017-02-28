<?php


//0b1001 & 0b1010 = 0b1000 -> Побитовое "И"
//0b1001 | 0b1010 = 0b1011 -> Побитовое "ИЛИ"
//0b1001 ^ 0b1010 = 0b0011 -> Исключающее "ИЛИ"

//Log all errors
//error_reporting E_ALL
error_reporting(-1);
error_reporting(E_ALL);
error_reporting(E_ALL | E_ERROR | E_WARNING | E_NOTICE | E_PARSE | E_DEPRECATED);




//Log nothing
//error_reporting 0
error_reporting(0);




//Log all without E_ERROR
//error_reporting E_ALL & ~E_ERROR
error_reporting(E_ALL ^ E_ERROR);



//Log errors but don't display
//display_errors 0
display_errors(0);
