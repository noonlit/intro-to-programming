#include <cstdio>
#include <iostream>
#include "lab2.h"

/**
 * Reads n numbers and adds even and odd ones separately.
 *
 * Prints even and odd results.
 */
void printEvenAndOddSums()
{
    std::cout << "How many numbers should be added? \n";

    int n;
    std::cin >> n;

    int oddSum = 0;
    int evenSum = 0;
    int current = 0;
    while (n > 0) {
        std::cout << "Enter a number: \n";
        std::cin >> current;
        n--;

        if ((current % 2) == 0) {
            evenSum += current;
            continue;
        }

        oddSum += current;
    }

    std::cout << "The odd sum is " << oddSum << " and the even sum is " << evenSum;
}