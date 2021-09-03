
#include "fdisk.h"
void fdisk::crearParticion(string tam, string uni, string pat, string fi, string typ, string nam)
{
    cout << "PARTICIÓN" << tam << "," << uni << "," << pat << ","<<fi<<"," <<typ<<","<<nam<<"."<<endl;
    bool error = false;
    long int tama = 0;
    char fit = 'F';
    if((strcmp(uni.c_str(),"m")==0) || (strcmp(uni.c_str(),"k")==0)|| (strcmp(uni.c_str(),"b")==0)){
        if (strcmp(uni.c_str(),"m")==0){
            tama=1024*1024* atoi(tam.c_str());
        }else if(strcmp(uni.c_str(),"k")==0){
            tama=1024*atoi(tam.c_str());
        }else if(strcmp(uni.c_str(),"b")==0){
            tama=atoi(tam.c_str());
        }
    }else{
        cout <<("ERROR: El parametro de unit no es valido.\n");
        cout <<("AVISO: No se pudo crear la particion.\n");
        error = true;
    }


    if(fi=="bf"||fi=="ff"||fi=="wf"){
        if(fi=="bf"){
            fit  = 'B';
        }
        else if(fi=="ff"){
            fit  = 'F';
        }
        else if(fi=="wf"){
            fit  = 'W';
        }
        else{
            cout << ("ERROR: El parametro de fit no es valido.\n");
            cout << ("AVISO: No se puede crear la particion.\n");
        }
    }
    else{
        cout << ("ERROR: El parametro de fit no es valido.\n");
        cout << ("AVISO: No se puede crear la particion.\n");
        error = true;
    }

    char ruta[500];
    strcpy(ruta,pat.c_str());
    int banderaP = disco::existeCarpeta(ruta);
    if(banderaP == 2){
        cout << ("ERROR: El parametro de path no es valido.\n");
        cout << ("AVISO: No se puede crear la particion.\n");
        error = true;
    }

    if((strcmp(typ.c_str(),"P")==0) || (strcmp(typ.c_str(),"E")==0)|| (strcmp(typ.c_str(),"L")==0)){
        if (strcmp(typ.c_str(),"P")==0){
            if(verificarNombre(pat,nam)==1){
                printf("ERROR: Ya existe una particion con el nombre introducido.\n");
                printf("AVISO: No se puede crear la particion Primaria.\n");
                error = true;
            }else if(error == false){
                cout << "Se va a crear una primaria"<<endl;
                crearPrimaria(pat,'P',fit,tama,nam);
            }
        }else if(strcmp(typ.c_str(),"E")==0){
            if(verificarNombre(pat,nam)==1){
                printf("ERROR: Ya existe una particion con el nombre introducido.\n");
                printf("AVISO: No se puede crear la particion Extendida.\n");
                error = true;
            }else if(error == false){
                cout << "Se va a crear una extendida"<<endl;
                crearExtendida(pat,'E',fit,tama,nam);
            }
        }else{

            //cout << "No logre crear particiones logicas "<< endl;
            crearLogica(pat,'L',fit,tama,nam);
        }
    }else{
        printf("ERROR: El parametro de type no es valido.\n");
        printf("AVISO: No se puede crear la particion.\n");
        error = true;
    }

}

