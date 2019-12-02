<?php

use GuzzleHttp\Client;
use GuzzleHttp\Exception\RequestException;
use GuzzleHttp\Promise;
use Psr\Http\Message\ResponseInterface;

chdir(__DIR__);

require '../vendor/autoload.php';

$client = new Client([
    'base_uri' => 'http://guzzle.local',
]);

$promise = $client->requestAsync('GET', '/sleep/one.php');
$promise->then(
    function (ResponseInterface $res) {
        echo $res->getStatusCode() . "\n";
    },
    function (RequestException $e) {
        echo $e->getMessage() . "\n";
        echo $e->getRequest()->getMethod();
    }
);

$promises = [$promise];
$results = Promise\settle($promises)->wait();

foreach ($results as $result) {

    echo "<pre>";
    var_dump($result['value']->getReasonPhrase());
}
