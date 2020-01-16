<?php

namespace App\Controller;

use App\SimpleModule\Service\SimpleServiceInterface;
use Symfony\Bundle\FrameworkBundle\Controller\AbstractController;
use Symfony\Component\HttpFoundation\JsonResponse;
use Symfony\Component\HttpFoundation\Response;
use Symfony\Component\Routing\Annotation\Route;

class MyController extends AbstractController
{
    public function index(SimpleServiceInterface $service): Response
    {
        return new Response($service->test());
    }

    /**
     * @Route("/test")
     * @return Response
     */
    public function test()
    {
        return $this->json(['qwerty' => 'asdfgh']);
    }

    /**
     * @param SimpleServiceInterface $service
     * @Route("/user/list/")
     * @return JsonResponse
     */
    public function userList(SimpleServiceInterface $service): JsonResponse
    {
        $users = $service->allUsers();

        return $this->json($users);
    }

    /**
     * @Route("/exception")
     */
    public function exception(): void
    {
        throw new \LogicException("This is a Logic Exception example!");
    }
}
