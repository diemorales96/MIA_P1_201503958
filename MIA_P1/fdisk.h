
#ifndef MIA_P1_FDISK_H
#define MIA_P1_FDISK_H

#include <stdlib.h>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <cstdlib>

#include "disco.h"

using namespace std;


class fdisk {
public:
    static void crearParticion(string tam, string uni, string pat, string fi, string typ, string nam );
    static void crearPrimaria(string pat, char typ, char fi, long tam, string nam);
    static void crearExtendida(string pat, char typ, char fi, long tam, string nam);
    static void crearLogica(string pat, char typ,char fi,long tam,string name);


    static void extenderParticion();

    static void eliminarP(string nam, string pat, string tipo);
    static void eliminarParticion(string nam, string pat, string tipo);

    static int verificarNombre(string pa, string nombre);
};

typedef struct espacio{
    long int inicio;
    long int final;
    char tip;
    string particion;
}espacio;

#endif //MIA_P1_FDISK_H
