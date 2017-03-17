<?php

//RecursiveTreeIterator
$tree = array(
    'Web',
    array(
        'Search Engines',
        array('Google', 'Bing', 'Yahoo', array(1,2,3,4,5, array(6,7,8,9)))
    ),
    array(
        'Social Coding',
        array('GitHub', 'Forrst')
    )
);

$awesome = new RecursiveTreeIterator(
    new RecursiveArrayIterator($tree),
    null, null, RecursiveIteratorIterator::LEAVES_ONLY
);

foreach ($awesome as $line)
    echo $line.PHP_EOL;







//RecursiveArrayIterator
$myArray = array(
    0 => 'a',
    1 => array('subA','subB',array(0 => 'subsubA', 1 => 'subsubB', 2 => array(0 => 'deepA', 1 => 'deepB'))),
    2 => 'b',
    3 => array('subA','subB','subC'),
    4 => 'c',
    5 => array(6, array(7, array(8, array(9, array(10))))),
);

$iterator = new RecursiveArrayIterator($myArray);
iterator_apply($iterator, 'traverseStructure', array($iterator));

function traverseStructure($iterator) {
    while ( $iterator -> valid() ) {
        if ( $iterator -> hasChildren() ) {
            traverseStructure($iterator -> getChildren());
        }
        else {
            echo $iterator -> key() . ' : ' . $iterator -> current() .PHP_EOL;
        }
        $iterator -> next();
    }
}






//RecursiveArrayIterator 2
$data = [];
$dl = PHP_EOL;
$dl = "<br>";

$myArray = [
    1,
    [2],
    [3, [4]],
    [5, [6, [7]]]
];

$iterator = new RecursiveArrayIterator($myArray);
//iterator_apply($iterator, 'traverseStructure', array($iterator));


//echo "<pre>";
//print_r($myArray);
//print_r($data);
//echo "</pre>";

function traverseStructure2($iterator, &$data) {

    while($iterator->valid()){

        $key = $iterator->key();

        if($iterator->hasChildren()){
            $data[$key] = [];
            traverseStructure2($iterator->getChildren(), $data[$key]);
        }
        else{
            $data[$key] = $iterator->current();
        }
        $iterator->next();
    }

}

traverseStructure2($iterator, $data);
echo "<pre>";
print_r($myArray);
print_r($data);
echo "</pre>";







//RecursiveArrayIterator 3
$arr = [
    ["sitepoint", "phpmaster"],
    ["buildmobile", "rubysource"],
    ["designfestival", "cloudspring"],
    "not an array",
    [1, [2, [3, [4, [5, [6, [7, [8, [9]]]]]]]]]
];

$iterator = new RecursiveArrayIterator($arr);

foreach(new RecursiveIteratorIterator($iterator) as $key => $value) {
    echo $key . ": " . $value . PHP_EOL;
}

if($iterator->valid()){
    var_dump("hasChildren:" . $iterator->hasChildren());
    var_dump($iterator->current());

    $iterator->next();

    var_dump("hasChildren:" . $iterator->hasChildren());
    var_dump($iterator->current());
    var_dump($iterator->getChildren()->current());
}
