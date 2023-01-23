#include "validators.h"
#include <stdio.h>
#include <pthread.h>

int check_valid_row(Params p);
int check_valid_column(Params p);
int check_valid_sub_square(Params p);

Params new_params(Matrix m, int row, int col, int **checker)
{
    Params p;
    p.m = m;
    p.column = col;
    p.row = row;
    p.checker = checker;
    return p;
}

void *validate_row(void *p)
{
    Params *params = (Params *)p;
    Matrix m = params->m;
    int row = params->row;
    int col = params->column;
    if (check_valid_row != 0)
    {
        printf("linha invalida: %d\n", row + 1);
        pthread_exit(NULL);
    }
    int position_validator[9] = {0};
    for (int i = 0; i < 9; i++)
    {
        int value = m.m[row][i];
        int pos = value - 1;
        if (value < 1 || value > 9 || position_validator[pos] == TRUE)
        {
            pthread_exit(NULL);
            return;
        }
        position_validator[pos] = TRUE;
    }
    params->checker[0][row] = 1;
    pthread_exit(NULL);
    return;
}

void *validate_column(void *p)
{
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