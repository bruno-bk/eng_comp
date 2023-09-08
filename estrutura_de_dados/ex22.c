// Exercício 22
// Considere uma tabela de hash de tamanho m = 1000 e a função de hash
// usando o método da multiplicação com A = (√ 5 − 1)/2. Calcule os
// valores de hash das chaves 61, 62, 63, 64 e 65.

// hash de 61 = 700
// hash de 62 = 318
// hash de 63 = 936
// hash de 64 = 554
// hash de 65 = 172

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TAM_MAX 1000

typedef struct Node {
    float info;
    struct Node* prox;
} Node;

int f_hash(int valor) {
    float val = valor * ((sqrt(5)-1)/2);
    return ((val-(int)val) * TAM_MAX);
}

int main() {
    printf("hash de 61 = %d\n", f_hash(61));
    printf("hash de 62 = %d\n", f_hash(62));
    printf("hash de 63 = %d\n", f_hash(63));
    printf("hash de 64 = %d\n", f_hash(64));
    printf("hash de 65 = %d\n", f_hash(65));
    
    return 0;
}