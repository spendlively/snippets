<?php

//Создание форка
$pid = pcntl_fork();
if($pid !== 0){

    //Приоритет родительского процесса
    pcntl_setpriority(10);
    echo "Parent\n";
}
else{

    //Приоритет дочернего процесса
    pcntl_setpriority(50);
    echo "Child\n";
}
