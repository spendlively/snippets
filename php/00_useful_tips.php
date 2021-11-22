<?php

//search files by extensions in path

//$files = glob("/mnt/media_remake/t/raw/{,*/,*/*/,*/*/*/,*/*/*/*/}*.psd", GLOB_BRACE);
$filteredFiles = array_filter($files, 'is_file');

