<?php

//Поток (stream) - это ресурс (resource), который ведет себя, как источник непрерывной последовательности данных
//С помощью потока можно читать, писать данные и перемещаться с помощью fseek()
//PHP reference
//http://php.net/manual/ru/book.stream.php
//http://php.net/manual/ru/internals2.ze1.streams.php



//Регистрация обработчика (wrapper) потока 
//stream_wrapper_register()



//Print all wrappers
print_r(stream_get_transports());
print_r(stream_get_wrappers());
print_r(stream_get_filters());



//php -S 0.0.0.0:7878
//curl -d "Hello World" -d "key=value" http://localhost:7878/streams.php
readfile('php://input');
echo PHP_EOL;

