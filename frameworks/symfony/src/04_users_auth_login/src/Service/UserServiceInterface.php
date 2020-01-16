<?php


namespace App\Service;


use App\Entity\User;

interface UserServiceInterface
{
    public function getAllUsers();

    public function addUser(User $user);

    public function getUserById($id);

    public function deleteUser(User $user);
}