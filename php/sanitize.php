<?php


//Экранирование символов для командной строки
$escapedCommand = escapeshellcmd("cat /etc/hosts");
shell_exec($escapedCommand);



//escape &<>" without '
htmlspecialchars('&<>"\'');
htmlentities('&<>"\''); //Can escape more simbols than htmlspecialchars



//escape &<>" with '
htmlspecialchars('&<>"\'', ENT_QUOTES);
htmlentities('&<>"\'', ENT_QUOTES);



//escaping options
//ENT_COMPAT	Преобразует двойные кавычки, одинарные кавычки не изменяются.
//ENT_QUOTES	Преобразует как двойные, так и одинарные кавычки.
//ENT_NOQUOTES  Оставляет без изменения как двойные, так и одинарные кавычки.



//decode escaped string
htmlspecialchars_decode('&amp;&lt;&gt;&quot;&#039;', ENT_QUOTES);
html_entity_decode('&amp;&lt;&gt;&quot;&#039;', ENT_QUOTES);



//remove html tags except for <br>
strip_tags('<li><br>', '<br>');



//escape '" to \'\"
addslashes('\'"');



//filter variable using other filters and options	
//filter_var("");
//filter_var_array(array());
//filter_input();
//filter_input_array(array());



//safe insert into database
// mysqli_escape_string();
// mysqli_real_escape_string();



//PDO binding
//$dbh->bindParam();
//$dbh->bindValue();