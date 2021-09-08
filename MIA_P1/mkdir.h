
#ifndef MIA_P1_MKDIR_H
#define MIA_P1_MKDIR_H
#include <iostream>
#include "string.h"
#include "mkfs.h"
#include <vector>

using namespace std;
class mkdir {
public:
    static vector<string> split(string str, char pattern);
    static void crearCarpeta(string path, string p, string Pname,string id,bool acceso);
    static string Separar(string path, int *content);
    static string Separar2(string path);
    static void Bitmap(char *bm, int n, int veces);
    static Inodo CInodo(char fechaActual[], int bloque,char tipo);
    static BloqueCarpetas CbloqueC(int actual, int padre);
    static BloqueApuntadores Crearapuntador();
    static void ReporteSuperBloque(string id, string path);


};


#endif //MIA_P1_MKDIR_H
