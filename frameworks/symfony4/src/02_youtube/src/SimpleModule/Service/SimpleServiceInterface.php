<?php


namespace App\SimpleModule\Service;


use App\SimpleModule\Repository\UserRepositoryInterface;

interface SimpleServiceInterface
{

    public function test(): string;

    public function allUsers(): array;
}
