// Ler o arquivo README.md para entender os requisitos

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define COD_OK 0
#define COD_DATA 1
#define COD_SIZE 2
#define COD_ID 3

#define COD_CONTA 4
#define COD_NUM_BOLETO 5
#define COD_DATA_VENC 6
#define COD_DATA_PAG 7
#define COD_VALOR 8

int find_next_client_equal_name(FILE *file, const char *client, int atual_pos) {
    char line[50];
    fseek(file, atual_pos, 0);
    while (!feof(file)) {
        fgets(line, sizeof(line), file);

        if (feof(file)) {
            /* printf("There are no more clients with the same name\n"); */
            return 0;
        }

        /* printf("Check client %s line: %s",client, line); */
        if (strncmp(line + 1, client, 5) == 0) {
            /* printf("find client %s pos %d\n", client, atual_pos); */
            return atual_pos;
        }

        fseek(file, 46, atual_pos);
        atual_pos += 46;
    }
}

int file_exist(const char *file_name) {
    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        /* printf("File do not exist\n"); */
        return 0;
    } else {
        /* printf("File exist\n"); */
        fclose(file);
        return 1;
    }
}

void create_client_file_name(const char *client_name, char *client_file_name,
                             size_t size) {
    struct tm *p;
    time_t seconds;
    time(&seconds);
    p = localtime(&seconds);

    sprintf(client_file_name, "%04d%02d%02d", p->tm_year + 1900, p->tm_mon + 1,
            p->tm_mday);
    strncat(client_file_name, client_name, 5);
    strcat(client_file_name, ".txt");
    client_file_name[size - 1] = '\0';

    /* printf("%s\n", client_file_name); */
}

void write_header(FILE *client_file) {
    char header[11];
    struct tm *p;
    time_t seconds;
    time(&seconds);
    p = localtime(&seconds);

    sprintf(header, "1%04d%02d%02d\n", p->tm_year + 1900, p->tm_mon + 1,
            p->tm_mday);
    fputs(header, client_file);
}

void process_line(const char *line, FILE *client_file) {
    /* printf("process line: %s", line); */
    char file_line[33];
    strcpy(file_line, "2");
    strncat(file_line, line + 6, 6);
    strncat(file_line, line + 12, 8);
    strncat(file_line, line + 28, 8);
    strncat(file_line, line + 36, 8);
    strcat(file_line, "\n");

    fputs(file_line, client_file);
}

void write_end_client_file(FILE *client_file, int number_of_tickets,
                           int amount_paid) {
    /* printf("write the end of the client file\n"); */
    char file_line[19];

    sprintf(file_line, "3%06d%010d\n", number_of_tickets, amount_paid);
    fputs(file_line, client_file);
}

void write_file_error(int line, char *msg) {
    char error_msg[100];
    FILE *file = fopen("ERRO.txt", "w");

    if (line != -1) {
        sprintf(error_msg,
                "Erro encontrado na linha %d do arquivo remessa.txt\n", line);
        fputs(error_msg, file);
    }
    sprintf(error_msg, "Erro: %s\n", msg);
    fputs(error_msg, file);

    fclose(file);
}

void process_ticket(FILE *file) {
    char line[50];
    char id[6] = "";
    char client_file_name[18] = "";
    FILE *client_file;
    int read_adress = 11;
    fseek(file, read_adress, 0);

    while (!feof(file)) {
        fgets(line, sizeof(line), file);
        if (feof(file)) {
            /* printf("End of file\n\n"); */
            break;
        }
        /* printf("read pos %d line: %s", read_adress, line); */
        strncpy(id, line + 1, 5);
        create_client_file_name(id, client_file_name, sizeof(client_file_name));

        if (!file_exist(client_file_name)) {
            client_file = fopen(client_file_name, "w");
            if (client_file == NULL) {
                write_file_error(-1, "Falha ao criar o arquivo do usuario");
            }

            int new_read_adress = read_adress;
            int number_of_tickets = 0;
            int amount_paid = 0;
            char ticket_value[9];

            write_header(client_file);
            do {
                process_line(line, client_file);

                number_of_tickets++;
                strncpy(ticket_value, line + 36, 8);
                ticket_value[8] = '\0';
                amount_paid += atoi(ticket_value);

                new_read_adress =
                    find_next_client_equal_name(file, id, new_read_adress + 46);
                fseek(file, new_read_adress, 0);
                fgets(line, sizeof(line), file);
            } while (new_read_adress != 0);

            write_end_client_file(client_file, number_of_tickets, amount_paid);
            fclose(client_file);
        }

        read_adress += 46;
        fseek(file, read_adress, 0);
    }
}

