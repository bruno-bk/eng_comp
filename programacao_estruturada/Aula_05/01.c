// Construa uma função que efetue a leitura dos elementos de um arranjo de
// inteiro. Para tanto a função recebará como parâmetros um arranjo de inteiros
// e um inteiro indicando seu tamanho (seu número de elementos). O tipo de
// retorno deve ser necessariamente void. Escreva um programa para testar esta
// função.

#include <stdio.h>
#include <stdlib.h>

void read_vector(int vector[], int vector_size) {
    int i;
    for (i = 0; i < vector_size; i++) {
        printf("Digite o valor do elemento %i = ", i);
        scanf("%i", &vector[i]);
    }
}

int main() {
    int i;
    int vector[5];
    int vector_size = 5;

    read_vector(vector, vector_size);

    for (i = 0; i < vector_size; i++) {
        printf("Valor de %i = %i\n", i, vector[i]);
    }
}