// Exercício 10
// Faça uma função que receba como parâmetro um ponteiro
// que aponte para uma lista e retorne quantos números pares
// contém nela. Utilize o protótipo:
// int pares(lista *no);

#include <stdlib.h>
#include <stdio.h>

typedef struct no {
	int valor;
	struct no *prox;
}lista;

lista* add_lista(lista *l, int valor){
	lista *aux = (lista*) malloc(sizeof(lista));
	
	aux->valor = valor;
	aux->prox = l;
	
	return aux;
	
}

void print_lista(lista *no){
	lista* aux;
	for(aux = no; aux != NULL; aux=aux->prox){
		printf("valor %.2d, ponteiro %p\n", aux->valor, aux->prox);
	}
}

int pares(lista *no){
	int num_repetidos = 0;
	lista* aux = no;
	while(aux != NULL){
		if (aux->valor % 2 == 0){
			num_repetidos++;
		}
		aux = aux->prox;
	}
	return num_repetidos;
}

int main(){
	lista *l = NULL;
	int i = 0;
	int num_repetidos = 0;
	
	for(i = 0; i < 10; i++){
		l = add_lista(l, i);
	}
	print_lista(l);
	
	printf("numero de pares = %d", pares(l));

	return 0;
}
