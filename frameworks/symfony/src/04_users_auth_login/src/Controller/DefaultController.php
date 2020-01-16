<?php

namespace App\Controller;

use Psr\Log\LoggerInterface;
use Symfony\Bundle\FrameworkBundle\Controller\AbstractController;
use Symfony\Component\HttpFoundation\Response;
use Symfony\Component\Routing\Annotation\Route;
use Symfony\Component\Security\Core\Authentication\Token\Storage\TokenStorageInterface;

class DefaultController extends AbstractController
{
    /**
     * @Route("/", name="root")
     * @param TokenStorageInterface $tokenStorage
     * @param LoggerInterface $logger
     * @return Response
     */
    public function index(TokenStorageInterface $tokenStorage, LoggerInterface $logger)
    {
        return $this->redirectToRoute('profile');
    }

    /**
     * @Route("/profile", name="profile")
     */
    public function profile()
    {
        return $this->render('profile.html.twig', []);
    }
}
