<?php

namespace Vendor\Package;

use FooInterface;
use BarClass as Bar;
use OtherVendor\OtherPackage\BazClass;

class Foo extends Bar implements FooInterface
{
    public $foo1 = null;

    public $foo2 = false;

    public $foo3 = true;

    public function sampleFunction($a, $b = null)
    {
        if ($a === $b) {
            bar();
        } elseif ($a > $b) {
            $foo->bar($arg1);
        } else {
            BazClass::bar($arg2, $arg3);
        }

        switch ($a) {
            case 0:
                echo 'First case, with a break';
                break;
            case 1:
                echo 'Second case, which falls through';
            // no break
            case 2:
            case 3:
            case 4:
                echo 'Third case, return instead of break';
                return;
            default:
                echo 'Default case';
                break;
        }

        while (1) {

        }
    }

    final public static function bar()
    {
        // тело метода
    }
}
