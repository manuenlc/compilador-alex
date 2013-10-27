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

int main()
{
	FILE *file = fopen("C:\\Users\\Emanuelle\\workspace c++\\ProjetoCompilador\\teste_lexico_alex.txt", "r");
	int acabou = false;

	if(!file)
	{
		printf("erro ao abrir o arquivo");
		return -1;
	}

	init_arquivo_fonte(file);

	token tk;

	while(!acabou)
	{
		tk = next_token();
		print_token(tk);
		if(tk.token1 == T_EOF) acabou = true;
	}


	return 0;
}
