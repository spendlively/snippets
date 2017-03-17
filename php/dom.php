<?php

//DOM
//ЧТЕНИЕ XML ДОКУМЕНТА
$xml = <<<'NOWDOC'
<?xml version="1.0" encoding="UTF-8"?>
<catalog>
<book>
<author age="33">Pushkin</author>
</book>
</catalog>
NOWDOC;



//Создание объекта XML
$dom = new DOMDocument('1.0', 'utf-8');



//Открытие файла
//$dom->load($file);

//Загрузка XML-строки
$dom->loadXML($xml);



//Обход дерева
foreach($dom->childNodes as $nodes1){
    if($nodes1->childNodes){
        foreach($nodes1->childNodes as $nodes2){
            if($nodes2->childNodes){
                foreach($nodes2->childNodes as $nodes3){
                    var_dump($nodes3->nodeName);
                    var_dump($nodes3->nodeValue);
                }
            }
        }
    }
}



//XPath
$xpath = new DOMXpath($dom);
//$elements = $xpath->query("//*[@age]");
//$elements = $xpath->query("/catalog/book/author[@age='33']");
$elements = $xpath->query("*/author[@age='33']");
if (!empty($elements)) {
    foreach ($elements as $element) {
        echo $element->nodeName. "=";
        $nodes = $element->childNodes;
        foreach ($nodes as $node) {
            echo $node->nodeValue. "\n";
        }
    }
}



//СОЗДАНИЕ XML ДОКУМЕНТА
//Получение корневого узла
$root = $dom->documentElement;



//Создание новых элементов
$book = $dom->createElement('book');
$title = $dom->createElement('title');



//Создание текстового узла
$text = $dom->createTextNode('PHP 5');



//Добавление узлов
$title->appendChild($text);
$book->appendChild($title);
$root->appendChild($book);



//Сохранение документа
$dom->save("test2.xml");
