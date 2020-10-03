#include <stdio.h>
#include <stdlib.h>
#include "lab4_c.h"

void printModifiedVector()
{
    int mainVectorSize;
    printf("Enter a size for the main vector: ");
    scanf_s("%d", &mainVectorSize);

    int secondaryVectorSize;
    printf("Enter a size for the secondary vector: ");
    scanf_s("%d", &secondaryVectorSize);

    // first vector needs enough memory to contain a copy of the second
    int totalVectorSize = mainVectorSize + secondaryVectorSize;
    int size = sizeof(int) * totalVectorSize;

    if (!size) {
        return;
    }

    int* mainVector = (int*)malloc(size);

    // sanity: did malloc return null?
    if (!mainVector) {
        return;
    }

    // second vector only needs to contain itself :)
    int secondarySize = sizeof(int) * secondaryVectorSize;

    if (!secondarySize) {
        return;
    }

    int* secondaryVector = (int*)malloc(secondarySize);

    if (!secondaryVector) {
        return;
    }

    // read into main vector
    for (int i = 0; i < mainVectorSize; i++) {
        printf("Enter value for main vector, index[%d]: ", i);
        int* nr = mainVector + i;
        scanf_s("%d", nr);
    }

    // read into secondary vector
    for (int i = 0; i < secondaryVectorSize; i++) {
        printf("Enter value for secondary vector, index[%d]: ", i);
        int* nr = secondaryVector + i;
        scanf_s("%d", nr);
    }

    // where to insert the secondary vector?
    int position;
    printf("On what position should the secondary vector start within the main vector?\n");
    printf("The maximum value is %d: ", mainVectorSize);
    scanf_s("%d", &position);

    if (position > mainVectorSize) {
        printf("Surely you're joking");
        return;
    }

    insertVectorIntoVector(mainVector, secondaryVector, totalVectorSize, mainVectorSize, secondaryVectorSize, position);
    printVector(mainVector, totalVectorSize);

    free(mainVector);
    free(secondaryVector);
}

/* Inserts given secondary vector, starting from the given position, into the main vector */
void insertVectorIntoVector(
    int* pMainVector, 
    const int* pSecondaryVector, 
    int totalVectorLength,
    int mainVectorLength,
    int secondaryVectorLength,
    int startPosition
)
{
    // move existing elements to the end of the main vector 
    // until reaching the end of the secondary one
    int secondaryVectorEndPosition = startPosition + (secondaryVectorLength - 1);
    int currentMainVectorEndPosition = mainVectorLength - 1;

    for (int i = totalVectorLength - 1; i > secondaryVectorEndPosition; i--) {
        pMainVector[i] = pMainVector[currentMainVectorEndPosition];
        currentMainVectorEndPosition--;
    }

    // copy secondary vector into created gap
    int j = 0;
    for (int i = startPosition; i <= secondaryVectorEndPosition; i++) {
        pMainVector[i] = pSecondaryVector[j];
        j++;
    }
}

/* Does what it says on the box */
void printVector(const int* vector, int length)
{
    for (int i = 0; i < length; i++) {
        printf("vector[%d] => %d\n", i, vector[i]);
    }
}