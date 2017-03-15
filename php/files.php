<?php

//Write a string into the file with locking
$filename = '/tmp/test.txt';
if(is_writable(dirname($filename))){

    if(!$df = fopen($filename, 'w')){
        throw new \Exception('Can not open the file');
    }

    if(flock($df, LOCK_EX)){

        if(fwrite($df, "TEST") === FALSE) {
            throw new \Exception('Can not write to the file');
        }

        flock($df, LOCK_UN);
        fclose($df);
    }
    else{
        throw new \Exception('Can not lock the file');
    }
}
else{
    throw new \Exception('The directory is forbidden');
}



//Read a text from the file with locking
$filename = '/tmp/test.txt';
if(is_readable($filename)){

    if(!$df = fopen($filename, 'r')){
        throw new \Exception('Can not open the file');
    }

    //If file is locked for writing
    if(flock($df, LOCK_SH)){

        //1. Read string by string
        while(($str = fgets($df, 4096)) !== false ){
            echo $str . PHP_EOL;
        }

//        //2. Read char by char
//        while(($str = fgetc($df)) !== false ){
//            echo $str;
//        }

//        //3. Read a specified length of the text
//        echo fread($df, filesize($filename)) . PHP_EOL;

        flock($df, LOCK_UN);
        fclose($df);
    }
    else{
        throw new \Exception('Can not lock the file');
    }
}
else{
    throw new \Exception('File is forbidden or not exists');
}



//Полезные функции
//testing an end of the file
var_dump(feof(fopen('/tmp/test.txt', 'w')));

//Get file into array
var_dump(file('/tmp/test.txt'));

//Output the file by filename
readfile('/tmp/test.txt');
echo PHP_EOL;

//Output the file by descriptor
fpassthru(fopen('/tmp/test.txt', 'r'));
echo PHP_EOL;

//Get filesize in bytes
var_dump(filesize('/tmp/test.txt'));

//Get file's directory
var_dump(dirname('/tmp/test.txt'));

//Create a temporary file
$df = tmpfile();

//delete the file
unlink('/tmp/test.txt');
