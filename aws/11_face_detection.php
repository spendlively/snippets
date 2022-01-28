<?php

$client = new RekognitionClient();

/**
 * 1. By file
 */
$filename = '/path/to/file.png';
$fp_image = fopen($filename, 'r');
$bytes = fread($fp_image, filesize($filename));
fclose($fp_image);

$result = $client->detectFaces([
    'Attributes' => ['ALL'],
    'Image' => [
        'Bytes' => $bytes,
    ]
]);


/**
 * 1. By s3 bucket key
 */
$prefix = 'prefix';
$filename = 'filename';
$result = $client->detectFaces([
    'Attributes' => ['ALL'],
    'Image' => [
        'S3Object' => [
            'Bucket' => 'worker-images.ws.pho.to',
            'Name' => sprintf('%s/%s', $prefix, $filename),
        ],
    ]
]);

$faceDetails = $result->get('FaceDetails');
