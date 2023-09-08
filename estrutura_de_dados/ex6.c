// Exercício 6
// Defina o tipo registro ponto com dois campos x e y (reais). Os campos representam as
// coordenadas desse ponto no sistema cartesiano. Escreva uma fun��o que, dados
// dois pontos, calcule a dist�ncia entre eles. As coordenadas dos pontos devem
// ser lidas no programa principal e passadas a` fun��o por meio de par�metros do
// tipo ponto. O resultado da fun��o deve ser informado pelo programa principal.

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct ponto {
	int x;
	int y;
};

float calc_distancia(struct ponto ponto1, struct ponto ponto2){
	float aux = pow(ponto1.x-ponto2.x, 2) + pow(ponto1.y-ponto2.y, 2);
	
	return sqrt(aux);
};

int main(){
	struct ponto ponto1;
	struct ponto ponto2;
	float result = 0;

	printf("digite o tamanho do x do ponto1: ");
	scanf("%i", &ponto1.x);
	
	printf("digite o tamanho do y do ponto1: ");
	scanf("%i", &ponto1.y);
	
	printf("digite o tamanho do x do ponto2: ");
	scanf("%i", &ponto2.x);
	
	printf("digite o tamanho do y do ponto2: ");
	scanf("%i", &ponto2.y);

	
	result = calc_distancia(ponto1, ponto2);	
	printf("O resultado e %.2f\n", result);
	
	return 0;
}
