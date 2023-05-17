// Escreva uma função que receba um arranjo e um inteiro, indicando o tamanho do
// arranjo. O valor de retorno deverá ser um novo arranjo, apenas com os valores
// do primeiro arranjo que forem diferentes de 0 (zero)

#include <stdio.h>
#include <stdlib.h>

#define VECTOR_SIZE 10

int vector_size_diff_0(int vector[], int vector_size) {
    int i;
    int amount_diff_0 = 0;

    for (i = 0; i < vector_size; i++) {
        if (vector[i] != 0) {
            amount_diff_0++;
        }
    }

    return amount_diff_0;
}

int *vector_diff_0(int vector[], int vector_size, int new_vector_size) {
    int *vector_return;
    int vector_adress = 0;
    int i;

    vector_return = (int *)malloc(new_vector_size * sizeof(int));

    for (i = 0; i < vector_size; i++) {
        if (vector[i] != 0) {
            vector_return[vector_adress] = vector[i];
            vector_adress++;
        }
    }

    return vector_return;
}

int main() {
    int vector[VECTOR_SIZE] = {-4, -3, -2, -1, 0, 1, 2, 3, 4, 5};
    int vector_size = VECTOR_SIZE;
    int *vector_res;
    int vector_size_res;
    int i;

    printf("[");
    for (i = 0; i < VECTOR_SIZE; i++) {
        printf("%d%s", vector[i], (i == VECTOR_SIZE - 1) ? "]\n" : ", ");
    }

    vector_size_res = vector_size_diff_0(vector, vector_size);

    vector_res = vector_diff_0(vector, vector_size, vector_size_res);
    printf("Arranjo com valores diferente de 0 = [");
    for (i = 0; i < vector_size_res; i++) {
        printf("%d%s", vector_res[i],
               (i == vector_size_res - 1) ? "]\n" : ", ");
    }
}
