#!/usr/bin/env php
<?php

chdir(dirname(__DIR__));

require_once('./vendor/autoload.php');

use App\Sender;

$simpleSender = new Sender();
$simpleSender->execute("Hello, World!");
