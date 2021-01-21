<?php

$bytes = openssl_random_pseudo_bytes(40);
$aesEncryptionKey = bin2hex($bytes);

function encryptData($data, $aesEncryptionKey)
{
    $encryptionKey = base64_decode($aesEncryptionKey);
    $iv = openssl_random_pseudo_bytes(openssl_cipher_iv_length('AES-256-GCM'));
    $encrypted = openssl_encrypt($data, 'AES-256-GCM', $encryptionKey, 0, $iv, $tag);
    return $encrypted . ':' . base64_encode($iv) . ':' . base64_encode($tag);
}

function decryptData($data, $aesEncryptionKey)
{
    $encryptionKey = base64_decode($aesEncryptionKey);
    list($encryptedData, $iv, $tag) = explode(':', $data, 3);
    return openssl_decrypt($encryptedData, 'AES-256-GCM', $encryptionKey, 0, base64_decode($iv), base64_decode($tag));
}

$encrypted = encryptData('Hello, World!', $aesEncryptionKey);
$decrypted = decryptData($encrypted, $aesEncryptionKey);

var_dump($decrypted);
