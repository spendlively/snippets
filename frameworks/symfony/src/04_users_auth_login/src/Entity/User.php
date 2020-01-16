<?php

namespace App\Entity;

use Doctrine\ORM\Mapping as ORM;
use Serializable;
use Symfony\Component\Security\Core\User\UserInterface;
use App\Entity\Role;

/**
 * @ORM\Table(name="app_users")
 * @ORM\Entity(repositoryClass="App\Repository\UserRepository")
 */
class User implements UserInterface, Serializable
{
    /**
     * @ORM\Column(type="integer")
     * @ORM\Id
     * @ORM\GeneratedValue(strategy="AUTO")
     */
    private $id;

    /**
     * @ORM\Column(type="string", length=25)
     */
    private $username;

    /**
     * @ORM\Column(type="string", length=25, nullable=true, options={"default": null})
     */
    private $lastname;

    /**
     * @ORM\Column(type="string", length=64)
     */
    private $password;

    /**
     * @ORM\Column(type="string", length=254, unique=true)
     */
    private $email;

    /**
     * @ORM\Column(type="text", nullable=true, options={"default": null})
     */
    private $description;

    /**
     * @ORM\Column(type="array", nullable=true)
     */
    private $roles;

    /**
     * @ORM\Column(name="is_active", type="boolean")
     */
    private $isActive;

    /**
     * @param mixed $id
     */
    public function setId($id): void
    {
        $this->id = $id;
    }

    /**
     * @param mixed $username
     */
    public function setUsername($username): void
    {
        $this->username = $username;
    }

    /**
     * @param mixed $lastname
     */
    public function setLastname($lastname): void
    {
        $this->lastname = $lastname;
    }

    /**
     * @param mixed $password
     */
    public function setPassword($password): void
    {
        $this->password = $password;
    }

    /**
     * @param mixed $email
     */
    public function setEmail($email): void
    {
        $this->email = $email;
    }

    /**
     * @param mixed $description
     */
    public function setDescription($description): void
    {
        $this->description = $description;
    }

    public function addRole($role)
    {
        if (!in_array($role, $this->roles)) {
            $this->roles[] = $role;
        }
        return $this;
    }

    public function removeRole($role)
    {
        if (($key = array_search($role, $this->roles)) !== false) {
            unset($this->roles[$key]);
        }
        return $this;
    }

    /**
     * @param mixed $isActive
     */
    public function setIsActive($isActive): void
    {
        $this->isActive = $isActive;
    }

    public function __construct($options = [])
    {
        $this->id = isset($options['id']) ? $options['id'] : null;
        $this->username = isset($options['username']) ? $options['username'] : null;
        $this->lastname = isset($options['lastname']) ? $options['lastname'] : null;
        $this->password = isset($options['password']) ? $options['password'] : null;
        $this->email = isset($options['email']) ? $options['email'] : null;
        $this->description = isset($options['description']) ? $options['description'] : null;
        $this->roles = isset($options['roles']) ? $options['roles'] : [ROLE::USER];
        $this->isActive = isset($options['isActive']) ? $options['isActive'] : 1;
    }

    public function getId()
    {
        return $this->id;
    }

    public function getUsername()
    {
        return $this->username;
    }

    public function getLastname()
    {
        return $this->lastname;
    }

    public function getEmail()
    {
        return $this->email;
    }

    public function getPassword()
    {
        return $this->password;
    }

    public function getDescription()
    {
        return $this->description;
    }

    public function getRoles()
    {
        return $this->roles;
    }

    /**
     * @return int|mixed
     */
    public function getIsActive()
    {
        return $this->isActive;
    }

    /**
     * Method is only meant to clean up possibly stored plain text passwords (or similar credentials).
     * Be careful what to erase if your user class is also mapped to a database
     * as the modified object will likely be persisted during the request.
     */
    public function eraseCredentials()
    {
    }

    /**
     * At the end of each request, the User object is serialized to the session.
     * On the next request, it's unserialized.
     * To help PHP do this correctly, you need to implement Serializable.
     *
     * @see \Serializable::serialize()
     */
    public function serialize()
    {
        return serialize(array(
            $this->id,
            $this->username,
            $this->lastname,
            $this->password,
            $this->email,
            $this->description,
        ));
    }

    /**
     * @param $serialized
     * @see \Serializable::unserialize()
     */
    public function unserialize($serialized)
    {
        list (
            $this->id,
            $this->username,
            $this->lastname,
            $this->password,
            $this->email,
            $this->description,
            ) = unserialize($serialized, array('allowed_classes' => false));
    }

    /**
     * Returns the salt that was originally used to encode the password.
     *
     * This can return null if the password was not encoded using a salt.
     *
     * @return string|null The salt
     */
    public function getSalt()
    {
        // TODO: Implement getSalt() method.
    }
}
