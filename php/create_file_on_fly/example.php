<?php

use Symfony\Component\Mime\Part\DataPart;

$json = "";
$fp = @fopen("php://memory", "r+");
fputs($fp, $json);
rewind($fp);
$jsonFileField = new DataPart($fp, 'points.json', 'json/application');
