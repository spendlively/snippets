<?php 


//Installing Reddis
//https://anton.logvinenko.name/en/blog/how-to-install-redis-and-redis-php-client.html
//https://scotch.io/tutorials/getting-started-with-redis-in-php





//Connecting to Redis
$redis = new Redis();
$redis->connect('127.0.0.1', 6379); 
// var_dump($redis->ping());die();





//Single value
$redis->set("single", "value1"); 
// var_dump($redis->get("single")); 





//List of values
$redis->rpush("languages", "french"); // [french]
$redis->rpush("languages", "arabic"); // [french, arabic]
$redis->lpush("languages", "english"); // [english, french, arabic]
$redis->lpush("languages", "swedish"); // [swedish, english, french, arabic]
$redis->lpop("languages"); // [english, french, arabic]
$redis->rpop("languages"); // [english, french]
$redis->llen("languages"); // 2
$redis->lrange("languages", 0, -1); // returns all elements
$redis->lrange("languages", 0, 1); // [english, french]






//Hashes
$key = 'linus torvalds';
$redis->hset($key, 'age', 44);
$redis->hset($key, 'country', ';finland');
$redis->hset($key, 'occupation', 'software engineer');
$redis->hset($key, 'reknown', 'linux kernel');
$redis->hset($key, 'to delete', 'i will be deleted');
$redis->get($key, 'age'); // 44
$redis->get($key, 'country'); // Finland
$redis->del($key, 'to delete');
$redis->hincrby($key, 'age', 20); // 64
$redis->hmset($key, [
    'age' => 44,
    'country' => 'finland',
    'occupation' => 'software engineer',
    'reknown' => 'linux kernel',
]);
$data = $redis->hgetall($key);
// print_r($data); // returns all key-value that belongs to the hash





//Increment and decrement
$redis->set("count", 0);
$redis->incr("count"); // 1
$redis->incr("count"); // 2
$redis->decr("count"); // 1
$redis->incrby("count", 15); // 15
$redis->incrby("count", 5);  // 20
$redis->decrby("count", 10); // 10
// var_dump($redis->get("count"));





//Sets
$key = "countries";
$redis->sadd($key, 'china');
$redis->sadd($key, ['england', 'france', 'germany']);
$redis->sadd($key, 'china'); // this entry is ignored
$redis->srem($key, ['england', 'china']);
$redis->sismember($key, 'england'); // false
$redis->smembers($key); // ['france', 'germany']





//Set expiry
// $key = "expire in 1 hour";
// $redis->expire($key, 3600); // expires in 1 hour
// $redis->expireat($key, time() + 3600); // expires in 1 hour
// sleep(600); // don't try this, just an illustration for time spent
// $redis->ttl($key); // 3000, ergo expires in 50 minutes
// $redis->persist($key); // this will never expire.





//Other
//Getting all keys
// var_dump($redis->keys("*"));
// var_dump($redis->exists('key'));