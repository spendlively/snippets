<?php

//SPLFileInfo
$fileName = '/tmp/';
$fileInfo = new SPLFileInfo($fileName);
var_dump($fileInfo->getPath());
var_dump($fileInfo->getSize());
var_dump($fileInfo->isFile());
var_dump($fileInfo->isDir());



//SplFileObject - построчная итерация файла
$it = new SplFileObject('/etc/hosts');
foreach($it as $line) {
    var_dump($line);
}
