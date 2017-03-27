<?php

//GET
$curl = curl_init('http://ya.ru');
curl_exec($curl);
curl_close($curl);



//GET with headers
$curl = curl_init('http://ya.ru');
curl_setopt($curl, CURLOPT_HEADER, true);
curl_exec($curl); // выполняем запрос curl
curl_close($curl);



//POST
$curl = curl_init('http://php.su/forum/loginout.php');
curl_setopt($curl, CURLOPT_POST, 1);
curl_setopt ($curl, CURLOPT_USERAGENT, "Mozilla/5.0 (бла бла бла..) ");
$headers = array
(
    'Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*;q=0.8',
    'Accept-Language: ru,en-us;q=0.7,en;q=0.3',
    'Accept-Encoding: deflate',
    'Accept-Charset: windows-1251,utf-8;q=0.7,*;q=0.7'
);
curl_setopt($curl, CURLOPT_HTTPHEADER,$headers);
curl_setopt($curl, CURLOPT_REFERER, "http://php.su/forum/loginout.php");
curl_setopt($curl, CURLOPT_POSTFIELDS, 'action=login&imembername=valenok&ipassword=ne_skaju&submit=%C2%F5%EE%E4');
curl_setopt($curl, CURLOPT_COOKIEJAR, "my_cookies.txt");
curl_setopt($curl, CURLOPT_COOKIEFILE, "my_cookies.txt");
curl_setopt($curl, CURLOPT_RETURNTRANSFER, 1);
$result = curl_exec($curl); // выполняем запрос curl
curl_close($curl);

