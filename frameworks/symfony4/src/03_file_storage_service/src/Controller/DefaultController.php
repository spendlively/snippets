<?php


namespace App\Controller;


use App\Service\FileStorageServiceInterface;
use App\Service\ServiceA;
use App\Service\ServiceB;
use Symfony\Bundle\FrameworkBundle\Controller\AbstractController;
use Symfony\Component\DependencyInjection\ContainerInterface;
use Symfony\Component\Filesystem\Filesystem;
use Symfony\Component\HttpFoundation\Response;
use Symfony\Component\Routing\Annotation\Route;

class DefaultController extends AbstractController
{


    public function __construct()
    {
    }

    /**
     * @Route("/", name="test")
     * @param FileStorageServiceInterface $fileStorageService
     * @return Response
     */
    public function test(FileStorageServiceInterface $fileStorageService)
    {
        $fileStorageService->setContent(['asfdgh' => '123456']);
        $content = $fileStorageService->getContent();
        return new Response(json_encode($content));
    }

    /**
     * @Route("/admin", name="admin")
     * @return Response
     */
    public function admin(){
        return new Response('This is admin page');
    }

}
