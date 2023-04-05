//Как происходит событие
// 1. Стадия перехвата (capturing stage)
// Событие сначала идет сверху вниз: window->Document->html->body->div->...
// 2. Стадия цели (target stage)
// Событие достигло целевого элемента
// 3. Стадия всплытия (bubbling stage)
// После этого событие начинает всплывать div->body->html->Document->window



//Событие onclick
// <input value="Нажми меня" onclick="alert(this.innerHTML)" type="button">
elem.onclick = function(){alert( 'Спасибо' );};



//Добавления нескольких обработчиков события с помощью addEventListener
element.addEventListener("click", foo);
element.removeEventListener("click", foo);
//Если функцию не сохранить в foo, то потом обработчик не снять



//Добавления нескольких обработчиков события в IE8
//Чтобы обойти можно подключить polyfill.io
element.attachEvent("on" + event, handler);
element.detachEvent("on" + event, handler);



//Остановка всплытия и предотвращение обработки по умолчанию
event.stopPropagation();//препятствует продвижению события, но на текущем элементе все обработчики отработают
event.stopImmediatePropagation();//предотвращает всплытие и останавливает обработку событий на текущем элементе
event.preventDefault();//предотвращение обработки по умолчанию (например переход по ссылке)
// return false;



//Получение объекта события
event = event || window.event;



//Генерация событий на элементах
var event = new Event("click");
elem.dispatchEvent(event);



//Custom событие
elem.addEventListener("hello", function(event){
    console.log(event.detail.name );
}, false);
var event = new CustomEvent("hello", {
    detail: {name: "Вася"}
});
elem.dispatchEvent(event);



//Custom событие мыши
var event = document.createEvent("MouseEvent");
event.initMouseEvent("click", true, true, null, 0, 0, 0, 100, 100, true, true, true, null, 1, null);
elem.dispatchEvent(event);

