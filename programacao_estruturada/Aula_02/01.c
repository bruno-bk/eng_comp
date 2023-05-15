// 1) Elabore um programa na linguagem C que informe as raízes de uma equação de
// 2º grau. Considere as seguintes situações: < 0  -> Nenhuma Raiz = 0  -> Uma
// Raiz > 0  -> Duas Raiz

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void main() {
    float a = 0;
    float b = 0;
    float c = 0;
    float delta;
    float x1;
    float x2;

    printf("Ax^2+Bx+C\n");
    printf("Digite o valor de A:");
    scanf("%f", &a);
    printf("Digite o valor de B:");
    scanf("%f", &b);
    printf("Digite o valor de C:");
    scanf("%f", &c);

    delta = pow(b, 2) - (4 * a * c);

    printf("\nDelta = %.2f\n", delta);

    if (delta < 0) {
        printf("A equacao %.1fx^2 + %.1fx + %.1f nao possui raises reais", a, b,
               c);
    } else if (delta == 0) {
        x1 = (-b + sqrt(delta)) / (2 * a);
        printf("A equacao possui uma raiz com valor %.2f", x1);
    } else {
        x1 = (-b + sqrt(delta)) / (2 * a);
        x2 = (-b - sqrt(delta)) / (2 * a);
        printf("A equacao possui duas raizes com valores %.2f e %.2f", x1, x2);
    }
}
