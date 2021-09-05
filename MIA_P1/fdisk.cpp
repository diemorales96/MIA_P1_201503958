
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
            FILE *archivo;
            char ruta[500];
            strcpy(ruta, pat.c_str());
            archivo = fopen(ruta,"rb+");
            MBR mbr;
            rewind(archivo);
            fread(&mbr,sizeof(MBR),1,archivo);

            for(int i =0; i < 4; i++){
                if(mbr.mbr_partition[i].part_status == 'V' && mbr.mbr_partition[i].part_type=='E'){
                    crearLogica(archivo,mbr.mbr_partition[i].part_start,mbr.mbr_tamano,uni,fit,typ,nam,tama);
                    fclose(archivo);
                    return;

                }
            }

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
//|EBR1|LOGICA|EBR2|
void fdisk::crearLogica(FILE *archivo, int inicio, int total,string uni,char fi,string typ,string nam , int tamanio_particion)
{
    EBR ebr;
    fseek(archivo, inicio, SEEK_SET);
    fread(&ebr, sizeof(EBR), 1, archivo);

    if (ebr.part_status == 'F')
    {
        //Se escribe el estado la particion
        ebr.part_status = 'V';

        //Tipo de fit
        if (fi == 'B' || fi == 'b' || fi == 'bf')
        {
            ebr.part_fit = 'B';
        }
        else if (fi == 'F' || fi == 'f' || fi == 'ff')
        {
            ebr.part_fit = 'F';
        }
        else if (fi == 'W' || fi == 'w' || fi == 'wf')
        {
            ebr.part_fit = 'W';
        }
        else
        {
            cout << "No se eligió un tipo de ajuste, La entrada fue: \"" << typ << "\"" << endl;
        }

        //Se escribe donde empieza la particion
        ebr.par_start = inicio + sizeof(EBR);
        //En caso de que el ebr sea el ultimo de la lista
        if (ebr.part_next == -1)
        {
            //Se escribe el tamaño de la particion

            ebr.part_size = tamanio_particion;

            //Se verifica si hay espacio para la particion
            if ((ebr.part_size + ebr.par_start) <= total)
            {
                //Se escribe donde sigue el otro ebr
                ebr.part_next = ebr.par_start + ebr.part_size;
            }
            else
            {
                cout << "La partición: \"" << nam << "\" sobrepasa el espacio disponible" << endl;
                return;
            }

            //Se escribe el nombre de la particion
            strcpy(ebr.part_name, nam.c_str());

            cout << "Partición: \"" << nam << "\" creada" << endl;

            //Se modifica el EBR
            fseek(archivo, inicio, SEEK_SET);
            fwrite(&ebr, sizeof(EBR), 1, archivo);

            //Se crea el siguiente EBR
            EBR ebr_siguiente;
            ebr_siguiente.part_fit = '-';
            ebr_siguiente.part_next = -1;
            ebr_siguiente.part_size = -1;
            ebr_siguiente.par_start = -1;
            ebr_siguiente.part_status = 'F';
            ebr_siguiente.part_name[0] = '\0';
            fseek(archivo, ebr.part_next, SEEK_SET);
            fwrite(&ebr_siguiente, sizeof(EBR), 1, archivo);
        }
            //Este es en caso de que el ebr se encuentre entre otro
        else
        {
            //Se crea el siguiente EBR
            EBR ebr_siguiente;
            ebr_siguiente.part_fit = '-';
            ebr_siguiente.part_next = -1;
            ebr_siguiente.part_size = -1;
            ebr_siguiente.par_start = -1;
            ebr_siguiente.part_status = 'F';
            ebr_siguiente.part_name[0] = '\0';

            //Se verifica si se usa todo el espacio
            if (tamanio_particion == ebr.part_size)
            {
                strcpy(ebr.part_name, nam.c_str());

                cout << "Partición: \"" << nam << "\" creada" << endl;

                //Se modifica el EBR
                fseek(archivo, inicio, SEEK_SET);
                fwrite(&ebr, sizeof(EBR), 1, archivo);
            }
                //En caso de que sea menor, entonces se divide en 2
            else if (tamanio_particion < ebr.part_size)
            {
                //Se crea el ebr siguiente para no perder la conexion
                ebr_siguiente.part_next = ebr.part_next;
                ebr_siguiente.par_start = ebr.par_start + tamanio_particion + sizeof(EBR);
                ebr_siguiente.part_size = ebr.part_next - ebr_siguiente.par_start;

                //Se escribe el nombre de la particion
                strcpy(ebr.part_name, nam.c_str());

                //Se escribe el espacio de la particion
                ebr.part_size = tamanio_particion;

                //Se escribe el siguiente de la particion
                ebr.part_next = ebr_siguiente.par_start - sizeof(EBR);

                cout << "Partición: \"" << nam << "\" creada" << endl;

                //Se modifica el EBR
                fseek(archivo, inicio, SEEK_SET);
                fwrite(&ebr, sizeof(EBR), 1, archivo);

                fseek(archivo, ebr.part_next, SEEK_SET);
                fwrite(&ebr_siguiente, sizeof(EBR), 1, archivo);
            }
            else
            {
                cout << "La partición: \"" << nam << "\" sobrepasa el espacio disponible" << endl;
                return;
            }
        }
    }
    else{
        crearLogica(archivo, ebr.part_next, total, uni,fi,typ,nam, tamanio_particion);
    }
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
