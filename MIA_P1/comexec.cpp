
#include "comexec.h"
#include "string.h"
#include <fstream>
#include "parser.h"

using namespace std;

extern int yyrestart(FILE *archivo);
extern int yyparse();

void comexec::leer(string ruta){
    string linea;
    ifstream archivoE(ruta);
    while(getline(archivoE,linea)){
        analizar(linea);
    }
}

void comexec::analizar(string cadena){
    string text1;
    text1 = cadena;
    ofstream archivo;
    archivo.open("datosAnalizar.txt");
    archivo << text1;
    archivo.close();
    text1.clear();

    FILE * input = fopen("datosAnalizar.txt","r");
    yyrestart(input);
    if( yyparse() == 0 ){
        cout << "Todo bien :) " <<endl;
    }
}