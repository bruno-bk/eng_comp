# Repositório de Engenharia da Computação

Este repositório é usado para armazenar todos os códigos escritos durante o curso de Engenharia da Computação. Aqui, você encontrará um conjunto de disciplinas, aulas e exercícios propostos pelos professores para que os estudantes possam desenvolver suas habilidades de programação.

## Ambiente de referência

Todos os comandos apresentados abaixo usam o ambiente Ubuntu com o [Fish shell](https://fishshell.com/) como referência. O Ubuntu é um sistema operacional baseado em Linux, que é amplamente utilizado no desenvolvimento de software. O Fish shell é uma shell de linha de comando moderna e amigável que oferece várias funcionalidades e recursos úteis para programadores.

## Arquitetura do repositório

O repositório está organizado por disciplinas, sendo que cada disciplina pode ter uma estrutura interna diferente. O formato de organização do repositório é o seguinte:

    Disciplina_01
    |   Aula_01
    |   |   01.c
    |   |   02.c
    |   Aula_02
    |   |   01.c
    |   |   02.c
    |   |   03.c
    Disciplina_02
    |   codigo_x.c
    Disciplina_03
    |   ex01.c
    |   ex02.c

## Executando o código

Para compilar e executar códigos em C, é necessário utilizar o compilador
gcc. Para compilar o código, execute o seguinte comando:
 
    gcc <path_do_codigo> -lm -o run ;and ./run

*obs: o parametro *-lm* não é necessário em todos os codigos, apenas nos
quais são usados a biblioteca math.h.*

> Por exemplo, para compilar o código *programacao_estruturada/Aula_01/01.c*,
> execute o seguinte comando:
> 
>     gcc programacao_estruturada/Aula_01/01.c -o run ;and ./run
> 
> Saida esperada:
> 
>     Digite um numero = 


Caso você não tenha o gcc instalado em seu computador, você pode instalá-lo
facilmente através do gerenciador de pacotes apt, usando o comando:

    sudo apt install gcc

## Formatação de código

Para garantir a uniformidade e legibilidade do código, todos os arquivos adicionados a este repositório são formatados usando o clang-format, uma ferramenta de formatação de código que segue um conjunto de regras de estilo predefinidas.

Para formatar um arquivo de código, basta utilizar o seguinte comando no terminal:

    clang-format -i <path_do_arquivo>

Caso você não tenha o clang-format instalado em seu computador, você pode instalá-lo facilmente através do gerenciador de pacotes apt, usando o comando:

    sudo apt install clang-format
