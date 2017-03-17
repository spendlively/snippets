<?php

//Простой генератор, возвращающий значения
function gen1(){
    for($i = 0; $i < 10; $i++) yield $i;
}
foreach(gen1() as $value) echo $value . PHP_EOL;



//Простой генератор, возвращающий пару ключ/значение
function gen2(){
    for($i = 0; $i < 10; $i++) yield $i=>$i+1;
}
foreach(gen2() as $key => $value) echo $key . ' - ' . $value . PHP_EOL;



//Простой генератор и спользование методов send() и next();
function gen3(){
    echo yield . PHP_EOL; //1
    echo "===" . PHP_EOL; //===
    echo yield . PHP_EOL; //
    echo "===" . PHP_EOL; //===
    echo yield . PHP_EOL; //2
}
$generator = gen3();
$generator->send(1);
$generator->next();
$generator->send(2);
$generator->send(3);



//Комбинация ввода и вывода в генератор
function gen4(){
    echo (yield "Hello");
}
$generator = gen4();
echo $generator->current();
$generator->send(", World!");



//Правильное закрытие дескриптора файла в фукции, возвращающей генератор
function readErrorLog(){
    try{
        $f = fopen('/var/log/apache2/error.log', 'r');
        while(!feof($f)){
            yield fgets($f);
        }
    } finally {
        fclose($f);
    }
}
foreach(readErrorLog() as $line){
    echo $line . PHP_EOL;
}
