// Exercício 3
// Crie um programa contendo o seguinte trecho de código:

// int a = 25;
// int *pa = &a;
// int b = *pa + a;
// printf("%d %d %d %d %d %d\n", a, pa, &a, *pa, b, &b);

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    int a = 25;
    int *pa = &a;
    int b = *pa + a;
    printf("%d %d %d %d %d %d\n", a, pa, &a, *pa, b, &b);
    getchar();
    return 0;
}
