#include <stdio.h>
#include "lab2_c.h"

/* Reads n numbers from input into a vector and returns n */
int readNumbersIntoVector(int* pOut, int maxSize) // pass a pointer to have access to the values
{
    int current, numbersCount = 0;

    printf("How many numbers?\n");

    scanf_s("%d", &numbersCount);

    int i = 0;
    while (i < numbersCount) {
        // avoid reading past the allocated size
        if (numbersCount > maxSize) {
            printf("We cannot read so many numbers!");
            return -1; // did you mean ... exception?
        }

        printf("Enter a number:\n");
        scanf_s("%d", &current);

        pOut[i] = current;
        i++;
    }

    return numbersCount;
}

/* Displays every element of a vector */
void displayElements(const int* pIn, int elementsCount) // can be const, we're not writing into it
{
    for (int i = 0; i < elementsCount; i++) {
        printf("Reading number from vector. The current number is %d.\n", pIn[i]);
    }
}

/* Reads values from a vector while they are positive */
void readValuesWhilePositive(const int* pIn, int elementsCount)
{
    for (int i = 0; i < elementsCount; i++) {
        if (pIn[i] < 0) {
            return;
        }

        // debug
        printf("The number being read is %d, and it is feeling positive.\n", pIn[i]);
    }
}

/* Displays sum of elements found in vector */
void displaySum(const int* pIn, int elementsCount)
{
    int sum = 0;
    for (int i = 0; i < elementsCount; i++) {
        sum += pIn[i];
    }

    printf("The sum is %d.\n", sum);
}

/* Prints the maximum value found in vector */
void displayMax(const int* pIn, int elementsCount)
{
    // the pointer might be to an invalid address
    if (pIn == 0) {
        return;
    }

    int max = pIn[0];
    for (int i = 1; i < elementsCount; i++) {
        if (pIn[i] > max) {
            max = pIn[i];
        }
    }

    printf("Maximum value is %d.\n", max);
}

/* Prints the minimum value found in vector */
void displayMin(const int* pIn, int elementsCount)
{
    if (pIn == 0) {
        return;
    }

    int min = pIn[0];
    for (int i = 1; i < elementsCount; i++) {
        if (pIn[i] < min) {
            min = pIn[i];
        }
    }

    printf("Minimum value is %d.\n", min);
}

/* Prints vector elements that are even numbers */
void displayEvenElements(const int* pIn, int elementsCount)
{
    if (pIn == 0) {
        return;
    }

    for (int i = 0; i < elementsCount; i++) {
        if (pIn[i] % 2 == 0) {
            printf("Element %d is even.\n", pIn[i]);
        }
    }
}

/* Prints vector elements found on even indices */
void displayElementsOnEvenIndices(const int* pIn, int elementsCount)
{
    if (pIn == 0) {
        return;
    }

    for (int i = 0; i < elementsCount; i += 2) {
        printf("Element %d is found on an even index, %d.\n", pIn[i], i);
    }
}

/* Prints vector elements that are found on indices that are multiples of x */
void displayElementsOnIndicesMultiplesOfX(const int* pIn, int elementsCount, int x)
{
    if (pIn == 0) {
        return;
    }

    for (int i = x; i < elementsCount; i += x) {
        printf("Element %d is found on an index multiple of %d, which is %d.\n", pIn[i], x, i);
    }
}

/* Prints vector elements that are multiples of x */
void displayMultiplesOfX(const int* pIn, int elementsCount, int x)
{
    if (pIn == 0) {
        return;
    }

    for (int i = 0; i < elementsCount; i++) {
        if (pIn[i] % x == 0) {
            printf("Element %d is a multiple of %d.\n", pIn[i], x);
        }
    }
}

/* Prints vector chars in reverse */
void displayCharactersInReverse(const char* pIn, int elementsCount)
{
    if (pIn == 0) {
        return;
    }

    printf("The current string in reverse is: ");

    for (int i = elementsCount - 1; i >= 0; i--) {
        putchar(pIn[i]);
    }

    printf("\n");
}

/* Prints numeric chars in vector */
void displayNumericChars(const char* pIn, int elementsCount)
{
    if (pIn == 0) {
        return;
    }

    printf("The following characters are numeric: ");
    for (int i = 0; i < elementsCount; i++) {
        if (isDigit(pIn[i]) != 0) {
            putchar(pIn[i]);
        }
    }

    printf("\n");
}

/* Prints vowels in vector */
void displayVowels(const char* pIn, int elementsCount)
{
    if (pIn == 0) {
        return;
    }

    printf("The following characters are vowels: ");
    for (int i = 0; i < elementsCount; i++) {
        if (isVowel(pIn[i]) != 0) {
            putchar(pIn[i]);
        }
    }

    printf("\n");
}

/* Prints consonants in vector */
void displayConsonants(const char* pIn, int elementsCount)
{
    if (pIn == 0) {
        return;
    }

    printf("The following characters are consonants: ");
    for (int i = 0; i < elementsCount; i++) {
        if (isConsonant(pIn[i]) != 0) {
            putchar(pIn[i]);
        }
    }

    printf("\n");
}

/* Prints uppercase letters in vector */
void displayUppercaseLetters(const char* pIn, int elementsCount)
{
    if (pIn == 0) {
        return;
    }

    printf("The following characters are uppercase: ");
    for (int i = 0; i < elementsCount; i++) {
        if (isUppercase(pIn[i]) != 0) {
            putchar(pIn[i]);
        }
    }

    printf("\n");
}

/* Checks whether given char represents a digit */
int isDigit(char c) // I MEAN BOOL, NOT INT
{
    return c >= '0' && c <= '9'; // or use the ascii code
}

/* Checks whether given char is a vowel */
int isVowel(char c) // I REALLY DO MEAN BOOL
{
    char vowels[] = "aeiouAEIOU";
    int size = sizeof(vowels) / sizeof(char);

    for (int i = 0; i < size; i++) {
        if (vowels[i] == c) {
            return 1;
        }
    }

    return 0;
}

/* Checks whether given char is a consonant*/
int isConsonant(char c) // ... bool
{
    return c >= 'A' && c <= 'z' && !isVowel(c);
}

/* Checks whether given char is an uppercase letter */
int isUppercase(char c) // i give up
{
    return c >= 'A' && c <= 'Z';
}