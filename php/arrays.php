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





//array_reduce - average from array of objects
$ratesSum = array_reduce($rates, function ($carry, $rate) {

    if (!$rate instanceof Rate) {
        throw new WrongClassException();
    }

    $carry += $rate->getRate();

    return $carry;
}, 0);

$averageRate = $ratesSum / count($rates);




//array_sum(array_map()) - average from array of objects
$ratesSum = array_sum(
    array_map(
        function(Rate $rate): float
        {
            return $rate->getRate();
        },
        $rates
    )
);
$averageRate = $ratesSum / count($rates);

