#include "mkdir.h"
#include "disco.h"
#include "mkfs.h"
#include "mount.h"
#include "login.h"


void mkdir::crearCarpeta(string path, string p, string Pname,string id)
{
    credenciales log;
    bool entrada = log.entro;
    listMounted particion;
    particion = mount::recorrerLista(id);
    int n = 0;
    char e = '/';
    FILE *archivo;
    archivo = fopen(particion.path.c_str(), "rb+");
    vector<string> f;
    f = split(path,e);
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
    //For para las palabras que forman la ruta
    int inodoaux = 0;
    for (int i = 1; i < contador; i++)
    {
        //For para los bloques de apuntadores de inodos
        int temporal = 0;
        if (encontrado == false && entra == true){
            archivo = fopen(particion.path.c_str(), "rb+");
            entra = false;
        }
        for (int j = 0; j < 15; j++)
        {

            if (aux2.i_block[j] != -1 )
            {
                /*if(aux2.i_block[j] == 0){ && temporal <= 0
                    temporal++;
                }*/
                if (j < 12)
                {

                    fseek(archivo, aux.s_block_start + (64 * aux2.i_block[j]), SEEK_SET);
                    fread(&aux3, 64, 1, archivo);
                    for (int k = 0; k < 4; k++)
                    {
                        if (aux3.b_content[k].b_name == f[i])
                        {
                            siguienteI = aux3.b_content[k].b_inodo;
                            encontrado = true;
                            break;
                        }
                    }
                    if (encontrado)
                    {
                        break;
                    }
                    actual = aux3.b_content[0].b_inodo;
                    padre = aux3.b_content[1].b_inodo;
                }
                else if (j == 12)
                {
                    BloqueApuntadores apuntador;
                    fseek(archivo, aux.s_block_start + (64 * aux2.i_block[j]), SEEK_SET);
                    fread(&apuntador, 64, 1, archivo);
                    for (int p = 0; p < 16; j++)
                    {
                        if (apuntador.b_pointers[p] != -1)
                        {
                            fseek(archivo, aux.s_block_start + (64 * apuntador.b_pointers[p]), SEEK_SET);
                            fread(&aux3, 64, 1, archivo);
                            for (int k = 0; k < 4; k++)
                            {
                                if (aux3.b_content[k].b_name == f[i])
                                {
                                    siguienteI = aux3.b_content[k].b_inodo;
                                    encontrado = true;
                                    break;
                                }
                            }
                            if (encontrado)
                            {
                                break;
                            }

                        }
                    }
                }
            }else{
                break;
            }
        }
        // /home/usr/prueba/archivos/ar.txt
        if (encontrado)
        {
            fseek(archivo, aux.s_inode_start + (sizeof(Inodo) * siguienteI), SEEK_SET);
            fread(&aux2, sizeof(Inodo), 1, archivo);
            encontrado = false;
        }
        else if (!encontrado && (i + 1) != contador  && p != "p")
        {
            cout << "No se encontro la ruta indicada y no es posible crear la ruta entera por la falta del parametro \"p\"" << endl;
            cout << "No fue posible crear la carpeta" << endl;
            return;
        }
        else
        {
            bool Creado = false;
            fseek(archivo, aux.s_inode_start + (sizeof(Inodo) * actual), SEEK_SET);
            fread(&aux2, sizeof(Inodo), 1, archivo);

            for (int j = 0; j < 15; j++)
            {
                if (j < 12)
                {

                    if (aux2.i_block[j] != -1 )
                    {

                        fseek(archivo, aux.s_block_start + (64 * aux2.i_block[j]), SEEK_SET);
                        fread(&aux3,64, 1, archivo);
                        for (int k = 0; k < 4; k++)
                        {
                            if (aux3.b_content[k].b_inodo == -1)
                            { //Se crea nuevo bloque de carpetas y nuevo inodo

                                BloqueCarpetas nuevaC;
                                Inodo nuevaT;
                                //Arreglos para los bitmap
                                char Bmi[n];
                                char Bmb[3 * n];
                                //Obtengo los arreglos de bitmap guardados en el disco
                                fseek(archivo, aux.s_bm_inode_start, SEEK_SET);
                                fread(&Bmi, sizeof(Bmi), 1, archivo);
                                fseek(archivo, aux.s_bm_block_start, SEEK_SET);
                                fread(&Bmb, sizeof(Bmb), 1, archivo);
                                //Actualizo los bitmap
                                //actBI(Bmi, n, 1);
                                //actBI(Bmb, 3 * n, 1);
                                nuevaT = CInodo(fechaActual, aux.s_blocks_count + 1,'0');
                                nuevaC = CbloqueC(aux.s_inodes_count + 1, actual);
                                strcpy(aux3.b_content[k].b_name, f[i].c_str());
                                aux3.b_content[k].b_inodo = aux.s_inodes_count + 1;

                                fseek(archivo, aux.s_inode_start + (sizeof(Inodo) * (aux.s_inodes_count + 1)), SEEK_SET);
                                fwrite(&nuevaT, sizeof(Inodo), 1, archivo);
                                fseek(archivo, aux.s_block_start + (64 * (aux.s_blocks_count + 1)), SEEK_SET);
                                fwrite(&nuevaC, 64, 1, archivo);

                                //fseek(archivo, aux.s_bm_inode_start, SEEK_SET);
                                //fwrite(&Bmi, sizeof(Bmi), 1, archivo);
                                //fseek(archivo, aux.s_bm_block_start, SEEK_SET);
                                //fwrite(&Bmb, sizeof(Bmb), 1, archivo);
                                fseek(archivo,aux.s_block_start+(64*aux2.i_block[j]),SEEK_SET);
                                fwrite(&aux3,64,1,archivo);

                                aux.s_inodes_count++;
                                aux.s_blocks_count++;
                                aux.s_free_inodes_count--;
                                aux.s_free_blocks_count--;
                                fseek(archivo,inicioP,SEEK_SET);
                                fwrite(&aux,sizeof(SuperBloque),1,archivo);
                                cout << "Carpeta creada correctamente" << endl;
                                fclose(archivo);
                                Creado = true;
                                entra = true;
                                break;
                            }
                        }
                    }
                    else
                    { //Creo Inodo,bloque de carpetas y otro bloque de carpetas
                        aux2.i_block[j] = aux.s_blocks_count + 1;
                        BloqueCarpetas nuevaC;
                        BloqueCarpetas nuevaC2;
                        Inodo nuevaT;
                        //char Bmi[n];
                        //char Bmb[3 * n];
                        //Obtengo los arreglos de bitmap guardados en el disco
                        //fseek(archivo, aux.s_bm_inode_start, SEEK_SET);
                        //fread(&Bmi, sizeof(Bmi), 1, archivo);
                        //fseek(archivo, aux.s_bm_block_start, SEEK_SET);
                        //fread(&Bmb, sizeof(Bmb), 1, archivo);
                        //Actualizo los bitmap
                        //actBI(Bmi, n, 1);
                        //actBI(Bmb, 3 * n, 2);
                        //Bloque de carpetas saliente del inodo revisado
                        nuevaC = CbloqueC(actual, padre);
                        //Bloque de carpetas saliente del nuevo inodo
                        nuevaC2 = CbloqueC(aux.s_inodes_count + 1, actual);
                        nuevaC.b_content[2].b_inodo = aux.s_inodes_count + 1;
                        strcpy(nuevaC.b_content[2].b_name, f[i].c_str());
                        nuevaT = CInodo(fechaActual, aux.s_blocks_count + 2,'0');
                        fseek(archivo, aux.s_inode_start + (sizeof(Inodo) * (aux.s_inodes_count + 1)), SEEK_SET);

                        fwrite(&nuevaT, sizeof(Inodo), 1, archivo);
                        fseek(archivo, aux.s_block_start + (64 * (aux.s_blocks_count + 1)), SEEK_SET);
                        fwrite(&nuevaC, 64, 1, archivo);
                        fseek(archivo, aux.s_block_start + (64 * (aux.s_blocks_count + 2)), SEEK_SET);
                        fwrite(&nuevaC2, 64, 1, archivo);
                        //fseek(archivo, aux.s_bm_inode_start, SEEK_SET);
                        //fwrite(&Bmi, sizeof(Bmi), 1, archivo);
                        //fseek(archivo, aux.s_bm_block_start, SEEK_SET);
                        //fwrite(&Bmb, sizeof(Bmb), 1, archivo);

                        fseek(archivo,aux.s_inode_start + (sizeof(Inodo)*actual),SEEK_SET);
                        fwrite(&aux2,sizeof(Inodo),1,archivo);
                        aux.s_inodes_count++;
                        aux.s_blocks_count++;
                        aux.s_blocks_count++;
                        aux.s_free_blocks_count--;
                        aux.s_free_blocks_count--;
                        aux.s_free_inodes_count--;
                        fseek(archivo,inicioP,SEEK_SET);
                        fwrite(&aux,sizeof(SuperBloque),1,archivo);
                        cout << "La carpeta fue creada con exito" << endl;
                        fclose(archivo);
                        Creado = true;
                        entra = true;
                    }
                    if(Creado == true){
                        break;
                    }
                }
                else if (j == 12)
                {
                    if (aux2.i_block[j] != -1)
                    {
                        BloqueApuntadores apuntador;
                        fseek(archivo, aux.s_block_start + (64 * aux2.i_block[j]), SEEK_SET);
                        fread(&apuntador, 64, 1, archivo);
                        for (int k = 0; k < 16; k++)
                        {
                            if (apuntador.b_pointers[k] == -1)
                            {
                                apuntador.b_pointers[k] = aux.s_blocks_count + 1;
                                BloqueCarpetas nuevaC;
                                BloqueCarpetas nuevaC2;
                                Inodo nuevaT;
                                char Bmi[n];
                                char Bmb[3 * n];
                                //Obtengo los arreglos de bitmap guardados en el disco
                                fseek(archivo, aux.s_bm_inode_start, SEEK_SET);
                                fread(&Bmi, sizeof(Bmi), 1, archivo);
                                fseek(archivo, aux.s_bm_block_start, SEEK_SET);
                                fread(&Bmb, sizeof(Bmb), 1, archivo);
                                //Actualizo los bitmap
                                actBI(Bmi, n, 1);
                                actBI(Bmb, 3 * n, 2);
                                //Bloque de carpetas saliente del bloque de apuntadores
                                nuevaC = CbloqueC(aux2.i_block[j], -1);
                                strcpy(nuevaC.b_content[0].b_name,f[i].c_str());
                                //Bloque de carpetas saliente del nuevo inodo
                                nuevaC2 = CbloqueC(aux.s_inodes_count + 1, actual);
                                nuevaT = CInodo(fechaActual, aux.s_blocks_count + 2,'0');
                                fseek(archivo, aux.s_inode_start + (sizeof(Inodo) * (aux.s_inodes_count + 1)), SEEK_SET);
                                fwrite(&nuevaT, sizeof(Inodo), 1, archivo);
                                fseek(archivo, aux.s_block_start + (64 * (aux.s_blocks_count + 1)), SEEK_SET);
                                fwrite(&nuevaC, 64, 1, archivo);
                                fseek(archivo, aux.s_block_start + (64 * (aux.s_blocks_count + 2)), SEEK_SET);
                                fwrite(&nuevaC2, 64, 1, archivo);
                                //fseek(archivo, aux.s_bm_inode_start, SEEK_SET);
                                //fwrite(&Bmi, sizeof(Bmi), 1, archivo);
                                //fseek(archivo, aux.s_bm_block_start, SEEK_SET);
                                //fwrite(&Bmb, sizeof(Bmb), 1, archivo);
                                fseek(archivo,aux.s_block_start+(64*aux.s_blocks_count),SEEK_SET);
                                fwrite(&apuntador,64,1,archivo);
                                aux.s_inodes_count++;
                                aux.s_blocks_count++;
                                aux.s_blocks_count++;
                                aux.s_free_blocks_count--;
                                aux.s_free_blocks_count--;
                                aux.s_free_inodes_count--;
                                fseek(archivo,inicioP,SEEK_SET);
                                fwrite(&aux,sizeof(SuperBloque),1,archivo);
                                cout << "La carpeta fue creada con exito" << endl;
                                fclose(archivo);
                                Creado = true;
                                entra = true;
                                break;
                            }
                        }
                    }else{
                        aux2.i_block[j] = aux.s_blocks_count + 1;
                        BloqueApuntadores nuevoAp;
                        nuevoAp = Capunt();
                        nuevoAp.b_pointers[0] = aux.s_blocks_count + 2;
                        BloqueCarpetas nuevaC;
                        nuevaC = CbloqueC(-1, -1);
                        nuevaC.b_content[0].b_inodo = aux.s_inodes_count + 1;
                        strcpy(nuevaC.b_content[0].b_name, f[i].c_str());
                        BloqueCarpetas nuevaC2;
                        nuevaC2 = CbloqueC(aux.s_inodes_count + 1, actual);
                        Inodo nuevaT;
                        nuevaT = CInodo(fechaActual, aux.s_blocks_count + 3,'0');
                        fseek(archivo, aux.s_inode_start + (sizeof(Inodo) * (aux.s_inodes_count + 1)), SEEK_SET);
                        fwrite(&nuevaT, sizeof(Inodo), 1, archivo);
                        fseek(archivo, aux.s_block_start + (64 * (aux.s_blocks_count + 1)), SEEK_SET);
                        fwrite(&nuevoAp, 64, 1, archivo);
                        fseek(archivo, aux.s_block_start + (64 * (aux.s_blocks_count + 2)), SEEK_SET);
                        fwrite(&nuevaC, 64, 1, archivo);
                        fseek(archivo, aux.s_block_start + (64 * (aux.s_blocks_count + 3)), SEEK_SET);
                        fwrite(&nuevaC2, 64, 1, archivo);
                        fseek(archivo,aux.s_inode_start + (sizeof(Inodo)*actual),SEEK_SET);
                        fwrite(&aux2,sizeof(Inodo),1,archivo);
                        aux.s_inodes_count++;
                        aux.s_blocks_count++;
                        aux.s_blocks_count++;
                        aux.s_blocks_count++;
                        aux.s_free_blocks_count--;
                        aux.s_free_blocks_count--;
                        aux.s_free_blocks_count--;
                        aux.s_free_inodes_count--;
                        fseek(archivo,inicioP,SEEK_SET);
                        fwrite(&aux,sizeof(SuperBloque),1,archivo);
                        cout << "La carpeta fue creada con exito" << endl;
                        fclose(archivo);
                        Creado = true;
                        entra = true;
                    }
                }
            }
        }
    }
}

