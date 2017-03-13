<?php

/////////////////////////////////////////////////////
///////////Узкоспециализированные запросы////////////
///////////////////Ad hoc query//////////////////////
/////////////////////////////////////////////////////
//Запрос для решение частной проблемы
//Полезно хранить в центролизованных библиотеках, чтобы не дублировать



/////////////////////////////////////////////////////
//////////////////Активная запись////////////////////
///////////////////Active Record/////////////////////
/////////////////////////////////////////////////////
//Класс имеет методы insert(), update(), delete() + поисковые методы
class User{

	public $id;
	public $name;

	public static function findByName($name){
		//SELECT * FROM user WHERE name LIKE $name
		//return new User();
	}

	public function __construct($id){
		//SELECT * FROM user WHERE id = $id
	}

	public function update(){
		//UPDATE
	}	
	
	public function insert(){
		//INSERT $this->id, $this->name
	}	
	
	public function delete(){
		//DELETE
	}	
}

$user = new User(1);
$user->name = 'Ivan';
$user->insert();



/////////////////////////////////////////////////////
///////////////Преобразователь (Mapper)//////////////
/////////////////////////////////////////////////////
class User2{

	public $id;
	public $name;

	public function __construct($id, $name){
		$this->id = $id;
		$this->name = $name;
	}
}

class Mapper{

	public static function findByName($name){
		//return new User2();
	}

	public static function findById($id){
		//return new User2();
	}

	public static function update(User2 $user){
		//UPDATE
	}	
	
	public static function insert(User2 $user){
		//INSERT
	}	
	
	public static function delete(User2 $user){
		//DELETE
	}	
}

$user = Mapper::findByName('Ivan');
$user->name = 'Petr';
Mapper::update($user);



/////////////////////////////////////////////////////
////////////Интегрированный преобразователь//////////
//////////////////Integrated mapper//////////////////
/////////////////////////////////////////////////////
//Нечто среднее