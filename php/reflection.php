<?php

class User{
    public $data = 1;
    public function getData(){
        return $this->data;
    }
    public function setData($data){
        $this->data = $data;
    }
}



//REFLECTION API
//Исследование классов с помощью ReflectionClass
$rc = new ReflectionClass('User');
//print_r(get_class_methods($rc));
$rc->getName();
$rc->getShortName();
$rc->hasMethod('getData');



//Исследование методов с помощью ReflectionMethod
$rm = new ReflectionMethod('User', 'getData');
$rm->isPublic();
//Вызов метода
$user = new User;
$rm->invoke($user);
$rm->invokeArgs($user, array());



//Исследование свойств с помощью ReflectionProperty
$rp = new ReflectionProperty('User', 'data');
$rp->getName();
$rp->setAccessible(true);
$user = new User;
$rp->getValue($user);



//Исследование параметров с помощью ReflectionParameter
$rp = new ReflectionParameter(array('User', 'setData'), 0); //0-ой параметр
$rp->isOptional();



//Исследование объектов с помощью ReflectionObject
$user = new User;
$ro = new ReflectionObject($user);
$ro->getNamespaceName();
