#include <stdio.h>
#include <stdlib.h>
#include "lab3_c.h"

/* Returns the reverse of the given number */
int reverseNumber(int number)
{
    int reversedNumber = 0;
    int remainder = 0;

    while (number != 0) {
        // get last digit
        remainder = number % 10;

        // multiply by 10 (making the last digit 0)
        // then add remainder (making the last digit the remainder)
        reversedNumber = reversedNumber * 10 + remainder;

        // take off the last digit
        number = number / 10;
    }

    return reversedNumber;
}

/* Prints the reverse of a number provided by the user */
void printReversedNumber()
{
    int number;

    printf("Input a number: \n");
    scanf_s("%d", &number);

    printf("The reversed number is %d\n", reverseNumber(number));
}

/* Reads elements into two matrices */
void readIntoMatrices(int** ppFirst, int** ppSecond, int* nrRows, int* rowLength)
{
    printf("How many elements per row? \n");
    int localNrRows = 0;
    scanf_s("%d", &localNrRows);

    printf("How many rows? \n");
    int localRowLength = 0;
    scanf_s("%d", &localRowLength);

    // first matrix
    int size = sizeof(int) * localNrRows * localRowLength;
    int* pFirst = (int*)(malloc(size));

    printf("The first matrix has %d rows and accepts %d elements per row. Please enter the values.\n",
        localNrRows,
        localRowLength
    );

    for (int row = 0; row < localNrRows; row++) {
        for (int rowPosition = 0; rowPosition < localRowLength; rowPosition++) {
            printf("Enter value for index[%d][%d]:", row, rowPosition);
            int offset = row * localRowLength + rowPosition;
            int* pNextNumber = pFirst + offset;
            scanf_s("%d", pNextNumber);
        }
    }

    // second matrix
    int* pSecond = (int*)(malloc(size));

    printf("The second matrix has %d rows and accepts %d elements per row. Please enter the values.\n",
        localNrRows,
        localRowLength
    );

    for (int row = 0; row < localNrRows; row++) {
        for (int rowPosition = 0; rowPosition < localRowLength; rowPosition++) {
            printf("Enter value for index[%d][%d]:", row, rowPosition);
            int offset = row * localRowLength + rowPosition;
            int* secondPNextNumber = pSecond + offset;
            scanf_s("%d", secondPNextNumber);
        }
    }

    *nrRows = localNrRows;
    *rowLength = localRowLength;
    *ppFirst = pFirst;
    *ppSecond = pSecond;
}

/*
Calculates sum between elements of matrices on same positions.
Assigns sum to third matrix on equivalent position.
*/
void calculateSumAndDisplay(const int* pFirst, const int* pSecond, int nrRows, int rowLength)
{
    int size = sizeof(int) * nrRows * rowLength;
    if (size == 0) {
        return;
    }

    int* result = (int*)malloc(size);
    if (!result) {
        return;
    }

    // calculate
    for (int row = 0; row < nrRows; row++) {
        for (int rowPosition = 0; rowPosition < rowLength; rowPosition++) {
            int offset = row * rowLength + rowPosition;

            result[offset] = pFirst[offset] + pSecond[offset];
        }
    }

    // display
    printf("Reading from result vector. \n");
    for (int row = 0; row < nrRows; row++) {
        for (int rowPosition = 0; rowPosition < rowLength; rowPosition++) {
            int offset = row * rowLength + rowPosition;
            printf("%d ", result[offset]);
        }

        printf("\n");
    }
}

/*  S1 = 7+14+21+…+7*n */
void printSumS1()
{
    int sum = 0;
    int n;

    printf("Enter a number: ");
    scanf_s("%d", &n);

    for (int i = 1; i <= n; i++) {
        sum += i * 7;
    }

    printf("S1: sum is %d\n", sum);
}

/* S7 = 2*3+4*5+…+100*101 */
void printSumS7()
{
    int sum = 0;
    int n = 100;

    for (int i = 2; i <= n; i += 2) {
        sum += i * (i + 1);
    }

    printf("S7: sum is %d\n", sum);
}

/* S4 = 1+1*2+1*2*3+1*2*3*4+…+1*2*3*4*…*n */
void printSumS4()
{
    int sum = 0;
    int n;

    printf("Enter a number: ");
    scanf_s("%d", &n);

    int multiplier = 1;
    for (int i = 1; i <= n; i++) {
        multiplier *= i;
        sum += multiplier;
    }
}

/* Folosind functii (sau nu), cititi un vector de n elemente,
afisati vectorul, inserati valoarea 100, pe pozitia x in vector; afisati noul vector; */

/* Inserts given value into given position in the vector */
void insertIntoVector(int* pVector, int vectorLength, int position, int value)
{
    // would run faster if going forward, but this is easier
    for (int i = vectorLength; i > position; i--) {
        pVector[i] = pVector[i - 1];
    }

    pVector[position] = value;
}

void printUpdatedVector()
{
    int n;
    int value;
    int position;

    printf("Enter a size for the vector: ");
    scanf_s("%d", &n);

    // allocate extra position for the number to be inserted
    n++;
    int size = sizeof(int) * n;

    if (!size) {
        return;
    }

    int* vector = (int*)malloc(size);

    if (!vector) {
        return;
    }

    // read into vector
    for (int i = 0; i < n - 1; i++) {
        printf("Enter value for index[%d]: ", i);
        int* nr = vector + i;
        scanf_s("%d", nr);
    }

    printVector(vector, n - 1);

    // get the extra nr and its position
    printf("Enter a number to insert into vector: ");
    scanf_s("%d", &value);

    printf("Enter an index for the number: ");
    scanf_s("%d", &position);

    // do magic
    insertIntoVector(vector, n, position, value);

    printVector(vector, n);
}

/* Does what it says on the box */
void printVector(const int* vector, int length)
{
    for (int i = 0; i < length; i++) {
        printf("vector[%d] => %d\n", i, vector[i]);
    }
}