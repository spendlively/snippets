//http://localhost:9999/arr.php?qwe=123&asd=456

//////////////////////////////////////////////////////
//////////////////////$_SERVER////////////////////////
//////////////////////////////////////////////////////

//Корневой каталог
$_SERVER['DOCUMENT_ROOT']; // /tmp

//Запрос
$_SERVER['HTTP_HOST']; //localhost:9999
$_SERVER['SERVER_NAME']; //0.0.0.0
$_SERVER['SERVER_PORT']; //9999
$_SERVER['REQUEST_URI']; ///arr.php
$_SERVER['REQUEST_METHOD']; //GET
$_SERVER['QUERY_STRING']; //qwe=123&asd=456

//Клиент
$_SERVER['REMOTE_ADDR']; //127.0.0.1
$_SERVER['REMOTE_PORT']; //45020

//HTTP загголовки
$_SERVER['HTTP_CONNECTION']; //keep-alive
$_SERVER['HTTP_UPGRADE_INSECURE_REQUESTS']; //1
$_SERVER['HTTP_USER_AGENT']; //Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/58.0.3029.110 Safari/537.36
$_SERVER['HTTP_ACCEPT']; //text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8
$_SERVER['HTTP_ACCEPT_ENCODING']; //gzip, deflate, sdch, br
$_SERVER['HTTP_ACCEPT_LANGUAGE']; //ru-RU,ru;q=0.8,en-US;q=0.6,en;q=0.4

//Метка времени, когда был сделан запрос
$_SERVER['REQUEST_TIME_FLOAT']; //1496732600.2592
$_SERVER['REQUEST_TIME']; //1496732600



//////////////////////////////////////////////////////
////////////////////////$_GET/////////////////////////
//////////////////////////////////////////////////////
$_GET['qwe']; //123
$_GET['asd']; //456



//Все массивы
$_SERVER
$_GET
$_POST
$_FILES
$_COOKIE
$_SESSION
$_REQUEST
$_ENV
