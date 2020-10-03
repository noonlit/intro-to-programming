#include <cstdio>
#include <iostream>
#include "lab1.h"

/*
* Reads an int from stdin.
* Displays the even digits found in the int.
*/
void printEvenDigits()
{
    int nr, lastDigit;
    int power = 1;
    int result = 0;

    std::cout << "Enter a multi-digit number: ";
    std::cin >> nr;

    while (nr > 0) {
        lastDigit = nr % 10;

        if ((lastDigit % 2) == 0) {
            result = result + lastDigit * power;
            power = power * 10;
        }

        nr = nr / 10;
    }

    std::cout << result;
}