<?php

class Book
{
    public $name;

    public function __construct(string $name)
    {
        $this->name = $name;
    }
}
// passed by reference!
function changeName(Book $book)
{
    $book->name = 'something else';
}

$book = new Book('something');
//echo $book->name . "\n";
changeName($book);
//echo $book->name;
//echo "\n";

/******************
 * Static methods *
 ******************/
class MathUtils
{
    public static function calculateAverage(array $numbers) : float
    {
        if (empty($numbers)) {
            return 0;
        }

        return array_sum($numbers) / count($numbers);
    }
}

$numbers = [4, 5];
// echo MathUtils::calculateAverage($numbers);

/*********************************************************
 * Inheritance, encapsulation, polymorphism, abstraction *
 *********************************************************/

/****************
 * Polymorphism *
 ****************/

abstract class Writer
{
    abstract public function write(string $string);
}

class ConsoleWriter extends Writer
{
    public function write(string $string)
    {
        echo $string;
    }
}

class FileWriter extends Writer
{
    public function write(string $string)
    {
        $file = fopen("text.txt", "a");
        fwrite($file, $string);
        fclose($file);
    }
}

$writer = new ConsoleWriter();
//$writer->write('output');

$writer = new FileWriter();
//$writer->write('output');

/*********
 * SOLID *
 *********/
