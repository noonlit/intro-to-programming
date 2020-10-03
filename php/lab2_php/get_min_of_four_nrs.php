<?php

/**
 * Returns min of four numbers read from the console.
 */
function getMinOfFourNumbers()
{
    $a = readline("Enter the first number: ");
    $b = readline("Enter the second number: ");
    $c = readline("Enter the third number: ");
    $d = readline("Enter the fourth number: ");

    $min = $a;

    if ($b < $min) {
        $min = $b;
    }

    if ($c < $min) {
        $min = $c;
    }

    if ($d < $min) {
        $min = $d;
    }

    return $min;
}


echo getMinOfFourNumbers();
