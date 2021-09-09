#include "move.h"
#include "mount.h"
#include "mkdir.h"
#include <vector>

void move::teleport(string path, string destino,string id,bool entra) {
    if(entra != true){
        cout<<"Debe tener una sesion iniciada para ejecutar este comando"<<endl;
        return;
    }

    int n = 0;
    vector <string> ruta;
    vector <string> dest;
    ruta = mkdir::split(path,'/');
    dest = mkdir::split(destino,'/');
    listMounted particion;
    particion = mount::recorrerLista(id);
    FILE *archivo;
    archivo = fopen(particion.path.c_str(), "rb+");
    int contador = 0;
    contador = ruta.size();
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
    int siguienteI = 0;
    int actual = 0;
    int padre = 0;
    int apuntador = 0;
    int x = 0, z = 0;
    int referencia = 0;
    string nameMov = "";

    for (int i = 1; i < contador; i++) {
        for (int j = 0; j < 15; j++) {
            if (aux2.i_block[j] != -1) {
                if (j < 12) {
                    fseek(archivo, aux.s_block_start + (64 * aux2.i_block[j]), SEEK_SET);
                    fread(&aux3, 64, 1, archivo);

                    for (int k = 0; k < 4; k++) {
                        string nombreArchivo(aux3.b_content[k].b_name);
                        if (nombreArchivo == ruta[i]) {
                            encontrado = true;
                            x = k;
                            if(i+1 == contador){
                                referencia = aux3.b_content[k].b_inodo;
                                nameMov = aux3.b_content[k].b_name;
                                aux3.b_content[k].b_inodo = -1;
                                strcpy(aux3.b_content[k].b_name,"--");

                                fseek(archivo, aux.s_block_start + (64 * aux2.i_block[j]), SEEK_SET);
                                fwrite(&aux3,64,1,archivo);

                            }
                            actual = aux3.b_content[0].b_inodo;
                            break;
                        }
                    }
                    if(encontrado){

                        fseek(archivo, aux.s_inode_start + (sizeof(Inodo)*aux3.b_content[x].b_inodo), SEEK_SET);
                        fread(&aux2, sizeof(Inodo), 1, archivo);
                        if((i+1) != contador){
                            encontrado = false;
                        }else{

                            fseek(archivo, aux.s_inode_start + (sizeof(Inodo)*aux3.b_content[x].b_inodo), SEEK_SET);
                            fread(&aux2, sizeof(Inodo), 1, archivo);
                            if(aux2.i_type == '1'){
                                nameMov = aux3.b_content[x].b_name;
                                referencia = aux3.b_content[x].b_inodo;
                            }
                        }

                        break;
                    }


                }
            }
        }

    }
    if(encontrado){
        int contador2 = 0;
        contador2 = dest.size();
        fseek(archivo, aux.s_inode_start, SEEK_SET);
        fread(&aux2, sizeof(Inodo), 1, archivo);
        encontrado = false;

        for (int j = 1; j < contador2; j++) {
            for (int k = 0; k < 15; k++) {
                if (aux2.i_block[k] != -1) {
                    if (k < 12) {

                        fseek(archivo, aux.s_block_start + (64 * aux2.i_block[k]), SEEK_SET);
                        fread(&aux3, 64, 1, archivo);

                        for (int y = 0; y < 4; y++) {
                            string nombreArchivo(aux3.b_content[y].b_name);
                            if (nombreArchivo == dest[j]) {
                                encontrado = true;
                                padre = aux3.b_content[0].b_inodo;
                                actual = aux3.b_content[1].b_inodo;
                                x = aux3.b_content[y].b_inodo;
                                break;
                            }
                        }
                        if(encontrado){
                            fseek(archivo, aux.s_inode_start + (sizeof(Inodo)*x), SEEK_SET);
                            fread(&aux2, sizeof(Inodo), 1, archivo);

                            if((j+1) != contador2){
                                encontrado = false;
                            }
                            break;
                        }
                    }
                }else{
                    break;
                }
            }
        }
        if(encontrado||destino == "/"){
            if(destino == "/"){
                fseek(archivo, aux.s_inode_start, SEEK_SET);
                fread(&aux2, sizeof(Inodo), 1, archivo);
                x = 0;
                actual = 0;
                padre = 0;
            }else{
                fseek(archivo, aux.s_inode_start + (sizeof(Inodo)*x), SEEK_SET);
                fread(&aux2, sizeof(Inodo), 1, archivo);
            }


            for(int k = 0;k<15;k++){
                if(aux2.i_block[k] != -1){
                    if(k<12){
                        fseek(archivo, aux.s_block_start + (64 * aux2.i_block[k]), SEEK_SET);
                        fread(&aux3, 64, 1, archivo);
                        for (int y = 0; y < 4; y++) {
                            if(aux3.b_content[y].b_inodo == -1){
                                aux3.b_content[y].b_inodo = referencia;
                                strcpy(aux3.b_content[y].b_name,nameMov.c_str());
                                fseek(archivo, aux.s_block_start + (64 * aux2.i_block[k]), SEEK_SET);
                                fwrite(&aux3,64,1,archivo);
                                break;
                            }

                        }
                    }
                }else{
                    if(k < 12){
                        BloqueCarpetas NuevaC;
                        NuevaC = mkdir::CrearBloqueCarpetas(actual,padre);
                        NuevaC.b_content[2].b_inodo = referencia;
                        strcpy(NuevaC.b_content[2].b_name,nameMov.c_str());
                        aux2.i_block[k] = aux.s_blocks_count + 1;
                        fseek(archivo,aux.s_block_start+(64*(aux.s_blocks_count+1)),SEEK_SET);
                        fwrite(&NuevaC,64,1,archivo);
                        aux.s_blocks_count ++;
                        aux.s_free_blocks_count --;
                        fseek(archivo,inicioP,SEEK_SET);
                        fwrite(&aux,sizeof(SuperBloque),1,archivo);
                        fseek(archivo, aux.s_inode_start + (sizeof(Inodo)*x), SEEK_SET);
                        fwrite(&aux2,sizeof(Inodo),1,archivo);
                        break;
                    }
                }
            }
        }
    }else{
        cout<<"Error";
        return;
    }
    fclose(archivo);
}

int move::buscarLibre(int x,int inicioP,string path,int padre,int actual) {
    FILE  *archivo;
    archivo = fopen(path.c_str(), "rb+");
    SuperBloque aux;
    Inodo aux2;
    BloqueCarpetas aux3;
    fseek(archivo, inicioP, SEEK_SET);
    fread(&aux, sizeof(aux), 1, archivo);

    fseek(archivo, aux.s_inode_start, SEEK_SET);
    fread(&aux2, sizeof(Inodo), 1, archivo);
    for(int i = 0; i < 15; i++){
        if(aux2.i_block[i] != -1){
            if(i < 12){
                fseek(archivo, aux.s_block_start + (64 * aux2.i_block[i]), SEEK_SET);
                fread(&aux3, 64, 1, archivo);
                for(int j = 0; j < 4; j++){
                    if(aux3.b_content[j].b_inodo == -1){
                        return j;
                    }
                }
            }
        }

    }
}