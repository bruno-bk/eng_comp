// 6) Crie um programa que leia strings digitadas pelo usuário e informe se a
// string digitada é um número ou uma palavra.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_number(char *data) {
    int i;

    for (i = 0; i < strlen(data); i++) {
        if (data[i] < 48 || data[i] > 57) {
            return 0;
        }
    }

    return 1;
}

int main() {
    char data[100];

    printf("Digite uma string: ");
    gets(data);

    if (is_number(data)) {
        printf("a string '%s' e um numero\n", data);
    } else {
        printf("a string '%s' nao e um numero\n", data);
    }
}
