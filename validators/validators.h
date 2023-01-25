#ifndef VALIDATORS
#define VALIDATORS
#include "../matrix/sudoku.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define TRUE 1
#define FALSE 0

typedef struct
{
    Matrix m;
    int row;
    int column;
} Params;

Params *new_params(Matrix m, int row, int col);
int check_valid_row(Params p);
int check_valid_column(Params p);
int check_valid_sub_square(Params p);

#endif