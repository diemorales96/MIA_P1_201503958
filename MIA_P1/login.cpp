#include "login.h"
#include "mount.h"

void login::verificar(string user, string pass, string id) {
    credenciales log;
    if(user == "root" && pass =="123" && log.entro == false){
        log.entro = true;
        log.idMount = id;
        cout << "Login con el id: " << id <<endl;
    }else{
        log.entro = false;
        log.idMount = "";
        cout << "Usuario o Contraseña incorrectos" << endl;
    }

}
