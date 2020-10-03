#include <cstdio>
#include <iostream>
#include "lab1.h"

// extern void printText(); - would be needed in the absence of a header file

int main()
{
    std::cout << "Enter four numbers in sequence: \n";
    std::cout << getMaxBetweenFourNumbers();

    return 1;
}