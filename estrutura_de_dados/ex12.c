// Exercício 12
// Considere a existência de um tipo abstrato Pilha de números de ponto flutuante,
// cuja interface está definida no arquivo pilha.h da seguinte forma:
// typedef struct p pilha;
// pilha* cria();
// void push (pilha *p, float dado);
// float pop (pilha *p);
// int vazia (pilha *p);
// void libera (pilha *p);
// Sem conhecer a representação interna desse tipo abstrato Pilha e usando apenas
// as funções declaradas no arquivo pilha.h, implemente uma função que receba duas
// pilhas, p1 e p2, e passe todos os elementos da pilha p2 para o topo da pilha p1.
// Note que ao final dessa função, a pilha p2 vai estar vazia e a pilha p1 conterá
// todos os elementos das duas pilhas. Essa função deve obedecer o protótipo:
// void concatena_pilhas (pilha *p1, pilha *p2);

// p1		p2		->	p1
// 2.1		7.2			7.2
// 4.5		3.1			3.1
// 1.0		9.8			9.8
//						2.1
//						4.5
//						1.0


#include "pilhas.h"

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

void libera (pilha *l){
	while(vazia(l) == 0){
		pop(l);
	}
	free(l);
}

void push(pilha *p, float dado) {
	elemento *aux = (elemento*) malloc(sizeof(elemento));

	aux->valor = dado;
	aux->baixo = p->topo;

	p->topo = aux;
}

float pop(pilha *p){
	if(vazia(p) == 0) {
		elemento *aux = p->topo;
		float valor = aux->valor;

		p->topo = aux->baixo;
		free(aux);
		return valor;
	}
}

void print_pilha(pilha *p){
	if(p != NULL){
        elemento* aux;
		for(aux = p->topo; aux != NULL; aux=aux->baixo){
			printf("valor %.2f, ponteiro %p\n", aux->valor, aux->baixo);
		}
	}
}

void concatena_pilhas (pilha *p1, pilha *p2){
	pilha *aux = cria();
	float valor;

	while (vazia(p2) == 0){
		valor = pop(p2);
		push(aux, valor);
	}
	while (vazia(aux) == 0){
		valor = pop(aux);
		push(p1, valor);
	}
}

int main(){
	pilha *p1;
	pilha *p2;
	
	p1 = cria();
	p2 = cria();
	
    push(p1, 1.0);
    push(p1, 4.5);
    push(p1, 2.1);
	
    push(p2, 9.8);
    push(p2, 3.1);
    push(p2, 7.2);

    printf("Pilha p1\n");
    print_pilha(p1);

    printf("\nPilha p2\n");
    print_pilha(p2);

	concatena_pilhas(p1, p2);
	printf("\nPilha p1 concatenada\n");
    print_pilha(p1);

	libera(p1);
	libera(p2);
    return 0;
}
