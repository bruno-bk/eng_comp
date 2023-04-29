// 5. Uma pesquisa sobre o sabor de um novo refrigerante foi feita com várias
// pessoas. As mesmas preenchiam uma tabela com 'O' de ótimo, 'B' de bom, 'R' de
// regular e 'U' de ruim. Faça um programa que leias as respostas coletadas pela
// pesquisa (as letras 'O', 'B', 'R' e 'U') sendo que o fim das respostas será
// indicado por um traço '-'. Outras letras devem ser desconsideradas. O
// programa deve também:     - indicar a quantidade de cada resposta,
//      - indicar o total de respostas,
//      - calcular a porcentagem de cada uma das respostas, e
//      - indicar se a soma de respostas 'O' e 'B' é maior ou não que a soma de
//      respostas 'R' e 'U'.

#include <stdio.h>
#include <stdlib.h>

int main() {
    int amount_O = 0;
    int amount_B = 0;
    int amount_R = 0;
    int amount_U = 0;
    int amount_responses = 0;
    char response = ' ';

    printf("Respostas possiveis:\n");
    printf("O - otimo\n");
    printf("B - bom\n");
    printf("R - regular\n");
    printf("U - ruim\n");

    while (response != '-') {
        printf("letra = ");
        scanf(" %c", &response);
        getchar();
        if (response == 'O' || response == 'o') {
            amount_O++;
            amount_responses++;
        } else if (response == 'B' || response == 'b') {
            amount_B++;
            amount_responses++;
        } else if (response == 'R' || response == 'r') {
            amount_R++;
            amount_responses++;
        } else if (response == 'U' || response == 'u') {
            amount_U++;
            amount_responses++;
        }
    }

    printf("\n%i respostas contabilizados\n", amount_responses);
    printf("O = %i respostas - %.2f%% das respostas\n", amount_O,
           (float)amount_O / amount_responses * 100);
    printf("B = %i respostas - %.2f%% das respostas\n", amount_B,
           (float)amount_B / amount_responses * 100);
    printf("R = %i respostas - %.2f%% das respostas\n", amount_R,
           (float)amount_R / amount_responses * 100);
    printf("U = %i respostas - %.2f%% das respostas\n", amount_U,
           (float)amount_U / amount_responses * 100);

    if ((amount_O + amount_B) > (amount_R + amount_U)) {
        printf("A soma das respostas O e B é maior que R e U\n");
    } else {
        printf("A soma das respostas O e B não é maior que R e U\n");
    }
}
