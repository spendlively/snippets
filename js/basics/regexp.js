
//Поиск позиции первого вхождения
var text = "this is a test string";
console.log(text.search(/test/ui)); //8





//Поиск полной информации о вхождении
console.log(text.match(/test/ui));
// [(index):12 ["test", index: 8, input: "this is test string"]





//Разбиение на подстроки
console.log(text.split(/\s/, 2));
// ["this", "is"]





//Замена подстроки
console.log(text.replace(/\s/g, '-'));
// this-is-test-string
console.log(text.replace(/(this) (is)/, '$2 $1'));
// this is test string
console.log(text.replace(/.*/, '$&!'));
// this is a test string!





//Вызов метода регулярного выражения
console.log(/this/.test(text));
// true
console.log(/this/.exec(text));
// ["this", index: 0, input: "this is a test string"]





//Флаги
// i - поиск независимо от регистра
// g - поиск всех совпадений
// m - многострочный режим





//
