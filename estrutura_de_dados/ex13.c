// Exercício 13
// Considere a existência de um tipo abstrato Pilha de números inteiros,
// cuja interface está definida no arquivo pilha.h da seguinte forma:
// typedef struct p pilha;
// pilha* cria();
// void push (pilha *p, int v);
// int pop (pilha *p);
// int vazia (pilha *p);
// void libera (pilha *p);
// Sem conhecer a representação interna desse tipo abstrato Pilha e
// usando apenas as funções declaradas no arquivo pilha.h, implemente
// uma função que receba uma pilha e retire todos os elementos impares
// dessa pilha.
// Essa função deve obedecer o protótipo: void retira_impares(pilha *p);
// p    ->	p
// 72   	72
// 31   	98
// 98   	10
// 21
// 45
// 10


#include "pilhas2.h"

typedef struct p{
	struct e *topo;
} pilha;

typedef struct e{
	int valor;
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

void libera (pilha *l){
	while(vazia(l) == 0){
		pop(l);
	}
	free(l);
}

void push(pilha *p, int dado) {
	elemento *aux = (elemento*) malloc(sizeof(elemento));

	aux->valor = dado;
	aux->baixo = p->topo;

	p->topo = aux;
}

int pop(pilha *p){
	if(vazia(p) == 0) {
		elemento *aux = p->topo;
		int valor = aux->valor;

		p->topo = aux->baixo;
		free(aux);
		return valor;
	}
}

void print_pilha(pilha *p){
	if(p != NULL){
        elemento* aux;
		for(aux = p->topo; aux != NULL; aux=aux->baixo){
			printf("valor %.2d, ponteiro %p\n", aux->valor, aux->baixo);
		}
	}
}

void retira_impares(pilha *p){
	pilha *aux = cria();
	int valor;

	while (vazia(p) == 0){
		valor = pop(p);
        if (valor%2 == 0){
            push(aux, valor);
        }
	}
	while (vazia(aux) == 0){
		push(p, pop(aux));
	}
	libera(aux);
}

int main(){
	pilha *p;
	
	p = cria();

    push(p, 10);
    push(p, 45);
    push(p, 21);
    push(p, 98);
    push(p, 31);
    push(p, 72);

    printf("Pilha p\n");
    print_pilha(p);

	retira_impares(p);
	printf("\nPilha p Pares\n");
    print_pilha(p);

	libera(p);
    return 0;
}
