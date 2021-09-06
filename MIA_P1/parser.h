/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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
    TIgual = 312,
    TTexto = 313,
    TID = 314,
    TCara = 315,
    TMenos = 316,
    Cat = 317,
    File = 318
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 83 "parser.y"

    char TEXT [256];

#line 125 "parser.h"

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
