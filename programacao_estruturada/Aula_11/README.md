# 1. Descrição
 
A central de processamento de dados do Banco da faculdade recebe toda noite um arquivo texto contendo todos os pagamentos de boletos bancários realizados a favor de seus clientes nas várias agências bancárias espalhadas pelo país. O arquivo citado (chamado de REMESSA) segue o seguinte padrão:
 
* A primeira linha do arquivo enviado é chamada de CABEÇALHO e possui as seguintes informações:
 
* Número de Caracteres da linha: 9
* Informações obtidas a partir desta linha
 
| Nome    | Tipo      | Tamanho   | Valor     | Descrição                                           |
|---------|-----------|-----------|-----------|-----------------------------------------------------|
| ID      | Inteiro   | 1         | 1         | Indica que a linha é um cabeçalho                   |
| DATA    | Data      | 8         | Variável  | Informa a data da remessa. Segue o padrão AAAAMMDD. |

* obs AAAAMMDD significa:

        AAAA: Ano com 4 dígitos
        MM: Mês com 2 dígitos
        DD: Dia com 2 dígitos
 

As linhas seguintes informam dados sobre cada  boleto pago e é definida da seguinte forma:
 
* Número de Caracteres da linha: 44
* Informações obtidas a partir desta linha
 
| Nome            | Tipo      | Tamanho   | Valor     | Descrição                                                         |
|-----------------|-----------|-----------|-----------|-------------------------------------------------------------------|
| ID              | Número    | 1         | 2         | Indica que a linha é um boleto pago                               |
| CLIENTE         | Número    | 5         | Variável  | Informa o código do cliente do banco                              |
| CONTA           | Número    | 6         | Variável  | Informa a conta corrente a ser creditado o boleto.                |
| NUM_BOLETO      | Número    | 8         | Variável  | Número do Boleto Pago                                             |
| DATA_VENC       | Data      | 8         | Variável  | Informa a data de vencimento do boleto. Segue o padrão AAAAMMDD.  |
| DATA_PAGAMENTO  | Data      | 8         | Variável  | Informa a data de pagamento do boleto.                            |
| VALOR_PAGO      | Número    | 8         | Variável  | Informa o valor pago.Segue os eguinte padrão: NNNNNNDD.           |

* obs NNNNNNDD significa:

        NNNNNN: representa a parte inteira do valor
        DD: Representa a parte decimal.
        Ex: O valor R$ 2.340,54 seria representado como  00234054

# 2. arquivo de saida

O objetivo do projeto é desenvolver um programa que, a partir de um arquivo REMESSA, gera um arquivo RETORNO para cada um de seus clientes. Com esse arquivo, o cliente pode efetuar seu controle particular de pagamento dos boletos, além do banco poder atualizar o saldo na conta corrente desses seus clientes. O arquivo RETORNO deve seguir o padrão abaixo:

* A primeira linha do arquivo enviado é chamada de CABEÇALHO e possui as seguintes informações:

* Número de Caracteres da linha: 9
* Informações obtidas a partir desta linha
 
| Nome    | Tipo      | Tamanho   | Valor     | Descrição                                           |
|---------|-----------|-----------|-----------|-----------------------------------------------------|
| ID      | Inteiro   | 1         | 1         | Indica que a linha é um cabeçalho                   |
| DATA    | Data      | 8         | Variável  | Informa a data do retorno. Segue o padrão AAAAMMDD. |

As linhas seguintes informam dados sobre cada  boleto pago ao cliente e é definida da seguinte forma:

* Número de Caracteres da linha: 31
* Informações obtidas a partir desta linha

| Nome            | Tipo      | Tamanho   | Valor     | Descrição                                                       |
|-----------------|-----------|-----------|-----------|-----------------------------------------------------------------|
| ID              | Número    | 1         | 2         | Indica que a linha é um boleto pago                             |
| CONTA           | Número    | 6         | Variável  | Informa a conta corrente a ser creditado o boleto.              |
| NUM_BOLETO      | Número    | 8         | Variável  | Número do Boleto Pago                                           |
| DATA_PAGAMENTO  | Data      | 8         | Variável  | Informa a data de pagamento do boleto. Segue o padrão AAAAMMDD. |
| VALOR_PAGO      | Número    | 8         | Variável  | Informa o valor pago. Segue os padrão: NNNNNNDD.                |
 
A última linha do arquivo retorno segue o seguinte formato.
 
* Número de Caracteres da linha: 17
* Informações obtidas a partir desta linha
 
| Nome            | Tipo      | Tamanho   | Valor     | Descrição                                                           |
|-----------------|-----------|-----------|-----------|---------------------------------------------------------------------|
| ID              | Número    | 1         | 3         | Indica que a linha é a última                                       |
| TOTAL_BOLETOS   | Número    | 6         | Variável  | Informa o total de boletos registrados no arquivo de retorno.       |
| VALOR_TOTAL     | Número    | 10        | Variável  | Informa a soma total dos boletos registrados no arquivo de retorno  |

    Observação:
    Todos os campos numéricos são preenchidos com 0 (Zero) à esquerda caso o valor não ocupe todo o campo.
 
# 3. Regras para o desenvolvimento do programa:

1. O programa deve checar se o arquivo de remessa está no formato padrão, caso não esteja deve ser gerado um arquivo chamado ERRO.TXT contendo o tipo de erro encontrado. O erro deve ter a informação necessária para que, quem o leia, tenha condições de resolver o problema.

2. Cada arquivo de retorno contém os boletos referentes a um cliente, ou seja, se forem encontrados 10 clientes diferentes no arquivo de remessa, serão gerados 10 arquivos de retorno com os boletos referentes a cada um deles. O nome do arquvio de retorno deve seguir o padrao:
 AAAAMMDD_CLIENTE.txt onde AAAAMMDD é a data de geração do retorno e CLIENTE é o código do cliente obtido no arquivo de remessa.

3. O programa não terá qualquer tipo de interface com o usuário (qualquer operação deve ser passada por linha de comando). Não serão corrigidos os programas que tiverem qualquer tipo de interface que não seja a linha de comando.
