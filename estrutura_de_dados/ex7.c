//	Exercício 7
//	Defina o tipo de registro funcion�rio conforme a imagem abaixo, colete N
//	informado pelo usu�rio, crie um vetor alocado dinamicamente de tamanho N,
//	preencha os dados de cada campo, por fim, mostre todos os dados.
//  _____________________________
// | Código (int)				|
// ------------------------------
// | Salário (float)			|
// ------------------------------
// | Idade(int) | Sexo(char)  	|
// ------------------------------


#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct funcionario {
	int codigo;
	float salario;
	int idade;
	char sexo;
};

int input_int(char *title, int min, int max){
    int value;
    do {
        printf("%s (%i-%i): ", title, min, max);
	    scanf("%i", &value);
        if(value < min || value > max) {
            printf("O valor deve estar entre %i e %i\n", min, max);
        }
    } while(value < min || value > max);
	return value;
}

float input_float(char *title, float min, float max){
    float value;
    do {
        printf("%s (%.2f-%.2f): ", title, min, max);
	    scanf("%f", &value);
        if(value < min || value > max) {
            printf("O valor deve estar entre %.2f e %.2f\n", min, max);
        }
    } while(value < min || value > max);
	return value;
}

char input_char(char *title, char* options, int size){
    char value = ' ';
    do {
		printf("%s %d (", title, size);
		for(int i = 0; i < size; i++){
			printf("%c", options[i]);
			if (i == size-2) {
				printf(" ou ");
			} else if (i < size-2){
				printf(" ,");
			}
		}

        printf("): ");
	    scanf(" %c", &value);
		getchar();
		for(int i = 0; i < size; i++){
			if (value == options[i]) {
				return value;
			}
		}
        printf("Valor invalido \n");
    } while(1);
}

int main(){
	int i;
	int j;
	int soma = 0;

	printf("Digite o numero de funcionarios: ");
	scanf("%i", &i);


	struct funcionario *funcionarios = malloc(i * sizeof(struct funcionario));	

	for (j = 0; j < i; j++) {
		printf("\nFuncionario %i\n", j+1);

		funcionarios[j].codigo = input_int("Digite o codigo do funcionario: ", 0, 1000);
		funcionarios[j].salario = input_float("Digite o salario do funcionario: ", 0, 100000);
		funcionarios[j].idade = input_int("Digite a idade do funcionario: ", 0, 100);
		char options[] = {'M', 'F'};
		funcionarios[j].sexo = input_char("Digite o sexo do funcionario: ", options, sizeof(options));
	}
	printf("\n");
	for (j = 0; j < i; j++) {
		printf("\n");
		printf("Funcionario %d\n", j+1);
		printf("------------------------\n");
		printf("| Codigo: %04d         |\n", funcionarios[j].codigo);
		printf("------------------------\n");
		printf("| Salario: %09.2lf   |\n", funcionarios[j].salario);
		printf("------------------------\n");
		printf("| Idade: %02d | Sexo: %c  |\n", funcionarios[j].idade, funcionarios[j].sexo);
		printf("------------------------\n");
	}

	free(funcionarios);
	return 0;
}
