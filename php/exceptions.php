<?php

//1. НЕ БРОСАТЬ абстрактные исключения throw new Exception()
//2. Исключения должны быть иерархичны:
//Exception -> базовый класс -> базовый класс модуля -> все остальные исключения
class BaseException extends Exception{

    public function __construct($message = '', $code = 0){

        parent::__construct($message, $code);
    }
}



//3. Не обрабатывать исключения, если не понятно как их обработать
//4. Документировать исключения
/**
 * @throws BaseException выбрасывает базовое исключение
 */
try{
} catch(\Exception $e){
    throw new BaseException($e->getMessage(), $e->getCode(), $e);
}



//5. Должен быть один глобальный обработчик
//6. Не глушить исключения без обертки
try{
    //$app=>init();
} catch (\Exception $e){
    error_log($e->getMessage());
}



//7. Пример исключения 'Не найден пользователь'
class User{
    public $name = '';
    public $email = '';
}

class UserNotFoundException extends BaseException{

    protected $user = null;

    public function __construct(User $user){

        $this->user = $user;

        parent::__construct('Не найден пользователь', 0);
    }

    public function getUser(){

        return $this->user;
    }
}



//8. Преобразовывать в исключения:
// - все assertion fail
// - некритичные ошибки
// - return false или null В СЛУЧАЯХ ОШИБКИ
// - в else и switch..default В ИСКЛЮЧИТЕЛЬНОМ СЛУЧАЯХ если не сработал ни один if/case
// - в первом if($id === 0) throw new BaseException()
// - собачки (@$someValue) вместо isset
//т.к. брошенное исключние невозможно не заметить
