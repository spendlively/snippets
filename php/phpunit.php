<?php

//Installing php unit for php 7
//wget sudo https://phar.phpunit.de/phpunit.phar
//chmod +x phpunit.phar
//sudo mv phpunit.phar /usr/local/bin/phpunit
//phpunit --version



//Installing php unit for php 5
// wget https://phar.phpunit.de/phpunit-5.7.phar
// chmod +x phpunit-5.7.phar
// sudo mv phpunit-5.7.phar /usr/local/bin/phpunit
// phpunit --version



//Docs
//https://phpunit.de/manual/current/en/writing-tests-for-phpunit.html



//Test
//phpunit phpunit.php
//phpunit --verbose phpunit.php
//phpunit --bootstrap additional/User.php UserTest.php
//phpunit --bootstrap additional/User.php --testdox tests
use PHPUnit\Framework\TestCase;

class User{
	public $foo = 1;
}

class UserTest extends TestCase{





    /**
     * Simple tests
     */	
	public function testAll(){

		//Arrays
		$this->assertArraySubset(['key2' => ['value2']], ['key1' => ['value1'], 'key2' => ['value2'], 'key3' => ['value3']]);
		$this->assertArrayHasKey('key', ['key' => 'value']);
		$this->assertContains(2, [1, 2, 3]);
		$this->assertContainsOnly('string', ['string']);
		$this->assertCount(1, ['foo']);
		$this->assertEmpty([]);

		//Json
		$this->assertJsonStringEqualsJsonString(
		    json_encode(['key' => 'value']),
		    json_encode(['key' => 'value'])
		);

		//Simple types
		$this->assertNull(null);
		$this->assertInternalType('string', 'testting string');
		$this->assertEquals(1, 1);
		$this->assertGreaterThan(1, 2);
		$this->assertGreaterThanOrEqual(1, 2);
		$this->assertFalse(false);

		//Regexp
		$this->assertRegExp('/wer/', 'qwerty');
		$this->assertStringMatchesFormat('%d', '123');

		//Strings
		$this->assertStringEndsWith('y', 'qwerty');
		$this->assertStringStartsWith('q', 'qwerty');

		//Classes and Objects
		$user = new User();
		$this->assertObjectHasAttribute('foo', $user);
		$this->assertClassHasAttribute('foo', 'User');

		//Output
		$this->expectOutputString('foo');
        print 'foo';
	}





    /**
     * @dataProvider simpleProvider
     */
    public function testAdd($a, $b, $expected){
        $this->assertEquals($expected, $a + $b);
    }

    public function simpleProvider()
    {
        return [
            [0, 0, 0],
            [0, 1, 1],
            [1, 0, 1],
            [1, 1, 3]
        ];
    }
}
