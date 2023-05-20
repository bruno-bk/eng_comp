// 4) Crie funções que
// implementem a mesmas funcionalidades das funções abaixo:

// strlen.
// strcat.
// strcpy.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int func_strlen(char *data) {
    int size = 0;
    while (data[size] != '\0') {
        size++;
    }
    return size;
}

char *func_strcat(char *data1, char *data2) {
    int size1 = 0;
    int size2 = 0;
    while (data1[size1] != '\0') {
        size1++;
    }
    while (data2[size2] != '\0') {
        data1[size1] = data2[size2];
        size1++;
        size2++;
    }
    data1[size1] = '\0';

    return data1;
}

char *func_strcpy(char *data1, char *data2) {
    int size = 0;

    while (data2[size] != '\0') {
        data1[size] = data2[size];
        size++;
    }
    data1[size] = '\0';

    return data1;
}

int main() {
    char data1[20] = "Hello";
    char data2[10] = "World";
    char data3[20];

    printf("strlen %s = %i\n", data1, func_strlen(data1));

    printf("strcat %s\n", func_strcat(data1, data2));

    printf("strcpy %s\n", func_strcpy(data3, data1));
}
