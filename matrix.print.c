#include <stdio.h>
#include "matrix.h"

int matrix_print(MATRIX matrix, FILE* output)
{
	int rows = 0, cols = 0;

	matrix_size(matrix, &rows, &cols);

	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < cols; j++)
		{
			fprintf(output, "%d ", matrix_get(matrix, i, j));
		}

		printf("\n");
	}
}
