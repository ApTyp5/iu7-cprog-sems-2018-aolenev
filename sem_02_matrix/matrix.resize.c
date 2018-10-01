#include "matrix.h"

int min(int a, int b)
{
    return a > b ? b : a;
}

int matrix_resize(MATRIX* matrix, int rows, int cols)
{
    int old_rows = 0;
    int old_cols = 0;
    
    if (matrix == NULL)
        return NULLPTR_ERR;

    if (rows <= 0 || cols <= 0)
        return INVALID_DIMENSIONS_ERR;

    matrix_size(*matrix, &old_rows, &old_cols);
    
    MATRIX m = matrix_create(rows, cols);

    if (m == NULL)
        return ALLOC_ERROR;

    for (int i = 0; i < min(rows, old_rows); i++)
        for (int j = 0; j < min(cols, old_cols); j++)
            matrix_set(m, i, j, matrix_get(*matrix, i, j));

    matrix_delete(*matrix);

    *matrix = m;

    return SUCCESS;
}

