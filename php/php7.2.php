<?php

////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////PHP 7.2//////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////Новый тип object//////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
function test(object $obj) : object
{
    return new SplQueue();
}

test(new StdClass());





////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////Расширение типа параметра/////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
interface A
{
    public function Test(array $input);
}

class B implements A
{
    public function Test($input){} // тип параметра не указан $input
}





////////////////////////////////////////////////////////////////////////////////////////
//////////Разрешена завершающая запятая для сгруппированных пространств имён////////////
////////////////////////////////////////////////////////////////////////////////////////
use Foo\Bar\{
    Foo,
    Bar,
    Baz,
};
