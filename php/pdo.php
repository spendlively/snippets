<?php

$pdo = new \PDO('mysql:host=localhost;dbname=snippets;charset=utf8', 'ivan', 'passme');



//setAttribute
$pdo->setAttribute(\PDO::ATTR_ERRMODE, \PDO::ERRMODE_EXCEPTION);



//fetch
$dbh = $pdo->query("SELECT * FROM products");
if($dbh){
	$result = $dbh->fetch(\PDO::FETCH_ASSOC);
}



//fetchAll
$dbh = $pdo->query("SELECT * FROM products");
if($dbh){
	$result = $dbh->fetchAll(\PDO::FETCH_ASSOC);
}



//query execute
$dbh = $pdo->query("UPDATE products SET description = 'new description'");
if($dbh){
	$result = $dbh->execute();
}



// prepare execute insert
$dbh = $pdo->prepare("INSERT INTO products (id, title, description) VALUES (NULL, :title, :description)");
$title = 'coffee';
$dbh->bindParam(':title', $title);
$dbh->bindValue(':description', 'coffee description');
$dbh->execute();



//prepare execute select 1
$dbh = $pdo->prepare('SELECT * FROM products WHERE title = :title');
$dbh->bindValue(':title', 'tea', \PDO::PARAM_STR);
$dbh->execute();
$result = $dbh->fetchAll(\PDO::FETCH_ASSOC);



//prepare execute select 1
$dbh = $pdo->prepare('SELECT * FROM products WHERE title = :title'); 
$dbh->execute( array(':title' => 'tea')); 
$result = $dbh->fetchAll(\PDO::FETCH_ASSOC);



//transaction
$query = "INSERT INTO products (id, title, description) VALUES (NULL, :title, :description)";
try{
	$pdo->beginTransaction();
	$dbh = $pdo->prepare($query);
	$dbh->bindValue(':title', 'milk');
	$dbh->bindValue(':description', 'this is milk');
	$dbh->execute();
	$pdo->commit();
} catch(\Exception $e){
	$pdo->rollback();
}

