
#ifndef MIA_P1_MOVE_H
#define MIA_P1_MOVE_H
#include "mkfs.h"
#include "string.h"

using namespace std;

class move {
public:
    static void telepot(string path,string destino);
    static int buscarLibre(int x,int inicioP,string path,int padre,int acutal);
};


#endif //MIA_P1_MOVE_H
