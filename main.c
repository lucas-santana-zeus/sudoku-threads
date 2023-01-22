#include <stdio.h>
#include <stdlib.h>
#include "print/teste.h"

int main()
{
    FILE *sudoku;
    sudoku = fopen("sudoku.txt", "r");
    if (sudoku == NULL)
    {
        printf("Erro na abertura do arquivo");
        exit(1);
    }

    int a, b, c, d, e, f, g, h, i;
    fscanf(sudoku, "%d %d %d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &g, &h, &i);
    printf("%d %d %d %d %d %d %d %d %d\n", a, b, c, d, e, f, g, h, i);

    fclose(sudoku);
    return 0;
}