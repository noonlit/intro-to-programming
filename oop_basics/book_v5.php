<?php

/****************************************************************
 * We're always sure we can add up two ints.                    *
 * How do we make sure we can always get a price for a product? *
 ****************************************************************/
interface Chargeable
{
    public function getPrice() : float;
}

/****************************************************
 * Pinky promise products will always have a price. *
 * Discuss: specification vs implementation         *
 ****************************************************/
abstract class Product implements Chargeable //, ArrayAccess (predefined in PHP)
{
    protected $price;
    public $discount = 0.0;

    public function __construct(float $price)
    {
        $this->price = $price;
    }

    public function getPrice() : float
    {
        return $this->price - $this->discount;
    }
}

/**************************************************
 * Books inherit the parent's sins and contracts. *
 **************************************************/
class Book extends Product  // implements Downloadable
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

echo $book->getPrice();