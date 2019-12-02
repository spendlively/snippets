<?php

use GuzzleHttp\Client;
use GuzzleHttp\Promise;

chdir(__DIR__);

require '../vendor/autoload.php';

$client = new Client([
    'base_uri' => 'http://guzzle.local',
]);

$response = $client->request('GET', '/sleep/one.php');
print_r($response->getBody()->getContents());
