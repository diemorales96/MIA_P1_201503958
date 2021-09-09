#include "ren.h"
#include "mount.h"
#include "mkdir.h"
#include <vector>

void ren::cambiarNombre(string path, string nombreC,string id,bool entra){
    if(!entra){
        cout<<"Usuario No Logeado"<<endl;
        return;
    }

    int n = 0;
    vector<string> ruta;
    ruta = mkdir::split(path,'/');
    listMounted particion;
    particion = mount::recorrerLista(id);
    FILE *archivo;

    archivo = fopen(particion.path.c_str(), "rb+");
    int contador = ruta.size();
    MBR mbr;
    rewind(archivo);
    fread(&mbr, sizeof(mbr), 1, archivo);
    int inicioP = 0;
    int tam_P = 0;
    string nombre;
    for (int i = 0; i < particion.listMountedPartitions.size(); i++) {
        if (particion.listMountedPartitions[i].idPart == id) {
            nombre = particion.listMountedPartitions[i].nombrePart;
            break;
        }
    }

    for (int i = 0; i < 4; i++)
    {
        if (mbr.mbr_partition[i].part_name == nombre)
        {
            inicioP = mbr.mbr_partition[i].part_start;
            tam_P = mbr.mbr_partition[i].part_size;
            break;
        }
    }

    n = (tam_P - sizeof(SuperBloque)) / (4 + sizeof(Inodo) + 3 * 64);
    SuperBloque aux;
    Inodo aux2;
    BloqueCarpetas aux3;
    fseek(archivo, inicioP, SEEK_SET);
    fread(&aux, sizeof(aux), 1, archivo);
    time_t tiempo = time(0);
    struct tm *tlocal = localtime(&tiempo);
    char fechaActual[16];
    strftime(fechaActual, 16, "%d/%m/%y %H:%M:%S", tlocal);

    fseek(archivo, aux.s_inode_start, SEEK_SET);
    fread(&aux2, sizeof(Inodo), 1, archivo);
    bool encontrado = false;
    int x = 0, z = 0;
    for (int i = 1; i < contador; i++) {
        for (int j = 0; j < 15; j++) {
            if (aux2.i_block[j] != -1) {
                if (j < 12) {

                    fseek(archivo, aux.s_block_start + (64 * aux2.i_block[j]), SEEK_SET);
                    fread(&aux3, 64, 1, archivo);


                    for (int k = 0; k < 4; k++) {
                        string nombreArchivo(aux3.b_content[k].b_name);
                        if(nombreArchivo == nombreC){
                            cout<<"Este nombre ya existe en esta carpeta"<<endl;
                            return;
                        }
                        if (nombreArchivo == ruta[i]) {
                            x = k;
                            z = aux2.i_block[j];
                            encontrado = true;
                        }
                    }
                    if(encontrado){
                        fseek(archivo, aux.s_inode_start + (sizeof(Inodo)*aux3.b_content[x].b_inodo), SEEK_SET);
                        fread(&aux2, sizeof(Inodo), 1, archivo);
                        break;
                    }
                }
            }else{
                break;
            }
        }
        if((encontrado) && ((i+1) == contador)){
            strcpy(aux3.b_content[x].b_name,nombreC.c_str());
            fseek(archivo, aux.s_block_start + (64 * z), SEEK_SET);
            fwrite(&aux3,64,1,archivo);
            fclose(archivo);
        }else{
            encontrado = false;
        }
    }

}