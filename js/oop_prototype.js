// ДОСТОИНСТВА перед функциональным стилем
// Функциональный стиль записывает в каждый объект и свойства и методы, а прототипный – только свойства.
// Поэтому прототипный стиль – быстрее и экономнее по памяти.
// НЕДОСТАТКИ перед функциональным стилем
// При создании методов через прототип,
// мы теряем возможность использовать локальные переменные как приватные свойства,
// у них больше нет общей области видимости с конструктором.


//Creating an object
function User(name){

    this.name = name;
}

User.prototype.login = function(){
    console.log('login ' + this.name);
};

var user = new User('Олег');





//Inheritance in prototype style
function Admin(name){
    User.apply(this, arguments);
}

Admin.prototype = Object.create(User.prototype);
Admin.prototype.constructor = Admin;

var admin = new Admin('Вася');
admin.login();




//Create an object without object prototype
//В obj не будет лишних свойств и методов стандартного прототипа
var obj = Object.create(null);
obj.text = "Hello";




//Object.create for old browsers: es5-shim




//Croass-browser Object.create
if (!Object.create) {

    Object.create = function(proto) {
        function F() {}
        F.prototype = proto;
        return new F;
    };

}