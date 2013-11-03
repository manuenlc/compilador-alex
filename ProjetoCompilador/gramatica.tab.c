
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */



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





/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     T_EOF = 0,
     T_ID = 1,
     T_INT_CONST = 2,
     T_REAL_CONST = 3,
     T_BOOLEAN_CONST = 4,
     T_PROGRAM = 5,
     T_PROCEDURE = 6,
     T_BEGIN = 7,
     T_END = 8,
     T_IF = 9,
     T_THEN = 10,
     T_ELSE = 11,
     T_WHILE = 12,
     T_DO = 13,
     T_ASSIGN = 14,
     T_PLUS = 15,
     T_MINUS = 16,
     T_TIMES = 17,
     T_DIVIDE = 18,
     T_DIV = 19,
     T_MOD = 20,
     T_PLUS_EQ = 21,
     T_MINUS_EQ = 22,
     T_TIMES_EQ = 23,
     T_AND = 24,
     T_OR = 25,
     T_NOT = 26,
     T_DIVIDE_EQ = 27,
     T_VAR = 28,
     T_INTEGER = 29,
     T_REAL = 30,
     T_BOOLEAN = 31,
     T_COLON = 32,
     T_SEMICOLON = 33,
     T_COMMA = 34,
     T_PERIOD = 35,
     T_DOUBLE_PERIOD = 36,
     T_LBRACKET = 37,
     T_RBRACKET = 38,
     T_CONST = 39,
     T_REPEAT = 40,
     T_UNTIL = 41,
     T_EQ = 42,
     T_DIF = 43,
     T_LT = 44,
     T_LEQ = 45,
     T_GT = 46,
     T_GEQ = 47,
     T_PARAMETER = 48,
     T_VOID = 49,
     T_INVALID = 255
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{


    int token1;
	int token2;
    int token_valor_int;
	char token_valor_id[64];
    float token_valor_real;
    int token_valor_boolean;



} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */



