/*
 * geracao_de_codigo.c
 *
 *  Created on: 24/11/2013
 *      Author: Emanuelle
 */

#include "geracao_de_codigo.h"
#include <stdio.h>
#include <string.h>

identificador identificador_de_procedures[QTD_MAX_IDENTIFICADORES];
identificador identificador_de_var[QTD_MAX_IDENTIFICADORES];
int qtd_identificador_de_procedures = 0;
int qtd_identificador_de_var = 0;


void wml_generate_int_const_def(int valor_int_const);
//void wml_generate_real_const_def(float real_const_value);
//void wml_generate_boolean_const_def(bool boolena_const_value);

void wml_generate_procedure(char *nome, int token2, int qtd_argumentos);
int get_and_store_procedure_id(char *nome, int token2);

void wml_generate_print();




void wml_generate_int_const_def(int valor_int_const)
{
	printf("CONST INT %d\n", valor_int_const);
}

int get_and_store_procedure_id(char *nome, int token2)
{
	identificador_de_procedures[qtd_identificador_de_procedures].id = qtd_identificador_de_procedures + 1;
	identificador_de_procedures[qtd_identificador_de_procedures].token2 = token2;
	strcpy(identificador_de_procedures[qtd_identificador_de_procedures].nome, nome);
	return ++qtd_identificador_de_procedures;
}

void wml_generate_procedure(char *nome, int token2, int qtd_argumentos)
{
		printf("EXTERN FUNCTION %s %d %d\n", nome, get_and_store_procedure_id(nome, token2), qtd_argumentos);
}

void wml_generate_print()
{
	printf("CALL_LIB_S 2 5\n");
}
