/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "teehee.y" /* yacc.c:339  */

    #include "CodeNode.h"
    #include <stdio.h>
    #include<string>
    #include<vector>
    #include<string.h>
    #include "y.tab.h"
    #include <sstream>

    extern int yylex(void);
    void yyerror(const char *msg);
    extern int lineCount;

    char *identToken;
    int numberToken;
    int  count_names = 0;
    int count_temp = 0;

std::string create_temp() {
    std::stringstream temp; 
    temp << "_temp" << count_temp;
    count_temp += 1;
    return temp.str();
}

enum Type { Integer, Array };
struct Symbol {
  std::string name;
  Type type;
};
struct Function {
  std::string name;
  std::vector<Symbol> declarations;
};

std::vector <Function> symbol_table;


Function *get_function() {
  int last = symbol_table.size()-1;
  return &symbol_table[last];
}

bool find(std::string &value) {
  Function *f = get_function();
  for(int i=0; i < f->declarations.size(); i++) {
    Symbol *s = &f->declarations[i];
    if (s->name == value) {
      return true;
    }
  }
  return false;
}

void add_function_to_symbol_table(std::string &value) {
  Function f; 
  f.name = value; 
  symbol_table.push_back(f);
}

void add_variable_to_symbol_table(std::string &value, Type t) {
  Symbol s;
  s.name = value;
  s.type = t;
  Function *f = get_function();
  f->declarations.push_back(s);
}

void print_symbol_table(void) {
  printf("symbol table:\n");
  printf("--------------------\n");
  for(int i=0; i<symbol_table.size(); i++) {
    printf("function: %s\n", symbol_table[i].name.c_str());
    for(int j=0; j<symbol_table[i].declarations.size(); j++) {
      printf("  locals: %s\n", symbol_table[i].declarations[j].name.c_str());
    }
  }
  printf("--------------------\n");
}

#line 147 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    PLUS = 258,
    MINUS = 259,
    MULT = 260,
    MOD = 261,
    DIV = 262,
    EQUALS = 263,
    LESSTHAN = 264,
    GREATERTHAN = 265,
    ISEQUAL = 266,
    ISNOTEQUAL = 267,
    GTEQUAL = 268,
    LTEQUAL = 269,
    NOT = 270,
    SEMICOLON = 271,
    L_PAREN = 272,
    R_PAREN = 273,
    L_CURLY = 274,
    R_CURLY = 275,
    L_BRACKET = 276,
    R_BRACKET = 277,
    COMMA = 278,
    DECIMAL = 279,
    READ = 280,
    WRITE = 281,
    IF = 282,
    IFELSE = 283,
    ELSE = 284,
    WHILELOOP = 285,
    INTEGER = 286,
    FUNCTION = 287,
    RETURN = 288,
    IDENTIFIER = 289,
    NUMBER = 290
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 82 "teehee.y" /* yacc.c:355  */

  struct CodeNode *code_node;
  char *op_val;
  int int_val;

#line 229 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 246 "y.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   124

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  63
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  122

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   290

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    96,    96,    97,   104,   110,   119,   141,   142,   145,
     149,   160,   164,   172,   181,   182,   186,   191,   199,   200,
     208,   214,   220,   223,   239,   252,   262,   263,   264,   267,
     270,   282,   292,   298,   306,   318,   328,   334,   340,   348,
     354,   360,   366,   372,   380,   394,   398,   406,   407,   410,
     411,   412,   415,   416,   419,   420,   421,   424,   425,   431,
     434,   457,   458,   461
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PLUS", "MINUS", "MULT", "MOD", "DIV",
  "EQUALS", "LESSTHAN", "GREATERTHAN", "ISEQUAL", "ISNOTEQUAL", "GTEQUAL",
  "LTEQUAL", "NOT", "SEMICOLON", "L_PAREN", "R_PAREN", "L_CURLY",
  "R_CURLY", "L_BRACKET", "R_BRACKET", "COMMA", "DECIMAL", "READ", "WRITE",
  "IF", "IFELSE", "ELSE", "WHILELOOP", "INTEGER", "FUNCTION", "RETURN",
  "IDENTIFIER", "NUMBER", "$accept", "prog_start", "functions", "function",
  "arguments", "argument", "statements", "statement_p", "statement",
  "arr_decl", "arr_assn", "s_var", "s_if", "s_while", "expression",
  "addop", "term", "mulop", "factor", "arr_access", "func",
  "expression_bool", "ne_comp", "term_bool", "e_comp", "factor_bool",
  "var", "neg", "declaration", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290
};
# endif

