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


static int fileC = 0;
static string fileCat = "";

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
%token<TEXT> Mount
%token<TEXT> Unmount Id
%token<TEXT> Fdisk Type Delete Name Add P E L Fast Full Units

%token<TEXT> Touch R Cont Stdin

%token<TEXT> Mkfs Fs Fs2 Fs3

%token<TEXT>  Mkdir

%token<TEXT> Find Asterisco Interrogacion


%token<TEXT>  Login User Pwd Logout

%token<TEXT>  Ren
%token<TEXT>  Chmod Ugo
%token<TEXT>  Rep Mbr Disk Sb Tree Root Inode
%token<TEXT>  TIgual TTexto TID TCara
%token<TEXT>  TMenos
%token<TEXT>  Cat File
%token<TEXT>  Mv Dest
%token<TEXT>  Edit


//****************************** NO TERMINALES

%type<TEXT>  S CODIGO SENTENCIAS
%type<TEXT>  MKDISK CUERPO_MKDISK COMMAND_MKDISK UNIDAD DIRECCION AJUSTE
%type<TEXT> AJUSTEPART

%type<TEXT> RMDISK
%type<TEXT> EXEC
%type<TEXT> PAUSE
%type<TEXT> MOUNT CUERPO_MOUNT COMMAND_MOUNT
%type<TEXT> UNMOUNT
%type<TEXT> FDISK CUERPO_FDISK COMMAND_FDISK TIPO_PARTICION NOMBRE TDELETE
%type<TEXT> MKFS CUERPO_MKFS COMMAND_MKFS
%type<TEXT> TIPO_FORMATEO

%type<TEXT> TOUCH CUERPO_TOUCH COMMAND_TOUCH

%type<TEXT> MKDIR CUERPO_MKDIR COMMAND_MKDIR

%type<TEXT> LOGIN CUERPO_LOGIN COMMAND_LOGIN

%type<TEXT> REN CUERPO_REN COMMAND_REN

%type<TEXT> FIND CUERPO_FIND COMMAND_FIND TERMINA_FIND

%type<TEXT> CHMOD CUERPO_CHMOD COMMAND_CHMOD

%type<TEXT> REP CUERPO_REP COMMAND_REP TIPO_REP

%type<TEXT> CAT CUERPO_CAT COMMAND_CAT LOGOUT

%type<TEXT> MV CUERPO_MV COMMAND_MV

%type<TEXT> EDIT CUERPO_EDIT COMMAND_EDIT

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
			| PAUSE		{}
			| MOUNT		{}
			| UNMOUNT	{}
			| MKFS		{}
			| MKDIR		{}
			| TOUCH		{}
			| LOGIN		{}
			| REN		{}
			| FIND		{}
			| CHMOD		{}
			| REP		{}
			| CAT		{}
			| LOGOUT	{}
			| MV		{}
			| EDIT		{};

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

DIRECCION       	: TTexto    { pathMount = $1;  pathPart = $1; pathDisc = $1; patDisc = 1; comDisc = 1;
				     pathMkdir = $1;pathT = 1; path_find = $1;}
                	| Direccion { pathMount = $1;  pathPart = $1; pathDisc = $1; patDisc = 1; pathMkdir =
                		$1; pathT = 1; path_find = $1; };

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

NOMBRE          	: TTexto { namePart = disco::quitarComillas($1); nombreRen = disco::quitarComillas($1);}
                	| TID    { namePart = $1; nombreRen = $1;};

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
//------------------------------------PAUSE------------------------------------------------------------
PAUSE 			: Pause {
	printf("Presione ENTER para continuar: \n");
	int c = getchar();
};

//------------------------------------MOUNT------------------------------------------------------------
MOUNT 			: Mount CUERPO_MOUNT 		{
		if(pathR == 1 && idR == 1){
			if(comDisc == 1){
				pathMount = disco::quitarComillas(pathMount);
				mount::montar(pathMount, iMount);
			}else{
				mount::montar(pathMount, iMount);
			}
		}
		pathR = 0; comDisc = 0; iMount = ""; pathMount = "";
};

