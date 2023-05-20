// 4. Repita o exercício 3 de forma que a solução seja através de uma função
// recursiva.

#include <stdio.h>
#include <stdlib.h>

float sum(int x, int i) {
    if (i == 50) {
        return (float)x / 50;
    } else {
        int value = x / i;
        return ((float)x / i + sum(x, i + 1));
    }
}

int main() {
    int x;
    int i;
    float result = 0;

    printf("Digite o valor de x: ");
    scanf("%d", &x);

    printf("A somatoria de x = %.1f\n", sum(x, 1));
}
