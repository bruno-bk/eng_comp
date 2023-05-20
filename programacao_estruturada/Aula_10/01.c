// 1) Escreva uma função que
// decida se uma string é ou não um palíndromo (ou seja, se o inverso da
// string é igual a ela). Escreva um programa para testar a função.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_palindrome(char *data) {
    char data_inv[100];
    int i = 0;
    int j = strlen(data) - 1;

    for (i = 0; i < strlen(data); i++) {
        data_inv[j] = data[i];
        j--;
    }
    data_inv[strlen(data)] = '\0';
    if (strcmp(data, data_inv) == 0) {
        return 1;
    }
    return 0;
}

int main() {
    char data[100];

    printf("Digite a palavra: ");
    gets(data);

    printf("A palavra %s ", data);
    if (is_palindrome(data)) {
        printf("e palindromo\n");
    } else {
        printf("nao e palindromo\n");
    }
}
