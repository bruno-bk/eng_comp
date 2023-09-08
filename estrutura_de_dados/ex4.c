// Exercício 4
// Escreva um programa que calcule o IMC de uma pessoa e imprima
// as mensagens de acordo com a referencia abaixo:

// •imc<18 "Voce esta abaixo do peso"
// •imc<=25 "Parabens. Voce esta sarado."
// •imc<=30 "Atencao. Voce esta acima do peso”
// •Imc>31 ”cuidado voce está obeso”

#include <stdlib.h>
#include <stdio.h>

int main(){
	int peso;
	float altura;
	float imc;

	printf("digite a altura: ");
	scanf("%f", &altura);
	
	printf("digite o peso: ");
	scanf("%i", &peso);
	
	imc = peso/(altura*altura);
	
	printf("imc %f\n", imc);
	if (imc < 18){
		printf("Voce esta abaixo do peso");
	} else if (imc <= 25) {
		printf("Parabens. Voce esta sarado");
	} else if (imc <= 30) {
		printf("Voce esta acima do peso");
	} else {
		printf("Voce esta obeso");
	}
	
	return 0;
}
