/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include "scanner.h"

#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include "disco.h"
#include "fdisk.h"
#include <stdio.h>
#include "comexec.h"
#include "mount.h"
#include "mkfs.h"
#include "mkdir.h"
#include "touch.h"
#include "ren.h"
#include "move.h"
#include "find.h"
#include "chmod.h"
#include "cat.h"
#include "arbol.h"
#include <vector>
#include "edit.h"
#include "inodos.h"
#include "remove.h"

using namespace std;


extern int fila;
extern int columna;
extern char *yytext;


// ***************NODO BY DEAFULT
static string tamanioDisc = "", fitDisc = "ff", unitDisc = "m", pathDisc = "";
static string tamanioPart = "", fitPart = "wf", unitPart = "k", pathPart = "", tipoPart = "P", deletePart = "", namePart = "", addPart = "";
static string idReporte = "", tipoRep = "";
static string pathMount = "", iMount = "";

static int idMkfs = 0,  tMkfs = 0, sistMkfs = 0;
static string identificadorMkfs = "", tipoMkfs = "full", sistemaMkfs = "2fs";
static int tmDisc = 0, patDisc = 0, comDisc = 0, namDisc = 0, delDisc = 0, addDisc = 0, unDisc = 0, c1 = 0, c2 = 0, c3 =0, cc=0;
int n=0, pathR = 0, idR = 0;
static int patMkdir = 0,p = 0;
static string pathMkdir = "";
static int sizeT = 0,rT = 0, stdinT = 0, contT = 0,pathT = 0;
static string sizeTouch = "", stdinTouch= "",contTouch = "",pathTouch = "";

static int userL = 0,pwdL = 0, idL = 0;
static string userLogin = "",pwdLogin = "", idLogin = "";
static bool aceptado = false;

static int pathRe = 0,nombreRe = 0;
static string pathRen = "",nombreRen = "";

static int path_f = 0,name_f = 0,termina_f_ast = 0,termina_f_int = 0,termina_f_carp = 0;
static string path_find = "", name_find = "", termina_find_ast = "", termina_find_int = "",termina_find_carp = "";

static int pathCh = 0,ugoCh = 0,rCh = 0;
static string pathChmod = "",ugoChmod = "", rChmod = "";

static int mbrRep = 0,pathRep = 0,idRep = 0,nameRep = 0,sbRep = 0,diskRep = 0,treeRep = 0,rootRep = 0,inodeRep = 0;
static string pathReporte = "",id_Reporte = "", root_Reporte = "/";

static int pathMov = 0, destMov = 0;
static string pathMove = "", destMove = "";

static int pathEd = 0, stdinEd = 0, contEd = 0;
static string pathEdit = "", contEdit = "";

static int pathRem = 0;
static string pathRemove = "";


static int fileC = 0;
static string fileCat = "";

//********************ERRORES
int yyerror(const char* mens){
    cout << "Error Sintactico:" << endl;
    cout <<mens << ": " << yytext << " linea " << fila << " columna " << columna <<endl;
    cout << "\n" << endl;
    return 0;
}


#line 159 "parser.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
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
    Mkdisk = 258,
    Tamanio = 259,
    TNumero = 260,
    Fit = 261,
    Bf = 262,
    Wf = 263,
    Ff = 264,
    Unit = 265,
    Kilo = 266,
    Mega = 267,
    Path = 268,
    Direccion = 269,
    Rmdisk = 270,
    Exec = 271,
    Pause = 272,
    Mount = 273,
    Unmount = 274,
    Id = 275,
    Fdisk = 276,
    Type = 277,
    Delete = 278,
    Name = 279,
    Add = 280,
    P = 281,
    E = 282,
    L = 283,
    Fast = 284,
    Full = 285,
    Units = 286,
    Touch = 287,
    R = 288,
    Cont = 289,
    Stdin = 290,
    Mkfs = 291,
    Fs = 292,
    Fs2 = 293,
    Fs3 = 294,
    Mkdir = 295,
    Find = 296,
    Asterisco = 297,
    Interrogacion = 298,
    Login = 299,
    User = 300,
    Pwd = 301,
    Logout = 302,
    Ren = 303,
    Chmod = 304,
    Ugo = 305,
    Rep = 306,
    Mbr = 307,
    Disk = 308,
    Sb = 309,
    Tree = 310,
    Root = 311,
    Inode = 312,
    TIgual = 313,
    TTexto = 314,
    TID = 315,
    TCara = 316,
    TMenos = 317,
    Cat = 318,
    File = 319,
    Mv = 320,
    Dest = 321,
    Edit = 322,
    Rm = 323
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 93 "parser.y"

    char TEXT [256];

#line 284 "parser.cpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  122
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   241

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  69
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  64
/* YYNRULES -- Number of rules.  */
#define YYNRULES  147
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  258

