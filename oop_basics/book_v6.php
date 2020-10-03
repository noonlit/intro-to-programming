<?php

/***********************
 * Only specification *
 **********************/
interface Chargeable
{
    public function getPrice() : float;
}

/***********************
 * Only implementation *
 ***********************/
trait IdentityTrait
{
    public function generateId() : string
    {
        return uniqid();
    }
}

/************************************
 * Specification and implementation *
 ************************************/
abstract class Product implements Chargeable
{
    use IdentityTrait;

    protected $id;
    protected $price;
    public $discount = 0.0;

    public function __construct(float $price)
    {
        $this->id = $this->generateId();
        $this->price = $price;
    }

    public function getPrice() : float
    {
        return $this->price - $this->discount;
    }

    abstract public function getDetails() : string;
}

class Book extends Product
{
    private $name;
    private $author;

    public function __construct(float $price, string $name, string $author)
    {
        parent::__construct($price);

        $this->name = $name;
        $this->author = $author;
    }

    // must provide implementation for abstract parent method
    public function getDetails() : string
    {
        return "A work by {$this->author}, titled {$this->name}";
    }
}

$book = new Book(12.50, "nights at the circus", "angela carter");
var_dump($book);
