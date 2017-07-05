
//Методы
//eq() позволяет выбрать элемент из массива по индексу
//индекс начинается от нуля
$('p').eq(0).text("Текст");

//сss() возвращает/задает вычесленный стиль элемента
$("*").css("font-style", "italic");

//инверсия
$('li').not(':eq(2)').css("color","red");

//Текст/html
$("p").text("Содержит текст TEST!");
$("p").html("тут нет ничего особенного.");

//проверяет на соответствие указанному выражению
$("div").is(":first-child");
$("div").is(".blue,.red");
$("div").is(":contains('Test')");

//получение соответствующих элементов по селектору с фильтрацией
$("p").filter(".test").css("background-color", "red");
$("p").filter(":odd").css("background-color", "green");
$("p").filter(function (index) {
    if ($(this).attr("align") && index == 0) {
        return true;
    }
}).css("background-color", "red");

//выделяет подмножество из набора совпавших элементов
$("p").slice(2, 4).css("background-color", "red");

//добавляет в уже существующий набор дополнительные элементы span
$("p").add("span").css("background-color", "Red");

//отыскивает дочерние элементы, соответствующие указанному выражению.
$("p").find("span").css('color', 'red');

//Превращает текстовые узлы внутри #content в параграфы (текстовые узлы: nodeType = 3)
$("#content").contents().filter(function () {
    return this.nodeType === 3;
}).wrap("<p></p>");

//получает все дочерние элементы p для элемента с классом class1
$(".class1").children("p").css("background-color", "Red");

//возвращает ссылку на ближайшего родителя
$(".class1").parent();

