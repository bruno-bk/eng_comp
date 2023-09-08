#include <stdlib.h>
#include <stdio.h>

typedef struct f fila;
fila* cria(void);
void insere (fila* f, int dado);
int remove_f (fila* f);
int vazia (fila* f);
void libera (fila* f);

