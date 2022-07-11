#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "fila.h"
#include "pilha.h"

/**
 * @author Rodrigo Ferreira Rodrigues
 * @class Estrutura De Dados 1
 * @date 10/09/2018
 */
 
 /**
  * @param number
  * Recebem um valor ascii de um caracteres e converte para o numero decimal equivalente
  */ 
int converte(int number){
	switch(number){
		case 48:
			return 0;
			break;
		case 49:
			return 1;
			break;	
		case 50:
			return 2;
			break;
		case 51:
			return 3;
			break;
		case 52:
			return 4;
			break;	
		case 53:
			return 5;	
			break;	
		case 54:
			return 6;
			break;
		case 55:
			return 7;
			break;	
		case 56:
			return 8;
			break;	
		case 57:
			return 9;
			break;
	}
		exit(1);
}

/**
 * @PARAM *expr
 * @PARAM *err
 * @RETURN *err, ou saída fila E posfixada
 */
int calculadora(char * expr, int * err)
{
	// Primeiro parâmetro é NULL, devo retornar MALFORMADA.
	*err = 0;
	if(expr == NULL){
		return *err;
	}

	FILA *pfila = NULL; // Ponteiro FILA
	STACK *ppilha = NULL; // Ponteiro PILHA
	
	int tam_expr = 0, aux = 0, i = 0;
	
	/* 
	 * Pego o tamanho da entreda da fila E,
	 * para criar uma fila e pilha com no máximo o tamanho da entrada E
	 * */
	tam_expr = strlen(expr);
	pfila = create_fila(tam_expr); // ref pfila
	ppilha = create_stack(tam_expr); // ppilha
	
	// Contagem de parênteses(balanceamento)  
	for(i = 0; i < tam_expr; i++){
		printf("%c", expr[i]);
		if(expr[i] == '('){
			aux += 1;
		}
		if(expr[i] == ')'){
			aux -= 1;
		}
	}
	
	// Se aux for diferente de zeros, expr não tá balanceada.
	if(aux != 0){
		return *err;
	}

	// char/space
	if(expr[0] != 32 && expr[1] != 32){
		return -1;
	}		
	
	/*
	 * Algoritmo:
	 * Transforma entrada da fila E(fixada) em (Posfixada)
	 * */
	aux = 0; // reset aux
	for(i = 0; i < tam_expr; i++){
		switch(expr[i]){
			case '(':
					push(ppilha,expr[i]);
					break;
			case ')':
			while(peek(ppilha) != '('){
				insereFila(pfila,peek(ppilha));
				pop(ppilha);
			}
				pop(ppilha);
					break;
			case '+':
			case '-':
				if(stackIsEmpty(ppilha) == 1){
					push(ppilha,expr[i]);
					break;
				}
				aux = peek(ppilha);
				while(aux != '('){
					insereFila(pfila,aux);
					pop(ppilha);
					aux = peek(ppilha);
				}
				push(ppilha,expr[i]);
				break;
			case '/':
			case '*':
			case '%':
				if(stackIsEmpty(ppilha) == 1){
					push(ppilha,expr[i]);
					break;
				}
				aux = peek(ppilha);
				while(aux != '(' && aux != '+' && aux != '-'){
					insereFila(pfila,aux);
					pop(ppilha);
					aux = peek(ppilha);
				}
				push(ppilha,expr[i]);
				break;
			case '^':
				if(stackIsEmpty(ppilha) == 1){
					push(ppilha,expr[i]);
					break;
				}
				aux = peek(ppilha);
				while(aux != '(' && aux != '+' && aux != '-' && aux != '/' && aux != '*' && aux != '%'){
					insereFila(pfila,aux);
					pop(ppilha);
					aux = peek(ppilha);
				}
				push(ppilha,expr[i]);
				break;
			case ' ': // Encontrando um espaço
				break;
			case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
				insereFila(pfila,expr[i]);
				break;
			default: return *err; // O Caso default cai num caracter inválido, assim retorna um erro
		}
	}
	
	while(stackIsEmpty(ppilha) != 1){
		insereFila(pfila,peek(ppilha));
		pop(ppilha);
	}
	
	// Fim algoritmo Fixada -> Posfixada
	
	// Testes durante o desenvolvimento
	/*printf("\n");
	printf("Posfixada: ");
	exibirFila(pfila);*/
	
	/*
	 * Algoritmo que avalia a fila S com a expr posfixada e calcula o resultado
	 */
	int op1,op2,result;
	for(i = 0; pfila->array[i] != '\0'; i++){
		if(pfila->array[i] >= 48 && pfila->array[i] <= 57){
			push(ppilha,converte(pfila->array[i]));
		}
		if(pfila->array[i] == (int)'+'){
			op1 = peek(ppilha);
			pop(ppilha);
			op2 = peek(ppilha);
			pop(ppilha);
			result = op2 + op1;
			push(ppilha,result);
		}
		if(pfila->array[i] == (int)'-'){
			op1 = peek(ppilha);
			pop(ppilha);
			op2 = peek(ppilha);
			pop(ppilha);
			result = op2 - op1;
			push(ppilha,result);
		}
		if(pfila->array[i] == (int)'*'){
			op1 = peek(ppilha);
			pop(ppilha);
			op2 = peek(ppilha);
			pop(ppilha);
			result = op2 * op1;
			push(ppilha,result);
		}
		if(pfila->array[i] == (int)'/'){
			op1 = peek(ppilha);
			pop(ppilha);
			op2 = peek(ppilha);
			pop(ppilha);
			result = op2 / op1;
			push(ppilha,result);
		}
		if(pfila->array[i] == (int)'%'){
			op1 = peek(ppilha);
			pop(ppilha);
			op2 = peek(ppilha);
			pop(ppilha);
			result = op2 % op1;
			push(ppilha,result);
		}
		if(pfila->array[i] == (int)'^'){
			op1 = peek(ppilha);
			pop(ppilha);
			op2 = peek(ppilha);
			pop(ppilha);
			result = pow(op2,op1);
			push(ppilha,result);
		}
	}
	// Fim algoritmo que calcula o resultado
	
	//Apenas para testes durante o desenvolvimento
	//printf("\nResultado: %d\n", result);
	
	/*
	 * Algoritmo:
	 *  Avalia a condição final e retorna err ou o resultado
	 */
	pop(ppilha);
	if(stackIsEmpty(ppilha) == 1){
		*err = 1;
		return result;
	}
	*err = -1;
		return *err;
}