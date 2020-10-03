<?php

/**
 * Reads n numbers and adds even and odd ones separately.
 *
 * Prints even and odd results.
 */
function printEvenAndOddSums()
{
    $n = readline("How many numbers? ");

    $oddSum = 0;
    $evenSum = 0;

    for ($i = 0; $i < $n; $i++) {
        $nr = readline("Enter a number: ");
        $nr = (int) $nr;

        if ($nr % 2 == 0) {
            $evenSum += $nr;
            continue;
        }

        $oddSum += $nr;
    }

    echo "Odd sum is: {$oddSum}";
    echo "Even sum is: {$evenSum}";
}

printEvenAndOddSums();