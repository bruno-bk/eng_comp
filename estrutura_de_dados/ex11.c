// Exercício 11
// Faça uma função que receba como parâmetro uma lista, 
// duplique-a e retorne a nova lista com os mesmos dados.
// Utilize o protótipo:
// lista* duplica_lista(lista *no)

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

lista* duplica_lista(lista *no) {
    lista* new_lista = NULL;

    if (no->prox != NULL) {
        new_lista = duplica_lista(no->prox); 
    }

    new_lista = add_lista(new_lista, no->valor);
	return new_lista;
}

int main(){
    lista *l = NULL;
    lista *p = NULL;
    int i = 0;
	
    for(i = 0; i < 10; i++){
        l = add_lista(l, i);
    }

    p = duplica_lista(l);

    printf("lista l\n");
    print_lista(l);

    printf("\nlista p (duplicada)\n");
    print_lista(p);

    return 0;
}
