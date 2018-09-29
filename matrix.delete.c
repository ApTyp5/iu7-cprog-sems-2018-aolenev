#include <stdlib.h>
#include "matrix.h"

#define SUCCESS 0
#define ERROR_FREE -1

int matrix_delete(MATRIX matrix)
{
    if (matrix - 2 == NULL)
        return ERROR_FREE;
    
    free(matrix - 2);
    
    return SUCCESS;
}
