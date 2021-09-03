#ifndef MIA_P1_FIND_H
#define MIA_P1_FIND_H
#include "string.h"
#include "mkdir.h"
#include <vector>
using namespace std;

class find {
public:

    static string buscar(int uno, int varios, string path, string name, string id);
    static void buscarTodo(string dire, int uno, int varios, int siguienteI, int inicioP, string sufijo,FILE *file);
    static int verExtension(int uno, int varios, string nombre, string sufijo);
};


#endif //MIA_P1_FIND_H
