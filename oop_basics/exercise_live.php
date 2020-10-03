<?php

/**
 * Make a wishlist.
 *
 * The wishlist holds multiple books.
 *
 * Books can only be removed from the wishlist one by one, by ID.
 *
 * You can display the books' names as a comma-separated list.
 *
 * Task: Add three books to the wishlist.
 *
 * Task: Remove a book from the wishlist by its ID. (hint: unset())
 */

class Wishlist
{
    private $books = [];

    public function addBook(Book $book)
    {
        $this->books[$book->getId()] = $book;
    }

    public function removeBook(string $id)
    {
        unset($this->books[$id]);
    }
}

trait IdentityTrait
{
    public function generateId() : string
    {
        return uniqid('book-');
    }
}

class Book
{
    use IdentityTrait;

    private $id;
    private $name;

    public function __construct(string $name)
    {
        $this->id = $this->generateId();
        $this->name = $name;
    }

    public function getId() : string
    {
        return $this->id;
    }

    public function getName() : string
    {
        return $this->name;
    }
}

$wishlist = new Wishlist();
$book1 = new Book('carte');
$book2 = new Book('caiet');
$book3 = new Book('culegere');

$wishlist->addBook($book1);
$wishlist->addBook($book2);
$wishlist->addBook($book3);

$wishlist->removeBook($book2->getId());