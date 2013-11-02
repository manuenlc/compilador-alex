/*
 * lexico.h
 *
 *      Author: Emanuelle
 */

#ifndef LEXICO_H_
#define LEXICO_H_

#include <stdio.h>

# include "tokens.h"
# include "boolean.h"
# include "gramatica.tab.h"


typedef struct token_id_info
{
	int token2;
	char valor_id[ID_TAM_MAX];
} token_id_info;


/** funções */

/** retorna o token lido */
token next_token();

/** imprime as informações do token no console*/
void print_token(token to_print);

/** inicializa o arquivo que será lio por next_token()*/
void init_arquivo_fonte(FILE *arquivo_input);

/** retorna a linha atual */
int get_line();

/** retorna a string associada ao token2 de um YYSTYPE */
char *get_token2_id(int token2);

/** funções geradas pelo bison */
int yylex(void);
int yyerror(char* error_description);


#endif /* LEXICO_H_ */
