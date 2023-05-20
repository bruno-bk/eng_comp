// 3. Preparar um algoritmo que leia o valor de X e calcule o somatório a seguir
// para os 50 primeiros termos. S = X/1 + X/2 + X/3 + X/4 + ⋯

#include <stdio.h>
#include <stdlib.h>

int main() {
    int x;
    int i;
    float result = 0;

    printf("Digite o valor de x: ");
    scanf("%d", &x);

    for (i = 1; i <= 50; i++) {
        result += (float)x / i;
    }

    printf("A somatoria de x = %.1f\n", result);
}
