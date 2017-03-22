<?php

$address = '127.0.0.1';
$port = '9993';

//Создание конечной точки подключения
if(!$socket = socket_create(AF_INET, SOCK_STREAM, SOL_TCP)){
	echo socket_strerror($socket) . "\n";die();
}

//Инициализация соединения с сокетом
if(!$result = socket_connect($socket, $address, $port)){
	echo socket_strerror($result) . "\n";die();
}

//Запись в сокет №1
$msg = "quit\n";
socket_write($socket, $msg, strlen($msg));
while($answer = socket_read($socket, 2048)){
	echo $answer . "\n";
}

// //Запись в сокет №2
// $msg = "shutdown\n";
// socket_write($socket, $msg, strlen($msg));
// while($answer = socket_read($socket, 2048)){
// 	echo $answer . "\n";
// }

//Закрытие ресурса сокета
socket_close($socket);
