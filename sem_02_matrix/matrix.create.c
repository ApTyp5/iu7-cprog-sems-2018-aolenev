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
    if (!(col > 0 && row > 0))
        return NULL;

    MATRIX matr = calloc((3+row*col), sizeof(int));

    if (!matr)
        return NULL;

    *matr++ = 1;
    *matr++ = row;
    *matr++ = col;

    return matr;
}
