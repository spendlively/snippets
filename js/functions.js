//Вернуть новый массив из массива
let students = [{age: 20}, {age: 21}, {age: 22}];
let ages = students.map(s => s.age);
console.log("1) ages: ", ages);


//Вернуть аккумулятор из массива
let summaryAge = students.map(s => s.age).reduce((sum, age) => sum + age);
console.log("2) summary age: ", summaryAge)


//Вернуть аккумулятор из аргументов с преобразованием типов
function sumWithTypeConv() {
    return Array.from(arguments).reduce((a, b) => Number(a) + Number(b), 0)
}

console.log("3) sum with type conversation: ", sumWithTypeConv(1, "2"));


//Вернуть обрезанный массив по значению элемента
//Удаление элемента из массива полностью вместе с ключом
let arr = [1, 2, 3],
    el = 2;

arr.splice(arr.indexOf(el), 1);
console.log("4) splice: ", arr);


//Вернуть отфильтроывнный массив
//Очистка от нечисловых элементов в функциональном стиле
function clean(elements) {
    return elements.filter((el) => !isNaN(Number(el)))
}

let numbers = [1, "2", "three"];
console.log("5) clean: ", clean(numbers));

function sumWithClean() {
    return clean(Array.from(arguments)).reduce((a, b) => Number(a) + Number(b), 0)
}

console.log("6) sum with clean: ", sumWithClean(1, '2', "three"));


//Валидация массива
//Верификация нечисловых элементов в функциональном стиле
function verify(elements) {
    elements.forEach((el) => {
        if (isNaN(Number(el))) throw new Error("Not a number")
    })
}

try {
    console.log("7) verify: ", verify([1, "2"]));
    // console.log("7) verify: ", verify([1, "2", "qwerty"]));
} catch (e) {
    console.log(e);
}

//Функция сложения чисел (с верификацией/очисткой) в функциональном стиле
function sumWithVerify() {
console.log(Array.from(arguments))
    return verify(Array.from(arguments)).reduce((a, b) => Number(a) + Number(b), 0)
}
console.log("8) sum with verify: ", sumWithVerify(1, 2, "3"));
