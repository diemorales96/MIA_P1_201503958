//
// Created by diego on 1/09/21.
//
#ifndef MIA_P1_LOGIN_H
#define MIA_P1_LOGIN_H
#include "string.h"
#include "mount.h"


using namespace std;

typedef struct credenciales{
    string idMount = "";
    bool entro = false;

} credenciales;

class login {
public:
    static void verificar(string user,string pass, string id);
    login();
};


#endif //MIA_P1_LOGIN_H
