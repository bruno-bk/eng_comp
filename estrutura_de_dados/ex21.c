// Exercício 21
// Escreva o código para gerenciar uma tabela de hash com números de ponto flutuante.

#include <stdio.h>
#include <stdlib.h>

#define TAM_MAX 7

typedef struct n {
	float info;
	struct n *prox;
} no;

int f_hash(float valor) {
	return abs(valor) % TAM_MAX;
}

void inicializa(no **hash) {
	int i;
	for(i=0; i<TAM_MAX; i++) {
		hash[i] = NULL;
    }
}

void insere(no **hash, float valor) {
	int pos = f_hash(valor);
	no* novo = (no *) malloc(sizeof(no));

	if (novo==NULL) {
		printf("Erro!\n");
		exit(1);
	}

	novo->info=valor;
	novo->prox=NULL;
	no **lista = &hash[pos];
	if (*lista == NULL) {
		*lista = novo;
		printf("Inserido HASH[%d]\n",pos);
	
	}else {
		printf("Inserido com Colisao HASH[%d]\n",pos);
		no *temp= hash[pos];

		if(temp->info==valor){
			printf("Valor %.2f ja inserido\n",valor);
		}
		
		while (temp->prox != NULL){
			if(temp->info==valor)
			printf("Valor %.2f ja inserido\n",valor);
			temp=temp->prox;
		}
		temp->prox=novo;
	}
}

void apaga(no **hash, float valor) {
	int pos = f_hash(valor);
	no **lista = &hash[pos];
	no* ant = NULL;
	no* aux = *lista;

	while (aux != NULL && aux->info != valor) {
		ant = aux;
		aux = aux->prox;
	}
	
	if (aux == NULL){
		printf("Valor nao encontrado!\n");
		return;
	}
	
	if (ant == NULL) {
		hash[pos] = aux->prox;
	
	} else {
		ant->prox = aux->prox;	
	}
	free(aux);
}

no* busca(no **hash, float valor) {

	int pos = f_hash(valor);
	no *lista = hash[pos];

	while (lista != NULL) {
		if (valor == lista->info) return lista;
		lista = lista->prox;
	}
	return NULL;
}

void imprime(no **hash) {
	printf("\nTabela Hash\n");
	int i;
	for (i=0; i<TAM_MAX; i++) {
		printf("%p %p HASH[%d]\t",&hash[i], hash[i] , i);
		no *lista = hash[i];

		while (lista != NULL) {
			printf(" -> %.2f",lista->info);
			lista = lista->prox;
		}
		printf("\n");
	}
}

void libera(no **hash) {
	int i;
	no *aux;
	for(i=0; i < TAM_MAX; i++) {
		no **lista = &hash[i];

		while(*lista!= NULL) {
			aux = (*lista)->prox;
			free(*lista);
			*lista = aux;
		}
	}
}

int main() {
	no *list;

	inicializa(&list);

	insere(&list, 5);
	insere(&list, 3);
	insere(&list, 1);
	insere(&list, 7);
	insere(&list, 8);
	insere(&list, 6);
	insere(&list, 2);

	imprime(&list);

	libera(&list);
	
	return 0;
}