void fdisk::crearPrimaria(string pat, char typ, char fi, long int tam, string nam){
    bool errorCreacion = false;
    char ruta[500];
    strcpy(ruta, pat.c_str());

    FILE *fileC;
    fileC= fopen(ruta,"rb+");
    rewind(fileC);

    MBR mbrtemp;
    fread(&mbrtemp,sizeof(MBR),1,fileC);

    //******* Verificar Tamaño
    cout << "Part:" << tam <<",...Disco:" << mbrtemp.mbr_tamano << endl;
    if(tam >= mbrtemp.mbr_tamano){
        errorCreacion = true;
        cout << "ERROR: El tamanio de la particion es mayor o igual al tamanio del disco" << endl;
    }

    //******* Ver si hay particiones libres
    int particionLibre = 0;

    for(int i = 0; i < 4; i++){
        if ( mbrtemp.mbr_partition[i].part_status == 'F' ){
            particionLibre = i + 1;
            cout << "Particion "<< i + 1 <<" libre" << endl;
            break;
        }
    }
    if(particionLibre == 0){
        cout <<("ERROR: No hay particiones libres.\n");
        cout <<("AVISO: No se pudo crear la particion primaria.\n");
        errorCreacion = true;
    }
    //******* Ver si aun se pueden crear primarias
    int partPrim = 0;
    for(int i = 0;i < 4; i++){
        if ( (mbrtemp.mbr_partition[i].part_type == 'P' ) && (mbrtemp.mbr_partition[i].part_status == 'V') ){
            cout << "P" << i <<" es primaria" << endl;
            partPrim++;
        }
    }


    if(partPrim >= 3){
        cout <<("ERROR: Ya existen 3 particiones primarias.\n");
        cout <<("AVISO: No se pudo crear la particion primaria.\n");
        errorCreacion = true;
    }

    //******* Verificar si cabe en algun espacio
    if(errorCreacion == false){
        vector<espacio> esp;

        //--- Llenar el vector con los espacios usados
        for(int i = 0; i< 4; i++){
            if( mbrtemp.mbr_partition[i].part_status == 'V' )
            {
                espacio nuevo;
                nuevo.inicio = mbrtemp.mbr_partition[i].part_start;
                nuevo.final = mbrtemp.mbr_partition[i].part_start + mbrtemp.mbr_partition[i].part_size;
                nuevo.particion = mbrtemp.mbr_partition[i].part_name;
                esp.push_back(nuevo);
            }
        }

        //--- Insertar tamañao del ebr
        if(1+1 == 2){
            espacio nu;
            nu.inicio = 0;
            nu.final = sizeof (MBR) + 1;
            nu.particion = "MBR";
            esp.push_back(nu);
        }

        //--- Ordenar de menor a mayor
        espacio temporal;
        for (int i = 0; i < esp.size(); i++){
            for (int j = 0; j< esp.size()-1; j++){
                if (esp[j].inicio > esp[j+1].inicio){ // Ordena el array de mayor a menor, cambiar el "<" a ">" para ordenar de menor a mayor
                    temporal = esp[j];
                    esp[j] = esp[j+1];
                    esp[j+1] = temporal;
                }
            }
        }

        //--- Mostrar como quedo ordenado
        for (int i =0; i < esp.size(); i++)
            cout<< esp[i].inicio <<"-"<< esp[i].final<<" "<<esp[i].particion << endl;

        //---- Ver cual es el espacio ideal segun el fit
        if(esp.size() == 1){
            //--Insertar despues del mbr
            mbrtemp.mbr_partition[0].part_status='V';
            mbrtemp.mbr_partition[0].part_type=typ;
            mbrtemp.mbr_partition[0].part_fit =fi;
            mbrtemp.mbr_partition[0].part_start=( (sizeof (MBR)) + 1);
            mbrtemp.mbr_partition[0].part_size= tam;
            strcpy(mbrtemp.mbr_partition[0].part_name,nam.c_str());

            rewind(fileC);
            fwrite(&mbrtemp,sizeof (MBR),1,fileC);
            printf("AVISO: Particion primaria creada correctamente. Se almaceno en la P1. \n");
        }
        else{
            //---Insertar con el FF
            if( mbrtemp.disk_fit == 'F' ){
                //----Buscar espacio
                espacio nTemp;
                bool hayEspacio = false;
                long int restaFI = 0;

                for (int i =0; i < esp.size()-1; i++){
                    restaFI =  esp[i+1].inicio - esp[i].final;
                    //cout << "--*" << restaFI <<endl;
                    if(restaFI >= tam){
                        nTemp.inicio = esp[i].final + 1;
                        nTemp.final = esp[i+1].inicio - 1;
                        nTemp.particion = esp[i].particion;
                        hayEspacio = true;
                        break;
                    }

                    if(i == (esp.size()-2) ){
                        restaFI =  mbrtemp.mbr_tamano - esp[i+1].final;
                        //cout << "--**" << restaFI <<endl;
                        if(restaFI >= tam){
                            nTemp.inicio = esp[i+1].final + 1;
                            nTemp.particion = esp[i+1].particion;
                            hayEspacio = true;
                            break;
                        }
                    }
                }

                if(hayEspacio == true){
                    cout << "Insertar despues de: "<< nTemp.particion << ", IN: " << nTemp.inicio << endl;

                    int BcreoP = 0;
                    for(int i = 0;i<4;i++){
                        if( (mbrtemp.mbr_partition[i].part_status=='F') && BcreoP==0){
                            mbrtemp.mbr_partition[i].part_status='V';
                            mbrtemp.mbr_partition[i].part_type=typ;
                            mbrtemp.mbr_partition[i].part_fit =fi;
                            mbrtemp.mbr_partition[i].part_start=nTemp.inicio;
                            mbrtemp.mbr_partition[i].part_size= tam;
                            strcpy(mbrtemp.mbr_partition[i].part_name,nam.c_str());

                            rewind(fileC);
                            fwrite(&mbrtemp,sizeof (MBR),1,fileC);
                            printf("AVISO: Particion primaria creada correctamente. Se almaceno en la P1\n");
                            BcreoP=1;
                        }
                    }

                }
                else {
                    cout << "ERROR: No existe espacio suficiente para almacenar la particion" <<endl;
                    cout << "AVISO: No se creara la particion primaria" << endl;
                }


            }
                //---Insertar con el BF
            else if ( mbrtemp.disk_fit == 'B' ) {
                //----Buscar espacio
                espacio nTemp;
                bool hayEspacio = false;
                long int restaFI = 0, restaTemp = 0, entrarF = 0;

                for (int i =0; i < esp.size()-1; i++){
                    restaFI =  esp[i+1].inicio - esp[i].final;
                    //cout << "--*" << restaFI << endl; //<< "," << restaTemp <<endl;
                    if(restaFI >= tam){
                        if(entrarF == 0 ){
                            entrarF++;
                            restaTemp = restaFI;
                            nTemp.inicio = esp[i].final + 1;
                            nTemp.final = esp[i+1].inicio - 1;
                            nTemp.particion = esp[i].particion;
                            hayEspacio = true;
                        }else {
                            if(restaTemp > restaFI){
                                restaTemp = restaFI;
                                nTemp.inicio = esp[i].final + 1;
                                nTemp.final = esp[i+1].inicio - 1;
                                nTemp.particion = esp[i].particion;
                                hayEspacio = true;
                            }
                        }
                    }

                    if(i == (esp.size()-2) ){
                        restaFI =  mbrtemp.mbr_tamano - esp[i+1].final;
                        //cout << "--**" << restaFI << endl; //<< "," << restaTemp <<endl;
                        if(restaFI >= tam){
                            if(entrarF == 0 ){
                                entrarF++;
                                restaTemp = restaFI;
                                nTemp.inicio = esp[i+1].final + 1;
                                nTemp.particion = esp[i+1].particion;
                                hayEspacio = true;
                            }else {
                                if(restaTemp > restaFI){
                                    restaTemp = restaFI;
                                    nTemp.inicio = esp[i+1].final + 1;
                                    nTemp.particion = esp[i+1].particion;
                                    hayEspacio = true;
                                }
                            }
                        }
                    }

                }

                if(hayEspacio == true){
                    cout << "Insertar despues de: "<< nTemp.particion << ", IN: " << nTemp.inicio << endl;

                    int BcreoP = 0;
                    for(int i = 0; i<4; i++){
                        if( (mbrtemp.mbr_partition[i].part_status=='F') && BcreoP==0){
                            mbrtemp.mbr_partition[i].part_status='V';
                            mbrtemp.mbr_partition[i].part_type=typ;
                            mbrtemp.mbr_partition[i].part_fit =fi;
                            mbrtemp.mbr_partition[i].part_start=nTemp.inicio;
                            mbrtemp.mbr_partition[i].part_size= tam;
                            strcpy(mbrtemp.mbr_partition[i].part_name,nam.c_str());

                            rewind(fileC);
                            fwrite(&mbrtemp,sizeof (MBR),1,fileC);
                            printf("AVISO: Particion primaria creada correctamente. Se almaceno en la P1\n");
                            BcreoP=1;
                        }
                    }

                }
                else {
                    cout << "ERROR: No existe espacio suficiente para almacenar la particion" <<endl;
                    cout << "AVISO: No se creara la particion primaria" << endl;
                }

            }
                //---Insertar con el WF
            else{
                //----Buscar espacio
                espacio nTemp;
                bool hayEspacio = false;
                long int restaFI = 0, restaTemp = 0, entrarF = 0;

                for (int i =0; i < esp.size()-1; i++){
                    restaFI =  esp[i+1].inicio - esp[i].final;
                    //cout << "--*" << restaFI << endl; //<< "," << restaTemp <<endl;
                    if(restaFI >= tam){
                        if(entrarF == 0 ){
                            entrarF++;
                            restaTemp = restaFI;
                            nTemp.inicio = esp[i].final + 1;
                            nTemp.final = esp[i+1].inicio - 1;
                            nTemp.particion = esp[i].particion;
                            hayEspacio = true;
                        }else {
                            if(restaTemp < restaFI){
                                restaTemp = restaFI;
                                nTemp.inicio = esp[i].final + 1;
                                nTemp.final = esp[i+1].inicio - 1;
                                nTemp.particion = esp[i].particion;
                                hayEspacio = true;
                            }
                        }
                    }

                    if(i == (esp.size()-2) ){
                        restaFI =  mbrtemp.mbr_tamano - esp[i+1].final;
                        //cout << "--**" << restaFI << endl; //<< "," << restaTemp <<endl;
                        if(restaFI >= tam){
                            if(entrarF == 0 ){
                                entrarF++;
                                restaTemp = restaFI;
                                nTemp.inicio = esp[i+1].final + 1;
                                nTemp.particion = esp[i+1].particion;
                                hayEspacio = true;
                            }else {
                                if(restaTemp < restaFI){
                                    restaTemp = restaFI;
                                    nTemp.inicio = esp[i+1].final + 1;
                                    nTemp.particion = esp[i+1].particion;
                                    hayEspacio = true;
                                }
                            }
                        }
                    }

                }

                if(hayEspacio == true){
                    cout << "Insertar despues de: "<< nTemp.particion << ", IN: " << nTemp.inicio << endl;

                    int BcreoP = 0;
                    for(int i = 0; i<4; i++){
                        if( (mbrtemp.mbr_partition[i].part_status=='F') && BcreoP==0){
                            mbrtemp.mbr_partition[i].part_status='V';
                            mbrtemp.mbr_partition[i].part_type=typ;
                            mbrtemp.mbr_partition[i].part_fit =fi;
                            mbrtemp.mbr_partition[i].part_start=nTemp.inicio;
                            mbrtemp.mbr_partition[i].part_size= tam;
                            strcpy(mbrtemp.mbr_partition[i].part_name,nam.c_str());

                            rewind(fileC);
                            fwrite(&mbrtemp,sizeof (MBR),1,fileC);
                            printf("AVISO: Particion primaria creada correctamente. Se almaceno en la P1\n");
                            BcreoP=1;
                        }
                    }

                }
                else {
                    cout << "ERROR: No existe espacio suficiente para almacenar la particion" <<endl;
                    cout << "AVISO: No se creara la particion primaria" << endl;
                }

            }
        }

    }
    //---- Cerrar el archivo
    fclose(fileC);
}

