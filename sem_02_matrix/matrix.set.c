#include "matrix.h"

int matrix_set(MATRIX m, int row, int col, int val)
{
    if (m == NULL)
    {
        return ERR_MATRIX_NULL;
    }
    int real_rows = *(m + ROW_OFFSET);
    int real_columns = *(m + COL_OFFSET);

    if ((real_rows <= 0) || (real_columns <= 0))
    {
        return ERR_INCORRECT_DESCRIPTION;
    }

    if ((real_rows < row) || (real_columns < col))
    {
        return ERR_OUT_OF_RANGE;
    }

    *(m + row * real_columns + col) = val;
    return SUCCESS;
}
