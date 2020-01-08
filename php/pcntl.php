<?php

//Создание форка
$pid = pcntl_fork();
if ($pid !== 0) {
    printf("Parent process start (Pid = %s)\n", posix_getpid());

    //Приоритет родительского процесса
    pcntl_setpriority(10);
    sleep(100);

    printf("Parent process end (Pid = %s)\n", posix_getpid());
} else {
    printf("Child process start (Pid = %s)\n", posix_getpid());

    //Приоритет дочернего процесса
    pcntl_setpriority(50);
    sleep(100);

    printf("Child process end (Pid = %s)\n", posix_getpid());
}
