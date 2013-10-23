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


/* fun��es */
void print_token(token* to_print);
void add_char_to_nome_lido(char c);
token* fill_and_return_token(int token1);


token* fill_and_return_token(int token1)
{
	token* token_to_return = (token*) malloc(sizeof(token*));
	if(token_to_return)
	{
		printf("erro ao alocar mem�ria");
		return NULL;
	}

	token_to_return->token1 = token1;

	switch (token1)
	{
		case T_INT_CONST:
			token_to_return->token_valor_int = atoi(nome_lido);
			break;
		case T_BOOLEAN_CONST:
			if(strcmp("false", nome_lido)) token_to_return->token_valor_boolean = true;
			else token_to_return->token_valor_boolean = false;
			break;
		case T_REAL_CONST:
			token_to_return->token_valor_real = (float) atof(nome_lido);
			break;
		case T_ID:
			strcpy(token_to_return->token_valor_id, nome_lido);
			token_to_return->token2 = get_token2(token_to_return->token_valor_id);
			break;
		case T_EOF:
			strcpy(token_to_return->token_valor_id, "eof");
			break;
		default:
			strcpy(token_to_return->token_valor_id, nome_lido);
			break;
	}
	return token_to_return;
}


void add_char_to_nome_lido(char c)
{
	if(nome_lido_tam < ID_TAM_MAX - 1) printf("nome maior que o m�ximo permitido");
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
