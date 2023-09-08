// Exercício 16
// Criar uma Pilha usando o material anexo como referência, sendo que esta pilha será
// alocada estáticamente, contendo no máximo 7 elementos. 
// Siga a orientação do TAD a seguir :
// #define MAX 7
// typedef struct p{
//  int n; //quantidade de elementos
//  float vet[MAX];
// }pilhavet;
// Esta pilha deve respeitar a checagem que informa que uma pilha está cheia através do protótipo abaixo. 
// int cheia(pilhavet p); // verifica se a pilha está cheia

#include <stdio.h>
#include <stdlib.h>

#define MAX 7

typedef struct pi{
	int n;
	float vet[MAX];
}pilha;

int cheia(pilha p) {
	if (p.n < MAX) {
		return 0;
	}
	return 1;
}

void push(pilha *p, float valor) {
	if(cheia(*p) == 0){
		p->vet[p->n] = valor;
		(p->n)++;	
	} else {
		printf("valor %.2f nao adicionado, lista cheia.\n", valor);
	}
}

float pop(pilha *p){
	if(p->n > 0){
		(p->n)--;
	}
	return p->vet[p->n];
}

void print_lista(pilha *p){
	int i;
	for(i=p->n; i>0;i--){
		printf("%d - %.2f\n", i-1, p->vet[i-1]);
	}
}

int main() {
	pilha p;
	p.n = 0;
	
	push(&p, 1.1);
	push(&p, 2.2);
	push(&p, 3.3);
	push(&p, 4.4);
	push(&p, 5.5);
	push(&p, 6.6);
	push(&p, 7.7);
	push(&p, 8.8);
	
	printf("Pilha p\n");
	print_lista(&p);
	
	printf("\npop %.2f\n", pop(&p));

	printf("\nPilha p\n");
	print_lista(&p);
}
