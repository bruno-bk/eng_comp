// 02) Desenvolva uma função recursiva para efetuar a somatória de 1 até n ( 1 +
// 2 + 3 + ... + n - 1 + n )
// int Somat(int n)
// Exemplos:
// Somat(8) retorna 36 ( 1+2+3+4+5+6+7+8 = 36 )
// Somat(10) retornna 55 ( 1+2+3+4+5+6+7+8+9+10 = 55 )

#include <stdio.h>
#include <stdlib.h>

int soma(int i) {
    if (i == 1) {
        return (i);
    }
    return (i + soma(i - 1));
}

void main() {
    int a;
    int i;

    printf("Digite o valor de a ");
    scanf("%i", &a);

    for (i = 1; i <= a; i++) {
        printf("%d%s", i, (i == a) ? " = " : " + ");
    }
    printf("%i\n", soma(a));
}
