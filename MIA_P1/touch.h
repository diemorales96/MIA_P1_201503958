
#ifndef MIA_P1_TOUCH_H
#define MIA_P1_TOUCH_H
#include <iostream>
#include "string.h"
#include "mkdir.h"
#include <vector>
using namespace std;

typedef struct listaChar{
    vector<BloqueArchivos> contenido;
}listaChar;

class touch {
public:
    static void crearArchivo(string path, string r, string Pname,string cont, string stdi, string size,bool entra);
    static listaChar CbloqueC(string contenido);
};



#endif //MIA_P1_TOUCH_H
