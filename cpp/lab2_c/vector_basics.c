#include <stdio.h>
#include "lab2_c.h"

/* Class examples */
void addPositivesToVectorAndShowThem()
{
    int current, v[1000], sum = 0;

    // add positive elements to vector
    int i = 0;
    do {
        scanf_s("%d", &current);

        if (current > 0) {
            v[i] = current;
            i++;
        }

    } while (current != 0);

    // display each element of the vector
    int j;
    for (j = 0; j < i; j++) {
        // control string + conversion specifier, format string
        printf("Current element: %d \n", v[j]);
    }
}

void showSumOfPositives()
{
    int i, n, current, sum = 0;

    // nr of iterations
    scanf_s("%d", &n);

    for (i = 0; i < n; i++) {
        scanf_s("%d", &current);
        if (current > 0) {
            sum += current;
        }
    }

    printf("Sum is %d", sum);
}

void showMaxWithVector()
{
    int i, n, v[1000];

    // nr of iterations
    scanf_s("%d", &n);

    int max = 0;
    for (i = 0; i < n; i++) {
        scanf_s("%d", &v[i]);

        if (v[i] > max) {
            max = v[i];
        }
    }

    printf("Max is %d", max);
}

void testVectorBasics()
{
    // vector -> static allocation
    int i, n = 4, v[4], nr;

    scanf_s("%d", &nr);
    printf("Number is: %d \n", nr);

    // add last 4 of the read digits to the vector
    for (i = 0; i < 4; i++) {
        v[i] = nr % 10;
        nr = nr / 10;
    }

    // display vector backwards
    for (i = 3; i >= 0; i--) {
        printf("Current digit: %d \n", v[i]);
    }
}