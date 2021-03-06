
////////////////////////////////////////////////////////
///////////////////////Стили////////////////////////////
////////////////////////////////////////////////////////
//Возвращает или изменяет значения css
$("p").css("color", "green");
$("p").css({
    color: "green",
    backgroundColor: "lightgray"
});

//Доступ к HTML атрибуту первого тэга, который был выбран селектором
$("p").attr("style");

//Передача в метод attr() JSON-объекта
$("p").attr({
    style: "color:red; font-size:22pt",
    title: "JQuery Attr Test"
});

//Удаление атрибута style
$("p:odd").removeAttr("style");

//Установка значеня атрибута "class"
$("p").attr("class", "testClass");




////////////////////////////////////////////////////////
////////////////Аттрибуты без значений//////////////////
////////////////////////////////////////////////////////
//Возвращение или изменение свойств
$("input").prop("checked");
$("input").attr("checked");

//Удаляет свойства
$("input").removeProp("secretCode");

//Атрибут value
$("#edit1").val("Hello world");
$("#edit1").val();



////////////////////////////////////////////////////////
////////////////////////Классы//////////////////////////
////////////////////////////////////////////////////////
//Добавляет класс (не заменяет уже существующие)
$("#First").addClass("testClassGreen");

//Удаляет заданные классы
$(".class1").removeClass("class1");

//Добавляет или удаляет
$("p").toggleClass("class1");

//Проверяет наличие класса
$("p:first").hasClass('className');

//Установка значеня атрибута "class"
$("p").attr("class", "testClass");



////////////////////////////////////////////////////////
///////////////////////Размеры//////////////////////////
////////////////////////////////////////////////////////
//Возвращают/изменяет высоту
$("div").height();
$("div").innerHeight(); //высота элемента с учетом размера внутренних отступов (padding)
$("div").outerHeight(); //высота элемента с учетом внутренних отступов и рамки (border-width)
$("div").outerHeight(true); //высота элемента с учетом внутренних отступов, рамки (border-width) и внешних отступов

//Возвращают/изменяет ширину
$("div").width();
$("div").innerWidth(); //ширина элемента с учетом размера внутренних отступов (padding).
$("div").outerWidth(); //ширина элемента с учетом внутренних отступов и рамки (border-width)
$("div").outerWidth(true); //ширина элемента с учетом внутренних отступов, рамки (border-width) и внешних отступов

//Возвращает/изменяет координаты выбранного элемента относительно начала страницы
$("div").offset();

//Возвращают координаты выбранного элемента относительно ближайшего родителя,
//у которого задан тип позиционирования (css-свойство position равно relative или absolute или fixed).
$("#child").position();

//Возвращает ближайшего предка (т.е. из числа: родитель, прародитель, и так далее, до начало дерева DOM),
//у которого задан тип позиционирования (position равен relative или absolute или fixed).
$(".inner").offsetParent();
