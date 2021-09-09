
#ifndef MIA_P1_ARBOL_H
#define MIA_P1_ARBOL_H
#include "mkdir.h"
#include "string.h"

using namespace std;
class arbol {
public:
    static void Reporte(string id, string path, string inicio);
    static string buscarTodo(int siguienteI, int inicioP, FILE *archivo, string repo,string anterior);
    static string buscarInodos( Inodo tabla, int inodo);
    static string buscarBloques(BloqueCarpetas bloque, int actual, int padre, int Nbloque);
    static string buscarArchivos(int Nbloque);
};


#endif //MIA_P1_ARBOL_H
