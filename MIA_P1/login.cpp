#include "login.h"
#include "mount.h"

void login::verificar(string user, string pass, string id) {

    if(user == "root" && pass =="123"){
            //cred[0].entro = true;
            //cred[0].mont = id;
        cout << "Login con el id: " << id <<endl;
    }else{
        //cred[0].entro = false;
        //cred[0].mont = "";
        cout << "Usuario o Contraseña incorrectos" << endl;
    }

}
