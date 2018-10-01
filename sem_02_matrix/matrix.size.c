#include <stdio.h>
#include "matrix.h"

#define __EMRTY_SIZE 1
#define SUCCESS 0

int matrix_size(MATRIX matrix, int* rows, int* cols)
{
	if (matrix == NULL)
		return __EMRTY_SIZE;
	
	*cols = *(matrix + COL_OFFSET);
	*rows = *(matrix + ROW_OFFSET);
	
	return SUCCESS;
}

