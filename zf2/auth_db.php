<?php

include "./vendor/autoload.php";

use Zend\Authentication\AuthenticationService;
use Zend\Db\Adapter\Adapter as DbAdapter;
use Zend\Authentication\Adapter\DbTable as AuthAdapter;

//Таблицы и пользователь создаются в файле db_query.php

//Создание адаптер БД
$dbAdapter = new DbAdapter(array(
    'driver' => 'Pdo_Mysql',
    'database' => 'rsduadmin',
    'username' => 'rsduadmin',
    'password' => 'passme',
));

//Создание сервиса аутентификации
$authenticationService = new AuthenticationService();

//Проверка сессии до
var_dump($authenticationService->getIdentity());

//Параметры таблицы для аутентификации
$tablename = 'users';
$identityColumn = 'username';
$credentialColumn = 'password';

//Создание адаптера для подключения в БД
$authAdapter = new AuthAdapter($dbAdapter);
$authAdapter
    ->setTableName($tablename)
    ->setIdentityColumn($identityColumn)
    ->setCredentialColumn($credentialColumn)
;

//Данные пользователя
$username = 'my_username';
$password = 'my_password';
$realname = 'my_real_name';

//Ввод данных пользователя
$authAdapter
    ->setIdentity($username)
    ->setCredential($password)
;

//Попытка аутентификации
$result = $authenticationService->authenticate($authAdapter);

//Проверка результата аутентификации
if ($result->isValid()) {
    $storage = $authenticationService->getStorage();
    $storage->write($authAdapter->getResultRowObject(array(
        $username,
        $realname,
    )));

    $storage->write($authAdapter->getResultRowObject(
        null,
        $password
    ));

    //Проверка сессии после
    var_dump($authenticationService->getIdentity());

} else {
    var_dump("{$username} identified by {$password} is not valid ");
    $authenticationService->clearIdentity();
}
