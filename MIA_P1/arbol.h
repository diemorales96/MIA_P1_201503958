
#ifndef MIA_P1_ARBOL_H
#define MIA_P1_ARBOL_H
#include "mkdir.h"
#include "string.h"

using namespace std;
class arbol {
public:
    static void Reporte(string id, string path, string inicio);
    static string buscarTodo(int siguienteI, int inicioP, FILE *archivo, string repo,string anterior);
    static string bInodos( Inodo tabla, int inodo);
    static string bBloques(BloqueCarpetas bloque, int actual, int padre, int Nbloque);
};


#endif //MIA_P1_ARBOL_H