/*string mkdir::Separar(string path, int *content)
{
    string palabras[100];
    char *point;
    int *cont = 0;
    char cortado[path.length()];
    strcpy(cortado,path.c_str());
    point = strtok(cortado, "/");
    while (point != NULL)
    {
        palabras[cont] = point;
        cont++;
        point = strtok(NULL, "/");
    }
    content = cont;
    return palabras;
}*/

vector<string> mkdir::split(string str, char pattern)
{

    int posInit = 0;
    int posFound = 0;
    string splitted;
    vector<string> resultados;

    while (posFound >= 0)
    {
        posFound = str.find(pattern, posInit);
        splitted = str.substr(posInit, posFound - posInit);
        posInit = posFound + 1;
        resultados.push_back(splitted);
    }

    return resultados;
}

BloqueCarpetas mkdir::CbloqueC(int actual, int padre)
{
    BloqueCarpetas nuevaC;
    if (padre != -1)
    {
        nuevaC.b_content[0].b_inodo = actual;
        strcpy(nuevaC.b_content[0].b_name, ".");
        nuevaC.b_content[1].b_inodo = padre;
        strcpy(nuevaC.b_content[1].b_name, "..");
        nuevaC.b_content[2].b_inodo = -1;
        strcpy(nuevaC.b_content[2].b_name, "--");
        nuevaC.b_content[3].b_inodo = -1;
        strcpy(nuevaC.b_content[3].b_name, "--");
        return nuevaC;
    }
    else
    {
        nuevaC.b_content[0].b_inodo = actual;
        strcpy(nuevaC.b_content[0].b_name, "--");
        nuevaC.b_content[1].b_inodo = padre;
        strcpy(nuevaC.b_content[1].b_name, "..");
        nuevaC.b_content[2].b_inodo = -1;
        strcpy(nuevaC.b_content[2].b_name, "--");
        nuevaC.b_content[3].b_inodo = -1;
        strcpy(nuevaC.b_content[3].b_name, "--");
        return nuevaC;
    }
}

