<?php

if(!empty($_FILES)){
	foreach($_FILES as $file){
		if($file['tmp_name']){
			$res = move_uploaded_file($file['tmp_name'], "/tmp/" . basename($file['name']));
		}
	}
}
