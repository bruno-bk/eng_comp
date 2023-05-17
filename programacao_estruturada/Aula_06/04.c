// 04) Desenvolva um algoritmo recursivo em linguagem C para a Função de
// Ackerman:
// definição da funcão de Ackerman:
// a(m.n) = 1 se m = 0
// a(m,n) = a(m-1,1) se m != 0 e n = 0
// a(m,n) = a(m-1,a(m,n-1)) se m != 0 e n != 0
// int Ackerman(int a , int b )

#include <stdio.h>
#include <stdlib.h>

int a(int m, int n) {
    if (m == 0) {
        return n + 1;
    } else if (n == 0) {
        return (a(m - 1, 1));
    } else {
        return (a(m - 1, a(m, n - 1)));
    }
}

int main() {
    int m;
    int n;

    printf("Digite o valor de m ");
    scanf("%i", &m);
    printf("Digite o valor de n ");
    scanf("%i", &n);

    printf("Ackerman(%i,%i) = %i\n", m, n, a(m, n));
}
