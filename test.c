#include "calc.h"
#include "simplegrade.h"
#include <limits.h>



void teste_parametros(){
	int err;

	DESCRIBE("Testes de parâmetros");

	IF("Se o primeiro parâmetro é NULL");
	THEN("Retorna MALFORMADA");
	calculadora(NULL, &err);
	isEqual(err, MALFORMADA, 1);
}


void teste_malformadas(){
	int err;

	DESCRIBE("Testes de expressões mal-formadas");

	IF("Não tem espaços entre operandos e operadores");
	THEN("Retorna MALFORMADA");

	calculadora("1+2", &err);
	isEqual(err, MALFORMADA, 1);
	err = -1;
	calculadora("(1)", &err);
	isEqual(err, MALFORMADA, 1);

	IF("Parênteses não balanceados");
	THEN("Retorna MALFORMADA");
	err = -1;
	calculadora("( 1 + 2", &err);
	isEqual(err, MALFORMADA, 1);
	err = -1;
	calculadora("1 + 2 )", &err);
	isEqual(err, MALFORMADA, 1);
	err = -1;
	calculadora("1 + ( 1 + 2 ) + 3 )", &err);
	isEqual(err, MALFORMADA, 1);
	err = -1;
	calculadora("1 + ( 1 * ( 2 ) + 3", &err);
	isEqual(err, MALFORMADA, 1);

	IF("Caracteres inválidos");
	THEN("Retorna MALFORMADA");
	err = -1;
	calculadora("1 + x", &err);
	isEqual(err, MALFORMADA, 1);
	err = -1;
	calculadora("xabc - 5" , &err);
	isEqual(err, MALFORMADA, 1);
	err = -1;
	calculadora("( 1 â x )", &err);
	isEqual(err, MALFORMADA, 1);
}


void teste_simples(){
	int err = -1; 
	int res = 0;
	DESCRIBE("Testes simples com apenas uma operação");
	WHEN("Somando 1 e 2");
	THEN("Resultado é 3");
	res = calculadora("1 + 2", &err);
	isEqual(err, OK, 1);
	isEqual(res, 3, 1);

	WHEN("Subtraindo 2 e 1");
	THEN("Resultado é 1");
	res = calculadora("2 - 1", &err);
	isEqual(err, OK, 1);
	isEqual(res, 1, 1);

	WHEN("Multiplicando 2 e 3");
	THEN("Resultado é 6");
	res = calculadora("2 * 3", &err);
	isEqual(err, OK, 1);
	isEqual(res, 6, 1);

	WHEN("Dividindo 6 e 3");
	THEN("Resultado é 2");
	res = calculadora("6 / 3", &err);
	isEqual(err, OK, 1);
	isEqual(res, 2, 1);

	WHEN("Dividindo 6 e 4");
	THEN("Resultado é 1 (divisão inteira)");
	res = calculadora("6 / 4", &err);
	isEqual(err, OK, 1);
	isEqual(res, 1, 1);

	WHEN("Elevando 2 a 3a potência");
	THEN("Resultado é 8");
	res = calculadora("2 ^ 3", &err);
	isEqual(err, OK, 1);
	isEqual(res, 8, 1);

	WHEN("Resto da divisão entre 7 e 4");
	THEN("Resultado é 3");
	res = calculadora("7 % 4", &err);
	isEqual(err, OK, 1);
	isEqual(res, 3, 1);
}

void teste_prioridades(){
	int err = -1;
	int res = -1; 

	DESCRIBE("Teste da prioridade dos operadores");

	IF("Multiplicação tem maior prioridade que soma");
	THEN("Resultado deve ser 7");
	res = calculadora("1 + 2 * 3", &err);
	isEqual(res, 7, 1);
	isEqual(err, OK, 1);
	err = -1;

	IF("Exponenciação tem mais prioridade que Multiplicação");
	THEN("Resultado deve ser 8"); // Se exponenciação tem prioridade r=8
	res = calculadora("1 * 2 ^ 3", &err);
	isEqual(res, 8, 1);
	isEqual(err, OK, 1);
	err = -1;

	IF("Parênteses sempre ganham");
	THEN("Resultado deve ser 20");
	res = calculadora("4 * ( 2 + 3 )", &err);
	isEqual(res, 20, 1);
	isEqual(err, OK, 1);
	err = -1;

	IF("Parênteses sempre ganham");
	THEN("Resultado deve ser 20");
	res = calculadora("( 2 + 3 ) * 4", &err);
	isEqual(res, 20, 1);
	isEqual(err, OK, 1);
	err = -1;

	IF("Múltiplos parênteses");
	THEN("Resultado deve ser 16");
	res = calculadora("4 * ( 2 + ( 3 - 1 ) )", &err);
	isEqual(res, 16, 1);
	isEqual(err, OK, 1);
	err = -1;

	IF("Múltiplos parênteses");
	THEN("Resultado deve ser 3"); // r = 3
	res = calculadora("( 4 - 1 ) * ( 3 - 2 )", &err);
	isEqual(res, 3, 1);
	isEqual(err, OK, 1);
	err = -1;
}





int main(int argc, char ** argv){
	if (argc>1){
		return 0;
	}
	if (!argv){
		return 0;
	}


	teste_parametros();
	teste_malformadas();
	teste_simples();
	teste_prioridades();



	GRADEME();
	
	if (grade==maxgrade)
		return 0;
	else return grade;

}
