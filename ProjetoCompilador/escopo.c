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
bool search_parameter_or_var_on_current_scope_and_bellow(int token2);
bool search_procedure_on_current_scope_and_bellow(int token2);
bool search_const_on_current_scope_and_bellow(int token2);
bool search_symbol_on_current_scope_and_bellow(simbolo simbolo_procurado);
bool insert_var(int token2, int var_tipo);
bool insert_parameter(int token2, int parametro_tipo);
bool insert_procedure(int token2, int quantidade_argumentos, int *tipo_argumentos);
bool insert_const(int token2, int const_tipo);

/* compara se o simbolo_procurado é igual ao símbolo de escopo[altura_escopo][largura_escopo] */
bool is_equal(simbolo simbolo_procurado, int altura_escopo, int largura_escopo);
/* insere o simbolo no escopo atual se a quantidade de elementos adicionados não ultrapassar LARGURA_ESCOPO_MAX */
bool insert_symbol(simbolo simbolo_a_inserir);

void print_scopes();
void print_current_scope();


void begin_block()
{
	if(altura_escopo < ALTURA_ESCOPO_MAX) largura_escopo[++altura_escopo] = 0;
	else printf("limite de altura de escopo atingido\n");

	printf("novo escopo %d\n", altura_escopo);
}

void end_block()
{
	printf("eliminando escopo %d\n", altura_escopo);
	if(altura_escopo >= 0) largura_escopo[altura_escopo--] = 0;
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
		return true;
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

bool search_procedure_on_current_scope_and_bellow(int token2)
{
	int i, j;

	for(i = altura_escopo; i >= 0 ; --i)
		for(j = 0; j < largura_escopo[i]; ++j)
			if(escopo[i][j].token2 == token2 && escopo[i][j].tipo_simbolo == T_PROCEDURE)
				return true;

	return false;
}

bool search_const_on_current_scope_and_bellow(int token2)
{
	{
		int i, j;

		for(i = altura_escopo; i >= 0 ; --i)
			for(j = 0; j < largura_escopo[i]; ++j)
				if(escopo[i][j].token2 == token2 && escopo[i][j].tipo_simbolo == T_CONST)
					return true;

		return false;
	}
}

bool search_parameter_or_var_on_current_scope_and_bellow(int token2)
{
	int i, j;

	for(i = altura_escopo; i >= 0 ; --i)
		for(j = 0; j < largura_escopo[i]; ++j)
			if(escopo[i][j].token2 == token2 &&
					(escopo[i][j].tipo_simbolo == T_PARAMETER || escopo[i][j].tipo_simbolo == T_VAR))
				return true;

	return false;
}

bool search_symbol_on_current_scope_and_bellow(simbolo simbolo_procurado)
{
	int i, j;

	for(i = altura_escopo; i >= 0 ; --i)
		for(j = 0; j < largura_escopo[i]; ++j)
			if(is_equal(simbolo_procurado, i, j)) return true;

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

		int i;

		if(simbolo_a_inserir.quantidade_parametros > QTD_MAX_PARAMETROS) printf("ultrapassou a quantidade maxima de parametros permitida\n");
		else
		for(i = 0; i < simbolo_a_inserir.quantidade_parametros; ++i)
		{
			escopo[altura_escopo][posicao].tipo_argumentos[i] = simbolo_a_inserir.tipo_argumentos[i];
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

bool insert_var(int token2, int var_tipo)
{
	printf("\ntentando inserir uma variavel de token 2: %d e tipo %d ", token2, var_tipo);
	simbolo procurado;
	procurado.tipo_simbolo = T_VAR;
	procurado.token1 = var_tipo;
	procurado.token2 = token2;
	procurado.quantidade_parametros = 0;

	bool achou = search_token2_on_current_scope(token2);

	if(achou) return false; //o simbolo ja esta na tabela
	else return insert_symbol(procurado);

}

bool insert_parameter(int token2, int parametro_tipo)
{
	printf("\ntentando inserir um parametro de token 2: %d e tipo %d ", token2, parametro_tipo);
	simbolo procurado;
	procurado.tipo_simbolo = T_PARAMETER;
	procurado.token1 = parametro_tipo;
	procurado.token2 = token2;
	procurado.quantidade_parametros = 0;

	bool achou = search_token2_on_current_scope(token2);

	if(achou) return false; //o simbolo ja esta na tabela
	else return insert_symbol(procurado);
}

bool insert_procedure(int token2, int quantidade_argumentos, int *tipo_argumentos)
{
	printf("\ntentando inserir uma procedure de token 2: %d e qtd_args %d ", token2, quantidade_argumentos);
	simbolo procurado;
	procurado.tipo_simbolo = T_PROCEDURE;
	procurado.token1 = T_PROCEDURE;
	procurado.token2 = token2;
	procurado.quantidade_parametros = quantidade_argumentos;

	if(quantidade_argumentos > 0)
	{
		int i;
		for(i = 0; i < quantidade_argumentos; ++i)
		{
			printf("arg tk2: %d | ", tipo_argumentos[i]);
			procurado.tipo_argumentos[i] = tipo_argumentos[i];
		}
		printf("\n");
	}

	bool achou = search_token2_on_current_scope(token2);

	if(achou) return false; //o simbolo ja esta na tabela
	else return insert_symbol(procurado);
}

bool insert_const(int token2, int const_tipo)
{
	printf("\ntentando inserir uma constante de token 2: %d ", token2);
	simbolo procurado;
	procurado.tipo_simbolo = T_CONST;
	procurado.token1 = const_tipo;
	procurado.token2 = token2;
	procurado.quantidade_parametros = 0;

	bool achou = search_token2_on_current_scope(token2);

	if(achou) return false; //o simbolo ja esta na tabela
	else return insert_symbol(procurado);

}

void print_current_scope()
{
	int i;

	for(i = 0; i < largura_escopo[altura_escopo]; ++i)
	{
		simbolo simbolo_atual = escopo[altura_escopo][i];

		switch (simbolo_atual.tipo_simbolo)
		{
		case T_PROCEDURE:
			printf("tipo: %d token1: %d token2: %d qtdpar: %d ",
								simbolo_atual.tipo_simbolo, simbolo_atual.token1,
								simbolo_atual.token2, simbolo_atual.quantidade_parametros);
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

	printf("#\n");


}

void print_scopes()
{
	int i, j;

	for(i = altura_escopo; i >= 0 ; --i)
	{
		for(j = 0; j < largura_escopo[i]; ++j)
		{
			simbolo simbolo_atual = escopo[i][j];

			switch (simbolo_atual.tipo_simbolo)
			{
			case T_PROCEDURE:
				printf("tipo: %d token1: %d token2: %d qtdpar: %d",
						simbolo_atual.tipo_simbolo, simbolo_atual.token1,
						simbolo_atual.token2, simbolo_atual.quantidade_parametros);
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
		printf("#\n");
	}

	printf("\n");

}

/*
int main()
{
	begin_block();

	insert_const(1, T_INT_CONST);
	print_current_scope();


	insert_var(2, T_BOOLEAN);
	print_current_scope();


	insert_parameter(3, T_INTEGER);
	print_current_scope();

	printf("\n\n\n");
	begin_block();


	insert_procedure(4, 0, T_REAL, NULL);
	print_current_scope();


	insert_const(5, T_INTEGER);
	print_current_scope();

	printf("\n\n\n");
	print_scopes();

	printf("heloo ");

	return 0;

}
*/