#define YYPACT_NINF -37

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-37)))

#define YYTABLE_NINF -47

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -29,   -17,    25,   -37,   -29,    14,   -37,   -37,    17,     2,
      37,    38,   -37,    44,    17,    19,   -37,    45,    47,    48,
      49,    33,   -26,    51,    50,    19,    52,   -37,   -37,   -37,
     -37,   -37,    61,   -37,    39,   -26,    59,    59,    54,    30,
      55,    36,    53,   -37,   -37,    63,   -37,    41,   -37,   -37,
      19,   -26,   -37,    65,     3,   -37,   -12,   -12,    56,    60,
      62,   -37,   -37,   -26,   -37,   -37,   -37,   -26,   -26,    64,
     -37,    36,   -37,   -37,   -26,   -37,     6,    43,   -37,   -37,
      20,    66,    68,   -37,    53,   -37,     8,    77,    10,   -37,
     -37,   -37,    79,   -12,   -37,   -37,   -37,   -12,    80,   -37,
     -37,   -37,   -26,   -37,    19,    43,   -37,    19,    36,    67,
      76,     5,   -37,    59,    81,    84,    19,    19,    85,    86,
     -37,   -37
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     3,     4,     0,     1,     5,     9,     0,
       0,     7,    10,     0,     9,    11,     8,     0,     0,     0,
       0,     0,    45,    60,     0,    11,     0,    20,    21,    17,
      14,    15,     0,    16,     0,    45,    62,    62,    63,    60,
      40,    22,    31,    35,    43,     0,    41,     0,     6,    13,
      11,    45,    60,     0,     0,    61,     0,     0,     0,     0,
       0,    32,    33,    45,    36,    38,    37,    45,    45,     0,
      12,    25,    18,    19,    45,    58,     0,    48,    53,    59,
       0,     0,     0,    42,    30,    34,     0,     0,     0,    50,
      51,    49,     0,     0,    54,    56,    55,     0,     0,    23,
      44,    39,    45,    57,    11,    47,    52,    11,    24,     0,
       0,    26,    29,    62,     0,     0,    11,    11,     0,     0,
      28,    27
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -37,   -37,   100,   -37,    93,   -37,   -23,   -37,   -37,   -37,
     -37,   -37,   -37,   -37,   -31,   -37,    46,   -37,    57,   -37,
     -37,    58,   -37,    15,   -37,    13,   -15,   -36,   -37
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     4,    10,    11,    24,    25,    26,    27,
      28,    29,    30,    31,    41,    63,    42,    67,    43,    44,
      45,    76,    93,    77,    97,    78,    46,    56,    33
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      32,    57,    49,     1,    54,    74,    61,    62,    39,    40,
      32,    61,    62,    61,    62,    89,    90,     5,    91,    53,
      71,    73,    52,    75,    92,     6,   101,    70,   103,    89,
      90,     8,    91,   113,   114,    32,    12,    86,    98,    61,
      62,    79,    79,    88,    17,    18,    19,   -46,     9,    20,
      21,    59,    22,    23,    94,    13,    95,    96,    64,    65,
      66,    14,    34,    15,    35,    36,    37,    38,    50,    51,
      48,   108,    47,    52,    55,    58,    69,   115,    79,    60,
      68,   109,    79,    72,   110,   102,    87,   111,    99,    32,
     100,    81,    32,   118,   119,    82,   112,    83,   104,   107,
     116,    32,    32,   117,     7,   120,   121,    16,   105,    84,
     106,     0,     0,     0,     0,    80,     0,     0,     0,     0,
       0,     0,     0,     0,    85
};

