// Exercício 23
// Demonstre a inserção das chaves (k) 5, 28, 19, 15, 20, 33, 12, 7 e 10
// numa tabela de hash implementada com vetor de lista com tratamento
// de colisões. Considere a tabela com 9 (m) posições e a função hash
// como sendo h(k) = k % m. Reconstrua a tabela para m = 11 e comente
// os resultados.

/* m = 9					m = 11
| 0 |				 | 		| 0 | 33 	| 			
| 1 | 28 -> 19 -> 10 | 		| 1 | 12	| 		
| 2 | 20			 | 		| 2 |		| 		
| 3 | 12			 | 		| 3 |		| 		
| 4 |				 | 		| 4 | 15	| 		
| 5 | 5				 | 		| 5 | 5		| 		
| 6 | 15 -> 33		 | 		| 6 | 28	| 		
| 7 | 7				 | 		| 7 | 7	    | 		
| 8 |				 | 		| 8 | 19	| 		 
							| 9 | 20	|
							| 10| 10	|
							
Podemos ver que com a tabela com m=11 não temos nenhuma colisão
*/
#include <stdio.h>
#include <stdlib.h>

#define TAM_MAX 11

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
	insere(&list, 28);
	insere(&list, 19);
	insere(&list, 15);
	insere(&list, 20);
	insere(&list, 33);
	insere(&list, 12);
	insere(&list, 7);
	insere(&list, 10);

	imprime(&list);

	libera(&list);
}
