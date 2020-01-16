<?php


namespace App\SimpleModule\Service;


use App\SimpleModule\Repository\UserRepositoryInterface;

class SimpleService implements SimpleServiceInterface
{
    public $userRepository;

    public function __construct(UserRepositoryInterface $userRepository)
    {
        $this->userRepository = $userRepository;
    }

    public function test(): string
    {
        return 'Hi, from SimpleService::test()';
    }

    public function allUsers(): array {

        $users = $this->userRepository->all();

        return $users;
    }
}
