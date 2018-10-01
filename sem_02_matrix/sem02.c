#include <stdio.h>

#include "matrix.h"

int main(void)
{
	MATRIX m = matrix_create(3, 3);

	matrix_set(m, 0, 0, 1);
	matrix_set(m, 0, 1, 2);
	matrix_set(m, 0, 2, 3);
	matrix_print(m, stdout);

	matrix_resize(&m, 4, 4);
	matrix_set(m, 3, 3, 4);
	matrix_print(m, stdout);

	// matrix_transpose(&m);
	matrix_print(m, stdout);

	matrix_delete(m);

	return 0;
}
