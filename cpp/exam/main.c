#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Congratulations, it's a Car */
typedef struct Car {
    int modelYear;
} Car;

/* Swaps two Cars (sneakily / by ref) */
void swapCars(Car* first, Car* second)
{
    Car temp = *first;
    *first = *second;
    *second = temp;
}

/* Builds matrix of Cars */
void generateTestData(int rows, int cols, int modelYear, Car* cars)
{
    srand(time(NULL));
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            int offset      = row * cols + col;
            int currentYear = modelYear + rand() % 40;
            struct Car car  = { currentYear };
            cars[offset]  = car;

            printf("Position is %d and year is %d\n", offset, currentYear);
        }
    }
}

/* Sorts given matrix of cars using bubble sort */
void bubbleSortCars(int rows, int cols, Car* cars)
{
    int i, j, n = rows * cols;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (cars[j].modelYear > cars[j + 1].modelYear) {
                swapCars(&cars[j], &cars[j + 1]);
            }
        }
    }
}

/* Sorts given matrix of cars using insertion sort */
void insertionSortCars(int rows, int cols, Car* cars)
{
    int i, j, n = rows * cols;

    for (i = 0; i < n; i++) {
        Car currentCar = cars[i];

        for (j = i; j > 0 && cars[j - 1].modelYear > currentCar.modelYear; j--) {
            cars[j] = cars[j - 1];
        }

        cars[j] = currentCar;
    }
}

/* Prints given vector of Cars */
void printVector(const Car* v, int size)
{
    for (int i = 0; i < size; i++) {
        printf("Position is %d and year is %d\n", i, v[i].modelYear);
    }
}

/* Builds a matrix of Car structs and sorts them based on their model year. Prints results. */
int main(void)
{
    int rows      = 3;
    int cols      = 4;
    int modelYear = 1920;
    Car* cars     = malloc(sizeof(Car) * rows * cols);

    printf("Building cars ... \n");
    generateTestData(rows, cols, modelYear, cars);

    printf("**************\n");

    printf("Sorting cars ...\n");
    // bubbleSortCars(rows, cols, cars);
    insertionSortCars(rows, cols, cars);

    printVector(cars, (rows * cols));
}