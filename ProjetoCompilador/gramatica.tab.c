
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
#include "gramatica.tab.h"
#include "boolean.h"
#include "geracao_de_codigo.h"

extern int yyerror(char*);
extern int yylex(void);

int quantidade_arg = 0;
int arg_token2[20];
int arg_token1[20];
int quantidade_arg_adicionados = 0;
int quantidade_var = 0;
int quantidade_var_alocadas = 0;
int var_token2[20];
bool eh_declaracao_procedure;
bool eh_procedure_parametro;
bool uso_de_const;
bool eh_constante;

int tipo_constante;
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

/* "%code requires" blocks.  */


#include "escopo.h"
#include "tipo.h"
#include "geracao_de_codigo.h"




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
    
    struct procedure procedure_info;
    struct expressao expressao_info;
    struct t_id t_id_info;
    
    int label;



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
#define YYLAST   114

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  56
/* YYNRULES -- Number of rules.  */
#define YYNRULES  99
/* YYNRULES -- Number of states.  */
#define YYNSTATES  156

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
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,    10,    11,    17,    18,    20,    21,    22,
      24,    25,    29,    30,    33,    35,    38,    43,    48,    53,
      56,    58,    61,    64,    69,    70,    74,    76,    78,    80,
      84,    88,    91,    92,    96,    99,   100,   104,   106,   111,
     112,   116,   117,   119,   121,   123,   125,   127,   131,   134,
     135,   140,   141,   144,   145,   149,   151,   157,   164,   165,
     168,   174,   175,   177,   182,   183,   187,   190,   191,   194,
     196,   198,   200,   202,   204,   206,   210,   213,   215,   217,
     218,   222,   224,   226,   228,   231,   232,   236,   238,   240,
     242,   244,   246,   248,   252,   255,   257,   259,   261,   263
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      54,     0,    -1,     7,    55,     3,    35,    56,    37,    -1,
      -1,    57,    59,    58,    60,    94,    -1,    -1,    62,    -1,
      -1,    -1,    65,    -1,    -1,    61,    71,    60,    -1,    -1,
      41,    63,    -1,    64,    -1,    64,    63,    -1,     3,    44,
       4,    35,    -1,     3,    44,     5,    35,    -1,     3,    44,
       6,    35,    -1,    30,    66,    -1,    67,    -1,    67,    66,
      -1,    68,    35,    -1,     3,    69,    34,    70,    -1,    -1,
      36,     3,    69,    -1,    31,    -1,    32,    -1,    33,    -1,
      72,    56,    35,    -1,    73,    74,    35,    -1,     8,     3,
      -1,    -1,    39,    75,    40,    -1,    77,    76,    -1,    -1,
      35,    77,    76,    -1,    78,    -1,     3,    79,    34,    70,
      -1,    -1,    36,     3,    79,    -1,    -1,    82,    -1,    88,
      -1,    91,    -1,    94,    -1,    81,    -1,   107,    16,    96,
      -1,     3,    83,    -1,    -1,    39,    84,    85,    40,    -1,
      -1,    87,    86,    -1,    -1,    36,    87,    86,    -1,    96,
      -1,    11,    96,    89,    12,    80,    -1,    11,    96,    89,
      12,    90,    80,    -1,    -1,    80,    13,    -1,    92,    14,
      96,    93,    80,    -1,    -1,    15,    -1,     9,    80,    95,
      10,    -1,    -1,    35,    80,    95,    -1,    99,    97,    -1,
      -1,    98,    99,    -1,    46,    -1,    44,    -1,    48,    -1,
      47,    -1,    45,    -1,    49,    -1,   100,   103,   101,    -1,
     103,   101,    -1,    17,    -1,    18,    -1,    -1,   102,   103,
     101,    -1,    17,    -1,    18,    -1,    27,    -1,   106,   104,
      -1,    -1,   105,   106,   104,    -1,    19,    -1,    21,    -1,
      22,    -1,    26,    -1,    20,    -1,   108,    -1,    39,    96,
      40,    -1,    28,   106,    -1,     3,    -1,     4,    -1,     5,
      -1,     6,    -1,   107,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   124,   124,   128,   136,   143,   144,   148,   156,   159,
     163,   166,   170,   175,   178,   179,   182,   193,   201,   211,
     214,   215,   218,   221,   245,   246,   254,   258,   262,   268,
     271,   274,   281,   293,   325,   328,   329,   332,   335,   350,
     351,   359,   360,   361,   362,   363,   364,   367,   381,   401,
     404,   412,   416,   424,   427,   434,   440,   450,   463,   472,
     482,   496,   503,   512,   515,   516,   519,   535,   539,   552,
     553,   554,   555,   556,   557,   560,   576,   592,   593,   597,
     601,   620,   621,   622,   625,   644,   648,   665,   666,   667,
     668,   669,   672,   676,   688,   704,   742,   747,   751,   755
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
  "input", "insert_print_procedure", "block_body",
  "opt_constant_definition_part", "allocate_vars",
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
  "opt_brc_actual_parameter_list_brc", "set_procedure_par",
  "actual_parameter_list", "star_comma_actual_parameter",
  "actual_parameter", "if_statement", "insert_if_label",
  "insert_else_label", "while_statement", "insert_while_label",
  "insert_do_label", "compound_statement", "star_comma_statement",
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
       0,    53,    54,    55,    56,    57,    57,    58,    59,    59,
      60,    60,    61,    62,    63,    63,    64,    64,    64,    65,
      66,    66,    67,    68,    69,    69,    70,    70,    70,    71,
      72,    73,    74,    74,    75,    76,    76,    77,    78,    79,
      79,    80,    80,    80,    80,    80,    80,    81,    82,    83,
      83,    84,    85,    86,    86,    87,    88,    88,    89,    90,
      91,    92,    93,    94,    95,    95,    96,    97,    97,    98,
      98,    98,    98,    98,    98,    99,    99,   100,   100,   101,
     101,   102,   102,   102,   103,   104,   104,   105,   105,   105,
     105,   105,   106,   106,   106,   107,   108,   108,   108,   108
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     0,     5,     0,     1,     0,     0,     1,
       0,     3,     0,     2,     1,     2,     4,     4,     4,     2,
       1,     2,     2,     4,     0,     3,     1,     1,     1,     3,
       3,     2,     0,     3,     2,     0,     3,     1,     4,     0,
       3,     0,     1,     1,     1,     1,     1,     3,     2,     0,
       4,     0,     2,     0,     3,     1,     5,     6,     0,     2,
       5,     0,     1,     4,     0,     3,     2,     0,     2,     1,
       1,     1,     1,     1,     1,     3,     2,     1,     1,     0,
       3,     1,     1,     1,     2,     0,     3,     1,     1,     1,
       1,     1,     1,     3,     2,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     3,     0,     0,     1,     0,     5,     0,     0,     8,
       6,     0,    13,    14,     2,     0,     7,     9,     0,    15,
      24,    19,    20,     0,    10,     0,     0,     0,     0,     0,
      21,    22,     0,     0,    16,    17,    18,    24,     0,    41,
       4,     0,    10,     5,    32,    25,    26,    27,    28,    23,
      49,     0,    64,    46,    42,    43,    44,     0,    45,     0,
      31,    11,     0,     0,     0,    51,    48,    95,    96,    97,
      98,    77,    78,     0,     0,    58,    67,     0,    79,    85,
      99,    92,    41,     0,     0,     0,    29,    39,     0,    35,
      37,    30,     0,    94,     0,     0,    70,    73,    69,    72,
      71,    74,    66,     0,    79,    81,    82,    83,    76,     0,
      87,    91,    88,    89,    90,    84,     0,    64,    63,     0,
      47,     0,     0,    33,     0,    34,     0,    53,    55,    93,
      41,    68,    75,    79,    85,    65,    62,    41,    39,     0,
      35,    50,     0,    52,    56,    41,    80,    86,    60,    40,
      38,    36,    53,    59,    57,    54
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     8,     9,    24,    16,    32,    33,    10,
      12,    13,    17,    21,    22,    23,    29,    49,    42,    43,
      44,    64,    88,   125,    89,    90,   122,    52,    53,    54,
      66,    92,   126,   143,   127,    55,    95,   145,    56,    57,
     137,    58,    83,   128,   102,   103,    76,    77,   108,   109,
      78,   115,   116,    79,    80,    81
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -92
static const yytype_int8 yypact[] =
{
       9,   -92,    22,    21,   -92,   -10,   -14,    28,    -5,     4,
     -92,     3,   -92,    28,   -92,    45,   -92,   -92,    32,   -92,
      18,   -92,    45,    20,    60,    35,    36,    37,    66,    39,
     -92,   -92,    65,    67,   -92,   -92,   -92,    18,    34,    12,
     -92,    73,    60,   -14,    38,   -92,   -92,   -92,   -92,   -92,
      -4,     0,    43,   -92,   -92,   -92,   -92,    68,   -92,    63,
     -92,   -92,    46,    77,    48,   -92,   -92,   -92,   -92,   -92,
     -92,   -92,   -92,     5,     0,   -92,    14,     5,     2,    31,
     -92,   -92,    12,    74,     0,     0,   -92,    49,    47,    51,
     -92,   -92,     0,   -92,    50,    76,   -92,   -92,   -92,   -92,
     -92,   -92,   -92,     0,     2,   -92,   -92,   -92,   -92,     5,
     -92,   -92,   -92,   -92,   -92,   -92,     5,    43,   -92,    78,
     -92,    86,    58,   -92,    77,   -92,    54,    59,   -92,   -92,
      12,   -92,   -92,     2,    31,   -92,   -92,    12,    49,    34,
      51,   -92,     0,   -92,    83,    12,   -92,   -92,   -92,   -92,
     -92,   -92,    59,   -92,   -92,   -92
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -92,   -92,   -92,    56,   -92,   -92,   -92,    55,   -92,   -92,
      87,   -92,   -92,    79,   -92,   -92,    70,   -37,   -92,   -92,
     -92,   -92,   -92,   -36,   -21,   -92,   -33,   -81,   -92,   -92,
     -92,   -92,   -92,   -43,   -34,   -92,   -92,   -92,   -92,   -92,
     -92,    80,    -7,   -44,   -92,   -92,     8,   -92,   -91,   -92,
     -63,   -20,   -92,   -71,   -39,   -92
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -96
static const yytype_int16 yytable[] =
{
      59,   117,    93,    67,    68,    69,    70,    75,    67,    68,
      69,    70,   -95,   132,   104,    50,     1,    71,    72,   105,
     106,    39,     4,    51,     5,     6,   -61,     7,    73,   107,
      94,    11,    14,    73,    15,    65,    25,    26,    27,    74,
     119,   120,   146,    59,    74,   134,   133,    18,    20,   144,
     110,   111,   112,   113,    28,    31,   148,   114,    96,    97,
      98,    99,   100,   101,   154,    46,    47,    48,   -12,    37,
      34,    35,    36,    38,    39,    41,    60,    63,    82,    85,
      87,    86,    84,    91,   118,   121,   124,   123,   130,   138,
     129,    59,   139,   136,   141,   142,   153,    61,    59,    62,
      19,    30,   150,   140,   151,   149,    59,    45,   152,   155,
     135,   131,    40,     0,   147
};

static const yytype_int16 yycheck[] =
{
      39,    82,    73,     3,     4,     5,     6,    51,     3,     4,
       5,     6,    16,   104,    77,     3,     7,    17,    18,    17,
      18,     9,     0,    11,     3,    35,    14,    41,    28,    27,
      74,     3,    37,    28,    30,    39,     4,     5,     6,    39,
      84,    85,   133,    82,    39,   116,   109,    44,     3,   130,
      19,    20,    21,    22,    36,    35,   137,    26,    44,    45,
      46,    47,    48,    49,   145,    31,    32,    33,     8,     3,
      35,    35,    35,    34,     9,     8,     3,    39,    35,    16,
       3,    35,    14,    35,    10,    36,    35,    40,    12,     3,
      40,   130,    34,    15,    40,    36,    13,    42,   137,    43,
      13,    22,   139,   124,   140,   138,   145,    37,   142,   152,
     117,   103,    32,    -1,   134
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,    54,    55,     0,     3,    35,    41,    56,    57,
      62,     3,    63,    64,    37,    30,    59,    65,    44,    63,
       3,    66,    67,    68,    58,     4,     5,     6,    36,    69,
      66,    35,    60,    61,    35,    35,    35,     3,    34,     9,
      94,     8,    71,    72,    73,    69,    31,    32,    33,    70,
       3,    11,    80,    81,    82,    88,    91,    92,    94,   107,
       3,    60,    56,    39,    74,    39,    83,     3,     4,     5,
       6,    17,    18,    28,    39,    96,    99,   100,   103,   106,
     107,   108,    35,    95,    14,    16,    35,     3,    75,    77,
      78,    35,    84,   106,    96,    89,    44,    45,    46,    47,
      48,    49,    97,    98,   103,    17,    18,    27,   101,   102,
      19,    20,    21,    22,    26,   104,   105,    80,    10,    96,
      96,    36,    79,    40,    35,    76,    85,    87,    96,    40,
      12,    99,   101,   103,   106,    95,    15,    93,     3,    34,
      77,    40,    36,    86,    80,    90,   101,   104,    80,    79,
      70,    76,    87,    13,    80,    86
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
	
	int procedure_print_token2 = insert_procedure_print_token2();
	insert_procedure_print(procedure_print_token2);
;}
    break;

  case 4:

    {
	end_block();
	wml_procedure_or_program_end();
;}
    break;

  case 7:

    {
	if(eh_declaracao_procedure) wml_allocate_procedure_vars(quantidade_var_alocadas);		
	
	quantidade_var_alocadas = 0;
;}
    break;

  case 8:

    {
	quantidade_var_alocadas = 0;
;}
    break;

  case 10:

    {
	eh_declaracao_procedure = false;
;}
    break;

  case 12:

    {
	eh_declaracao_procedure = true;
;}
    break;

  case 16:

    {	
	wml_generate_int_const_def((yyvsp[(3) - (4)].token_valor_int), (yyvsp[(1) - (4)].token2));
		
	if(!insert_const((yyvsp[(1) - (4)].token2), T_INT_CONST))
	{
		printf("ERRO: Redefinicao do simbolo %s na linha %d\n", get_token2_id((yyvsp[(1) - (4)].token2)), get_line());
		YYERROR;
	}
	
;}
    break;

  case 17:

    {	
		if(!insert_const((yyvsp[(1) - (4)].token2), T_REAL_CONST))
		{
			printf("ERRO: Redefinicao do simbolo %s na linha %d\n", get_token2_id((yyvsp[(1) - (4)].token2)), get_line());
			YYERROR;
		}		
;}
    break;

  case 18:

    {		
		if(!insert_const((yyvsp[(1) - (4)].token2), T_BOOLEAN_CONST))
		{
			printf("ERRO: Redefinicao do simbolo %s na linha %d\n", get_token2_id((yyvsp[(1) - (4)].token2)), get_line());
			YYERROR;
		}
;}
    break;

  case 23:

    {	
	var_token2[quantidade_var] = (yyvsp[(1) - (4)].token2);
	++quantidade_var;
	
	quantidade_var_alocadas += quantidade_var; 
	
	int i;
	
	 
	for(i = quantidade_var - 1; i > -1; --i)
	{
		if(!insert_var(var_token2[i], (yyvsp[(4) - (4)].token1)))
		{
			printf("ERRO: Redefinicao do simbolo %s na linha %d\n", get_token2_id(var_token2[i]), get_line());
			YYERROR;
		}
		
		wml_generate_var_def(var_token2[i]);
	}
	quantidade_var = 0;	
;}
    break;

  case 25:

    {
	var_token2[quantidade_var] = (yyvsp[(2) - (3)].token2);
	++quantidade_var;
	
;}
    break;

  case 26:

    {
	(yyval.token1) = T_INTEGER;
;}
    break;

  case 27:

    {
	(yyval.token1) = T_REAL;
;}
    break;

  case 28:

    {
	(yyval.token1) = T_BOOLEAN;
;}
    break;

  case 31:

    {
	procedure_token2 = (yyvsp[(2) - (2)].token2);
;}
    break;

  case 32:

    {
	if(!insert_procedure(procedure_token2, 0 , NULL))
	{
		printf("ERRO: Redefinicao da procedure %s na linha %d\n", get_token2_id(procedure_token2), get_line());
		YYERROR;
	}
	
	wml_generate_procedure(get_token2_id(procedure_token2), procedure_token2, 0);
	
	begin_block();
	
;}
    break;

  case 33:

    {

	if(!insert_procedure(procedure_token2, quantidade_arg_adicionados, arg_token1))
	{
		printf("ERRO: Redefinicao da procedure %s na linha %d\n", get_token2_id(procedure_token2), get_line());
		YYERROR;
	}
	
	wml_generate_procedure(get_token2_id(procedure_token2), procedure_token2, quantidade_arg_adicionados);
	
	begin_block();
	
	int i;
	
	//for(i = 0; i < quantidade_arg_adicionados; ++i)
	for(i = quantidade_arg_adicionados -1 ; i >= 0; --i)
	{
		
		if(!insert_parameter(arg_token2[i], arg_token1[i]))
		{
			printf("ERRO: Redefinicao do simbolo %s na linha %d\n", get_token2_id(arg_token2[i]), get_line());
			YYERROR;
		}
		
		wml_generate_var_def(arg_token2[i]);
	}
	
	quantidade_arg_adicionados = 0;
;}
    break;

  case 38:

    {	
	arg_token2[quantidade_arg++] = (yyvsp[(1) - (4)].token2);
	
	int i;
	for(i = quantidade_arg_adicionados; i < quantidade_arg; ++i)
	{
		arg_token1[i] = (yyvsp[(4) - (4)].token1);
	}
	quantidade_arg_adicionados = quantidade_arg;
	
	quantidade_arg = 0;
;}
    break;

  case 40:

    {
	arg_token2[quantidade_arg++] = (yyvsp[(2) - (3)].token2);
	

;}
    break;

  case 47:

    {	
	if(!check_assignment((yyvsp[(1) - (3)].t_id_info).tipo, (yyvsp[(3) - (3)].token1)))
	{
		printf("ERRO: Nao eh possivel atribuir um %s a um %s na linha %d\n", get_type_name((yyvsp[(3) - (3)].token1)), get_type_name((yyvsp[(1) - (3)].t_id_info).tipo), get_line());
		YYERROR;
	}
	
	wml_var_assignment((yyvsp[(1) - (3)].t_id_info).token2);
	
	uso_de_const = false; // uso de constante no lado direito n�o � permitido;
;}
    break;

  case 48:

    {
	if(!search_procedure_on_current_scope_and_bellow((yyvsp[(1) - (2)].token2)))
	{
		printf("ERRO: A procedure %s eh utilizada na linha %d mas n�o foi declarada\n", get_token2_id((yyvsp[(1) - (2)].token2)), get_line());
		YYERROR;
	}
	
	
	if(!check_procedure_usage((yyvsp[(1) - (2)].token2), (yyvsp[(2) - (2)].procedure_info).qtd_argumentos, arg_token1))
	{		
		printf("ERRO: A procedure %s eh utilizada incorretamente na linha %d\n", get_token2_id((yyvsp[(1) - (2)].token2)), get_line());
		YYERROR;
	}
	
	wml_procedure_usage((yyvsp[(1) - (2)].token2));
;}
    break;

  case 49:

    {
	(yyval.procedure_info).qtd_argumentos = 0;
;}
    break;

  case 50:

    {
	(yyval.procedure_info).qtd_argumentos = (yyvsp[(3) - (4)].procedure_info).qtd_argumentos;
	eh_procedure_parametro = false;
;}
    break;

  case 51:

    {
	eh_procedure_parametro = true;
;}
    break;

  case 52:

    {
	arg_token1[(yyvsp[(2) - (2)].procedure_info).qtd_argumentos] = (yyvsp[(1) - (2)].token1);
	(yyval.procedure_info).qtd_argumentos = (yyvsp[(2) - (2)].procedure_info).qtd_argumentos + 1;
;}
    break;

  case 53:

    {
	(yyval.procedure_info).qtd_argumentos = 0;
;}
    break;

  case 54:

    {
	arg_token1[(yyvsp[(3) - (3)].procedure_info).qtd_argumentos] = (yyvsp[(2) - (3)].token1);
	(yyval.procedure_info).qtd_argumentos = (yyvsp[(3) - (3)].procedure_info).qtd_argumentos + 1;
;}
    break;

  case 55:

    {
	(yyval.token1) = (yyvsp[(1) - (1)].token1);
;}
    break;

  case 56:

    {
	if((yyvsp[(2) - (5)].token1) != T_BOOLEAN && (yyvsp[(2) - (5)].token1) != T_BOOLEAN_CONST)
	{
		printf("ERRO: A condicao do 'if' na linha %d deve ser um booleano\n", get_line());
		YYERROR;
	}
	
	print_label((yyvsp[(3) - (5)].label));
;}
    break;

  case 57:

    {
	if((yyvsp[(2) - (6)].token1) != T_BOOLEAN && (yyvsp[(2) - (6)].token1) != T_BOOLEAN_CONST)
	{
		printf("ERRO: A condicao do 'if' na linha %d deve ser um booleano\n", get_line());
		YYERROR;
	}
	
	print_label((yyvsp[(5) - (6)].label));
;}
    break;

  case 58:

    {
	int label = new_label();
	wml_tjump_fw(label);
	push_label(label);
	(yyval.label) = label;
;}
    break;

  case 59:

    {
	int label2 = new_label();
	int label1 = pop_label();
	wml_tjump_fw(label2);
	print_label(label1);
	(yyval.label) = label2;
;}
    break;

  case 60:

    {
	if((yyvsp[(3) - (5)].token1) != T_BOOLEAN && (yyvsp[(3) - (5)].token1) != T_BOOLEAN_CONST)
	{
		printf("ERRO: A condicao do 'while' na linha %d deve ser um booleano\n", get_line());
		YYERROR;
	}
	
	wml_jump_bw((yyvsp[(1) - (5)].label));
	print_label((yyvsp[(4) - (5)].label));
;}
    break;

  case 61:

    {
	int label = new_label();
	print_label(label);
	(yyval.label) = label;
;}
    break;

  case 62:

    {
	int label = new_label();
	wml_tjump_fw(label);
	(yyval.label) = label;
;}
    break;

  case 66:

    {
	int tipo_resultado = result_type((yyvsp[(1) - (2)].token1), (yyvsp[(2) - (2)].expressao_info).tipo_operando1, (yyvsp[(2) - (2)].expressao_info).operacao);
	
	wml_operation_usage((yyvsp[(1) - (2)].token1), (yyvsp[(2) - (2)].expressao_info).tipo_operando1, (yyvsp[(2) - (2)].expressao_info).operacao);
		
	if(tipo_resultado != T_INVALID) (yyval.token1) = tipo_resultado;
	else
	{
		printf("ERRO: Operacao invalida na linha %d\n", get_line());
		YYERROR;
	}
;}
    break;

  case 67:

    {
	(yyval.expressao_info).tipo_operando1 = T_EOF;
	(yyval.expressao_info).operacao = T_EOF;	
;}
    break;

  case 68:

    {
	(yyval.expressao_info).tipo_operando1 = (yyvsp[(2) - (2)].token1);
	(yyval.expressao_info).operacao = (yyvsp[(1) - (2)].token1);
		
	if((yyvsp[(1) - (2)].token1) == T_INVALID || (yyvsp[(2) - (2)].token1) == T_INVALID)
	{
		printf("ERRO: Operacao invalida na linha %d\n", get_line());
		YYERROR;
	}
;}
    break;

  case 69:

    { (yyval.token1) = T_LT;  ;}
    break;

  case 70:

    { (yyval.token1) = T_EQ;  ;}
    break;

  case 71:

    { (yyval.token1) = T_GT;  ;}
    break;

  case 72:

    { (yyval.token1) = T_LEQ; ;}
    break;

  case 73:

    { (yyval.token1) = T_DIF; ;}
    break;

  case 74:

    { (yyval.token1) = T_GEQ; ;}
    break;

  case 75:

    {
	int tipo_resultado = result_type((yyvsp[(2) - (3)].token1), (yyvsp[(3) - (3)].expressao_info).tipo_operando1, (yyvsp[(3) - (3)].expressao_info).operacao);
		
	if(tipo_resultado != T_INVALID)
	{
		(yyval.token1) = tipo_resultado;
	}
	else
	{
		printf("ERRO: Operacao invalida na linha %d\n", get_line());
		YYERROR;
	}
	
	wml_operation_usage(T_VOID, T_VOID, (yyvsp[(1) - (3)].token1));
;}
    break;

  case 76:

    {
	int tipo_resultado = result_type((yyvsp[(1) - (2)].token1), (yyvsp[(2) - (2)].expressao_info).tipo_operando1, (yyvsp[(2) - (2)].expressao_info).operacao);
		
	if(tipo_resultado != T_INVALID)
	{
		(yyval.token1) = tipo_resultado;
	}
	else
	{
		printf("ERRO: Operacao invalida na linha %d\n", get_line());
		YYERROR;
	}
;}
    break;

  case 77:

    { (yyval.token1) = T_PLUS; ;}
    break;

  case 78:

    { (yyval.token1) = T_MINUS; ;}
    break;

  case 79:

    {
	(yyval.expressao_info).tipo_operando1 = T_EOF;
	(yyval.expressao_info).operacao = T_EOF;
;}
    break;

  case 80:

    {
	int tipo_resultado = result_type((yyvsp[(2) - (3)].token1), (yyvsp[(3) - (3)].expressao_info).tipo_operando1, (yyvsp[(3) - (3)].expressao_info).operacao);
	
	wml_operation_usage((yyvsp[(2) - (3)].token1), (yyvsp[(3) - (3)].expressao_info).tipo_operando1, (yyvsp[(3) - (3)].expressao_info).operacao);
	
	if(tipo_resultado != T_INVALID)
	{
		(yyval.expressao_info).tipo_operando1 = tipo_resultado;
		(yyval.expressao_info).operacao = (yyvsp[(1) - (3)].token1);
	}
	else
	{
		printf("ERRO: Operacao invalida na linha %d\n", get_line());
		YYERROR;
	}
;}
    break;

  case 81:

    {(yyval.token1) = T_PLUS; ;}
    break;

  case 82:

    {(yyval.token1) = T_MINUS; ;}
    break;

  case 83:

    {(yyval.token1) = T_OR; ;}
    break;

  case 84:

    {
	int tipo_resultado = result_type((yyvsp[(1) - (2)].token1), (yyvsp[(2) - (2)].expressao_info).tipo_operando1, (yyvsp[(2) - (2)].expressao_info).operacao);
	
	wml_operation_usage((yyvsp[(1) - (2)].token1), (yyvsp[(2) - (2)].expressao_info).tipo_operando1, (yyvsp[(2) - (2)].expressao_info).operacao);
		
	if(tipo_resultado != T_INVALID)
	{
		(yyval.token1) = tipo_resultado;
	}
	else
	{
		printf("ERRO: Operacao invalida na linha %d\n", get_line());
		YYERROR;
	}
;}
    break;

  case 85:

    {
	(yyval.expressao_info).tipo_operando1 = T_EOF;
	(yyval.expressao_info).operacao = T_EOF;
;}
    break;

  case 86:

    {
	int tipo_resultado = result_type((yyvsp[(2) - (3)].token1), (yyvsp[(3) - (3)].expressao_info).tipo_operando1, (yyvsp[(3) - (3)].expressao_info).operacao);

	if(tipo_resultado != T_INVALID)
	{
		(yyval.expressao_info).tipo_operando1 = tipo_resultado;
		(yyval.expressao_info).operacao = (yyvsp[(1) - (3)].token1);
	}
	else
	{
		printf("ERRO: Operacao invalida na linha %d\n", get_line());
		YYERROR;
	}	
;}
    break;

  case 87:

    { (yyval.token1) = T_TIMES;  ;}
    break;

  case 88:

    { (yyval.token1) = T_DIV;    ;}
    break;

  case 89:

    { (yyval.token1) = T_MOD;    ;}
    break;

  case 90:

    { (yyval.token1) = T_AND;    ;}
    break;

  case 91:

    { (yyval.token1) = T_DIVIDE; ;}
    break;

  case 92:

    {
	(yyval.token1) = (yyvsp[(1) - (1)].t_id_info).tipo;
;}
    break;

  case 93:

    {	
	if((yyvsp[(2) - (3)].token1) != T_INVALID)
	{
		(yyval.token1) = (yyvsp[(2) - (3)].token1);
	}
	else
	{
		printf("ERRO: Operacao invalida na linha %d\n", get_line());
		YYERROR;
	}
;}
    break;

  case 94:

    {
	if((yyvsp[(2) - (2)].token1) == T_BOOLEAN_CONST || (yyvsp[(2) - (2)].token1) == T_BOOLEAN)
	{
		(yyval.token1) = (yyvsp[(2) - (2)].token1);
	}
	else
	{
		printf("ERRO: utilizacao incorreta de 'not' na linha %d", get_line());
		YYERROR;
	}
	
	wml_operation_usage((yyvsp[(2) - (2)].token1), T_VOID, (yyvsp[(1) - (2)].token1));
;}
    break;

  case 95:

    {	
	(yyval.t_id_info).tipo = get_token_type((yyvsp[(1) - (1)].token2));
	(yyval.t_id_info).token2 = (yyvsp[(1) - (1)].token2);
	
	switch((yyval.t_id_info).tipo)
	{
	case T_INT_CONST:
	case T_REAL_CONST:
	case T_BOOLEAN_CONST:
		eh_constante = true;
		break;
	default:
		eh_constante = false;
	}
	
	if(eh_procedure_parametro || uso_de_const)
	{
		if(!search_parameter_or_var_on_current_scope_and_bellow((yyvsp[(1) - (1)].token2)) && !search_const_on_current_scope_and_bellow((yyvsp[(1) - (1)].token2)))
		{
			printf("ERRO: O simbolo %s eh utilizado na linha %d mas n�o foi declarado\n", get_token2_id((yyvsp[(1) - (1)].token2)), get_line());
			YYERROR;
		}
	}
	else
	{	if(!search_parameter_or_var_on_current_scope_and_bellow((yyvsp[(1) - (1)].token2)))
		{
			if(eh_constante) printf("ERRO: O simbolo %s eh utilizado como variavel na linha %d mas foi declarado como constante\n", get_token2_id((yyvsp[(1) - (1)].token2)), get_line());
			else printf("ERRO: O simbolo %s eh utilizado na linha %d mas n�o foi declarado\n", get_token2_id((yyvsp[(1) - (1)].token2)), get_line());
			YYERROR;
		}
	}
	
	uso_de_const = true;

;}
    break;

  case 96:

    {
	(yyval.t_id_info).tipo = T_INT_CONST;
	wml_int_const_def_usage((yyvsp[(1) - (1)].token_valor_int), T_EOF);
;}
    break;

  case 97:

    {
	(yyval.t_id_info).tipo = T_REAL_CONST;
;}
    break;

  case 98:

    {
	(yyval.t_id_info).tipo = T_BOOLEAN_CONST;
;}
    break;

  case 99:

    {
	(yyval.t_id_info).tipo = (yyvsp[(1) - (1)].t_id_info).tipo;
	(yyval.t_id_info).token2 = (yyvsp[(1) - (1)].t_id_info).token2;
	
	if((yyvsp[(1) - (1)].t_id_info).tipo == T_INT_CONST || (yyvsp[(1) - (1)].t_id_info).tipo == T_REAL_CONST || (yyvsp[(1) - (1)].t_id_info).tipo == T_BOOLEAN_CONST)
	{
		wml_int_const_def_usage(T_VOID, (yyvsp[(1) - (1)].t_id_info).token2);
		
	} else
	{
		wml_var_usage((yyvsp[(1) - (1)].t_id_info).token2);
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




