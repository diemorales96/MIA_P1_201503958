#include "arbol.h"
#include "mount.h"
void arbol::Reporte(string id, string path, string inicio)
{
    vector<string> ruta;
    listMounted particion;
    particion = mount::recorrerLista(id);
    //Mkdir::Separar(path, ruta);
    FILE *archivo;
    string rep;
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
    //int n = 0;
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
    //n = (tam_P - sizeof(S_bloque)) / (4 + sizeof(TInodos) + 3 * 64);
    SuperBloque aux;
    Inodo aux2;
    BloqueCarpetas aux3;
    fseek(archivo, inicioP, SEEK_SET);
    fread(&aux, sizeof(aux), 1, archivo);

    fseek(archivo, aux.s_inode_start, SEEK_SET);
    fread(&aux2, sizeof(Inodo), 1, archivo);
    bool encontrado = false;
    int siguienteI = 0;
    int actual = 0;
    int padre = 0;
    int apuntador = 0;
    for (int i = 0; i < contador; i++)
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
            else
            {
                break;
            }
        }
    }
    rep = buscarTodo(siguienteI, inicioP, archivo, rep,"");
}

string arbol::buscarTodo(int siguienteI, int inicioP, FILE *archivo, string repo,string anterior)
{
    SuperBloque aux;
    Inodo aux2;
    BloqueCarpetas aux3;
    fseek(archivo, inicioP, SEEK_SET);
    fread(&aux, sizeof(SuperBloque), 1, archivo);
    fseek(archivo, aux.s_inode_start + (sizeof(Inodo) * siguienteI), SEEK_SET);
    fread(&aux2, sizeof(Inodo), 1, archivo);
    repo += bInodos(aux2, siguienteI)+"\n";
    if(anterior!=""){
        repo+=anterior+"->inode"+to_string(siguienteI);
        cout<<repo<<endl;
        cout<<"--------------------------------------------------------------------------------------------------"<<endl;
    }

    for (int i = 0; i < 15; i++)
    {

        if (aux2.i_block[i] != -1)
        {
            if (i < 12)
            {
                fseek(archivo, aux.s_block_start + (64 * aux2.i_block[i]), SEEK_SET);
                fread(&aux3, 64, 1, archivo);
                repo += bBloques(aux3, aux3.b_content[0].b_inodo, aux3.b_content[1].b_inodo, aux2.i_block[i]);
                repo += "inode" + to_string(aux3.b_content[0].b_inodo) + ":i" + to_string(i)+"->node"+to_string(aux2.i_block[i])+":b"+to_string(aux2.i_block[i]);
                //cout << repo << endl;
                for (int j = 0; j < 4; j++)
                {
                    if(j>=2){
                        if (aux3.b_content[j].b_inodo != -1)
                        {
                            Inodo nuevo;
                            fseek(archivo,aux.s_inode_start+(sizeof(Inodo)*aux3.b_content[j].b_inodo),SEEK_SET);
                            fread(&nuevo,sizeof(Inodo),1,archivo);
                            if(nuevo.i_type == '0'){
                                siguienteI = aux3.b_content[j].b_inodo;
                                string n="node"+to_string(aux2.i_block[i])+":bc"+to_string(aux2.i_block[i])+to_string(j);
                                buscarTodo(siguienteI,inicioP,archivo,repo,n);
                            }
                        }
                    }
                }
            }
        }else{
            break;
        }
    }
}

string arbol::bInodos(Inodo tabla, int inodo)
{
    string fecha(tabla.i_atime);
    string fecha2(tabla.i_ctime);
    string fecha3(tabla.i_mtime);
    string tipo(1,tabla.i_type);
    string repo = "";
    repo += "inode" + to_string(inodo) + "[label=\"Inodo" + to_string(inodo) + "|{i_uid|" + to_string(tabla.i_uid) + "}|{i_gid|" + to_string(tabla.i_gid) + "}|{i_size|" + to_string(tabla.i_size) + "}|{i_atime|" + fecha + "}|{i_ctime|" + fecha2 + "}|{i_mtime|" + fecha3 + "}|{i_perm|" + to_string(tabla.i_perm) + "}|{i_type|" + tipo + "}|";
    for (int i = 0; i < 15; i++)
    {
        if (tabla.i_block[i] != -1)
        {
            repo += "{i_block[" + to_string(i) + "]|<i" + to_string(i) + ">" + to_string(tabla.i_block[i]) + "}";
        }
        else
        {
            repo += "{i_block[" + to_string(i) + "]|" + to_string(tabla.i_block[i]) + "}";
        }
        if (i < 14)
        {
            repo += "|";
        }
    }
    repo += "\"]\n";

    return repo;
}
string arbol::bBloques(BloqueCarpetas bloque, int actual, int padre, int Nbloque)
{
    string repo = "";
    repo += "node" + to_string(Nbloque) + "[label=\"<b" + to_string(Nbloque) + "> Bloque Carpeta " + to_string(Nbloque) + "|";

    for (int i = 0; i < 4; i++)
    {

        repo += "{" + string(bloque.b_content[i].b_name) + "|<bc" + to_string(Nbloque)+ to_string(i)+ ">" + to_string(bloque.b_content[i].b_inodo) + "}";
        if (i < 3)
        {
            repo += "|";
        }
    }
    repo+= "\"]\n";
    return repo;
}