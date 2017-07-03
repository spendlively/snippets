<?php

include "./vendor/autoload.php";

use Zend\Db\Adapter\Adapter as DbAdapter;

//Подключение
$dbAdapter = new DbAdapter(array(
    'driver' => 'Pdo_Mysql',
    'database' => 'rsduadmin',
    'username' => 'rsduadmin',
    'password' => 'passme',
));

//Cоздание таблицы
$sqlCreate = "
    CREATE TABLE users (
    id INT(11) NOT NULL AUTO_INCREMENT,
    username VARCHAR(50) UNIQUE NOT NULL,
    password VARCHAR(32) NULL,
    real_name VARCHAR(150) NULL,
    PRIMARY KEY (id)
)";
$statement = $dbAdapter->query($sqlCreate);
$resultSet = $statement->execute();
//var_dump($resultSet);die();

//Создание записи
$sqlInsert = "
  INSERT INTO users (username, password, real_name)
  VALUES ('my_username', 'my_password', 'My Real Name')
";
$statement = $dbAdapter->query($sqlInsert);
$resultSet = $statement->execute();
//var_dump($resultSet);die();
