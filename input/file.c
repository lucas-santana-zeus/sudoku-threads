#include "file.h"
#include <stdio.h>
#include <stdlib.h>
#define SIZE 9

// FILE *open_sudoku_file();

// void get_sudoku_matrix()
// {

//     FILE *sudoku = open_sudoku_file();

//     for (int i = 0; i < SIZE; i++)
//     {
//         fscanf(sudoku, "%d %d %d %d %d %d %d %d %d",
//                &m[i][0], &m[i][1], &m[i][2], &m[i][3], &m[i][4], &m[i][5], &m[i][6], &m[i][7], &m[i][9]);
//     }
//     fclose(sudoku);
// }

FILE *open_sudoku_file()
{
    FILE *file;
    file = fopen("sudoku.txt", "r");
    if (file == NULL)
    {
        printf("Erro na abertura do arquivo");
        exit(1);
    }
    return file;
}