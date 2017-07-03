<?php

//Простое использование EventManager
require 'vendor/autoload.php';

use Zend\EventManager\EventManager;

$eventManager = new EventManager();

$eventManager->attach('do', function($e) {
    $event  = $e->getName();
    $params = $e->getParams();
    var_dump($event);
    var_dump($params);
});

$params = array('qwe' => 123);
$eventManager->trigger('do', null, $params);
