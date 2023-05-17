// 05) Suponha a existência de um vetor de inteiros
// #define MAX 10;
// int Vet[MAX];
// a) escreva uma função recursiva para somar o n primeiros elementos de Vet
// int VetSoma(int A[],int n) (n é o tamanho do vetor)
// b) escreva uma função recursiva para encontrar o maior elemento de Vet
// int VetMaior(int A[],int n) ( n é o tamanho do vetor)
// c) escreva um procedimento recursivo para inverter Vet. Repare que as
// variáveis inic e fim são as posições inicial e final do vetor.
// void VetInv(int A[],int inic,int fim)

#include <stdio.h>
#include <stdlib.h>

int vet_soma(int a[], int n) {
    n -= 1;
    if (n == 0) {
        return a[n];
    }
    return (a[n] + vet_soma(a, n));
}

int vet_maior(int a[], int n) {
    int next;
    n -= 1;

    if (n == 0) {
        return a[n];
    } else {
        next = vet_maior(a, n);
        if (next < a[n]) {
            next = a[n];
        }
        return (next);
    }
}

void vet_inv(int a[], int inic, int fim) {
    int aux;

    if (inic < fim) {
        aux = a[fim];
        a[fim] = a[inic];
        a[inic] = aux;
        vet_inv(a, inic + 1, fim - 1);
    }
}

int main() {
    int n = 10;
    int i;
    int a[10] = {2, 20, 3, 40, 5, 100, 12, 0, 8, 1};

    printf("[");
    for (i = 0; i < n; i++) {
        printf("%d%s", a[i], (i == n - 1) ? "]\n" : ", ");
    }

    printf("\nvet_soma = %i\n", vet_soma(a, n));

    printf("vet_maior = %i\n", vet_maior(a, n));

    vet_inv(a, 0, n - 1);
    printf("vet_inv = [");
    for (i = 0; i < n; i++) {
        printf("%d%s", a[i], (i == n - 1) ? "]\n" : ", ");
    }
}
