/*
 * escopo.c
 *
 *      Author: Emanuelle
 */

#include <stdio.h>
#include <stdlib.h>

#include "escopo.h"
#include "gramatica.tab.h"
#include "tokens.h"

simbolo escopo[ALTURA_ESCOPO_MAX][LARGURA_ESCOPO_MAX];
int altura_escopo = -1;
int largura_escopo[LARGURA_ESCOPO_MAX];

/* Declaração de funções*/
void begin_block();
void end_block();
bool search_token2_on_current_scope(int token2);
bool search_symbol_on_current_scope_and_bellow(simbolo simbolo_procurado);
bool insert_var(int token1, int token2);
bool insert_parameter(int token1, int token2);
bool insert_procedure(int token2, int quantidade_parametros, int tipo_retorno, simbolo parametros[QTD_MAX_PARAMETROS] );
bool insert_const(int token1, int token2);

/* compara se o simbolo_procurado é igual ao símbolo de escopo[altura_escopo][largura_escopo] */
bool is_equal(simbolo simbolo_procurado, int altura_escopo, int largura_escopo);
/* insere o simbolo no escopo atual se a quantidade de elementos adicionados não ultrapassar LARGURA_ESCOPO_MAX */
bool insert_symbol(simbolo simbolo_a_inserir);


void begin_block()
{
	if(altura_escopo < ALTURA_ESCOPO_MAX) largura_escopo[++altura_escopo] = 0;
	else printf("limite de altura de escopo atingido\n");
}

void end_block()
{
	if(altura_escopo > 0) largura_escopo[altura_escopo--] = 0;
		else printf("nao ha mais escopo para eliminar\n");
}

bool is_equal(simbolo simbolo_procurado, int altura_escopo, int largura_escopo)
{
	simbolo simbolo_comparado = escopo[altura_escopo][largura_escopo];

	if(simbolo_procurado.tipo_simbolo == simbolo_comparado.tipo_simbolo
		&& simbolo_procurado.token1 == simbolo_comparado.token1
		&& simbolo_procurado.token2 == simbolo_comparado.token2
		&& simbolo_procurado.quantidade_parametros == simbolo_comparado.quantidade_parametros)
	{
		if(simbolo_procurado.quantidade_parametros == 0) return true;
		else
		{
			if(simbolo_procurado.tipo_simbolo != simbolo_comparado.tipo_retorno) return false;

			int i;
			for(i = 0; i < simbolo_procurado.quantidade_parametros; ++i)
			{
				if(simbolo_procurado.parametros[i] != simbolo_comparado.parametros[i])
					return false;
			}
			return true;
		}
	}
	else return false;
}


bool search_token2_on_current_scope(int token2)
{
	int i;
	for(i = 0; i < largura_escopo[altura_escopo]; ++i)
	{
		if(escopo[altura_escopo][i].token2 == token2) return true;
	}

	return false;
}

bool search_symbol_on_current_scope_and_bellow(simbolo simbolo_procurado)
{
	int i, j;

	for(i = altura_escopo; i >= 0 ; --i)
		for(j = 0; j < largura_escopo[altura_escopo]; ++j)
			if(is_equal(simbolo_procurado, i, i)) return true;

	return false;
}

bool insert_symbol(simbolo simbolo_a_inserir)
{
	int posicao = largura_escopo[altura_escopo];
	if(posicao < LARGURA_ESCOPO_MAX)
	{
		escopo[altura_escopo][posicao].tipo_simbolo = simbolo_a_inserir.tipo_simbolo;
		escopo[altura_escopo][posicao].token1 = simbolo_a_inserir.token1;
		escopo[altura_escopo][posicao].token2 =  simbolo_a_inserir.token2;
		escopo[altura_escopo][posicao].quantidade_parametros = simbolo_a_inserir.quantidade_parametros;

		if(simbolo_a_inserir.tipo_simbolo == T_PROCEDURE)
		{
			escopo[altura_escopo][posicao].tipo_retorno = simbolo_a_inserir.tipo_retorno;

			if(simbolo_a_inserir.quantidade_parametros > 0)
			{
				int i;
				for(i = 0; i < simbolo_a_inserir.quantidade_parametros; ++i)
					escopo[altura_escopo][posicao].parametros[i] = simbolo_a_inserir.parametros[i];
			}
		}

		++largura_escopo[altura_escopo];
		return true;
	}
	else
	{
		printf("a quantidade de simbolos para esse escopo atingiu o limite maximo\n");
		return false;
	}
}

