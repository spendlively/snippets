<?php

//Итерирование строки в php
$q = "aa";
for($i = 0; $i < 1000; $i++){
    echo $q++ . PHP_EOL;
}


//Хранение имени переменной
$a = 'b';
$b = 'c';
echo $$a;