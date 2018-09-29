#include "matrix.h"

#include <stdio.h>

int matrix_set(MATRIX, int row, int col, int val)
{
    if (MATRIX == NULL)
    {
        return ERR_MATRIX_NULL;
    }
    int real_rows = *(MATRIX + ROW_OFFSET);
    int real_columns = *(MATRIX + COL_OFFSET);

    if ((real_rows <= 0) || (real_columns <= 0))
    {
        return ERR_INCORRECT_DESCRIPTION;
    }

    if ((real_rows < row) || (real_columns < col))
    {
        return ERR_OUT_OF_RANGE;
    }

    *(MATRIX + row * real_columns + col) = val;
    return SUCCESS;
}
