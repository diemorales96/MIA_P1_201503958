%{
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


using namespace std;


extern int fila;
extern int columna;
extern char *yytext;


// ***************NODO BY DEAFULT
static string tamanioDisc = "", fitDisc = "ff", unitDisc = "m", pathDisc = "";
static string tamanioPart = "", fitPart = "wf", unitPart = "k", pathPart = "", tipoPart = "P", deletePart = "", namePart = "", addPart = "";
static string idReporte = "", pathR = "", tipoRep = "";
static string pathMount = "", idMount = "";


static int tmDisc = 0, patDisc = 0, comDisc = 0, namDisc = 0, delDisc = 0, addDisc = 0, unDisc = 0, c1 = 0, c2 = 0, c3 =0, cc=0;
int n=0;


//********************ERRORES
int yyerror(const char* mens){
    cout << "Error Sintactico:" << endl;
    cout <<mens << ": " << yytext << " linea " << fila << " columna " << columna <<endl;
    cout << "\n" << endl;
    return 0;
}

%}

%define parse.error verbose
%locations

%union{
    char TEXT [256];
}

//****************************** TERMINALES

%token<TEXT>  Mkdisk Tamanio TNumero Fit Bf Wf Ff
%token<TEXT>  Unit Kilo Mega
%token<TEXT>  Path Direccion

%token<TEXT> Rmdisk
%token<TEXT> Exec
%token<TEXT> Pause
%token<TEXT> Fdisk Type Delete Name Add P E L Fast Full Units

%token<TEXT>  Rep Mbr Disk
%token<TEXT>  TIgual TTexto TID TCara
%token<TEXT>  TMenos 



//****************************** NO TERMINALES

%type<TEXT>  S CODIGO SENTENCIAS
%type<TEXT>  MKDISK CUERPO_MKDISK COMMAND_MKDISK UNIDAD DIRECCION AJUSTE
%type<TEXT> AJUSTEPART

%type<TEXT> RMDISK
%type<TEXT> EXEC
%type<TEXT> PAUSE
%type<TEXT> FDISK CUERPO_FDISK COMMAND_FDISK TIPO_PARTICION NOMBRE TDELETE

%start S



%%

S             		: CODIGO  {
                          cout << "Comando Ejecutado\n" << endl;
                        };

CODIGO          	: CODIGO SENTENCIAS {}
                  	| SENTENCIAS        {};

SENTENCIAS      	: MKDISK	{}
			| RMDISK 	{}
			| FDISK 	{}
			| EXEC		{}
			| PAUSE		{};

//--------------------------------------MKDISK---------------------------------------------------------
MKDISK          	: Mkdisk CUERPO_MKDISK    {
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
                      	};

CUERPO_MKDISK     	: CUERPO_MKDISK COMMAND_MKDISK {}
                	| COMMAND_MKDISK {};
                    

COMMAND_MKDISK        	: Tamanio TIgual TNumero  {tamanioDisc = $3; tmDisc = 1;}
                	| Unit TIgual UNIDAD      {}
                	| Path TIgual DIRECCION   {patDisc = 1;}
                	| Fit TIgual AJUSTE       {};
                
UNIDAD          	: Kilo    {unitDisc = "k"; unitPart = "k"; }
                	| Mega    { unitDisc = "m"; unitPart = "m"; };

DIRECCION       	: TTexto    {pathMount = $1;  pathPart = $1; pathDisc = $1; patDisc = 1; comDisc = 1;}
                	| Direccion { pathMount = $1;  pathPart = $1; pathDisc = $1; patDisc = 1;};

AJUSTE          	: Bf    { fitDisc ="bf"; }
                	| Wf    { fitDisc ="wf"; }
                	| Ff    { fitDisc ="ff"; };
//------------------------------------RMDISK-------------------------------------------------
RMDISK			: Rmdisk Path TIgual DIRECCION{
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
};

//------------------------------------FDISK------------------------------------------------------------
FDISK			: Fdisk CUERPO_FDISK{

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

                                                                                  };

CUERPO_FDISK		: CUERPO_FDISK COMMAND_FDISK	{}
			| COMMAND_FDISK			{};

COMMAND_FDISK		: Tamanio TIgual TNumero	{ tamanioPart = $3; tmDisc = 1; cc++; c1 = cc; }
			| Unit TIgual UNIDAD		{ unDisc = 1; }
			| Path TIgual DIRECCION		{ patDisc = 1; }
			| Fit TIgual  AJUSTEPART	{}
			| Type TIgual TIPO_PARTICION	{}
			| Delete TIgual TDELETE 	{ delDisc = 1; cc++; c2 = cc; }
			| Name TIgual NOMBRE      	{ namDisc = 1; }
			| Add TIgual TNumero      	{ addPart = $3; addDisc = 1; cc++; c3 = cc; }
			| Add TIgual TMenos TNumero     { addPart = $3; addDisc = 1; cc++; c3 = cc; };

AJUSTEPART         	: Bf    {fitPart = "bf"; }
                	| Wf    { fitPart = "wf"; }
                	| Ff    {fitPart = "ff"; };

TIPO_PARTICION      	: P   { tipoPart = "P"; }
                	| E   { tipoPart = "E"; }
                	| L   { tipoPart = "L"; };

TDELETE         	: Full  { deletePart = "full"; }
                	| Fast  { deletePart = "fast"; };

NOMBRE          	: TTexto { namePart = disco::quitarComillas($1); }
                	| TID    { namePart = $1; };

//------------------------------------EXEC------------------------------------------------------------
EXEC 			: Exec Path TIgual DIRECCION {
			if (patDisc == 1){
				if(comDisc == 1){
				      	pathPart = disco::quitarComillas(pathPart);
					comexec::leer(pathPart);
				}
				else
					comexec::leer(pathPart);
			}
};

PAUSE 			: Pause {
	printf("Presione ENTER para continuar: \n");
	int c = getchar();
};

%%


