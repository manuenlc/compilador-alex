/*
 * tipo.h
 *
 *      Author: Emanuelle
 */

#ifndef TIPO_H_
#define TIPO_H_

#include "boolean.h"

typedef struct expressao
{
	int operacao;
	int tipo_operando1;
	//int tipo_operando2;


} expressao;

typedef struct procedure
{
	int token2;
	int qtd_argumentos;
	int tipo_argumentos[20];

} procedure;


int result_type(int operando1, int operando2, int operacao);
bool check_assignment(int variavel, int resultado);
char *get_type_name(int token1);

#endif /* TIPO_H_ */
