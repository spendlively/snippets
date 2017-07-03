<?php

$loader = require "./vendor/autoload.php";

class Student{

	public $name = '';
	public $surname = '';

	public function __construct($name, $surname){

		$this->name = $name;
		$this->surname = $surname;
	}
}

class ClassRoom{

	public $student = 'null';

	public function __construct(Student $student){

		$this->student = $student;
	}
}

$di = new \Zend\Di\Di();
$classRoom = $di->get('ClassRoom', array(
    'name' => 'Ivan',
    'surname' => 'Ivanov'
));

var_dump($classRoom); die();
