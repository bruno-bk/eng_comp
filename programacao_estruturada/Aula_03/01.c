// 1. Dados dois conjuntos de 20 de números reais previamente ordenados,
// escrever um programa capaz de obter um terceiro conjunto, também ordenado,
// contendo os elementos da intersecção (apenas os elementos comuns aos dois
// conjuntos, sem repetição de elementos) dos conjuntos originais.

#include <stdio.h>
#include <stdlib.h>

void main() {
    int amount_value = 20;
    float value1[] = {1,  2,  3,  4,  5,  6,  7,  8,  9,  10,
                      11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    float value2[] = {0,  1,  3,  4,  8,  10, 15, 24, 25, 26,
                      27, 28, 29, 30, 31, 32, 33, 34, 35, 36};
    float value3[amount_value];
    int value3_index = 0;
    int i, j;

    for (i = 0; i < amount_value; i++) {
        for (j = 0; j < amount_value; j++) {
            if (value1[i] == value2[j]) {
                value3[value3_index] = value1[i];
                value3_index++;
            }
        }
    }

    printf("Conjunto 1\n{");
    for (i = 0; i < amount_value; i++) {
        if (i < amount_value - 1) {
            printf("%.2f, ", value1[i]);
        } else {
            printf("%.2f", value1[i]);
        }
    }
    printf("}\n");

    printf("Conjunto 2\n{");
    for (i = 0; i < amount_value; i++) {
        if (i < amount_value - 1) {
            printf("%.2f, ", value2[i]);
        } else {
            printf("%.2f", value2[i]);
        }
    }
    printf("}\n");

    printf("Conjunto de intersecção\n{");
    for (i = 0; i < value3_index; i++) {
        if (i < value3_index - 1) {
            printf("%.2f, ", value3[i]);
        } else {
            printf("%.2f", value3[i]);
        }
    }
    printf("}\n");
}