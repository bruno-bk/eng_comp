// Exercício 14
// Considera o tipo abstrato Pilha de números inteiros do exercício
// anterior (exercício 2) e escreva uma função que informa a quantidade
// de negativos em uma pilha.
// Use o protótipo: int contanegativos(pilha *p)
// Obs.: Após na execução da função, a pilha deverá conter os mesmos
// elementos e ordem que havia antes da execução da função.


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

int contanegativos(pilha *p){
	pilha *aux = cria();
	int valor;
	int negativos = 0;

	while (vazia(p) == 0){
		valor = pop(p);
        push(aux, valor);
        if (valor < 0){
            negativos++;
        }
	}
	while (vazia(aux) == 0){
		valor = pop(aux);
		push(p, valor);
	}
	libera(aux);
    return negativos;
}

int main(){
	pilha *p;
    int negativos;
	
	p = cria();

    push(p, 10);
    push(p, -45);
    push(p, 21);
    push(p, -98);
    push(p, -31);
    push(p, 72);
	
    printf("Pilha p antes da contagem\n");
    print_pilha(p);

	negativos = contanegativos(p);

	printf("\nPilha p apos a contagem\n");
    print_pilha(p);
    
	printf("\nA pilha p contem %d elementos negativos\n", negativos);
    return 0;
}
