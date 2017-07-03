<?php

require '../vendor/autoload.php';

use  Zend\ModuleManager\ModuleManager;

$config = [
    'Zend\Router',
    'Zend\Validator',
    'Application',
];

$mm = new ModuleManager($config);

echo "<pre>";
var_dump($mm);
echo "</pre>";