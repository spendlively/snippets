
// Готово DOM дерево
$(document).ready(function () {
    alert("Document loaded");
});

// load() - устанавливает обработчик на JavaScript событие load
// window.load - Загружена вся страница с учетом всех внешних ресурсов (картинок, сценариев, стилей)
$(window).load(function () {
    alert("Window loaded");
});

//добавляет обработчик на JavaScript событие "click"
$("p").click(function(){
    alert("clicked");
});

//focus - событие происходит, когда элемент получает фокус
$("input").focus(function() {
    $(this).val("focus");
});

//blur - событие происходит, когда элемент теряет фокус
$("input").blur(function() {
    $(this).val("blur");
});

// keydown() - устанавливает обработчик события keydown для каждого элемента набора.
// event - объект, определяющий информацию о событии.
$(window).keydown(function (event) {
    switch (event.keyCode) {// event.keyCode - код нажатой клавиши
        case 37: {
            alert("left pushed");
        }
            break;
        case 38: {
            alert("up pushed");
        }
            break;
        case 39: {
            alert("right pushed");
        }
            break;
        case 40: {
            alert("down pushed");
        }
            break;
    }
});

// keyup() - создает обработчик на событие keyup для каждого элемента набора.
$(window).keyup(function (event) {
    switch (event.keyCode) {
        case 37: {
            alert("left poped");
        }
            break;
        case 38: {
            alert("up poped");
        }
            break;
        case 39: {
            alert("right poped");
        }
            break;
        case 40: {
            alert("down poped");
        }
            break;
    }
});

// keypress - событие, которое возникает при нажатии символьной клавиши клавиатуры
// (не срабатывает для функциональных клавиш (Shift, Ctrl, Alt и т.д.)
$(window).keypress(function (event) {
    alert(String.fromCharCode(event.charCode) + "(" + event.charCode + ")");
});

// mouseover(f) - функция, которая принимает и назначает функцию "f" как обработчик на событие mouseover для каждого элемента набора.
// событие происходит при входе курсора в область элемента.
$("div:first").mouseover(function () { overCount++; Update(); }) // курсор попадает в область элемента

// mouseout(f) - функция, которая принимает и назначает функцию "f" как обработчик на событие mouseout для каждого элемента набора.
// событие происходит при выходе курсора в область элемента.
$("div:last").mouseout(function () { outCount++; Update(); }) // курсор выходит за область элемента

// hover(in, out) - функция, которая отвечает за привязку обработчиков на события mouseover и mouseout.
$("div").hover(function(){}, function(){});

//mousemove() - функция, устанавливающая обработчик на событие движения курсора по поверхности элемента.
$("div").mousemove(function (e) {
    e.pageX;
    e.pageY;
});

//Метод on(событие, обработчик) используется для привязки обработчиков на события к объекту или объектам.
//принимает в качестве аругментов событие и функцию обработчик
//Предусмотрено добавление дополнительных параметров. В отличии от addEventListener(), который может работать как на "перехвате"
$("ul").on("click", function (event) {
    $(event.target).css("background", "red");
});

