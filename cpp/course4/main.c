#include <stdlib.h>
#include <stdio.h>
#include "course4.h"

struct Point // global
{
    int x, y;
};

int main(void)
{
    // A valid initialization. member x gets value 0 and y 
    // gets value 1.  The order of declaration is followed. 
    struct Point point = { 0, 1 };
    printf("%d\n", point.x);

    /*
    Class example for reading vector
    */
    int v[3] = { 1, 2, 3 }, n;

    // printf("%d\n", *(v + 2)); // print third value
    
    readVector(&v, &n);
}

/* Reads a vector of length n */
void readVector(int* pV, int* n)
{
    printf("Length?\n");
    scanf_s("%d", n); // let's pretend this is unproblematic

    int length = *n;
    for (int i = 0; i < length; i++) {
        scanf_s("%d", &pV[i]);
    }
}