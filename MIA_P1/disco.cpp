#include "disco.h"

//************************************ Crear el Disco ************************************
void disco::crearDisco(string tamanio, string unidad, string fit, string path)
{
    cout << "Disco de tamaño " << tamanio  << ","<<unidad<<","<<fit<<","<<path <<"."<< endl;
    bool error = false;
    int size = atoi(tamanio.c_str());
    if(verificarExtension(path) == false){
        cout <<"------------Extension incorrecta-----------"<<endl;
        error = true;
    }
    if((strcmp(unidad.c_str(),"k")==0)||(strcmp(unidad.c_str(),"m")==0)){
        error = false;
    }else{
        error = true;
        cout<<"Error en la unidad seleccionada, unidad no valida"<<endl;
    }
    if(error == false){
        //PATH
        const char * c = path.c_str();

        //UNIDAD

        long int unit = 0;

        char nul = '\0';
        if(unidad == "k"){
            unit = 1024;
        }else{
            unit  = 1024*1024;
        }
        crearDirectorio(path);
        FILE *fileCrear;
        fileCrear = fopen(c,"wb+");
        fclose(fileCrear);

        FILE *fileC;
        fileC = fopen(c, "rb+");
        rewind(fileC);
        long int tam = atoi(tamanio.c_str()) * unit;
        for(int var = 0; var < (tam); var++){
            fwrite(&nul,sizeof (nul),1,fileC);
        }
        fclose(fileC);


        MBR mbr;
        mbr.mbr_tamano = tam;

        char fecha[25];
        f(fecha);

        strcpy(mbr.mbr_fecha_creacin,fecha);
        mbr.mbr_disk_signature = aleatorio();

        if(fit=="ff"){
            mbr.disk_fit='F';
        }else if(fit =="bf"){
            mbr.disk_fit = 'B';
        }else{
            mbr.disk_fit = 'W';
        }

        for(int i = 0; i < 4;i++){
            mbr.mbr_partition[i].part_status = 'F';
        }

        fileC = fopen(c,"rb+");
        rewind(fileC);
        fwrite(&mbr,sizeof (MBR),1,fileC);
        fclose(fileC);

    }else{
        cout << "NO SE PUDO CREAR EL DISCO" << path << endl;
    }
}

string disco::quitarComillas(string path){
    char cad [500];
    strcpy(cad,path.c_str());
    int i = 0;
    int j=0;
    if(cad[0]=='"' && cad[strlen(cad)-1]=='"'){
        for(i=0;i<strlen(cad);i++){
            if(cad[i]!='"'){
                cad[j]=cad[i];
                j++;
            }
            if(i==(strlen(cad)-2)){
                cad[i]='\0';
            }
        }
    }
    return cad;
}

bool disco::verificarExtension(string path){
    char separador = '/';
    int cont = 0;
    string vector[40];
    string sentencia= path;

    for(size_t p=0, q=0; p!=sentencia.npos; p=q){
        vector[cont] = sentencia.substr(p+(p!=0),(q=sentencia.find(separador, p+1))-p-(p!=0));
        cont++;
    }

    string str = vector[cont-1];
    size_t found = str.find(".disk");
    if (found!=std::string::npos){
        cout << str <<endl;
        return  true;
    }
    else{
        return false;
    }
}

void disco::crearDirectorio(string path){
    cout<<"Ruta->"<<path<<endl;
    char separador = '/';
    int contador = 0;
    string vector[40];
    string sentencia= path;

    for(size_t p=0, q=0; p!=sentencia.npos; p=q){
        vector[contador] = sentencia.substr(p+(p!=0),(q=sentencia.find(separador, p+1))-p-(p!=0));
        contador++;
    }

    string nuevo = vector[0];
    contador--;
    for(int i = 1; i < contador; i++){
        nuevo += separador + vector[i];
    }

    char ruta[500];
    strcpy(ruta,nuevo.c_str());
    if(existeCarpeta(ruta) == 2){
        cout << "ERROR: NO EXISTE LA CARPETA SOLICITADA SE PROCEDERA A CREAR EN ->"<<ruta << endl;
        crearCarpeta(ruta);
    }
}

void disco::crearCarpeta(char ruta[]){
    char comando[500]=" mkdir \"";
    strcat(comando,ruta);
    strcat(comando,"\"");
    cout<<"comando ->"<<comando<<endl;
    system(comando);
}

int disco::existeCarpeta(char ruta[]){
    struct stat estado;
    if(stat(ruta,&estado)==-1){
        return 2;
    }else{
        return 1;
    }
}

void disco::f( char cadena[]){
    time_t tiempo = time(nullptr);
    struct tm *tlocal = localtime(&tiempo);
    strftime(cadena,128,"%d/%m/%y %H:%M:%S",tlocal);
}

int disco::aleatorio(){
    int numero;
    numero=rand()%(500-1+1)+1;
    return numero;
}

void disco::eliminarDisco(string path){
    char ruta[400];
    strcpy(ruta,path.c_str());
    int error = existeCarpeta(ruta);

    if (error == 1){
        string desicion = "N";
        cout <<"¿Esta seguro que desea borrar el disco "<<path << " ? (s)(n)"<< endl;
        cout << "DESICIÓN: " ;
        cin >> desicion;
        if(desicion == ("s") ){
            cout << "AVISO: Se procedera a eliminar el disco" << endl;
            remove(path.c_str());
        }else {
            cout << "AVISO: No se borra el disco " << endl;
        }
    }
    else{
        cout << "ERROR: El disco "<< path<< "no existe o el directorio es incorrecto" << endl;
    }
}