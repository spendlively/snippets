<?php

use GuzzleHttp\Client;
use GuzzleHttp\Promise;

chdir(__DIR__);

require '../vendor/autoload.php';

$client = new Client([
    'base_uri' => 'http://guzzle.local',
]);

$promises = [
    $client->getAsync('/sleep/one.php'),
    $client->getAsync('/sleep/two.php'),
    $client->getAsync('/sleep/three.php'),
];

$results = Promise\settle($promises)->wait();

foreach ($results as $result) {

    echo "<pre>";
    var_dump($result['value']->getBody()->getContents());
}