Inodo mkdir::CInodo(char fechaActual[], int bloque,char tipo)
{
    Inodo tablainodos;

    tablainodos.i_uid = 1;
    tablainodos.i_gid = 1;
    tablainodos.i_size = 0;
    strcpy(tablainodos.i_atime, fechaActual);
    strcpy(tablainodos.i_ctime, fechaActual);
    strcpy(tablainodos.i_mtime, fechaActual);
    for (int i = 0; i < 15; i++)
    {
        tablainodos.i_block[i] = -1;
    }
    tablainodos.i_block[0] = bloque;

    tablainodos.i_type = tipo;
    tablainodos.i_perm = 664;
    return tablainodos;
}

void mkdir::actBI(char *bm, int n, int veces)
{
    if (veces == 1)
    {
        for (int i = 0; i < n; i++)
        {
            if (bm[i] == '0')
            {
                bm[i] = '1';
                break;
            }
        }
    }
    else
    {
        for (int i = 0; i < veces; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (bm[i] == '0')
                {
                    bm[i] = '1';
                    break;
                }
            }
        }
    }
}

BloqueApuntadores mkdir::Capunt()
{
    BloqueApuntadores apuntador;
    for (int i = 0; i < 16; i++)
    {
        apuntador.b_pointers[i] = -1;
    }
    return apuntador;
}