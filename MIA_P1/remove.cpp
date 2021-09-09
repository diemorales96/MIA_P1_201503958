#include "remove.h"
#include "mount.h"
int inodos=0;
int bloques=0;
void remove::buscar(string path, string id,bool aceptado)
{
    if(!aceptado){
        cout<<"Usuario No Logeado"<<endl;
        return;
    }
    vector<string> ruta;
    listMounted particion;
    particion = mount::recorrerLista(id);
    //Mkdir::Separar(path, ruta);
    FILE *archivo;
    archivo = fopen(particion.path.c_str(), "rb+");
    int contador = 0;
    if (path != "/")
    {
        ruta = mkdir::split(path,'/');
    }
    contador = ruta.size();

    //string name = ruta[contador - 1];
    MBR mbr;
    rewind(archivo);
    fread(&mbr, sizeof(mbr), 1, archivo);
    int inicioP = 0;
    int tam_P = 0;
    string nombre;
    int n = 0;
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
    int v = 0;
    int apuntador = 0;
    for (int i = 1; i < contador; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            if (aux2.i_block[j] != -1)
            {
                if (j < 12)
                {
                    fseek(archivo, aux.s_block_start + (64 * aux2.i_block[j]), SEEK_SET);
                    fread(&aux3, 64, 1, archivo);
                    for (int k = 0; k < 4; k++)
                    {
                        if (aux3.b_content[k].b_inodo != -1)
                        {
                            if(aux3.b_content[k].b_name == ruta[i]){
                                encontrado = true;
                                v = k;
                                actual = j;
                                siguienteI = aux3.b_content[k].b_inodo;
                                break;
                            }
                        }
                    }
                    if (encontrado)
                    {
                        fseek(archivo, aux.s_inode_start + (sizeof(Inodo) * siguienteI), SEEK_SET);
                        fread(&aux2, sizeof(Inodo), 1, archivo);
                        break;
                    }
                }
            }
            else
            {
                break;
            }
        }
    }
    if(encontrado) {
        inodos++;
        buscarTodo(siguienteI, inicioP, archivo);
        aux3.b_content[v].b_inodo=-1;
        strcpy(aux3.b_content[v].b_name,"--");
        aux.s_blocks_count=aux.s_blocks_count-bloques;
        aux.s_free_blocks_count=aux.s_free_blocks_count+bloques;
        aux.s_inodes_count=aux.s_inodes_count-inodos;
        aux.s_free_inodes_count=aux.s_free_inodes_count+inodos;
        fseek(archivo, aux.s_block_start+(64*actual), SEEK_SET);
        fwrite(&aux3,64,1,archivo);
        fseek(archivo,inicioP,SEEK_SET);
        fwrite(&aux,sizeof (SuperBloque),1,archivo);
        fclose(archivo);
        cout<<"Elemento eliminado con exito"<<endl;
    }else{
        cout<<"NO se encontro la carpeta de inicio"<<endl;
        return;
    }

}
void remove::buscarTodo(int siguienteI, int inicioP, FILE *archivo)
{
    SuperBloque aux;
    Inodo aux2;
    BloqueCarpetas aux3;
    fseek(archivo, inicioP, SEEK_SET);
    fread(&aux, sizeof(SuperBloque), 1, archivo);
    fseek(archivo, aux.s_inode_start + (sizeof(Inodo) * siguienteI), SEEK_SET);
    fread(&aux2, sizeof(Inodo), 1, archivo);
    inodos++;
    for (int i = 0; i < 15; i++)
    {
        if (aux2.i_block[i] != -1)
        {
            bloques++;
            if(aux2.i_type == '0'){
                if (i < 12)
                {
                    fseek(archivo, aux.s_block_start + (64 * aux2.i_block[i]), SEEK_SET);
                    fread(&aux3, 64, 1, archivo);
                    for (int j = 0; j < 4; j++)
                    {
                        if (aux3.b_content[j].b_inodo != -1)
                        {
                            string nombre(aux3.b_content[j].b_name);


                            if (j >= 2)
                            {
                                if (aux2.i_block[i] != -1)
                                {
                                    Inodo siguiente;
                                    fseek(archivo, aux.s_inode_start + (sizeof(Inodo) * aux3.b_content[j].b_inodo), SEEK_SET);
                                    fread(&siguiente, sizeof(Inodo), 1, archivo);
                                    buscarTodo(aux3.b_content[j].b_inodo, inicioP,archivo);
                                }
                            }

                        }
                    }
                }
            }
        }
        else
        {
            break;
        }
    }
}