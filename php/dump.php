<?php

$DB_USER = 'user';
$DB_PASS = 'pass';
$DB_NAME = 'dbname';

header('Content-Type: application/x-gzip');
header(sprintf('Content-Disposition: attachment; filename="backup-%s.sql.gz"', date('d-m-Y')));

$cmd = sprintf('mysqldump -u %s --password=%s %s | gzip --best', $DB_USER, $DB_PASS, $DB_NAME);

passthru($cmd);

exit(0);
