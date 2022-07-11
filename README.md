# AED1 - Trabalho 1 - Calculadora

Declaro que o presente trabalho contém código desenvolvido exclusivamente por mim e que não foi compartilhado de nenhuma forma com terceiros a não ser o professor da disciplina. Compreendo que qualquer violação destes princípios será punida rigorosamente de acordo com o Regimento da UFPEL.

(Preencha com seus dados)

- Nome completo: *****
- Username do Bitbucket: *****
- Email @inf: *****


## Descrição 

Este trabalho consiste em desenvolver uma calculadora de expressões contendo números inteiros usando notação polonesa reversa (ou pós-fixada). O cálculo consiste de três etapas: 

- Ler e validar a expressão
- Transformar para pós-fixada 
- Calcular


## Entrada

A entrada consiste de uma _string_ com a expressão infixada contendo os seguintes caracteres além de dígitos decimais: 

    ( , ) , + , - , * , / , ^ , %

_^_ refere-se à exponenciação, _%_ ao resto da divisão.

A prioridade das operações em ordem decrescente é:

- ( , )
- ^
- *, /, %
- +, -

Não há operadores _-_ e _+_ unários.

Exemplo: 

    ( 5 + 4 ) % 4

É calculada como:

    ( 9 ) % 4
    1

Todas as operações, parênteses e números devem estar separados por exatamente um espaço. Qualquer expressão que não esteja em conformidade deve ser considerada inválida.

Para exemplos de conversão, vejam [2]. 

## Saída

A saída consiste de um inteiro e uma condição de erro que indica se:

- MALFORMADA (a expressão não é uma expressão aritmética)
- OK (a expressão foi avaliada e seu resultado está na saída)

Caso a expressão seja MALFORMADA, a saída deve ser zero.

## Algoritmo de conversão infixada para pós-fixada

    Entrada: fila E com expressão infixada
    Saída: fila S com expressão pós-fixada

    Pilha P

    Para cada elemento x retirado de E:
        Caso x for:
            operando: Coloque em S
            ( : coloque em P
            ) : tire operadores de P até encontrar (, adicionando-os a S
            operador: tire operadores de S enquanto topo de P tiver precedência maior ou igual a x ou (, coloque em S
                      coloque x em P

    Tire todos os operandos de P e coloque em S
        // Se pilha ainda conter ( , a expressão é inválida


## Algoritmo de cálculo

O algoritmo não considera _underflow_ e _overflow_, mas a implementação deve testar.


    Entrada: fila E com expressão pós-fixada
    Saída: inteiro

    Pilha P

    Para cada elemento x de E:
        Se x for:
            operando: coloque em P
            operador: retire dois operandos de P e realize operação, colocando resultado em P

    Retire topo da pilha para y:
        Se pilha vazia:
            Retorne y
        Se pilha não vazia:
            Retorne erro


## Produtos

- aluno.c: testes do aluno
- calc.c: implementação da calculadora

A versão final deverá executar os testes dos Professores no _pipeline_ do Bitbucket usando a regra _make test_. 

O Makefile poderá ser modificado para adicionar as regras para construir as bibliotecas de listas, filas e pilhas que serão copiadas do repositório do aluno. 

*Implementações que não usem as interfaces de tipo abstrato de dados como definidas em aula não serão aceitas*.


## Estruturas de Dados Necessárias

### Fila

Pode ser implementada com uma lista encadeada ou sequencial. Como um elemento na fila de entrada pode ser um número ou operação, sugere-se:

- Definir uma enumeração com os diferentes tipos de operação;
- Usar _switch_ para essas operações;
- Definir uma _struct_ que tenha a opção de ter um número, uma operação e um valor para definir o que está contido, como:


        enum operacao {adicao, subtracao, ...};
        enum num_ou_op {num, op};
        struct entrada{
            int numero;
            enum operacao oper;
            enum num_ou_op tipo;
        };

### Pilha

Também pode ser implementada como uma lista de qualquer tipo. Um elemento na pilha é sempre um operando, então pode-se usar simplesmente uma lista de inteiros para o armazenamento.


## Cronograma

- Entrega final: _10/10/2018_


## Referências

- [1]https://pt.wikipedia.org/wiki/Nota%C3%A7%C3%A3o_polonesa_inversa
- [2]https://www.mathblog.dk/tools/infix-postfix-converter/

