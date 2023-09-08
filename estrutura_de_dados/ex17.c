// Exercício 17
// Separe todos os valores guardados em f de tal forma que os
// valores pares são movidos para a fila f_pares e os valores ímpares para
// f_impares Considere a existência de um tipo abstrato Fila de números
// inteiros, cuja interface está definida no arquivo fila.h da seguinte forma:

// typedef struct f fila;

// fila* cria(void);
// void insere (fila* f, int dado);
// int remove_f (fila* f);
// int vazia (fila* f);
// void libera (fila* f);

// Sem conhecer a representação interna desse tipo abstrato Fila e usando apenas
// as funções declaradas, implemente uma função que receba três filas, f,
// f_impares e f_pares, e separe todos os valores guardados em f de tal forma
// que os valores pares são movidos para a fila f_pares e os valores ímpares
// para f_impares.

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

void separa_filas(fila *f, fila *f_pares, fila *f_impares) {
    int temp;
    while (vazia(f) == 0) {
        temp = remove_f(f);
        if (temp % 2 == 0) {
            insere(f_pares, temp);
        } else {
            insere(f_impares, temp);
        }
    }
}

int main() {
    fila *f1;
    fila *f_pares;
    fila *f_impares;

    f1 = cria();
    f_pares = cria();
    f_impares = cria();

    insere(f1, 21);
    insere(f1, 72);
    insere(f1, 45);
    insere(f1, 31);
    insere(f1, 10);
    insere(f1, 98);

    printf("Fila f1\n");
    imprime(f1);

    separa_filas(f1, f_pares, f_impares);

    printf("\nFila f1\n");
    imprime(f1);
    printf("\nFila f_pares\n");
    imprime(f_pares);
    printf("\nFila f_impares\n");
    imprime(f_impares);

    libera(f1);
    libera(f_pares);
    libera(f_impares);
    return 0;
}
