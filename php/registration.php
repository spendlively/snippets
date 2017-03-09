<?php

//sudo apt install php7.0-mbstring

try {

	//Validate email
	$email = filter_input(INPUT_POST, 'email', FILTER_VALIDATE_EMAIL);
	if(!$email){
 		throw new Exception('Invalid email');
	}

	//Validate password
	$password = filter_input(INPUT_POST, 'password');
	if (!$password || mb_strlen($password) < 8) {
		throw new Exception('Password must contain 8+ characters');
	}

	//Create password hash
	$passwordHash = password_hash(
		$password,
		PASSWORD_DEFAULT,
		array('cost' => 12)
	);

	if ($passwordHash === false) {
		throw new Exception('Password hash failed');
	}

	//TODO: saving new user
} catch (Exception $e) {

	//Report error
	header('HTTP/1.1 400 Bad request');
	echo $e->getMessage();
}
