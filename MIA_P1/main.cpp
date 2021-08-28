#include <iostream>
#include "string.h"
#include "parser.h"
#include <cstdlib>
#include <stdlib.h>
#include <fstream>


using namespace std;

extern int yyrestart(FILE *archivo);
extern int yyparse();

void analizar(string cadena);
void leer(string ruta);

int main(){
    string opcion;
    string entrada;
    while (opcion != "salir"){
        cout << "-------Proyecto 1---------"<<endl;
        cout << "-------Ingese un Comando:---------"<<endl;

        cout<<"->";
        char imp2[200];
        cin.getline(imp2,200,'\n');
        cout<<"INPUT:"<<imp2<<endl;
        string a(imp2);
        opcion = a;
        if (a != "salir"){
            try {
                string com(imp2);
                analizar(com);
            } catch (string ex) {

            }
        }
    }
    return 0;
}

void analizar(string cadena){
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


//mkdisk -size=10 -path=/home/diego/Escritorio/s/disco1.dk
//rmdisk -path=/home/diego/Escritorio/s/disco1.dk
//home/diego/Escritorio/salidas/Entrada.sh
//fdisk -Size=300 -path=/home/diego/Escritorio/s/disco1.dk -name=Particion1
//exec -path=/home/diego/Escritorio/s/salida.txt