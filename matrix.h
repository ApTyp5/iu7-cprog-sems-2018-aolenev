#ifndef __MATRIX_H
#define __MATRIX_H

#include <stdlib.h>
#include <stdio.h>

typedef int* MATRIX;

#define ROW_OFFSET -1
#define COL_OFFSET -2
#define TYPE_OFFSET -3
#define WRONG_MATRIX -4
#define MATRIX_SIZE_ERROR -5
#define NULLPTR_ERR -6
#define INVALID_DIMENSIONS_ERR -7
#define ALLOC_ERROR -8

#define SUCCESS 0
#define FAIL 10
#define __EMRTY_SIZE 1

MATRIX matrix_create(int row, int col);
MATRIX matrix_create_from_file(FILE* file);

int matrix_get(MATRIX, int row, int col);
int matrix_set(MATRIX, int row, int col, int val);

int matrix_resize(MATRIX* matrix, int rows, int cols);
int matrix_size(MATRIX matrix, int* rows, int* cols);

int matrix_transpose(MATRIX* matrix);
int matrix_print(MATRIX matrix, FILE* output);

int matrix_append_row(MATRIX* matrix);
int matrix_append_column(MATRIX* matrix);
int matrix_remove_row(MATRIX* matrix);
int matrix_remove_column(MATRIX* matrix);

MATRIX matrix_delete(MATRIX matrix);


#endif // __MATRIX_H

