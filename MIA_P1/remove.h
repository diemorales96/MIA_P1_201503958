//
// Created by diego on 8/09/21.
//

#ifndef MIA_P1_REMOVE_H
#define MIA_P1_REMOVE_H
#include "mkdir.h"
#include "string.h"

using namespace std;
class remove {
public:
    static void buscar(string path, string id,bool aceptado);
    static void buscarTodo(int siguienteI, int inicioP, FILE *archivo);
};


#endif //MIA_P1_REMOVE_H
