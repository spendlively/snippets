<?php

//search files by extensions in path
$files = glob("/path/to/directory/*.{jpg,gif,png}", GLOB_BRACE);
$filteredFiles = array_filter($files, 'is_file');
