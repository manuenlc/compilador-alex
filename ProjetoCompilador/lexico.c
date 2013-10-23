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
#include "lexico.h"


/* variaveis globais */
int nome_lido_tam;
char nome_lido[ID_TAM_MAX];
token_id_no *inicio_lista_token_id;


/* funções */
void print_token(token* to_print);
void add_char_to_nome_lido(char c);
token* fill_and_return_token(int token1);
/*se não existir: colocar o id na lista e retorna o novo token2
 * se existir: retorna o token2 que estava na lista
 * retorna -1 se deu erro de memória*/
int get_and_check_token2(char* token_id);

int get_and_check_token2(char* token_id)
{
	if(!inicio_lista_token_id) //lista vazia
	{
		inicio_lista_token_id = (token_id_no*) malloc(sizeof(token_id_no*));

		if(!inicio_lista_token_id)
		{
			printf("erro ao alocar memoria");
			return -1;
		}

		inicio_lista_token_id->token2 = 1;
		strcpy(inicio_lista_token_id->valor_id, token_id);
		inicio_lista_token_id->proximo = NULL;
		return 1;
	}

	if(!strcmp(inicio_lista_token_id->valor_id, token_id)) return 1; // é o primeiro da lista

	token_id_no *no_atual = inicio_lista_token_id;
	int token_id_posicao = 2;

	while(no_atual->proximo && !strcmp(no_atual->proximo->valor_id, token_id))
	{
		no_atual = no_atual->proximo;
		++token_id_posicao;
	}

	if(!no_atual) //se no_atual for nulo -> adicionar na lista
	{
		no_atual->proximo = (token_id_no*) malloc(sizeof(token_id_no*));

		if(!no_atual->proximo)
		{
			printf("erro ao alocar memoria");
			return -1;
		}

		no_atual = no_atual->proximo;

		no_atual->token2 = token_id_posicao;
		strcpy(no_atual->valor_id, token_id);
		no_atual->proximo = NULL;
	}

	//senão, o elemento foi encontra -> retorna a posição dele
	return token_id_posicao;
}

token* fill_and_return_token(int token1)
{
	token* token_to_return = (token*) malloc(sizeof(token*));
	if(token_to_return)
	{
		printf("erro ao alocar memória");
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
			token_to_return->token2 = get_and_check_token2(token_to_return->token_valor_id);
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
