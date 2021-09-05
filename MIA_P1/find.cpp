
#include "find.h"
#include "mkdir.h"
#include "mount.h"
#include <vector>

string find::buscar(int uno, int varios, string path, string name, string id)
{
    vector<string> f;
    if (uno == 1 || varios == 1){
        name = "." + name;
    }

    listMounted particion;
    particion = mount::recorrerLista(id);
    FILE *archivo;
    archivo = fopen(particion.path.c_str(), "rb");
    int contador = 0;
    if (path != "/")
    {
        f = mkdir::split(path,'/');
        contador = f.size();
    }

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
    int apuntador = 0;
    vector<string> reporte;

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
                            encontrado = true;
                            siguienteI = aux3.b_content[k].b_inodo;
                            break;
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
            else{
                break;
            }
        }
    }

    buscarTodo(particion.path,uno,varios,siguienteI,inicioP,name,archivo);
    fclose(archivo);
}
vector <string> reporte;
void find::buscarTodo(string dire, int uno, int varios, int siguienteI, int inicioP, string sufijo,FILE *archivo)
{

    SuperBloque aux;
    Inodo aux2;
    BloqueCarpetas aux3;
    fseek(archivo, inicioP, SEEK_SET);
    fread(&aux, sizeof(SuperBloque), 1, archivo);
    fseek(archivo, aux.s_inode_start + (sizeof(Inodo) * siguienteI), SEEK_SET);
    fread(&aux2, sizeof(Inodo), 1, archivo);
    for (int i = 0; i < 15; i++)
    {
        if (aux2.i_block[i] != -1)
        {
            if (i < 12)
            {
                fseek(archivo, aux.s_block_start + (64 * aux2.i_block[i]), SEEK_SET);
                fread(&aux3, 64, 1, archivo);
                for (int j = 0; j < 4; j++)
                {
                    if (aux3.b_content[j].b_inodo != -1)
                    {
                        string nombre(aux3.b_content[j].b_name);

                        if (verExtension(uno, varios, nombre, sufijo) == 1)
                        {
                            cout<<"Nombre archivo: "<< nombre<<endl;
                            reporte.push_back(nombre);
                        }else if(sufijo == aux3.b_content[j].b_name){
                            cout<<"Nombre carpeta: "<< nombre<<endl;
                            reporte.push_back(nombre);
                        }
                        else
                        {
                            if(j >= 2){
                                if(aux2.i_block[i] != -1){
                                    Inodo siguiente;
                                    fseek(archivo, aux.s_inode_start + (sizeof(Inodo) * aux3.b_content[j].b_inodo), SEEK_SET);
                                    fread(&siguiente, sizeof(Inodo), 1, archivo);
                                    if (siguiente.i_type == '0')
                                    {
                                        buscarTodo(dire, uno, varios,aux3.b_content[j].b_inodo, inicioP, sufijo,archivo);
                                    }
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

int find::verExtension(int uno, int varios, string nombre, string sufijo)
{
    if (uno == 1 && varios == 0)
    {
        int tamanio = nombre.length() - sufijo.length();
        if (tamanio == 1)
        {
            if (nombre == "" || sufijo == "")
            {
                return 0;
            }

            size_t str_ = strlen(nombre.c_str());
            size_t suf_ = strlen(sufijo.c_str());

            if (suf_ > str_)
            {
                return 0;
            }

            return 0 == strncmp(nombre.c_str() + str_ - suf_, sufijo.c_str(), suf_);
        }
        else
        {
            return 0;
        }
    }
    else
    {
        if (nombre == "" || sufijo == "")
        {
            return 0;
        }

        size_t str_ = strlen(nombre.c_str());
        size_t suf_ = strlen(sufijo.c_str());

        if (suf_ > str_)
        {
            return 0;
        }

        return 0 == strncmp(nombre.c_str() + str_ - suf_, sufijo.c_str(), suf_);
    }
}