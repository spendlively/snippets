<?php

include "./vendor/autoload.php";

use Zend\Authentication\AuthenticationService;
use Zend\Authentication\Adapter\AdapterInterface;
use Zend\Authentication\Result;

class Adapter implements AdapterInterface{

    public $username = null;
    public $password = null;

    public function __construct($username, $password){

        $this->username = $username;
        $this->password = $password;
    }

    public function authenticate(){

        if($this->username === 'admin' && $this->password === 'passme'){
            return new Result(Result::SUCCESS, $this->username);
        }
        else{
            return new Result(Result::FAILURE, $this->username);
        }
    }
}

$auth = new AuthenticationService();
//Проверка до аутентификации
var_dump($auth->getIdentity());

//Вариант 1
$adapter = new Adapter('admin', 'passme');
$result = $auth->authenticate($adapter);
if(!$result->isValid()){
    $messages = $result->getMessages();
}
var_dump('Valid');

//Проверка после аутентификации 
var_dump($auth->getIdentity());
//$auth->clearIdentity();
