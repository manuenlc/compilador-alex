/*
 * escopo.h
 *
 *  Created on: 31/10/2013
 *      Author: Emanuelle
 */

#ifndef ESCOPO_H_
#define ESCOPO_H_

#include "boolean.h"

#define ALTURA_ESCOPO_MAX	20
#define LARGURA_ESCOPO_MAX	100
#define QTD_MAX_PARAMETROS	20

#define T_PARAMETER			48

typedef struct simbolo
{
	int tipo_simbolo; //parameter, const, var, procedure
	int token1;
	int token2;

	int quantidade_parametros; //para procedures
	simbolo parametros[QTD_MAX_PARAMETROS];

} simbolo;


void begin_block();
void end_block();
/** retorna true (1) se achou o simbolo no escopo atual
 *  retorna false (0) caso contrário*/
bool seach_symbol_on_current_scope(simbolo simbolo_procurado);
bool seach_symbol_on_current_scope_and_bellow(simbolo simbolo_procurado);

/** retorna true (1) se o simbolo foi adicionado no escopo atual
 * retorna false (0) caso contrário
 * */
bool insert_var(int token1, int token2);
bool insert_parameter(int token1, int token2);
bool insert_procedure(int token2, int quantidade_parametros, simbolo parametros[QTD_MAX_PARAMETROS] );
bool insert_const(int token1, int token2);

#endif /* ESCOPO_H_ */
