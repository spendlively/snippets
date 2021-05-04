<?php

set_time_limit(0);

try {
    $imagePath = '/home/spendlively/common/downloads/quality/imagick/1.png';
    $image = new Imagick($imagePath);
    for ($i = 0; $i < 2; $i++) {
        $image->adaptiveSharpenImage(3, 1);
    }
} catch (ImagickException $e) {
    echo 'Ошибка: ', $e->getMessage();
    die();
}
header('Content-type: image/png');
echo $image;
