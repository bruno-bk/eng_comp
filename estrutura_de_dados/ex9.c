// Exercício 9
// Faça uma função recursiva que calcula a somatória de uma
// sequência de números naturais de 0 até N.

#include <stdio.h>
#include <stdlib.h>

int soma_recursiva(int numero) {
    int i;

    if (numero == 1){
        return 1;
    }

    return numero + soma_recursiva(numero - 1);
}

void main(){
    int n, result;

    printf("Digite o numero: "); 
    scanf("%d", &n);

    result = soma_recursiva(n);

    printf("A soma de 0 até %d = %d\n", n, result);

    return 0;
}
