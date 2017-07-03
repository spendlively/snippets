
//Экранирование вывода
<?= $this->escapeHtml($title); ?>

//Url
<?= $this->url("modulename", array("action"=>"edit", "id"=>$user->id)); ?>
