<?php

include "./vendor/autoload.php";

use Zend\Db\Adapter\Adapter;
use Zend\Db\Adapter\Driver\ResultInterface;
use Zend\Db\ResultSet\ResultSet;

//Подключение
$adapter = new Adapter(array(
	'driver' => 'Pdo_Mysql',
	'database' => 'rsduadmin',
	'username' => 'rsduadmin',
	'password' => 'passme',
));



//Вставка
$adapter->query("INSERT INTO test (id, name) VALUES (NULL, 'Ivan')", Adapter::QUERY_MODE_EXECUTE);



//Выборка
$resultSet = $adapter->query("SELECT * FROM test WHERE id = ?", array(1));
foreach($resultSet as $row){
    echo "<pre>";
    print_r($row);
    echo "</pre>";
}



//Выборка с явным созданием Statement и ResultSet
$stmt = $adapter->createStatement('SELECT * FROM test WHERE id = ?', array(1));
$result = $stmt->execute();

if($result instanceof ResultInterface && $result->isQueryResult()){

    $resultSet = new ResultSet();
    $resultSet->initialize($result);

    foreach($resultSet as $row){
        echo "<pre>";
        print_r($row);
        echo "</pre>";
    }
}
