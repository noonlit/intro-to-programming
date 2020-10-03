<?php
/**
 * Make a wishlist.
 *
 * The wishlist can hold any number of books.
 *
 * Books can only be removed from the wishlist one by one, by ID.
 *
 * Add three books to the wishlist.
 *
 * Remove a book from the wishlist by its ID.
 */

trait IdentityTrait
{
    public function generateId() : string
    {
        return uniqid();
    }
}

class Book
{
    use IdentityTrait;

    private $id;
    private $price;
    private $name;

    public function __construct(float $price, string $name)
    {
        $this->id    = $this->generateId();
        $this->price = $price;
        $this->name  = $name;
    }

    public function getId()
    {
        return $this->id;
    }

    public function getName()
    {
        return $this->name;
    }
}

class Wishlist
{
    private $books;

    public function addItem(Book $book)
    {
        $this->books[$book->getId()] = $book;
    }

    public function removeItem(string $id)
    {
        unset($this->books[$id]);
    }

    public function showNames() : string
    {
        $output = '';

        foreach ($this->books as $book) {
            $output .= $book->getName() . ", ";
        }

        return rtrim($output, ', ');
    }
}

$wishlist = new Wishlist();
$book1 = new Book(12.3, "nights at the circus");
$book2 = new Book(10.2, "harry potter and the bloody pointer");
$book3 = new Book(100, "the little struct that could");

$wishlist->addItem($book1);
$wishlist->addItem($book2);
$wishlist->addItem($book3);

echo $wishlist->showNames();
echo "\n";

$wishlist->removeItem($book1->getId());
echo $wishlist->showNames();


