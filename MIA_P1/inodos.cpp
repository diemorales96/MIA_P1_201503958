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
    string grafo;
    rep = buscarTodo(0,inicioP,archivo,rep,"/");
    string cc = "dot -Tpng archivoDot1.dot -o " ;
    cc += path;
    grafo = "digraph MBR{\n";
    grafo += "  nodesep=.05\n";
    grafo += "rankdir=LR\n";
    grafo += "node [shape=record,width=.1,height=.1]\n";
    grafo += "Nodo0 [label = \"INODOS";
    grafo += rep+"\"]\n";
    grafo += "}";
    //cout<<grafo<<endl;
    //cout<<"-------------------aqui-----------";
    char ru[500];
    strcpy(ru, cc.c_str());
    //cout << "ru: " << ru << endl;

    ofstream file;
    file.open("archivoDot1.dot");
    file << grafo;
    file.close();
    system(ru);

    string ccc ="nohup display ";
    ccc+= path;
    ccc+= " &";

    char rut[500];
    strcpy(rut, ccc.c_str());
    //cout << ccc << endl;
    string q(rut);
    string comando = "eog " + q;
    const char *cmd2 = comando.c_str();
    system(cmd2);
    fclose(archivo);
    getchar();
}

bool bandera2 = false;

string inodos::buscarTodo( int siguienteI, int inicioP,FILE* archivo,string rep,string nombre)
{

    SuperBloque aux;
    Inodo aux2;
    BloqueCarpetas aux3;
    bool bandera = false;
    fseek(archivo, inicioP, SEEK_SET);
    fread(&aux, sizeof(SuperBloque), 1, archivo);
    fseek(archivo, aux.s_inode_start + (sizeof(Inodo) * siguienteI), SEEK_SET);
    fread(&aux2, sizeof(Inodo), 1, archivo);

    for (int i = 0; i < 15; i++)
    {
        if (aux2.i_block[i] != -1)
        {
            //rep += "|{" + to_string(aux2.i_block[i])+"| Folder"+"|"+nombre+"}";
            if (i < 12)
            {
                fseek(archivo, aux.s_block_start + (64 * aux2.i_block[i]), SEEK_SET);
                fread(&aux3, 64, 1, archivo);
                for (int j = 0; j < 4; j++)
                {
                    if(j>=2){
                        if (aux3.b_content[j].b_inodo != -1)
                        {
                            if(!bandera2){
                                rep += "|{" + to_string(aux2.i_block[i])+"| Folder"+"|"+nombre+"}";
                                bandera2 = true;
                            }
                            siguienteI = aux3.b_content[j].b_inodo;
                            Inodo nodoAux;
                            fseek(archivo, aux.s_inode_start + (sizeof(Inodo) * siguienteI), SEEK_SET);
                            fread(&nodoAux, sizeof(Inodo), 1, archivo);
                            if(nodoAux.i_type == '0'){
                                rep += "|{" + to_string(aux3.b_content[j].b_inodo)+"| Folder"+"|"+ string(aux3.b_content[j].b_name)+"}";
                                rep = buscarTodo(siguienteI,inicioP,archivo,rep,aux3.b_content[j].b_name);
                            }else{
                                rep += "|{" + to_string(aux3.b_content[j].b_inodo)+"| Archivo"+"|"+ string(aux3.b_content[j].b_name)+"}";
                            }

                            //cout<<rep<<endl;
                            //cout <<"------------------------aqui-------------------------------"<<endl;

                            if(j+1 < 4 && aux3.b_content[j+1].b_inodo != -1){
                                siguienteI = aux3.b_content[j+1].b_inodo;
                                nombre = aux3.b_content[j+1].b_name;
                            }
                        }
                    }
                }

            }
        }else {
            break;
        }
    }
    return rep;
}