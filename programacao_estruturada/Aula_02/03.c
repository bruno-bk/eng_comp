// 3) Desafio para quem quiser tentar: Escreva um programa em C que leia um
// valor inteiro N (entre 0 e 1000). Depois disso, leia N números inteiros e
// armazene todos. Imprima: os valores lidos, os valores em ordem crescente, os
// valores em ordem contrária a que foram inseridos.

#include <stdio.h>
#include <stdlib.h>

void main() {
    int amount = 0;
    int amount_printed = 0;
    int i, j;
    int less;
    int larger;

    printf("Digite a quantidade de valores: ");
    scanf("%i", &amount);

    int value[amount];

    for (i = 0; i < amount; i++) {
        printf("Digite o valor %i: ", i + 1);
        scanf("%i", &value[i]);

        if (i == 0) {
            less = value[i];
            larger = value[i];
        } else if (value[i] < less) {
            less = value[i];
        } else if (value[i] > larger) {
            larger = value[i];
        }
    }

    printf("\nOrdem de digitacao: [");
    for (i = 0; i < amount; i++) {
        if (amount_printed == amount - 1) {
            amount_printed = 0;
            printf("%i", value[i]);
        } else {
            amount_printed++;
            printf("%i,", value[i]);
        }
    }
    printf("]\n");

    printf("Ordem crescente: [");
    for (i = less; i <= larger; i++) {
        for (j = 0; j < amount; j++) {
            if (value[j] == i) {
                if (amount_printed == amount - 1) {
                    amount_printed = 0;
                    printf("%i", value[j]);
                } else {
                    amount_printed++;
                    printf("%i,", value[j]);
                }
            }
        }
    }
    printf("]\n");

    printf("Ordem contraria a digitacao: [");
    for (i = amount - 1; i >= 0; i--) {
        if (amount_printed == amount - 1) {
            amount_printed = 0;
            printf("%i", value[i]);
        } else {
            amount_printed++;
            printf("%i,", value[i]);
        }
    }
    printf("]\n");
}
