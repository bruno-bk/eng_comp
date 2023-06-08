#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
/* #include <windows.h> */

char *itoa(int value, char *str, int radix) {
    static char dig[] = "0123456789"
                        "abcdefghijklmnopqrstuvwxyz";
    int n = 0, neg = 0;
    unsigned int v;
    char *p, *q;
    char c;

    if (radix == 10 && value < 0) {
        value = -value;
        neg = 1;
    }
    v = value;
    do {
        str[n++] = dig[v % radix];
        v /= radix;
    } while (v);
    if (neg)
        str[n++] = '-';
    str[n] = '\0';

    for (p = str, q = p + (n - 1); p < q; ++p, --q)
        c = *p, *p = *q, *q = c;
    return str;
}

int main() {
    FILE *f;
    int i, cc;
    time_t t;
    char c;
    char boletoc[9];
    char str[45];
    char cliente[5][6] = {"00010", "00100", "00015", "00020", "00110"};
    char conta[5][7] = {"419886", "001876", "786543", "001767", "018887"};
    int boleto = 87433457;
    char pagamento[10][9] = {"20210507", "20210704", "20211001", "20211101",
                             "20210807", "20210427", "20210930", "20210218",
                             "20210117", "20210407"};
    char vencimento[10][9] = {"20220507", "20220704", "20221001", "20221101",
                              "20220807", "20220427", "20220930", "20220218",
                              "20220117", "20220407"};
    char valor[9] = "00000000";
    srand((unsigned)time(&t));

    strcpy(str, "");

    f = fopen("remessa.txt", "w");
    if (f == NULL) {
        printf("Erro ao criar arquivo.");
    } else {
        printf("Arquivo criado com sucesso.\n");
    }
    fputs("120220525\n", f);
    i = 0;
    do {
        strcat(str, "2");
        cc = rand() % 5;
        strcat(str, cliente[cc]);
        strcat(str, conta[cc]);
        itoa(boleto + i, boletoc, 10);
        strcat(str, boletoc);
        strcat(str, vencimento[rand() % 10]);
        strcat(str, pagamento[rand() % 10]);
        sprintf(valor, "%08d", rand() % 99999999);
        strcat(str, valor);
        strcat(str, "\n");
        fputs(str, f);
        strcpy(str, "");
        i = i + 1;
    } while (i < 100);
    fclose(f);

    f = fopen("remessa.txt", "r");
    if (f == NULL) {
        printf("Erro ao abrir arquivo.");
    }

    while ((c = fgetc(f)) != EOF) {
        printf("%c", c);
    }

    // fgets(frase,34,f);
    // puts(frase);

    fclose(f);
}
