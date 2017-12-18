<?php

class Logger
{
    public function log($message)
    {
        //...
    }

}

class Product
{
    protected $logger;

    public function __construct(Logger $logger)
    {
        $this->logger = $logger;
    }

    public function getLogger()
    {
        return $this->logger;
    }

    public function setPrice($price)
    {
        try{
            //..
        } catch (\Exception $e) {
            $this->getLogger()->log($e->getMessage());
        }
    }
}

$product = new Product(new Logger);
$product->setPrice(100);
