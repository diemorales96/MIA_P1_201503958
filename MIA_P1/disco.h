
#ifndef MIA_P1_DISCO_H
#define MIA_P1_DISCO_H

#include <iostream>
#include "parser.h"
#include <math.h>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <cstdlib>

using namespace std;

typedef struct Partition{
    char part_status = '\0'; //Indica si la partición está activa o no
    char part_type = '\0'; //Indica el tipo de partición, primaria o extendida. Tendrá los valores ​ P ​ o ​ E
    char part_fit = '\0'; //Tipo de ajuste de la partición. Tendrá los valores ​ B ​ (Best), ​ F ​ (First) o ​ W ​ (worst)
    long int part_start = 0; //Indica en que byte del disco inicia la partición
    long int part_size = 0; //Contiene el tamaño total de la partición en bytes
    char part_name[16]; //Nombre de la partición
}Partition;

typedef struct MBR{
    long int mbr_tamano = 0; //Tamaño total del disco en bytes
    char mbr_fecha_creacin[25]; //time Fecha y hora de creación del disco
    int mbr_disk_signature = 0; //Número random, que identifica de forma única a cada disco
    char disk_fit = '\0'; //Tipo de ajuste de la partición. Tendrá los valores ​ B(Best), F(First) o W(worst)
    Partition mbr_partition[4]; //partition Estructura con información de la partición 1- 4
}MBR;

typedef  struct EBR{
    char part_status = '\0';
    char part_fit = '\0';
    long int par_start = 0;
    long int part_size = 0;
    int part_next = 0;
    char part_name[16];
}EBR;


class disco {
public:
    static void crearDisco(string tam, string uni, string fi, string pat);
    static string quitarComillas(string path);
    static bool verificarExtension(string path);
    static void crearDirectorio(string path);
    static int existeCarpeta(char ruta[]);
    static void crearCarpeta(char ruta[]);

    static void eliminarDisco(string path);

    static void f( char cadena[]);
    static int aleatorio();

    static void repoteMBR(string id, string path);
    static void reporteEBR(string id, string path);
    static void reporteDisco(string id, string path);
    static void generarGraficaDisk(MBR &mbr,string destino,string disco,FILE *archivo);
    static double obtenerPorcentaje(int tamanio,int tamanioTotal);
public:
    disco();
};


#endif //MIA_P1_DISCO_H
