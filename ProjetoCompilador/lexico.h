/*
 * lexico.h
 *
 *      Author: Emanuelle
 */

#ifndef LEXICO_H_
#define LEXICO_H_

# include "tokens.h"
# include "boolean.h"


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


#endif /* LEXICO_H_ */
