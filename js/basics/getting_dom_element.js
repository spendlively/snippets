
//document -> document.documentElement -> document.body
//html
document.documentElement;
//body
document.body;



//Ссылки на соседние элементы
// children
// firstChild
// lastChild
// childNodes
// parentNode
// nextSibling



//6 основных методов для поиска
// getElementById (везде)
// getElementsByName (везде)
// getElementsByTagName (везде)
// getElementsByClassName (кроме IE8-)
// querySelector (везде)
// querySelectorAll (везде)



//Поиск по ID (только у document)
document.getElementById("123");



//Поиск по имени
document.getElementsByName("age");
element.getElementsByName("age");



//Поиск по имени тэга (у document и у элемента)
document.getElementsByTagName("div");
document.getElementsByTagName('*');
element.getElementsByTagName("div");



//Поиск по классу
//Не поддерживается в IE8
document.getElementsByClassName('article');



//Поиск по селектору css (>= IE8+)
document.querySelectorAll('ul > li:last-child');
document.querySelectorAll(':hover');
document.querySelector('ul > li:last-child');
document.querySelector(':hover');
element.querySelectorAll('ul > li:last-child');
element.querySelectorAll(':hover');
element.querySelector('ul > li:last-child');
element.querySelector(':hover');





////////////////////////////////////////////////////////////////
///////////////////////ДОПОЛНИТЕЛЬНО////////////////////////////
////////////////////////////////////////////////////////////////

//Проверка удовлетворяет ли элемент селектору (false/true)
//Не поддерживается в IE8
//Старое имя matchesSelector, либо с префиксами ms/moz/webkit
element.matches('a[href$="zip"]');



//Поиск ближайшего элемента clsest(selector)
//Слабо поддерживается
element.closest('li');



//Поиск по xpath
var result = document.evaluate(
    "//h2[contains(., 'XPath')]",
    document.documentElement,
    null,
    XPathResult.ORDERED_NODE_SNAPSHOT_TYPE, null
);