void fdisk::crearExtendida(string pat, char typ, char fi, long tam, string nam){
    bool errorCreacion = false;
    char ruta[500];
    strcpy(ruta, pat.c_str());

    FILE *fileC;
    fileC= fopen(ruta,"rb+");
    rewind(fileC);

    MBR mbrtemp;
    fread(&mbrtemp,sizeof(MBR),1,fileC);

    //******* Verificar Tamaño
    cout << tam <<",..." << mbrtemp.mbr_tamano << endl;
    if(tam >= mbrtemp.mbr_tamano){
        errorCreacion = true;
        cout << "ERROR: El tamanio de la particion es mayor o igual al tamanio del disco" << endl;
        cout << "AVISO: No se creara la particion extendida"<<endl;
    }

    //******* Ver si hay particiones libres
    int particionLibre = 0;
    for(int i = 0; i<4;i++){
        if ( mbrtemp.mbr_partition[i].part_status == 'F' ){
            particionLibre = 1;
            cout << "Particion 1 libre" << endl;
            break;
        }
    }

    if(particionLibre == 0){
        cout <<("ERROR: No hay particiones libres.\n");
        cout <<("AVISO: No se pudo crear la particion extendida.\n");
        errorCreacion = true;
    }

    //******* Ver si aun se pueden crear primarias
    int partPrim = 0;
    for(int i = 0; i <4;i++){
        if ( (mbrtemp.mbr_partition[i].part_type == 'E') && (mbrtemp.mbr_partition[i].part_status == 'V') ){
            cout << "P1 es Extendida" << endl;
            partPrim++;
        }
    }

    if(partPrim >= 1){
        cout <<("ERROR: Ya existe un particion extendida.\n");
        cout <<("AVISO: No se pudo crear la particion extendida.\n");
        errorCreacion = true;
    }

    //******* Verificar si cabe en algun espacio
    if(errorCreacion == false){
        vector<espacio> esp;

        //--- Llenar el vector con los espacios usados
        for(int i = 0; i<4;i++){
            if( mbrtemp.mbr_partition[i].part_status == 'V' )
            {
                espacio nuevo;
                nuevo.inicio = mbrtemp.mbr_partition[i].part_start;
                nuevo.final = mbrtemp.mbr_partition[i].part_start + mbrtemp.mbr_partition[i].part_size;
                nuevo.particion = mbrtemp.mbr_partition[i].part_name;
                esp.push_back(nuevo);
            }
        }

        //--- Insertar tamañao del ebr
        if(1+1 == 2){
            espacio nu;
            nu.inicio = 0;
            nu.final = sizeof (MBR) + 1;
            nu.particion = "MBR";
            esp.push_back(nu);
        }

        //--- Ordenar de menor a mayor
        espacio temporal;
        for (int i = 0; i < esp.size(); i++){
            for (int j = 0; j< esp.size()-1; j++){
                if (esp[j].inicio > esp[j+1].inicio){ // Ordena el array de mayor a menor, cambiar el "<" a ">" para ordenar de menor a mayor
                    temporal = esp[j];
                    esp[j] = esp[j+1];
                    esp[j+1] = temporal;
                }
            }
        }

        //--- Mostrar como quedo ordenado
        for (int i =0; i < esp.size(); i++)
            cout<< esp[i].inicio <<"-"<< esp[i].final<<" "<<esp[i].particion << endl;

        //---- Ver cual es el espacio ideal segun el fit
        if(esp.size() == 1){
            //--Insertar despues del mbr
            mbrtemp.mbr_partition[0].part_status='V';
            mbrtemp.mbr_partition[0].part_type='E';
            mbrtemp.mbr_partition[0].part_fit =fi;
            mbrtemp.mbr_partition[0].part_start=( (sizeof (MBR)) + 1);
            mbrtemp.mbr_partition[0].part_size= tam;
            strcpy(mbrtemp.mbr_partition[0].part_name,nam.c_str());
            rewind(fileC);
            fwrite(&mbrtemp,sizeof (MBR),1,fileC);
            fseek(fileC, mbrtemp.mbr_partition[0].part_start, SEEK_SET);
            EBR aux;
            aux.par_start = -1;
            aux.part_status = 'F';
            aux.part_next = -1;
            fwrite(&aux,sizeof(EBR),1,fileC);
            printf("AVISO: Particion extendida creada correctamente. Se almaceno en la P1. \n");
        }
        else{
            //---Insertar con el FF
            if( mbrtemp.disk_fit == 'F' ){
                //----Buscar espacio
                espacio nTemp;
                bool hayEspacio = false;
                long int restaFI = 0;

                for (int i =0; i < esp.size()-1; i++){
                    restaFI =  esp[i+1].inicio - esp[i].final;
                    //cout << "--*" << restaFI <<endl;
                    if(restaFI >= tam){
                        nTemp.inicio = esp[i].final + 1;
                        nTemp.final = esp[i+1].inicio - 1;
                        nTemp.particion = esp[i].particion;
                        hayEspacio = true;
                        break;
                    }

                    if(i == (esp.size()-2) ){
                        restaFI =  mbrtemp.mbr_tamano - esp[i+1].final;
                        //cout << "--**" << restaFI <<endl;
                        if(restaFI >= tam){
                            nTemp.inicio = esp[i+1].final + 1;
                            nTemp.particion = esp[i+1].particion;
                            hayEspacio = true;
                            break;
                        }
                    }
                }

                if(hayEspacio == true){
                    cout << "Insertar despues de: "<< nTemp.particion << ", IN: " << nTemp.inicio << endl;

                    int BcreoP = 0;
                    for(int i = 0;i < 4; i++){
                        if( (mbrtemp.mbr_partition[i].part_status=='F') && BcreoP==0){
                            mbrtemp.mbr_partition[i].part_status='V';
                            mbrtemp.mbr_partition[i].part_type='E';
                            mbrtemp.mbr_partition[i].part_fit =fi;
                            mbrtemp.mbr_partition[i].part_start=nTemp.inicio;
                            mbrtemp.mbr_partition[i].part_size= tam;
                            strcpy(mbrtemp.mbr_partition[i].part_name,nam.c_str());

                            rewind(fileC);
                            fwrite(&mbrtemp,sizeof (MBR),1,fileC);

                            fseek(fileC, mbrtemp.mbr_partition[i].part_start, SEEK_SET);
                            EBR aux;
                            aux.par_start = -1;
                            aux.part_status = 'F';
                            aux.part_next = -1;
                            fwrite(&aux,sizeof(EBR),1,fileC);

                            printf("AVISO: Particion extendida creada correctamente. Se almaceno en la P1\n");
                            BcreoP=1;
                            break;
                        }
                    }
                }
                else {
                    cout << "ERROR: No existe espacio suficiente para almacenar la particion" <<endl;
                    cout << "AVISO: No se creara la particion extendida" << endl;
                }


            }
                //---Insertar con el BF
            else if ( mbrtemp.disk_fit == 'B' ) {
                //----Buscar espacio
                espacio nTemp;
                bool hayEspacio = false;
                long int restaFI = 0, restaTemp = 0, entrarF = 0;

                for (int i =0; i < esp.size()-1; i++){
                    restaFI =  esp[i+1].inicio - esp[i].final;
                    //cout << "--*" << restaFI << endl; //<< "," << restaTemp <<endl;
                    if(restaFI >= tam){
                        if(entrarF == 0 ){
                            entrarF++;
                            restaTemp = restaFI;
                            nTemp.inicio = esp[i].final + 1;
                            nTemp.final = esp[i+1].inicio - 1;
                            nTemp.particion = esp[i].particion;
                            hayEspacio = true;
                        }else {
                            if(restaTemp > restaFI){
                                restaTemp = restaFI;
                                nTemp.inicio = esp[i].final + 1;
                                nTemp.final = esp[i+1].inicio - 1;
                                nTemp.particion = esp[i].particion;
                                hayEspacio = true;
                            }
                        }
                    }

                    if(i == (esp.size()-2) ){
                        restaFI =  mbrtemp.mbr_tamano - esp[i+1].final;
                        //cout << "--**" << restaFI << endl; //<< "," << restaTemp <<endl;
                        if(restaFI >= tam){
                            if(entrarF == 0 ){
                                entrarF++;
                                restaTemp = restaFI;
                                nTemp.inicio = esp[i+1].final + 1;
                                nTemp.particion = esp[i+1].particion;
                                hayEspacio = true;
                            }else {
                                if(restaTemp > restaFI){
                                    restaTemp = restaFI;
                                    nTemp.inicio = esp[i+1].final + 1;
                                    nTemp.particion = esp[i+1].particion;
                                    hayEspacio = true;
                                }
                            }
                        }
                    }

                }

                if(hayEspacio == true){
                    cout << "Insertar despues de: "<< nTemp.particion << ", IN: " << nTemp.inicio << endl;

                    int BcreoP = 0;
                    for(int i = 0;i < 4; i++) {
                        if ((mbrtemp.mbr_partition[i].part_status == 'F') && BcreoP == 0) {
                            mbrtemp.mbr_partition[i].part_status = 'V';
                            mbrtemp.mbr_partition[i].part_type = 'E';
                            mbrtemp.mbr_partition[i].part_fit = fi;
                            mbrtemp.mbr_partition[i].part_start = nTemp.inicio;
                            mbrtemp.mbr_partition[i].part_size = tam;
                            strcpy(mbrtemp.mbr_partition[i].part_name, nam.c_str());

                            rewind(fileC);
                            fwrite(&mbrtemp, sizeof(MBR), 1, fileC);

                            fseek(fileC, mbrtemp.mbr_partition[i].part_start, SEEK_SET);
                            EBR aux;
                            aux.par_start = -1;
                            aux.part_status = 'F';
                            aux.part_next = -1;
                            fwrite(&aux,sizeof(EBR),1,fileC);

                            printf("AVISO: Particion extendida creada correctamente. Se almaceno en la P1\n");
                            BcreoP = 1;
                        }
                    }

                }
                else {
                    cout << "ERROR: No existe espacio suficiente para almacenar la particion" <<endl;
                    cout << "AVISO: No se creara la particion extendida" << endl;
                }

            }
                //---Insertar con el WF
            else{
                //----Buscar espacio
                espacio nTemp;
                bool hayEspacio = false;
                long int restaFI = 0, restaTemp = 0, entrarF = 0;

                for (int i =0; i < esp.size()-1; i++){
                    restaFI =  esp[i+1].inicio - esp[i].final;
                    //cout << "--*" << restaFI << endl; //<< "," << restaTemp <<endl;
                    if(restaFI >= tam){
                        if(entrarF == 0 ){
                            entrarF++;
                            restaTemp = restaFI;
                            nTemp.inicio = esp[i].final + 1;
                            nTemp.final = esp[i+1].inicio - 1;
                            nTemp.particion = esp[i].particion;
                            hayEspacio = true;
                        }else {
                            if(restaTemp < restaFI){
                                restaTemp = restaFI;
                                nTemp.inicio = esp[i].final + 1;
                                nTemp.final = esp[i+1].inicio - 1;
                                nTemp.particion = esp[i].particion;
                                hayEspacio = true;
                            }
                        }
                    }

                    if(i == (esp.size()-2) ){
                        restaFI =  mbrtemp.mbr_tamano - esp[i+1].final;
                        //cout << "--**" << restaFI << endl; //<< "," << restaTemp <<endl;
                        if(restaFI >= tam){
                            if(entrarF == 0 ){
                                entrarF++;
                                restaTemp = restaFI;
                                nTemp.inicio = esp[i+1].final + 1;
                                nTemp.particion = esp[i+1].particion;
                                hayEspacio = true;
                            }else {
                                if(restaTemp < restaFI){
                                    restaTemp = restaFI;
                                    nTemp.inicio = esp[i+1].final + 1;
                                    nTemp.particion = esp[i+1].particion;
                                    hayEspacio = true;
                                }
                            }
                        }
                    }

                }

                if(hayEspacio == true){
                    cout << "Insertar despues de: "<< nTemp.particion << ", IN: " << nTemp.inicio << endl;

                    int BcreoP = 0;
                    for(int i = 0;i < 4; i++) {
                        if ((mbrtemp.mbr_partition[i].part_status == 'F') && BcreoP == 0) {
                            mbrtemp.mbr_partition[i].part_status = 'V';
                            mbrtemp.mbr_partition[i].part_type = 'E';
                            mbrtemp.mbr_partition[i].part_fit = fi;
                            mbrtemp.mbr_partition[i].part_start = nTemp.inicio;
                            mbrtemp.mbr_partition[i].part_size = tam;
                            strcpy(mbrtemp.mbr_partition[i].part_name, nam.c_str());

                            rewind(fileC);
                            fwrite(&mbrtemp, sizeof(MBR), 1, fileC);

                            fseek(fileC, mbrtemp.mbr_partition[i].part_start, SEEK_SET);
                            EBR aux;
                            aux.par_start = -1;
                            aux.part_status = 'F';
                            aux.part_next = -1;
                            fwrite(&aux,sizeof(EBR),1,fileC);

                            printf("AVISO: Particion extendida creada correctamente. Se almaceno en la P1\n");
                            BcreoP = 1;
                        }
                    }
                }
                else {
                    cout << "ERROR: No existe espacio suficiente para almacenar la particion" <<endl;
                    cout << "AVISO: No se creara la particion extendida" << endl;
                }

            }
        }

    }
    //---- Cerrar el archivo
    fclose(fileC);
}

