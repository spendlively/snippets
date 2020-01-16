<?php


namespace App\Service;


use App\Entity\User;
use App\Repository\UserRepositoryInterface;

class UserService implements UserServiceInterface
{
    private $userRepository;

    public function __construct(UserRepositoryInterface $userRepository)
    {
        $this->userRepository = $userRepository;
    }

    public function getAllUsers()
    {
        return $this->userRepository->findAll();
    }

    public function addUser(User $user)
    {
        return $this->userRepository->save($user);
    }

    public function getUserById($id)
    {
        return $this->userRepository->find($id);
    }

    public function deleteUser(User $user)
    {
        $this->userRepository->delete($user);
    }
}
