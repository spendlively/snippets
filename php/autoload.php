<?php

///////////////////////////////////////////////////////////////////////
//////////////////////////////////PSR-4////////////////////////////////
///////////////////////////////////////////////////////////////////////
//1. composer.json
'
{
    "autoload": {
        "psr-4": {
            "MyLibrary\\": "src/",
            "MyApp\\Plugins\\": "plugins/"
    }
}
';

//2. Создание автозагрузчика
//composer dump-autoload

//3. Подключение автозагрузчика
//require_once __DIR__ . 'vendor/autoload.php';

//4. Описание:
// - psr-4 - регистр имеет значение
// - \\ это экранированный \ в json
// - Примеры классов:
//    - MyLibrary\Some\Class -> src/Some/Class.php
//    - MyApp\Plugins\Some\Class -> plugins/Some/Class.php
// - Ссылки
//    - https://getcomposer.org/doc/04-schema.md#psr-4




//Dev-загрузчик
'
{
    "require-dev": {
    "phpunit/phpunit": "^5.5"
    },
    "autoload": {
    "psr-4": {
        "TDD\\": "src/"
        }
    },
    "autoload-dev": {
    "psr-4": {
        "TDD\\Test\\": "tests/"
        }
    }
}
';