CUERPO_MOUNT 		: CUERPO_MOUNT COMMAND_MOUNT  	{}
			| COMMAND_MOUNT 	   	{};

COMMAND_MOUNT 		: Path TIgual DIRECCION 	{pathR = 1;}
			| Name TIgual TID 		{idR = 1; iMount = $3;};
//------------------------------------UNMOUNT------------------------------------------------------------
UNMOUNT         	: Unmount Id TIgual TID  {
		    iMount = $4;
		    mount::desmontarParticiones(iMount);
		    iMount = "";
                                          	};

//------------------------------------MKFS------------------------------------------------------------
MKFS			: Mkfs CUERPO_MKFS{
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
};

CUERPO_MKFS		: CUERPO_MKFS COMMAND_MKFS 	{}
			| COMMAND_MKFS			{};

COMMAND_MKFS		: Type TIgual TDELETE 		{ tMkfs = 1; tipoMkfs = deletePart; }
			| Id TIgual TID			{ idMkfs = 1; identificadorMkfs = $3; }
			| Fs TIgual TIPO_FORMATEO	{ sistMkfs = 1; };

TIPO_FORMATEO		: Fs2 				{ sistemaMkfs = "2fs";}
			| Fs3				{ sistemaMkfs = "3fs";};
//------------------------------------MKDIR------------------------------------------------------------

MKDIR			: Mkdir CUERPO_MKDIR 		{
	if(patMkdir == 1){
		if (p == 1){
			mkdir::crearCarpeta(pathMkdir,"","Particion1",idLogin,aceptado);
		}else{
			mkdir::crearCarpeta(pathMkdir,"","Particion1",idLogin,aceptado);
		}
	}else{
		cout <<"Falta parametro path en el comando MKDIR ";
	}
};

CUERPO_MKDIR		: CUERPO_MKDIR COMMAND_MKDIR 	{}
			| COMMAND_MKDIR			{};

COMMAND_MKDIR		: TMenos P 			{ p = 1; }
			| Path TIgual DIRECCION 	{ patMkdir = 1; };
//--------------------------------------- TOUCH --------------------------------------------------------------------
TOUCH 			: Touch CUERPO_TOUCH		{
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

};

CUERPO_TOUCH 		: CUERPO_TOUCH COMMAND_TOUCH	{}
			| COMMAND_TOUCH			{};

COMMAND_TOUCH 		: Tamanio TIgual TNumero	{ sizeT = 1; sizeTouch = $3; }
			| Path TIgual DIRECCION		{ pathTouch = pathMkdir; }
			| Cont TIgual DIRECCION		{ contT = 1; contTouch = pathMkdir; }
			| Stdin				{stdinT = 1;}
			| R 				{rT = 1;};

//-------------------------------- LOGIN -------------------------------------------------------------------------
LOGIN			: Login CUERPO_LOGIN 		{
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

};

CUERPO_LOGIN 		: CUERPO_LOGIN COMMAND_LOGIN	{}
			| COMMAND_LOGIN			{};

COMMAND_LOGIN		: User TIgual TID 		{ userL = 1; userLogin = $3; }
			| Pwd TIgual TNumero 		{ pwdL = 1; pwdLogin = $3; }
			| Id TIgual TID 		{ idL = 1; idLogin = $3; };

LOGOUT 			: Logout 			{
		cout<<"--------------Cerro Sesion-------------"<<endl;
		userL = 0; userLogin = ""; pwdL = 0; pwdLogin = ""; idL = 0; idLogin = "",aceptado = false;
};

//---------------------------------- REN ---------------------------------------------------------------------------
REN			: Ren CUERPO_REN		{
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
};

CUERPO_REN 		: CUERPO_REN COMMAND_REN	{}
			| COMMAND_REN			{};

