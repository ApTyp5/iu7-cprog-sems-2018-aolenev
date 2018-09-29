#include <stdio.h>
#include "matrix.h"

/**
 *
 */
MATRIX matrix_create(int row, int col)
{
	int* matrix = malloc((row*col + 3)*sizeof(int));
	return matrix+3;
}
