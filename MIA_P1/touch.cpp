#include "touch.h"
#include "disco.h"
#include "mkfs.h"
#include "mount.h"

void touch::crearArchivo(string path, string r, string Pname, string cont, int Stdin, string size,bool entra)
{
    if(!entra){
        cout<<"Usuario No logeado"<<endl;
    }
    int n = 0;
    string contenido2;
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

    listMounted particion;
    particion = mount::recorrerLista(Pname);
    //Mkdir::Separar(path, ruta);
    FILE *archivo;
    archivo = fopen(particion.path.c_str(), "rb+");
    vector<string> f;
    f = mkdir::split(path,'/');
    int contador = f.size();
    //string name = ruta[contador - 1];
    MBR mbr;
    rewind(archivo);
    fread(&mbr, sizeof(mbr), 1, archivo);
    int inicioP = 0;
    int tam_P = 0;
    string nombre;
    for (int i = 0; i < particion.listMountedPartitions.size(); i++)
    {
        if (particion.listMountedPartitions[i].idPart == Pname)
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
    bool creado = false;
    //For para las palabras que forman la ruta
    for (int i = 1; i < contador; i++)
    {
        //FOr para los bloques de apuntadores de inodos
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
                        string nombreArchivo(aux3.b_content[k].b_name);

                        if (nombreArchivo == f[i])
                        {
                            BloqueArchivos archivito;
                            fseek(archivo, aux.s_inode_start+(sizeof(Inodo)*aux3.b_content[k].b_inodo), SEEK_SET);
                            fread(&aux2, sizeof(Inodo), 1, archivo);
                            fseek(archivo, aux.s_block_start + (64* aux2.i_block[0]), SEEK_SET);
                            fread(&archivito, 64, 1, archivo);
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
                    for (int j = 0; j < 16; j++)
                    {
                        if (apuntador.b_pointers[j] != -1)
                        {
                            fseek(archivo, aux.s_block_start + (64 * apuntador.b_pointers[j]), SEEK_SET);
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
        if (encontrado)
        {
            fseek(archivo, aux.s_inode_start + (sizeof(Inodo) * siguienteI), SEEK_SET);
            fread(&aux2, sizeof(Inodo), 1, archivo);
            encontrado = false;
        }
        else if (!encontrado && (i + 1) != contador - 1 && r != "r")
        {
            cout << "No se encontro la ruta indicada y no es posible crear la ruta entera por la falta del parametro \"p\"" << endl;
            cout << "No fue posible crear la carpeta" << endl;
            return;
        }
        else
        {
            fseek(archivo, aux.s_inode_start + (sizeof(Inodo) * actual), SEEK_SET);
            fread(&aux2, sizeof(Inodo), 1, archivo);
            for (int j = 0; j < 15; j++)
            {
                if (j < 12)
                {
                    if (aux2.i_block[j] != -1)
                    {
                        fseek(archivo, aux.s_block_start + (64 * aux2.i_block[j]), SEEK_SET);
                        fread(&aux3, 64, 1, archivo);
                        for (int k = 0; k < 4; k++)
                        {
                            if (aux3.b_content[k].b_inodo == -1)
                            { //Se crea nuevo bloque de carpetas y nuevo inodo
                                listaChar nuevaC;
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
                                nuevaT = mkdir::CInodo(fechaActual, aux.s_blocks_count + 1,'1');
                                if(contenido2 != "") {
                                    nuevaC = CbloqueC(contenido2);
                                    for(int s = 0; s < nuevaC.contenido.size();s++){
                                        aux.s_blocks_count++;
                                        fseek(archivo,aux.s_block_start +(64*(aux.s_blocks_count)),SEEK_SET);
                                        fwrite(&nuevaC.contenido[s],64,1,archivo);
                                        aux.s_free_blocks_count--;
                                        nuevaT.i_block[s] = aux.s_blocks_count;
                                        /*if (s >= 1){

                                        }*/
                                    }
                                }else{
                                    BloqueArchivos nuevobloque;
                                    nuevaC.contenido.push_back(nuevobloque);
                                    fseek(archivo, aux.s_block_start + (64 * (aux.s_blocks_count + 1)), SEEK_SET);
                                    fwrite(&nuevaC.contenido[0], 64, 1, archivo);
                                    aux.s_blocks_count++;
                                    aux.s_free_blocks_count--;
                                }
                                strcpy(aux3.b_content[k].b_name, f[i].c_str());
                                aux3.b_content[k].b_inodo = aux.s_inodes_count + 1;
                                fseek(archivo, aux.s_inode_start + (sizeof(Inodo) * (aux.s_inodes_count + 1)), SEEK_SET);
                                fwrite(&nuevaT, sizeof(Inodo), 1, archivo);

                                fseek(archivo, aux.s_block_start +(64*aux2.i_block[j]), SEEK_SET);
                                fwrite(&aux3, 64, 1, archivo);

                                fseek(archivo, aux.s_bm_inode_start, SEEK_SET);
                                fwrite(&Bmi, sizeof(Bmi), 1, archivo);
                                fseek(archivo, aux.s_bm_block_start, SEEK_SET);
                                fwrite(&Bmb, sizeof(Bmb), 1, archivo);
                                aux.s_inodes_count++;
                                aux.s_free_inodes_count--;
                                fseek(archivo, inicioP, SEEK_SET);
                                fwrite(&aux, sizeof(SuperBloque), 1, archivo);
                                fclose(archivo);
                                cout << "Carpeta creada correctamente" << endl;
                                creado = true;
                                break;
                            }
                        }
                    }
                    else
                    { //Creo Inodo,bloque de carpetas y otro bloque de carpetas
                        if(aux2.i_type == '1'){
                            aux2.i_block[j] = aux.s_blocks_count + 1;
                            listaChar nuevaC;
                            char Bmi[n];
                            char Bmb[3 * n];
                            //Obtengo los arreglos de bitmap guardados en el disco
                            fseek(archivo, aux.s_bm_inode_start, SEEK_SET);
                            fread(&Bmi, sizeof(Bmi), 1, archivo);
                            fseek(archivo, aux.s_bm_block_start, SEEK_SET);
                            fread(&Bmb, sizeof(Bmb), 1, archivo);
                            //Actualizo los bitmap
                            //actBI(Bmi, n, 1);
                            //actBI(Bmb, 3 * n, 2);
                            //Bloque de carpetas saliente del inodo revisado
                            nuevaC = CbloqueC(contenido2);
                            //Bloque de carpetas saliente del nuevo inodo
                            fseek(archivo, aux.s_block_start + (64 * (aux.s_blocks_count + 1)), SEEK_SET);
                            fwrite(&nuevaC, 64, 1, archivo);
                            fseek(archivo, aux.s_bm_inode_start, SEEK_SET);
                            fwrite(&Bmi, sizeof(Bmi), 1, archivo);
                            fseek(archivo, aux.s_bm_block_start, SEEK_SET);
                            fwrite(&Bmb, sizeof(Bmb), 1, archivo);

                            fseek(archivo, aux.s_inode_start + (sizeof(Inodo) * aux2.i_block[j]), SEEK_SET);
                            fwrite(&aux2, sizeof(Inodo), 1, archivo);
                            aux.s_inodes_count++;
                            aux.s_blocks_count++;
                            aux.s_blocks_count++;
                            aux.s_free_blocks_count--;
                            aux.s_free_blocks_count--;
                            aux.s_free_inodes_count--;
                            fseek(archivo, inicioP, SEEK_SET);
                            fwrite(&aux, sizeof(SuperBloque), 1, archivo);
                            fclose(archivo);
                            cout << "La carpeta fue creada con exito" << endl;
                            creado = true;
                        }else{
                            BloqueCarpetas nuevaCarp;
                            nuevaCarp= mkdir::CbloqueC(actual,padre);
                            aux.s_blocks_count++;
                            Inodo nuevaT;
                            nuevaT = mkdir::CInodo(fechaActual, aux.s_blocks_count+1, '1');
                            listaChar nuevoA;

                            nuevaCarp.b_content[2].b_inodo=aux.s_inodes_count+1;
                            strcpy(nuevaCarp.b_content[2].b_name,f[i].c_str());
                            aux2.i_block[j]=aux.s_blocks_count;
                            fseek(archivo,aux.s_block_start+(64*aux.s_blocks_count),SEEK_SET);
                            fwrite(&nuevaCarp,64,1,archivo);
                            if (contenido2 != "")
                            {
                                nuevoA = CbloqueC(contenido2);
                                for (size_t t = 0; t < nuevoA.contenido.size(); t++)
                                {
                                    aux.s_blocks_count++;
                                    fseek(archivo, aux.s_block_start + (64 * (aux.s_blocks_count)), SEEK_SET);
                                    fwrite(&nuevoA.contenido[t], 64, 1, archivo);
                                    aux.s_free_blocks_count--;
                                    nuevaT.i_block[t]=aux.s_blocks_count;

                                }
                            }
                            else
                            {
                                BloqueArchivos nuevito;
                                nuevoA.contenido.push_back(nuevito);
                                fseek(archivo, aux.s_block_start + (64 * (aux.s_blocks_count + 1)), SEEK_SET);
                                fwrite(&nuevoA.contenido[0], 64, 1, archivo);
                                aux.s_blocks_count++;
                                aux.s_free_blocks_count--;


                            }
                            fseek(archivo,aux.s_inode_start+(sizeof (Inodo)*(aux.s_inodes_count+1)),SEEK_SET);
                            fwrite(&nuevaT,sizeof (Inodo),1,archivo);
                            fseek(archivo,aux.s_inode_start+(sizeof (Inodo)*actual),SEEK_SET);
                            fwrite(&aux2,sizeof (Inodo),1,archivo);
                            aux.s_inodes_count++;
                            aux.s_free_inodes_count--;
                            fseek(archivo,inicioP,SEEK_SET);
                            fwrite(&aux,sizeof (SuperBloque),1,archivo);
                            creado=true;
                        }
                    }
                    if(creado == true){
                        creado = false;
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
                                //actBI(Bmi, n, 1);
                                //actBI(Bmb, 3 * n, 2);
                                //Bloque de carpetas saliente del bloque de apuntadores
                                //nuevaC = CbloqueC(aux2.i_block[j], -1);
                                //strcpy(nuevaC.b_content[0].b_name, ruta[i].c_str());
                                //Bloque de carpetas saliente del nuevo inodo
                                //nuevaC2 = CbloqueC(aux.s_inodes_count + 1, actual);
                                //nuevaT = CInodo(fechaActual, aux.s_blocks_count + 2);
                                fseek(archivo, aux.s_inode_start + (sizeof(Inodo) * (aux.s_inodes_count + 1)), SEEK_SET);
                                fwrite(&nuevaT, sizeof(Inodo), 1, archivo);
                                fseek(archivo, aux.s_block_start + (64 * (aux.s_blocks_count + 1)), SEEK_SET);
                                fwrite(&nuevaC, 64, 1, archivo);
                                fseek(archivo, aux.s_block_start + (64 * (aux.s_blocks_count + 2)), SEEK_SET);
                                fwrite(&nuevaC2, 64, 1, archivo);
                                fseek(archivo, aux.s_bm_inode_start, SEEK_SET);
                                fwrite(&Bmi, sizeof(Bmi), 1, archivo);
                                fseek(archivo, aux.s_bm_block_start, SEEK_SET);
                                fwrite(&Bmb, sizeof(Bmb), 1, archivo);
                                fseek(archivo, aux.s_block_start + (64 * aux.s_blocks_count), SEEK_SET);
                                fwrite(&apuntador, 64, 1, archivo);
                                aux.s_inodes_count++;
                                aux.s_blocks_count++;
                                aux.s_blocks_count++;
                                aux.s_free_blocks_count--;
                                aux.s_free_blocks_count--;
                                aux.s_free_inodes_count--;
                                fseek(archivo, inicioP, SEEK_SET);
                                fwrite(&aux, sizeof(SuperBloque), 1, archivo);
                                fclose(archivo);
                                cout << "La carpeta fue creada con exito" << endl;
                                break;
                            }
                        }
                    }
                    else
                    {
                    /*
                        aux2.i_block[j] = aux.s_blocks_count + 1;
                        BloqueApuntadores nuevoAp;
                        nuevoAp = Capunt();
                        nuevoAp.b_pointers[0] = aux.s_blocks_count + 2;
                        BloqueCarpetas nuevaC;
                        nuevaC = CbloqueC(-1, -1);
                        nuevaC.b_content[0].b_inodo = aux.s_inodes_count + 1;
                        strcpy(nuevaC.b_content[0].b_name, ruta[i].c_str());
                        B_carpet nuevaC2;
                        nuevaC2 = CbloqueC(aux.s_inodes_count + 1, actual);
                        TInodos nuevaT;
                        nuevaT = CInodo(fechaActual, aux.s_blocks_count + 3);
                        fseek(archivo, aux.s_inode_start + (sizeof(TInodos) * aux.s_inodes_count + 1), SEEK_SET);
                        fwrite(&nuevaT, sizeof(TInodos), 1, archivo);
                        fseek(archivo, aux.s_block_start + (sizeof(B_carpet) * aux.s_blocks_count + 1), SEEK_SET);
                        fwrite(&nuevoAp, sizeof(B_carpet), 1, archivo);
                        fseek(archivo, aux.s_block_start + (sizeof(B_carpet) * aux.s_blocks_count + 2), SEEK_SET);
                        fwrite(&nuevaC, sizeof(B_carpet), 1, archivo);
                        fseek(archivo, aux.s_block_start + (sizeof(B_carpet) * aux.s_blocks_count + 3), SEEK_SET);
                        fwrite(&nuevaC2, sizeof(B_carpet), 1, archivo);
                        fseek(archivo, aux.s_inode_start + (sizeof(TInodos) * actual), SEEK_SET);
                        fwrite(&aux2, sizeof(TInodos), 1, archivo);

                        aux.s_inodes_count++;
                        aux.s_blocks_count++;
                        aux.s_blocks_count++;
                        aux.s_blocks_count++;
                        aux.s_free_blocks_count--;
                        aux.s_free_blocks_count--;
                        aux.s_free_blocks_count--;
                        aux.s_free_inodes_count--;
                        fseek(archivo, inicioP, SEEK_SET);
                        fwrite(&aux, sizeof(SuperB), 1, archivo);
                        fclose(archivo);
                        cout << "Se creo la carpeta correctamente" << endl;*/
                    cout<<"asdf"<<endl;
                    }
                }
            }
        }
    }
}

listaChar touch::CbloqueC(string contenido)
{
    listaChar nuevaC;

    string aux;
    for (int i = 0; i < contenido.size(); i++)
    {
        aux += contenido[i];
        if (aux.size() == 64 || (i + 1) == contenido.size())
        {
            BloqueArchivos nuevoA;
            strcpy(nuevoA.b_content, aux.c_str());
            nuevaC.contenido.push_back(nuevoA);
            aux="";
        }

    }
    return nuevaC;

}