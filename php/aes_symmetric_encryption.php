<?php

/**
 * Симметричное шифрование 32-х байтным (256 бит)
 * AES-ключом с кодом аутентификацией GCM
 *
 * $iv - Initialization Vector
 * $tag - HMAC (hash-based message authentication code)
 *
 * GCM - https://ru.wikipedia.org/wiki/Galois/Counter_Mode
 */

const ENCRYPTION_METHOD = 'AES-256-GCM';
$bytes = openssl_random_pseudo_bytes(32);
$key = bin2hex($bytes);

function encryptData($data, $key)
{
    $iv = openssl_random_pseudo_bytes(openssl_cipher_iv_length(ENCRYPTION_METHOD));
    $encrypted = openssl_encrypt($data, ENCRYPTION_METHOD, $key, 0, $iv, $tag);
    return $encrypted . ':' . base64_encode($iv) . ':' . base64_encode($tag);
}

function decryptData($data, $key)
{
    list($encryptedData, $iv, $tag) = explode(':', $data, 3);
    return openssl_decrypt($encryptedData, ENCRYPTION_METHOD, $key, 0, base64_decode($iv), base64_decode($tag));
}

$encrypted = encryptData('Hello, World!', $key);
$decrypted = decryptData($encrypted, $key);

var_dump($decrypted);
