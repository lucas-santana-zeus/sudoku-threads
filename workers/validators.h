#ifndef VALIDATORS
#define VALIDATORS
#include "../matrix/sudoku.h"
#include <stdio.h>
#include <pthread.h>
#define TRUE 1
#define FALSE 0

typedef struct
{
    Matrix m;
    int row;
    int column;
    int **checker;
} Params;

Params new_params(Matrix m, int row, int col, int **checker);
void *validate_row(void *p);
void *validate_column(void *p);

#endif