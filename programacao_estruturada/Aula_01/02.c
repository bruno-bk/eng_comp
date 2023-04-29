// 2. Faça um algoritmo que, lendo 3 números correspondentes aos coeficientes a,
// b, e c de uma equação do 2º grau, calcule seu DELTA e também as raízes desta
// equação, imprimindo seus valores.

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    float a;
    float b;
    float c;
    float delta;

    printf("ax²+bx+c=0\n");
    printf("Digite o valor de a = ");
    scanf("%f", &a);
    printf("Digite o valor de b = ");
    scanf("%f", &b);
    printf("Digite o valor de c = ");
    scanf("%f", &c);

    delta = (pow(b, 2) - (4 * a * c));
    printf("O valor do delta = %.2f\n", delta);

    if (delta < 0) {
        printf("A equação não possui raizes reais\n");
    } else if (delta == 0) {
        printf("X = %.2f\n", (-b + sqrt(delta)) / (2 * a));
    } else {
        printf("X1 = %.2f\n", (-b + sqrt(delta)) / (2 * a));
        printf("X2 = %.2f\n", (-b - sqrt(delta)) / (2 * a));
    }
}
