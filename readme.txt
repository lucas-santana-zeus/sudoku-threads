Comandos para compilação:

gcc -c input/file.c -o out/file.o 
gcc -c matrix/sudoku.c -o out/sudoku.o
gcc -c validators/validators.c -o out/validators.o
gcc -o main main.c out/file.o out/sudoku.o out/validators.o

Comando para Execução:
./main

O programa lê um arquivo chamado "sudoku.txt"
Portanto para testar outros arquivos deve-se alterar o nomes deles para "sudoku.txt"