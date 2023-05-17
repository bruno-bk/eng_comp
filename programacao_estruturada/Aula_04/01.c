// 1. Implementar um programa para corrigir provas de múltipla escolha. Cada
// prova possui 10 questões, cada uma com 4 alternativas (apenas uma correta). O
// primeiro conjunto de dados a ser lido (respostas corretas) será o gabarito
// para a correção da prova. Os demais conjuntos lidos (respostas de cada aluno)
// devem ser previamente identificados pelo RA do aluno. Se é fornecido um RA de
// valor zero ou negativo, sabemos que não existem mais alunos. Finalizada a
// entrada de dados dos alunos o programa deverá exibir: o número e nota de cada
// aluno; a porcentagem de aprovação, sabendo-se que a nota mínima de aprovação
// é 5.0; a média da classe; a quantidade e os RAs dos alunos que obtiveram a
// maior nota (considerando empates); e a quantidade e os RAs dos alunos que
// obtiveram a menor nota (considerando empates); e Se um mesmo RA for dado 2 ou
// mais vezes, o programa substituirá os resultados deste aluno.

#include <stdio.h>
#include <stdlib.h>

void test_result_input(char questions[], int questions_amount) {
    int i;
    for (i = 0; i < questions_amount; i++) {
        printf("Questao %i: ", i + 1);
        scanf("%c", &questions[i]);
        getchar();
    }
}

int identify_student_index(int ra, int students_ra[], int students_amount) {
    int i;
    for (i = 1; i <= students_amount; i++) {
        if (students_ra[i] == ra) {
            return i;
        }
    }
    return i;
}

void main() {
    int questions_amount = 10;
    int students_amount = 0;
    int read_student = 1;
    int student_ra[1000];
    char test_template[1000][questions_amount];

    printf("Gabarito\n");
    student_ra[0] = 0; // gabarito
    test_result_input(test_template[0], questions_amount);

    while (read_student) {
        int ra;
        printf("Ra do aluno: ");
        scanf("%i", &ra);
        getchar();

        if (ra > 0) {
            int student_index =
                identify_student_index(ra, student_ra, students_amount);
            printf("Aluno %i\n", student_index);
            if (student_index > students_amount) {
                student_ra[student_index] = ra;
                students_amount++;
            }
            test_result_input(test_template[student_index], questions_amount);
        } else {
            read_student = 0;
        }
    }

    int approved = 0;
    int points[1000];
    float avarage = 0;
    int lowest_point;
    int amount_lowest_point = 0;
    int highest_point;
    int amount_highest_point = 0;
    int i;
    int j;
    printf("\n\nResultados:\n");
    for (i = 1; i <= students_amount; i++) {
        printf("\tRa: %i - ", student_ra[i]);
        points[i] = 0;
        for (j = 0; j < questions_amount; j++) {
            if (test_template[i][j] == test_template[0][j]) {
                points[i]++;
            }
        }
        printf("Nota: %i\n", points[i]);
        avarage += points[i];
        if (points[i] >= 5) {
            approved++;
        }

        if (i == 1) {
            lowest_point = points[i];
            highest_point = points[i];
            amount_lowest_point = 1;
            amount_highest_point = 1;
        } else {
            if (points[i] < lowest_point) {
                lowest_point = points[i];
                amount_lowest_point = 1;
            } else if (points[i] == lowest_point) {
                amount_lowest_point++;
            }

            if (points[i] > highest_point) {
                highest_point = points[i];
                amount_highest_point = 1;
            } else if (points[i] == highest_point) {
                amount_highest_point++;
            }
        }
    }

    printf("%.1f%% dos alunos aprovados.\n",
           (float)approved / students_amount * 100);
    printf("A clase teve uma media de %.1f pontos.\n",
           (float)avarage / students_amount);

    printf("%i %s com a maior nota:\n", amount_highest_point,
           (amount_highest_point <= 1) ? "aluno" : "alunos");
    for (i = 1; i <= students_amount; i++) {
        if (highest_point == points[i]) {
            printf("\tRa: %i\n", student_ra[i]);
        }
    }

    printf("%i %s com a menor nota:\n", amount_lowest_point,
           (amount_lowest_point <= 1) ? "aluno" : "alunos");
    for (i = 1; i <= students_amount; i++) {
        if (lowest_point == points[i]) {
            printf("\tRa: %i\n", student_ra[i]);
        }
    }
}
