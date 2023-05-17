// 03) Elabore uma função recursiva para encontar os números do Triângulo de
// Pascal
// Triângulo de Pascal

// col 1 col 2 col 3 col 4 col 5 col 6 col 7

// 1
// 1 1
// 1 2  1
// 1 3  3  1
// 1 4  6  4 1
// 1 5 10 10 5 1
// : : : : : : : ...

// int Pascal(int lin , int col )
// Exemplos:
// Pascal(4,2) retorna 3 (linha 4 e coluna 2 )
// Pascal(6,4) retorna 10 (linha 6 e coluna 4)
// Pascal(9,1) retorna 1 (linha 9 e coluna 1)

#include <stdio.h>
#include <stdlib.h>

int pascal(int x, int y) {
    if (x == 1 || x == 2 || y == 1 || y == x) {
        return (1);
    }

    return (pascal(x - 1, y) + pascal(x - 1, y - 1));
}

int main() {
    int a;
    int b;

    printf("Digite o valor da linha ");
    scanf("%i", &a);
    printf("Digite o valor da coluna ");
    scanf("%i", &b);

    if (b <= a) {
        printf("linha %i, coluna %i = %i\n", a, b, pascal(a, b));
    } else {
        printf("O valor da coluna deve ser menor ou igual a linha!\n");
    }
}
