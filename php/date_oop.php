<?php

//date.timezone = 'Asia/Novosibirsk';
date_default_timezone_set('Asia/Novosibirsk');



//DateTime
//Output formatted date
$datetime = new DateTime();
// echo $datetime->format('Y-m-d H:i:s');

//create from format
$datetime = DateTime::createFromFormat('Y-m-d H:i:s', '2017-03-07 13:53:22');
// echo $datetime->format('Y-m-d H:i:s');



//DateInterval
//Output date plus 2 weeks
$datetime = new DateTime('2014-01-01 14:00:00');
$datetime->add(new DateInterval('P2W'));
// echo $datetime->format('Y-m-d H:i:s');



//DateTimeZone
//Setting timezones
$datetime = new DateTime('2014-08-20', new DateTimeZone('America/New_York'));
//Changing timezones
$datetime = new DateTime('2014-08-20', new DateTimeZone('America/New_York'));
$datetime->setTimezone(new DateTimeZone('Asia/Hong_Kong'));



//DatePeriod
$dateStart = new \DateTime();
$dateInterval = \DateInterval::createFromDateString('-1 day');
$datePeriod = new \DatePeriod($dateStart, $dateInterval, 3, DatePeriod::EXCLUDE_START_DATE);
foreach ($datePeriod as $date) {
    echo $date->format('Y-m-d') . PHP_EOL;
}



//Date good extention
//nesbot/carbon
//https://github.com/briannesbitt/Carbon

echo PHP_EOL;