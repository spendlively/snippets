//Creating an object
function User(name){

    this.name = name;

    this.login = function(){
        console.log('login ' + this.name);
    }
}

var user = new User('Олег');





//Inheritance in functional style
//Наследник не имеет доступа к приватным свойствам родителя
function Admin(name){
    User.apply(this, arguments);
}

var admin = new Admin('Вася');
admin.login();
