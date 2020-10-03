<?php

abstract class Product
{
    protected $price;
    public $discount = 0;
    public $tax      = 0;

    public function __construct(float $price)
    {
        $this->price = $price;
    }

    public function getPrice() : float
    {
        return $this->price + $this->tax - $this->discount;
    }
}

class Book extends Product
{
    private $name;
    private $author;

    public function __construct(float $price, string $name, string $author)
    {
        parent::__construct($price);

        $this->name   = $name;
        $this->author = $author;
    }
}

$book = new Book(12.50, "nights at the circus", "angela carter");
$book->discount = 3;
echo "The price is {$book->getPrice()}\n";

/*********************************************
 * What if the price now has to include tax? *
 ********************************************/
// TODO