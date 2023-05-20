// 1. Fazer um algoritmo que, dado um número real representando um valor em
// reais, converta e apresente o equivalente desse valor em dólar, sabendo que a
// cotação do dólar é de R$ 4,22.

#include <stdio.h>
#include <stdlib.h>

int main() {
    float real;

    printf("Digite o valor em real: ");
    scanf("%f", &real);

    printf("%.2f %s equivale a %.2f %s\n", real, real == 1 ? "real" : "reais",
           real * 4.22, real * 4.22 == 1 ? "dolar" : "dolares");
}
