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
static token_id_info array_tokens_id[ID_QTD_MAX];
int qtd_token_id = 0;
static FILE *arquivo_fonte = NULL;
int eh_comentario = false;


/* funções */
void print_token(token to_print);
void add_char_to_nome_lido(char c);
char next_char();
void init_arquivo_fonte(FILE *arquivo_input);
void close_arquivo_fonte();
token fill_and_return_token(int token1);
token token_reserved_word();
token token_ponctuation(char c);
token token_id_or_reserved_word(char c);
/* quando entrar em uma região de comentário, esse método retornará o próximo token depois do comentário*/
token jump_comments(char c);
token token_int_real_or_invalid(char c);
/* volta uma posição na posição atual do arquivo arquivo_fonte*/
void go_back_the_char_read();
/*se não existir: colocar o id na lista e retorna o novo token2
 * se existir: retorna o token2 que estava na lista
 * retorna -1 se deu erro de memória*/
int get_and_check_token2(char* token_id);


/*implementação das funções */

void init_arquivo_fonte(FILE *arquivo_input)
{
	if(arquivo_input == NULL) printf("arquivo invalido!");
	else arquivo_fonte = arquivo_input;
}

void close_arquivo_fonte()
{
	close(arquivo_fonte);
	qtd_token_id = 0;
}

int get_and_check_token2(char* token_id)
{

	int token_id_posicao = 0;

	while(token_id_posicao < qtd_token_id
			&& strcmp(array_tokens_id[token_id_posicao].valor_id, token_id))
		++token_id_posicao;

	if(token_id_posicao >= qtd_token_id) //não encontrou o token -> adiciona no array
	{
		if(qtd_token_id < ID_QTD_MAX)
		{
			++qtd_token_id;
			array_tokens_id[token_id_posicao].token2 = qtd_token_id;
			strcpy(array_tokens_id[token_id_posicao].valor_id, token_id);
			return qtd_token_id;
		}
	}

	return array_tokens_id[token_id_posicao].token2; //senão, o elemento foi encontrado -> retorna a posição dele
}

token fill_and_return_token(int token1)
{
	nome_lido[nome_lido_tam++] = '\0';

	token token_to_return;

	token_to_return.token1 = token1;

	switch (token1)
	{
		case T_INT_CONST:
			token_to_return.token_valor_int = atoi(nome_lido);
			strcpy(token_to_return.token_valor_id, "");
			break;
		case T_BOOLEAN_CONST:
			if(!strcmp("false", nome_lido)) token_to_return.token_valor_boolean = false;
			else token_to_return.token_valor_boolean = true;
			strcpy(token_to_return.token_valor_id, "");
			break;
		case T_REAL_CONST:
			token_to_return.token_valor_real = (float) atof(nome_lido);
			strcpy(token_to_return.token_valor_id, "");
			break;
		case T_ID:
			strcpy(token_to_return.token_valor_id, nome_lido);
			token_to_return.token2 = get_and_check_token2(token_to_return.token_valor_id);
			break;
		case T_EOF:
			strcpy(token_to_return.token_valor_id, "");
			close_arquivo_fonte();
			break;
		default:
			strcpy(token_to_return.token_valor_id, "");
			break;
	}
	return token_to_return;
}

token jump_comments(char c)
{
	while(eh_comentario)
	{
		if(c == '}') eh_comentario = false;
		else
		{
			if(c == '*')
			{
				c = next_char();
				if(c== ')')	eh_comentario = false;

			}else
			{
				if(c == EOF)
				{
					eh_comentario = false;
					return fill_and_return_token(T_EOF);
				}

				c = next_char();
			}
		}
	}

	return next_token();
}

void add_char_to_nome_lido(char c)
{
	if(nome_lido_tam > ID_TAM_MAX - 1) printf("nome maior que o máximo permitido");
	else
	{
		nome_lido[nome_lido_tam++] = c;
	}
}

void print_token(token to_print)
{
	printf("%d\t\t", to_print.token1);

	switch (to_print.token1)
	{
		case T_INT_CONST:
			printf(" \t\t%d", to_print.token_valor_int);
			break;
		case T_BOOLEAN_CONST:
			if(to_print.token_valor_boolean) printf(" \t\ttrue");
			else printf(" \t\tfalse");
			break;
		case T_REAL_CONST:
			printf(" \t\t%f", to_print.token_valor_real);
			break;
		case T_ID:
			printf("%d\t\t", to_print.token2);
			printf("%s", to_print.token_valor_id);
			break;
		default:
			printf("%s", to_print.token_valor_id);
			break;
	}

		printf("\n");
}

