
//Готово DOM дерево
$(document).ready(function () {
    console.log('ready');
});



//Загружена вся страница с учетом всех внешних ресурсов (картинок, сценариев, стилей)
$(window).load(function () {
    console.log('load');
});



//Cобытие "click"
$("p").click(function(){
    console.log('click');
});



//Событие focus/blur
$("input").focus(function() {
    console.log('focus');
});



//Событие keydown/keyup
$(window).keydown(function (event) {
    switch (event.keyCode) {
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



//Событие keypress (символьная клавиша клавиатуры)
//(не срабатывает для функциональных клавиш (Shift, Ctrl, Alt и т.д.)
$(window).keypress(function (event) {
    console.log(event.charCode);
    console.log(String.fromCharCode(event.charCode));
});



//Событие mouseover/mouseout
$("div").mouseover(function(){
    console.log('mouseover');
});



//Событие hover(in, out) - привязка обработчиков mouseover и mouseout
$("div").hover(function(){
    console.log('mouseover');
}, function(){
    console.log('mouseout');
});



//Событие mousemove() - движение курсора по поверхности элемента
$("div").mousemove(function (e) {
    console.log(e.pageX, e.pageY);
});



//Метод on(событие, обработчик) - привязка обработчиков на события к объекту или объектам.
//Предусмотрено добавление дополнительных параметров.
//В отличии от addEventListener(), который может работать как на "перехвате"
$("ul").on("click", function (event) {
    $(event.target).css("background", "red");
});

