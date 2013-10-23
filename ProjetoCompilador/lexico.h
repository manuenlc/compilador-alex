/*
 * lexico.h
 *
 *      Author: Emanuelle
 */

#ifndef LEXICO_H_
#define LEXICO_H_

# include "tokens.h"
# include "boolean.h"


typedef struct token_no
{
	token *token_atual;
	struct token_no *proximo_token;
} token_no;


/** fun��es */

/** retorna o token lido */
token* next_token();

/** imprime as informa��es do token no console*/
void print_token(token* to_print);


#endif /* LEXICO_H_ */
