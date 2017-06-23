<?php

$filename = realpath('/retro/DA_ARC_54_1/DA_ARC_54_1_DT21062017.db');
$tablename = 'DA_ARC_54_1';

try{
$pdo = new \PDO('sqlite:' . $filename);
$pdo->setAttribute(\PDO::ATTR_ERRMODE, \PDO::ERRMODE_EXCEPTION);

    $st = $pdo->query("SELECT * FROM {$tablename} LIMIT 10");

    while ($row = $st->fetch(\PDO::FETCH_ASSOC)){
        var_dump($row);
    }
} catch(\Exception $e){
    var_dump($e->getMessage());
}

