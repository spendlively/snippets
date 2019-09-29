<?php


namespace App\SimpleModule\Repository;


use App\SimpleModule\Model\User;
use Doctrine\Bundle\DoctrineBundle\Repository\ServiceEntityRepository;
use Doctrine\Common\Persistence\ManagerRegistry;
use Doctrine\Common\Persistence\ObjectManager;

class UserRepository extends ServiceEntityRepository implements UserRepositoryInterface
{

    private $register;

    private $manager;

    public function __construct(ManagerRegistry $registry, ObjectManager $manager){

        parent::__construct($registry, User::class);

        $this->register = $registry;
        $this->manager = $manager;
    }

    public function all(): array {
        $users = parent::findAll();
        return $users;
    }

    public function save(User $user): User
    {
        return $user;
    }
}
