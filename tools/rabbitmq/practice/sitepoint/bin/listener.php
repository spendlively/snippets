#!/usr/bin/env php
<?php

chdir(dirname(__DIR__));

require_once('./vendor/autoload.php');

use App\Receiver;

$receiver = new Receiver();
$receiver->listen();
