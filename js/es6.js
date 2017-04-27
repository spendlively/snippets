
//Деструктуризация
let [one, two] = [1, 2];

let {three, four} = {three: 3, four: 4};

function foo({one, two}){
	console.log(one, two);
}
foo({one: 1, two: 2});




//Spread оператор ...
let [five, six, ...rest] = "5 6 7 8 9".split(" ");

function bar(one, two, ...rest) {
	console.log(one, two, rest);
}
bar(1, 2, 3, 4);

let numbers = [1, 2, 3];
Math.max(1, 2, 3)
Math.max.apply(Math, numbers);
Math.max(...numbers);





//Стрелочные функции (нет своего this и arguments)
let foo1 = a => a + 1;
let foo2 = (a,b) => a + b;
let foo3 = (a,b) => { return a + b + 1 };
console.log(foo1(1), foo1(1, 2), foo1(1, 2));





//Шаблонизация с помощью `
console.log(`${one} + ${two} = ${one + two}`); //1 + 2 = 3





//Объекты и прототипы
//super и методы объекта
let animal = {
  walk() {
    console.log("walk");
  }
};
let rabbit = {
  __proto__: animal,
  walk() {
    super.walk();
  }
};
rabbit.walk();




//Object.assign
let target = {};
Object.assign(target, {one: 1}, {two: 2}, {three: 3})
console.log(target);





//Геттер-сеттер для прототипа
Object.setPrototypeOf(rabbit, animal);
console.log(Object.getPrototypeOf(rabbit));





//Классы
class User{

	constructor(name){
		this.name = name;
	}

  	get fullName(){
    	return `Mr. ${this.name}`;
  	}

	set fullName(name) {
    	this.name = `${name}`;
  	}

	foo(){
		return 'foo';
	}

	static bar() {
		return console.log('bar');
	}
}

class Admin extends User{}

let admin = new Admin("Ivan");
console.log(admin.name);
console.log(admin.fullName);
admin.fullName = 'Petr';
console.log(admin.fullName);
console.log(admin.foo());
console.log(Admin.bar());



//Set, Map, WeakSet и WeakMap

//Итераторы и генераторы

//Proxy

