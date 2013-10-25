/*
 * main.c
 *
 *  Created on: 23/10/2013
 *      Author: Emanuelle
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tokens.h"
#include "boolean.h"
#include "lexico.h"

/*
int main()
{
	token* tk = (token*) malloc(sizeof(token*));
	if(!tk) {printf("erro ao alocar memoria"); return -1;}

	tk->token1 = T_BOOLEAN_CONST;
	tk->token2 = 10;
	tk->token_valor_int = 20;
	tk->token_valor_real = 13.2;
	tk->token_valor_boolean = false;
	strcpy(tk->token_valor_id, "hello");

	print_token(tk);

	free(tk);

	return 0;
}

*/
