//#include <stdlib.h>
#include "matrix.h"

#define SUCCESS 0
#define ERROR_FREE -1

int matrix_delete(MATRIX matrix)
{
    if (matrix == NULL)
        return ERROR_FREE;
    
    if ((matrix + TYPE_OFFSET) != NULL)
        free(matrix + TYPE_OFFSET);
    else
        return ERROR_FREE;
    
    return SUCCESS;
}