static const yytype_int8 yycheck[] =
{
      15,    37,    25,    32,    35,    17,     3,     4,    34,    35,
      25,     3,     4,     3,     4,     9,    10,    34,    12,    34,
      51,    18,    34,    35,    18,     0,    18,    50,    18,     9,
      10,    17,    12,    28,    29,    50,    34,    68,    18,     3,
       4,    56,    57,    74,    25,    26,    27,    17,    31,    30,
      31,    21,    33,    34,    11,    18,    13,    14,     5,     6,
       7,    23,    17,    19,    17,    17,    17,    34,    16,     8,
      20,   102,    21,    34,    15,    21,    35,   113,    93,    24,
      17,   104,    97,    18,   107,     8,    22,    20,    22,   104,
      22,    35,   107,   116,   117,    35,    20,    35,    19,    19,
      19,   116,   117,    19,     4,    20,    20,    14,    93,    63,
      97,    -1,    -1,    -1,    -1,    57,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    67
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    32,    37,    38,    39,    34,     0,    38,    17,    31,
      40,    41,    34,    18,    23,    19,    40,    25,    26,    27,
      30,    31,    33,    34,    42,    43,    44,    45,    46,    47,
      48,    49,    62,    64,    17,    17,    17,    17,    34,    34,
      35,    50,    52,    54,    55,    56,    62,    21,    20,    42,
      16,     8,    34,    62,    50,    15,    63,    63,    21,    21,
      24,     3,     4,    51,     5,     6,     7,    53,    17,    35,
      42,    50,    18,    18,    17,    35,    57,    59,    61,    62,
      57,    35,    35,    35,    52,    54,    50,    22,    50,     9,
      10,    12,    18,    58,    11,    13,    14,    60,    18,    22,
      22,    18,     8,    18,    19,    59,    61,    19,    50,    42,
      42,    20,    20,    28,    29,    63,    19,    19,    42,    42,
      20,    20
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    36,    37,    37,    38,    38,    39,    40,    40,    41,
      41,    42,    42,    42,    43,    43,    44,    44,    44,    44,
      44,    44,    44,    45,    46,    47,    48,    48,    48,    49,
      50,    50,    51,    51,    52,    52,    53,    53,    53,    54,
      54,    54,    54,    54,    55,    56,    56,    57,    57,    58,
      58,    58,    59,    59,    60,    60,    60,    61,    61,    61,
      62,    63,    63,    64
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     1,     1,     2,     8,     1,     3,     0,
       2,     0,     3,     2,     1,     1,     1,     1,     4,     4,
       1,     1,     2,     5,     6,     3,     8,    13,    12,     8,
       3,     1,     1,     1,     3,     1,     1,     1,     1,     4,
       1,     1,     3,     1,     4,     0,     1,     3,     1,     1,
       1,     1,     3,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     0,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
      if (yytable_value_is_error (yyn))
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 96 "teehee.y" /* yacc.c:1646  */
    {}
#line 1409 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 97 "teehee.y" /* yacc.c:1646  */
    {
        CodeNode *code_node = (yyvsp[0].code_node);
        printf("%s\n", code_node->code.c_str());
    }
#line 1418 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 104 "teehee.y" /* yacc.c:1646  */
    {
        CodeNode *node = new CodeNode;
        CodeNode *code_node1 = (yyvsp[0].code_node);
        node->code += code_node1->code;
        (yyval.code_node) = node; 
    }
#line 1429 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 110 "teehee.y" /* yacc.c:1646  */
    {
        CodeNode *code_node1 = (yyvsp[-1].code_node);
        CodeNode *code_node2 = (yyvsp[0].code_node);
        CodeNode *node = new CodeNode;
        node->code += code_node1->code + code_node2->code;
        (yyval.code_node) = node; 
    }
#line 1441 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 120 "teehee.y" /* yacc.c:1646  */
    {
    CodeNode *node = new CodeNode;
    std::string func_name = (yyvsp[-6].op_val);
    node->code = "";
    node->code += std::string("func ") + func_name + std::string("\n");

    // params arguments
    CodeNode *arguments = (yyvsp[-4].code_node);
    node->code += arguments->code;

    // statements
    CodeNode *statements = (yyvsp[-1].code_node);
    node->code += statements->code;

    node->code += std::string("endfunc\n");
    (yyval.code_node) = node;

    add_function_to_symbol_table(func_name);
}
#line 1465 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 141 "teehee.y" /* yacc.c:1646  */
    {}
#line 1471 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 142 "teehee.y" /* yacc.c:1646  */
    {}
#line 1477 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 145 "teehee.y" /* yacc.c:1646  */
    {
        CodeNode *node = new CodeNode;
        (yyval.code_node) = node; 
    }
#line 1486 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 149 "teehee.y" /* yacc.c:1646  */
    {
        // CodeNode *code_node1 = new CodeNode;
        // std::string id = $2;
        // code_node1->code += std::string(". ") + id + std::string("\n");
        // $$ = code_node1;

        // Type t = Integer;
        // add_variable_to_symbol_table(id , t);
    }
#line 1500 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 160 "teehee.y" /* yacc.c:1646  */
    {
        CodeNode *node = new CodeNode;
        (yyval.code_node) = node; 
    }
#line 1509 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 164 "teehee.y" /* yacc.c:1646  */
    {
        CodeNode *code_node1 = (yyvsp[-2].code_node);
        CodeNode *code_node2 = (yyvsp[0].code_node);
        CodeNode *node = new CodeNode;
        
        node->code += code_node1->code + code_node2->code;
        (yyval.code_node) = node;
    }
#line 1522 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 172 "teehee.y" /* yacc.c:1646  */
    {
        // CodeNode *code_node1 = $1;
        // CodeNode *code_node2 = $2;
        // CodeNode *node = new CodeNode;
        // node->code += code_node1->code + code_node2->code;
        // $$ = node;
    }
#line 1534 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 181 "teehee.y" /* yacc.c:1646  */
    {}
#line 1540 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 182 "teehee.y" /* yacc.c:1646  */
    {}
#line 1546 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 186 "teehee.y" /* yacc.c:1646  */
    {
        CodeNode *node = new CodeNode;
        node->code += (yyvsp[0].code_node)->code;
        (yyval.code_node) = node;
    }
#line 1556 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 191 "teehee.y" /* yacc.c:1646  */
    {
        CodeNode *node = new CodeNode;
        CodeNode *code_node1 = (yyvsp[0].code_node);

        node->code += code_node1->code;
        node->name = code_node1->name;
        (yyval.code_node) = node;
    }
#line 1569 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 199 "teehee.y" /* yacc.c:1646  */
    {}
#line 1575 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 200 "teehee.y" /* yacc.c:1646  */
    {
        CodeNode *node = new CodeNode;
        CodeNode *expression = (yyvsp[-1].code_node);
        std::string id = expression->name;
        node->code = expression->code;
        node->code += std::string(".> ") + id + std::string("\n");
        (yyval.code_node) = node;
    }
#line 1588 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 208 "teehee.y" /* yacc.c:1646  */
    {
        // CodeNode *node = new CodeNode;
        // node->code += $1->code;
        // node->name = $1->name;
        // $$ = node;
    }
#line 1599 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 214 "teehee.y" /* yacc.c:1646  */
    {
        // CodeNode *node = new CodeNode;
        // node->code += $1->code;
        // node->name = $1->name;
        // $$ = node;
    }
#line 1610 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 220 "teehee.y" /* yacc.c:1646  */
    {}
#line 1616 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 223 "teehee.y" /* yacc.c:1646  */
    {
    // std::string tmp = create_temp();
    // CodeNode *tmp_node = new CodeNode;
    // tmp_node->name = tmp;
    // tmp_node->code += tmp;

    std::string id = (yyvsp[-3].op_val);
    std::string num = (yyvsp[-1].op_val);
    
    CodeNode *node = new CodeNode;
    node->code = std::string(".[] ") + id + std::string(", ") + num + std::string("\n");
    node->name = id;
    (yyval.code_node) = node;
}
#line 1635 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 239 "teehee.y" /* yacc.c:1646  */
    {
    //std::string temp = create_temp();
    std::string name = (yyvsp[-5].op_val);
    std::string num = (yyvsp[-3].op_val);

    CodeNode *node = new CodeNode;
    //node->code = std::string(". ") + temp + std::string("\n");
    node->code += (yyvsp[0].code_node)->code;
    node->code += std::string("[]= ") + name + std::string(", ") + num + std::string(", ") + (yyvsp[0].code_node)->name + std::string("\n");
    (yyval.code_node) = node;
}
#line 1651 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 252 "teehee.y" /* yacc.c:1646  */
    {
    CodeNode *node = new CodeNode;
    node->code = (yyvsp[0].code_node)->code;
    node->name = (yyvsp[-2].code_node)->name;

    node->code += std::string("= ") + (yyvsp[-2].code_node)->name + std::string(", ") + (yyvsp[0].code_node)->name + std::string("\n");
    (yyval.code_node) = node;
}
#line 1664 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 262 "teehee.y" /* yacc.c:1646  */
    {}
#line 1670 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 263 "teehee.y" /* yacc.c:1646  */
    {}
#line 1676 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 264 "teehee.y" /* yacc.c:1646  */
    {}
#line 1682 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 267 "teehee.y" /* yacc.c:1646  */
    {}
#line 1688 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 270 "teehee.y" /* yacc.c:1646  */
    {
    std::string temp = create_temp();

    CodeNode* addop_node = (yyvsp[-1].code_node);

    CodeNode *node = new CodeNode;
    node->code = (yyvsp[-2].code_node)->code + (yyvsp[0].code_node)->code + std::string(". ")  + temp + std::string("\n");

    node->code += addop_node->name + temp + std::string(", ") + (yyvsp[-2].code_node)->name + std::string(", ") + (yyvsp[0].code_node)->name + std::string("\n");
    node->name = temp;
    (yyval.code_node) = node; 
}
#line 1705 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 282 "teehee.y" /* yacc.c:1646  */
    {
        CodeNode *node = new CodeNode;
        CodeNode *term = (yyvsp[0].code_node);
        
        node->name = term->name;
        node->code += term->code;
        (yyval.code_node) = node;
    }
#line 1718 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 292 "teehee.y" /* yacc.c:1646  */
    {
        CodeNode* node = new CodeNode;
        node->name = std::string("+ ");
        node->code += "";
        (yyval.code_node) = node;
    }
#line 1729 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 298 "teehee.y" /* yacc.c:1646  */
    {
        CodeNode* node = new CodeNode;
        node->name = std::string("- ");
        node->code += "";
        (yyval.code_node) = node;
    }
#line 1740 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 306 "teehee.y" /* yacc.c:1646  */
    {
    std::string temp = create_temp();

    CodeNode* mulop_node = (yyvsp[-1].code_node);
  
    CodeNode *node = new CodeNode;
    node->code = (yyvsp[-2].code_node)->code + (yyvsp[0].code_node)->code + std::string(". ")  + temp  + std::string("\n");

    node->code += mulop_node->name + temp + std::string(", ") + (yyvsp[-2].code_node)->name + std::string(", ") + (yyvsp[0].code_node)->name + std::string("\n");
    node->name = temp;
    (yyval.code_node) = node; 
}
#line 1757 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 318 "teehee.y" /* yacc.c:1646  */
    {
        CodeNode *node = new CodeNode;
        CodeNode *factor = (yyvsp[0].code_node);
        
        node->name = factor->name;
        node->code += factor->code;
        (yyval.code_node) = node;
    }
#line 1770 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 328 "teehee.y" /* yacc.c:1646  */
    {
        CodeNode* node = new CodeNode;
        node->name = std::string("* ");
        node->code += "";
        (yyval.code_node) = node;
    }
#line 1781 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 334 "teehee.y" /* yacc.c:1646  */
    {
        CodeNode* node = new CodeNode;
        node->name = std::string("/ ");
        node->code += "";
        (yyval.code_node) = node;
    }
#line 1792 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 340 "teehee.y" /* yacc.c:1646  */
    {
        CodeNode* node = new CodeNode;
        node->name = std::string("\% ");
        node->code += "";
        (yyval.code_node) = node;
    }
#line 1803 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 348 "teehee.y" /* yacc.c:1646  */
    {
    CodeNode *node = new CodeNode;
    node->name = (yyvsp[-1].code_node)->name;
    node->code += (yyvsp[-3].code_node)->code + (yyvsp[-1].code_node)->code;
    (yyval.code_node) = node;
}
#line 1814 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 354 "teehee.y" /* yacc.c:1646  */
    {
        CodeNode *node = new CodeNode;
        //node->code = "";
        node->name = (yyvsp[0].op_val);
        (yyval.code_node) = node;
    }
#line 1825 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 360 "teehee.y" /* yacc.c:1646  */
    {
        CodeNode *node = new CodeNode;
        node->code = (yyvsp[0].code_node)->code;
        node->name = (yyvsp[0].code_node)->name;
        (yyval.code_node) = node;
    }
#line 1836 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 366 "teehee.y" /* yacc.c:1646  */
    {
        CodeNode *node = new CodeNode;
        node->code = "";
        node->name = (yyvsp[-2].op_val);
        (yyval.code_node) = node;
    }
#line 1847 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 372 "teehee.y" /* yacc.c:1646  */
    {
        CodeNode *node = new CodeNode;
        node->code = (yyvsp[0].code_node)->code;
        node->name = (yyvsp[0].code_node)->name;
        (yyval.code_node) = node;
    }
#line 1858 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 380 "teehee.y" /* yacc.c:1646  */
    {
        std::string id = (yyvsp[-3].op_val);
        std::string index = (yyvsp[-1].op_val);
        std::string tmp = create_temp();

        CodeNode *node = new CodeNode;
        node->name = tmp;
        node->code = std::string(". ") + tmp + std::string("\n");
        node->code += std::string("=[] ") + tmp + std::string(", ") + id + std::string(", ") + index + std::string("\n");

        (yyval.code_node) = node;
    }
#line 1875 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 394 "teehee.y" /* yacc.c:1646  */
    {
    CodeNode *node = new CodeNode;
    (yyval.code_node) = node;
}
#line 1884 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 398 "teehee.y" /* yacc.c:1646  */
    {
        CodeNode *node = new CodeNode;
        node->code = "";
        node->name = (yyvsp[0].op_val);
        (yyval.code_node) = node;
    }
#line 1895 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 406 "teehee.y" /* yacc.c:1646  */
    {}
#line 1901 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 407 "teehee.y" /* yacc.c:1646  */
    {}
#line 1907 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 410 "teehee.y" /* yacc.c:1646  */
    {}
#line 1913 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 411 "teehee.y" /* yacc.c:1646  */
    {}
#line 1919 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 412 "teehee.y" /* yacc.c:1646  */
    {}
#line 1925 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 415 "teehee.y" /* yacc.c:1646  */
    {}
#line 1931 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 416 "teehee.y" /* yacc.c:1646  */
    {}
#line 1937 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 419 "teehee.y" /* yacc.c:1646  */
    {}
#line 1943 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 420 "teehee.y" /* yacc.c:1646  */
    {}
#line 1949 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 421 "teehee.y" /* yacc.c:1646  */
    {}
#line 1955 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 424 "teehee.y" /* yacc.c:1646  */
    {}
#line 1961 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 425 "teehee.y" /* yacc.c:1646  */
    {
        CodeNode *node = new CodeNode;
        node->code = "";
        node->name = (yyvsp[0].op_val);
        (yyval.code_node) = node;
    }
#line 1972 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 431 "teehee.y" /* yacc.c:1646  */
    {}
#line 1978 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 434 "teehee.y" /* yacc.c:1646  */
    {
    CodeNode *node = new CodeNode;
    node->code = "";
    node->name = (yyvsp[0].op_val);
    (yyval.code_node) = node;
}
#line 1989 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 457 "teehee.y" /* yacc.c:1646  */
    {}
#line 1995 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 458 "teehee.y" /* yacc.c:1646  */
    {}
#line 2001 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 461 "teehee.y" /* yacc.c:1646  */
    {
        CodeNode *node = new CodeNode;
        std::string id = (yyvsp[0].op_val);
        node->code += std::string(". ") + id + std::string("\n");
        (yyval.code_node) = node;

        //Type t = Integer;
        // add_variable_to_symbol_table(id , t);
    }
#line 2015 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2019 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
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
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 485 "teehee.y" /* yacc.c:1906  */


int main(int argc, char **argv)
{
    yyparse();
   print_symbol_table();
   return 0;
}

void yyerror(const char *msg)
{
   printf("** Line %d: %s\n", lineCount, msg);
   exit(1);
}
