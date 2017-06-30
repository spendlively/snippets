<?php

//ArrayIterator
$arr = array(0,1,2,3,4,5,6,7,8,9);
$arrayIterator = new ArrayIterator($arr);
foreach($arrayIterator as $value) {
    var_dump($value);
}



//ArrayIterator & LimitIterator
$arr = array(0,1,2,3,4,5,6,7,8,9);
$arrIterator = new ArrayIterator($arr);
$limitIterator = new LimitIterator($arrIterator, 3, 4);
foreach($limitIterator as $value) {
    var_dump($value); //3, 4, 5, 6
}



//AppendIterator
$arr1 = new ArrayIterator(array(1,2,3));
$arr2 = new ArrayIterator(array(4,5,6));
$iterator = new AppendIterator();
$iterator->append($arr1);
$iterator->append($arr2);
foreach($iterator as $value) {
    var_dump($value); //1, 2, 3, 4, 5, 6
}



//RecursiveArrayIterator
$arr = array(1, array(2, array(3)));
$recursiveArrayIterator = new RecursiveArrayIterator($arr);
foreach(new RecursiveIteratorIterator($recursiveArrayIterator) as $key => $value) {
    var_dump($value);
}



//FilterIterator
class GreaterThan3FilterIterator extends FilterIterator {
    public function accept() {
        return ($this->current() > 3);
    }
}
$arr = new ArrayIterator(array(1,2,3,4,5,6));
$iterator = new GreaterThan3FilterIterator($arr);
var_dump(iterator_to_array($iterator)); //4, 5, 6



//RegexIterator
$arr = array('abc','def', 'ghi', 'jkl');
$arrIterator = new ArrayIterator($arr);
$iterator = new RegexIterator($arrIterator, '/a|i/');
var_dump(iterator_to_array($iterator)); //abc, ghi



//DirectoryIterator
$pathName = '/tmp/';
foreach(new DirectoryIterator($pathName) as $fileInfo) {
    var_dump($fileInfo);
}



//RecursiveDirectoryIterator & RecursiveIteratorIterator
$pathName = '/tmp/';
$i = new RecursiveDirectoryIterator($pathName);
foreach(new RecursiveIteratorIterator($i) as $fileInfo) {
    var_dump($fileInfo);
}



//SplFileObject - построчная итерация файла
$it = new SplFileObject('/etc/hosts');
foreach($it as $line) {
    var_dump($line);
}
