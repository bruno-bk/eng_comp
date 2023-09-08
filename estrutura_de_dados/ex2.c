// Exercício 2
// Considere uma tabela de hash de tamanho m = 1000 e a função de hash
// usando o método da multiplicação com A = (√ 5 − 1)/2. Calcule os
// valores de hash das chaves 61, 62, 63, 64 e 65.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float calc_delta(float a, float b, float c){
    return pow(b,2)-(4*a*c);
}

int main(){
	float a;
	float b;
	float c;
    float delta;

	printf("ax²+bx+c=0\n");
	printf("Digite o valor de a = ");
	scanf("%f", &a);
	printf("Digite o valor de b = ");
	scanf("%f", &b);
	printf("Digite o valor de c = ");
	scanf("%f", &c);

    delta = calc_delta(a, b, c);
    printf("O valor do delta = %.2f\n", delta);
}