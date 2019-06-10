<?php

namespace App;

use PhpAmqpLib\Connection\AMQPConnection;

class Receiver
{
    const QUEUE_NAME = 'app_order';

    public function listen()
    {
        $connection = new AMQPConnection(
            'localhost',    #host
            5672,           #port
            'guest',        #user
            'guest'     #password
        );

        $channel = $connection->channel();

        $channel->queue_declare(
            self::QUEUE_NAME,    #имя очереди, такое же, как и у отправителя
            false,         #пассивный
            false,         #надёжный
            false,        #эксклюзивный
            false       #автоудаление
        );

        $channel->basic_consume(
            self::QUEUE_NAME,             #очередь
            '',                #тег получателя - Идентификатор получателя, валидный в пределах текущего канала. Просто строка
            false,                 #не локальный - TRUE: сервер не будет отправлять сообщения соединениям, которые сам опубликовал
            true,                   #без подтверждения - отправлять соответствующее подтверждение обработчику, как только задача будет выполнена
            false,                 #эксклюзивная - к очереди можно получить доступ только в рамках текущего соединения
            false,                   #не ждать - TRUE: сервер не будет отвечать методу. Клиент не должен ждать ответа
            array($this, 'processOrder')    #функция обратного вызова - метод, который будет принимать сообщение
        );

        while (count($channel->callbacks)) {
            $channel->wait();
        }

        $channel->close();
        $connection->close();
    }

    public function processOrder($msg)
    {
        var_dump($msg->body);
    }
}
