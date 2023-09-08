// Exercício 20
// Faça uma função que receba como
// parâmetro uma árvore conforme a estrutura abaixo e retorno quantos nós há nessa
// árvore.

// typedef struct tree {
//   int info;
//   struct tree *esq;
//   struct tree *dir;
// }arv;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tree {
	int info;
	struct tree *esq;
	struct tree *dir;
}arv;

arv* cria(){
	return NULL;
}

arv* insere (arv* f, int dado){
	if (f == NULL) {
		f = (arv*) malloc(sizeof(arv));	
		f->info = dado;
		f->dir = NULL;
		f->esq = NULL;
	} else if (dado < f->info) {
		f->esq = insere(f->esq, dado);
	} else {
		f->dir = insere(f->dir, dado);
	}

	return f;
}

arv* libera (arv* a){
	if (a != NULL){
		libera(a->esq);
		libera(a->dir);
		free(a);
	}
	return NULL;
}

void imprime_tree(arv *node, int isLeft, int isRoot, const char *prefix) {
  	if (node == NULL){
		return;
  	}

  	if (isRoot == 1) {
    	printf("-----");
  	} else {
		printf("%s%s", prefix, (isLeft==1 ? "L|---" : "R|---"));
  	}
  	printf("%.2d\n", node->info);

	char new_prefix[strlen(prefix)+6];
	strcpy(new_prefix, prefix);
	strcat(new_prefix, (isLeft==1 ? " |   " : "     "));
  	imprime_tree(node->esq, 1, 0, new_prefix);
  	imprime_tree(node->dir, 0, 0, new_prefix);
}

void imprime(arv* node){
	if (node != NULL){
		printf("%p | valor %d | dir %p esq %p\n",node, node->info, node->dir, node->esq);
		imprime(node->dir);
		imprime(node->esq);
	}
}

int cont_nodes(arv* p){
	if(p != NULL){
		return (cont_nodes(p->dir) + cont_nodes(p->esq) + 1);
	}
	return 0;
}

int main(){	
	arv *f;

	f = cria();

    f = insere(f, 10);
    f = insere(f, 20);
    f = insere(f, 5);
    f = insere(f, 21);
    f = insere(f, 7);
    f = insere(f, 2);
    f = insere(f, 19);
    f = insere(f, 18);
    f = insere(f, 25);
    f = insere(f, 40);
    f = insere(f, 39);
    f = insere(f, 41);

    printf("Arvore f\n");
	imprime_tree(f, 0, 1, "");

	printf("A arvore possui %d nos\n", cont_nodes(f));

	libera(f);
    return 0;
}
