#include <stdio.h>
#include "matrix.h"


int matrix_get(MATRIX matrix, int row, int col)
{
    return *(matrix + row * *(matrix + COL_OFFSET) + col);
}
