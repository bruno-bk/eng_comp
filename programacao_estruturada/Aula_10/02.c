// 2) Escreva uma função que
// receba uma string de 0s e 1s, interprete essa string como um número em
// notação binária e devolva o valor desse número.

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void calc_bin(char *data) {
    int num = 0;
    int i;

    for (i = (strlen(data) - 1); i >= 0; i--) {
        if (data[i] == '1') {
            num += pow(2, ((strlen(data) - 1) - i));
        }
    }
    printf("O numero %s = %i decimal\n", data, num);
}

int main() {
    char data[100];

    printf("Digite a numero em binario: ");
    gets(data);

    calc_bin(data);
}
