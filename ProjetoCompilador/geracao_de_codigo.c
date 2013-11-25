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
identificador identificador_de_int_const[QTD_MAX_IDENTIFICADORES];

int labels_geradas = 0;
int labels_adicionadas = 0;
int pilha_labels[QTD_MAX_IDENTIFICADORES];

int qtd_identificador_de_procedures = 0;
int qtd_identificador_de_var = 0;
int qtd_identificador_de_int_const = 0;

/** declara��o de fun��es */
void wml_generate_int_const_def(int valor_int_const);
void wml_int_const_def_usage(int valor_int_const);
//void wml_generate_real_const_def(float real_const_value);
//void wml_generate_boolean_const_def(bool boolena_const_value);

void wml_generate_var_def(int token2);
void wml_var_usage(int token2);
void wml_var_assignment(int token2);

void wml_generate_procedure(char *nome, int token2, int qtd_argumentos);
void wml_procedure_usage(int procedure_token2);
void wml_procedure_or_program_end();
void wml_allocate_procedure_vars(int qtd_var_alocadas);

void wml_operation_usage(int op1_token2, int op2_token2, int operacao);

int new_label();
void push_label(int label);
int pop_label();
int read_top_label();

int get_and_store_procedure_id(char *nome, int token2);
int get_identifier(int token2, int tipo);

void wml_generate_print();





/** implementa��o de fun��es */

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
	else // � do tipo var
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

	int i;
	for(i = 0; i < qtd_identificador_de_int_const; ++i)
	{
		if(identificador_de_int_const[i].token2 == valor_int_const) return ; // j� existe! n�o precisa declarar de novo!
	}

	printf("CONST INT %d\n", valor_int_const);

	identificador_de_int_const[qtd_identificador_de_int_const].id = qtd_identificador_de_int_const + 1;
	identificador_de_int_const[qtd_identificador_de_int_const].token2 = valor_int_const;
	++qtd_identificador_de_int_const;
}

void wml_int_const_def_usage(int valor_int_const)
{
	int i;
	for(i = 0; i < qtd_identificador_de_int_const; ++i)
	{
		if(identificador_de_int_const[i].token2 == valor_int_const)
		{
			printf("LOAD_CONST_S %d\n", identificador_de_int_const[i].id);
			return ;
		}
	}

	// se a int_const n�o foi definida, ela � adicionada!
	wml_generate_int_const_def(valor_int_const);
	printf("LOAD_CONST_S %d\n", qtd_identificador_de_int_const);
}

void wml_generate_var_def(int token2)
{
	int i;
	for(i = 0; i < qtd_identificador_de_var; ++i)
	{
		if(identificador_de_var[i].token2 == token2) return; // J� definido. N�o precisa definir de novo.
	}

	identificador_de_var[qtd_identificador_de_var].id = qtd_identificador_de_var + 1;
	identificador_de_var[qtd_identificador_de_var].token2 = token2;
	strcpy(identificador_de_var[qtd_identificador_de_var].nome, get_token2_id(token2));

	printf("incluindo tk2 %d, t_id %d - %s\n", identificador_de_var[qtd_identificador_de_var].token2
												, identificador_de_var[qtd_identificador_de_var].id
												, identificador_de_var[qtd_identificador_de_var].nome);
	++qtd_identificador_de_var;
}

void wml_var_usage(int token2)
{
	int i;
	for(i = 0; i < qtd_identificador_de_var; ++i)
	{
		if(identificador_de_var[i].token2 == token2)
		{
			printf("LOAD_VAR_S %d - %s\n", identificador_de_var[i].id, get_token2_id(token2));
			return ;
		}
	}
}

void wml_var_assignment(int token2)
{
	int i;
	for(i = 0; i < qtd_identificador_de_var; ++i)
	{
		if(identificador_de_var[i].token2 == token2)
		{
			printf("STORE_VAR_S %d - %s\n", identificador_de_var[i].id, get_token2_id(token2));
			return ;
		}
	}
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

void wml_allocate_procedure_vars(int qtd_var_alocadas)
{
	printf("FUNCVARS %d\n", qtd_var_alocadas);
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

void wml_operation_usage(int op1_token2, int op2_token2, int operacao)
{
	//printf("op1 = %d, op2 = %d, op = %d\n", op1_token2, op2_token2, operacao);

	if(op2_token2 == T_EOF) return ;

	switch(operacao)
	{
	case T_AND:
		printf("ADD\n");
		break;
	case T_DIF:
		printf("NE\n");
		break;
	case T_MOD:
		printf("REM\n");
		break;
	case T_LT:
		printf("LT\n");
		break;
	case T_TIMES:
		printf("MUL\n");
		break;
	case T_DIV:
		printf("IDIV\n");
		break;
	case T_EQ:
		printf("EQ\n");
		break;
	case T_MINUS:
		if(op2_token2 == T_VOID) printf("UMINUS\n");
		else printf("SUB\n");
		break;
	case T_EOF:
		break;
	default:
		printf("falta adicionar operacao %d\n", operacao);

	}
}