#define YYUNDEFTOK  2
#define YYMAXUTOK   323


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   174,   174,   178,   179,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   203,   220,   221,   224,   225,
     226,   227,   229,   230,   232,   234,   237,   238,   239,   241,
     257,   299,   300,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   312,   313,   314,   316,   317,   318,   320,   321,
     323,   324,   327,   338,   344,   356,   357,   359,   360,   362,
     369,   386,   387,   389,   390,   391,   393,   394,   397,   409,
     410,   412,   413,   415,   443,   444,   446,   447,   448,   449,
     450,   453,   473,   474,   476,   477,   478,   480,   486,   499,
     500,   502,   503,   505,   518,   519,   521,   522,   524,   525,
     526,   528,   539,   540,   542,   543,   544,   547,   596,   597,
     599,   600,   601,   602,   604,   605,   606,   607,   608,   611,
     616,   617,   619,   632,   647,   648,   650,   651,   653,   674,
     675,   677,   678,   679,   681,   692,   693,   695
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "Mkdisk", "Tamanio", "TNumero", "Fit",
  "Bf", "Wf", "Ff", "Unit", "Kilo", "Mega", "Path", "Direccion", "Rmdisk",
  "Exec", "Pause", "Mount", "Unmount", "Id", "Fdisk", "Type", "Delete",
  "Name", "Add", "P", "E", "L", "Fast", "Full", "Units", "Touch", "R",
  "Cont", "Stdin", "Mkfs", "Fs", "Fs2", "Fs3", "Mkdir", "Find",
  "Asterisco", "Interrogacion", "Login", "User", "Pwd", "Logout", "Ren",
  "Chmod", "Ugo", "Rep", "Mbr", "Disk", "Sb", "Tree", "Root", "Inode",
  "TIgual", "TTexto", "TID", "TCara", "TMenos", "Cat", "File", "Mv",
  "Dest", "Edit", "Rm", "$accept", "S", "CODIGO", "SENTENCIAS", "MKDISK",
  "CUERPO_MKDISK", "COMMAND_MKDISK", "UNIDAD", "DIRECCION", "AJUSTE",
  "RMDISK", "FDISK", "CUERPO_FDISK", "COMMAND_FDISK", "AJUSTEPART",
  "TIPO_PARTICION", "TDELETE", "NOMBRE", "EXEC", "PAUSE", "MOUNT",
  "CUERPO_MOUNT", "COMMAND_MOUNT", "UNMOUNT", "MKFS", "CUERPO_MKFS",
  "COMMAND_MKFS", "TIPO_FORMATEO", "MKDIR", "CUERPO_MKDIR",
  "COMMAND_MKDIR", "TOUCH", "CUERPO_TOUCH", "COMMAND_TOUCH", "LOGIN",
  "CUERPO_LOGIN", "COMMAND_LOGIN", "LOGOUT", "REN", "CUERPO_REN",
  "COMMAND_REN", "FIND", "CUERPO_FIND", "COMMAND_FIND", "TERMINA_FIND",
  "CHMOD", "CUERPO_CHMOD", "COMMAND_CHMOD", "REP", "CUERPO_REP",
  "COMMAND_REP", "TIPO_REP", "CAT", "CUERPO_CAT", "COMMAND_CAT", "MV",
  "CUERPO_MV", "COMMAND_MV", "EDIT", "CUERPO_EDIT", "COMMAND_EDIT", "RM",
  "CUERPO_RM", "COMMAND_RM", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323
};
# endif

#define YYPACT_NINF (-130)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      38,    62,    -7,     9,  -130,     1,    17,    98,    58,    -9,
      -1,    11,   -16,  -130,    21,    -6,    -5,   -24,    -8,    -3,
      30,    48,    38,  -130,  -130,  -130,  -130,  -130,  -130,  -130,
    -130,  -130,  -130,  -130,  -130,  -130,  -130,  -130,  -130,  -130,
    -130,  -130,  -130,  -130,    15,    22,    23,    32,    62,  -130,
      40,    49,    60,    66,     1,  -130,    70,    72,    73,    74,
      75,    76,    77,    78,    79,    98,  -130,    80,    81,  -130,
      82,  -130,    58,  -130,    83,    84,    85,    -9,  -130,    86,
      41,    -1,  -130,    87,    88,    11,  -130,    89,    90,    91,
     -16,  -130,    92,    93,    21,  -130,    94,  -130,    95,    -6,
    -130,    96,    97,   100,   101,    -5,  -130,    64,   -24,  -130,
     102,   103,    -8,  -130,   104,   106,  -130,    -3,  -130,   107,
      30,  -130,  -130,  -130,   124,   105,    53,     4,  -130,     4,
       4,     4,    28,  -130,   109,   151,   108,    53,     4,    99,
      47,    24,    -2,  -130,   152,     4,     4,  -130,   110,    47,
      71,  -130,     4,  -130,  -130,     4,   -22,  -130,   111,   112,
     158,  -130,     4,    24,  -130,     4,   161,  -130,     4,   113,
      42,     4,  -130,   116,  -130,     4,     4,  -130,     4,     4,
    -130,     4,  -130,  -130,  -130,  -130,  -130,  -130,  -130,  -130,
    -130,  -130,  -130,  -130,  -130,  -130,  -130,  -130,  -130,  -130,
    -130,  -130,  -130,  -130,  -130,  -130,  -130,  -130,  -130,  -130,
    -130,  -130,  -130,  -130,  -130,  -130,  -130,   162,  -130,  -130,
    -130,  -130,  -130,  -130,  -130,  -130,  -130,  -130,   115,   117,
    -130,  -130,  -130,  -130,  -130,  -130,  -130,  -130,  -130,  -130,
    -130,  -130,  -130,  -130,  -130,  -130,  -130,  -130,     4,  -130,
    -130,  -130,  -130,  -130,  -130,  -130,  -130,  -130
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,    63,     0,     0,     0,     0,     0,
       0,     0,     0,    97,     0,     0,     0,     0,     0,     0,
       0,     0,     2,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    21,    16,    17,    18,    19,
      20,    22,    23,    24,     0,     0,     0,     0,    25,    27,
       0,     0,     0,     0,    64,    66,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    40,    42,     0,     0,    90,
       0,    89,    83,    85,     0,     0,     0,    70,    72,     0,
       0,    78,    80,     0,     0,   103,   105,     0,     0,     0,
      91,    93,     0,     0,    98,   100,     0,   116,     0,   111,
     113,     0,     0,     0,     0,   117,   119,     0,   129,   131,
       0,     0,   133,   135,     0,     0,   143,   138,   140,     0,
     144,   146,     1,     3,     0,     0,     0,     0,    26,     0,
       0,     0,     0,    65,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    41,     0,     0,     0,    84,     0,     0,
       0,    71,     0,    81,    79,     0,     0,   104,     0,     0,
       0,    92,     0,     0,    99,     0,     0,   112,     0,     0,
       0,     0,   118,     0,   130,     0,     0,   134,     0,     0,
     139,     0,   145,    28,    36,    37,    38,    31,    32,    33,
      29,    35,    34,    30,    39,    62,    67,    68,    69,    43,
      52,    53,    54,    46,    44,    45,    55,    56,    57,    47,
      59,    58,    48,    60,    61,    49,    50,     0,    86,    87,
      88,    74,    73,    76,    77,    75,    82,   106,     0,     0,
     110,   107,    96,    94,    95,   101,   102,   114,   115,   121,
     120,   124,   126,   125,   127,   128,   122,   123,     0,   136,
     137,   141,   142,   147,    51,   108,   109,   132
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -130,  -130,  -130,   146,  -130,  -130,    52,    39,  -129,  -130,
    -130,  -130,  -130,   114,  -130,  -130,    29,    18,  -130,  -130,
    -130,  -130,   126,  -130,  -130,  -130,   118,  -130,  -130,  -130,
     119,  -130,  -130,   120,  -130,  -130,   121,  -130,  -130,  -130,
     122,  -130,  -130,   123,  -130,  -130,  -130,   125,  -130,  -130,
     127,  -130,  -130,  -130,   128,  -130,  -130,   129,  -130,  -130,
      65,  -130,  -130,    63
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    21,    22,    23,    24,    48,    49,   190,   193,   187,
      25,    26,    65,    66,   203,   209,   212,   215,    27,    28,
      29,    54,    55,    30,    31,    77,    78,   225,    32,    81,
      82,    33,    72,    73,    34,    90,    91,    35,    36,    94,
      95,    37,    85,    86,   231,    38,    99,   100,    39,   105,
     106,   246,    40,   108,   109,    41,   112,   113,    42,   117,
     118,    43,   120,   121
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     194,   195,   196,   216,    87,   110,    50,    96,   101,   205,
     114,    74,    79,    75,    52,   102,   219,   220,   191,   103,
     228,   229,    51,   226,    83,    53,   227,    97,    76,    88,
      89,   115,   116,   235,    92,    84,   237,    56,   230,   239,
     107,     1,   247,   119,    98,    93,   249,   250,   122,   251,
     252,   104,   253,     2,     3,     4,     5,     6,   111,     7,
     217,    80,    67,   192,   188,   189,    44,   153,    45,   173,
       8,    68,    46,   124,     9,    47,   210,   211,    10,    11,
     125,   126,    12,   213,   214,    13,    14,    15,   197,    16,
     127,    69,    70,    71,   241,   242,   243,   244,   129,   245,
     128,    17,    57,    18,    58,    19,    20,   130,    59,   223,
     224,    60,   184,   185,   186,   200,   201,   202,   131,   257,
      61,    62,    63,    64,   132,   206,   207,   208,   134,   183,
     135,   136,   137,   138,   139,   140,   141,   142,   144,   145,
     146,   148,   149,   150,   152,   155,   156,   158,   159,   160,
     162,   163,   165,   166,   168,   169,   199,   218,   170,   171,
     175,   176,   178,   234,   179,   181,   238,   254,   123,   198,
     221,   232,   233,   240,   248,   255,   204,   256,   222,   143,
     133,   236,   180,   182,     0,     0,     0,     0,     0,     0,
       0,     0,   147,     0,     0,   151,     0,     0,     0,     0,
     154,     0,     0,     0,     0,     0,     0,     0,   157,     0,
       0,   161,     0,     0,     0,     0,   164,     0,     0,     0,
       0,     0,     0,     0,   167,     0,     0,     0,     0,     0,
       0,     0,   172,     0,     0,     0,   174,     0,     0,     0,
       0,   177
};

