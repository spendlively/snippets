<?php

set_time_limit(0);

try {
    $imagePath = '/home/spendlively/common/downloads/quality/imagick/2.png';
    $image = new Imagick($imagePath);
    for ($i = 0; $i < 2; $i++) {
        $image->sharpenimage(3, 1, Imagick::CHANNEL_DEFAULT);
    }
} catch (ImagickException $e) {
    echo 'Ошибка: ', $e->getMessage();
    die();
}
header('Content-type: image/png');
echo $image;
