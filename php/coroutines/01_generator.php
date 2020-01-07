<?php

function getGenerator()
{

    $i = 0;
    while (true) {
        sleep(1);
        yield ++$i;
    }
}

$generator = getGenerator();

//foreach ($generator as $value){
//    var_dump($value);
//}

while($generator->valid()){

    var_dump($generator->current());
    sleep(1);
    $generator->next();

}