static const yytype_int16 yycheck[] =
{
     129,   130,   131,     5,    20,    13,    13,    13,    13,   138,
      13,    20,    13,    22,    13,    20,   145,   146,    14,    24,
      42,    43,    13,   152,    13,    24,   155,    33,    37,    45,
      46,    34,    35,   162,    13,    24,   165,    20,    60,   168,
      64,     3,   171,    13,    50,    24,   175,   176,     0,   178,
     179,    56,   181,    15,    16,    17,    18,    19,    66,    21,
      62,    62,     4,    59,    11,    12,     4,    26,     6,     5,
      32,    13,    10,    58,    36,    13,    29,    30,    40,    41,
      58,    58,    44,    59,    60,    47,    48,    49,    60,    51,
      58,    33,    34,    35,    52,    53,    54,    55,    58,    57,
      48,    63,     4,    65,     6,    67,    68,    58,    10,    38,
      39,    13,     7,     8,     9,     7,     8,     9,    58,   248,
      22,    23,    24,    25,    58,    26,    27,    28,    58,     5,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,     5,     5,    58,    58,
      58,    58,    58,     5,    58,    58,     5,     5,    22,    60,
      60,    60,    60,    60,    58,    60,   137,    60,   149,    65,
      54,   163,   117,   120,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    72,    -1,    -1,    77,    -1,    -1,    -1,    -1,
      81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    -1,
      -1,    90,    -1,    -1,    -1,    -1,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   105,    -1,    -1,    -1,   108,    -1,    -1,    -1,
      -1,   112
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    15,    16,    17,    18,    19,    21,    32,    36,
      40,    41,    44,    47,    48,    49,    51,    63,    65,    67,
      68,    70,    71,    72,    73,    79,    80,    87,    88,    89,
      92,    93,    97,   100,   103,   106,   107,   110,   114,   117,
     121,   124,   127,   130,     4,     6,    10,    13,    74,    75,
      13,    13,    13,    24,    90,    91,    20,     4,     6,    10,
      13,    22,    23,    24,    25,    81,    82,     4,    13,    33,
      34,    35,   101,   102,    20,    22,    37,    94,    95,    13,
      62,    98,    99,    13,    24,   111,   112,    20,    45,    46,
     104,   105,    13,    24,   108,   109,    13,    33,    50,   115,
     116,    13,    20,    24,    56,   118,   119,    64,   122,   123,
      13,    66,   125,   126,    13,    34,    35,   128,   129,    13,
     131,   132,     0,    72,    58,    58,    58,    58,    75,    58,
      58,    58,    58,    91,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    82,    58,    58,    58,   102,    58,    58,
      58,    95,    58,    26,    99,    58,    58,   112,    58,    58,
      58,   105,    58,    58,   109,    58,    58,   116,    58,    58,
      58,    58,   119,     5,   123,    58,    58,   126,    58,    58,
     129,    58,   132,     5,     7,     8,     9,    78,    11,    12,
      76,    14,    59,    77,    77,    77,    77,    60,    60,     5,
       7,     8,     9,    83,    76,    77,    26,    27,    28,    84,
      29,    30,    85,    59,    60,    86,     5,    62,     5,    77,
      77,    60,    85,    38,    39,    96,    77,    77,    42,    43,
      60,   113,    60,    60,     5,    77,    86,    77,     5,    77,
      60,    52,    53,    54,    55,    57,   120,    77,    58,    77,
      77,    77,    77,    77,     5,    60,    60,    77
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    69,    70,    71,    71,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    73,    74,    74,    75,    75,
      75,    75,    76,    76,    77,    77,    78,    78,    78,    79,
      80,    81,    81,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    83,    83,    83,    84,    84,    84,    85,    85,
      86,    86,    87,    88,    89,    90,    90,    91,    91,    92,
      93,    94,    94,    95,    95,    95,    96,    96,    97,    98,
      98,    99,    99,   100,   101,   101,   102,   102,   102,   102,
     102,   103,   104,   104,   105,   105,   105,   106,   107,   108,
     108,   109,   109,   110,   111,   111,   112,   112,   113,   113,
     113,   114,   115,   115,   116,   116,   116,   117,   118,   118,
     119,   119,   119,   119,   120,   120,   120,   120,   120,   121,
     122,   122,   123,   124,   125,   125,   126,   126,   127,   128,
     128,   129,   129,   129,   130,   131,   131,   132
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     1,     3,     3,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     4,
       2,     2,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     4,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     1,     2,     2,     1,     3,     3,     4,
       2,     2,     1,     3,     3,     3,     1,     1,     2,     2,
       1,     2,     3,     2,     2,     1,     3,     3,     3,     1,
       1,     2,     2,     1,     3,     3,     3,     1,     2,     2,
       1,     3,     3,     2,     2,     1,     3,     3,     2,     2,
       1,     2,     2,     1,     3,     3,     1,     2,     2,     1,
       3,     3,     3,     3,     1,     1,     1,     1,     1,     2,
       2,     1,     4,     2,     2,     1,     3,     3,     2,     2,
       1,     3,     3,     1,     2,     2,     1,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
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
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 174 "parser.y"
                                  {
                          cout << "Comando Ejecutado\n" << endl;
                        }
#line 1769 "parser.cpp"
    break;

  case 3:
#line 178 "parser.y"
                                            {}
#line 1775 "parser.cpp"
    break;

  case 4:
#line 179 "parser.y"
                                            {}
#line 1781 "parser.cpp"
    break;

  case 5:
#line 181 "parser.y"
                                        {}
#line 1787 "parser.cpp"
    break;

  case 6:
#line 182 "parser.y"
                                        {}
#line 1793 "parser.cpp"
    break;

  case 7:
#line 183 "parser.y"
                                        {}
#line 1799 "parser.cpp"
    break;

  case 8:
#line 184 "parser.y"
                                        {}
#line 1805 "parser.cpp"
    break;

  case 9:
#line 185 "parser.y"
                                        {}
#line 1811 "parser.cpp"
    break;

  case 10:
#line 186 "parser.y"
                                        {}
#line 1817 "parser.cpp"
    break;

  case 11:
#line 187 "parser.y"
                                        {}
#line 1823 "parser.cpp"
    break;

  case 12:
#line 188 "parser.y"
                                        {}
#line 1829 "parser.cpp"
    break;

  case 13:
#line 189 "parser.y"
                                        {}
#line 1835 "parser.cpp"
    break;

  case 14:
#line 190 "parser.y"
                                        {}
#line 1841 "parser.cpp"
    break;

  case 15:
#line 191 "parser.y"
                                        {}
#line 1847 "parser.cpp"
    break;

  case 16:
#line 192 "parser.y"
                                        {}
#line 1853 "parser.cpp"
    break;

  case 17:
#line 193 "parser.y"
                                        {}
#line 1859 "parser.cpp"
    break;

  case 18:
#line 194 "parser.y"
                                        {}
#line 1865 "parser.cpp"
    break;

  case 19:
#line 195 "parser.y"
                                        {}
#line 1871 "parser.cpp"
    break;

  case 20:
#line 196 "parser.y"
                                        {}
#line 1877 "parser.cpp"
    break;

  case 21:
#line 197 "parser.y"
                                        {}
#line 1883 "parser.cpp"
    break;

  case 22:
#line 198 "parser.y"
                                        {}
#line 1889 "parser.cpp"
    break;

  case 23:
#line 199 "parser.y"
                                        {}
#line 1895 "parser.cpp"
    break;

  case 24:
#line 200 "parser.y"
                                        {}
#line 1901 "parser.cpp"
    break;

  case 25:
#line 203 "parser.y"
                                                  {
    if( (tmDisc == patDisc) == 1){
        if(comDisc == 1){
            //Quitar Comillas
            pathDisc = disco::quitarComillas(pathDisc);
            disco::crearDisco(tamanioDisc, unitDisc, fitDisc, pathDisc);
        }
        else
            disco::crearDisco(tamanioDisc, unitDisc, fitDisc, pathDisc);
    }
    else{
        cout << "Falta un parametro obligatorio para la creacion del disco" << endl;
    }
    tamanioDisc = ""; fitDisc = "ff"; unitDisc = "m"; pathDisc = "";
    tmDisc = 0; patDisc = 0; comDisc = 0;
                      	}
#line 1922 "parser.cpp"
    break;

  case 26:
#line 220 "parser.y"
                                                       {}
#line 1928 "parser.cpp"
    break;

  case 27:
#line 221 "parser.y"
                                         {}
#line 1934 "parser.cpp"
    break;

  case 28:
#line 224 "parser.y"
                                                  {tamanioDisc = (yyvsp[0].TEXT); tmDisc = 1;}
#line 1940 "parser.cpp"
    break;

  case 29:
#line 225 "parser.y"
                                                  {}
#line 1946 "parser.cpp"
    break;

  case 30:
#line 226 "parser.y"
                                                  {patDisc = 1;}
#line 1952 "parser.cpp"
    break;

  case 31:
#line 227 "parser.y"
                                                  {}
#line 1958 "parser.cpp"
    break;

  case 32:
#line 229 "parser.y"
                                  {unitDisc = "k"; unitPart = "k"; }
#line 1964 "parser.cpp"
    break;

  case 33:
#line 230 "parser.y"
                                  { unitDisc = "m"; unitPart = "m"; }
#line 1970 "parser.cpp"
    break;

  case 34:
#line 232 "parser.y"
                                    { pathMount = (yyvsp[0].TEXT);  pathPart = (yyvsp[0].TEXT); pathDisc = (yyvsp[0].TEXT); patDisc = 1; comDisc = 1;
				     pathMkdir = (yyvsp[0].TEXT);pathT = 1; path_find = (yyvsp[0].TEXT);}
#line 1977 "parser.cpp"
    break;

  case 35:
#line 234 "parser.y"
                                    { pathMount = (yyvsp[0].TEXT);  pathPart = (yyvsp[0].TEXT); pathDisc = (yyvsp[0].TEXT); patDisc = 1; pathMkdir =
                		(yyvsp[0].TEXT); pathT = 1; path_find = (yyvsp[0].TEXT); }
#line 1984 "parser.cpp"
    break;

  case 36:
#line 237 "parser.y"
                                { fitDisc ="bf"; }
#line 1990 "parser.cpp"
    break;

  case 37:
#line 238 "parser.y"
                                { fitDisc ="wf"; }
#line 1996 "parser.cpp"
    break;

  case 38:
#line 239 "parser.y"
                                { fitDisc ="ff"; }
#line 2002 "parser.cpp"
    break;

  case 39:
#line 241 "parser.y"
                                                      {
	if(patDisc == 1){
		if(comDisc == 1){
			pathDisc = disco::quitarComillas(pathDisc);
			disco::eliminarDisco(pathDisc);
		}else{
			disco::eliminarDisco(pathDisc);
		}
	}else{
		cout<<"Falta un parametro obligatorio";
	}
	pathDisc = "";
	patDisc = 0; comDisc = 0;
}
#line 2021 "parser.cpp"
    break;

  case 40:
#line 257 "parser.y"
                                            {

      if(unDisc == 0){
	unitPart = "k";
      }
      cout<<"tipo de particionfit :"<<fitPart<<endl;
      //cout << "---" << unitPart << endl;
      if( c1 == 1 && patDisc == 1 && tmDisc == 1 && namDisc == 1 )
      {
	  //Crear una particion
	  if(comDisc == 1){
	      pathPart = disco::quitarComillas(pathPart);
	      fdisk::crearParticion(tamanioPart, unitPart, pathPart, fitPart, tipoPart, namePart);
	  }
	  else
	      fdisk::crearParticion(tamanioPart, unitPart, pathPart, fitPart, tipoPart, namePart);

      }
      if( c2 == 1 && patDisc == 1 && delDisc == 1 && namDisc == 1 )
      {
	  //Eliminar una particion
	  if(comDisc == 1){
	      pathDisc = disco::quitarComillas(pathDisc);
	      fdisk::eliminarP(namePart, pathDisc, deletePart);
	  }
	  else
	  	fdisk::eliminarP(namePart, pathPart, deletePart);
      }
      if( c3 == 1 && patDisc == 1 && addDisc == 1 && unDisc == 1 && namDisc == 1 ){
	  //Agregar espacio
	  if(comDisc == 1){
	      pathDisc = disco::quitarComillas(pathDisc);
	      cout << "No IMPLEMENTE LA FUNCION ADD" << endl;
	  }
	  cout << "No IMPLEMENTE LA FUNCION ADD" << endl;
      }

      tamanioPart = ""; fitPart = "wf"; unitPart = "k"; pathPart = ""; tipoPart = "P"; deletePart = ""; namePart = ""; addPart = "";
      tmDisc = 0; patDisc = 0; comDisc = 0; c1 = 0; c2 = 0; c3 = 0; cc = 0; namDisc = 0; unDisc =0; delDisc =0; addDisc = 0 ;

                                                                                  }
#line 2067 "parser.cpp"
    break;

  case 41:
#line 299 "parser.y"
                                                        {}
#line 2073 "parser.cpp"
    break;

  case 42:
#line 300 "parser.y"
                                                        {}
#line 2079 "parser.cpp"
    break;

  case 43:
#line 302 "parser.y"
                                                        { tamanioPart = (yyvsp[0].TEXT); tmDisc = 1; cc++; c1 = cc; }
#line 2085 "parser.cpp"
    break;

  case 44:
#line 303 "parser.y"
                                                        { unDisc = 1; }
#line 2091 "parser.cpp"
    break;

  case 45:
#line 304 "parser.y"
                                                        { patDisc = 1; }
#line 2097 "parser.cpp"
    break;

  case 46:
#line 305 "parser.y"
                                                        {}
#line 2103 "parser.cpp"
    break;

  case 47:
#line 306 "parser.y"
                                                        {}
#line 2109 "parser.cpp"
    break;

  case 48:
#line 307 "parser.y"
                                                        { delDisc = 1; cc++; c2 = cc; }
#line 2115 "parser.cpp"
    break;

  case 49:
#line 308 "parser.y"
                                                        { namDisc = 1; }
#line 2121 "parser.cpp"
    break;

  case 50:
#line 309 "parser.y"
                                                        { addPart = (yyvsp[0].TEXT); addDisc = 1; cc++; c3 = cc; }
#line 2127 "parser.cpp"
    break;

  case 51:
#line 310 "parser.y"
                                                        { addPart = (yyvsp[-1].TEXT); addDisc = 1; cc++; c3 = cc; }
#line 2133 "parser.cpp"
    break;

  case 52:
#line 312 "parser.y"
                                {fitPart = "bf"; }
#line 2139 "parser.cpp"
    break;

  case 53:
#line 313 "parser.y"
                                { fitPart = "wf"; }
#line 2145 "parser.cpp"
    break;

  case 54:
#line 314 "parser.y"
                                {fitPart = "ff"; }
#line 2151 "parser.cpp"
    break;

  case 55:
#line 316 "parser.y"
                              { tipoPart = "P"; }
#line 2157 "parser.cpp"
    break;

  case 56:
#line 317 "parser.y"
                              { tipoPart = "E"; }
#line 2163 "parser.cpp"
    break;

  case 57:
#line 318 "parser.y"
                              { tipoPart = "L"; }
#line 2169 "parser.cpp"
    break;

  case 58:
#line 320 "parser.y"
                                { deletePart = "full"; }
#line 2175 "parser.cpp"
    break;

  case 59:
#line 321 "parser.y"
                                { deletePart = "fast"; }
#line 2181 "parser.cpp"
    break;

  case 60:
#line 323 "parser.y"
                                 { namePart = disco::quitarComillas((yyvsp[0].TEXT)); nombreRen = disco::quitarComillas((yyvsp[0].TEXT));}
#line 2187 "parser.cpp"
    break;

  case 61:
#line 324 "parser.y"
                                 { namePart = (yyvsp[0].TEXT); nombreRen = (yyvsp[0].TEXT);}
#line 2193 "parser.cpp"
    break;

  case 62:
#line 327 "parser.y"
                                                     {
			if (patDisc == 1){
				if(comDisc == 1){
				      	pathPart = disco::quitarComillas(pathPart);
					comexec::leer(pathPart);
				}
				else
					comexec::leer(pathPart);
			}
}
#line 2208 "parser.cpp"
    break;

  case 63:
#line 338 "parser.y"
                                {
	printf("Presione ENTER para continuar: \n");
	int c = getchar();
}
#line 2217 "parser.cpp"
    break;

  case 64:
#line 344 "parser.y"
                                                        {
		if(pathR == 1 && idR == 1){
			if(comDisc == 1){
				pathMount = disco::quitarComillas(pathMount);
				mount::montar(pathMount, iMount);
			}else{
				mount::montar(pathMount, iMount);
			}
		}
		pathR = 0; comDisc = 0; iMount = ""; pathMount = "";
}
#line 2233 "parser.cpp"
    break;

  case 65:
#line 356 "parser.y"
                                                        {}
#line 2239 "parser.cpp"
    break;

  case 66:
#line 357 "parser.y"
                                                        {}
#line 2245 "parser.cpp"
    break;

  case 67:
#line 359 "parser.y"
                                                        {pathR = 1;}
#line 2251 "parser.cpp"
    break;

  case 68:
#line 360 "parser.y"
                                                        {idR = 1; iMount = (yyvsp[0].TEXT);}
#line 2257 "parser.cpp"
    break;

  case 69:
#line 362 "parser.y"
                                                 {
		    iMount = (yyvsp[0].TEXT);
		    mount::desmontarParticiones(iMount);
		    iMount = "";
                                          	}
#line 2267 "parser.cpp"
    break;

  case 70:
#line 369 "parser.y"
                                          {
	if(idMkfs == 1){
		if (sistMkfs == 1){
			if(sistemaMkfs == "2fs"){
				mkfs::Formato_ext2(identificadorMkfs, tipoMkfs);
			}else{
				cout <<"3fs"<<endl;
				mkfs::Formato_ext3(identificadorMkfs, tipoMkfs);
			}
		}else{
			mkfs::Formato_ext2(identificadorMkfs, tipoMkfs);
		}
	}else{
		cout << "Falta un ID de una particion montada" ;
	}
}
#line 2288 "parser.cpp"
    break;

  case 71:
#line 386 "parser.y"
                                                        {}
#line 2294 "parser.cpp"
    break;

  case 72:
#line 387 "parser.y"
                                                        {}
#line 2300 "parser.cpp"
    break;

  case 73:
#line 389 "parser.y"
                                                        { tMkfs = 1; tipoMkfs = deletePart; }
#line 2306 "parser.cpp"
    break;

  case 74:
#line 390 "parser.y"
                                                        { idMkfs = 1; identificadorMkfs = (yyvsp[0].TEXT); }
#line 2312 "parser.cpp"
    break;

  case 75:
#line 391 "parser.y"
                                                        { sistMkfs = 1; }
#line 2318 "parser.cpp"
    break;

  case 76:
#line 393 "parser.y"
                                                        { sistemaMkfs = "2fs";}
#line 2324 "parser.cpp"
    break;

  case 77:
#line 394 "parser.y"
                                                        { sistemaMkfs = "3fs";}
#line 2330 "parser.cpp"
    break;

  case 78:
#line 397 "parser.y"
                                                        {
	if(patMkdir == 1){
		if (p == 1){
			mkdir::crearCarpeta(pathMkdir,"","Particion1",idLogin,aceptado);
		}else{
			mkdir::crearCarpeta(pathMkdir,"","Particion1",idLogin,aceptado);
		}
	}else{
		cout <<"Falta parametro path en el comando MKDIR ";
	}
}
#line 2346 "parser.cpp"
    break;

  case 79:
#line 409 "parser.y"
                                                        {}
#line 2352 "parser.cpp"
    break;

  case 80:
#line 410 "parser.y"
                                                        {}
#line 2358 "parser.cpp"
    break;

  case 81:
#line 412 "parser.y"
                                                        { p = 1; }
#line 2364 "parser.cpp"
    break;

  case 82:
#line 413 "parser.y"
                                                        { patMkdir = 1; }
#line 2370 "parser.cpp"
    break;

  case 83:
#line 415 "parser.y"
                                                        {
			if(pathT == 1){
				if(contT == 1 && stdinT == 1){
					cout<<"Error en los parametros"<<endl;
                               	}else{
                               		if(rT == 1){
                               			if(comDisc == 1){
								pathTouch = disco::quitarComillas(pathTouch);
								touch::crearArchivo(pathTouch,"r",idLogin,contTouch,stdinT,sizeTouch,aceptado);
                                                	}else{
								touch::crearArchivo(pathTouch,"r",idLogin,contTouch,stdinT,sizeTouch,aceptado);
                                                }

                               		}else{
                               			if(comDisc == 1){
							pathTouch = disco::quitarComillas(pathTouch);
							touch::crearArchivo(pathTouch,"r","581a",contTouch,stdinT,sizeTouch,aceptado);
						}else{
							touch::crearArchivo(pathTouch,"r","581a",contTouch,stdinT,sizeTouch,aceptado);
						}
                               		}

                               	}
			}
			pathTouch = ""; contTouch = ""; stdinTouch = "";sizeTouch = ""; pathT = 0; contT = 0; stdinT = 0; rT = 0;

}
#line 2402 "parser.cpp"
    break;

  case 84:
#line 443 "parser.y"
                                                        {}
#line 2408 "parser.cpp"
    break;

  case 85:
#line 444 "parser.y"
                                                        {}
#line 2414 "parser.cpp"
    break;

  case 86:
#line 446 "parser.y"
                                                        { sizeT = 1; sizeTouch = (yyvsp[0].TEXT); }
#line 2420 "parser.cpp"
    break;

  case 87:
#line 447 "parser.y"
                                                        { pathTouch = pathMkdir; }
#line 2426 "parser.cpp"
    break;

  case 88:
#line 448 "parser.y"
                                                        { contT = 1; contTouch = pathMkdir; }
#line 2432 "parser.cpp"
    break;

  case 89:
#line 449 "parser.y"
                                                        {stdinT = 1;}
#line 2438 "parser.cpp"
    break;

  case 90:
#line 450 "parser.y"
                                                        {rT = 1;}
#line 2444 "parser.cpp"
    break;

  case 91:
#line 453 "parser.y"
                                                        {
	listMounted particion;
        particion = mount::recorrerLista(idLogin);
        if(particion.id != 0){
		cout<<"Particion no montada"<<endl;
    	}else{
		if(idL == 1 && userL == 1 && pwdL == 1){
			if(userLogin == "root" && pwdLogin == "123"){
				cout<<"Ingreso exitoso";
				aceptado = true;
			}else{
				cout<<"Usuario o contraseña incorrectos"<<endl;
			}
		}else{
			cout << "falta un parametro";
		}
    	}

}
#line 2468 "parser.cpp"
    break;

  case 92:
#line 473 "parser.y"
                                                        {}
#line 2474 "parser.cpp"
    break;

  case 93:
#line 474 "parser.y"
                                                        {}
#line 2480 "parser.cpp"
    break;

  case 94:
#line 476 "parser.y"
                                                        { userL = 1; userLogin = (yyvsp[0].TEXT); }
#line 2486 "parser.cpp"
    break;

  case 95:
#line 477 "parser.y"
                                                        { pwdL = 1; pwdLogin = (yyvsp[0].TEXT); }
#line 2492 "parser.cpp"
    break;

  case 96:
#line 478 "parser.y"
                                                        { idL = 1; idLogin = (yyvsp[0].TEXT); }
#line 2498 "parser.cpp"
    break;

  case 97:
#line 480 "parser.y"
                                                        {
		cout<<"--------------Cerro Sesion-------------"<<endl;
		userL = 0; userLogin = ""; pwdL = 0; pwdLogin = ""; idL = 0; idLogin = "",aceptado = false;
}
#line 2507 "parser.cpp"
    break;

  case 98:
#line 486 "parser.y"
                                                        {
	if(pathRe == 1 && nombreRe == 1){
		if(comDisc == 1){
			pathRen = disco::quitarComillas(pathTouch);
			ren::cambiarNombre(pathRen,nombreRen,idLogin,aceptado);
		}else{
			ren::cambiarNombre(pathRen,nombreRen,idLogin,aceptado);
		}
	}else{
		cout <<"Faltan parametros"<<endl;
	}
}
#line 2524 "parser.cpp"
    break;

  case 99:
#line 499 "parser.y"
                                                        {}
#line 2530 "parser.cpp"
    break;

  case 100:
#line 500 "parser.y"
                                                        {}
#line 2536 "parser.cpp"
    break;

  case 101:
#line 502 "parser.y"
                                                        { pathRe = 1; pathRen = pathMkdir; }
#line 2542 "parser.cpp"
    break;

  case 102:
#line 503 "parser.y"
                                                        { nombreRe = 1; }
#line 2548 "parser.cpp"
    break;

  case 103:
#line 505 "parser.y"
                                                        {
	if(path_f ==1 && name_f == 1){
		if(comDisc == 1){
			path_find = disco::quitarComillas(path_find);
			find::buscar(termina_f_int,termina_f_ast,path_find,name_find,"581a");
		}else{
			find::buscar(termina_f_int,termina_f_ast,path_find,name_find,"581a");
		}
	}else{
		cout << "Falta un parametro"<<endl;
	}
}
#line 2565 "parser.cpp"
    break;

  case 104:
#line 518 "parser.y"
                                                        {}
#line 2571 "parser.cpp"
    break;

  case 105:
#line 519 "parser.y"
                                                        {}
#line 2577 "parser.cpp"
    break;

  case 106:
#line 521 "parser.y"
                                                        { path_f = 1; }
#line 2583 "parser.cpp"
    break;

  case 107:
#line 522 "parser.y"
                                                        { name_f = 1; }
#line 2589 "parser.cpp"
    break;

  case 108:
#line 524 "parser.y"
                                                { termina_f_ast = 1; termina_find_ast = "*"; name_find = (yyvsp[0].TEXT); }
#line 2595 "parser.cpp"
    break;

  case 109:
#line 525 "parser.y"
                                                { termina_f_int = 1; termina_find_int = "?"; name_find = (yyvsp[0].TEXT); }
#line 2601 "parser.cpp"
    break;

  case 110:
#line 526 "parser.y"
                                                { termina_f_carp = 1; name_find = (yyvsp[0].TEXT); }
#line 2607 "parser.cpp"
    break;

  case 111:
#line 528 "parser.y"
                                                        {
	if(pathCh == 1 && ugoCh == 1){
		if(comDisc == 1){
			pathChmod = disco::quitarComillas(pathChmod);
			chmod::cambiarP(pathChmod,rChmod,ugoChmod,idLogin,aceptado);
		}else{
			chmod::cambiarP(pathChmod,rChmod,ugoChmod,idLogin,aceptado);
		}
	}
}
#line 2622 "parser.cpp"
    break;

  case 112:
#line 539 "parser.y"
                                                        {}
#line 2628 "parser.cpp"
    break;

  case 113:
#line 540 "parser.y"
                                                        {}
#line 2634 "parser.cpp"
    break;

  case 114:
#line 542 "parser.y"
                                                        { pathCh = 1; pathChmod = (yyvsp[0].TEXT); }
#line 2640 "parser.cpp"
    break;

  case 115:
#line 543 "parser.y"
                                                        { ugoCh = 1; ugoChmod = (yyvsp[0].TEXT); }
#line 2646 "parser.cpp"
    break;

  case 116:
#line 544 "parser.y"
                                                        { rCh = 1; rChmod = "r"; }
#line 2652 "parser.cpp"
    break;

  case 117:
#line 547 "parser.y"
                                                        {
	if(idRep == 1 && pathRep == 1 && nameRep == 1){
		if(mbrRep == 1){
			if(comDisc == 1){
				pathReporte = disco::quitarComillas(pathReporte);
				disco::repoteMBR(id_Reporte,pathReporte);
			}else{
				disco::repoteMBR(id_Reporte,pathReporte);
			}

		}else if (sbRep == 1){
			if(comDisc == 1){
				pathReporte = disco::quitarComillas(pathReporte);
				mkdir::ReporteSuperBloque(id_Reporte, pathReporte);
			}else{
				mkdir::ReporteSuperBloque(id_Reporte, pathReporte);
			}
		}else if(diskRep == 1){
			if(comDisc == 1){
				pathReporte = disco::quitarComillas(pathReporte);
				disco::reporteDisco(id_Reporte, pathReporte);
			}else{
				disco::reporteDisco(id_Reporte, pathReporte);
			}
		}else if(treeRep == 1){
			if(comDisc == 1){
				pathReporte = disco::quitarComillas(pathReporte);
				root_Reporte = disco::quitarComillas(root_Reporte);
				arbol::Reporte(id_Reporte,root_Reporte,pathReporte);
			}else{
				arbol::Reporte(id_Reporte,root_Reporte,pathReporte);
			}
		}else if (inodeRep == 1){
			if(comDisc == 1){
				pathReporte = disco::quitarComillas(pathReporte);
				inodos::Reporte(pathReporte,id_Reporte);
			}else{
				inodos::Reporte(pathReporte,id_Reporte);
			}
		}else{
			cout<<"error en parametro name";
		}
	}else{
		cout<<"Falta un parametro"<<endl;
	}
	idRep = 0; pathRep = 0; nameRep = 0,root_Reporte = "/";
	mbrRep = 0; comDisc = 0; pathReporte = ""; id_Reporte = ""; sbRep = 0; diskRep = 0,treeRep = 0; rootRep = 0; inodeRep = 0;
}
#line 2705 "parser.cpp"
    break;

  case 118:
#line 596 "parser.y"
                                                        {}
#line 2711 "parser.cpp"
    break;

  case 119:
#line 597 "parser.y"
                                                        {}
#line 2717 "parser.cpp"
    break;

  case 120:
#line 599 "parser.y"
                                                        { idRep = 1; id_Reporte = (yyvsp[0].TEXT); }
#line 2723 "parser.cpp"
    break;

  case 121:
#line 600 "parser.y"
                                                        { pathRep = 1; pathReporte = pathMount; }
#line 2729 "parser.cpp"
    break;

  case 122:
#line 601 "parser.y"
                                                        { nameRep = 1; }
#line 2735 "parser.cpp"
    break;

  case 123:
#line 602 "parser.y"
                                                        { rootRep = 1; root_Reporte = pathMount; }
#line 2741 "parser.cpp"
    break;

  case 124:
#line 604 "parser.y"
                                                        { mbrRep = 1; }
#line 2747 "parser.cpp"
    break;

  case 125:
#line 605 "parser.y"
                                                        { sbRep = 1; }
#line 2753 "parser.cpp"
    break;

  case 126:
#line 606 "parser.y"
                                                        { diskRep = 1; }
#line 2759 "parser.cpp"
    break;

  case 127:
#line 607 "parser.y"
                                                        { treeRep = 1; }
#line 2765 "parser.cpp"
    break;

  case 128:
#line 608 "parser.y"
                                                        { inodeRep = 1; }
#line 2771 "parser.cpp"
    break;

  case 129:
#line 611 "parser.y"
                                                        {


}
#line 2780 "parser.cpp"
    break;

  case 130:
#line 616 "parser.y"
                                                        {}
#line 2786 "parser.cpp"
    break;

  case 131:
#line 617 "parser.y"
                                                        {}
#line 2792 "parser.cpp"
    break;

  case 132:
#line 619 "parser.y"
                                                        { fileC = 1; fileCat = pathMount;
	if(fileC == 1){
		if(comDisc == 1){
			pathReporte = disco::quitarComillas(pathReporte);
			cat::ContentA(fileCat, idLogin,aceptado);
		}else{
			cat::ContentA(fileCat, idLogin,aceptado);
		}
	}else{
		cout <<"Fal el comando file"<<endl;
	}
}
#line 2809 "parser.cpp"
    break;

  case 133:
#line 632 "parser.y"
                                      {
	if(pathMov == 1 && destMov == 1){
		if(comDisc == 1){
			pathMove = disco::quitarComillas(pathMove);
			destMove = disco::quitarComillas(destMove);
			move::teleport(pathMove,destMove,idLogin,aceptado);
		}else{
			move::teleport(pathMove,destMove,idLogin,aceptado);
		}
	}else{
		cout<<"Falta un parametro obligatorio"<<endl;
	}

}
#line 2828 "parser.cpp"
    break;

  case 134:
#line 647 "parser.y"
                                                        {}
#line 2834 "parser.cpp"
    break;

  case 135:
#line 648 "parser.y"
                                                        {}
#line 2840 "parser.cpp"
    break;

  case 136:
#line 650 "parser.y"
                                                        { pathMov = 1; pathMove = pathMount; }
#line 2846 "parser.cpp"
    break;

  case 137:
#line 651 "parser.y"
                                                        { destMov = 1; destMove = pathMount; }
#line 2852 "parser.cpp"
    break;

  case 138:
#line 653 "parser.y"
                                                        {

	if(pathEd == 1){
		if((contEd == 1) && (stdinEd == 1)){
			cout<<"entra aqui puta madre :( "<<endl;
                       	cout<<"No pueden venir juntos el parametro cont y el stdin"<<endl;
		}else{
			if(comDisc == 1){
				pathEdit = disco::quitarComillas(pathEdit);
				contEdit = disco::quitarComillas(contEdit);
				edit::editar(pathEdit,contEdit,stdinEd,idLogin,aceptado);
			}else{
				edit::editar(pathEdit,contEdit,stdinEd,idLogin,aceptado);
			}
}
	}else{
		cout<<"Es necesario el parametro path"<<endl;
	}
	contEd = 0; stdinEd = 0; pathEd = 0; comDisc = 0; pathEdit = ""; contEdit = "";
}
#line 2877 "parser.cpp"
    break;

  case 139:
#line 674 "parser.y"
                                                        {}
#line 2883 "parser.cpp"
    break;

  case 140:
#line 675 "parser.y"
                                                        {}
#line 2889 "parser.cpp"
    break;

  case 141:
#line 677 "parser.y"
                                                        { pathEd = 1; pathEdit = pathMount;}
#line 2895 "parser.cpp"
    break;

  case 142:
#line 678 "parser.y"
                                                        { contEd = 1; contEdit = pathMount; }
#line 2901 "parser.cpp"
    break;

  case 143:
#line 679 "parser.y"
                                                        { stdinEd = 1; }
#line 2907 "parser.cpp"
    break;

  case 144:
#line 681 "parser.y"
                                                        {
	if(pathRem == 1){
		if(comDisc == 1){
			pathRemove = disco::quitarComillas(pathRemove);
			remove::buscar(pathRemove,idLogin,aceptado);
		}else{
			remove::buscar(pathRemove,idLogin,aceptado);
		}
	}
}
#line 2922 "parser.cpp"
    break;

  case 145:
#line 692 "parser.y"
                                                        {}
#line 2928 "parser.cpp"
    break;

  case 146:
#line 693 "parser.y"
                                                        {}
#line 2934 "parser.cpp"
    break;

  case 147:
#line 695 "parser.y"
                                                        { pathRem = 1; pathRemove = pathMount; }
#line 2940 "parser.cpp"
    break;


#line 2944 "parser.cpp"

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
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc);
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp, yylsp);
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
#line 698 "parser.y"
