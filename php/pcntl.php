<?php

/////////////////////////////////////////////
///////////Один дочерний процесс/////////////
/////////////////////////////////////////////
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



/////////////////////////////////////////////
////////Несколько дочерних процессов/////////
/////////////////////////////////////////////
$urls = ['url1', 'url2', 'url3'];
function download($urls)
{
}

if (!function_exists('pcntl_fork')) die('Pcntl is not available');

$pids = [];
foreach ($urls as $i => $url) {
    $pids[$i] = pcntl_fork();
    if (!$pids[$i]) {
        download($url);
        exit();
    }
}

foreach ($urls as $i => $url) {
    pcntl_waitpid($pids[$i], $status, WUNTRACED);
}