void fdisk::crearLogica(string pat, char typ, char fi, long tam, string name) {
    char ruta[500];
    strcpy(ruta,pat.c_str());
    FILE *fileC;
    fileC= fopen(ruta,"rb+");
    rewind(fileC);
    MBR mbr;

    fseek(fileC, 0, SEEK_SET);
    fread(&mbr, sizeof(MBR), 1, fileC);
    int c = 0;
    for(int i = 0; i < 4; i++){
        if(mbr.mbr_partition[i].part_type == 'E' && mbr.mbr_partition[i].part_status == 'V'){
            cout << "Se va a crear una Logica"<<endl;

            int tamcompleto = tam +sizeof(EBR);
            if(mbr.mbr_partition[i].part_size < tamcompleto){
                cout << "La particion sobre pasa el tamaño de la particion extendida"<<endl;
            }else{
                EBR ebr;
                Partition part;

                fseek(fileC, mbr.mbr_partition[i].part_start, SEEK_SET);
                fread(&ebr, sizeof(EBR), 1, fileC);

                if(ebr.part_status == 'F'){

                    ebr.part_status = 'V';
                    ebr.par_start = mbr.mbr_partition[i].part_start+ (sizeof(EBR))+1;
                    ebr.part_size = tam;
                    ebr.part_fit = fi;
                    ebr.part_next = mbr.mbr_partition[i].part_start+ (sizeof(EBR)) + tam + 1;
                    strcpy(ebr.part_name,name.c_str());
                    fseek(fileC, mbr.mbr_partition[i].part_start, SEEK_SET);
                    fwrite(&ebr, sizeof(EBR), 1, fileC);

                    fseek(fileC, mbr.mbr_partition[i].part_start+(sizeof(EBR))+1, SEEK_SET);
                    fread(&part, sizeof(Partition), 1, fileC);
                    part.part_status = 'V';
                    part.part_start = mbr.mbr_partition[i].part_start +(sizeof(EBR))+1;
                    strcpy(part.part_name,name.c_str());
                    part.part_size = tam;
                    part.part_fit = fi;
                    fseek(fileC, mbr.mbr_partition[i].part_start+(sizeof(EBR))+1, SEEK_SET);
                    fwrite(&part, sizeof(Partition), 1, fileC);


                    fseek(fileC, ebr.part_next, SEEK_SET);
                    fwrite(&ebr, sizeof(EBR), 1, fileC);
                    EBR aux;
                    aux.part_status = 'F';
                    aux.part_size = -1;
                    aux.part_next = -1;
                    fseek(fileC, ebr.part_next, SEEK_SET);
                    fwrite(&aux, sizeof(EBR), 1, fileC);
                    fclose(fileC);
                }else{
                    EBR temp;
                    int comp = 0;
                    int tamreal = 0;
                    vector<espacio> esp;
                    // |EBR| LOGICA | EBR2|

                    for(int j = 0; j < 5; j++) {
                        comp = (mbr.mbr_partition[i].part_size - (temp.par_start +temp.part_size+ sizeof(EBR)));
                        tamreal  = (tam +sizeof(EBR));
                        if(ebr.part_next != -1){
                            if (ebr.part_next - ebr.par_start == ebr.part_size) {
                                temp = ebr;
                                fseek(fileC, ebr.part_next, SEEK_SET);
                                fread(&ebr, sizeof(EBR), 1, fileC);
                            }else{
                                temp = ebr;
                                espacio nuevo;
                                nuevo.inicio = ebr.par_start;
                                nuevo.final = ebr.par_start + ebr.part_size;
                                nuevo.particion = ebr.part_name;
                                esp.push_back(nuevo);
                                fseek(fileC, ebr.part_next, SEEK_SET);
                                fread(&ebr, sizeof(EBR), 1, fileC);
                            }

                        }else if(comp >= tamreal){
                            espacio nuevo;
                            nuevo.inicio = temp.part_next + sizeof(EBR);
                            nuevo.final = mbr.mbr_partition[i].part_size;
                            nuevo.particion = "";
                            esp.push_back(nuevo);
                            break;
                        }
                    }
                    espacio temporal;
                    for (int i = 0; i < esp.size(); i++){
                        for (int j = 0; j< esp.size()-1; j++){
                            if (esp[j].inicio > esp[j+1].inicio){
                                temporal = esp[j];
                                esp[j] = esp[j+1];
                                esp[j+1] = temporal;
                            }
                        }
                    }
                    //FIT
                    fseek(fileC, mbr.mbr_partition[i].part_start, SEEK_SET);
                    fread(&ebr, sizeof(EBR), 1, fileC);
                    for(int j = 0; j < 5; j++) {
                        if (mbr.mbr_partition[i].part_fit == 'F') {
                            //----Buscar espacio
                            espacio nTemp;
                            bool hayEspacio = false;
                            long int restaFI = 0;

                            for (int i = 0; i < esp.size(); i++) {
                                restaFI = esp[i].final -esp[i].inicio;
                                if (restaFI >= tam) {
                                    nTemp.inicio = esp[i].inicio;
                                    nTemp.final = esp[i].inicio + tam;
                                    nTemp.particion = esp[i].particion;
                                    hayEspacio = true;
                                    break;
                                }

                                if (i == (esp.size() - 1)) {
                                    restaFI = mbr.mbr_partition[i].part_size - esp[i].final;
                                    if (restaFI >= tam) {
                                        nTemp.inicio = esp[i].final + 1;
                                        nTemp.particion = esp[i].particion;
                                        hayEspacio = true;
                                        break;
                                    }
                                }
                            }

                            if (hayEspacio == true) {
                                cout << "Insertar despues de: " << nTemp.particion << ", IN: " << nTemp.inicio << endl;

                                int BcreoP = 0;
                                for (int k = 0; k < 5; k++) {
                                    //if ((part.part_status == 'F') && BcreoP == 0) {
                                    part.part_status = 'V';
                                    part.part_type = typ;
                                    part.part_fit = fi;
                                    part.part_start = nTemp.inicio;
                                    part.part_size = tam;
                                    part.part_name, name.c_str();

                                    fseek(fileC, nTemp.inicio, SEEK_SET);
                                    fwrite(&part, sizeof(MBR), 1, fileC);
                                    printf("AVISO: Particion primaria creada correctamente. Se almaceno en la P1\n");
                                    BcreoP = 1;
                                    //}
                                    break;
                                }

                            } else {
                                cout << "ERROR: No existe espacio suficiente para almacenar la particion" << endl;
                                cout << "AVISO: No se creara la particion primaria" << endl;
                            }
                        }
                    }
                }
            }
            cout<<"Se creo correctamente la particion Logica";
            break;
        }
        c ++;
    }
    if(c == 4){
        fclose(fileC);
        cout << "No existe una particion extendida para poder crear una partcion logica"<<endl;
    }
    fileC= fopen(ruta,"rb+");
    rewind(fileC);
    MBR a;
    EBR b;
    EBR d;
    fseek(fileC, 0, SEEK_SET);
    fread(&a, sizeof(MBR), 1, fileC);
    fseek(fileC, a.mbr_partition[0].part_start, SEEK_SET);
    fread(&b, sizeof(EBR), 1, fileC);
    rewind(fileC);
    fseek(fileC, b.part_next, SEEK_SET);
    fread(&d, sizeof(EBR), 1, fileC);
    cout<<"asdf";
}


