//Создание
//Создание элемента
var div = document.createElement('div');
//Создание текстового узла
var text = document.createTextNode('Тут был я');



//Создание и заполнение
var div = document.createElement('div');
div.className = "alert alert-success";
div.innerHTML = "<strong>Ура!</strong> Вы прочитали это важное сообщение.";



//Добавление элемента
//Добавление в конец
document.body.appendChild(el);
parentEl.insertBefore(el, null);
//Добавление в середину
parentEl.insertBefore(el, nextSibling);
//Добавление в начало
parentEl.insertBefore(el, parentEl.firstChild);
//Добавление соседа
div.parentNode.insertBefore(div2, div.nextSibling);



//Клонирование узлов
//Быстрее, чем пересоздавать большой элемент
//Клонирование полностью
elem.cloneNode(true);
//Клонирование без дочерних элементов
elem.cloneNode(false);



//Удаление
//Удаление элемента
parentElem.removeChild(elem);
//Удаление с заменой
parentElem.replaceChild(newElem, elem);
//Удаление напрямую без ссылки на родителя
elem.remove();



//Перемещение элемента на новое место
//Элемент автоматом удалится со старого места
var first = document.body.children[0];
var last = document.body.children[1];
document.body.insertBefore(last, first);



//Множественная вставка
//Не работает в Firefox до версии 8
elem.insertAdjacentHTML(where, "<ul><li>1</li><li>2</li><li>5</li></ul>");
// where:
// 'beforeBegin' - перед elem
// 'afterBegin' - внутрь elem, в самое начало
// 'beforeEnd' - внутрь elem, в конец
// 'afterEnd' - после elem
//Создаёт текстовый узел из строки text и вставляет его в указанное место относительно elem.
elem.insertAdjacentText(where, text)



//DocumentFragment