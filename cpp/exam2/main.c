#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Utils */
void printMatrix(int* const matrix, int rows, int cols)
{
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            int offset = row * cols + col;
            printf("%d ", matrix[offset]);
        }
        printf("\n");
    }
}

/* Sort primary diagonal of square matrix */
int main(void)
{
    int rows = 4;
    int cols = 4;
    int size = sizeof(int) * rows * cols;

    if (!size) {
        return;
    }

    int* matrix = (int*) malloc(size);

    if (!matrix) {
        return;
    }

    // populate matrix, keeping values less than 10
    srand(time(NULL));
    for (int i = 0, n = rows * cols; i < n; i++) {
        matrix[i] = rand() % 10;
    }

    // show original matrix
    printMatrix(matrix, rows, cols);

    // sort diagonal
    int swapped;
    do {
        swapped = 0;

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (col == row) { // i.e. we are on primary diagonal
                    // current position
                    int offset = row * cols + col;

                    // position of next diagonal element
                    int nextElementOffset = offset + cols + 1;

                    // sanity check: are we within bounds?
                    if (nextElementOffset < (rows * cols)) {
                       // swap current element with the next one if necessary
                        if (matrix[nextElementOffset] < matrix[offset]) {
                            int tmp                   = matrix[offset];
                            matrix[offset]            = matrix[nextElementOffset];
                            matrix[nextElementOffset] = tmp;
                            
                            // register swap
                            swapped = 1;
                        }
                    }
                }
            }
        }
    } while (swapped);

    printf("*****************************\n");

    // show final result
    printMatrix(matrix, rows, cols);
}