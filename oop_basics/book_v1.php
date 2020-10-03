<?php

/************************************
 * A struct that's now all grown up *
 ************************************/
class Book
{
    public $name;
    public $author;

    public function getBookDetails() : string // bundle up the behaviour with the data
    {
        $name   = ucwords($this->name); // discuss: $this
        $author = strtoupper($this->author);

        return "The book is {$name} by {$author}";
    }
}

$book = new Book();

/************************************************
 * Go on Youtube, forget to set book properties *
 ************************************************/

echo $book->getBookDetails();