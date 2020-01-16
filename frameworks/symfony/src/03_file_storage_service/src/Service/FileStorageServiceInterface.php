<?php


namespace App\Service;


interface FileStorageServiceInterface
{
    public function getContent(): array;

    public function setContent(array $content): void;
}
