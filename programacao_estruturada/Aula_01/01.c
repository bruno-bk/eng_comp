// 1. Escreva um programa em linguagem C que leia um valor real correspondente a
// uma medida em metros, convertendo o valor dado em pés (1 metro = 3.315 pés),
// exibindo  os valores dado e convertido. Caso o usuário forneça um valor
// negativo, deve ser exibida uma mensagem e a operação de conversão não deve
// ser efetuada.

#include <stdio.h>
#include <stdlib.h>

void main() {
    float num;

    printf("Digite um numero = ");
    scanf("%f", &num);

    if (num < 0) {
        printf("Nao permitido numeros negativos.");
    } else {
        printf("%.2f metros = %.2f pes\n", num, num * 3.315);
    }
}
