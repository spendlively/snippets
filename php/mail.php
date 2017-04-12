<?php

//Send simple mail
mail("spendlively@mail.ru", "Subject", "Message");



//Send with headers
mail("spendlively@mail.ru", "Subjectt", "Message",
    "From: spendlively@yandex.ru\r\n"
    ."Reply-To: spendlively@yandex.ru\r\n"
    ."X-Mailer: PHP/" . phpversion());



//Send HTML message
$to= "Konstantin <spendlively@mail.ru>" . ", " ; //обратите внимание на запятую
$to .= "Spendlively <spendlively@yandex.ru>";
$subject = "Subject";
$message = '<html><head><title>Test</title></head><body><p>Test</p></body></html>';
$headers= "MIME-Version: 1.0\r\n";
$headers .= "Content-type: text/html; charset=utf-8\r\n";
$headers .= "From: Myself <spendlively@gmail.com>\r\n";
$headers .= "Cc: birthdayarchive@example.com\r\n";
$headers .= "Bcc: birthdaycheck@example.com\r\n";
mail($to, $subject, $message, $headers);

