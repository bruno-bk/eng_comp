// Escreva uma função que receba como parâmetro um arranjo com 10 valores
// inteiros e retorne um novo arranjo, em que a posição 0 contenha o número de
// elementos desse novo arranjo, seguido pelos elementos do primeiro arranjo que
// forem pares.

// Repita o exercício anterior, mas retornando apenas os elementos do primeiro
// arranjo que forem primos. OBS: Utilize alocação dinâmica para criar um novo
// arranjo com o tamanho exato necessário.

#include <stdio.h>
#include <stdlib.h>

int *vector_pair(int vector[], int vector_size) {
    int amount_pair = 1;
    int i;
    int *vector_return;
    int vector_adress = 1;

    for (i = 0; i < vector_size; i++) {
        if (vector[i] % 2 == 0) {
            amount_pair++;
        }
    }

    vector_return = (int *)malloc(amount_pair * sizeof(int));
    vector_return[0] = amount_pair;

    for (i = 0; i < vector_size; i++) {
        if (vector[i] % 2 == 0) {
            vector_return[vector_adress] = vector[i];
            vector_adress++;
        }
    }

    return vector_return;
}

int is_prime_number(int number) {
    int i;
    if (number < 2 && number > -2) {
        return 0;
    } else if (number >= 2) {
        for (int i = 2; i < number; i++) {
            if (number % i == 0) {
                return 0;
            }
        }
    } else {
        for (int i = number + 1; i < -1; i++) {
            if (number % i == 0) {
                return 0;
            }
        }
    }
    return 1;
}

int *vector_prime(int vector[], int vector_size) {
    int amount_prime = 1;
    int i;
    int *vector_return;
    int vector_adress = 1;

    for (i = 0; i < vector_size; i++) {
        if (is_prime_number(vector[i])) {
            amount_prime++;
        }
    }

    vector_return = (int *)malloc(amount_prime * sizeof(int));
    vector_return[0] = amount_prime;

    for (i = 0; i < vector_size; i++) {
        if (is_prime_number(vector[i])) {
            vector_return[vector_adress] = vector[i];
            vector_adress++;
        }
    }

    return vector_return;
}

void main() {
    int vector[10] = {-4, -3, -2, -1, 0, 1, 2, 3, 4, 5};
    int *vector_res;
    int vector_size = 10;
    int i;

    printf("[");
    for (i = 0; i < 10; i++) {
        printf("%d%s", vector[i], (i == 9) ? "]\n" : ", ");
    }

    vector_res = vector_pair(vector, vector_size);
    printf("\narranjo de numero par = [");
    for (i = 0; i < vector_res[0]; i++) {
        printf("%d%s", vector_res[i], (i == vector_res[0] - 1) ? "]\n" : ", ");
    }
    free(vector_res);

    vector_res = vector_prime(vector, vector_size);
    printf("arranjo de numero primo = [");
    for (i = 0; i < vector_res[0]; i++) {
        printf("%d%s", vector_res[i], (i == vector_res[0] - 1) ? "]\n" : ", ");
    }
    free(vector_res);
}
