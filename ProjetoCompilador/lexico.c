/*
 * lexico.c
 *
 *      Author: Emanuelle
 */

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "tokens.h"
#include "boolean.h"


/* variaveis globais */
int nome_lido_tam;
char nome_lido[ID_TAM_MAX];


/* funções */
void print_token(token* to_print);
void add_char_to_nome_lido(char c);

void add_char_to_nome_lido(char c)
{
	if(nome_lido_tam < ID_TAM_MAX - 1) printf("nome maior que o máximo permitido");
	else
	{
		nome_lido[nome_lido_tam++] = c;
	}
}


void print_token(token* to_print)
{
	if(to_print == NULL)
	{
		printf("token NULL");
		return;
	}

	printf("%d\t\t", to_print->token1);

	switch (to_print->token1)
	{
		case T_INT_CONST:
			printf(" \t\t%d", to_print->token_valor_int);
			break;
		case T_BOOLEAN_CONST:
			if(to_print->token_valor_boolean) printf(" \t\ttrue");
			else printf(" \t\tfalse");
			break;
		case T_REAL_CONST:
			printf(" \t\t%f", to_print->token_valor_real);
			break;
		case T_ID:
			printf("%d\t\t", to_print->token2);
			printf("%s", to_print->token_valor_id);
			break;
		default:
			printf("%s", to_print->token_valor_id);
			break;
	}

		printf("\n");
}

token* next_token()
{
	nome_lido_tam = 0;

	printf("TODO");
	return NULL;
}
