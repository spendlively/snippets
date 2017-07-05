<?php

//Файл в картинкой
$image = '/tmp/1.jpg';

//Кодируем файл в base64
$imageData = base64_encode(file_get_contents($image));

//Формат src: data:{mime};base64,{data};
$src = "data: {mime_content_type($image)};base64,{$imageData}";

//Вывод изображения
echo '<img src="', $src, '">';
