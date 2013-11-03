%{

#include "lexico.h"
#include "tokens.h"
#include "escopo.h"
#include "gramatica.tab.h"
#include "boolean.h"

extern int yylex(void);
extern int yyerror(char*);

int quantidade_arg = 0;
int arg_token2[20];
int arg_token1[20];
int quantidade_arg_adicionados = 0;
int quantidade_var = 0;
int var_token2[20];
bool eh_declaracao_procedure;
int type_atual;
int procedure_token2;


%}

%union 
{
    int token1;
	int token2;
    int token_valor_int;
	char token_valor_id[64];
    float token_valor_real;
    int token_valor_boolean;
}

%token T_EOF                  0
%token T_ID                   1
%token T_INT_CONST            2
%token T_REAL_CONST           3
%token T_BOOLEAN_CONST        4
%token T_PROGRAM              5
%token T_PROCEDURE            6
%token T_BEGIN                7
%token T_END                  8
%token T_IF                   9
%token T_THEN                 10
%token T_ELSE                 11
%token T_WHILE                12
%token T_DO                   13
%token T_ASSIGN               14
%token T_PLUS                 15
%token T_MINUS                16
%token T_TIMES                17
%token T_DIVIDE               18
%token T_DIV                  19
%token T_MOD                  20
%token T_PLUS_EQ              21
%token T_MINUS_EQ             22
%token T_TIMES_EQ             23
%token T_AND                  24
%token T_OR                   25
%token T_NOT                  26
%token T_DIVIDE_EQ            27
%token T_VAR                  28
%token T_INTEGER              29
%token T_REAL                 30
%token T_BOOLEAN              31
%token T_COLON                32
%token T_SEMICOLON            33
%token T_COMMA                34
%token T_PERIOD               35
%token T_DOUBLE_PERIOD        36
%token T_LBRACKET             37
%token T_RBRACKET             38
%token T_CONST                39
%token T_REPEAT               40
%token T_UNTIL                41
%token T_EQ                   42
%token T_DIF                  43
%token T_LT                   44
%token T_LEQ                  45
%token T_GT                   46
%token T_GEQ                  47
%token T_PARAMETER			  48
%token T_VOID				  49
%token T_INVALID             255


%no-lines

%right T_THEN T_ELSE

%type<token1> type relational_operator sign_operator multiplying_operator
%type<token2> T_ID  
%type<token_valor_real> T_REAL_CONST
%type<token_valor_int> T_INT_CONST
%type<token_valor_boolean> T_BOOLEAN_CONST



%%
input: T_PROGRAM T_ID T_SEMICOLON new_block block_body T_PERIOD
;

new_block: 
{
	begin_block();
}
;

block_body: opt_constant_definition_part opt_variable_definition_part star_procedure_definition compound_statement
{
	end_block()
}
;

opt_constant_definition_part:
                            | constant_definition_part
;

opt_variable_definition_part: 
                            | variable_definition_part  
;

star_procedure_definition:
{
	eh_declaracao_procedure = false;
	printf("\nfim de declaracao de procedure\n");
} 
                         | set_procedure_definition procedure_definition star_procedure_definition
;

set_procedure_definition :
{
	eh_declaracao_procedure = true;
	printf("\ndeclaracao de procedure\n");
} 
;

constant_definition_part: T_CONST plus_constant_definition
;

plus_constant_definition: constant_definition 
                        | constant_definition plus_constant_definition
;

constant_definition: T_ID T_EQ T_INT_CONST T_SEMICOLON
{	
		 
		if(!insert_const($1, T_INTEGER))
		{
			printf("ERRO: Redefinicao do simbolo %s na linha %d", get_token2_id($1), get_line());
			YYERROR;
		}		
}
                   | T_ID T_EQ T_REAL_CONST T_SEMICOLON
{	
		if(!insert_const($1, T_REAL))
		{
			printf("ERRO: Redefinicao do simbolo %s na linha %d", get_token2_id($1), get_line());
			YYERROR;
		}		
} 
                   | T_ID T_EQ T_BOOLEAN_CONST T_SEMICOLON
{		
		if(!insert_const($1, T_BOOLEAN))
		{
			printf("ERRO: Redefinicao do simbolo %s na linha %d", get_token2_id($1), get_line());
			YYERROR;
		}
}
;

variable_definition_part: T_VAR plus_variable_definition
;

plus_variable_definition: variable_definition 
                        | variable_definition plus_variable_definition
;

variable_definition: variable_group T_SEMICOLON
;

variable_group: T_ID star_comma_id T_COLON type
{	
	var_token2[quantidade_var] = $1;
	++quantidade_var;
	
	int i;
	
	 
	for(i = quantidade_var - 1; i > -1; --i)
	{
		if(!insert_var(var_token2[i], $4))
		{
			printf("ERRO: Redefinicao do simbolo %s na linha %d", get_token2_id(var_token2[i]), get_line());
			YYERROR;
		}
	}
	quantidade_var = 0;	
}
;

star_comma_id: 
             | T_COMMA T_ID star_comma_id
{
	var_token2[quantidade_var] = $2;
	++quantidade_var;
	
}
;

