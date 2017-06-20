<?php

include "./vendor/autoload.php";

use Zend\Form\Form;
use Zend\Form\Element;
use Zend\InputFilter\Factory as InputFactory;
use Zend\InputFilter\InputFilter;
use Zend\InputFilter\InputFilterAwareInterface;
use Zend\InputFilter\InputFilterInterface;

class UserForm extends Form{

    public function __construct($name = 'user'){

        parent::__construct($name);

        $this->setAttribute("method", "post");
//        $this->setAttribute("target", "__blank");
        $this->setAttribute("enctype", "application/x-www-form-urlencoded");
        $this->setAttribute("id", "userform");

        $this->add(array(
            'name' => 'id',
            'attribute' => array(
                'type' => 'hidden',
            ),
        ));

        $this->add(array(
            'name' => 'name',
            'attribute' => array(
                'type' => 'textarea',
            ),
            'options' => array(
                'label' => 'Description',
            ),
        ));

        $submit = new Element('submit');
        $submit->setAttribute('type', 'submit');
        $submit->setAttribute('value', 'Go!');
        $submit->setAttribute('id', 'submit_button');
        $this->add($submit);
    }
}

$factory = new InputFactory();
$inputFilter = new InputFilter();
$inputFilter->add($factory->createInput(array(
   'name' => 'name',
   'required' => true,
    'filter' => array(
        array('name' => 'StripTags'),
        array('name' => 'StringTrim'),
    ),
    'validators' => array(
        array(
            'name' => 'StringLength',
            'options' => array(
                'encoding' => 'UTF-8',
                'min' => 6,
                'max' => 20,
            ),
        ),
    ),
)));

$form = new UserForm();
$form->setInputFilter($inputFilter);

if(!empty($_POST)){
    $form->setData($_POST);
    if($form->isValid()){
        echo "<pre>";
        print_r($_POST);
        echo "</pre>";
    }
}

//View
$url = '/test.php';
$form->setAttribute('action', $_SERVER['REQUEST_URI']);

$zfView = new \Zend\View\Renderer\PhpRenderer();
$plugins = $zfView->getHelperPluginManager();
$config  = new \Zend\Form\View\HelperConfig;
$config->configureServiceManager($plugins);

$form->prepare();
echo $zfView->form()->openTag($form);
echo $zfView->formHidden($form->get('id'));
echo $zfView->formRow($form->get('name'));
echo $zfView->formSubmit( $form->get('submit'));
echo $zfView->form()->closeTag();

//Альтернативный способ
//$form->prepare();
//echo $zfView->form()->openTag($form);
//echo $zfView->formCollection($form);
//echo $zfView->form()->closeTag();
//die();





////ZF2 MVC
////IndexController.php
//public function testAction()
//{
//    $form = new UserForm();
//    $form->setInputFilter($inputFilter);
//
//    $request = $this->getRequest();
//    if ($request->isPost()) {
//        $form->setData($request->getPost());
//        if ($form->isValid()) {
//            return $this->redirect()->toRoute('album');
//        }
//    }
//
//    return new ViewModel(array(
//        'form' => $form,
//    ));
//}

////test.phtml
////Вывод по одному
//$form->prepare();
//echo $this->form()->openTag($form);
//echo $this->formHidden($form->get('id'));
//echo $this->formRow($form->get('name'));
////echo $this->formCollection($form);
//echo $this->formSubmit($form->get('submit'));
//echo $this->form()->closeTag();
