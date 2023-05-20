// Visando se preparar para a Black Friday, uma loja de material esportivo
// montou a seguinte estratégia de descontos, de acordo com a faixa de preço
// atual dos produtos:

// |Preço atual                 | Desconto  |
// |>= 0 e < R$ 50,00           | 30%       |
// |>= R$ 50,00 e < R$ 200,00   | 20%       |
// |>= R$ 200 e < R$ 500,00     | 10%       |
// |>= R$ 500,00                | 5%        |

// Preparar um algoritmo para ler o código e o valor atual do produto e mostrar
// o código e o valor reajustado.

#include <stdio.h>
#include <stdlib.h>

int main() {
    int cod;
    float price;

    printf("Digite o codigo do produto: ");
    scanf("%d", &cod);

    printf("Digite o valor do produto: ");
    scanf("%f", &price);

    if (price >= 0 && price < 50) {
        price = price * 0.70;
    } else if (price >= 50 && price < 200) {
        price = price * 0.80;
    } else if (price >= 200 && price < 500) {
        price = price * 0.90;
    } else if (price >= 500) {
        price = price * 0.95;
    }

    printf("O produto %d valor atualizado %.2f\n", cod, price);
}
