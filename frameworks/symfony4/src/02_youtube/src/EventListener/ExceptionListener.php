<?php


namespace App\EventListener;


use Symfony\Component\HttpFoundation\Response;
use Symfony\Component\HttpKernel\Event\GetResponseForExceptionEvent;
use Symfony\Component\HttpKernel\Exception\BadRequestHttpException;

class ExceptionListener
{
    public function onKernelException(GetResponseForExceptionEvent $event): GetResponseForExceptionEvent
    {
        $response = new Response();

        $exception = $event->getException();

        if($exception instanceof \LogicException){
            $exception = new BadRequestHttpException($exception->getMessage());
        }

        $response->setStatusCode($exception->getStatusCode());

        $response->setContent(json_encode([
            'error' => $exception->getMessage()
        ]));

        $event->setResponse($response);

        return $event;
    }
}
