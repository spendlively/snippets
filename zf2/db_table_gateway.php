<?php

include "./vendor/autoload.php";

use Zend\Db\Adapter\Adapter;
use Zend\Db\ResultSet\ResultSet;
use Zend\Db\TableGateway\AbstractTableGateway;

class User{

    public $id;
    public $name;

    /**
     * Преобразователь данных, обязателен для передачи Test в setArrayObjectPrototype
     *
     * @param $data
     */
    public function exchangeArray($data){

        $this->id = isset($data['id']) ? $data['id'] : null;
        $this->name = isset($data['name']) ? $data['name'] : null;
    }
}

class UserTableGateway extends AbstractTableGateway{

    public $table = 'test';

    public function __construct(Adapter $adapter){

        $this->adapter = $adapter;

        $this->resultSetPrototype = new ResultSet();
        $this->resultSetPrototype->setArrayObjectPrototype(new User());
//        $this->resultSetPrototype->setArrayObjectPrototype(new ArrayObject());

        $this->initialize();
    }

    public function fetchAll(){

        $resultSet = $this->select();

        return $resultSet;
    }

    public function getUser($id){

        $id = (int)$id;
        $resultSet = $this->select(array(
            'id' => $id,
        ));
        $row = $resultSet->current();

        return $row;
    }

    public function saveUser(User $user){

        $data = array(
            "name" => $user->name,
        );

        if($user->id === null){
            $this->insert($data);
        }
        else{
            $this->update($data, array("id" => $user->id));
        }
    }

    public function deleteUser($id){
        $id = (int)$id;
        $this->delete(array('id' => $id));
    }
 }

//Подключение
$adapter = new Adapter(array(
    'driver' => 'Pdo_Mysql',
    'database' => 'rsduadmin',
    'username' => 'rsduadmin',
    'password' => 'passme',
));

//Создание объекта TableGateway
$userTableGateway = new UserTableGateway($adapter);

//Выборка всех данных
$resultSet = $userTableGateway->fetchAll();
foreach($resultSet as $row){
    var_dump($row);
}

//Выборка одной записи
var_dump($userTableGateway->getUser(1));

//Вставка данных
$user1 = new User();
$user1->name = 'Oleg';
$userTableGateway->saveUser($user1);

//Обновление данных 
$user2 = new User();
$user2->id = 1;
$user2->name = 'Petr';
$userTableGateway->saveUser($user2);

//Удаление
$userTableGateway->deleteUser(2);
