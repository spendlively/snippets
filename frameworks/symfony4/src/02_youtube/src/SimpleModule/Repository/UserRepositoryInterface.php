<?php


namespace App\SimpleModule\Repository;


use App\SimpleModule\Model\User;

interface UserRepositoryInterface
{
    public function all(): array;

    public function save(User $user): User;
}
