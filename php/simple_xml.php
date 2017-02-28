<?php


//save xml 1
$xml = new SimpleXMLElement('<root><user age="30">1</user></root>');
$xml->saveXML('/tmp/1.xml');



//save xml 2
$xml = simplexml_load_string('<root><user>2</user></root>');
$xml->asXml('/tmp/2.xml');



//load xml from file
$xml = simplexml_load_file('/tmp/1.xml');
$xml->asXml();



//get node value
$xml->user[0];



//Xpath releative searching
$nodes = $xml->xpath('user');
$nodes[0];



//Xpath
$xml->xpath('user[@age]');
$xml->xpath('user[age=\'30\']');
$xml->xpath('user[attribute::age=\'30\']');



//count
$xml->count();



//Adding a node
$xml->addChild('user', '3');



//Adding an attr
$xml->user[1]->addAttribute('age', '33');



//Getting an attr
$xml->user[1]->attributes()->age;



//Deleting a node
unset($xml->user[1]);
