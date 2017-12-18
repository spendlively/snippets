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



//Форматирование чисел (7 знаков после запятой)
$scale = number_format($scale, 7, ".", "");



//Поиск файлов по шаблону
$files = glob('*.php');
$files = glob('*.{php,txt}', GLOB_BRACE);

$files = glob('../images/a*.jpg');
$files = array_map('realpath',$files);



//Генерация уникальных id
//with prefix
echo uniqid('foo_');
//with more entropy
echo uniqid('',true);
//both
uniqid('bar_',true);



//Сжатие строк
$string = "qwerty";
$compressed = gzcompress($string);
$original = gzuncompress($compressed);



//Информация о процессоре и памяти
memory_get_usage();
memory_get_peak_usage();
getrusage();



//