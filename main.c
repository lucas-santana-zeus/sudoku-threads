#include <stdio.h>
#include <stdlib.h>
#include "input/file.h"
#include "matrix/sudoku.h"

int matriz[9][9];

int main()
{
    // FILE *sudoku;
    // sudoku = fopen("sudoku.txt", "r");
    // if (sudoku == NULL)
    // {
    //     printf("Erro na abertura do arquivo");
    //     exit(1);
    // }

    // int m[9][9];
    // for (int i = 0; i < 9; i++)
    // {
    //     fscanf(sudoku, "%d %d %d %d %d %d %d %d %d",
    //            &m[i][0], &m[i][1], &m[i][2], &m[i][3], &m[i][4], &m[i][5], &m[i][6], &m[i][7], &m[i][9]);
    // }

    FILE *sudoku = open_sudoku_file();
    Matrix s = get_sudoku_matrix(sudoku);

    for (int i = 0; i < 9; i++)
    {
        printf("%d %d %d %d %d %d %d %d %d\n",
               s.m[i][0], s.m[i][1], s.m[i][2], s.m[i][3], s.m[i][4], s.m[i][5], s.m[i][6], s.m[i][7], s.m[i][9]);
    }

    // fclose(sudoku);

    return 0;
}