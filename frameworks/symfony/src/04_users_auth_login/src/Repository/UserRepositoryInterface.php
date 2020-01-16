<?php


namespace App\Repository;


use App\Entity\User;

interface UserRepositoryInterface
{
    public function save(User $user);

    public function delete(User $user);
}
