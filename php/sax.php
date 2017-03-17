<?php

//SAX: Официальный сайт: http://www.saxproject.org/
//Описывает метод парсинга XML-документов для получения данных из них
//Создавать и изменять XML-документы с помощью SAX невозможно
//XML-парсеру предоставляется набор собственных
//функций для обработки различных типов XML-данных
//Парсер автоматически вызывает эти функции в процессе
//последовательной обработки XML-документа

$xml = <<<'NOWDOC'
<catalog>
<book>
<author age="33">Pushkin</author>
</book>
</catalog>
NOWDOC;

//Создание парсера с использованием кодировки utf-8
$sax = xml_parser_create('utf-8');

//Отключение опции  case-folding
xml_parser_set_option($sax, XML_OPTION_CASE_FOLDING, false);

//Пропускать значения, состоящие из пробелов.
xml_parser_set_option($sax, XML_OPTION_SKIP_WHITE, true);

//Функции - обработчики тэгов
xml_set_element_handler($sax, 'sax_start','sax_end');

//Функция - обработчик данных тэгов
xml_set_character_data_handler($sax, 'sax_cdata');

//Передаю строку, которую необходимо распарсить
//xml_parse($sax, file_get_contents('test.xml'),true);
xml_parse($sax, $xml, true);

//Обработка ошибок
var_dump(xml_error_string(xml_get_error_code($sax)));

//Освобождение анализатора
xml_parser_free($sax);

//Обработка открывающегося тэга
function sax_start($sax, $tag, $attr) {
    var_dump($tag);
    var_dump($attr);
}

//Обработка данных тэга
function sax_cdata($sax, $data) {
    var_dump($data);
}

//Обработка закрывающегося тэга
function sax_end($sax, $tag) {
    var_dump($tag);
}
