// Exercício 18
// Considere a existência de um tipo abstrato Fila de números inteiros, cuja
// interface está definida no arquivo fila.h da seguinte forma:

// typedef struct f fila;
// fila* cria(void);
// void insere (fila* f, int dado);
// int remove_f (fila* f);
// int vazia (fila* f);
// void libera (fila* f);

// Implemente uma função que, dada uma fila, inverta a ordem
// de seus elementos. Por exemplo, se a fila originalmente tiver seus
// elementos na ordem 4,3,9,2, após a chamada da sua função a fila deve
// ter seus elementos na ordem 2,9,3,4. O protótipo da função deve ser:
// void inverte (fila* f).

#include "fila.h"

typedef struct n {
    int info;
    struct n *prox;
} no;

typedef struct f {
    no *inicio;
    no *fim;
} fila;

fila *cria() {
    fila *f = (fila *)malloc(sizeof(fila));
    f->inicio = NULL;
    f->fim = NULL;
    return f;
}

void insere(fila *f, int dado) {
    no *novo = (no *)malloc(sizeof(no));
    novo->info = dado;
    novo->prox = NULL;
    if (f->fim != NULL) {
        f->fim->prox = novo;
    }
    f->fim = novo;
    if (f->inicio == NULL) {
        f->inicio = f->fim;
    }
}

int vazia(fila *p) {
    if (p->inicio == NULL) {
        return 1;
    }
    return 0;
}

int remove_f(fila *f) {
    if (vazia(f) == 0) {
        int temp;
        temp = f->inicio->info;
        no *aux = f->inicio->prox;
        free(f->inicio);
        f->inicio = aux;
        if (f->inicio == NULL) {
            f->fim = NULL;
        }
        return temp;
    }
    printf("fila vazia.\n");
    exit(1);
}

void libera(fila *l) {
    while (vazia(l) == 0) {
        remove_f(l);
    }
    free(l);
}

void imprime(fila *p) {
    if (p != NULL) {
        no *aux;
        for (aux = p->inicio; aux != NULL; aux = aux->prox) {
            printf("valor %3.d, ponteiro %p\n", aux->info, aux);
        }
    } else {
        printf("a fila nao existe!");
    }
}

void inverte_recursiva(fila *f, fila *temp) {
    if (vazia(f)) {
        return;
    }
    int aux = remove_f(f);
    inverte_recursiva(f, temp);
    insere(temp, aux);
}

void inverte(fila *f) {
    fila *aux;
    aux = cria();

    inverte_recursiva(f, aux);

    while (vazia(aux) == 0) {
        insere(f, remove_f(aux));
    }

    libera(aux);
}

int main() {
    fila *f1;

    f1 = cria();

    insere(f1, 21);
    insere(f1, 72);
    insere(f1, 45);
    insere(f1, 31);
    insere(f1, 10);
    insere(f1, 98);

    printf("Fila f1\n");
    imprime(f1);

    inverte(f1);

    printf("\nFila f1 inversa\n");
    imprime(f1);

    libera(f1);
    return 0;
}
