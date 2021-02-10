<?php

use Aws\S3\S3Client;

$awsS3Client = new S3Client();
$bucket = 'bucket'; //required
$prefix = 'prefix'; //null or 'prefix'
$delimiter = null; //null or '/'

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

$keys = [];
$options = ['Bucket' => $bucket];
if ($prefix) $options['Prefix'] = $prefix;
if ($delimiter) $options['Delimiter'] = $delimiter;

try {
    $results = $awsS3Client->getPaginator('ListObjects', $options);

    foreach ($results as $result) {

        /**
         * If 'Delimiter' == '/', keys produced in 'CommonPrefixes' fields
         */
        if ($objects = $result->get('CommonPrefixes')) {
            foreach ($objects as $object) {
                if (!empty($object['Prefix'])) $keys[] = $object['Prefix'];
            }
        }

        /**
         * If 'Delimiter' == null, keys produced in 'Contents' fields
         */
        if ($objects = $result->get('Contents')) {
            foreach ($objects as $object) {
                if (!empty($object['Key'])) $keys[] = $object['Key'];
            }
        }
    }
} catch (S3Exception $e) {
//    $logger->error(sprintf('[S3 ListObjects Error] %s (file: %s, line: %s)', $e->getMessage(), __FILE__, __LINE__));
}

return $keys;