bool insert_var(int token1, int token2)
{
	simbolo procurado;
	procurado.tipo_simbolo = T_VAR;
	procurado.token1 = token1;
	procurado.token2 = token2;
	procurado.quantidade_parametros = 0;

	bool achou = search_token2_on_current_scope(token2);

	if(achou) return false; //o simbolo ja esta na tabela
	else return insert_symbol(procurado);

}

bool insert_parameter(int token1, int token2)
{
	simbolo procurado;
	procurado.tipo_simbolo = T_PARAMETER;
	procurado.token1 = token1;
	procurado.token2 = token2;
	procurado.quantidade_parametros = 0;

	bool achou = search_token2_on_current_scope(token2);

	if(achou) return false; //o simbolo ja esta na tabela
	else return insert_symbol(procurado);
}

bool insert_procedure(int token2, int quantidade_parametros,int tipo_retorno, simbolo parametros[QTD_MAX_PARAMETROS] )
{
	simbolo procurado;
	procurado.tipo_simbolo = T_PROCEDURE;
	procurado.token1 = T_PROCEDURE;
	procurado.token2 = token2;
	procurado.quantidade_parametros = quantidade_parametros;
	procurado.tipo_retorno = tipo_retorno;

	bool achou = search_token2_on_current_scope(token2);

	if(achou) return false; //o simbolo ja esta na tabela
	else return insert_symbol(procurado);
}

bool insert_const(int token1, int token2)
{
	simbolo procurado;
	procurado.tipo_simbolo = T_CONST;
	procurado.token1 = token1;
	procurado.token2 = token2;
	procurado.quantidade_parametros = 0;

	bool achou = search_token2_on_current_scope(token2);

	if(achou) return false; //o simbolo ja esta na tabela
	else return insert_symbol(procurado);

}

void print_current_scope()
{
	int i, j;

	for(i = altura_escopo; i >= 0 ; --i)
	{
		for(j = 0; j < largura_escopo[altura_escopo]; ++j)
		{
			simbolo simbolo_atual = escopo[i][j];

			switch (simbolo_atual.tipo_simbolo)
			{
				case T_PROCEDURE:
					printf("tipo: %d token1: %d token2: %d qtdpar: %d retorno: %d",
												simbolo_atual.tipo_simbolo, simbolo_atual.token1,
												simbolo_atual.token2, simbolo_atual.quantidade_parametros,
												simbolo_atual.tipo_retorno);
				break;
			default:
				//case T_VAR:
				//case T_PARAMETER:
				//case T_CONST:
					printf("tipo: %d token1: %d token2: %d qtdpar: %d",
							simbolo_atual.tipo_simbolo, simbolo_atual.token1,
							simbolo_atual.token2, simbolo_atual.quantidade_parametros);
			}
			printf(" -> ");
		}
		printf("\n");
	}

}

int main()
{
	begin_block();

	insert_const(T_INT_CONST, 1);
	print_current_scope();
	insert_var(T_INTEGER, 2);
	print_current_scope();
	insert_parameter(T_BOOLEAN, 3);
	print_current_scope();
	insert_procedure(4, 0, T_REAL, NULL);
	print_current_scope();
	insert_const(T_INT_CONST, 4);
	print_current_scope();


	return 0;
}
