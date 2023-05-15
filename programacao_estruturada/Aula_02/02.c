// 2) Elabore um programa na linguagem C que colete a quantidade de alunos de
// uma sala e as suas respectivas notas, no final, informe a média da sala.

#include <stdio.h>
#include <stdlib.h>

void main() {
    int amount_sudents = 0;
    float point = 0;
    float average = 0;
    int i;

    printf("Digite a quantidade de alunos: ");
    scanf("%d", &amount_sudents);

    for (i = 0; i < amount_sudents; i++) {
        printf("Digite a nota do aluno%i: ", i + 1);
        scanf("%f", &point);
        average += point;
    }

    printf("\nA media da sala e igual %.2f\n", average / amount_sudents);
}
