
#include "mount.h"
#include "disco.h"


void mount::montar(string path, string name) {
    int partMontar = 0;
    char ruta[500];
    strcpy(ruta,path.c_str());
    char nombre[100];
    strcpy(nombre, name.c_str());
    string n = obtenerNDisco(path);
    char nombreDisco[500];
    strcpy(nombreDisco,n.c_str());

    if(fdisk::verificarNombre(path,name)==1){
        if(disco::existeCarpeta(ruta)==1){
            FILE *carpeta;
            carpeta= fopen(ruta,"rb+");
            rewind(carpeta);

            MBR mbrtemp;
            fread(&mbrtemp,sizeof (MBR),1,carpeta);
            if(carpeta!= nullptr){

                if(mbrtemp.mbr_partition[0].part_status =='V' && partMontar==0){

                    if(strcmp(mbrtemp.mbr_partition[0].part_name,name.c_str())==0 ){

                        listMounted disco;
                        disco=discoMontado(path);

                        if(disco.id == 500){
                            agregarDisco(nombreDisco,path);
                            disco=discoMontado(path);

                            if(agregarParticion(nombre,disco) == 1){
                                cout<<"-----------------------------------------------------------"<<endl;
                                cout << "AVISO: Particion: " << nombre << " montada correctamente.\n";
                                cout<<"-----------------------------------------------------------"<<endl;
                            }else{
                                cout<<"------------------------------------------------------------"<<endl;
                                cout<<"ERROR: La particion no se pudo montar."<<endl;
                                cout<<" La particion ya habia sido montada."<<endl;
                                cout<<"-------------------------------------------------------------"<<endl;
                            }
                            partMontar=1;
                        }else{

                            if(particionMontada(nombre,disco)==1){
                                cout<<"--------------------------------------------------------"<<endl;
                                cout<<" La particion ya se encuentra montada"<<endl;
                                cout<<"-------------------------------------------------------"<<endl;
                                partMontar=1;
                            }else{
                                if(agregarParticion(nombre,disco) == 1){
                                    cout<<"--------------------------------------------------------"<<endl;
                                    cout << "AVISO: Particion: " << nombre << " montada correctamente.\n";
                                    cout<<"--------------------------------------------------------"<<endl;
                                }
                                partMontar=1;
                            }
                        }

                    }

                }

                //-----NEXT----
                if(mbrtemp.mbr_partition[1].part_status =='V' && partMontar==0){

                    if(strcmp(mbrtemp.mbr_partition[1].part_name,name.c_str())==0 ){

                        listMounted disco;
                        disco = discoMontado(path);

                        if(disco.id == 500){
                            agregarDisco(nombreDisco,path);
                            disco=discoMontado(path);
                            cout<<"Hallado "<<disco.nombreDisco<<", particion montada correctamente"<<endl;
                            if(agregarParticion(nombre,disco) == 1){
                                cout<<"-----------------------------------------------------------"<<endl;
                                cout << "AVISO: Particion: " << nombre << " montada correctamente.\n";
                                cout<<"-----------------------------------------------------------"<<endl;
                            }else{
                                cout<<"------------------------------------------------------------"<<endl;
                                cout<<"ERROR: La particion no se pudo montar."<<endl;
                                cout<<" La particion ya habia sido montada."<<endl;
                                cout<<"-------------------------------------------------------------"<<endl;
                            }
                            partMontar=1;
                        }else{

                            if(particionMontada(nombre,disco)==1){
                                cout<<"--------------------------------------------------------"<<endl;
                                cout<<" La particion ya se encuentra montada"<<endl;
                                cout<<"-------------------------------------------------------"<<endl;
                                partMontar=1;
                            }else{
                                if(agregarParticion(nombre,disco) == 1){
                                    cout<<"--------------------------------------------------------"<<endl;
                                    cout << "AVISO: Particion: " << nombre << " montada correctamente.\n";
                                    cout<<"--------------------------------------------------------"<<endl;
                                }
                                partMontar=1;
                            }
                        }

                    }

                }

                if(mbrtemp.mbr_partition[2].part_status =='V' && partMontar==0){

                    if(strcmp(mbrtemp.mbr_partition[2].part_name,name.c_str())==0 ){

                        listMounted disco;
                        disco = discoMontado(path);

                        if(disco.id == 500){
                            agregarDisco(nombreDisco,path);
                            disco=discoMontado(path);

                            if(agregarParticion(nombre,disco) == 1){
                                cout<<"-----------------------------------------------------------"<<endl;
                                cout << "AVISO: Particion: " << nombre << " montada correctamente.\n";
                                cout<<"-----------------------------------------------------------"<<endl;
                            }else{
                                cout<<"------------------------------------------------------------"<<endl;
                                cout<<"ERROR: La particion no se pudo montar."<<endl;
                                cout<<" La particion ya habia sido montada."<<endl;
                                cout<<"-------------------------------------------------------------"<<endl;
                            }
                            partMontar=1;
                        }else{

                            if(particionMontada(nombre,disco)==1){
                                cout<<"--------------------------------------------------------"<<endl;
                                cout<<" La particion ya se encuentra montada"<<endl;
                                cout<<"-------------------------------------------------------"<<endl;
                                partMontar=1;
                            }else{
                                if(agregarParticion(nombre,disco) == 1){
                                    cout<<"--------------------------------------------------------"<<endl;
                                    cout << "AVISO: Particion: " << nombre << " montada correctamente.\n";
                                    cout<<"--------------------------------------------------------"<<endl;
                                }
                                partMontar=1;
                            }
                        }

                    }

                }


                if(mbrtemp.mbr_partition[3].part_status =='V' && partMontar==0){

                    if(strcmp(mbrtemp.mbr_partition[3].part_name,name.c_str())==0 ){

                        listMounted disco;
                        disco = discoMontado(path);

                        if(disco.id == 500){
                            agregarDisco(nombreDisco,path);
                            disco=discoMontado(path);

                            if(agregarParticion(nombre,disco) == 1){
                                cout<<"-----------------------------------------------------------"<<endl;
                                cout << "AVISO: Particion: " << nombre << " montada correctamente.\n";
                                cout<<"-----------------------------------------------------------"<<endl;
                            }else{
                                cout<<"------------------------------------------------------------"<<endl;
                                cout<<"ERROR: La particion no se pudo montar."<<endl;
                                cout<<" La particion ya habia sido montada."<<endl;
                                cout<<"-------------------------------------------------------------"<<endl;
                            }
                            partMontar=1;
                        }else{

                            if(particionMontada(nombre,disco)==1){
                                cout<<"--------------------------------------------------------"<<endl;
                                cout<<" La particion ya se encuentra montada"<<endl;
                                cout<<"-------------------------------------------------------"<<endl;
                                partMontar=1;
                            }else{
                                if(agregarParticion(nombre,disco) == 1){
                                    cout<<"--------------------------------------------------------"<<endl;
                                    cout << "AVISO: Particion: " << nombre << " montada correctamente.\n";
                                    cout<<"--------------------------------------------------------"<<endl;
                                }
                                partMontar=1;
                            }
                        }

                    }

                }

            }
            if(partMontar==0){
                cout<<"---NO SE PUDO MONTAR LA PARTICION---"<<endl;
            } else{
                mostrarParticiones();
            }
            fclose(carpeta);
        }else{
            cout<<"--------------------------------------------------------------"<<endl;
            cout <<"ERROR: Path ingresado no valido, no pertenece a algun disco"<<endl;
            cout<<"             PARTICION NO MONTADA                           "<<endl;
            cout<<"---------------------------------------------------------------"<<endl;
        }
    } else{
        cout<<"--------------------------------------------------------------"<<endl;
        cout <<"ERROR: No existe particion con el nombre proporcionado"<<endl;
        cout<<"             PARTICION NO MONTADA                           "<<endl;
        cout<<"---------------------------------------------------------------"<<endl;
    }

}

