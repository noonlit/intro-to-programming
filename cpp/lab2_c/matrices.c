#include <stdio.h>
#include <stdlib.h>
#include "lab2_c.h"

/* Does what it says on the box */
void readNumbersIntoMatrix(int** ppMatrix, int* nrRows, int* rowLength)
{
    printf("How many elements per row? \n");
    int localNrRows = 0;
    scanf_s("%d", &localNrRows);

    printf("How many rows? \n");
    int localRowLength = 0;
    scanf_s("%d", &localRowLength);

    // dynamically allocate a chunk of this size on the heap
    int* p = (int*)(malloc(sizeof(int) * localNrRows * localRowLength)); // malloc returns void*, so cast to int*

    printf("The current matrix has %d rows and accepts %d elements per row. Please enter the values.\n",
        localNrRows,
        localRowLength
    );

    for (int row = 0; row < localNrRows; row++) {
        for (int rowPosition = 0; rowPosition < localRowLength; rowPosition++) {
            printf("Enter value for index[%d][%d]:", row, rowPosition);
            int offset = row * localRowLength + rowPosition;
            int* pNextNumber = p + offset; // put next number where the pointer points
            scanf_s("%d", pNextNumber);
        }
    }

    // assign to output variables
    *nrRows = localNrRows; // writes to the pointed location
    *rowLength = localRowLength;
    *ppMatrix = p;
}

/* Prints elements of given matrix */
void displayMatrixElements(const int* pMatrix, int nrRows, int rowLength)
{
    for (int row = 0; row < nrRows; row++) {
        printf("Row number: %d \n", row);
        for (int rowPosition = 0; rowPosition < rowLength; rowPosition++) {
            int offset = row * rowLength + rowPosition;
            printf("Element: %d ", pMatrix[offset]); // *(pMatrix + offset) -> deref first element + offset
        }
        printf("\n");
    }
}

/* Displays the sum of elements in given matrix */
void displayMatrixSum(const int* pMatrix, int nrRows, int rowLength)
{
    int sum = 0;

    for (int row = 0; row < nrRows; row++) {
        for (int rowPosition = 0; rowPosition < rowLength; rowPosition++) {
            int offset = row * rowLength + rowPosition;
            sum += *(pMatrix + offset);
        }
    }

    printf("The sum of elements is %d\n", sum);
}

/* Displays even matrix elements */
void displayMatrixEvenElements(const int* pMatrix, int nrRows, int rowLength)
{
    for (int row = 0; row < nrRows; row++) {
        for (int rowPosition = 0; rowPosition < rowLength; rowPosition++) {
            int offset = row * rowLength + rowPosition;

            if (pMatrix[offset] % 2 == 0) {
                printf("Element with value %d on position %d is even\n", pMatrix[offset], offset);
            }
        }
    }
}

/* Displays odd matrix elements */
void displayMatrixOddElements(const int* pMatrix, int nrRows, int rowLength)
{
    for (int row = 0; row < nrRows; row++) {
        for (int rowPosition = 0; rowPosition < rowLength; rowPosition++) {
            int offset = row * rowLength + rowPosition;

            if (pMatrix[offset] % 2 != 0) {
                printf("Element with value %d on position %d is odd\n", pMatrix[offset], offset);
            }
        }
    }
}

/* Displays elements found on primary diagonal of given matrix */
void displayMatrixPrimaryDiagonal(const int* pMatrix, int nrRows, int rowLength)
{
    // accept square matrix only
    if (nrRows != rowLength) {
        return;
    }

    for (int row = 0; row < nrRows; row++) {
        for (int rowPosition = 0; rowPosition < rowLength; rowPosition++) {
            if (rowPosition == row) {
                int offset = row * rowLength + rowPosition;
                printf("Element with value %d on position %d is found on the primary diagonal\n", pMatrix[offset], offset);
            }
        }
    }
}

/* Displays elements found on secondary diagonal of given matrix */
void displayMatrixSecondaryDiagonal(const int* pMatrix, int nrRows, int rowLength)
{
    // accept square matrix only
    if (nrRows != rowLength) {
        return;
    }

    for (int row = 0; row < nrRows; row++) {
        for (int rowPosition = 0; rowPosition < rowLength; rowPosition++) {
            if (row == (nrRows - rowPosition - 1)) {
                int offset = row * rowLength + rowPosition;

                printf("Element with value %d on position %d is found on the secondary diagonal\n", pMatrix[offset], offset);
            }
        }
    }
}

/* Prints the elements found above the main diagonal of the given matrix */
void displayMatrixElementsAbovePrimaryDiagonal(const int* pMatrix, int nrRows, int rowLength)
{
    // accept square matrix only
    if (nrRows != rowLength) {
        return;
    }

    for (int row = 0; row < nrRows; row++) {
        for (int rowPosition = 0; rowPosition < rowLength; rowPosition++) {
            int offset = row * rowLength + rowPosition;

            if (rowPosition > row) {
                printf("Element with value %d on position %d is found above the main diagonal\n", pMatrix[offset], offset);
            }
        }
    }
}

