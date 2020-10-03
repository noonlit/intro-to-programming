<?php

/*********************************
 * A struct with a different hat *
 *********************************/
class Book
{
    public $name;
    public $author;
}

/************************************
 * Build a book from the blueprint! *
 ***********************************/
$book         = new Book();
$book->name   = "nights at the circus";
$book->author = "angela carter";


/*****************************************
 * How do we show our book in the store? *
 *****************************************/

/********************************
 * Option A: plain echo details *
 ********************************/
echo "The book is {$book->name} by {$book->author} \n";
echo "The book is " . ucwords($book->name) . " by " . strtoupper($book->author) . "\n"; // but what if we want a specific format?


/*******************************
 * Option B: write a function *
 ******************************/
function getBookDetails(Book $book) : string // note the type hint
{
    return "The book is " . ucwords($book->name) . " by " . strtoupper($book->author);
}

echo getBookDetails($book); // ... but we have to make sure we include the function everywhere along with the class!
