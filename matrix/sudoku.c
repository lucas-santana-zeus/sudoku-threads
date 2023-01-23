#include "sudoku.h"
#include <stdio.h>
#include <stdlib.h>

Matrix get_sudoku_matrix(FILE *sudoku_file)
{
    Matrix s;
    for (int i = 0; i < 9; i++)
    {
        fscanf(sudoku_file, "%d %d %d %d %d %d %d %d %d",
               &s.m[i][0], &s.m[i][1], &s.m[i][2], &s.m[i][3], &s.m[i][4], &s.m[i][5], &s.m[i][6], &s.m[i][7], &s.m[i][9]);
    }
    fclose(sudoku_file);
    return s;
}