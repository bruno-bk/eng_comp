// Exercício 1
// Escreva um programa utilizando a linguagem C, que lei o array:
// [2,3,5,6,8,8,10,12], e imprima os valores repetidos.

// getchar();
// scanf();
// printf();

#include <stdlib.h>
#include <stdio.h>


int main() {
    const int SIZE = 8;
    int array[SIZE];
    int i;
    int j;

    for (i = 0; i < SIZE; i++) {
        printf("digite o elemento %d: ", i);
        scanf("%i", &array[i]);
    }

    for (i = 0; i < SIZE; i++) {
        for (j = i+1; j < SIZE; j++) {
            if (array[i] == array[j]) {
                printf("Os indices %d e %d possuem o valor repetido: %d\n", i, j, array[i]);
            }
        }
    }

    return 0;
}