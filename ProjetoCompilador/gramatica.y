%{

#include "lexico.h"
#include "tokens.h"

extern int yylex(void);
extern int yyerror(char*);

%}

%union 
{
    int token1;
	int token2;
    int token_valor_int;
	char token_valor_id[ID_TAM_MAX];
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
%token T_INVALID             255

%right T_THEN T_ELSE

%%
input: T_PROGRAM T_ID T_SEMICOLON block_body T_PERIOD
;
block_body: 
	constant_definition_part 
	variable_definition_part opt_procedure_definition 
	compound_statement
;
constant_definition_part: 
	| T_CONST constant_definition opt_constant_definition
;
constant_definition: T_ID T_EQ constant T_SEMICOLON
;
variable_definition_part: 
	| T_VAR variable_definition opt_variable_definition
;
variable_definition: variable_group T_SEMICOLON
;
variable_group:	
	T_ID opt_id T_COLON type
;
type: T_INTEGER | T_BOOLEAN | T_REAL 
;
procedure_definition: 	
	T_PROCEDURE T_ID procedure_block T_SEMICOLON
;
procedure_block: T_SEMICOLON block_body
	| T_LBRACKET formal_parameter_list T_RBRACKET T_SEMICOLON block_body
;
formal_parameter_list:
	parameter_definition opt_parameter_definition
;
parameter_definition: variable_group
;
statement: 
	assignment_statement | procedure_statement |
	if_statement | while_statement |
    compound_statement |
;
assignment_statement: 
	variable_access T_ASSIGN expression
;
procedure_statement: 
	T_ID | T_ID T_LBRACKET actual_parameter_list T_RBRACKET
;
actual_parameter_list: 
	actual_parameter opt_actual_parameter
;
actual_parameter: expression
;
if_statement: 
	T_IF expression T_THEN statement
	| T_IF expression T_THEN statement T_ELSE statement
;
while_statement: 
	T_WHILE expression T_DO statement
;
compound_statement: 
	T_BEGIN statement opt_statement T_END
;
expression: simple_expression 
	| simple_expression relational_operator simple_expression
;
relational_operator: 
	T_LT | T_EQ | T_GT | T_LEQ | T_DIF | T_GEQ
;
simple_expression: term opt_adding_operator
	| sign_operator term opt_adding_operator
;
sign_operator: T_PLUS | T_MINUS
;
adding_operator: T_PLUS | T_MINUS | T_OR
;
term: factor opt_multiplying_operator
;
multiplying_operator: T_TIMES | T_DIV | T_MOD | T_AND
;
factor: constant_use | variable_access | 
	T_LBRACKET expression T_RBRACKET | T_NOT factor
;
variable_access: T_ID
;
constant: T_INT_CONST | T_REAL_CONST | T_BOOLEAN_CONST | T_ID
;
constant_use: T_INT_CONST | T_REAL_CONST | T_BOOLEAN_CONST
;
opt_procedure_definition: 
	| procedure_definition opt_procedure_definition
;
opt_constant_definition:
	| constant_definition opt_constant_definition
;
opt_variable_definition:
	| variable_definition opt_variable_definition
;
opt_id:
	| T_COMMA T_ID opt_id
;
opt_actual_parameter:
	| T_COMMA actual_parameter opt_actual_parameter
;
opt_statement:
	| T_SEMICOLON statement opt_statement
;
opt_adding_operator:
	| adding_operator opt_adding_operator
;
opt_parameter_definition:
	| T_SEMICOLON parameter_definition opt_parameter_definition
;
opt_multiplying_operator:
	| multiplying_operator opt_multiplying_operator
;
%%