#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   113

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  50
/* YYNRULES -- Number of rules.  */
#define YYNRULES  93
/* YYNRULES -- Number of states.  */
#define YYNSTATES  150

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   257

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,    52,     1,     2
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,    10,    11,    16,    17,    19,    20,    22,
      23,    27,    28,    31,    33,    36,    41,    46,    51,    54,
      56,    59,    62,    67,    68,    72,    74,    76,    78,    82,
      86,    89,    90,    94,    97,    98,   102,   104,   109,   110,
     114,   115,   117,   119,   121,   123,   125,   129,   132,   133,
     137,   140,   141,   145,   147,   152,   159,   164,   169,   170,
     174,   177,   178,   181,   183,   185,   187,   189,   191,   193,
     197,   200,   202,   204,   205,   209,   211,   213,   215,   218,
     219,   223,   225,   227,   229,   231,   233,   235,   239,   242,
     244,   246,   248,   250
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      54,     0,    -1,     7,     3,    35,    55,    56,    37,    -1,
      -1,    57,    58,    59,    88,    -1,    -1,    61,    -1,    -1,
      64,    -1,    -1,    60,    70,    59,    -1,    -1,    41,    62,
      -1,    63,    -1,    63,    62,    -1,     3,    44,     4,    35,
      -1,     3,    44,     5,    35,    -1,     3,    44,     6,    35,
      -1,    30,    65,    -1,    66,    -1,    66,    65,    -1,    67,
      35,    -1,     3,    68,    34,    69,    -1,    -1,    36,     3,
      68,    -1,    31,    -1,    32,    -1,    33,    -1,    71,    56,
      35,    -1,    72,    73,    35,    -1,     8,     3,    -1,    -1,
      39,    74,    40,    -1,    76,    75,    -1,    -1,    35,    76,
      75,    -1,    77,    -1,     3,    78,    34,    69,    -1,    -1,
      36,     3,    78,    -1,    -1,    81,    -1,    86,    -1,    87,
      -1,    88,    -1,    80,    -1,   101,    16,    90,    -1,     3,
      82,    -1,    -1,    39,    83,    40,    -1,    85,    84,    -1,
      -1,    36,    85,    84,    -1,    90,    -1,    11,    90,    12,
      79,    -1,    11,    90,    12,    79,    13,    79,    -1,    14,
      90,    15,    79,    -1,     9,    79,    89,    10,    -1,    -1,
      35,    79,    89,    -1,    93,    91,    -1,    -1,    92,    93,
      -1,    46,    -1,    44,    -1,    48,    -1,    47,    -1,    45,
      -1,    49,    -1,    94,    97,    95,    -1,    97,    95,    -1,
      17,    -1,    18,    -1,    -1,    96,    97,    95,    -1,    17,
      -1,    18,    -1,    27,    -1,   100,    98,    -1,    -1,    99,
     100,    98,    -1,    19,    -1,    21,    -1,    22,    -1,    26,
      -1,    20,    -1,   102,    -1,    39,    90,    40,    -1,    28,
     100,    -1,     3,    -1,     4,    -1,     5,    -1,     6,    -1,
     101,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   101,   101,   105,   110,   116,   117,   120,   121,   125,
     129,   133,   139,   142,   143,   146,   155,   163,   173,   176,
     177,   180,   183,   203,   204,   212,   216,   220,   226,   229,
     232,   239,   249,   276,   279,   280,   283,   286,   299,   300,
     308,   309,   310,   311,   312,   313,   316,   319,   329,   330,
     333,   336,   337,   340,   343,   344,   347,   351,   354,   355,
     358,   361,   362,   365,   366,   367,   368,   369,   370,   373,
     374,   377,   378,   381,   382,   385,   386,   387,   390,   393,
     394,   397,   398,   399,   400,   401,   404,   405,   406,   409,
     420,   421,   422,   423
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "T_EOF", "error", "$undefined", "T_ID", "T_INT_CONST", "T_REAL_CONST",
  "T_BOOLEAN_CONST", "T_PROGRAM", "T_PROCEDURE", "T_BEGIN", "T_END",
  "T_IF", "T_THEN", "T_ELSE", "T_WHILE", "T_DO", "T_ASSIGN", "T_PLUS",
  "T_MINUS", "T_TIMES", "T_DIVIDE", "T_DIV", "T_MOD", "T_PLUS_EQ",
  "T_MINUS_EQ", "T_TIMES_EQ", "T_AND", "T_OR", "T_NOT", "T_DIVIDE_EQ",
  "T_VAR", "T_INTEGER", "T_REAL", "T_BOOLEAN", "T_COLON", "T_SEMICOLON",
  "T_COMMA", "T_PERIOD", "T_DOUBLE_PERIOD", "T_LBRACKET", "T_RBRACKET",
  "T_CONST", "T_REPEAT", "T_UNTIL", "T_EQ", "T_DIF", "T_LT", "T_LEQ",
  "T_GT", "T_GEQ", "T_PARAMETER", "T_VOID", "T_INVALID", "$accept",
  "input", "new_block", "block_body", "opt_constant_definition_part",
  "opt_variable_definition_part", "star_procedure_definition",
  "set_procedure_definition", "constant_definition_part",
  "plus_constant_definition", "constant_definition",
  "variable_definition_part", "plus_variable_definition",
  "variable_definition", "variable_group", "star_comma_id", "type",
  "procedure_definition", "procedure_block", "init_procedure",
  "opt_brc_formal_parameter_list_brc", "formal_parameter_list",
  "star_smc_parameter_definition", "parameter_definition",
  "variable_group_par", "star_comma_id_par", "statement",
  "assignment_statement", "procedure_statement",
  "opt_brc_actual_parameter_list_brc", "actual_parameter_list",
  "star_comma_actual_parameter", "actual_parameter", "if_statement",
  "while_statement", "compound_statement", "star_comma_statement",
  "expression", "opt_relational_operator_simple_expression",
  "relational_operator", "simple_expression", "sign_operator",
  "star_adding_operator_term", "adding_operator", "term",
  "star_multiplying_operator_factor", "multiplying_operator", "factor",
  "variable_access", "constant", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,     1,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,   255
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    53,    54,    55,    56,    57,    57,    58,    58,    59,
      59,    60,    61,    62,    62,    63,    63,    63,    64,    65,
      65,    66,    67,    68,    68,    69,    69,    69,    70,    71,
      72,    73,    73,    74,    75,    75,    76,    77,    78,    78,
      79,    79,    79,    79,    79,    79,    80,    81,    82,    82,
      83,    84,    84,    85,    86,    86,    87,    88,    89,    89,
      90,    91,    91,    92,    92,    92,    92,    92,    92,    93,
      93,    94,    94,    95,    95,    96,    96,    96,    97,    98,
      98,    99,    99,    99,    99,    99,   100,   100,   100,   101,
     102,   102,   102,   102
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     0,     4,     0,     1,     0,     1,     0,
       3,     0,     2,     1,     2,     4,     4,     4,     2,     1,
       2,     2,     4,     0,     3,     1,     1,     1,     3,     3,
       2,     0,     3,     2,     0,     3,     1,     4,     0,     3,
       0,     1,     1,     1,     1,     1,     3,     2,     0,     3,
       2,     0,     3,     1,     4,     6,     4,     4,     0,     3,
       2,     0,     2,     1,     1,     1,     1,     1,     1,     3,
       2,     1,     1,     0,     3,     1,     1,     1,     2,     0,
       3,     1,     1,     1,     1,     1,     1,     3,     2,     1,
       1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     3,     5,     0,     0,     7,
       6,     0,    12,    13,     2,     0,     9,     8,     0,    14,
      23,    18,    19,     0,     0,     0,     0,     0,     0,     0,
       0,    20,    21,    40,     4,     0,     9,     5,    31,    15,
      16,    17,    23,     0,    48,     0,     0,    58,    45,    41,
      42,    43,    44,     0,    30,    10,     0,     0,     0,    24,
      25,    26,    27,    22,     0,    47,    89,    90,    91,    92,
      71,    72,     0,     0,     0,    61,     0,    73,    79,    93,
      86,     0,    40,     0,     0,    28,    38,     0,    34,    36,
      29,     0,    51,    53,    88,     0,    40,    64,    67,    63,
      66,    65,    68,    60,     0,    73,    75,    76,    77,    70,
       0,    81,    85,    82,    83,    84,    78,     0,    40,    58,
      57,    46,     0,     0,    32,     0,    33,    49,     0,    50,
      87,    54,    62,    69,    73,    79,    56,    59,    38,     0,
      34,    51,    40,    74,    80,    39,    37,    35,    52,    55
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     6,     8,     9,    16,    24,    25,    10,    12,
      13,    17,    21,    22,    23,    30,    63,    36,    37,    38,
      58,    87,   126,    88,    89,   123,    47,    48,    49,    65,
      91,   129,    92,    50,    51,    52,    83,    93,   103,   104,
      75,    76,   109,   110,    77,   116,   117,    78,    79,    80
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -89
static const yytype_int8 yypact[] =
{
      11,    18,    28,   -12,   -89,   -89,    -9,    26,    -4,    14,
     -89,    -1,   -89,    26,   -89,    55,    51,   -89,    34,   -89,
      24,   -89,    55,    27,    61,    63,    37,    38,    39,    72,
      42,   -89,   -89,    13,   -89,    74,    51,    -9,    40,   -89,
     -89,   -89,    24,    23,    -3,     2,     2,    43,   -89,   -89,
     -89,   -89,   -89,    64,   -89,   -89,    46,    79,    48,   -89,
     -89,   -89,   -89,   -89,     2,   -89,   -89,   -89,   -89,   -89,
     -89,   -89,     6,     2,    75,    20,     6,     8,    31,   -89,
     -89,    69,    13,    76,     2,   -89,    52,    49,    56,   -89,
     -89,    50,    57,   -89,   -89,    54,    13,   -89,   -89,   -89,
     -89,   -89,   -89,   -89,     2,     8,   -89,   -89,   -89,   -89,
       6,   -89,   -89,   -89,   -89,   -89,   -89,     6,    13,    43,
     -89,   -89,    89,    62,   -89,    79,   -89,   -89,     2,   -89,
     -89,    82,   -89,   -89,     8,    31,   -89,   -89,    52,    23,
      56,    57,    13,   -89,   -89,   -89,   -89,   -89,   -89,   -89
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -89,   -89,   -89,    60,   -89,   -89,    65,   -89,   -89,    85,
     -89,   -89,    77,   -89,   -89,    58,   -37,   -89,   -89,   -89,
     -89,   -89,   -36,   -22,   -89,   -32,   -81,   -89,   -89,   -89,
     -89,   -34,   -23,   -89,   -89,    84,    -8,   -42,   -89,   -89,
       9,   -89,   -88,   -89,   -62,   -25,   -89,   -70,   -33,   -89
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -90
static const yytype_int16 yytable[] =
{
      53,   119,    94,    74,    81,    66,    67,    68,    69,    66,
      67,    68,    69,   -89,   105,   131,    44,   133,     1,    70,
      71,     3,    33,     5,    45,   106,   107,    46,     4,    11,
      72,    95,     7,    14,    72,   108,    64,   136,    26,    27,
      28,    73,   121,    18,    15,    73,   143,   135,   134,    53,
     111,   112,   113,   114,    60,    61,    62,   115,    20,   -11,
      29,   149,    32,    53,    97,    98,    99,   100,   101,   102,
      33,    35,    39,    40,    41,    42,    43,    54,    82,    57,
      84,    85,    86,    90,   118,    53,   120,    96,   122,   124,
     127,   125,   138,   128,   130,   142,   139,    56,    19,    31,
      59,    55,   146,   140,   147,   141,   145,   148,    34,    53,
     144,   137,     0,   132
};

static const yytype_int16 yycheck[] =
{
      33,    82,    72,    45,    46,     3,     4,     5,     6,     3,
       4,     5,     6,    16,    76,    96,     3,   105,     7,    17,
      18,     3,     9,    35,    11,    17,    18,    14,     0,     3,
      28,    73,    41,    37,    28,    27,    39,   118,     4,     5,
       6,    39,    84,    44,    30,    39,   134,   117,   110,    82,
      19,    20,    21,    22,    31,    32,    33,    26,     3,     8,
      36,   142,    35,    96,    44,    45,    46,    47,    48,    49,
       9,     8,    35,    35,    35,     3,    34,     3,    35,    39,
      16,    35,     3,    35,    15,   118,    10,    12,    36,    40,
      40,    35,     3,    36,    40,    13,    34,    37,    13,    22,
      42,    36,   139,   125,   140,   128,   138,   141,    24,   142,
     135,   119,    -1,   104
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,    54,     3,     0,    35,    55,    41,    56,    57,
      61,     3,    62,    63,    37,    30,    58,    64,    44,    62,
       3,    65,    66,    67,    59,    60,     4,     5,     6,    36,
      68,    65,    35,     9,    88,     8,    70,    71,    72,    35,
      35,    35,     3,    34,     3,    11,    14,    79,    80,    81,
      86,    87,    88,   101,     3,    59,    56,    39,    73,    68,
      31,    32,    33,    69,    39,    82,     3,     4,     5,     6,
      17,    18,    28,    39,    90,    93,    94,    97,   100,   101,
     102,    90,    35,    89,    16,    35,     3,    74,    76,    77,
      35,    83,    85,    90,   100,    90,    12,    44,    45,    46,
      47,    48,    49,    91,    92,    97,    17,    18,    27,    95,
      96,    19,    20,    21,    22,    26,    98,    99,    15,    79,
      10,    90,    36,    78,    40,    35,    75,    40,    36,    84,
      40,    79,    93,    95,    97,   100,    79,    89,     3,    34,
      76,    85,    13,    95,    98,    78,    69,    75,    84,    79
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 3:

    {
	begin_block();
;}
    break;

  case 4:

    {
	end_block()
;}
    break;

  case 9:

    {
	eh_declaracao_procedure = false;
	printf("\nfim de declaracao de procedure\n");
;}
    break;

  case 11:

    {
	eh_declaracao_procedure = true;
	printf("\ndeclaracao de procedure\n");
;}
    break;

  case 15:

    {	
		 
		if(!insert_const((yyvsp[(1) - (4)].token2), T_INTEGER))
		{
			printf("ERRO: Redefinicao do simbolo %s na linha %d", get_token2_id((yyvsp[(1) - (4)].token2)), get_line());
			YYERROR;
		}		
;}
    break;

  case 16:

    {	
		if(!insert_const((yyvsp[(1) - (4)].token2), T_REAL))
		{
			printf("ERRO: Redefinicao do simbolo %s na linha %d", get_token2_id((yyvsp[(1) - (4)].token2)), get_line());
			YYERROR;
		}		
;}
    break;

  case 17:

    {		
		if(!insert_const((yyvsp[(1) - (4)].token2), T_BOOLEAN))
		{
			printf("ERRO: Redefinicao do simbolo %s na linha %d", get_token2_id((yyvsp[(1) - (4)].token2)), get_line());
			YYERROR;
		}
;}
    break;

  case 22:

    {	
	var_token2[quantidade_var] = (yyvsp[(1) - (4)].token2);
	++quantidade_var;
	
	int i;
	
	 
	for(i = quantidade_var - 1; i > -1; --i)
	{
		if(!insert_var(var_token2[i], (yyvsp[(4) - (4)].token1)))
		{
			printf("ERRO: Redefinicao do simbolo %s na linha %d", get_token2_id(var_token2[i]), get_line());
			YYERROR;
		}
	}
	quantidade_var = 0;	
;}
    break;

  case 24:

    {
	var_token2[quantidade_var] = (yyvsp[(2) - (3)].token2);
	++quantidade_var;
	
;}
    break;

  case 25:

    {
	(yyval.token1) = T_INTEGER;
;}
    break;

  case 26:

    {
	(yyval.token1) = T_REAL;
;}
    break;

  case 27:

    {
	(yyval.token1) = T_BOOLEAN;
;}
    break;

  case 30:

    {
	procedure_token2 = (yyvsp[(2) - (2)].token2);
;}
    break;

  case 31:

    {
	if(!insert_procedure(procedure_token2, 0 , NULL))
	{
		printf("ERRO: Redefinicao do simbolo %s na linha %d", get_token2_id(procedure_token2), get_line());
		YYERROR;
	}
	
	begin_block();
	
;}
    break;

  case 32:

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
;}
    break;

  case 37:

    {	
	arg_token2[quantidade_arg++] = (yyvsp[(1) - (4)].token2);
	
	int i;
	for(i = quantidade_arg_adicionados; i < quantidade_arg; ++i)
	{
		arg_token1[i] = (yyvsp[(4) - (4)].token1);
	}
	quantidade_arg_adicionados = quantidade_arg;
;}
    break;

  case 39:

    {
	arg_token2[quantidade_arg++] = (yyvsp[(2) - (3)].token2);
	

;}
    break;

  case 47:

    {
	if(!search_token2_on_current_scope_and_bellow((yyvsp[(1) - (2)].token2)))
	{
		printf("ERRO: A procedure %s eh utilizada na linha %d mas não foi declarada\n", get_token2_id((yyvsp[(1) - (2)].token2)), get_line());
		//YYERROR;
	}
;}
    break;

  case 63:

    { (yyval.token1) = T_LT;  ;}
    break;

  case 64:

    { (yyval.token1) = T_EQ;  ;}
    break;

  case 65:

    { (yyval.token1) = T_GT;  ;}
    break;

  case 66:

    { (yyval.token1) = T_LEQ; ;}
    break;

  case 67:

    { (yyval.token1) = T_DIF; ;}
    break;

  case 68:

    { (yyval.token1) = T_GEQ; ;}
    break;

  case 71:

    { (yyval.token1) = T_PLUS; ;}
    break;

  case 72:

    { (yyval.token1) = T_MINUS; ;}
    break;

  case 81:

    { (yyval.token1) = T_TIMES;  ;}
    break;

  case 82:

    { (yyval.token1) = T_DIV;    ;}
    break;

  case 83:

    { (yyval.token1) = T_MOD;    ;}
    break;

  case 84:

    { (yyval.token1) = T_AND;    ;}
    break;

  case 85:

    { (yyval.token1) = T_DIVIDE; ;}
    break;

  case 89:

    {
	
	if(!search_token2_on_current_scope_and_bellow((yyvsp[(1) - (1)].token2)))
	{
		printf("ERRO: O simbolo %s eh utilizado na linha %d mas não foi declarado\n", get_token2_id((yyvsp[(1) - (1)].token2)), get_line());
		//YYERROR;
	}
;}
    break;



      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}




