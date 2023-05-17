// Escreva uma função que receba as seguintes informações: um valor real
// indicando capital inicial PV, um valor real que corresponde a taxa de juros
// da aplicação J e um número inteiro de períodos da aplicação N. A função deve
// retornar o capital futuro FV dado pela relação abaixo. Escreva um programa
// que teste esta função, sendo  FV = PV * ( 1 + J )^N

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

float future_capital(float PV, float J, int N) { return PV * pow((1 + J), N); }

int main() {
    float PV = 50;
    float J = 0.03;
    int N = 2;

    printf("Aplicando %.2f reais em %d peridos com taxa de juros %.2f = %.2f\n",
           PV, N, J, future_capital(PV, J, N));
}
