<?php

$address = '127.0.0.1';
$port = '9993';

//Создание конечной точки подключения
if(!$socket = socket_create(AF_INET, SOCK_STREAM, SOL_TCP)){
	echo socket_strerror($socket) . "\n";die();
}

//Связывание сокета с адресом
if(!$result = socket_bind($socket, $address, $port)){
	echo socket_strerror($result) . "\n";die();
}

//Прослушивание соединения на сокете
if(!$result = socket_listen($socket, 5)){
	echo socket_strerror($result) . "\n";die();
}

while(true){

	//Разрешение входящего соединения с сокетом
	if(!$msgSock = socket_accept($socket)){
		echo socket_strerror($msgSock) . "\n";
		break;
	}

	//Запись в сокет
	$msg = "Welcome!\n";
	socket_write($msgSock, $msg, strlen($msg));

	while(true){

		//Чтение из сокета
		if(!$buffer = socket_read($msgSock, 2048, PHP_NORMAL_READ)){
			echo socket_strerror($buffer);
			continue;
		}

		$buffer = trim($buffer);

		//Запись ответа в сокет
		$answer = "You wrote: {$buffer}";
		socket_write($msgSock, $answer, strlen($answer));
		echo $buffer . "\n";

		if(!$buffer) continue;
		if($buffer == 'quit') break;
		if($buffer == 'shutdown') break 2;
	}

	//Закрытие ресурса сокета
	if($msgSock) socket_close($msgSock);
}

//Закрытие ресурса сокета
if($socket) socket_close($socket);
