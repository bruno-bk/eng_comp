// Exercício 8
// Faça uma função que calcula o fatorial de um número natural e 
// depois transforme essa função em uma função recursiva. 

#include <stdio.h>
#include <stdlib.h>

int calc_fatorial_rec(int numero) {
    int i;

    if (numero == 1){
        return 1;
    }

    return numero * calc_fatorial_rec(numero - 1);
}

int calc_fatorial(int numero) {
    int i;
    int fatorial = 1;

    for(i = numero; i > 0; i--) {
        fatorial *= i;
    }

    return fatorial;
}


void main(){
    int n, fatorial;
  
    printf("Digite o numero: "); 
    scanf("%d", &n);
  
    fatorial = calc_fatorial_rec(n);
  
    printf("Fatorial de %d: %d\n", n, fatorial);

    return 0;
}