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
#line 1 "egemenkilic-hw3.y" /* yacc.c:339  */

#define INITIAL_SIZE 10
#ifdef YYDEBUG
yydebug = 1;
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#include "egemenkilic-hw3.h"
void yyerror (const char *msg) /* Called by yyparse on error */ {return; }

// Function Headers
int checkIdentifier(Scope *scope, ExprNode *expr);
void addExpressionToList(Scope *scope, ExprNode *newExpr);

void setIdent (IdentNode * ident1, StringNode * str1);
void sendMail (ExprNode * expr1, RecipientList *recipientList, char *currentSenderEmail);
void initGlobalScope();
void enterScope();
void exitScope();
void validateDateTime(char* date, char* time, int lineNum);

bool isValidDate(char* date);
bool isValidTime(char* time);

ExprNode * makeExpressionNodeFromString(StringNode str);
ExprNode * makeExpressionNodeFromIdent(IdentNode ident);

RecipientNode* createRecipientNode(IdentNode ident, char* email);
RecipientNode* createRecipientNodeFromString(char* name, char* email);
RecipientList* createRecipientList(RecipientNode* firstNode);
RecipientList* addRecipientToList(RecipientNode* newNode, RecipientList* list);

ScheduledEmail* createScheduledEmail(char *date, char *time, char *senderEmail, char *recipientInfo, char *message);
void addScheduledEmailToList(ScheduledEmail *newEmail);

Scope *globalScope = NULL;
Scope *currentScope = NULL;

// Dynamic array to keep track of errors
ExprNode ** expressions;
int expressionsSize = 100;
int exprIndex = 0;

// This is a flag indicating there is a semantic error in the program 
int error = 0;

char ** errors;
char* currentSenderEmail = NULL;
char* globalMessage = NULL;
char* globalTo = NULL;
char* scheduleDate = NULL;
char* scheduleTime = NULL;
char* globalName = NULL;

char* userecipientMailInfo = NULL;
char* userecipientMailName = NULL;

int errorSize = 100;
int errorIndex = 0;

ScheduledEmail *scheduledEmailsHead = NULL;


#line 134 "egemenkilic-hw3.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "egemenkilic-hw3.tab.h".  */
#ifndef YY_YY_EGEMENKILIC_HW3_TAB_H_INCLUDED
# define YY_YY_EGEMENKILIC_HW3_TAB_H_INCLUDED
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
    tIDENT = 258,
    tSTRING = 259,
    tADDRESS = 260,
    tDATE = 261,
    tTIME = 262,
    tMAIL = 263,
    tENDMAIL = 264,
    tSCHEDULE = 265,
    tENDSCHEDULE = 266,
    tSEND = 267,
    tTO = 268,
    tFROM = 269,
    tSET = 270,
    tCOMMA = 271,
    tCOLON = 272,
    tLPR = 273,
    tRPR = 274,
    tLBR = 275,
    tRBR = 276,
    tAT = 277
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 69 "egemenkilic-hw3.y" /* yacc.c:355  */

    IdentNode identNode;
    StringNode stringNode;
    ExprNode *exprNodePtr;
    ScheduledEmail * scheduledEmailPtr;
    int lineNum;

    RecipientNode *recipientNode;
    RecipientList *recipientList;
    

#line 209 "egemenkilic-hw3.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_EGEMENKILIC_HW3_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 226 "egemenkilic-hw3.tab.c" /* yacc.c:358  */

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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   56

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  23
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  14
/* YYNRULES -- Number of rules.  */
#define YYNRULES  24
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  63

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   277

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
      15,    16,    17,    18,    19,    20,    21,    22
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    96,    96,    99,   100,   101,   104,   104,   118,   119,
     120,   121,   124,   125,   128,   144,   148,   154,   157,   162,
     165,   168,   173,   173,   206
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "tIDENT", "tSTRING", "tADDRESS", "tDATE",
  "tTIME", "tMAIL", "tENDMAIL", "tSCHEDULE", "tENDSCHEDULE", "tSEND",
  "tTO", "tFROM", "tSET", "tCOMMA", "tCOLON", "tLPR", "tRPR", "tLBR",
  "tRBR", "tAT", "$accept", "program", "statements", "mailBlock", "$@1",
  "statementList", "sendStatements", "sendStatement", "option",
  "recipientList", "recipient", "scheduleStatement", "$@2", "setStatement", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277
};
# endif

