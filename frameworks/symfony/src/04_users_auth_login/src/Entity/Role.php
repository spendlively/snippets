<?php

namespace App\Entity;

class Role
{
    const ADMIN = 'ROLE_ADMIN';

    const USER = 'ROLE_USER';

    const MODERATOR = 'ROLE_MODERATOR';

    const DESIGNER = 'ROLE_DESIGNER';

    /**
     * Returns an array of available roles
     *
     * @return array
     */
    public static function getRoles()
    {
        return [
            'designer' => self::DESIGNER,
            'moderator' => self::MODERATOR,
            'admin' => self::ADMIN,
        ];
    }
}
