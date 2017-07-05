
//Фильтры
//Четные/нечетные
$("p:even").css("background-color", "red");
$("p:odd").css("background-color", "red");
//Первый/последний
$("li:first").css("color", "blue");
$("li:last").css("color", "red");
//Первый дочерний/последний дочерний
$("li:first-child").css("color", "blue");
$("li:last-child").css("color", "red");
//Единственный дочерний
$("div p:only-child").css("color", "blue");
//n-ный дочерний
$(".one tr:nth-child(7)").css("background-color", "lightblue");
$(".two tr:nth-child(even)").css("background-color", "lightblue");
$(".three tr:nth-child(odd)").css("background-color", "lightblue");
$(".four tr:nth-child(3n+1)").css("background-color", "lightblue");
//Выбор по индексу (eq - индекс начинается от нуля)
$("p:eq(3)").css("background-color", "#4dea4d");
$("p:gt(4)").css("background-color", "#4dea4d");
$("p:lt(4)").css("background-color", "#4dea4d");
//Инверсия
$("li:not(li:eq(3))").css("background-color", "yellow");
//Получение всех заголовков
$(":header").css("background-color", "#4dea4d");
//Элементы, в которых происходит анимация
$(":animated").css("background", "red");
//Все элементы, в которых встречается указанный текст.
$("p:contains('JavaScript')").css("background-color", "red");
//Все элементы в которых отсутствует содержимое
$("div:empty").css("background-color", "Red");
//Все элементы, которые содержат указанный в параметрах элемент
$("div:has(p)").css("background-color", "red");
//Все элементы img с атрибутом alt содержащим значение из списка значений, разделенных пробелом
$("img[alt~='new']").css("border", "4px solid #005cf2");
//Все элементы a с атрибутом target не равного _blank
$("a[target!=_blank]").css("background-color", "#9bff70");




//Фильтры форм
//все кнопки на странице.
$(":button").css("font-weight","bold");
//все элементы "checkbox".
var count = $(":checkbox").length;
//только отмеченные флажки или переключатели
var count = $("input:checked").length;
//элементы форм, находящиеся в неактивном состоянии
$("input:disabled").val("disabled");
//элементы форм, находящиеся в активном состоянии
$("input:enabled").val("enabled");
//все элементы типа "file"
$(":file").css("border", "1px solid red");