#define YYPACT_NINF -47

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-47)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      -8,     9,    11,    12,   -47,    -8,    -8,    10,     6,   -47,
     -47,   -47,     8,    22,   -47,    13,     1,   -47,     5,    15,
      19,     1,     1,     1,    16,    -2,   -47,   -47,   -47,   -47,
      23,   -47,   -47,    17,    18,    20,    24,    21,    25,    26,
      28,    14,    27,    31,   -47,    33,    34,    32,   -47,    26,
      30,    35,    38,   -47,   -47,    41,    30,    36,    37,   -47,
     -47,   -47,   -47
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     0,     2,     3,     3,     0,     0,     1,
       5,     4,     0,     0,     6,     0,     8,    24,     0,     0,
       0,     8,     8,     8,     0,     0,     7,    10,    11,     9,
       0,    16,    15,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    17,    22,     0,     0,     0,    14,     0,
       0,     0,     0,    19,    18,     0,    12,     0,     0,    23,
      13,    21,    20
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -47,   -47,     0,   -47,   -47,    -1,   -26,   -46,   -47,   -12,
     -47,   -47,   -47,     3
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     5,    16,    20,    55,    21,    33,    42,
      43,    22,    50,    23
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
       1,    31,    32,     6,    56,    10,    11,     2,     6,     6,
      56,    18,     9,    19,     8,    12,     2,    45,    46,    47,
      27,    28,    29,     7,    13,    14,    15,    24,    26,    34,
      60,    38,    17,    37,    36,    25,    30,    54,    35,     0,
      57,    39,    19,    58,    41,    44,    40,    49,    48,    51,
      52,    53,    59,     0,     0,    61,    62
};

