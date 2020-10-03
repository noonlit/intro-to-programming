#include <stdio.h>
#include <stdlib.h>


int labyrinth[10][10];

/* Prints given matrix in matrix-y format */
void printMatrix(int rows, int cols, int* v)
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int offset = i * cols + j;
            printf("%d ", v[offset]);
        }

        printf("\n");
    }
}

/* Recursively adds numbers up to n */
int f(int n)
{
    if (n == 1) {
        return 1;
    }

    return n + f(n - 1);
}

int findPath(int i, int j)
{
    if (labyrinth[i][j] == 2) {
        printf("%d-%d", i, j);
        return 2;
    }

    if (labyrinth[i][j] == 1) {
        return 1;
    }

    labyrinth[i][j] = 1;

    if (findPath(i, j + 1) == 2) {
        return 2;
    }

    if (findPath(i + 1, j) == 2) {
        return 2;
    }

    if (findPath(i + 1, j) == 2) {
        return 2;
    }

    if (findPath(i + 1, j) == 2) {
        return 2;
    }

    return 1;
}

int main(void)
{
    // review matrix problems
    int rows = 2;
    int cols = 3;

    int m[2][3] = { 3, 5, 1, 2, 4, 9 };

    // printMatrix(rows, cols, m);

    // this sorts the matrix, truly
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // magic();
        }
    }

    // recursion
    // printf("%d", f(12));

    // backtracking
    printMatrix(10, 10, (int *) labyrinth);
    printf("\n\n");

    int n = 10;

    // create borders
    for (int i = 0; i < n; i++) {
        labyrinth[i][0] = 1;
        labyrinth[i][n - 1] = 1;
        labyrinth[0][i] = 1;
        labyrinth[n - 1][i] = 1;
    }

    // create exit
    labyrinth[n - 2][n - 2] = 2;

    printMatrix(10, 10, (int *) labyrinth);

    findPath(1, 1);
}