<?php

/*********************************************
 * What if we want to sell other things too? *
 *********************************************/
abstract class Product
{
    public $price;
    public $discount = 0;

    public function __construct(float $price)
    {
        $this->price = $price;
    }
}

/*******************************************
 * Now we can get properties for free!     *
 * Discuss: single vs multiple inheritance *
 *******************************************/
class Book extends Product //, Artwork
{
    public $name;
    public $author;

    public function __construct(float $price, string $name, string $author)
    {
        parent::__construct($price); // is not called automatically!

        $this->name   = $name;
        $this->author = $author;
    }
}

class Artwork
{
    public function getMessage() : string
    {
        return "There's only one rule that I know of, babies — God damn it, you've got to be kind.";
    }
}


/*********************************
 * Note our book has a price now *
 ********************************/
$book = new Book(12.50, "nights at the circus", "angela carter");


/*************************
 * How about a discount? *
 *************************/
$book->discount = 3;
echo "The price is {$book->price}\n";
echo "Wait ... \n";
echo "The price is " . ($book->price - $book->discount) . "\n";


/*********************************************
 * What if the price now has to include tax? *
 ********************************************/
$book->tax = 1;
echo "Actually ... \n";
echo "The price is " . ($book->price + $book->tax - $book->discount);
