/*
 * tipo.h
 *
 *      Author: Emanuelle
 */

#ifndef TIPO_H_
#define TIPO_H_

typedef struct expressao
{
	int operacao;
	int tipo_operando1;
	int tipo_operando2;


} expressao;

int result_type(int operando1, int operando2, int operacao);

#endif /* TIPO_H_ */
