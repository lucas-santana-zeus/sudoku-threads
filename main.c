#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include "input/file.h"
#include "matrix/sudoku.h"
#include "validators/validators.h"

void *validate_row(void *p);
void *validate_column(void *p);
void *validate_sub_square(void *p);

sem_t sem_matrix;
sem_t sem_valid;
// [0]: rows; [1]: columns; [2]: sub_squares;
int valid[3][9] = {{0}}; // checker

int main()
{
    sem_init(&sem_matrix, 0, 1);
    sem_init(&sem_valid, 0, 1);

    pthread_t workers[27];

    int t_index = 0;

    FILE *sudoku = open_sudoku_file();
    Matrix s = get_sudoku_matrix(sudoku);

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (j == 0)
            { // valida linhas
                Params *p = new_params(s, i, j);
                pthread_create(&workers[t_index], NULL, validate_row, p);
                t_index++;
            }
            if (i == 0)
            {
                Params *p = new_params(s, i, j);
                pthread_create(&workers[t_index], NULL, validate_column, p);
                t_index++;
            }
            if (i % 3 == 0 && j % 3 == 0)
            {
                Params *p = new_params(s, i, j);
                pthread_create(&workers[t_index], NULL, validate_sub_square, p);
                t_index++;
            }
        }
    }

    for (int i = 0; i < 27; i++)
    {
        pthread_join(workers[i], NULL);
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            printf("%d ", valid[i][j]);
        }
        printf("\n");
    }

    sem_destroy(&sem_matrix);
    sem_destroy(&sem_valid);

    return 0;
}

void *validate_row(void *p)
{
    Params *params = (Params *)p;
    Matrix m = params->m;
    int row = params->row;
    int col = params->column;

    if (check_valid_row(*params) != 0)
    {
        printf("trabalhador linha - linha invalida: %d\n", row);
        pthread_exit(NULL);
    }

    int position_validator[9] = {0};
    for (int i = 0; i < 9; i++)
    {
        int value = m.m[row][i];
        int pos = value - 1;
        if (value < 1 || value > 9 || position_validator[pos] == TRUE)
        {
            printf("row: v:%d pos: %d\n", value, pos);
            pthread_exit(NULL);
        }
        position_validator[pos] = TRUE;
    }

    sem_wait(&sem_valid);
    valid[0][row] = 1;
    sem_post(&sem_valid);

    pthread_exit(NULL);
}

void *validate_column(void *p)
{
    Params *params = (Params *)p;
    Matrix m = params->m;
    int row = params->row;
    int col = params->column;

    if (check_valid_column(*params) != 0)
    {
        printf("trabalhador coluna - coluna invalida: %d\n", col);
        pthread_exit(NULL);
    }
    int position_validator[9] = {0};
    for (int i = 0; i < 9; i++)
    {
        int value = m.m[i][col];
        int pos = value - 1;
        if (value < 1 || value > 9 || position_validator[pos] == TRUE)
        {
            printf("col: v:%d pos: %d\n", value, pos);
            pthread_exit(NULL);
        }
        position_validator[pos] = TRUE;
    }

    sem_wait(&sem_valid);
    valid[1][col] = 1;
    sem_post(&sem_valid);
    pthread_exit(NULL);
}

void *validate_sub_square(void *p)
{
    Params *params = (Params *)p;
    Matrix m = params->m;
    int row = params->row;
    int col = params->column;

    if (check_valid_sub_square(*params) < 0)
    {
        printf("trabalhador sub quadrado - setor invalido: %d\n", row + col / 3);
        pthread_exit(NULL);
    }

    int position_validator[9] = {0};
    for (int i = row; i < row + 3; i++)
    {
        for (int j = col; j < col + 3; j++)
        {
            int value = m.m[i][j];
            int pos = value - 1;
            if (value < 0 || value > 9 || position_validator[pos] == TRUE)
            {
                printf("sq: v:%d pos: %d\n", value, pos);
                pthread_exit(NULL);
            }
            position_validator[pos] = TRUE;
        }
    }
    sem_wait(&sem_valid);
    valid[2][row + col / 3] = 1;
    sem_post(&sem_valid);
    pthread_exit(NULL);
}