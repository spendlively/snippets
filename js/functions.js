
//Удаление элемента из массива полностью вместе с ключом
var arr = [1, 2, 3],
	el = 2;

arr.splice(arr.indexOf(el), 1);
console.log(arr);