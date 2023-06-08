// 1. Escreva um programa em linguagem C que verifique se um 
// número está com o digito verificador correto, ou calcule
// o digito verificador para um determindo numero.
// A regra de verificação deve ser criada.

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define DIGITOS 8

int obter_casa_decimal(const double valor, int i) {
    int base = pow(10, (i + 1));
    return (int)(valor * base) % 10;
}

int calcula_digito_verificador(long codigo) {
    int codigo_array[DIGITOS];
    int digito1 = 0;
    int digito2 = 0;
    int soma;
    const double sqrt_2 = 1.4142135623730950488016887242097;

    for (int i = (DIGITOS - 1); i >= 0; i--) {
        codigo_array[i] = codigo % 10;
        codigo /= 10;
    }

    for (int i = 0; i < DIGITOS; i++) {
        digito1 += (codigo_array[i]) * obter_casa_decimal(sqrt_2, i);
        digito2 += ((codigo_array[i] + 3) * sqrt_2);
    }

    soma = (digito1 % 101) * (digito2 % 101);

    return soma % 97;
}

int menu() {
    int escolha;
    while (1) {
        printf("1 - Calcular o numero verificador.\n");
        printf("2 - Verificar um numero de inscricao.\n");
        printf("0 - Sair.\n");
        printf("Escolha uma das opcoes acima: ");
        scanf("%d", &escolha);
        printf("\n");

        if (escolha >= 0 && escolha <= 2) {
            return escolha;
        } else {
            printf("Opcao invalida\n\n");
        }
    }
}

int main() {
    double n;

    while (1) {
        int opcao = menu();

        if (opcao == 1) {
            printf("Digite um numero de 8 digitos (ex: 12345678): ");
            scanf("%lf", &n);

            if (n >= 0 && n < 100000000) {
                printf("Para o numero %.0f, o digito verificador e %d.\n\n", n, calcula_digito_verificador((long)n));
            } else {
                printf("numero invalido, tente novamente.\n\n");
            }

        } else if (opcao == 2) {
            printf("Digite um numero de 10 digitos (ex: 1234567890): ");
            scanf("%lf", &n);

            if (n >= 0 && n < 10000000000) {
                long cod = ((long)n) / 100;
                long dig = ((long)n) % 100;

                printf("O numero %.0f ", n);
                if (dig == calcula_digito_verificador(cod)) {
                    printf("e valido!\n\n");
                } else {
                    printf("e invalido!\n\n");
                }

            } else {
                printf("numero invalido, tente novamente.\n\n");
            }

        } else {
            break;
        }
    }
    return 0;
}
