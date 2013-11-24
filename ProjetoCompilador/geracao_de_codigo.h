/*
 * geracao_de_codigo.h
 *
 *  Created on: 24/11/2013
 *      Author: Emanuelle
 */

#ifndef GERACAO_DE_CODIGO_H_
#define GERACAO_DE_CODIGO_H_

#include "boolean.h"
#include "tokens.h"

#define QTD_MAX_IDENTIFICADORES		50

typedef struct identificador
{
	int id;
	int token2;
	char nome[ID_TAM_MAX];

} identificador;


void wml_generate_int_const_def(int valor_int_const);
//void wml_generate_real_const_def(float real_const_value);
//void wml_generate_boolean_const_def(bool boolena_const_value);

void wml_generate_procedure(char *nome, int token2, int qtd_argumentos);
int get_and_store_procedure_id(char *nome, int token2);



void wml_generate_print();
void wml_generate_add();
void wml_generate_ne();
void wml_generate_lt();


/*
 * <>
 * :=
 * <
 * mod
 * if
 * then
 * while
 * do
 * print
 */

#endif /* GERACAO_DE_CODIGO_H_ */
