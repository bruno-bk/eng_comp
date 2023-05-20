// 3) Faça uma função que receba o nome e o sobrenome de uma pessoa (em string
// separadas) e retorne uma string contendo o nome completo da pessoa.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *concat(char *data1, const char *data2) {
    strcat(data1, " ");
    strcat(data1, data2);
    return data1;
}

int main() {
    char data1[100] = "Hello";
    char data2[50] = "World";

    puts(concat(data1, data2));
}
