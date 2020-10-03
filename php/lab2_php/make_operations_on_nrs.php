<?php

/**
 * Adds up numbers from input until zero is received. Prints sum.
 */
function printSumUntilZeroIsRead()
{
    $sum = 0;

    do {
        $nr = readline("Enter a number: ");
        $nr = (int) $nr;
        $sum += $nr;
    } while ($nr !== 0);

    echo "Sum is {$sum}";
}

// printSumUntilZeroIsRead();

/**
 * Prints divisors of number read fom input.
 */
function printDivisorsAndSumOfDivisors()
{
    $nr = readline("Enter a number: ");
    $nr = (int) $nr;

    $sum = 0;
    for ($i = 1; $i <= $nr; $i++) {
        if ($nr % $i == 0) {
            echo "Divisor {$i} was found\n";
            $sum += $i;
        }
    }

    echo "The sum of divisors is {$sum}";
}

// printDivisorsAndSumOfDivisors();

/**
 * Prints a count of the prime numbers given as input.
 */
function printPrimeCount()
{
    $n = readline("How many numbers? ");
    $n = (int) $n;

    $primeCount = 0;
    for ($i = 0; $i < $n; $i++) {
        $nr = readline("Enter a number: ");
        $nr = (int) $nr;

        if (isPrime($nr)) {
            $primeCount++;
        }
    }

    echo $primeCount;
}

/**
 * Silly && basic solution to identifying a prime number.
 *
 * @param int $nr
 * @return bool
 */
function isPrime(int $nr) : bool
{
    if ($nr <= 1) {
        return false;
    }

    for ($i = 2; $i < $nr; $i++) {
        if ($nr % $i == 0) {
            return false;
        }
    }

    return true;
}

function semiCleverIsPrime(int $nr)
{
    // only go halfway to $n
}

function moreThanSemiCleverIsPrime(int $nr)
{
    // only go up to sqrt($nr)
}

printPrimeCount();