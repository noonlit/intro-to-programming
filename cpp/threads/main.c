#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

typedef struct matrix
{
    int* data;
    int nrRows;
    int nrColumns;
} matrix;

typedef struct matrixData 
{
    matrix* firstMatrix;
    matrix* secondMatrix;
    matrix* resultMatrix;
    int resultRow;
    int resultCol;
} matrixData;

/* Util functions */
void matrixPrint(const matrix* pMatrix)
{
    for (int i = 0; i < pMatrix->nrRows; i++) {
        for (int j = 0; j < pMatrix->nrColumns; j++) {
            printf("%d ", matrixGet(pMatrix, i, j));
        }
        printf("\n");
    }
}

void matrixGenerate(matrix* pMatrix)
{
    /* Generate matrix with values < 10 */
    for (int i = 0; i < pMatrix->nrRows; i++) {
        for (int j = 0; j < pMatrix->nrColumns; j++) {
            matrixSet(pMatrix, i, j, rand() % 10);
        }
    }
}

matrix* matrixNew(int nrRows, int nrColumns)
{
    matrix* result    = malloc(sizeof(matrix));
    int size          = sizeof(int) * nrRows * nrColumns;
    result->data      = malloc(size);
    result->nrColumns = nrColumns;
    result->nrRows    = nrRows;

    return result;
}

void matrixDelete(matrix* matrix)
{
    free(matrix->data);
    free(matrix);
}

void matrixSet(matrix* m, int row, int col, int val)
{
    int offset = row * m->nrColumns + col;

    m->data[offset] = val;
}

int matrixGet(matrix* m, int row, int col)
{
    int offset = row * m->nrColumns + col;
    return m->data[offset];
}

/*  Multiplies matrices found in given args struct */
void* multiplyMatrices(void* matrixArgs)
{
    matrixData* args = matrixArgs;

    matrix* firstMatrix  = args->firstMatrix;
    matrix* secondMatrix = args->secondMatrix;
    matrix* result       = args->resultMatrix;

    // Calculate sum of products between row and column values
    int sum = 0;
    for (int i = 0; i < firstMatrix->nrColumns; i++) {
        int left  = matrixGet(firstMatrix, args->resultRow, i);
        int right = matrixGet(secondMatrix, i, args->resultCol);

        sum += left * right;
    }

    matrixSet(result, args->resultRow, args->resultCol, sum);

    free(matrixArgs);

    pthread_exit(NULL);
}

/* Multiples two matrices using threads */
int main()
{
    /* Seed random number generator */
    srand(time(NULL));

    int rows = 1;
    int cols = 2;
    matrix* firstMatrix = matrixNew(rows, cols);
    matrix* secondMatrix = matrixNew(cols, rows);

    /* Generate matrices to multiply */
    printf("First matrix:\n");
    matrixGenerate(firstMatrix);
    matrixPrint(firstMatrix);

    printf("\n");

    printf("Second matrix:\n");
    matrixGenerate(secondMatrix);
    matrixPrint(secondMatrix);

    printf("\n");

    /* Allocate space for result */
    int resultSize       = rows * rows;
    matrix* resultMatrix = matrixNew(rows, rows);

    /* Allocate space for threads */
    int threadsSize = sizeof(pthread_t) * resultSize;

    if (!threadsSize) {
        return 1;
    }

    pthread_t* threads = malloc(threadsSize);

    if (!threads) {
        return 1;
    }

    /* Create threads to multiply matrices */
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rows; j++) {
            matrixData* threadArgs   = malloc(sizeof(matrixData));
            threadArgs->firstMatrix  = firstMatrix;
            threadArgs->secondMatrix = secondMatrix;
            threadArgs->resultMatrix = resultMatrix;
            threadArgs->resultRow    = i;
            threadArgs->resultCol    = j;

            /*
            The first argument is a pointer to thread which is set by this function.
            The second argument specifies attributes. If the value is NULL, then default attributes shall be used.
            The third argument is name of function to be executed for the thread to be created.
            The fourth argument is used to pass arguments to the function.
            */
            pthread_create(&threads[i * rows + j], NULL, multiplyMatrices, (void*)threadArgs);
        }
    }

    // Wait for threads to complete so that they all wrote to the result
    for (int i = 0; i < resultSize; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Result:\n");
    matrixPrint(resultMatrix);

    matrixDelete(firstMatrix);
    matrixDelete(secondMatrix);
    matrixDelete(resultMatrix);

    return 0;
}
