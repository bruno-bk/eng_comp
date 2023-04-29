// 4. Em um frigorífico são recebidos um número variável de bois a cada dia.
// Cada boi traz preso no seu pescoço um cartão contendo um número de
// identificação e seu peso. Implementar um programa que efetue a leitura de
// todos números de identificação e peso de cada boi, exibindo ao final o número
// e o peso dos bois mais gordo e mais magro, bem como o peso médio dos bois. Um
// número de identificação 0 (zero) indica o final da leitura. Note que não é
// necessário armazenar os dados de todos os bois.

#include <stdio.h>
#include <stdlib.h>

int main() {
    float less_weight = 0;
    int less_weight_code = 0;
    float larger_weight = 0;
    int larger_weight_code = 0;
    float average_weight = 0;
    int amount = 0;

    float weight = 0;
    int code = 1;

    while (code != 0) {
        printf("Digite o codigo = ");
        scanf("%i", &code);
        if (code != 0) {
            printf("Digite o peso = ");
            scanf("%f", &weight);
            if (weight < less_weight || less_weight == 0) {
                less_weight = weight;
                less_weight_code = code;
            }
            if (weight > larger_weight || larger_weight == 0) {
                larger_weight = weight;
                larger_weight_code = code;
            }

            amount++;
            average_weight = average_weight + weight;
        }
    }

    printf("\nO boi mais gordo com o codigo %i e peso %.2fkg\n",
           larger_weight_code, larger_weight);
    printf("O boi mais magro com o codigo %i e peso %.2fkg\n", less_weight_code,
           less_weight);
    printf("O peso medio do dia foi %.2fkg\n", average_weight / amount);
}
