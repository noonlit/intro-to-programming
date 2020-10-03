<?php

class A
{
    private $a = 1;

    public function addA(A $a) {
        return $this->a + $a->a;
    }
}

$a = new A();
$b = new A();

var_dump($a->addA($b));