<?php
/**
 * Created by PhpStorm.
 * User: spendlively
 * Date: 14.08.19
 * Time: 17:18
 */

namespace App\Controller;


use Sensio\Bundle\FrameworkExtraBundle\Configuration\Route;
use Symfony\Component\HttpFoundation\Response;

class ArticleController
{

    /**
     * @Route("/")
     */
    public function homepage()
    {
        return new Response('Hi');
    }

    /**
     * @Route("/show")
     */
    public function show()
    {
        return new Response('show');
    }

    /**
     * @Route("/news/{slug}")
     * @param $slug
     * @return Response
     */
    public function slug($slug)
    {
        return new Response(sprintf(
            'The page is about word: %s',
            $slug
        ));
    }
}
