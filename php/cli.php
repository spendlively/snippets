#!/usr/local/bin/php

<?php

    echo "Args count: $argc" . PHP_EOL;

foreach($argv as $arg){
    var_dump($arg);
}
