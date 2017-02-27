<?php

//Content-Type
if(!headers_sent()){
	header("Content-Type: text/html; charset=utf-8");
}



//Redirect
header("Location: http://ya.ru", true, 301);



//404
header("HTTP/1.0 404 Not Found");



//File downloading
$file = "/tmp/file.pdf";
if (file_exists($file)) {
    header('Content-Description: File Transfer');
    header('Content-Type: application/octet-stream');
    header('Content-Disposition: attachment; filename="'.basename($file).'"');
    header('Expires: 0');
    header('Cache-Control: must-revalidate');
    header('Pragma: public');
    header('Content-Length: ' . filesize($file));
    readfile($file);
    exit;
}

