#include <stdlib.h>

#include "matrix.h"

#define SUCCESS 0
#define NULLPTR_ERR -1
#define INVALID_DIMENSIONS_ERR -2
#define ALLOC_ERROR -3

int min(int a, int b)
{
    return a > b ? b : a;
}

int matrix_resize(MATRIX* matrix, int rows, int cols)
{
    if (matrix == NULL)
        return NULLPTR_ERR;

    if (rows <= 0 || cols <= 0)
        return INVALID_DIMENSIONS_ERR;

    MATRIX m = matrix_create(rows, cols);

    if (m == NULL)
        return ALLOC_ERROR;

    for (int i = 0; i < min(rows, ((int*)matrix)[ROW_OFFSET]); i++)
        for (int j = 0; j < min(cols, ((int*)matrix)[COL_OFFSET]); j++)
            matrix_set(m, i, j, matrix_get(*matrix, i, j));

    matrix_delete(*matrix);

    *matrix = m;
}

