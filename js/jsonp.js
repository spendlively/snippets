
//1. JSONP - JSON with Paddings
//2. JSONP - JSON-данные завернутые в вызов уже объявленой функции
//3. Позволяет получить данные с другого домена
//4. Имя callback-функции как правило передается в запросе

//Отправка запроса
function addScript(src) {
  var elem = document.createElement("script");
  elem.src = src;
  document.head.appendChild(elem);
}

//Обработка ответа
function foo(json){
	console.log(json);
}

//Вызов
addScript("/test.jsonp?callback=foo");
// foo({
//   name: "Вася",
//   age: 25
// });
