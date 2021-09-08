#include "edit.h"
#include <vector>
#include "mount.h"
#include "mkdir.h"
#include "touch.h"
void edit::editar(string path, string cont, int Stdin, string id, bool acceso) {

    if(acceso == false){
        cout<<"Usuario no logeado"<<endl;
        return;
    }

    listMounted particion;
    particion = mount::recorrerLista(id);

    if(particion.id == 500){
        cout<<"Particion no montada"<<endl;
        return;
    }

    string contenido2 ="";
    if(cont!=""){
        FILE* arch;
        arch=fopen(cont.c_str(),"r");
        fseek(arch,0,SEEK_END);
        vector<string> f;
        f = mkdir::split(path,'/');
        int tamanio = 0;
        tamanio=ftell(arch);
        rewind(arch);
        char* contenido;
        contenido=(char*)malloc(sizeof(char)*tamanio);
        fread(contenido,1,tamanio,arch);
        string con(contenido);
        cout<< con <<endl;
        contenido2=con;
    }else if(Stdin == 1){
        cout<<"Ingrese texto: "<<endl;
        getline(cin,contenido2);
    }
    int n = 0;
    char e = '/';
    FILE *archivo;
    archivo = fopen(particion.path.c_str(), "rb+");
    vector<string> f;
    f = mkdir::split(path,e);
    int contador = f.size();
    MBR mbr;
    rewind(archivo);
    fread(&mbr, sizeof(mbr), 1, archivo);
    int inicioP = 0;
    int tam_P = 0;
    string nombre;
    nombre = particion.listMountedPartitions[0].nombrePart;


    for (int i = 0; i < 4; i++)
    {
        if (mbr.mbr_partition[i].part_name == nombre)
        {
            inicioP = mbr.mbr_partition[i].part_start;
            tam_P = mbr.mbr_partition[i].part_start;
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
    int apuntador=0;
    bool entra = false;
    int inodoaux = 0;
    int x = 0;
    int referencia;

    for (int i = 1; i < contador; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            if (aux2.i_block[j] != -1 )
            {
                if (j < 12)
                {
                    fseek(archivo, aux.s_block_start + (64 * aux2.i_block[j]), SEEK_SET);
                    fread(&aux3, 64, 1, archivo);
                    for (int k = 0; k < 4; k++)
                    {
                        if(aux3.b_content[k].b_name == f[i]){
                            encontrado = true;
                            x = k;
                            if(i+1 == contador){
                                referencia =aux3.b_content[k].b_inodo;

                            }
                        }
                    }
                    if(encontrado){
                        fseek(archivo, aux.s_inode_start + (sizeof(Inodo)*aux3.b_content[x].b_inodo), SEEK_SET);
                        fread(&aux2, sizeof(Inodo), 1, archivo);
                        if(i+1 != contador){
                            encontrado = false;
                        }
                        break;
                    }
                }
            }
        }

    }
    if(encontrado){
        fseek(archivo, aux.s_inode_start + (sizeof(Inodo)*referencia), SEEK_SET);
        fread(&aux2, sizeof(Inodo), 1, archivo);
        listaChar NuevoC;
        NuevoC = touch::CbloqueC(contenido2);
        for(int i = 0; i<15;i++){
            if(aux2.i_block[i] == -1){
                for(int s = 0; s < NuevoC.contenido.size();s++){
                    aux.s_blocks_count++;
                    fseek(archivo,aux.s_block_start +(64*(aux.s_blocks_count)),SEEK_SET);
                    fwrite(&NuevoC.contenido[s],64,1,archivo);
                    aux2.i_block[i] = aux.s_blocks_count ;
                    aux.s_free_blocks_count--;
                    if(s<NuevoC.contenido.size()){
                        i++;
                    }
                }
                break;
            }
        }
    }
    fseek(archivo, aux.s_inode_start + (sizeof(Inodo)*referencia), SEEK_SET);
    fwrite(&aux2,sizeof(Inodo),1,archivo);
    fseek(archivo, inicioP, SEEK_SET);
    fwrite(&aux, sizeof(SuperBloque), 1, archivo);
    fclose(archivo);
}