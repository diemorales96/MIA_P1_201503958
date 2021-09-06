#include "inodos.h"
#include "string.h"
#include "mount.h"
using  namespace std;

void inodos::Reporte(string path, string id) {
    listMounted particion;
    particion = mount::recorrerLista(id);
    FILE *archivo;
    archivo =  fopen(particion.path.c_str(),"rb");
    string rep;
    MBR mbr;
    rewind(archivo);
    fread(&mbr, sizeof(mbr), 1, archivo);
    string nombre;
    for(int i = 0; i < particion.listMountedPartitions.size(); i++){
        if (particion.listMountedPartitions[i].idPart == id)
        {
            nombre = particion.listMountedPartitions[i].nombrePart;
            break;
        }
    }
    int inicioP;
    int tam_P;
    for (int i = 0; i < 4; i++)
    {
        if (mbr.mbr_partition[i].part_name == nombre)
        {
            inicioP = mbr.mbr_partition[i].part_start;
            tam_P = mbr.mbr_partition[i].part_start;
            break;
        }
    }
    SuperBloque aux;
    Inodo aux2;
    BloqueCarpetas aux3;
    fseek(archivo, inicioP, SEEK_SET);
    fread(&aux, sizeof(aux), 1, archivo);
    time_t tiempo = time(0);
    struct tm *tlocal = localtime(&tiempo);
    char fechaActual[16];
    strftime(fechaActual, 16, "%d/%m/%y %H:%M:%S", tlocal);
    BloqueCarpetas s;
    fseek(archivo, aux.s_inode_start, SEEK_SET);
    fread(&aux2, sizeof(Inodo), 1, archivo);
    rep = buscarTodo(0,inicioP,archivo,rep,"/");
}



string inodos::buscarTodo( int siguienteI, int inicioP,FILE* archivo,string rep,string nombre)
{

    SuperBloque aux;
    Inodo aux2;
    BloqueCarpetas aux3;
    fseek(archivo, inicioP, SEEK_SET);
    fread(&aux, sizeof(SuperBloque), 1, archivo);
    fseek(archivo, aux.s_inode_start + (sizeof(Inodo) * siguienteI), SEEK_SET);
    fread(&aux2, sizeof(Inodo), 1, archivo);
    bool bandera = false;
    for (int i = 0; i < 15; i++)
    {
        if (aux2.i_block[i] != -1)
        {
            if (i < 12)
            {
                if(aux2.i_type == '0'){
                    fseek(archivo, aux.s_block_start + (64 * aux2.i_block[i]), SEEK_SET);
                    fread(&aux3, 64, 1, archivo);
                    for (int j = 0; j < 4; j++)
                    {
                        if(j>=2){
                            if (aux3.b_content[j].b_inodo != -1)
                            {
                                rep += "|{" + to_string(siguienteI)+"| Folder"+"|"+nombre+"}";
                                siguienteI = aux3.b_content[j].b_inodo;
                                cout<<rep<<endl;
                                cout <<"------------------------aqui-------------------------------"<<endl;
                                rep = buscarTodo(siguienteI,inicioP,archivo,rep,aux3.b_content[j].b_name);
                                if(j+1 < 4 && aux3.b_content[j+1].b_inodo != -1){
                                    siguienteI = aux3.b_content[j+1].b_inodo;
                                    nombre = aux3.b_content[j+1].b_name;
                                }
                            }
                        }
                    }
                }else{
                    BloqueArchivos contenido;
                    fseek(archivo,aux.s_block_start+(64*aux2.i_block[i]),SEEK_SET);
                    fread(&contenido,64,1,archivo);
                    rep += "|{" + to_string(siguienteI)+"| Archivo"+"|"+nombre+"}";
                    cout<<rep<<endl;
                    cout <<"------------------------aqui-------------------------------"<<endl;
                }
            }
        }else {
            break;
        }
    }
    return rep;
}