COMMAND_REN		: Path TIgual DIRECCION		{ pathRe = 1; pathRen = pathMkdir; }
			| Name TIgual NOMBRE		{ nombreRe = 1; };
//----------------------------------------- FIND -----------------------------------------------------------------------
FIND			: Find CUERPO_FIND 		{
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
};

CUERPO_FIND 		: CUERPO_FIND COMMAND_FIND	{}
			| COMMAND_FIND			{};

COMMAND_FIND		: Path TIgual DIRECCION		{ path_f = 1; }
			| Name TIgual TERMINA_FIND	{ name_f = 1; };

TERMINA_FIND		: Asterisco TID		{ termina_f_ast = 1; termina_find_ast = "*"; name_find = $2; }
			| Interrogacion TID	{ termina_f_int = 1; termina_find_int = "?"; name_find = $2; }
			| TID			{ termina_f_carp = 1; name_find = $1; };
//------------------------------------- CHMOD -----------------------------------------------------------------
CHMOD			: Chmod CUERPO_CHMOD 		{
	if(pathCh == 1 && ugoCh == 1){
		if(comDisc == 1){
			pathChmod = disco::quitarComillas(pathChmod);
			chmod::cambiarP(pathChmod,rChmod,ugoChmod,idLogin,aceptado);
		}else{
			chmod::cambiarP(pathChmod,rChmod,ugoChmod,idLogin,aceptado);
		}
	}
};

CUERPO_CHMOD 		: CUERPO_CHMOD COMMAND_CHMOD	{}
			| COMMAND_CHMOD			{};

COMMAND_CHMOD		: Path TIgual DIRECCION		{ pathCh = 1; pathChmod = $3; }
			| Ugo TIgual TNumero		{ ugoCh = 1; ugoChmod = $3; }
			| R 				{ rCh = 1; rChmod = "r"; };
//------------------------------------- REP -----------------------------------------------------------------

REP 			: Rep CUERPO_REP		{
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
};

CUERPO_REP 		: CUERPO_REP COMMAND_REP	{}
			|COMMAND_REP			{};

COMMAND_REP		: Id TIgual TID 		{ idRep = 1; id_Reporte = $3; }
			| Path TIgual DIRECCION		{ pathRep = 1; pathReporte = pathMount; }
			| Name TIgual TIPO_REP		{ nameRep = 1; }
			| Root TIgual DIRECCION		{ rootRep = 1; root_Reporte = pathMount; };

TIPO_REP		: Mbr 				{ mbrRep = 1; }
			| Sb				{ sbRep = 1; }
			| Disk				{ diskRep = 1; }
			| Tree				{ treeRep = 1; }
			| Inode				{ inodeRep = 1; };
//------------------------------------- CAT -----------------------------------------------------------------

CAT 			: Cat CUERPO_CAT		{


};

CUERPO_CAT		: CUERPO_CAT COMMAND_CAT	{}
			| COMMAND_CAT			{};

COMMAND_CAT 		: File TNumero TIgual DIRECCION	{ fileC = 1; fileCat = pathMount;
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
};

MV			: Mv CUERPO_MV{
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

};

CUERPO_MV		: CUERPO_MV COMMAND_MV		{}
			| COMMAND_MV			{};

COMMAND_MV 		: Path TIgual DIRECCION		{ pathMov = 1; pathMove = pathMount; }
			| Dest TIgual DIRECCION		{ destMov = 1; destMove = pathMount; };

EDIT			: Edit CUERPO_EDIT		{

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
};

CUERPO_EDIT		: CUERPO_EDIT COMMAND_EDIT	{}
			| COMMAND_EDIT			{};

COMMAND_EDIT		: Path TIgual DIRECCION		{ pathEd = 1; pathEdit = pathMount;}
			| Cont TIgual DIRECCION		{ contEd = 1; contEdit = pathMount; }
			| Stdin				{ stdinEd = 1; };

%%