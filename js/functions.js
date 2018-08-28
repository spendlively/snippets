
//Удаление элемента из массива полностью вместе с ключом
var arr = [1, 2, 3],
	el = 2;

arr.splice(arr.indexOf(el), 1);
console.log(arr);





//Очистка от нечисловых элементов в функциональном стиле
function clean(elements){
	return elements.filter((el) => !isNaN(Number(el)))
}





//Верификация нечисловых элементов в функциональном стиле
function verify(elements){
    elements.forEach((el) => {if(isNaN(Number(el))) throw new Error("Not a number")})
}





//Функция сложения чисел (с верификацией/очисткой) в функциональном стиле
function sum() {
    return Array.from(arguments).reduce((a, b) => Number(a) + Number(b), 0)
}
function sum() {
    return verify(Array.from(arguments)).reduce((a, b) => Number(a) + Number(b), 0)
}
function sum() {
    return clean(Array.from(arguments)).reduce((a, b) => Number(a) + Number(b), 0)
}
