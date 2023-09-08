#include <stdlib.h>
#include <stdio.h>

typedef struct p pilha;
typedef struct e elemento;
pilha* cria();
void push(pilha *p, float dado);
float pop(pilha *l);
int vazia (pilha *p);
void libera (pilha *p);

