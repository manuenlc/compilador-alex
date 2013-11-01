/*
 * escopo.c
 *
 *      Author: Emanuelle
 */

#include <stdio.h>
#include <stdlib.h>

#include "escopo.h"


simbolo escopo[ALTURA_ESCOPO_MAX][LARGURA_ESCOPO_MAX];
int altura_escopo = 0;

/* Declaração de funções*/
void begin_block();
void end_block();
bool seach_symbol_on_current_scope(simbolo simbolo_procurado);
bool seach_symbol_on_current_scope_and_bellow(simbolo simbolo_procurado);
bool insert_var(int token1, int token2);
bool insert_parameter(int token1, int token2);
bool insert_procedure(int token2, int quantidade_parametros, simbolo parametros[QTD_MAX_PARAMETROS] );
bool insert_const(int token1, int token2);


void begin_block()
{
	if(altura_escopo < ALTURA_ESCOPO_MAX) ++altura_escopo;
	else printf("limite de altura de escopo atingido\n");
}

void end_block()
{
	if(altura_escopo > 0) --altura_escopo;
		else printf("nao ha mais escopo para eliminar\n");
}


bool seach_symbol_on_current_scope(simbolo simbolo_procurado)
{
	printf("ToDo");
	return false;
}

bool seach_symbol_on_current_scope_and_bellow(simbolo simbolo_procurado)
{
	printf("ToDo");
	return false;
}

bool insert_var(int token1, int token2)
{
	printf("ToDo");
	return false;
}

bool insert_parameter(int token1, int token2)
{
	printf("ToDo");
	return false;
}

bool insert_procedure(int token2, int quantidade_parametros, simbolo parametros[QTD_MAX_PARAMETROS] )
{
	printf("ToDo");
	return false;
}

bool insert_const(int token1, int token2)
{
	printf("ToDo");
	return false;
}
