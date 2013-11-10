/*
 * tipo.c
 *
 *  Created on: 10/11/2013
 *      Author: Emanuelle
 */

#include "tipo.h"
#include "gramatica.tab.h"
#include <stdio.h>

int result_type(int operando1, int operando2, int operacao);
;

int result_type(int operando1, int operando2, int operacao)
{
	printf("operandos: %d %d operacao: %d\n", operando1, operando2, operacao);
	switch(operacao)
	{
	case T_PLUS:
	case T_TIMES:
	case T_MINUS:
	case T_DIVIDE:
		switch(operando1)
		{
		case T_INTEGER:
		case T_INT_CONST:
			if(operando2 == T_INTEGER || operando2 == T_INT_CONST ) return T_INTEGER;
			else if(operando2 == T_REAL || operando2 == T_REAL_CONST) return T_REAL;
			else return T_INVALID;
			/* no break */
		case T_REAL:
		case T_REAL_CONST:
			if(operando2 == T_INTEGER || operando2 == T_INT_CONST || operando2 == T_REAL || operando2 == T_REAL_CONST) return T_REAL;
			else return T_INVALID;
		default:
			return T_INVALID;
		}
		/* no break */
	case T_AND:
	case T_OR:
		switch(operando1)
		{
		case T_BOOLEAN:
		case T_BOOLEAN_CONST:
			if(operando2 == T_BOOLEAN || operando2 == T_BOOLEAN_CONST) return T_BOOLEAN;
			else return T_INVALID;
		default:
			return T_INVALID;
		}
		/* no break */
	case T_LT:
	case T_GT:
	case T_GEQ:
	case T_LEQ:
		switch(operando1)
		{
		case T_INTEGER:
		case T_INT_CONST:
			if(operando2 == T_INTEGER || operando2 == T_INT_CONST) return T_INTEGER;
			else return T_INVALID;
		case T_REAL:
		case T_REAL_CONST:
			if(operando2 == T_REAL || operando2 == T_REAL_CONST) return T_REAL;
			else return T_INVALID;
		default:
			return T_INVALID;
		}
		/* no break */
	case T_DIF:
	case T_EQ:
		switch(operando1)
		{
		case T_BOOLEAN:
		case T_BOOLEAN_CONST:
			if(operando2 == T_BOOLEAN || operando2 == T_BOOLEAN_CONST) return T_BOOLEAN;
			else return T_INVALID;
			/* no break */
		case T_INTEGER:
		case T_INT_CONST:
			if(operando2 == T_INTEGER || operando2 == T_INT_CONST ) return T_BOOLEAN;
			else return T_INVALID;
		case T_REAL:
		case T_REAL_CONST:
			if(operando2 == T_REAL || operando2 == T_REAL_CONST ) return T_BOOLEAN;
			else return T_INVALID;
		default:
			return T_INVALID;
		}
		/* no break */
	case T_DIV:
	case T_MOD:
		switch(operando1)
		{
		case T_INTEGER:
		case T_INT_CONST:
			if(operando2 == T_INTEGER || operando2 == T_INT_CONST ) return T_INTEGER;
			else return T_INVALID;
		default:
			return T_INVALID;
		}
		/* no break */
	case T_NOT:
		switch(operando1)
		{
		case T_BOOLEAN:
		case T_BOOLEAN_CONST:
			if(operando2 == T_EOF) return T_BOOLEAN;
			else return T_INVALID;
		default:
			return T_INVALID;
		}
		/* no break */
	case T_EOF:
		return operando1;
	default:
		return T_INVALID;
	}

}