void fdisk::eliminarP(string nam, string pat, string tipo){
    cout << "Part. delete: " << nam << "," << tipo << "," << pat << endl;
    if(strcmp(tipo.c_str(),"fast")){
        eliminarParticion(nam,pat,tipo);
    }else if(strcmp(tipo.c_str(),"full")){
        eliminarParticion(nam,pat,tipo);
    }else{
        printf("ERROR: El parametro de delete no es valido.\n");
        printf("AVISO: No se pudo eliminar la particion.\n");
    }
}

void fdisk::eliminarParticion(string nam, string pat, string tipo){
    int BborroP = 0;
    char ruta[500];
    strcpy(ruta,pat.c_str());
    if(disco::existeCarpeta(ruta) == 1){
        FILE *fileC;
        fileC= fopen(ruta,"rb+");
        rewind(fileC);
        MBR mbrtemp;
        fread(&mbrtemp,sizeof(MBR),1,fileC);

        if(fileC != nullptr){
            for(int i = 0; i<4; i++){
                if( (mbrtemp.mbr_partition[i].part_status=='V') && (BborroP==0) ){
                    if(strcmp(mbrtemp.mbr_partition[i].part_name,nam.c_str())==0){
                        if( tipo == "fast" ){
                            mbrtemp.mbr_partition[i].part_status='F';
                            rewind(fileC);
                            fwrite(&mbrtemp,sizeof(MBR),1,fileC);
                            printf("AVISO: Particion eliminada correctamente. Se encontraba en P1. FAST\n");
                            BborroP=1;
                            break;
                        }else{
                            mbrtemp.mbr_partition[i].part_status='F';
                            mbrtemp.mbr_partition[i].part_type='\0';
                            mbrtemp.mbr_partition[i].part_fit='\0';
                            mbrtemp.mbr_partition[i].part_start=0;
                            mbrtemp.mbr_partition[i].part_size=0;
                            strcpy(mbrtemp.mbr_partition[i].part_name,"\0");
                            rewind(fileC);
                            fwrite(&mbrtemp,sizeof(MBR),1,fileC); // aca escribo de nuevo el MBR
                            printf("AVISO: Particion eliminada correctamente. Se encontraba en P1. FULL.\n");
                            BborroP=1;
                            break;
                        }
                    }
                }
            }

            if(BborroP == 0){
                printf("ERROR: No se encontro la particion.\n");
                cout << "AVISO: No se pudo eliminar la particion " << nam <<".\n";
            }
        }
        else{
            printf("ERROR: No se pudo acceder al disco.\n");
            printf("AVISO: No se pudo eliminar la particion.\n");
        }

        fclose(fileC);

    }else{
        printf("ERROR: La ruta ingresada no referencia ningun disco.\n");
        printf("AVISO: No se pudo eliminar la particion.\n");
    }
}