string mount::obtenerNDisco(string path) {
    char nombre[500];
    strcpy(nombre,path.c_str());


    char separador='/';
    string arrayChar[50];
    string texto=path;
    int aux=0;

    for(size_t i=0,j=0;i!=texto.npos;i=j){
        arrayChar[aux]=texto.substr(i+(i!=0),(j=texto.find(separador, i+1))-i-(i!=0));
        aux++;
    }
    separador = '.';
    int contador = 0;
    string vector[10];
    for(size_t i=0, j=0; i!=texto.npos; i=j){
        vector[contador] = texto.substr(i+(i!=0),(j=texto.find(separador, i+1))-i-(i!=0));
        contador++;
    }

    return  vector[0];

}

listMounted mount::discoMontado(string path) {
    string n = obtenerNDisco(path);
    if(listaMontados.empty() == false){
        for (int i = 0; i < listaMontados.size(); i++) {
            if(listaMontados[i].nombreDisco == n){
                cout << "El disco " << n << " ya esta montado " << endl;
                return listaMontados[i];
            }
        }
    }
    listMounted tmp;
    tmp.id = 500;
    cout << "El disco " << n << " aun no esta montado " << endl;
    return tmp;
}

void mount::agregarDisco(string nombreDisco, string path) {
    listMounted nuevo;
    nuevo.id = 0;
    nuevo.path = path;
    nuevo.num = contA + 1;
    contA++;
    nuevo.nombreDisco = nombreDisco;
    nuevo.listMountedPartitions.clear();
    listaMontados.push_back(nuevo);
    cout << "Se agrego el disco " << nuevo.nombreDisco << " a la lista de montados" << nuevo.path << endl;
    cout<<"--------------------------------------------------------------------------------------------------------"<<endl;



}


