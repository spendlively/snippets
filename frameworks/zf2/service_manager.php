<?php

//Сохранение сервиса "массив"
require 'vendor/autoload.php';

use Zend\ServiceManager\ServiceManager;

$sm = new ServiceManager();

$arrayService = array('qwerty' => 123456);
$sm->setService('arrayService', $arrayService);

echo "<pre>";
var_dump($sm->get('arrayService'));
echo "</pre>";





//Вызов serviceManager из контроллера
// $this->getServiceLocator()

