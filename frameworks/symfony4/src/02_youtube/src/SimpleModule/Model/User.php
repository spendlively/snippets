<?php

namespace App\SimpleModule\Model;

use Doctrine\ORM\Persisters\Entity;
use Doctrine\ORM\Mapping as ORM;

/**
 * Class User
 * @package App\SimpleModule\Model
 * @ORM\Entity(repositoryClass="App\SimpleModule\Repository\UserRepository")
 */
class User
{
    /**
     * @var int
     * @ORM\Id()
     * @ORM\Column(type="integer", length=11)
     * @ORM\GeneratedValue()
     **/
    private $id;

    /**
     * @var string
     * @ORM\Column(type="string", length=255)
     **/
    private $name;

    /**
     * @var int
     * @ORM\Column(type="integer", length=3)
     **/
    private $age;

    /**
     * @var string
     * @ORM\Column(type="text")
     **/
    private $information;

    public function __construct(string $name, int $age, string $information = null)
    {
        $this->name = $name;
        $this->age = $age;
        $this->information = $information;
    }

    /**
     * @return int
     */
    public function getId(): int
    {
        return $this->id;
    }

    /**
     * @return string
     */
    public function getName(): string
    {
        return $this->name;
    }

    /**
     * @return int
     */
    public function getAge(): int
    {
        return $this->age;
    }

    /**
     * @return string
     */
    public function getInformation(): string
    {
        return $this->information;
    }
}