int mount::agregarParticion(string partName, listMounted disco) {

    //Hacemos una busqueda a traves del disco
    for (int i = 0; i < listaMontados.size(); i++) {
        if(listaMontados[i].nombreDisco == disco.nombreDisco){
            //Visualizamos las particiones montadas si son halladas.
            if(listaMontados[i].listMountedPartitions.size() == 0){
                partMontada nuevo;
                nuevo.letra = 'a';
                nuevo.nombrePart = partName;
                nuevo.idPart = "581" + string(1,'a');
                listaMontados[i].listMountedPartitions.push_back(nuevo);
                return  1;
            }
            else{
                partMontada nuevo;
                nuevo.letra = letras[listaMontados[i].listMountedPartitions.size()];
                nuevo.nombrePart = partName;
                nuevo.idPart = "58" + to_string(listaMontados[i].num) + listaMontados[i].listMountedPartitions[i].letra;
                listaMontados[i].listMountedPartitions.push_back(nuevo);
                return  1;
            }
        }
    }
    return 0;
}


int mount::particionMontada(string name, listMounted disco) {//Realizamos una busqueda en el disco
    for (int i = 0; i < listaMontados.size(); i++) {
        if(listaMontados[i].nombreDisco == disco.nombreDisco){
            //En caso de hallarlas, las visualizamos
            if(listaMontados[i].listMountedPartitions.size() != 0){
                for (int j = 0; j < listaMontados[i].listMountedPartitions.size(); j++) {
                    if(listaMontados[i].listMountedPartitions[j].nombrePart == name){
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}


void mount::mostrarParticiones() {
    //Buscamos en el disco
    for (int i = 0; i < listaMontados.size(); i++) {
        //procedemos a mostrar las particiones que ya estan monatadas
        for (int j = 0; j < listaMontados[i].listMountedPartitions.size(); j++) {
            cout << " " << listaMontados[i].nombreDisco <<" | "<< listaMontados[i].listMountedPartitions[j].nombrePart<<" | "<< " 58" << listaMontados[i].num<< listaMontados[i].listMountedPartitions[j].letra<< endl;
        }

    }

}


void mount::desmontarParticiones(string idParticionM) {

    cout<<"==============================================================="<<endl;
    cout<<"Se procedera a desmontar particion: "<<idParticionM<<endl;
    cout<<"==============================================================="<<endl;

    bool flag= false;

    for (int i = 0; i < listaMontados.size(); i++) {
        //HACEMOS UN RECORRIDO POR LAS PARTICIONES MONTADAS
        for (int j = 0; j < listaMontados[i].listMountedPartitions.size(); j++) {
            string idM = "58";
            idM += to_string( listaMontados[i].num);
            idM += listaMontados[i].listMountedPartitions[j].letra;
            if(idM == idParticionM){
                cout << idM << "," << to_string( listaMontados[i].num) <<endl;
                listaMontados[i].listMountedPartitions.erase (listaMontados[i].listMountedPartitions.begin()+j);
                flag = true;
                break;
            }
        }
    }


    if(flag){
        cout<<"---------------------------------------------------------"<<endl;
        cout<<"AVISO: Se desmonto correctamente la particion"<<endl;
        cout<<"---------------------------------------------------------"<<endl;
        mostrarParticiones();

    }else{
        cout<<"--------------------------------------------------------------"<<endl;
        cout<<"ERROR: No se encontro la particion solicitada"<<endl;
        cout <<"AVISO: No se pudo desmontar la particion: " << idParticionM<<endl;
        cout<<"-------------------------------------------------------------"<<endl;
    }



}

listMounted mount::recorrerLista(string id) {
    for (int i = 0; i < listaMontados.size(); i++) {
        for(int j = 0; j < listaMontados[i].listMountedPartitions.size(); j++) {
            string comp = "58" + to_string(listaMontados[i].num) + listaMontados[i].listMountedPartitions[j].letra;
            if (comp == id){
                return listaMontados[i];
            }
        }
    }
    listMounted vacio;
    return vacio;
}