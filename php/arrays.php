<?php

////////////////////////////////////////////////////
///Sorting array by another array with filtering////
////////////////////////////////////////////////////
$priorities = array(
	'Ivan',
    'Petr',
);

$names = array(
	array('name' => 'Roman'),
	array('name' => 'Oleg'),
	array('name' => 'Petr'),
	array('name' => 'Ivan'),
);

$priorities = array_flip($priorities);

$names = array_filter($names, function($a) use ($priorities){

	return isset($priorities[$a['name']]);
});

usort($names, function($a, $b) use ($priorities){

	return $priorities[$a['name']] > $priorities[$b['name']];
});

var_dump($names);die();