static const yytype_int8 yycheck[] =
{
       8,     3,     4,     0,    50,     5,     6,    15,     5,     6,
      56,    10,     0,    12,     3,     5,    15,     3,     4,     5,
      21,    22,    23,    14,    18,    17,     4,    22,     9,     6,
      56,     7,    19,    13,    16,    20,    20,    49,    21,    -1,
       5,    20,    12,     5,    18,    17,    21,    16,    21,    16,
      16,    19,    11,    -1,    -1,    19,    19
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     8,    15,    24,    25,    26,    36,    14,     3,     0,
      25,    25,     5,    18,    17,     4,    27,    19,    10,    12,
      28,    30,    34,    36,    22,    20,     9,    28,    28,    28,
      20,     3,     4,    31,     6,    21,    16,    13,     7,    20,
      21,    18,    32,    33,    17,     3,     4,     5,    21,    16,
      35,    16,    16,    19,    32,    29,    30,     5,     5,    11,
      29,    19,    19
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    23,    24,    25,    25,    25,    27,    26,    28,    28,
      28,    28,    29,    29,    30,    31,    31,    32,    32,    33,
      33,    33,    35,    34,    36
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     2,     0,     7,     0,     2,
       2,     2,     1,     2,     8,     1,     1,     1,     3,     3,
       5,     5,     0,    11,     5
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
        case 6:
#line 104 "egemenkilic-hw3.y" /* yacc.c:1646  */
    { 
    enterScope(); 
    currentSenderEmail = strdup((yyvsp[-1].stringNode).value); 
    globalTo = currentSenderEmail;

    }
#line 1340 "egemenkilic-hw3.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 110 "egemenkilic-hw3.y" /* yacc.c:1646  */
    {
    exitScope();
    free(currentSenderEmail); // Free the sender's email after use
    currentSenderEmail = NULL;
    globalTo = NULL;
}
#line 1351 "egemenkilic-hw3.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 128 "egemenkilic-hw3.y" /* yacc.c:1646  */
    {
                // printf("sendStatement: option value: %s\n", $3->stringValue);
                RecipientNode *current = (yyvsp[-1].recipientList)->head;
                userecipientMailInfo = current->email;
                userecipientMailName = current->name;
                // printf("sendStatement: Current sender name: %s\n\n", userecipientMailName);
                // printf("sendStatement: Email scheduled to be sent from %s\n to", currentSenderEmail);
                if (!error && userecipientMailName && scheduleDate && scheduleTime){
                    char* formattedMessage = (globalMessage != NULL) ? globalMessage : "(No message)";
                    // printf("Expected: E-mail scheduled to be sent from %s on %s, %s to %s: %s\n", globalTo, scheduleDate, scheduleTime, userecipientMailName, formattedMessage);
                }
                sendMail((yyvsp[-5].exprNodePtr), (yyvsp[-1].recipientList), currentSenderEmail); // $3 is the message and $7 is the recipientList
                //7 DE EKLENMELI
}
#line 1370 "egemenkilic-hw3.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 144 "egemenkilic-hw3.y" /* yacc.c:1646  */
    {
        (yyval.exprNodePtr) = makeExpressionNodeFromString((yyvsp[0].stringNode));

}
#line 1379 "egemenkilic-hw3.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 148 "egemenkilic-hw3.y" /* yacc.c:1646  */
    {
        (yyval.exprNodePtr) = makeExpressionNodeFromIdent((yyvsp[0].identNode));
}
#line 1387 "egemenkilic-hw3.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 154 "egemenkilic-hw3.y" /* yacc.c:1646  */
    {
            (yyval.recipientList) = createRecipientList((yyvsp[0].recipientNode));
            }
#line 1395 "egemenkilic-hw3.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 157 "egemenkilic-hw3.y" /* yacc.c:1646  */
    {
                (yyval.recipientList) = addRecipientToList((yyvsp[-2].recipientNode), (yyvsp[0].recipientList));
            }
#line 1403 "egemenkilic-hw3.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 162 "egemenkilic-hw3.y" /* yacc.c:1646  */
    {
            (yyval.recipientNode) = createRecipientNodeFromString(NULL, (yyvsp[-1].stringNode).value); // Assuming $2 is email of type char*
          }
#line 1411 "egemenkilic-hw3.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 165 "egemenkilic-hw3.y" /* yacc.c:1646  */
    {
            (yyval.recipientNode) = createRecipientNodeFromString((yyvsp[-3].stringNode).value, (yyvsp[-1].stringNode).value); // $2 is name (stringNode), $4 is email (char*)
          }
#line 1419 "egemenkilic-hw3.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 168 "egemenkilic-hw3.y" /* yacc.c:1646  */
    {
            (yyval.recipientNode) = createRecipientNode((yyvsp[-3].identNode), (yyvsp[-1].stringNode).value); // $2 is identifier (IdentNode), $4 is email (char*)
          }
#line 1427 "egemenkilic-hw3.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 173 "egemenkilic-hw3.y" /* yacc.c:1646  */
    {
                        validateDateTime((yyvsp[-4].stringNode).value, (yyvsp[-2].stringNode).value, (yyvsp[-4].stringNode).lineNum);

                        scheduleDate = (yyvsp[-4].stringNode).value;
                        // printf("scheduleStatement: scheduleDate: %s\n", scheduleDate);
                        scheduleTime = (yyvsp[-2].stringNode).value;
                        // printf("scheduleStatement: scheduleTime: %s\n", scheduleTime);
                        // printf("scheduleStatement: userecipientMailInfo %s\n", userecipientMailInfo);
                        // printf("scheduleStatement: userecipientMailName %s\n", userecipientMailName);
                        

       
                        // printf("scheduleStatement: Sender mail address: %s\n", globalTo);
                        // printf("scheduleStatement: userecipientMailName: %s\n", userecipientMailName);
                        // printf("scheduleStatement: GlobalName: %s\n\n", globalName);
                        // printf("scheduleStatement: globalMessage: %s\n", globalMessage);
                        if (!error && userecipientMailName){
                                char* formattedMessage = (globalMessage != NULL) ? globalMessage : "(No message)";
                                printf("E-mail scheduled to be sent from %s on %s, %s to %s: %s\n", globalTo, scheduleDate, scheduleTime, userecipientMailName, formattedMessage);
                        }
                        // ScheduledEmail* createScheduledEmail(char *date, char *time, char *senderEmail, char *recipientInfo, char *message);
                        if (userecipientMailInfo){
                            ScheduledEmail *newEmail = createScheduledEmail(scheduleDate, scheduleTime, globalTo, userecipientMailName, globalMessage);
                            addScheduledEmailToList(newEmail);
                        }
                        // addScheduledEmailToList(newEmail);
                        
                        // printf("Date Value %s\n", $4.value);
                        // printf("Time Value %s\n", $4.value);
                        // printf("Date Line num %d\n", $4.value);
                    }
#line 1463 "egemenkilic-hw3.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 206 "egemenkilic-hw3.y" /* yacc.c:1646  */
    {
                // Same thing as assign
                setIdent(&(yyvsp[-3].identNode), &(yyvsp[-1].stringNode));
                }
#line 1472 "egemenkilic-hw3.tab.c" /* yacc.c:1646  */
    break;


#line 1476 "egemenkilic-hw3.tab.c" /* yacc.c:1646  */
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
#line 211 "egemenkilic-hw3.y" /* yacc.c:1906  */


ScheduledEmail* createScheduledEmail(char *date, char *time, char *senderEmail, char *recipientInfo, char *message) {
    ScheduledEmail *newEmail = malloc(sizeof(ScheduledEmail));
    if (newEmail == NULL) {
        fprintf(stderr, "Memory allocation failed for ScheduledEmail\n");
        exit(EXIT_FAILURE);
    }

    // Initialize fields of newEmail
    newEmail->date = strdup(date);
    /* printf("createScheduledEmail: newEmail->date: %s", newEmail->date); */
    newEmail->time = strdup(time);
    /* printf("createScheduledEmail: newEmail->time: %s", newEmail->time); */
    newEmail->senderEmail = strdup(senderEmail);
    /* printf("createScheduledEmail: newEmail->senderEmail: %s", newEmail->senderEmail); */
    newEmail->recipientInfo = strdup(recipientInfo); // Set recipientInfo
    /* printf("createScheduledEmail: recipientInfo: %s", recipientInfo); */
    newEmail->message = strdup(message); // Set message
    /* printf("createScheduledEmail: newEmail->message: %s", newEmail->message); */
    newEmail->next = NULL;
    return newEmail;
}
// Helper function to compare dates in "dd/mm/yyyy" format
int compareDates(const char* date1, const char* date2) {
    int day1, month1, year1, day2, month2, year2;
    sscanf(date1, "%d/%d/%d", &day1, &month1, &year1);
    sscanf(date2, "%d/%d/%d", &day2, &month2, &year2);

    if (year1 != year2) return year1 - year2;
    if (month1 != month2) return month1 - month2;
    return day1 - day2;
}

// Helper function to compare times in "hh:mm" format
int compareTimes(const char* time1, const char* time2) {
    int hour1, minute1, hour2, minute2;
    sscanf(time1, "%d:%d", &hour1, &minute1);
    sscanf(time2, "%d:%d", &hour2, &minute2);

    if (hour1 != hour2) return hour1 - hour2;
    return minute1 - minute2;
}

void addScheduledEmailToList(ScheduledEmail *newEmail) {
    if (newEmail == NULL) return;

    newEmail->next = scheduledEmailsHead;
    scheduledEmailsHead = newEmail;
}

void addScheduledEmail(char *date, char *time, char *senderEmail, char *recipientInfo, char *message, int lineNum) {
    ScheduledEmail *newEmail = (ScheduledEmail *)malloc(sizeof(ScheduledEmail));
    newEmail->date = strdup(date);
    newEmail->time = strdup(time);
    newEmail->senderEmail = strdup(senderEmail);
    newEmail->recipientInfo = strdup(recipientInfo);
    newEmail->message = strdup(message);
    newEmail->lineNum = lineNum;
    newEmail->next = NULL;

    // Add to the head of the list or another strategy as preferred
    newEmail->next = scheduledEmailsHead;
    scheduledEmailsHead = newEmail;
}

// Sorting function
void sortScheduledEmails() {
    /* printf("Inside sortScheduledEmails\n"); */
    bool swapped;
    ScheduledEmail *current;
    ScheduledEmail *lastPtr = NULL;

    if (scheduledEmailsHead == NULL)
        return;

    do {
        swapped = false;
        current = scheduledEmailsHead;

        while (current->next != lastPtr) {
            int dateComparison = compareDates(current->date, current->next->date);
            /* printf("sortScheduledEmails dateComparison: %s", dateComparison); */
            int timeComparison = compareTimes(current->time, current->next->time);
            /* printf("sortScheduledEmails timeComparison: %s", timeComparison); */

            if (dateComparison > 0 || (dateComparison == 0 && (timeComparison > 0 || (timeComparison == 0 && current->lineNum > current->next->lineNum)))) {
                // Swap current and current->next
                ScheduledEmail *temp = current->next;
                current->next = temp->next;
                temp->next = current;
                if (current == scheduledEmailsHead) {
                    scheduledEmailsHead = temp;
                }
                swapped = true;
            }
            current = current->next;
        }
        lastPtr = current;
    } while (swapped);
}

// Helper function to convert a month number to its name
const char* getMonthName(int month) {
    const char* months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    if (month >= 1 && month <= 12) {
        return months[month - 1];
    }
    return "";
}

// Function to format date from "dd/mm/yyyy" to "Month Day, Year"
char* formatDate(const char* date) {
    int day, month, year;
    sscanf(date, "%d/%d/%d", &day, &month, &year);

    const char* monthName = getMonthName(month);
    char* formattedDate = (char*)malloc(30 * sizeof(char)); // Allocate enough space

    if (formattedDate != NULL) {
        sprintf(formattedDate, "%s %d, %d", monthName, day, year);
    }

    return formattedDate; // Remember to free this memory after use!
}

void printScheduledEmails() {
    sortScheduledEmails();
    ScheduledEmail *current = scheduledEmailsHead;
    while (current != NULL) {
        char* formattedDate = formatDate(current->date);
        printf("E-mail scheduled to be sent from %s on %s, %s to %s: %s\n",
               current->senderEmail, formattedDate, current->time, current->recipientInfo, current->message);
        free(formattedDate); // Free the formatted date string after use
        current = current->next;
    }
}

bool isValidDate(char* date) {
    int day, month, year;

    if (sscanf(date, "%d/%d/%d", &day, &month, &year) != 3) return false; // Incorrect format
    if (day < 1 || day > 31) return false;
    if (month < 1 || month > 12) return false;
    /* if (year < 1900 || year > 2100) return false; // Adjust year range as needed */

    // Check for leap year if needed

    return true;
}

bool isValidTime(char* time) {
    int hour, minute;

    if (sscanf(time, "%d:%d", &hour, &minute) != 2) return false; // Incorrect format
    if (hour < 0 || hour > 23) return false;
    if (minute < 0 || minute > 59) return false;

    return true;
}

Scope* createNewScope(Scope *parent) {
    Scope *newScope = malloc(sizeof(Scope));
    newScope->variables = malloc(sizeof(ExprNode*) * INITIAL_SIZE); // Define INITIAL_SIZE
    newScope->varCount = 0;
    newScope->varSize = INITIAL_SIZE;
    newScope->parent = parent;
    return newScope;
}

void validateDateTime(char* date, char* time, int lineNum) {
    if (!isValidDate(date)) {
        error = 1;
        printf("ERROR at line %d: date object is not correct (%s)\n", lineNum, date);
    }
    if (!isValidTime(time)) {
        error = 1;
        printf("ERROR at line %d: time object is not correct (%s)\n", lineNum, time);
    }
}

void enterScope() {
    Scope *newScope = createNewScope(currentScope);
    currentScope = newScope;
}

void exitScope() {
    if (currentScope->parent != NULL) {
        Scope *temp = currentScope;
        currentScope = currentScope->parent;
        free(temp); // Also, free the variables and the list itself
    }
}

void initGlobalScope() {
    globalScope = createNewScope(NULL); // NULL as it has no parent
    currentScope = globalScope;
}

int checkIdentifier(Scope *scope, ExprNode *expr) {
    /* printf("checkIdentifier: Checking for identifier '%s'\n", expr->value); */
    if (expr->value == NULL) {
        return -1; // Indicates the expression is a string.
    }

    // Start checking from the current scope and move up to parent scopes.
    while (scope != NULL) {
        /* printf("checkIdentifier: Checking scope with %d variables\n", scope->varCount); */
        /* int i;
        for (i = 0; i < scope->varCount; i++) {
            if (scope->variables[i] != NULL && strcmp(expr->value, scope->variables[i]->value) == 0) {
                printf("checkIdentifier: Found '%s' in current scope at index %d\n", expr->value, i);
                // Identifier found in the current scope.
                return i;
            }
        } */
        // Move to the parent scope if the identifier is not found in the current scope.
        scope = scope->parent;
        /* printf("checkIdentifier: Moving to parent scope\n"); */
    }

    // Identifier not found in any scope.
    /* printf("checkIdentifier: Identifier '%s' not found in any scope\n", expr->value); */
    return -2;
}

void addExpressionToList(Scope *scope, ExprNode *newExpr) {
    // Ensure the scope and new expression are valid
    if (scope == NULL || newExpr == NULL) {
        return;
    }

    // Check if the variable already exists in the current scope
    int i;
    for (i = 0; i < scope->varCount; i++) {
        if (scope->variables[i] != NULL && strcmp(newExpr->value, scope->variables[i]->value) == 0) {
            // Update the existing variable
            scope->variables[i]->stringValue = newExpr->stringValue;
            return; // Updated the existing entry, so no need to add a new one
        }
    }

    // If the variable is not found, add it as a new entry
    // Check if the current scope's variable list is full
    if (scope->varCount >= scope->varSize) {
        // Double the size of the variable list
        scope->varSize *= 2;
        scope->variables = realloc(scope->variables, sizeof(ExprNode*) * scope->varSize);
        // Check for allocation failure
        if (scope->variables == NULL) {
            fprintf(stderr, "Memory reallocation failed for scope variables\n");
            exit(EXIT_FAILURE);
        }
    }

    // Add the new expression to the current scope's variable list
    scope->variables[scope->varCount] = newExpr;
    scope->varCount++;
}

RecipientNode* createRecipientNode(IdentNode ident, char* email) {
    /* printf("\ncreateRecipientNode: Creating recipient node with ident '%s' and email '%s'\n", ident.value, email); */
    RecipientNode* newNode = (RecipientNode*)malloc(sizeof(RecipientNode));
    if (newNode == NULL) {
        /* fprintf(stderr, "Memory allocation failed for RecipientNode\n"); */
        return NULL;
    }

    ExprNode tempExpr;
    tempExpr.value = ident.value;
    int exprId = checkIdentifier(currentScope, &tempExpr);

    if (exprId >= 0 && exprId < exprIndex && expressions[exprId]) {
        // Identifier found, use its string value from expressions array
        newNode->name = strdup(expressions[exprId]->stringValue);
    } else {
        // Identifier not found, use the identifier's name as-is
        newNode->name = strdup(ident.value);
    }

    newNode->email = strdup(email); // Copy the email
    newNode->lineNum = ident.lineNum;
    newNode->next = NULL;
    /* printf("createRecipientNode: Recipient node creation successful\n\n"); */

    return newNode;
}

RecipientNode* createRecipientNodeFromString(char* name, char* email) {
    /* printf("\ncreateRecipientNodeFromString: Creating recipient node with name '%s' and email '%s'\n", name, email); */
    RecipientNode* newNode = (RecipientNode*)malloc(sizeof(RecipientNode));
    if (newNode == NULL) {
        /* fprintf(stderr, "Memory allocation failed for RecipientNode\n"); */
        return NULL;
    }
    newNode->name = name ? strdup(name) : NULL; // Copy the name if it's not NULL
    newNode->email = strdup(email); // Copy the email
    newNode->lineNum = -1; // Line number might not be relevant for string literals
    newNode->next = NULL;
    /* printf("\n\ncreateRecipientNodeFromString: Create recipient node is successful\n"); */

    return newNode;
}

RecipientList* createRecipientList(RecipientNode* firstNode) {
    /* printf("\ncreateRecipientList: Creating new recipient list\n"); */
    RecipientList* newList = (RecipientList*)malloc(sizeof(RecipientList));
    if (newList == NULL) {
        /* fprintf(stderr, "Memory allocation failed for RecipientList\n"); */
        return NULL;
    }
    /* printf("createRecipientList: First node name '%s', email '%s'\n\n", firstNode->name, firstNode->email); */
    newList->head = firstNode;
    return newList;
}

RecipientList* addRecipientToList(RecipientNode* newNode, RecipientList* list) {
    /* printf("\naddRecipientToList: Adding recipient node to list\n"); */
    if (list == NULL) {
        /* fprintf(stderr, "RecipientList is NULL\n"); */
        return NULL;
    }
    if (newNode == NULL) {
        /* fprintf(stderr, "New RecipientNode is NULL\n"); */
        return list;
    }
    /* printf("addRecipientToList: New node name '%s', email '%s'\n\n", newNode->name, newNode->email); */
    // Adding to the end of the list
    newNode->next = list->head;
    list->head = newNode;
    
    return list;
}

ExprNode * makeExpressionNodeFromIdent(IdentNode ident){

    ExprNode * newNode = (ExprNode *)malloc(sizeof(ExprNode));
    newNode->lineNum = ident.lineNum;
    /* printf("\nmakeExpressionNodeFromIdent: New node has line number: %d\n", ident.lineNum); */
    /* newNode->identifier = ident.value; */
    newNode->value = ident.value;
    /* printf("\nmakeExpressionNodeFromIdent: Creating new node value with ident.value: %s\n", ident.value); */
    newNode->stringValue = NULL;
    return newNode;
}

ExprNode * makeExpressionNodeFromString(StringNode str){

    ExprNode * newNode = (ExprNode *)malloc(sizeof(ExprNode));
    /* We only need the value of the value */
    /* newNode->identifier = NULL; */
    newNode->value = NULL;
    /* printf("makeExpressionNodeFromString: Creating new node value with str.value: %s\n", str.value); */
    globalMessage = str.value;
    /* printf("globalMessage: %s\n", globalMessage);
    printf("globalTo: %s\n", globalTo); */
    newNode->lineNum = str.lineNum;
    /* printf("makeExpressionNodeFromString: New node has line number: %d\n", str.lineNum); */
    newNode->stringValue = str.value;
    return newNode;
}

void setIdent (IdentNode * ident1, StringNode * str1){
    // Create a new ExprNode for the identifier
    ExprNode *newExpr = makeExpressionNodeFromIdent(*ident1);
    /* printf("setIdent: Setting newExpr->stringValue to %s\n", str1->value); */
    newExpr->stringValue = str1->value;

    // Add the new expression to the current scope
    addExpressionToList(currentScope, newExpr);
    /* printf("setIdent: Added '%s' to current scope with value '%s'\n", ident1->value, str1->value); */
}

void sendMail(ExprNode *expr1, RecipientList *recipientList, char* currentSenderEmail) {
    /* printf("sendMail: Entered function.\n"); */

    if (expr1 == NULL) {
        /* printf("sendMail: Warning - expr1 is NULL.\n"); */
        return;
    }

    /* printf("sendMail: expr1 is not NULL. Proceeding.\n"); */
    /* printf("sendMail: Checking expr1->value...\n"); */

    char * message;
    if (expr1->value == NULL) {
        /* printf("sendMail: Warning - expr1->value is NULL.\n"); */
        // If expr1 is a string literal, use it directly
        message = strdup(expr1->stringValue);
    } else {
        int exprId = checkIdentifier(currentScope, expr1);
        if (exprId >= 0 && exprId < exprIndex && expressions[exprId] && expressions[exprId]->stringValue) {
            message = strdup(expressions[exprId]->stringValue);
        } else {
            /* printf("sendMail: Identifier not found or no string value, using identifier name: %s\n", expr1->value); */
            message = strdup(expr1->value);
        }
        /* printf("sendMail: expr1->value = %s\n", expr1->value); */
    }

    if (recipientList == NULL) {
        /* printf("sendMail: Warning - recipientList is NULL.\n"); */
        free(message);
        return;
    }
    /* printf("sendMail: Checking expr1->stringValue...\n"); */

    if (expr1->stringValue == NULL) {
    /* printf("sendMail: Warning - expr1->stringValue is NULL.\n"); */
    } else {
        /* printf("sendMail: expr1->stringValue = %s\n", expr1->stringValue); */
    }

    int exprId = checkIdentifier(currentScope, expr1);
    /* printf("sendMail: exprId returned from checkIdentifier is %d\n", exprId); */

    if (exprId >= 0) {
        /* printf("sendMail: Expression found in list. Index: %d\n", exprId); */
    } else if (exprId == -1) {
        /* printf("sendMail: Expression is a string. Value: %s\n", expr1->stringValue); */
    } else {
        /* printf("sendMail: Expression not found. expr1->value: %s\n", expr1->value); */

        error = 1;

        char lineNumStr[20];
        sprintf(lineNumStr, "Test %d", expr1->lineNum);

        int i;
        bool mailFinder = false;
        for (i = 0; i < currentScope->varCount; i++) {
                if (currentScope->variables[i] != NULL) {
                    /* printf("552 Variable %d: %s with value %s\n", i, currentScope->variables[i]->value, currentScope->variables[i]->stringValue); */
                }
                if (strcmp(currentScope->variables[i]->value, expr1->value) == 0) {
                    mailFinder = true;
                    /* printf("556 The values are equal, and you are looking for: %s, and value is: %s\n", expr1->value, currentScope->variables[i]->stringValue); */
                }                
        }
        
        char *src = "ERROR at line %d: %s is undefined\n";
        int buffer = 20;
        int totalLength = strlen(src) + (expr1->value ? strlen(expr1->value) : 0) + strlen(lineNumStr) + buffer;
        /* printf("sendMail: totalLength calculated as %d\n", totalLength); */
        char *dest = (char *)malloc(totalLength);

        if (dest == NULL) {
            /* fprintf(stderr, "Memory allocation failed\n"); */
            return;
        }

        if (!mailFinder){
            sprintf(dest, src, expr1->lineNum, expr1->value ? expr1->value : "NULL");
        }
        
        printf("%s", dest);

        if (errorIndex < errorSize) {
            /* printf("sendMail: Adding error message to existing errors array.\n"); */
            /* printf("sendMail: errorIndex is: %d \n", errorIndex); */
            /* printf("sendMail: errorSize is: %d \n", errorSize); */
            if (dest == NULL) {
                /* fprintf(stderr, "Memory allocation failed\n"); */
                return;
            } else {
                /* printf("sendMail: dest is not NULL\n"); */
            }
            if (errors == NULL) {
                /* printf("sendMail: errors is NULL. Allocating memory space for errors.\n"); */
                errors = malloc(sizeof(char*) * errorSize);
                if (errors == NULL) {
                    /* fprintf(stderr, "Memory allocation failed for errors\n"); */
                    return;
                }
            }
            /* printf("sendMail: Memory allocation for errors is successful.\n"); */
            errors[errorIndex] = dest;
            errorIndex += 1;
            /* printf("sendMail: dest set inside errors with errorIndex\n"); */
        } else {
            /* printf("sendMail: Reallocating errors array due to insufficient space.\n"); */
            errorSize = errorSize + errorSize;
            char **temp = realloc(errors, sizeof(char *) * errorSize);

            if (temp == NULL) {
                /* printf("sendMail: Memory reallocation for errors array failed.\n"); */
                free(dest);
                return;
            }

            errors = temp;
            /* printf("sendMail: Successfully reallocated errors array. Adding error message.\n"); */
            errors[errorIndex] = dest;
            errorIndex += 1;
        }
    }
    /* printf("sendMail: Current Scope has %d variables.\n", currentScope->varCount); */
    int i;
    for (i = 0; i < currentScope->varCount; i++) {
        if (currentScope->variables[i] != NULL) {
            /* printf("Variable %d: %s with value %s\n", i, currentScope->variables[i]->value, currentScope->variables[i]->stringValue); */
        }
    }
      if (recipientList == NULL) {
        /* printf("sendMail: Warning - recipientList is NULL.\n"); */
    } else {
        char *message = (expr1->stringValue != NULL) ? expr1->stringValue : "(No message)";
        
        // Array to keep track of processed emails
        char *processedEmails[100]; // Adjust size as needed
        int processedCount = 0;
        
        RecipientNode *current = recipientList->head;
        RecipientNode *tempCurrent = recipientList->head;
        while (current != NULL) {
            char *recipientInfo;
            char *recipientEmail = current->email;
            bool alreadyProcessed = false;

            int i;
            for (i = 0; i < processedCount; i++) {
                if (strcmp(recipientEmail, processedEmails[i]) == 0) {
                    alreadyProcessed = true;
                    break;
                }
            }
            
            // Check if the recipient's name is an identifier or a string literal
            if (current->name && current->name[0] == '"') {
                // It's a string literal, remove the quotes
                recipientInfo = strdup(current->name + 1);
                recipientInfo[strlen(recipientInfo) - 1] = '\0'; // Remove the ending quote
                /* printf("sendMail: recipientInfo value: %s\n", recipientInfo); */
            } else if (current->name) {
                // It's an identifier, check if it's defined
                ExprNode tempExpr;
                tempExpr.value = current->name;
                int recipientId = checkIdentifier(currentScope, &tempExpr);
                /* printf("sendMail: current->name is: %s\n", current->name); */
                /* printf("sendMail: recipientId is: %d, exprIndex is: %d\n", recipientId, exprIndex); */
                
                int i;
                bool matchFound = false;
                for (i = 0; i < currentScope->varCount; i++) {
                    if (currentScope->variables[i] != NULL) {
                        /* printf("Variable %d: %s with value %s, current->name: %s\n", i, currentScope->variables[i]->value, currentScope->variables[i]->stringValue, current->name); */
                    }
                    if (strcmp(currentScope->variables[i]->value, current->name) == 0) {
                        matchFound = true;
                        /* printf("The values are equal.\n"); */
                    }                
                }
                
                if (recipientId >= 0 && recipientId < exprIndex) {
                    /* printf("sendMail: recipientId >= 0 && recipientId < exprIndex\n"); */
                    if (expressions[recipientId] && expressions[recipientId]->stringValue) {
                            recipientInfo = strdup(expressions[recipientId]->stringValue);
                            /* printf("sendMail: Value of recipientInfo %s\n", recipientInfo); */
                    }
                } else {
                    // Identifier not found, print error and skip
                
                    if (!matchFound){
                        printf("ERROR at line: %d %s is undefined\n", current->lineNum, current->name);
                    } else {
                        char * namePrint = NULL;
                        int i;
                        for (i = 0; i < currentScope->varCount; i++) {
                            if (currentScope->variables[i] != NULL) {
                                /* printf("Variable %d: %s with value %s, current->name: %s\n", i, currentScope->variables[i]->value, currentScope->variables[i]->stringValue, current->name); */
                            }
                            if (strcmp(currentScope->variables[i]->value, current->name) == 0) {
                                namePrint = strdup(currentScope->variables[i]->stringValue + 1);
                                namePrint[strlen(namePrint) - 1] = '\0'; // Remove the ending quote
                                /* printf("The values are equal, and you are looking for: %s\n", currentScope->variables[i]->stringValue); */
                            }                
                        }
                        
                        globalName = namePrint;
                        globalTo = currentSenderEmail;
                        printf("E-mail sent from %s to %s: %s\n", currentSenderEmail, namePrint, tempCurrent->name);
                    }
                    error = 1;
                    /* printf("Walking current\n"); */
                    current = current->next;
                    continue;
                }
            } else {
                // No name provided, use email
                recipientInfo = strdup(current->email);
            }

            // Print the email sent info
            if (!error && !alreadyProcessed){
                    /* printf("785 E-mail sent from %s to %s: %s\n", currentSenderEmail, recipientInfo, message); */
                    // Add email to processed list
                    processedEmails[processedCount++] = recipientEmail;

                    // Determine recipient info to use (name or email)
                    char *recipientInfo = (current->name && current->name[0] != '\0') ? current->name : recipientEmail;
                    if (current->name && current->name[0] == '"') {
                        // It's a string literal, remove the quotes
                        recipientInfo = strdup(current->name + 1);
                        recipientInfo[strlen(recipientInfo) - 1] = '\0'; // Remove the ending quote
                        /* printf("sendMail: recipientInfo value: %s\n", recipientInfo); */
                        
                        ExprNode tempExpr;
                        tempExpr.value = current->name;
                        int recipientId = checkIdentifier(currentScope, &tempExpr);

                        if (recipientId >= 0) {
                            // Identifier found, use its string value
                            recipientInfo = strdup(expressions[recipientId]->stringValue);
                        } else {
                            // No identifier or it's a string literal
                            recipientInfo = strdup(current->name);
                        }
                    }
                    // Print email message
                    if (message != "(No message)"){
                        if (current->name && current->name[0] == '"') {
                            recipientInfo = strdup(current->name + 1);
                            recipientInfo[strlen(recipientInfo) - 1] = '\0'; // Remove the ending quote
                        }
                        globalTo = currentSenderEmail;
                        if (!error){
                            printf("E-mail sent from %s to %s: %s\n", currentSenderEmail, recipientInfo, message);
                        }
                    }
            } else {
                // No name provided, use email
                recipientInfo = strdup(current->email);
            }
            free(recipientInfo);
            current = current->next;
        }
    }


    /* printf("sendMail: Exiting function.\n"); */
}




int main () 
{
    initGlobalScope();
    if (yyparse())
    {
        printf("ERROR\n");
        return 1;
    } 
    else 
    {
        printScheduledEmails();
        printf("OK\n");
        return 0;
    } 
}

