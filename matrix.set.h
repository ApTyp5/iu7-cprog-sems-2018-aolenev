#ifndef __MATRIX_SET_H__
#define __MATRIX_SET_H__

#include "matrix.h"

#define SUCCESS 0
#define ERR_MATRIX_NULL -1
#define ERR_OUT_OF_RANGE -2
#define ERR_INCORRECT_DESCRIPTION -3

int matrix_set(MATRIX, int row, int col, int val);
#endif
