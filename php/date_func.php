<?php

//date.timezone = Asia/Novosibirsk
date_default_timezone_set('Asia/Novosibirsk');



//set locale utf8
setlocale(LC_ALL, 'ru_RU.UTF-8');



//current time 
time();
strtotime('now');



//current time + 1 week
time() + 60*60*24*7;
strtotime('+1 week');



//5 ways to set a certain date
strtotime('+1 week 2 days 3 hours 4 minutes 5 seconds');
strtotime('12/28/2013');
strtotime('2013-12-28 22:59:59');
strtotime('+1 week 2 days 3 hours 4 minutes 5 seconds', time());
mktime(23, 59, 59, 12, 31, 2013);



//assoc array about date/time
getdate();
getdate(time());



//formatting
date('y-n-j G:i:s');
date('Y-m-d H:i:s');
