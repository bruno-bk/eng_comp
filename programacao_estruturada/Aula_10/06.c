// 7) Crie um programa que leia 3 strings digitadas pelo usuário e as coloque em
// ordem crescente.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char data1[100];
    char data2[100];
    char data3[100];

    printf("Digite a string 1: ");
    gets(data1);
    printf("Digite a string 2: ");
    gets(data2);
    printf("Digite a string 3: ");
    gets(data3);

    printf("\nOrdem crescente:\n");
    if (strcmp(data1, data2) < 0 && strcmp(data1, data3) < 0) {
        printf("%s\n", data1);
        if (strcmp(data2, data3) < 0) {
            printf("%s\n", data2);
            printf("%s\n", data3);
        } else {
            printf("%s\n", data3);
            printf("%s\n", data2);
        }
    } else if (strcmp(data2, data1) < 0 && strcmp(data2, data3) < 0) {
        printf("%s\n", data2);
        if (strcmp(data1, data3) < 0) {
            printf("%s\n", data1);
            printf("%s\n", data3);
        } else {
            printf("%s\n", data3);
            printf("%s\n", data1);
        }
    } else if (strcmp(data3, data1) < 0 && strcmp(data3, data1) < 0) {
        printf("%s\n", data3);
        if (strcmp(data1, data2) < 0) {
            printf("%s\n", data1);
            printf("%s\n", data2);
        } else {
            printf("%s\n", data2);
            printf("%s\n", data1);
        }
    }
}
