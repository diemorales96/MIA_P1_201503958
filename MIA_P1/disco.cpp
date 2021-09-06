#include "disco.h"
#include "mount.h"
#include "mkdir.h"
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

void disco::repoteMBR(string id, string path){
    vector<listMounted> disco;
    listMounted aux = mount::recorrerLista(id);
    FILE *archivo;
    archivo = fopen(aux.path.c_str(),"rb");
    vector<string> f;
    f = mkdir::split(aux.path,'/');
    string r = f[f.size()-1];
    MBR mbr;
    rewind(archivo);
    fread(&mbr,sizeof(MBR),1,archivo);

    string date(mbr.mbr_fecha_creacin);
    string fit(1, mbr.disk_fit);

    string grafo = "digraph MBR{\n";
    grafo += "  nodesep=.05\n";
    grafo += "rankdir=LR\n";
    grafo += "node [shape=record,width=.1,height=.1]\n";
    grafo += "Nodo0 [label = \" MBR ";
    grafo += r + "| {NOMBRE | VALOR}|";
    grafo += "{ mbr_tamaño | "+ to_string(mbr.mbr_tamano) +" }|";
    grafo += "{ mbr_fecha  | "+ date  +" }|";
    grafo += "{ mbr_signature | "+ to_string(mbr.mbr_disk_signature) +" }|";
    grafo += "{ mbr_fit | "+ fit +" }|";


    for(int i = 0; i < 4; i++){
        string status(1, mbr.mbr_partition[i].part_status);
        string D_type(1, mbr.mbr_partition[i].part_type);
        if (mbr.mbr_partition[i].part_status == 'V'){
            string nombre(mbr.mbr_partition[i].part_name);
            grafo += "DISCO"+ to_string(i +1) +"|";
            grafo += "{part_status | "+ status +" }|";
            grafo += "{part_type | "+ D_type +" }|";
            grafo += "{part_start | "+ to_string(mbr.mbr_partition[i].part_start) +" }|";
            grafo += "{part_size | "+ to_string(mbr.mbr_partition[i].part_size) +" }|";
            grafo += "{part_name | "+ nombre +" }";
        }
    }
    grafo += "\"]\n}";

    string cc = "dot -Tpng archivoDot1.dot -o " ;
    cc += path;

    cout <<grafo << endl;

    char ru[500];
    strcpy(ru, cc.c_str());
    cout << "ru: " << ru << endl;

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
    cout << ccc << endl;
    string s(rut);
    string comando = "eog " + s;
    const char *cmd2 = comando.c_str();
    system(cmd2);
    fclose(archivo);
    getchar();


}



void disco::reporteDisco(string id, string path){
    vector<listMounted> disco;
    listMounted aux = mount::recorrerLista(id);
    FILE *archivo;
    archivo = fopen(aux.path.c_str(),"rb");
    vector<string> f;
    f = mkdir::split(aux.path,'/');
    string r = f[f.size()-1];
    MBR mbr;
    rewind(archivo);
    fread(&mbr,sizeof(MBR),1,archivo);
    generarGraficaDisk(mbr,path,aux.path,archivo);
}

void disco::generarGraficaDisk(MBR &mbr, string destino, string disco,FILE *archivo) {
    string cadena = "";
    int sizeMBR = sizeof(mbr)+1;
    cadena += "digraph DISK{\n";
    cadena += "    Disk[\n";
    cadena += "    shape=plaintext\n";
    cadena += "    label=<\n";
    cadena += "    <table border='1' cellborder='1'>\n";
    cadena += "    <tr><td>MBR</td>\n";
    double ocupado = 0.0;
    int revisado = sizeMBR;
    for(int i = 0;i < 4; i++){
        if (i > 0){
            if (revisado+1 < mbr.mbr_partition[i].part_start) {
                int espacio = mbr.mbr_partition[i].part_start - revisado;
                double porcentaje = obtenerPorcentaje(espacio,(mbr.mbr_tamano-sizeMBR));
                ocupado +=porcentaje;
                cadena += "     <td> LIBRE<br/>" + to_string(porcentaje)+"%</td>\n";
                revisado += espacio;
            }

        }

        if(mbr.mbr_partition[i].part_status == 'F'){
            cadena += "     <td>PART" + to_string(i+1) + "<br/>0%</td>\n";
        }else{
            double porcentaje = obtenerPorcentaje(mbr.mbr_partition[i].part_size,mbr.mbr_tamano-sizeMBR);
            if(mbr.mbr_partition[i].part_type == 'P'){
                if(porcentaje > 0){
                    cadena += "     <td>" + string(mbr.mbr_partition[i].part_name) + "(Primaria)<br/>";
                    cadena += "     <br/>" + to_string(porcentaje)+ "%</td>\n";
                    ocupado += porcentaje;
                    revisado += mbr.mbr_partition[i].part_size;
                }
            }else{
                cadena += "     <td>\n";
                cadena += "     <table border = '1' cellborder = '1'>\n";
                cadena += "      <tr>\n";
                cadena += "     <td>"+ string(mbr.mbr_partition[i].part_name) + "(EXTENDIDA)<br/>";
                cadena += "     <br/>" + to_string(porcentaje)+ "%</td></tr>\n";
                ocupado += porcentaje;
                revisado += mbr.mbr_partition[i].part_size;
                EBR ebr;
                fseek(archivo,mbr.mbr_partition[i].part_start , SEEK_SET);
                fread(&ebr, sizeof(EBR), 1, archivo);
                cadena += "        <tr><td>\n";
                cadena += "            <table border = '1' cellborder = '1'>\n";
                cadena += "            <tr>\n";
                int inicio = 0;
                while(true){
                    cadena+= "      <td>EBR</td>\n";
                    if(ebr.part_status=='F'){
                        break;
                    }
                    cadena+= "      <td>LOGICA - " + string(ebr.part_name);
                    cadena += "            </td>\n";
                    if(ebr.part_next == -1){
                        break;
                    }
                    inicio = ebr.part_next;
                    fseek(archivo,inicio, SEEK_SET);
                    fread(&ebr, sizeof(EBR), 1, archivo);
                }
                cadena += "        </tr></table>\n";
                cadena += "        </td>\n";
                cadena += "        </tr>\n";
                cadena += "        </table>\n";
                cadena += "        </td>\n";
            }
        }
    }
    if(ocupado < 100){
        double libre = 100 - ocupado;
        cadena += "     <td>LIBRE <br/>" + to_string(libre) + "%</td>\n";
    }
    cadena += "    </tr>";
    cadena += "    </table>\n";
    cadena += "    >];\n";
    cadena += "}";

    cout<< cadena<<endl;
    string cc = "dot -Tpng archivoDot1.dot -o " ;
    cc += destino;

    cout <<cadena << endl;

    char ru[500];
    strcpy(ru, cc.c_str());
    cout << "ru: " << ru << endl;

    ofstream file;
    file.open("archivoDot1.dot");
    file << cadena;
    file.close();
    system(ru);

    string ccc ="nohup display ";
    ccc+= destino;
    ccc+= " &";

    char rut[500];
    strcpy(rut, ccc.c_str());
    cout << ccc << endl;
    string s(rut);
    string comando = "eog " + s;
    const char *cmd2 = comando.c_str();
    system(cmd2);
    fclose(archivo);
    getchar();



}

double disco::obtenerPorcentaje(int tamanio, int tamanioTotal) {
    double ftam = tamanio;
    double ftamTotal = tamanioTotal;
    double res = (ftam *100)/ftamTotal;
    return res;
}