# Repositório de Engenharia da Computação

Este repositório é usado para armazenar todos os códigos escritos durante o curso de Engenharia da Computação. Aqui, você encontrará um conjunto de disciplinas, aulas e exercícios propostos pelos professores para que os estudantes possam desenvolver suas habilidades de programação.

## Ambiente de referência

Todos os comandos apresentados abaixo usam o ambiente Ubuntu com o [Fish shell](https://fishshell.com/) como referência. O Ubuntu é um sistema operacional baseado em Linux, que é amplamente utilizado no desenvolvimento de software. O Fish shell é uma shell de linha de comando moderna e amigável que oferece várias funcionalidades e recursos úteis para programadores.

## Arquitetura do repositório

O repositório é organizado em disciplinas, cada uma com um conjunto de aulas, e cada aula contém os exercícios propostos pelos professores. O formato de organização do repositório é como apresentado abaixo:

    Disciplina_01
    |   Aula_01
    |   |   ex_01.c
    |   |   ex_02.c
    |   Aula_02
    |   |   ex_01.c
    |   |   ex_02.c
    |   |   ex_03.c
    Disciplina_02
    |   Aula_01
    |   |   ex_01.c
    |   |   ex_02.c
    |   |   ex_03.c
    |   |   ex_04.c

## Formatação de código

Para garantir a uniformidade e legibilidade do código, todos os arquivos adicionados a este repositório são formatados usando o clang-format, uma ferramenta de formatação de código que segue um conjunto de regras de estilo predefinidas.

Para formatar um arquivo de código, basta utilizar o seguinte comando no terminal:

    clang-format -i <path_for_file>

Caso você não tenha o clang-format instalado em seu computador, você pode instalá-lo facilmente através do gerenciador de pacotes apt, usando o comando:

    sudo apt install clang-format