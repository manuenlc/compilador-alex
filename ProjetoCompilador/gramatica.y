Program = T_PROGRAM T_ID T_SEMICOLON BlockBody T_PERIOD .

BlockBody = [ ConstantDefinitionPart ] 	[ VariableDefinitionPart ] { ProcedureDefinition } 	CompoundStatement .

ConstantDefinitionPart = 	T_CONST ConstantDefinition { ConstantDefinition } .

ConstantDefinition = T_ID T_EQ Constant T_SEMICOLON .

VariableDefinitionPart = T_VAR VariableDefinition { VariableDefinition } .

CariableDefinition = VariableGroup T_SEMICOLON .

VariableGroup = T_ID { T_COMMA T_ID } T_COLON Type .

Type = T_INTEGER | T_BOOLEAN | T_REAL	

ProcedureDefinition = T_PROCEDURE T_ID ProcedureBlock T_SEMICOLON .

ProcedureBlock = [ T_LBRACKET FormalParameterList T_RBRACKET ] T_SEMICOLON BlockBody .

FormalParameterList = 	ParameterDefinition { T_SEMICOLON ParameterDefinition } .

ParameterDefinition = VariableGroup .

Statement = AssignmentStatement
		| ProcedureStatement
		| IfStatement 
		| WhileStatement 
		| CompoundStatement 
		| Empty .
		
AssignmentStatement = VariableAccess T_ASSIGN Expression .

ProcedureStatement = T_ID [ T_LBRACKET ActualParameterList T_RBRACKET ] .

ActualParameterList = ActualParameter{ T_COMMA ActualParameter } .

ActualParameter = Expression | VariableAccess .

IfStatement = T_IF Expression T_THEN Statement [ T_ELSE Statement ] .

WhileStatement = T_WHILE Expression T_DO Statement .

CompoundStatement = T_BEGIN Statement { T_SEMICOLON Statement } T_END .

Expression = SimpleExpression [ RelationalOperator SimpleExpression ].

RelationalOperator = T_LT 
		| T_EQ 
		| T_GT 
		| T_LEQ 
		| T_DIF 
		| T_GEQ .
SimpleExpression = 	[ SignOperator ] Term { AddingOperator Term } .

SignOperator = T_PLUS
		| T_MINUS .
		
AddingOperator = T_PLUS 
		| T_MINUS 
		| T_OR.
		
Term = Factor{ MultiplyingOperator Factor }.

MultiplyingOperator = T_TIMES
		| T_DIV 
		| T_MOD 
		| T_AND .
Factor = Constant 
		| VariableAccess
		| T_LBRACKET Expression T_RBRACKET
		| T_NOT Factor .
		
VariableAccess = T_ID .

Constant = T_INT_CONST
		| T_REAL_CONST
		| T_BOOLEAN_CONST
		| T_ID.