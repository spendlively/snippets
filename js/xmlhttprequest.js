
//Синхронный GET-запрос
var xhr = new XMLHttpRequest(),
	method = ,
	url = 'test.json',
	async = false;

xhr.open(method, url, async);
xhr.send();
if(xhr.status != 200){
	console.log(xhr.status + ': ' + xhr.statusText);
} 
else{
	console.log(xhr.responseText);
}





//Асинхронный GET-запрос (по умолчанию)
var xhr = new XMLHttpRequest();
xhr.open('GET', 'test.json', true);
xhr.onreadystatechange = function(){
	if(xhr.readyState != 4) return;
	if(xhr.status != 200){
		console.log(xhr.status + ': ' + xhr.statusText);
  	}
  	else{
		console.log(xhr.responseText);
	}
}
xhr.send();
//Состояния запроса xhr.readyState
// const unsigned short UNSENT = 0; // начальное состояние
// const unsigned short OPENED = 1; // вызван open
// const unsigned short HEADERS_RECEIVED = 2; // получены заголовки
// const unsigned short LOADING = 3; // загружается тело (получен очередной пакет данных)
// const unsigned short DONE = 4; // запрос завершён





//GET-запрос с параметрами
var xhr = new XMLHttpRequest();
var params = 'name=' + encodeURIComponent("Вася") +
  '&age=' + encodeURIComponent(25);
xhr.open("GET", '/test.json?' + params, true);
xhr.onreadystatechange = function(){
	if(xhr.readyState != 4) return;
	if(xhr.status != 200){
		console.log(xhr.status + ': ' + xhr.statusText);
  	}
  	else{
		console.log(xhr.responseText);
	}
}
xhr.send();





//POST-запрос с параметрами
//В стандартных HTTP-формах для POST доступны три кодировки, задаваемые через атрибут enctype:
// application/x-www-form-urlencoded
// multipart/form-data
// text-plain
var xhr = new XMLHttpRequest();
var body = 'name=' + encodeURIComponent("Вася") +
  '&age=' + encodeURIComponent(25);
xhr.open("POST", '/test.json', true)
xhr.setRequestHeader('Content-Type', 'application/x-www-form-urlencoded')
xhr.onreadystatechange = function(){
	if(xhr.readyState != 4) return;
	if(xhr.status != 200){
		console.log(xhr.status + ': ' + xhr.statusText);
  	}
  	else{
		console.log(xhr.responseText);
	}
}
xhr.send(body);

// У форм есть две основные кодировки: 
//  - application/x-www-form-urlencoded – по умолчанию и 
//  - multipart/form-data – для POST запросов, если явно указана в enctype. 
// Вторая кодировка обычно используется для больших данных и только для тела запроса.
// Для составления запроса в application/x-www-form-urlencoded используется функция encodeURIComponent.
// Для отправки запроса в multipart/form-data – объект FormData.
// Для обмена данными JS ↔ сервер можно использовать и просто JSON, желательно с указанием кодировки в заголовке Content-Type.





//HTTP-ЗАГОЛОВКИ
//Заголовки запроса
//Указание http-заголовков при запросе (нельзя указывать заголовки браузера: Referer или Host и др.)
//Указанный заголовок нельзя отменить, повторный хаголовок лишь добавит информацию
xhr.setRequestHeader('Content-Type', 'application/json');

//Заголовки ответа
//Получить значение заголовка
xhr.getResponseHeader('Content-Type');
xhr.getAllResponseHeaders();





//IE8, IE9
var XHR = ("onload" in new XMLHttpRequest()) ? XMLHttpRequest : XDomainRequest;
var xhr = new XHR();





//Антикэш заголовки
//Cache-Control: no-cache.
//или альтернативный способ
// xhr.open('GET', 'service?r=' + Math.random(), false);




//МЕТОДЫ
// open(method, url, async, user, password)
// send(body)
// abort()
// setRequestHeader(name, value)
// getResponseHeader(name)
// getAllResponseHeaders()

//СВОЙСТВА
// timeout
// responseText
// responseXML
// status
// statusText

//СОБЫТИЯ
// onreadystatechange
// ontimeout
// onerror
// onload
// onprogress
// onabort
// onloadstart
// onloadend