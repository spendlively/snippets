<?php

foreach (scandir('./') as $filename) {
    if($filename === '.' || $filename === '..' || $filename === 'index.php' || $filename === 'sleep') continue;

    printf('<h3><a href="/%s" target="_blank">%s</a><h3>', $filename, $filename);
}
