#ifndef MIA_P1_MOUNT_H
#define MIA_P1_MOUNT_H

#include <vector>
#include "fdisk.h"
using namespace std;

typedef struct partMontada{
    string letra;
    int estado = 0;
    string nombrePart;
    string idPart;
}partMontada;

typedef struct listMounted{
    int id;
    string nombreDisco;
    string path;
    int num = 0;
    vector<partMontada> listMountedPartitions;
} listMounted;

static char letras[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
static vector<listMounted> listaMontados;
static int contM = 0, contA = 0;


class mount {
public:
    static void montar(string path, string name);
    static listMounted discoMontado(string path);
    static string obtenerNDisco(string path);
    static void agregarDisco(string nombreDisco, string path);
    static int particionMontada(string name, listMounted disco);
    static int agregarParticion(string partName, listMounted disco);
    static void mostrarParticiones();
    static listMounted recorrerLista(string id);
    static void desmontarParticiones(string idParticionM);

};


#endif //MIA_P1_MOUNT_H
