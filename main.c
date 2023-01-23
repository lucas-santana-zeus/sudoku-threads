#include <stdio.h>
#include <stdlib.h>
#include "input/file.h"
#include "matrix/sudoku.h"

// typedef struct
// {
//     int row;
//     int column;
// } params;

// [0]: rows; [1]: columns; [2]: sub_squares;
int valid[3][9];

int main()
{

    FILE *sudoku = open_sudoku_file();
    Matrix s = get_sudoku_matrix(sudoku);

    // for (int i = 0; i < 9; i++)
    // {
    //     printf("%d %d %d %d %d %d %d %d %d\n",
    //            s.m[i][0], s.m[i][1], s.m[i][2], s.m[i][3], s.m[i][4], s.m[i][5], s.m[i][6], s.m[i][7], s.m[i][9]);
    // }

    return 0;
}