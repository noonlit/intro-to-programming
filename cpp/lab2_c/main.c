#include <stdio.h>
#include <stdlib.h>
#include "lab2_c.h"

// the includes are called preprocessing directives

int main()
{
    /* Vectors with ints */
    // runOneDimensionalVectorIntProblems();

    /* Vectors with chars */
    // runOneDimensionalVectorCharProblems();

    /* Bidimensional vectors */
    runMatrixProblems();

    return 0;
}

/*
 - Citirea unei matrici patratice de n*n [x] (sort of. it can be n * n).
 - Afisarea unei matrici patratice de n*n [x]
 - Afișarea sumei tuturor elementelor unei matrici pătratice de n*n [x]
 - Citirea unei matrici n*m [x]
 - Afisarea unei matrici n*m [x]
 - Afișarea sumei elementelor pare/impare ale fiecărei linii/coloane a unei matrici n*n [x] - ish
 - Afișarea elementelor de pe diagonala principala/secundara a unei matrici n*n [x]
 - Afișarea elementelor de sub/deasupra diagonalei principale/secundare a unei matrici n*n [x]
 - Afisarea celui mai mic/mare element al unei matrici n*n, aflat pe diagonala principala/secundara [x]
 - Afisarea sumei elementelor unei matrici n*n aflate sub/deasupra diagonalei principale/secundare [x]
 - Afișarea celui mai mic/mare element al fiecarei linii/coloane a unei matrici n*n [x]
*/
void runMatrixProblems()
{
    int rowLength = 0;
    int nrRows = 0;
    int* out = 0;

    // Citirea unei matrici patratice de n*n
    // Citirea unei matrici n*m
    readNumbersIntoMatrix(&out, &nrRows, &rowLength); // they all convert to pointers to their types

    // Afisarea unei matrici patratice de n*n
    // Afisarea unei matrici n*m 
    displayMatrixElements(out, nrRows, rowLength);

    // Afișarea sumei elementelor pare / impare ale fiecărei linii / coloane a unei matrici n*n
    displayMatrixSum(out, nrRows, rowLength); // general sum and then the even/odd elements are easy to identify

    // Afișarea sumei elementelor pare/impare ale fiecărei linii/coloane a unei matrici n*n
    displayMatrixEvenElements(out, nrRows, rowLength);
    displayMatrixOddElements(out, nrRows, rowLength);

    // Afișarea elementelor de sub/deasupra diagonalei principale/secundare a unei matrici n*n
    displayMatrixPrimaryDiagonal(out, nrRows, rowLength);
    displayMatrixSecondaryDiagonal(out, nrRows, rowLength);

    // Afișarea elementelor de sub / deasupra diagonalei principale / secundare a unei matrici n * n
    displayMatrixElementsAbovePrimaryDiagonal(out, nrRows, rowLength);
    displayMatrixElementsBeneathPrimaryDiagonal(out, nrRows, rowLength);

    // Afisarea celui mai mic/mare element al unei matrici n*n, aflat pe diagonala principala/secundara
    displayMinOnMatrixPrimaryDiagonal(out, nrRows, rowLength);
    displayMaxOnMatrixSecondaryDiagonal(out, nrRows, rowLength);

    // Afisarea sumei elementelor unei matrici n * n aflate sub / deasupra diagonalei principale / secundare
    displayMatrixSumAbovePrimaryDiagonal(out, nrRows, rowLength);
    displayMatrixSumBeneathPrimaryDiagonal(out, nrRows, rowLength);

    // Afișarea celui mai mic / mare element al fiecarei linii / coloane a unei matrici n * n
    displayMinRowElement(out, nrRows, rowLength);
    displayMaxColumnElement(out, nrRows, rowLength);

    free(out);
}

/*
Repetitive cu vectori

- Afisati in ordine inversa caracterele dintr-un vector de caractere [x]
- Afisati cifrele dintr-un vector de n caractere [x]
- Afisati literele mari dintr-un vector de n caractere [x]
- Afisati vocalele dintr-un sir de n caractere [x]
- Afisati consoanele dintr-un sir de n caractere [x]
*/
void runOneDimensionalVectorCharProblems()
{
    // Afisati in ordine inversa caracterele dintr-un vector de caractere
    char v[] = "abcdef1234ZXYU";
    int charSize = sizeof(v) / sizeof(char);

    displayCharactersInReverse(v, charSize);

    // Afisati cifrele dintr-un vector de n caractere 
    displayNumericChars(v, charSize);

    // Afisati vocalele dintr-un sir de n caractere
    displayVowels(v, charSize);

    // Afisati consoanele dintr-un sir de n caractere
    displayConsonants(v, charSize);

    // Afisati literele mari dintr-un vector de n caractere
    displayUppercaseLetters(v, charSize);
}

/*
Repetitive cu vectori

- Cititi un vector cu n elemente int [x]
- Afisati un vector cu n elemente int [x]
- Cititi elementele unui vector cat timp ele sunt pozitive [x]
- [Afisati] Suma elementelor unui vector de int [x]
- [Afisati] Max/min elementelor unui vector de int [x]
- Afisati elementele pare ale unui vector de int [x]
- Afisati elementele de pe pozitiile pare ale unui vector [x]
- Afisati elementele de pe pozitiile multipli ai lui x ale unui vector [x]
- Afisati elementele multipli ai lui x dintr-un vector [x]
*/
void runOneDimensionalVectorIntProblems()
{
    // int out[] = { 1,2,3 }; vector initialized with values, but this is needless work
    int out[100];
    int size = sizeof(out) / sizeof(out[0]); // size in bytes / size of int

    // "Cititi un vector cu n elemente int"
    int numbersCount = readNumbersIntoVector(out, size); // out converts to pointer

    // "Afisati un vector cu n elemente int"
    // use the vector we just have lying around
    displayElements(out, numbersCount);

    // "Cititi elementele unui vector cat timp ele sunt pozitive"
    readValuesWhilePositive(out, numbersCount);

    // "[Afisati] Suma elementelor unui vector de int"
    displaySum(out, numbersCount);

    // [Afisati] Max/min elementelor unui vector de int
    displayMax(out, numbersCount);
    displayMin(out, numbersCount);

    // Afisati elementele pare ale unui vector de int
    displayEvenElements(out, numbersCount);

    // Afisati elementele de pe pozitiile pare ale unui vector
    displayElementsOnEvenIndices(out, numbersCount);

    // Afisati elementele de pe pozitiile multipli ai lui x ale unui vector
    int x = 3; // could also read it
    displayElementsOnIndicesMultiplesOfX(out, numbersCount, x);

    // Afisati elementele multipli ai lui x dintr-un vector
    displayMultiplesOfX(out, numbersCount, x);
}