%option noyywrap
%option case-insensitive

%{
        #include "parser.h"
        #include "stdlib.h"
        #include "stdio.h"
        #include "error.h"
        #include <iostream>

        using namespace std;

    int fila =1;
    int columna=0;

%}

SaltoDeLinea    [ \n | \r | \r\n | \t\r\f\n]
Espacio         [(" " | (\t\f)]

Digito          [0-9]
TkNumero        {Digito}+("."{Digito}+)?

Letra           [a-zA-ZZñÑáéíóúÁÉÍÓÚ]

Id              (({Digito}+)|{Letra})({Letra}|"_"|{Digito})*

texto           \"[^\n"]+\"

cara 		    \'(^^|#t|#n|\^\'|[^\'])\'

Direccion  	    "/"[^\r\n" "]*[^\r\n" "]

Comentario	    "#"[^\r\n]*[^\r\n]

%%

"Mkdisk"			{	return (Mkdisk);  }
"Rmdisk"			{	return (Rmdisk);  }
"Exec"              {   return (Exec);    }
"Pause"             {   return (Pause);   }
"Mount"             {   return (Mount);   }
"Unmount"           {   return (Unmount); }

"login"             {   return (Login);   }
"-user"             {   return (User);    }
"-pwd"              {   return (Pwd);     }

"ren"               {   return (Ren);     }


"Mkfs"              {   return (Mkfs);    }
"-fs"               {   return (Fs);      }
"2fs"               {   return (Fs2);     }
"3fs"               {   return (Fs3);     }

"Mkdir"             {   return (Mkdir);   }

"touch"             {   return (Touch);   }
"-r"                {   return (R);       }
"-cont"             {   return (Cont);    }
"-stdin"            {   return (Stdin);    }

"Fdisk"			    {	return (Fdisk); }

"-type"				{	return (Type); 	}
"p"					{	return (P); 	}
"e"					{	return (E); 	}
"l"					{	return (L); 	}

"-delete"			{	return (Delete); 	}
"-name"				{	return (Name);	}
"Fast"				{	return (Fast); 	}
"Full"				{	return (Full); 	}
"-add"				{	return (Add); 	}
"-units"			{	return (Units); 	}

"-size"				{	return (Tamanio); }

"-f"				{	return (Fit); 	}
"bf"				{	return (Bf); 	}
"ff"				{	return (Ff); 	}
"wf"				{	return (Wf); 	}

"-u"                {	return (Unit); 	}
"k"					{	return (Kilo); 	}
"m"					{	return (Mega); 	}

"find"              {   return (Find);  }
"*"                 {   return (Asterisco);   }
"?"                 {   return (Interrogacion); }

"chmod"             {   return (Chmod); }
"-ugo"              {   return (Ugo);   }

"-path"				{	return (Path); 	}

"rep"				{	return (Rep); 	}
"mbr"				{	return (Mbr); 	}
"disk"				{	return (Disk); 	}


"="					{	return (TIgual); }
"-" 				{	return (TMenos); }

"-id"               {   return (Id); 	 }

{TkNumero}			{	strcpy(yylval.TEXT, yytext); return (TNumero); }
{texto}         	{ 	strcpy(yylval.TEXT, yytext); return (TTexto); }
{Id} 				{ 	strcpy(yylval.TEXT, yytext); return (TID); }

{cara}          	{   strcpy(yylval.TEXT, yytext); return (TCara); }

{Direccion}         {   strcpy(yylval.TEXT, yytext); return (Direccion); }

{Espacio}			{}
{SaltoDeLinea}	    { fila++; columna=0;}
{Comentario}		{ cout <<"Se encontro un Comentario" << endl; }

.                   {
                        cout << "Se encontro " << string(yytext)<< " : Error Lexico "<< fila << ", " <<columna <<endl;
                    }
%%