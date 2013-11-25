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

typedef struct int_const
{
	int id;
	int token2;
	int valor;

} int_const;

typedef struct t_id
{
	int token2;
	int tipo;

} t_id;



void wml_generate_int_const_def(int valor_int_const, int token2);
void wml_int_const_def_usage(int valor_int_const, int token2);
//void wml_generate_real_const_def(float real_const_value);
//void wml_generate_boolean_const_def(bool boolena_const_value);

void wml_generate_var_def(int token2);
void wml_var_usage(int token2);
void wml_var_assignment(int token2);

void wml_generate_procedure(char *nome, int token2, int qtd_argumentos);
void wml_allocate_procedure_vars(int qtd_var_alocadas);
void wml_procedure_usage(int procedure_token2);
void wml_procedure_or_program_end();

void wml_operation_usage(int op1_token2, int op2_token2, int operacao);

int new_label();
void push_label(int label);
int pop_label();
int read_top_label();
void print_label(int label);

void wml_tjump_fw(int label);


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
