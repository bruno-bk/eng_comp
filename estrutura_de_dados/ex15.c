// Exercício 15
// adicione as funções: imprimir, criar e liberar uma pilha.

#include <stdio.h>
#include <stdlib.h>

typedef struct p{
	struct e *topo;
} pilha;

typedef struct e{
	float valor;
	struct e *baixo;
} elemento;

pilha* cria(){
	pilha *novo = (pilha*) malloc(sizeof(pilha));
	novo->topo = NULL;

	return novo;
}

int vazia (pilha *p){
	if(p->topo == NULL){
		return 1;
	}
	return 0;
}

void push(pilha *p, float dado) {
	elemento *aux = (elemento*) malloc(sizeof(elemento));

	aux->valor = dado;
	aux->baixo = p->topo;

	p->topo = aux;
}

float pop(pilha *p){
	if (vazia(p) == 0){
		elemento *aux = p->topo;
		float valor = aux->valor;

		p->topo = aux->baixo;
		free(aux);
		return valor;	
	}
	return 0;	
}

void libera (pilha *l){
	while(vazia(l) == 0){
		pop(l);
	}
	free(l);
}

void imprime(pilha *p){
	if(p != NULL){
        elemento* aux;
		for(aux = p->topo; aux != NULL; aux=aux->baixo){
			printf("valor %.2f, ponteiro %p\n", aux->valor, aux->baixo);
		}
	}
}

int main(){
	pilha *p1;

	p1 = cria();

    push(p1, 1.0);
    push(p1, 4.5);
    push(p1, 2.1);

    printf("Pilha p1\n");
    imprime(p1);
	libera(p1);
    return 0;
}
