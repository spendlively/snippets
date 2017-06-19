<?php

include "./vendor/autoload.php";

use Zend\Db\Sql\Sql;
use Zend\Db\Adapter\Adapter;

//Подключение
$adapter = new Adapter(array(
    'driver' => 'Pdo_Mysql',
    'database' => 'rsduadmin',
    'username' => 'rsduadmin',
    'password' => 'passme',
));

$sql = new Sql($adapter);
//$sql = new Sql($adapter, 'test');

$select = $sql->select();
$select->from('test');
$select->where(array('id' => 1));

$statement = $sql->prepareStatementForSqlObject($select);
$resultSet = $statement->execute();

foreach($resultSet as $row){
    echo "<pre>";
    print_r($row);
    echo "</pre>";
}
