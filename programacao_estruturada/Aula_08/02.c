// Faça um programa que leia as notas das duas provas de programação de uma
// classe, armazenando cada conjunto em um arranjo distinto. Depois deve ser
// calculada a média aritmética de cada aluno sendo tais resultados armazenados
// em um terceiro arranjo. O programa também deve calcular a média da classe em
// cada prova. Use preferencialmente funções para realizar estas tarefas.

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define STUDENTS 3

void read_note(float notes[], int amount_note) {
    int i;

    for (i = 0; i < amount_note; i++) {
        printf("Digite a nota do aluno %d: ", i + 1);
        scanf("%f", &notes[i]);
    }
    printf("\n");
}

float calculate_average(float notes[], int amount_note) {
    float average = 0;
    int i;

    for (i = 0; i < amount_note; i++) {
        average += notes[i];
    }

    return average / amount_note;
}

int main() {
    int i = 0;

    float note_1[STUDENTS];
    float note_2[STUDENTS];
    float note_f[STUDENTS];

    printf("Nota 1\n");
    read_note(note_1, STUDENTS);
    printf("Nota 2\n");
    read_note(note_2, STUDENTS);

    printf("Media da prova 1: %.2f\n", calculate_average(note_1, STUDENTS));
    printf("Media da prova 2: %.2f\n\n", calculate_average(note_2, STUDENTS));

    printf("Nota final dos alunos:\n");
    for (i = 0; i < STUDENTS; i++) {
        note_f[i] = (note_1[i] + note_2[i]) / 2;
        printf("Aluno %d = %.2f\n", i + 1, note_f[i]);
    }
}
