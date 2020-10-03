<?php

/**
 * Class Car
 */
class Car
{
    public $modelYear;

    public function __construct(int $modelYear)
    {
        $this->modelYear = $modelYear;
    }
}

/**
 * Generates car data for sorting
 *
 * @param int $rows
 * @param int $cols
 * @param int $initialYear
 * @return array
 */
function generateTestData(int $rows, int $cols, int $initialYear) : array
{
    $data = [];
    for ($i = 0; $i < $rows; $i++) {
        for ($j = 0; $j < $cols; $j++) {
            $modelYear = $initialYear + rand(1, 30);
            $data[$i][$j] = new Car($modelYear);
        }
    }

    return $data;
}

/**
 * Sorts a matrix of cars so that the cars on every row
 * are sorted by model year, ascending
 *
 * @param Car[] $cars
 */
function sortCarRowsByYear(array &$cars)
{
    foreach ($cars as $i => &$carRow) {
        sortCarRow($carRow);
        // sortCarRowPhpWay($carRow);
    }
}

/**
 * Sorts a row of cars in ascending order of model year.
 * Uses bubble sort.
 *
 * @param array $carRow
 */
function sortCarRow(array &$carRow)
{
    $n = count($carRow);

    foreach ($carRow as $i => $car) {
        $swapped = false;

        for ($j = 0; $j < $n - $i - 1; $j++) {
            // compare current element with next and swap them if necessary
            if ($carRow[$j]->modelYear > $carRow[$j+1]->modelYear) {
                $tmp          = $carRow[$j];
                $carRow[$j]   = $carRow[$j+1];
                $carRow[$j+1] = $tmp;

                $swapped = true;
            }
        }

        if (!$swapped) {
            break;
        }
    }
}

/**
 * Sorts cars with an user-defined function.
 *
 * @param array $carRow
 */
function sortCarRowPhpWay(array &$carRow) {
    usort($carRow, function($firstCar, $secondCar) {
        if ($firstCar->modelYear == $secondCar->modelYear) {
            return 0;
        }

        return $firstCar->modelYear > $secondCar->modelYear ? 1 : -1;
    });
}

/**
 * Prints model years for given array of cars.
 *
 * @param array $cars
 */
function echoCarData(array $cars)
{
    foreach ($cars as $i => $carRow) {
        foreach ($carRow as $j => $car) {
            echo "Car on row $i and column $j - {$car->modelYear}\n";
        }
        echo "- \n";
    }
}

/**
 * Generate test data and sort it
 */
$cars = generateTestData(4, 3, 1900);

echo "Initial data:\n\n";
echoCarData($cars);

sortCarRowsByYear($cars);

echo "**********************\n";
echo "Sorted data:\n\n";
echoCarData($cars);