token token_reserved_word()
{
	nome_lido[nome_lido_tam++] = '\0';

	if(!strcmp(nome_lido, "program")) return fill_and_return_token(T_PROGRAM);
	else if(!strcmp(nome_lido,"procedure")) return fill_and_return_token(T_PROCEDURE);
	else if(!strcmp(nome_lido,"begin")) return fill_and_return_token(T_BEGIN);
	else if(!strcmp(nome_lido,"end")) return fill_and_return_token(T_END);
	else if(!strcmp(nome_lido,"if")) return fill_and_return_token(T_IF);
	else if(!strcmp(nome_lido,"then")) return fill_and_return_token(T_THEN);
	else if(!strcmp(nome_lido,"else")) return fill_and_return_token(T_ELSE);
	else if(!strcmp(nome_lido,"while")) return fill_and_return_token(T_WHILE);
	else if(!strcmp(nome_lido,"do")) return fill_and_return_token(T_DO);
	else if(!strcmp(nome_lido,"div")) return fill_and_return_token(T_DIV);
	else if(!strcmp(nome_lido,"mod")) return fill_and_return_token(T_MOD);
	else if(!strcmp(nome_lido,"and")) return fill_and_return_token(T_AND);
	else if(!strcmp(nome_lido,"or")) return fill_and_return_token(T_OR);
	else if(!strcmp(nome_lido,"not")) return fill_and_return_token(T_NOT);
	else if(!strcmp(nome_lido,"var")) return fill_and_return_token(T_VAR);
	else if(!strcmp(nome_lido,"real")) return fill_and_return_token(T_REAL);
	else if(!strcmp(nome_lido,"integer")) return fill_and_return_token(T_INTEGER);
	else if(!strcmp(nome_lido,"boolean")) return fill_and_return_token(T_BOOLEAN);
	else if(!strcmp(nome_lido,"const")) return fill_and_return_token(T_CONST);
	else if(!strcmp(nome_lido,"repeat")) return fill_and_return_token(T_REPEAT);
	else if(!strcmp(nome_lido,"until")) return fill_and_return_token(T_UNTIL);
	else if(!strcmp(nome_lido,"true")) return fill_and_return_token(T_BOOLEAN_CONST);
	else if(!strcmp(nome_lido,"false")) return fill_and_return_token(T_BOOLEAN_CONST);
	else return fill_and_return_token(T_ID);
}

token token_ponctuation(char c)
{
	switch(c)
	{
	case '+': return fill_and_return_token(T_PLUS);
	case '-': return fill_and_return_token(T_MINUS);
	case '*': return fill_and_return_token(T_TIMES);
	case '/': return fill_and_return_token(T_DIVIDE);
	case '=': return fill_and_return_token(T_EQ);
	case ';': return fill_and_return_token(T_SEMICOLON);
	case ',': return fill_and_return_token(T_COMMA);
	case '(':
		c = next_char();
		if(c != '*') return fill_and_return_token(T_LBRACKET); //voltar 1
		/* no break */
	case '{':
		eh_comentario = true;
		return next_token();
	case ')': return fill_and_return_token(T_RBRACKET);
	case '<':
		c = next_char();
		if(c == '=') return fill_and_return_token(T_LEQ);
		else if(c == '>') return fill_and_return_token(T_DIF);
		else
		{
			go_back_the_char_read();
			return fill_and_return_token(T_LT);
		}
	case '>':
		c = next_char();
		if(c == '=') return fill_and_return_token(T_GEQ);
		else
		{
			go_back_the_char_read();
			return fill_and_return_token(T_GT);
		}
	case ':':
		c = next_char();
		if(c == '=') return fill_and_return_token(T_ASSIGN);
		else
		{
			go_back_the_char_read();
			return fill_and_return_token(T_COLON);
		}
	case '.':
		c = next_char();
		if(c == '.') return fill_and_return_token(T_DOUBLE_PERIOD);
		else
		{
			go_back_the_char_read();
			return fill_and_return_token(T_PERIOD);
		}
	default :
		return fill_and_return_token(T_INVALID);
	}

}

token token_int_real_or_invalid(char c)
{
	while(isdigit(c))
	{
		add_char_to_nome_lido(c);
		c = next_char();
	}

	if(isalpha(c))
	{
		while(isalpha(c) || isdigit(c)) c = next_char(); //ignora os caracteres lidos (variável não pode começar com dígito)

		return fill_and_return_token(T_INVALID);
	}

	if(c != '.' && (isspace(c) || ispunct(c))) //retorna um número inteiro
	{
		go_back_the_char_read();
		return fill_and_return_token(T_INT_CONST);
	}

	if(c == '.') //pode ser float ou inválido
	{
		add_char_to_nome_lido(c);
		c = next_char();

		while(isdigit(c))
		{
			add_char_to_nome_lido(c);
			c = next_char();
		}

		if(isalpha(c))
		{
			while(isalpha(c) || isdigit(c)) c = next_char(); //ignora caracteres inválidos

			return fill_and_return_token(T_INVALID);
		}

		go_back_the_char_read();
		return fill_and_return_token(T_REAL_CONST);
	}

	return fill_and_return_token(T_INVALID);
}

token token_id_or_reserved_word(char c)
{
	add_char_to_nome_lido(c);
	c = next_char();

	while(isalpha(c))
	{
		add_char_to_nome_lido(c);
		c = next_char();
	}

	if(isdigit(c) || c=='_' )
	{
		while(isdigit(c) || c == '_' || isalpha(c)) //é variável
		{
			add_char_to_nome_lido(c);
			c = next_char();
		}

		return fill_and_return_token(T_ID);
	}
	else
	{
		return token_reserved_word();
	}

}

void go_back_the_char_read()
{
	int result = fseek(arquivo_fonte, -1,SEEK_CUR);
	if(result) printf("erro ao tentar voltar 1 char");

}

char next_char()
{
	return tolower(fgetc(arquivo_fonte));
}

token next_token()
{
	nome_lido_tam = 0;
	char c = next_char();

	if(eh_comentario) return jump_comments(c);

	while(isspace(c)) c = next_char();

	if(c == EOF) return fill_and_return_token(T_EOF);

	if(isdigit(c)) return token_int_real_or_invalid(c);

	if(isalpha(c)) return token_id_or_reserved_word(c);

	if(ispunct(c)) return token_ponctuation(c);

	return fill_and_return_token(T_INVALID);
}
