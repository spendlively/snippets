<?php

//Installing
//sudo apt-get install memcached php5-memcache
//sudo netstat -netulap | grep memcache



//Storing a session (php.ini)
//session.save_handler = memcache
//session.save_path = "tcp://localhost:11211"
//session.save_path=”tcp://127.0.0.1:11211?persistent=1&weight=1&timeout=1&retry_interval=15″
ini_set('session.save_handler', 'memcache');
ini_set('session.save_path', 'tcp://localhost:11211');
session_start();
if(empty($_SESSION['key'])){
    $_SESSION['key'] = time();
}
var_dump($_SESSION);



//Connecting
$memcache = new \Memcache();
$memcache->connect('127.0.0.1', 11211, 1);
//$memcache->pconnect('127.0.0.1', 11211, 1);
//var_dump($memcache->getExtendedStats());
//var_dump($memcache->getServerStatus('127.0.0.1'));
//$memcache->close();



//Saving a new data for 60 seconds without gzip
$memcache->set('key', 111, false, 60);
var_dump($memcache->get('key'));



//Adding data if not exists, if exists returns false
$memcache->add('key', 222, false, 60);
var_dump($memcache->get('key'));



//Replacing an existing data
$memcache->replace('key', 333, false, 60);
var_dump($memcache->get('key'));



//Incrementing/decrementing
$memcache->increment('key', 100);
var_dump($memcache->get('key'));
$memcache->decrement('key', 33);
var_dump($memcache->get('key'));



//Deleting
//$memcache->delete('key');
//var_dump($memcache->get('key'));



//Clear whole storage
//$memcache->flush();