/* Prints the elements found beneath the main diagonal of the given matrix */
void displayMatrixElementsBeneathPrimaryDiagonal(const int* pMatrix, int nrRows, int rowLength)
{
    // accept square matrix only
    if (nrRows != rowLength) {
        return;
    }

    for (int row = 0; row < nrRows; row++) {
        for (int rowPosition = 0; rowPosition < rowLength; rowPosition++) {
            int offset = row * rowLength + rowPosition;

            if (rowPosition < row) {
                printf("Element with value %d on position %d is found beneath the main diagonal\n", pMatrix[offset], offset);
            }
        }
    }
}

/* Prints the minimum value found on the primary diagonal */
void displayMinOnMatrixPrimaryDiagonal(const int* pMatrix, int nrRows, int rowLength)
{
    // accept square matrix only
    if (nrRows != rowLength) {
        return;
    }

    int min = pMatrix[0];
    for (int row = 0; row < nrRows; row++) {
        for (int rowPosition = 0; rowPosition < rowLength; rowPosition++) {
            int offset = row * rowLength + rowPosition;

            if ((rowPosition == row) && (pMatrix[offset] < min)) {
                min = pMatrix[offset];
            }
        }
    }

    printf("The min value found on the primary diagonal is %d. \n", min);
}

/* Prints the maximum value found on the secondary diagonal */
void displayMaxOnMatrixSecondaryDiagonal(const int* pMatrix, int nrRows, int rowLength)
{
    // accept square matrix only
    if (nrRows != rowLength) {
        return;
    }

    int max = pMatrix[0];
    for (int row = 0; row < nrRows; row++) {
        for (int rowPosition = 0; rowPosition < rowLength; rowPosition++) {
            int offset = row * rowLength + rowPosition;

            if ((row == (nrRows - rowPosition - 1)) && (pMatrix[offset] > max)) {
                max = pMatrix[offset];
            }
        }
    }

    printf("The max value found on the secondary diagonal is %d. \n", max);
}

/* Prints the sum of elements found above the main diagonal of the given matrix */
void displayMatrixSumAbovePrimaryDiagonal(const int* pMatrix, int nrRows, int rowLength)
{
    // accept square matrix only
    if (nrRows != rowLength) {
        return;
    }

    int sum = 0;
    for (int row = 0; row < nrRows; row++) {
        for (int rowPosition = 0; rowPosition < rowLength; rowPosition++) {
            int offset = row * rowLength + rowPosition;

            if (rowPosition > row) {
                sum += pMatrix[offset];
            }
        }
    }

    printf("The sum of elements above the main diagonal is %d. \n", sum);
}

/* Prints the sum of elements found beneath the main diagonal of the given matrix */
void displayMatrixSumBeneathPrimaryDiagonal(const int* pMatrix, int nrRows, int rowLength)
{
    // accept square matrix only
    if (nrRows != rowLength) {
        return;
    }

    int sum = 0;
    for (int row = 0; row < nrRows; row++) {
        for (int rowPosition = 0; rowPosition < rowLength; rowPosition++) {
            int offset = row * rowLength + rowPosition;

            if (rowPosition < row) {
                sum += pMatrix[offset];
            }
        }
    }

    printf("The sum of elements beneath the main diagonal is %d. \n", sum);
}

/* Displays the minimum element on every matrix row */
void displayMinRowElement(const int* pMatrix, int nrRows, int rowLength)
{
    for (int row = 0; row < nrRows; row++) {
        int min = pMatrix[row * rowLength];

        for (int rowPosition = 0; rowPosition < rowLength; rowPosition++) {
            int offset = row * rowLength + rowPosition;

            if (pMatrix[offset] < min) {
                min = pMatrix[offset];
            }
        }

        printf("The minimum value on row %d is %d. \n", row, min);
    }
}

/* Displays the maximum element on every matrix column */
void displayMaxColumnElement(const int* pMatrix, int nrRows, int nrColumns)
{
    int maxSize = sizeof(int) * nrColumns;

    if (!maxSize) {
        return;
    }

    int* colMax = (int*)malloc(maxSize);

    if (!colMax) {
        return;
    }

    // make sure you have an appropriately low value to compare the min with
    for (int i = 0; i < nrColumns; i++) {
        colMax[i] = INT_MIN;
    }

    for (int row = 0; row < nrRows; row++) {
        for (int col = 0; col < nrColumns; col++) {
            int offset = row * nrColumns + col;

            if (colMax[col] < pMatrix[offset]) {
                colMax[col] = pMatrix[offset];
            }
        }
    }

    for (int i = 0; i < nrColumns; i++) {
        printf("The max for column %d is %d \n", i, colMax[i]);
    }
}