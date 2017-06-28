<?php

/////////////////////////////////////////////////////////
//////////SplDoublyLinkedList - Двусвязный список////////
/////////////////////////////////////////////////////////

//SplStack — Стек
$stack = new SplStack();

$stack->push(1);
$stack->push(2);
$stack->push(3);

var_dump($stack->count()); //3
var_dump($stack->top()); //3
var_dump($stack->bottom()); //1
var_dump($stack->serialize()); //i:6;:s:1:"1";:s:1:"2";:s:1:"3";

var_dump($stack->pop()); //3
var_dump($stack->pop()); //2
var_dump($stack->pop()); //1



//SplQueue - Очередь
$queue = new SplQueue();

$queue->setIteratorMode(SplQueue::IT_MODE_DELETE);

$queue->enqueue(11);
$queue->enqueue(22);
$queue->enqueue(33);

var_dump($queue->dequeue()); //11
var_dump($queue->dequeue()); //22

var_dump($queue->top()); //33



/////////////////////////////////////////////////////////
//////////SplHeap - Куча (древовидная структура)/////////
/////////////////////////////////////////////////////////
//SplMaxHeap
$heap = new SplMaxHeap();
$heap->insert(222);
$heap->insert(333);
$heap->insert(111);

var_dump($heap->extract()); // 333
var_dump($heap->extract()); // 222
var_dump($heap->extract()); // 111

//SplMinHeap
$heap = new SplMinHeap();
$heap->insert(222);
$heap->insert(333);
$heap->insert(111);

var_dump($heap->extract()); // 111
var_dump($heap->extract()); // 222
var_dump($heap->extract()); // 333



//SplPriorityQueue - очередь с приоритетами
$queue = new SplPriorityQueue();
$queue->setExtractFlags(SplPriorityQueue::EXTR_DATA); // получаем только значения элементов

$queue->insert('Q', 1);
$queue->insert('W', 2);
$queue->insert('E', 3);
$queue->insert('R', 4);
$queue->insert('T', 5);
$queue->insert('Y', 6);

$queue->top();

while($queue->valid()){
    var_dump($queue->current()); //YTREWQ
    $queue->next();
}



//SplFixedArray - массив с фиксированным количеством элементов
//Подходит для нумерованных списков
$a = new SplFixedArray(10000);
$count = 100000;

for($i =0; $i<$count; $i++){
    $a[$i] = $i;
    if ($i==9999) $a->setSize(100000);
}



//SplObjectStorage - хранилище объектов
$s = new SplObjectStorage(); // создаем хранилище

$o1 = new StdClass;
$o2 = new StdClass;
$o3 = new StdClass;

$s->attach($o1); //прикрепляем к хранилищу объект
$s->attach($o2);

var_dump($s->contains($o1)); //bool(true)
var_dump($s->contains($o2)); //bool(true)
var_dump($s->contains($o3)); //bool(false)

$s->detach($o2); //открепляем объект от хранилища

var_dump($s->contains($o1)); //bool(true)
var_dump($s->contains($o2)); //bool(false)
var_dump($s->contains($o3)); //bool(false)



////SplObjectStorage - пример 2
$s = new SplObjectStorage();

$o1 = (object)array('a'=>1);
$o2 = (object)array('b'=>2);
$o3 = (object)array('c'=>3);

$s[$o1] = "data for object 1";
$s[$o2] = array(1,2,3);

foreach($s as $i => $key)
{
    var_dump("Entry $i:"); // You get a numeric index
    var_dump($key, $s[$key]);
    echo "\n";
}
