// 3. Escreva um programa que calcule o valor de y = f(x) = a*x + b num
// intervalo de valores de x,  sendo dados pelo usuário os coeficientes a e b,
// bem como os valores do limite inferior e superior do intervalo de x bem como
// o valor do increment de x. O programa deve exibir resultados como um tabela
// onde constam os valores de x e y=f(x) lado a lado.

#include <stdio.h>
#include <stdlib.h>

int main() {
    float a;
    float b;
    float y;
    int min;
    int max;
    int step;
    int x;

    printf("y = a*x + b\n");
    printf("Digite o valor de a = ");
    scanf("%f", &a);
    printf("Digite o valor de b = ");
    scanf("%f", &b);

    printf("Digite o limite inferior = ");
    scanf("%i", &min);
    printf("Digite o limite superior = ");
    scanf("%i", &max);
    printf("Digite o valor de incremento = ");
    scanf("%i", &step);

    for (x = min; x < max; x = x + step) {
        y = a * x + b;
        printf("x = %i | y = %.2f\n", x, y);
    }
}
