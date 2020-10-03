<?php

class Book
{
    public $name;
    public $author;

    public function __construct(string $name, string $author) // called automatically when object is built
    {
        $this->name = $name;
        $this->author = $author;
    }

    public function getBookDetails() : string
    {
        $name = ucwords($this->name);
        $author = strtoupper($this->author);

        return "The book is {$name} by {$author}";
    }
}

/****************************************************
 * Ensure Book is not a BlankCover when we build it *
 ****************************************************/
$book = new Book("nights at the circus", "angela carter");
echo $book->getBookDetails();


