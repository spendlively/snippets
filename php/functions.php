<?php

//Создание массива, содержащиего названия переменных и их значения
$a = 'а';
$b = 'б';
$all = compact('a', 'b');



//Инициализация переменные на основе массива
list($a, $b, $c) = array(1, 2, 3);



//Выполнение кода прямо перед окончанием работы скрипты
register_shutdown_function('my_shutdown');
function my_shutdown(){
    var_dump('Bye-bye!');
}



//Подсветка кода php
highlight_string('<?php phpinfo(); ?>');