type: T_INTEGER
{
	$$ = T_INTEGER;
}
    | T_REAL
{
	$$ = T_REAL;
}
    | T_BOOLEAN
{
	$$ = T_BOOLEAN;
}
;

procedure_definition: procedure_block block_body T_SEMICOLON
;

procedure_block: init_procedure opt_brc_formal_parameter_list_brc T_SEMICOLON
;

init_procedure: T_PROCEDURE T_ID
{
	procedure_token2 = $2;
}
;

opt_brc_formal_parameter_list_brc:
{
	if(!insert_procedure(procedure_token2, 0 , NULL))
	{
		printf("ERRO: Redefinicao do simbolo %s na linha %d", get_token2_id(procedure_token2), get_line());
		YYERROR;
	}
	
	begin_block();
	
}
                                 | T_LBRACKET formal_parameter_list T_RBRACKET
{

	if(!insert_procedure(procedure_token2, quantidade_arg_adicionados, arg_token2))
	{
		printf("ERRO: Redefinicao do simbolo %s na linha %d", get_token2_id(procedure_token2), get_line());
		YYERROR;
	}
	
	begin_block();
	
	int i;
	
	for(i = 0; i < quantidade_arg_adicionados; ++i)
	{
		
		if(!insert_parameter(arg_token2[i], arg_token1[i]))
		{
			printf("ERRO: Redefinicao do simbolo %s na linha %d", get_token2_id(arg_token2[i]), get_line());
			YYERROR;
		}
	}
	
	quantidade_arg_adicionados = 0;
}
;

formal_parameter_list: parameter_definition star_smc_parameter_definition
;

star_smc_parameter_definition:
                             | T_SEMICOLON parameter_definition star_smc_parameter_definition
;

parameter_definition: variable_group_par
;

variable_group_par: T_ID star_comma_id_par T_COLON type
{	
	arg_token2[quantidade_arg++] = $1;
	
	int i;
	for(i = quantidade_arg_adicionados; i < quantidade_arg; ++i)
	{
		arg_token1[i] = $4;
	}
	quantidade_arg_adicionados = quantidade_arg;
}
;

star_comma_id_par: 
             | T_COMMA T_ID star_comma_id_par
{
	arg_token2[quantidade_arg++] = $2;
	

}
;

statement: 
         | procedure_statement
         | if_statement
         | while_statement
         | compound_statement
         | assignment_statement
;

assignment_statement: variable_access T_ASSIGN expression
;

procedure_statement: T_ID opt_brc_actual_parameter_list_brc
;

opt_brc_actual_parameter_list_brc:
                                 | T_LBRACKET actual_parameter_list T_RBRACKET
;

actual_parameter_list: actual_parameter star_comma_actual_parameter
;

star_comma_actual_parameter: 
                          | T_COMMA actual_parameter star_comma_actual_parameter
;

actual_parameter: expression
;

if_statement: T_IF expression T_THEN statement
            | T_IF expression T_THEN statement T_ELSE statement
;

while_statement: T_WHILE expression T_DO statement
;


compound_statement: T_BEGIN statement star_comma_statement T_END
;

star_comma_statement: 
                    | T_SEMICOLON statement star_comma_statement
;

expression: simple_expression opt_relational_operator_simple_expression
;

opt_relational_operator_simple_expression: 
                                         | relational_operator simple_expression
;

relational_operator: T_LT  { $$ = T_LT;  }
                   | T_EQ  { $$ = T_EQ;  }
                   | T_GT  { $$ = T_GT;  }
                   | T_LEQ { $$ = T_LEQ; }
                   | T_DIF { $$ = T_DIF; }
                   | T_GEQ { $$ = T_GEQ; }
;

simple_expression: sign_operator term star_adding_operator_term
                 | term star_adding_operator_term
;

sign_operator: T_PLUS { $$ = T_PLUS; }
             | T_MINUS { $$ = T_MINUS; }
;

star_adding_operator_term:
                         | adding_operator term star_adding_operator_term
;

adding_operator: T_PLUS
               | T_MINUS
               | T_OR
;

term: factor star_multiplying_operator_factor
;

star_multiplying_operator_factor:
                                | multiplying_operator factor star_multiplying_operator_factor
;

multiplying_operator: T_TIMES  { $$ = T_TIMES;  } 
                    | T_DIV    { $$ = T_DIV;    }
                    | T_MOD    { $$ = T_MOD;    }
                    | T_AND    { $$ = T_AND;    }
                    | T_DIVIDE { $$ = T_DIVIDE; }
;

factor: constant
      | T_LBRACKET expression T_RBRACKET
      | T_NOT factor
;

variable_access: T_ID
{
	
	if(!search_token2_on_current_scope_and_bellow($1))
	{
		printf("ERRO: O simbolo %s eh utilizado na linha %d mas n�o foi declarado\n", get_token2_id($1), get_line());
		//YYERROR;
	}
}
;

constant: T_INT_CONST
        | T_REAL_CONST
        | T_BOOLEAN_CONST
        | variable_access
;
%%