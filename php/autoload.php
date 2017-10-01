<?php

//////////////////////////////////////////////////////////////////////////
///////////////////////Автозагрузчик в composer.json//////////////////////
//////////////////////////////////////////////////////////////////////////
//1. composer.json
'
{
  "autoload": {
    "psr-0": {
      //new \PSR0\MyClass() -> ./psr-0/PSR0/MyClass.php
      //new \PSR0\Another_MyClass() -> ./psr-0/PSR0/Another/MyClass.php (class Another_MyClass{})
      "PSR0\\": "psr0/"
    },
    "psr-4": {
      //new \PSR4\MyClass() -> ./psr-4/MyClass.php
      "PSR4\\": "psr4/"
    },
    "classmap": [
      //new \ClassMapNamespace\JustClass() -> ./classmap/MyClass.php
      "classmap/",
      //new \AnyNameSpace\JustClass() -> ./JustClass.php
      "JustClass.php"
    ],
    "files": [
      //Подгрузится файл functions.php с глобальными функциями 
      "functions.php"
    ]
  }
}
';

//2. Создание/обновление автозагрузчика
//composer dump-autoload

//3. Подключение автозагрузчика
//require_once __DIR__ . '/vendor/autoload.php';
//или
//require_once __DIR__ . '/../vendor/autoload.php';





//////////////////////////////////////////////////////////////////////////
//////////////////////////////Теория//////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//1. Регистрация своего (нескольких) автозагрузчика spl_autoload_register(function($classname){...});
//2. Автозагрузчики вызываются по очереди пока не будет найден класс
//3. Автозагрузчик не должен выдввать ошибку
//4. Функция __autoload() устарела так как не не позволяет использовать >1 загрузчика
//5. Стандартная функция загрузчик в php - spl_autoload()
//6. psr-4 - регистр имеет значение
//7. \\ это экранированный \ в json
//8. Что вызывает автозагрузчик
//    - new A();
//    - A::someMethod();
//    - if(class_exists('A')){...}
//9. Ссылки
//    - https://getcomposer.org/doc/04-schema.md#psr-4





//////////////////////////////////////////////////////////////////////////
///////////////////////Автозагрузчик в коде///////////////////////////////
//////////////////////////////////////////////////////////////////////////

//Подгрузка неймспейса в коде
// instantiate the loader
$loader = new \Example\Psr4AutoloaderClass;

// register the autoloader
$loader->register();

// register the base directories for the namespace    prefix
$loader->addNamespace('Foo\Bar', '/path/to/packages/foo-bar/src');
$loader->addNamespace('Foo\Bar', '/path/to/packages/foo-bar/tests');
