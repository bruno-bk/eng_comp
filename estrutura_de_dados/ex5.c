// Exercício 5
// Faça um programa em C que leia um valor N, crie dinamicamente um vetor de N
// elementos, leia os N dados digitados pelo usuário e informe a soma dos valores.
// Além disso, antes de finalizar o programa, deve-se liberar a área de memória
// alocada.

#include <stdlib.h>
#include <stdio.h>

int main(){
	int i;
	int j;
	int soma = 0;

	printf("digite o tamanho do array: ");
	scanf("%i", &i);
	
	int *p = malloc(i * sizeof(int));
	
	for (j = 0; j < i; j++) {
		printf("digite o valor do elemento %i: ", j);
		scanf("%i", p + j * sizeof(int));
	}

	for (j = 0; j < i; j++) {
		soma = soma + *(p + j * sizeof(int));
	}
	
	printf("O valor da soma e: %d\n", soma);
	
	free(p);
	return 0;
}
