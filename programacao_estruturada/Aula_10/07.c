// 8) Desenvolva um programa que leia o RA, nome, nota 1 e nota 2 de um aluno e
// imprima: Uma lista com o RA, nome, a média e a situação final de cada aluno
// (>= 5 aprovado) A média final da turma OBS: Não se sabe no início quantos
// alunos serão digitados, necessário solicitar o total ao usuário.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int amount_students = 0;
    float grade = 0;
    char RA[100][20];
    char name[100][20];
    float grade1[100];
    float grade2[100];
    int i;

    printf("Toral de alunos: ");
    scanf("%d", &amount_students);

    for (i = 0; i < amount_students; i++) {
        getchar();
        printf("\nAluno %d\n", i + 1);
        printf("RA: ");
        gets(RA[i]);
        printf("Nome: ");
        gets(name[i]);
        printf("Nota1: ");
        scanf("%f", &grade1[i]);
        printf("Nota2: ");
        scanf("%f", &grade2[i]);
    }

    printf("\nRA\tNome\tMedia\tResultado\n");
    for (i = 0; i < amount_students; i++) {
        printf("%s\t%s\t%.2f\t", RA[i], name[i], (grade1[i] + grade2[i]) / 2);
        if ((grade1[i] + grade2[i]) / 2 >= 5) {
            printf("Aprovado\n");
        } else {
            printf("Reprovado\n");
        }
        grade += (grade1[i] + grade2[i]) / 2;
    }

    printf("Media da turma: %.2f\n", grade / amount_students);
}
