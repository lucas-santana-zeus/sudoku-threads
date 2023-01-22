#include <stdio.h>
#include <stdlib.h>
#include "print/teste.h"
#include "input/sudoku.h"

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

    get_sudoku_matrix(matriz);

    for (int i = 0; i < 9; i++)
    {
        printf("%d %d %d %d %d %d %d %d %d\n",
               matriz[i][0], matriz[i][1], matriz[i][2], matriz[i][3], matriz[i][4], matriz[i][5], matriz[i][6], matriz[i][7], matriz[i][9]);
    }

    // fclose(sudoku);

    return 0;
}