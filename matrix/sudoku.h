#ifndef SUDOKU_MATRIX
#define SUDOKU_MATRIX
#include <stdio.h>

typedef struct
{
    int m[9][9];
} Matrix;

Matrix get_sudoku_matrix(FILE *sudoku_file);

#endif