// 01) Elabore uma função recursiva em linguagem C/C++ para realizar a
// operação de exponenciação ab, onde a e b são inteiros

// int Eleva(int a, int b)
// Exemplos:
// Eleva(2,5) retorna 32 ( 2^5 = 32 )
// Eleva(3,4) retorna 81 ( 3^4 = 81 )

#include <stdio.h>
#include <stdlib.h>

int eleva(int i, int b) {
    if (b == 1) {
        return (i);
    }
    return (i * eleva(i, b - 1));
}

void main() {
    int a;
    int b;

    printf("Digite o valor de a ");
    scanf("%i", &a);

    printf("Digite o valor de b ");
    scanf("%i", &b);

    printf("%i^%i = %i\n", a, b, eleva(a, b));
}
