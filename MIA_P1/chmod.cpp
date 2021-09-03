#include "chmod.h"
#include "mount.h"
void chmod::cambiarP(string path, string p, string UGO, string id)
{
    vector<string> f;
    f = mkdir::split(path,'/');
    listMounted particion;
    particion = mount::recorrerLista(id);
    FILE *archivo;
    archivo = fopen(particion.path.c_str(), "rb+");
    int contador = f.size();
    MBR mbr;
    rewind(archivo);
    fread(&mbr, sizeof(mbr), 1, archivo);
    int inicioP = 0;
    int tam_P = 0;
    string nombre;
    for (int i = 0; i < particion.listMountedPartitions.size(); i++)
    {
        if (particion.listMountedPartitions[i].idPart == id)
        {
            nombre = particion.listMountedPartitions[i].nombrePart;
            break;
        }
    }

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

    fseek(archivo, aux.s_inode_start, SEEK_SET);
    fread(&aux2, sizeof(Inodo), 1, archivo);
    bool encontrado = false;
    int siguienteI = 0;
    int actual = 0;
    int padre = 0;
    int apuntador = 0;
    for (int i = 1; i < contador; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            if (aux2.i_block[j] != -1)
            {
                if (j < 12)
                {
                    fseek(archivo, aux.s_block_start + (sizeof(BloqueCarpetas) * aux2.i_block[j]), SEEK_SET);
                    fread(&aux3, sizeof(BloqueCarpetas), 1, archivo);
                    for (int k = 0; k < 4; k++)
                    {
                        if (aux3.b_content[k].b_name == f[i])
                        {
                            encontrado = true;
                            siguienteI = aux3.b_content[k].b_inodo;
                            if (p != "")
                            {
                                //Cambio los permisos de este inodo
                            }

                            break;
                        }
                        if (encontrado)
                        {
                            if (i + 1 == contador)
                            {
                                aux2.i_perm=atoi(UGO.c_str());
                                strcpy(aux2.i_mtime,fechaActual);
                                fseek(archivo,aux.s_inode_start+(sizeof(Inodo)*siguienteI),SEEK_SET);
                                fwrite(&aux2,sizeof(Inodo),1,archivo);
                                fseek(archivo,aux.s_inode_start+(sizeof(Inodo)*siguienteI),SEEK_SET);
                                fread(&aux2, sizeof(Inodo), 1, archivo);
                                break;
                            }
                            fseek(archivo, aux.s_inode_start + (sizeof(Inodo) * siguienteI), SEEK_SET);
                            fread(&aux2, sizeof(Inodo), 1, archivo);
                            break;
                        }
                    }
                }
            }else{
                break;
            }
        }
    }
    fclose(archivo);
}