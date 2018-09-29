#include <stdio.h>
#include "matrix.h"

/**
 * @brief matrix_create - Creates matrix
 * @param [in] row - number of rows
 * @param [in] col - number of cols
 * @return Created matrix
 */
MATRIX matrix_create(int row, int col)
{
    MATRIX matr = malloc((2+row*col)*sizeof(int));

    *matr++ = row;
    *matr++ = col;

    return matr;
}
