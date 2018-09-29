#include "matrix.h"

int min(int a, int b)
{
    return a > b ? b : a;
}

int matrix_resize(MATRIX* matrix, int rows, int cols)
{
    int row_1 = 0;
    int col_1 = 0;
    
    if (matrix == NULL)
        return NULLPTR_ERR;

    if (rows <= 0 || cols <= 0)
        return INVALID_DIMENSIONS_ERR;

    matrix_size(*matrix, &row_1, &col_1);
    
    MATRIX m = matrix_create(rows, cols);

    if (m == NULL)
        return ALLOC_ERROR;

    for (int i = 0; i < row_1; i++)
        for (int j = 0; j < col_1; j++)
            matrix_set(m, i, j, matrix_get(*matrix, i, j));

    matrix_delete(*matrix);

    *matrix = m;

    return SUCCESS;
}

