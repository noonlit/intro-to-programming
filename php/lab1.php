<?php
/**
 * Source: https://docs.google.com/document/d/e/2PACX-1vRAw-8yfiw2GYhPV3cfmuA2sirvB1gpdqR6TE-NpjBbPu1dDC7QFDQ68t3h2DkJxJ5BkBi_1FoUMm0x/pub
 */

/**
 * Accepts square matrix, returns sum of elements on main diagonal.
 *
 * @param array $input
 * @return float
 */
function addMainDiagonalElements(array $input) : float
{
    $sum = 0;
    $inputLength = count($input);

    for ($i = 0; $i < $inputLength; $i++) {
        $element = $input[$i];
        $elementLength = count($element);

        for ($j = 0; $j < $elementLength; $j++) {
            // in order for an element to be part of the diagonal,
            // the row counter must be equal to the column counter
            if ($i == $j) {
                $sum += (float) $element[$j];
            }
        }
    }

    return $sum;
}

/**
 * Accepts square matrix, returns sum of elements beneath main diagonal
 *
 * @param array $input
 * @return float
 */
function addElementsBeneathMainDiagonal(array $input) : float
{
    $sum = 0;
    $inputLength = count($input);

    for ($i = 0; $i < $inputLength; $i++) {
        $element = $input[$i];
        $elementLength = count($element);

        for ($j = 0; $j < $elementLength; $j++) {
            // in order for an element to be beneath the diagonal,
            // the row counter must be smaller than the column counter
            if ($j < $i) {
                $sum += (float) $element[$j];
            }
        }
    }

    return $sum;
}

$input = [
    [1, 2, 3, 4],
    [1, 2, 3, 4],
    [1, 2, 3, 4],
    [1, 2, 3, 4]
];

// main diagonal
// echo addMainDiagonalElements($input);

// elements under main diagonal
echo addElementsBeneathMainDiagonal($input);