int validar_cabecalho(const char *linha) {
    int i = 0;
    /* printf("validar_cabecalho: %s", linha); */

    if (linha[0] != '1') {
        return COD_ID;
    }

    if (strlen(linha) != 10) {
        return (COD_SIZE);
    }

    for (i = 1; 8 >= i; i++) {
        if (linha[i] < '0' || linha[i] > '9') {
            return COD_DATA;
        }
    }

    return COD_OK;
}

int validar_linha(const char *linha) {
    int i = 0, valida = 0;
    /* printf("validar_linha: %s", linha); */
    // VALIDA QTD DE CARACTERES
    if (strlen(linha) != 45) {
        return (COD_SIZE);
    }
    // VALIDA ID LINHA
    if (linha[0] != '2') {
        return (COD_ID);
    }
    // VALIDA CONTA
    for (i = 6; 11 >= i; i++) {
        if (linha[i] < '0' || linha[i] > '9') {
            return (COD_CONTA);
        }
    }
    // VALIDA COD BOLETO
    for (i = 12; 19 >= i; i++) {
        if (linha[i] < '0' || linha[i] > '9') {
            return (COD_NUM_BOLETO);
        }
    }
    // VALIDA DATA DE VENCIMENTO
    for (i = 20; 27 >= i; i++) {
        if (linha[i] < '0' || linha[i] > '9') {
            return (COD_DATA_VENC);
        }
    }
    // VALIDA DATA DE PAGAMENTO
    for (i = 28; 35 >= i; i++) {
        if (linha[i] < '0' || linha[i] > '9') {
            return (COD_DATA_PAG);
        }
    }
    // VALIDA VALOR
    for (i = 36; 43 >= i; i++) {
        if (linha[i] < '0' || linha[i] > '9') {
            return (COD_VALOR);
        }
    }
    return COD_OK;
}

int check_remessa(FILE *file) {
    char line[50];
    int read_adress = 0;
    int line_number = 0;
    int code_return = 0;

    fseek(file, read_adress, 0);
    fgets(line, sizeof(line), file);
    line_number++;

    code_return = validar_cabecalho(line);
    if (code_return == COD_SIZE) {
        write_file_error(1, "O cabecalho esta com o tamanho incorreto");
    } else if (code_return == COD_ID) {
        write_file_error(1, "A linha possui o id invalido");
    } else if (code_return == COD_DATA) {
        write_file_error(1, "A data do cabecalho possui caracter invalido");

    } else if (code_return == 0) {
        read_adress = 11;
        fseek(file, read_adress, 0);

        while (!feof(file)) {
            fseek(file, -1, SEEK_CUR);
            fgets(line, sizeof(line), file);
            line_number++;
            if (feof(file)) {
                /* printf("End of file\n\n"); */
                break;
            }

            code_return = validar_linha(line);
            if (code_return) {
                /* printf("Erro %d na linha %d\n", code_return, line_number); */
                if (code_return == COD_SIZE) {
                    write_file_error(line_number,
                                     "A linha esta com o tamanho incorreto");
                } else if (code_return == COD_ID) {
                    write_file_error(line_number,
                                     "A linha possui o id invalido");
                } else if (code_return == COD_CONTA) {
                    write_file_error(
                        line_number,
                        "O numero da conta pussui caracter invalido");
                } else if (code_return == COD_NUM_BOLETO) {
                    write_file_error(
                        line_number,
                        "O numero do boleto pussui caracter invalido");
                } else if (code_return == COD_DATA_VENC) {
                    write_file_error(
                        line_number,
                        "A data de vencimento possui caracter invalido");
                } else if (code_return == COD_DATA_PAG) {
                    write_file_error(
                        line_number,
                        "A data do pagamento possui caracter invalido");
                } else if (code_return == COD_VALOR) {
                    write_file_error(
                        line_number,
                        "O valor do boleto possui caracter invalido");
                }
                break;
            }

            read_adress += 45;
            fseek(file, read_adress, 0);
        }
    }

    return code_return;
}

int main() {
    FILE *file = fopen("remessa.txt", "r");
    if (file == NULL) {
        write_file_error(-1, "Arquivo remessa.txt nao encontrado");
    } else if (check_remessa(file) == COD_OK) {
        process_ticket(file);
    }
    fclose(file);
}
