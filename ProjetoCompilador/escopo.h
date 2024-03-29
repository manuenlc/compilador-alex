/*
 * escopo.h
 *
 *  Created on: 31/10/2013
 *      Author: Emanuelle
 */

#ifndef ESCOPO_H_
#define ESCOPO_H_

#include "boolean.h"
#include "gramatica.tab.h"

#define ALTURA_ESCOPO_MAX	20
#define LARGURA_ESCOPO_MAX	100
#define QTD_MAX_PARAMETROS	20


typedef struct simbolo
{
	int tipo_simbolo; //parameter, const, var, procedure
	int token1;

	int token2;

	int quantidade_parametros; //para procedures
	int tipo_argumentos[20]; //token 1 do tipo de parametro

} simbolo;

void begin_block();
void end_block();
/** retorna true (1) se achou o simbolo no escopo atual
 *  retorna false (0) caso contrário*/
bool search_token2_on_current_scope(int token2);
bool search_parameter_or_var_on_current_scope_and_bellow(int token2);
bool search_procedure_on_current_scope_and_bellow(int token2);
bool search_const_on_current_scope_and_bellow(int token2);
bool search_symbol_on_current_scope_and_bellow(simbolo simbolo_procurado);

/** retorna true (1) se o simbolo foi adicionado no escopo atual
 * retorna false (0) caso contrário
 * */
bool insert_var(int token2, int var_tipo);
bool insert_parameter(int token2, int parametro_tipo);
bool insert_procedure(int token2, int quantidade_argumentos, int *tipo_argumentos);
bool insert_const(int token2, int const_tipo);
bool insert_procedure_print(int procedure_print_token2);

void print_current_scope();

/** retorna o tipo associado a um token_id*/
int get_token_type(int token2);

bool check_procedure_usage(int token2, int qtd_parametros, int *tipo_argumentos);

#endif /* ESCOPO_H_ */
