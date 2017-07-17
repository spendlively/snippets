
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

//выбирает все родительские элементы
$("span").parents();
$("span").parents("div");

//ближайший родительский элемент, которые соответствуют указанному селектору
$("span").closest("div");

//последующие родственные элементы для всех элементов существующего набора
$("p:first").next();

//предыдущие родственные элементы для всех элементов существующего набора
$("p").prev();

//поиск всех родственных элементов после текущего элемента
$("p.class1").nextAll()

//Поиск всех родственных элементов после текущего элемента до указанного селектора
$(".class1").nextUntil(".class2");

//поиск всех родственных элементов перед текущим элементом
$("p.class1").prevAll();
$("p.class1").prevAll("p");

//поиск всех родственных элементов перед текущим элементом до указанного селектора
$(".class1").prevUntil();
$(".class2").prevUntil(".class1");

//олучение всех родственных элементов
$(".highlight").siblings();

//добавляет предыдущий набор jQuery к текущему
//в пределах одной цепочки команд и возвращает объединенный набор
$("div") // берем div'ы
    .find("p") // находим дочерние параграфы
    .andSelf() // добалвяем в выборку div'ы
    .addClass("border");

//отменяет последнее деструктивное действие, возвращая
//тем самым набор элементов к его предыдущему состоянию (до деструктивной операции).
$("p") // находим все p
    .add("div").css("border", "1px solid red") // добавляем к выборке все div и задаем рамку
    .end().css("background-color", "green"); // убираем div, оставляя p и меняем фон

//получает HTML-содержимое первого элемента в наборе соответствующих элементов
//или устанавливает HTML-разметку для каждого совпавшего элемента
$("p").html();
$("p").html("<u>Hello world</u>");

//получает содержимое текста каждого элемента в наборе соответствующих элементов,
//в том числе их потомков, или устанавливает текстовое содержимое элементов набора.
$("p").text();
$("p").text("<a href=\"#\">Link</a>");

//добавляет контент внутрь каждого элемента набора.
//Добавляемый контент следует за уже существующим.
//Данный метод подобен применению appendChild.
$("table").append("<tr><td>3</td><td>4</td></tr>");

//добавляет все элементы набора к другому указанному набору элементов.
//Добавляемые элементы следуют после уже существующих.
$("<b>Hello world</b>").appendTo(".test");

//добавляет контент внутрь каждого элемента набора.
//Добавляемый контент следует перед уже существующим.
$("table").prepend("<tr><td>3</td><td>4</td></tr>");

//добавляет все элементы набора к другому указанному набору элементов.
//Добавляемые элементы следуют перед уже существующими
$("<b>Hello world</b>").prependTo(".test"); // Добавление контента в элемент ".test".

//вставляет каждый совпавший элемент набора в указанную конструкцию HTML кода.
//Этот процесс наиболее полезен для встраивания дополнительной структуры в документ
//без необходимости разрушения его первоначальных семантических свойств.
$("span").wrap("<div>");

//удаляет все содержимое из каждого элемента в наборе совпавших элементов.
$("p").empty();

//удаляет все совпавшие элементы из DOM.
//Эта функция НЕ удаляет элементы из объекта jQuery, позволяя Вам воспользоваться ими позже.
//Обратите внимание, начиная с версии 1.2.2 эта функция также удаляет все обработчики событий
//и внутренние закешированные данные.
$("span").remove();

