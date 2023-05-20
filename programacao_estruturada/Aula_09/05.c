// 5. Dados dois conjuntos de 5 números reais previamente ordenados, escrever um
// programa capaz de obter um terceiro conjunto, também ordenado, contendo os
// elementos da intersecção não nulos(todos os elementos que se repetem) dos
// conjuntos originais, exceto os que forem zero. Escreva uma função que retorne
// o terceiro vetor.

#include <stdio.h>
#include <stdlib.h>

#define VECTOR_SIZE 20

int *intersection(int vector1[], int vector2[], int vector_size, int *size) {
    int i;
    int j;
    int *new_vector;
    int address = 0;

    *size = 0;

    for (i = 0; i < vector_size; i++) {
        for (j = 0; j < vector_size; j++) {
            if (vector1[i] == vector2[j] && vector1[i] != 0) {
                (*size)++;
            }
        }
    }

    new_vector = (int *)malloc((*size) * sizeof(int));

    for (i = 0; i < vector_size; i++) {
        for (j = 0; j < vector_size; j++) {
            if (vector1[i] == vector2[j] && vector1[i] != 0) {
                new_vector[address] = vector1[i];
                address++;
            }
        }
    }
    return new_vector;
}

void print_vetor(int vetor[], int n, const char *title) {
    printf("%s = [", title);
    for (int i = 0; i < n; i++) {
        printf("%d%s", vetor[i], (i == n - 1) ? "]\n" : ", ");
    }
}

int main() {
    int i;
    int SIZE = 20;
    int value1[] = {-2, -1, 3,  4,  5,  6,  7,  8,  9,  10,
                    11, 12, 13, 14, 15, 16, 17, 18, 19, 30};
    int value2[] = {-2, 0,  1,  3,  4,  8,  10, 15, 24, 25,
                    26, 27, 28, 29, 30, 31, 32, 33, 36, 40};
    int size_3;
    int *value3;

    value3 = intersection(value1, value2, VECTOR_SIZE, &size_3);

    print_vetor(value1, SIZE, "vetor1");
    print_vetor(value2, SIZE, "vetor1");
    print_vetor(value3, size_3, "intersection");
}
