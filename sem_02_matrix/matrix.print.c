#include <stdio.h>
#include "matrix.h"

int matrix_print(MATRIX matrix, FILE* output)
{
    int rows = 0, cols = 0;

	if (matrix == NULL)
		return -4;
	
    if (matrix_size(matrix, &rows, &cols) != 0)
		return -5;

    for (int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            fprintf(output, "%d %s", matrix_get(matrix, i, j),
                j == cols - 1 ? "\n" : " ");
        
    return 0;
}
