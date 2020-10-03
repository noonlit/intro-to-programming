#include <cstdio>
#include <iostream>
#include "lab1.h" // local path first

void printText()
{
    // c-style print
    printf("This is a string: %s", "string");

    // cpp-style print - will concatenate the two arguments
    // << - the stream out operator
    std::cout << "one" << " " << "two";
}

void readAndPrintInts()
{
    int a;
    int b;

    // read both ints, cpp-style 
    // note the stream in operator
    std::cin >> a >> b;

    // write both ints
    std::cout << a << b;
    std::cout << "\n";

    // read both ints, c-style
    scanf_s("%d%d", &a, &b); // safe scanf (mostly needed for reading over string bounds)

    // write both ints
    printf("%d %d", a, b);
}
