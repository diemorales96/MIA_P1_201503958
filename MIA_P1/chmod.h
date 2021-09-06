
#ifndef MIA_P1_CHMOD_H
#define MIA_P1_CHMOD_H
#include "string.h"
#include "mkdir.h"

using namespace std;
class chmod {
public:
    static void cambiarP(string path, string p, string UGO, string id,bool entra);
};


#endif //MIA_P1_CHMOD_H
