// Exercício 24
// Considere um cadastro de alunos desenvolvido que permita incluir, alterar, excluir, buscar e
// mostrar as seguintes informações: RA, Nome, Curso, Nota1, Nota2 e Nota3. Com isso faça as
// seguintes tarefas.
// a) Crie uma função inserir que permita inserir o aluno em uma lista encadeada em ordem
// alfabética, não permitindo a duplicidade de RA;
// b) Crie uma função alterar que permita fazer a alteração de um cadastro do aluno já inserido
// na lista, ainda não permitido a duplicidade de RA e deixando a lista em ordem alfabética;
// c) Crie uma função excluir que permita excluir o aluno já inserido na lista por meio do RA;
// d) Crie uma função buscar que permita fazer a busca pelo aluno na lista encadeada pelo seu
// RA;
// e) Crie uma função relatório que mostrará todos os campos do registro aluno e mais o item
// média que irá mostrar a maior média entre N1 e N2, N1 e N3 ou N2 e N3.
// f) Reutilizando as funções elaboradas acima, criar o programa que mostre o menu conforme
// apresentado abaixo:
// 1 – Inserir Aluno
// 2 – Alterar Aluno
// 3 – Excluir Aluno
// 4 – Buscar Aluno
// 5 – Relatório das Notas
// 6 - Sair

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct S {
    int id;
    char name[100];
    char course[100];
    float grades[3];
    struct S *next;
} Student;

const int NUM_GRADES = 3;
Student *students = NULL;

void insertStudent(int id, char name[], char course[], float grades[]) {
    Student *newStudent = (Student *)malloc(sizeof(Student));
    newStudent->id = id;
    strcpy(newStudent->name, name);
    strcpy(newStudent->course, course);
    for (int i = 0; i < NUM_GRADES; i++) {
        newStudent->grades[i] = grades[i];
    }
    newStudent->next = NULL;

    if (students == NULL) {
        students = newStudent; 
    } else {
        if (id < students->id) {
            newStudent->next = students;
            students = newStudent;
        } else if (id == students->id) {
            printf("Erro: Aluno com RA %d já existe.\n", id);
            free(newStudent);
            return;
        } else {
            Student *student = students;
            while (student->next != NULL && id > student->next->id) {
                student = student->next;
            }
            if (student->next != NULL && id == student->next->id) {
                printf("Erro: Aluno com RA %d já existe.\n", id);
                free(newStudent);
                return;
            }
            newStudent->next = student->next;
            student->next = newStudent;
        }
    }
    printf("Aluno inserido com sucesso.\n");
}

void modifyStudent(int id, char name[], char course[], float grades[]) {
    Student *student = students;
    while (student != NULL) {
        if (id == student->id) {
            strcpy(student->name, name);
            strcpy(student->course, course);
            for (int i = 0; i < NUM_GRADES; i++) {
                student->grades[i] = grades[i];
            }
            printf("Aluno com RA %d alterado com sucesso.\n", id);
            return;
        }
        student = student->next;
    }
    printf("Erro: Aluno com RA %d não encontrado.\n", id);
}

void deleteStudent(int id) {
    if (students == NULL) {
        printf("Erro: Lista de alunos vazia.\n");
        return;
    }

    Student *student = students;
    Student *previousStudent = NULL;
    while (student != NULL) {
        if (id == student->id) {
            if (previousStudent == NULL) {
                students = student->next;
            } else {
                previousStudent->next = student->next;
            }
            free(student);
            printf("Aluno com RA %d excluído com sucesso.\n", id);
            return;
        }
        previousStudent = student;
        student = student->next;
    }
    printf("Erro: Aluno com RA %d não encontrado.\n", id);
}

Student *searchStudent(int id) {
    Student *student = students;
    while (student != NULL) {
        if (id == student->id) {
            return student;
        }
        student = student->next;
    }
    return NULL;
}

void gradeReport() {
    if (students == NULL) {
        printf("Erro: Lista de alunos vazia.\n");
        return;
    }

    Student *student = students;
    while (student != NULL) {
        float average1 = (student->grades[0] + student->grades[1]) / 2;
        float average2 = (student->grades[0] + student->grades[2]) / 2;
        float average3 = (student->grades[1] + student->grades[2]) / 2;
        float highestAverage = average1;
        if (average2 > highestAverage) {
            highestAverage = average2;
        }
        if (average3 > highestAverage) {
            highestAverage = average3;
        }

        printf("RA: %d\n", student->id);
        printf("Nome: %s\n", student->name);
        printf("Curso: %s\n", student->course);
        for (int i = 0; i < NUM_GRADES; i++) {
            printf("Nota %d: %.2f\n", i + 1, student->grades[i]);
        }
        printf("Media: %.2f\n", highestAverage);
        printf("\n");

        student = student->next;
    }
}

int main() {
    int option = 0;
    while (option != 6) {
        printf("Menu:\n");
        printf("1 - Inserir Aluno\n");
        printf("2 - Alterar Aluno\n");
        printf("3 - Excluir Aluno\n");
        printf("4 - Buscar Aluno\n");
        printf("5 - Relatório das Notas\n");
        printf("6 - Sair\n");

        printf("Digite uma opção: ");
        scanf("%d", &option);

        switch (option) {
        case 1: {
            int id;
            char name[50];
            char course[50];
            float grades[NUM_GRADES];

            printf("RA: ");
            scanf("%d", &id);
            printf("Nome: ");
            scanf(" %[^\n]", name);
            printf("Curso: ");
            scanf(" %[^\n]", course);
            for (int i = 0; i < NUM_GRADES; i++) {
                printf("Nota %d: ", i + 1);
                scanf("%f", &grades[i]);
            }

            insertStudent(id, name, course, grades);
            break;
        }

        case 2: {
            int id;
            char name[50];
            char course[50];
            float grades[NUM_GRADES];

            printf("RA do aluno a ser alterado: ");
            scanf("%d", &id);

            Student *existingStudent = searchStudent(id);
            if (existingStudent == NULL) {
                printf("Erro: Aluno com RA %d não encontrado.\n", id);
                break;
            }

            printf("Novo nome: ");
            scanf(" %[^\n]", name);
            printf("Novo Curso: ");
            scanf(" %[^\n]", course);
            for (int i = 0; i < NUM_GRADES; i++) {
                printf("Nova nota %d: ", i + 1);
                scanf("%f", &grades[i]);
            }

            modifyStudent(id, name, course, grades);
            break;
        }
        case 3: {
            int id;
            printf("RA do aluno a ser excluído: ");
            scanf("%d", &id);
            deleteStudent(id);
            break;
        }
        case 4: {
            int id;
            printf("RA do aluno a ser buscado: ");
            scanf("%d", &id);
            Student *foundStudent = searchStudent(id);
            if (foundStudent != NULL) {
                printf("Aluno encontrado:\n");
                printf("RA: %d\n", foundStudent->id);
                printf("Nome: %s\n", foundStudent->name);
                printf("Curso: %s\n", foundStudent->course);
                for (int i = 0; i < NUM_GRADES; i++) {
                    printf("Nota %d: %.2f\n", i, foundStudent->grades[i]);
                }
                printf("\n");
            } else {
                printf("Erro: Aluno com RA %d não encontrado.\n", id);
            }
            break;
        }
        case 5: {
            gradeReport();
            break;
        }
        case 6:
            printf("Saindo.\n");
            break;
        default:
            printf("Opcao invalida\n");
            break;
        }

        printf("\n");
    }

    return 0;
}