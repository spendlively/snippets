
//3 ways to create object
function c1(name){this.name = name;};
var o1 = new c1('o1'),
    o2 = {
        name: 'o2'
    },
    o3 = Object.create(null); //null или prototype





//Prototype inheritance
//1. Простой способ (deprecated)
var parent = {};
var child = {};
child.__proto__ = parent;

//2. Простой способ с использованием конструкторов (deprecated)
function parent(){};
function child(){};
var c = new child();
c.__proto__ = parent.prototype;

//3. Создание объекта с указанием прототипа
var parent = {};
var child = Object.create(parent);

//4. Использование конструкторов
function parent(){};
function child(){};
child.prototype = new parent();

//5. Самый правильный способ - использование функции
function inherit(child, parent){
    function f(){};
    f.prototype = parent.prototype;
    child.prototype = new f();
    //плюшки
    child.prototype.constructor = child;
    child.superclass = parent.prototype;
    return child;
}