int fdisk::verificarNombre(string pa, string nombre){
    char ruta[500];
    char nom[16];
    strcpy(nom,nombre.c_str());
    strcpy(ruta,pa.c_str());
    if(disco::existeCarpeta(ruta)==1){
        FILE *fileC;

        fileC= fopen(ruta,"rb+");
        rewind(fileC);

        MBR mbrtemp;
        fread(&mbrtemp,sizeof(MBR),1,fileC);

        if(fileC!=nullptr){
            for(int i = 0; i < 4;i++){
                if(mbrtemp.mbr_partition[i].part_status == 'V'){
                    if(strcmp(mbrtemp.mbr_partition[i].part_name,nom)==0){
                        return 1;
                    }
                }
            }
        }
        fclose(fileC);
    }
    return 0;
}

/*
void fdisk::extenderParticion(fdisk *disco, int cantidad) {

    //int tam_extension;
    FILE *archivo;
    archivo = fopen(disco->getRuta().c_str(), "rb+");

    if(archivo == NULL){
        cout << " >> Archivo no encontrado. \n";
    }

    // Tamaño del disco
    fseek(archivo, 0L, SEEK_END);
    long int tamanioArchivo = ftell(archivo);

    mbr mbr_tmp;
    fseek(archivo, 0, SEEK_SET);
    fread(&mbr_tmp, sizeof(mbr), 1, archivo);


    // la cantidad a extender es mayor a la del disco
    if(cantidad >= tamanioArchivo){
        cout << " >> La particion no se puede extender, la cantidad a extender es superior al tamanio del disco. \n";
    } else {
        for(int i = 0; i < 4; i++){
            if(strcmp(mbr_tmp.mbr_particions[i].part_name, disco->getNombre().c_str()) == 0){

                if(disco->getUnidad() == "m" || disco->getUnidad() == "M"){
                    cantidad = cantidad*1024*1024;
                }else if(disco->getUnidad() == "k" || disco->getUnidad()  == "K"){
                    cantidad = cantidad*1024;
                }else if(disco->getUnidad() == "b" || disco->getUnidad() == "B"){

                }
                int tamanioActual = mbr_tmp.mbr_particions[i].part_size;
                mbr_tmp.mbr_particions[i].part_size = tamanioActual + cantidad;
                cout <<  mbr_tmp.mbr_particions[i].part_size << "\n";
                fseek(archivo, 0, SEEK_SET);
                fwrite(&mbr_tmp, sizeof(mbr), 1, archivo);
                cout << " >> La particion ha sido extendida. \n";
            }
        }
    }

    fclose(archivo);


}*/