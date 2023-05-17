// 2. Escreva uma função que determine o número de segundos decorridos entre
// dois instantes. Cada instante é dado como três valores inteiros válidos
// correspondentes a hora (0...23), minuto (0...59) e segundo (0 ... 59).
// Escreva  um programa que leia dois valores válidos de instantes,
// fornecendo-os a esta função para que se determine o número de segundos entre
// tais instantes

#include <stdio.h>
#include <stdlib.h>

int input_int(char *title, int min, int max) {
    int value;
    do {
        printf("%s (%i-%i): ", title, min, max);
        scanf("%i", &value);
        if (value < min || value > max) {
            printf("O valor deve estar entre %i e %i\n", min, max);
        }
    } while (value < min || value > max);
}

int main() {
    int timestamp[2];
    int i;

    for (i = 0; i < 2; i++) {
        int hour = input_int("hora", 0, 23);
        int minute = input_int("minuto", 0, 59);
        int second = input_int("segundo", 0, 59);

        timestamp[i] = second + (minute * 60) + (hour * 60 * 60);
    }

    printf("\nDiferença de %i segundos\n", timestamp[1] - timestamp[0]);
}