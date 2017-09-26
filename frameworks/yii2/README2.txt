- Вложенные контроллеры - создать папку в controllers и views

//Свой layout
1. config/web.php
'layout' => 'basic'

2. Controller
public $layout = 'basic';
$this->layout = 'main';

3. Html::a('text', ['post/index']);

4. yii\web\View;

5. Подключение одного файла js в шаблоне
$this->registerJsFile('@web/js/file.js', ['depends' => 'Yii\web\YiiAsset']);
$this->registerJs('alert(1)', ['depends' => 'Yii\web\YiiAsset']);

6. Yii cookbook
yiiframework.com/wiki/

7. if (Yii::$app->request->isAjax){
    return 'test';
}

8. Защита от подмены форм
Нужно добавлять токен csrf для работы с post
<?= Html::csrfMetaTags(); ?>

9. Отключить csrf валидацию
public function beforeAction ($action){
    if ($action->id === 'index'){
        $this->enableCsrfValidation = false;
    }
    return parent::beforeAction($action);
}

10. Заполнение title в контроллере
$this->view->title = 'test';

11. Блоки, передача в главный layout
//в шаблоне
<?php $this->beginBlock ('block1'); ?>
<h1>test </h1>
<?php $this->endBlock (); ?>

//в лэйауте
<?= $this->blocks ['block1']; ?>

12. Функция compact

13. Русские сообщения валидаторов форм
config/web.php
'language' => 'ru',
В главном шаблоне
<html lang="<?= Yii::$app->language ?>">

14. Поля не перечисленные в rules не будут заполнены при $model->load ($post);
Обход:
public function rules()
{
    return [
        ['text', 'safe'],
Или
        ['text', 'trim'],
    ];
}

15. Flash сообщения об успехе или неудаче
//контроллер
if ($model->validate ()){
    Yii::$app->session->setFlash('success', 'ok');
    //сброс формы
    return $this->refresh ();
} else {
    Yii::$app->session->setFlash('error', 'ошибка');
}

//view
if (Yii::$app->session->hasFlash('success'))
{
    echo Yii::$app->session->getFlash('success');
}

16. Custom валидатор
public function rules()
{
    return [
        ['text', 'myRule']
    ];
}

public function myRule ($attr)
{
    if (!in_array ($this->$attr, ['value'])){
        $this->addError ($attr, 'wrong!');
    }
}

17. Подключение bootstrap.js
assets/AppAsset.php
depends
yii\bootstrap\BootstrapPluginAsset

18. ActiveRecord
CRUD
$cats = $model::find ()->all ();
foreach ($cats as $cat){
    echo = $cat->title;
}

19. Указание имени таблицы в ar
static public function tableName ()
{
    return 'category';
}

20. Методы active record
1) Category::find ()
::findOne (['parent' => 691]) //без доп методов
::findAll (['parent' => 691]) //без доп методов
::findBySql ('select * from tbl')->all () //без промежуточных методов
::findBySql ('select * from tbl where id = :id', [':id' => 1])->all ()
2) любой метод в любом порядке
->orderBy (['id' => SORT_ASC])
->asArray()
->where ('parent = 691')
->where (['parent' => 691])
->where (['like', 'title', 'pp']) //без %%
->where (['>=, 'id', 695]) //без %%
->limit (1)
3) ->all(), ->one (), ->count (), ->sum ()

21. //Связи в ActiveReco­rd
class Product extends ActiveRecord
{
    public function getCategories()
    {
        return $this­->hasOne(Category::c­lassName(), ['catego­ry_field' => 'produc­t_field']);
    }
}

class Category exten­ds ActiveRecord
{
    public function getProducts()
    {
        return $this­->hasMany(Product::c­lassName(), ['produc­t_field' => 'categor­y_field']);
    }
}

$category = Category­::findOne(694);
$products = $categor­y->products; //getPr­oducts()
//$category->products не появится пока к нему не обратишся (ленивая загрузка)

22. В ActiveRecord в отличае от Model свойства-поля определять не обязательно

23. Метод save делает insert или update в зависимости от способа создания объекта
- new Model () - insert
- Model::fins () - update

24. Сохранение
$model->save (false) //insert без валидации
if($model->save (false)){} // с валидацией

Если свойство не описано в rules, то оно считается не безопасным и в бд запишется null

25. Удаление
$model->delete ();
Model::deleteAll (['>', 'id', 3]);
Model::deleteAll (); //удалить все из таблицы

26. Виджеты
//Класс виджета
//components/MyWidge­t.php
class MyWidget exten­ds \yii\base\Widget
{
    public $name;

    public function init()
    {
        parent::init­();

        if($this->na­me === null) $this->­name = 'Guest';
        ob_start();
    }

    public function run()
    {
        //return "<h­1>Hello, $this->name­!</h1>";
        return $this­->render('my', [
            'name' => $this->name,
            'content' => mb_strtoupper(o­b_get_clean(), 'utf-­8'),
        ]);
    }
}

//Шаблон виджета
//components/views/m­y.php
<p><?= $content; ?><­/p>
<h1>Hello, <?= $name; ?>!</h1>

//Шаблон экшна
<?php echo MyWidget:­:widget(); ?>

<?php echo MyWidget:­:widget(['name' => 'Ivan']); ?>

<?php MyWidget::begi­n(['name' => 'Ivan']­); ?>
<p>user text</p>
<?php MyWidget::end(­); ?>

