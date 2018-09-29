#include <stdlib.h>
#include "matrix.h"

void matrix_delete(MATRIX matrix)
{
    free(matrix - 2);
}
