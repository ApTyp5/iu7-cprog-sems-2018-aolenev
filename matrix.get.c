#include <stdio.h>
#include "matrix.h"

#define MIN_SIZE 0

int matrix_get(MATRIX matrix, int row, int col)
{
    return *(matrix + row * *(matrix - 2) + col);
}
