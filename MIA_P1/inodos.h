
#ifndef MIA_P1_INODOS_H
#define MIA_P1_INODOS_H
#include "mkdir.h"
#include "string.h"
using namespace std;
class inodos {
public:
    static void Reporte(string path,string id);
    static string buscarTodo(int siguienteI,int inicio_P,FILE* archivo,string rep,string nombre);
};


#endif //MIA_P1_INODOS_H
