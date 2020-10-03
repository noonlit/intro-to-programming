#include <cstdio>
#include <iostream>
#include "lab2.h"

/**
 * Prints a count of the prime numbers given as input (naive solution)
 */
void printPrimeCount()
{
    int n, i, divisorsCount, primesCount = 0;

    do {
        scanf_s("%d", &n);

        divisorsCount = 0;
        for (i = 2; i < n; i++) {
            if (n % i == 0) {
                divisorsCount++;
            }
        }

        if (divisorsCount == 0) {
            primesCount++;
            printf("Found a prime! %d \n", n);
        }
    } while (n > 0); // arbitrarily

    printf("There are %d primes! How exciting!", primesCount);
}

/**
 * Adds up numbers from input until zero is received. Prints sum.
 * Uses C syntax for reading because C++ is technically cheating.
 */
void printSumUntilZeroIsEntered()
{
    int n;
    int sum = 0;

    do {
        scanf_s("%d", &n);
        sum += n;
    } while (n > 0);

    printf("Sum is: %d", sum);
}

/* Rule: first number is the units digit */
/* TODO as homework: use while. */
void reconstructNumberFromInputs()
{
    int iterations = 3; // arbitrarily
    int power = 1;
    int result = 0;
    int i, nr;

    // inputs 1 2 3 results in 321
    for (i = 0; i < iterations; i++) {
        scanf_s("%d", &nr);
        result = result + nr * power;
        power = power * 10;
    }

    printf("Result is %d", result);
}