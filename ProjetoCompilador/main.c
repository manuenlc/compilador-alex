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

#include "tipo.h"
#include "gramatica.tab.h"

extern int yyparse(void);


int main()
{
	FILE *file = fopen("C:\\Users\\Emanuelle\\workspace c++\\ProjetoCompilador\\teste_tipo.txt", "r");

	if(!file)
	{
		printf("erro ao abrir o arquivo");
		return -1;
	}

	init_arquivo_fonte(file);


/*
	int acabou = false;

	token tk;

	while(!acabou)
	{
		tk = next_token();
		print_token(tk);

		if(tk.token1 == T_EOF) acabou = true;
	}

*/
	printf("compilando...\n");

	if(!yyparse()) puts("compilado!");
	else puts("compilacao falhou!");


	return 0;
}

