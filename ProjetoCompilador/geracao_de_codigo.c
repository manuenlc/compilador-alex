/*
 * geracao_de_codigo.c
 *
 *  Created on: 24/11/2013
 *      Author: Emanuelle
 */

#include "geracao_de_codigo.h"
#include "gramatica.tab.h"
#include "lexico.h"
#include <stdio.h>
#include <string.h>

identificador identificador_de_procedures[QTD_MAX_IDENTIFICADORES];
identificador identificador_de_var[QTD_MAX_IDENTIFICADORES];

int labels_geradas = 0;
int labels_adicionadas = 0;
int pilha_labels[QTD_MAX_IDENTIFICADORES];

int qtd_identificador_de_procedures = 0;
int qtd_identificador_de_var = 0;

/** declaração de funções */
void wml_generate_int_const_def(int valor_int_const);
//void wml_generate_real_const_def(float real_const_value);
//void wml_generate_boolean_const_def(bool boolena_const_value);

void wml_generate_procedure(char *nome, int token2, int qtd_argumentos);
void wml_procedure_usage(int procedure_token2);
void wml_procedure_or_program_end();

int new_label();
void push_label(int label);
int pop_label();
int read_top_label();

int get_and_store_procedure_id(char *nome, int token2);
int get_identifier(int token2, int tipo);

void wml_generate_print();





/** implementação de funções */

int new_label()
{
	return ++labels_geradas;
}

void push_label(int label)
{
	if(labels_adicionadas > QTD_MAX_IDENTIFICADORES)
	{
		printf("erro: pilha de labels cheia!\n");
		return ;
	}

	pilha_labels[labels_adicionadas++] = label;
}

int pop_label()
{
	if(labels_adicionadas < 0)
	{
		printf("erro: pilha de labels vazia!\n");
		return T_INVALID;
	}

	return pilha_labels[--labels_adicionadas];
}

int read_top_label()
{
	return pilha_labels[labels_adicionadas - 1];
}

int get_identifier(int token2, int tipo)
{
	int i = 0;

	if(tipo == T_PROCEDURE)
	{
		while(i < qtd_identificador_de_procedures)
		{
			if(identificador_de_procedures[i].token2 == token2) return identificador_de_procedures[i].id;

			++i;
		}

		return T_INVALID;

	}
	else // é do tipo var
	{
		while(i < qtd_identificador_de_var)
		{
			if(identificador_de_var[i].token2 == token2) return identificador_de_var[i].id;

			++i;
		}

		return T_INVALID;
	}
}

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

void wml_procedure_usage(int procedure_token2)
{
	if(!strcmp(get_token2_id(procedure_token2), "print")) wml_generate_print();
	else printf("CALL_S %d\n", get_identifier(procedure_token2, T_PROCEDURE));
}

void wml_procedure_or_program_end()
{
	printf("RETURN\n");
}

void wml_generate_print()
{
	printf("CALL_LIB_S 2 5\n");
}
