
//Селекторы
$("*").css("font-style", "italic");
$("p").css("color", "red");
$("p,ul").css("color", "red");
$("div p").css("color", "red");
$("p + div").css("color", "red");
$("div > span").css("color", "red");
$("div:has(ul)").css("background", "red");
$("p.red").css("color", "red");
$("p#red").css("color", "red");
$("span ~ p").css("color", "red"); //предшествует элемент "span" на том же уровне вложенности
$("a[target]").css("color", "red");
$("input[type=text]").val("admin");
$("a[href^='http://']").css("color", "red"); //начинается c "http://"
$("a[href$='.com']").css("color", "blue"); //заканчивается на ".com"
$("a[href*='html']").css("color", "green"); //который содержит "html"
