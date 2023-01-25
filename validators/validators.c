#include "validators.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

Params *new_params(Matrix m, int row, int col)
{
    Params *p = (Params *)malloc(sizeof(Params));
    p->m = m;
    p->column = col;
    p->row = row;

    return p;
}

int check_valid_row(Params p)
{
    if (p.column != 0 || p.row > 8)
    {
        return -1;
    }
    return 0;
}

int check_valid_column(Params p)
{
    if (p.row != 0 || p.column > 8)
    {
        return -1;
    }
    return 0;
}

int check_valid_sub_square(Params p)
{
    if (p.row > 6 || p.column > 6 || p.row % 3 != 0 || p.column % 3 != 0)
    {
        return -1;
    }
    return 0;
}