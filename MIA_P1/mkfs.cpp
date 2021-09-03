#include "mkfs.h"
#include "mount.h"
void mkfs::Formato_ext2(string id, string tipo) {
    listMounted exis = mount::recorrerLista(id);

    if(exis.id == 500){
        cout<<"NO existe la particion indicada"<<endl;
        return;
    }

    FILE*archivo;
    archivo=fopen(exis.path.c_str(),"rb+");
    MBR mbr;
    rewind(archivo);
    fread(&mbr,sizeof(mbr),1,archivo);
    int inicio_P=0;
    int tam_P=0;
    string name;

    for (int i = 0; i < 4; i++)
    {
        if(mbr.mbr_partition[i].part_name==exis.listMountedPartitions[i].nombrePart){
            inicio_P=mbr.mbr_partition[i].part_start;
            tam_P=mbr.mbr_partition[i].part_size;
            name=mbr.mbr_partition[i].part_name;
            break;
        }
    }

    int n=0;
    cout<<"Se procedera a formatear la particion: "<<name<<endl;
    n=(tam_P-sizeof(SuperBloque))/(4+sizeof(Inodo)+3*64);

    int Ninodos=n;
    int Nbloques=3*n;
    int Bitinodos=n;
    int Bitbloques=3*n;

    if(tipo=="full"){
        char nul='0';
        for (int i = 0; i < tam_P; i++)
        {
            fwrite(&nul,sizeof(nul),1,archivo);
            fseek(archivo,inicio_P+i,SEEK_SET);
        }

    }

    time_t tiempo = time(0);
    struct tm *tlocal = localtime(&tiempo);
    char fechaActual[16];
    strftime(fechaActual,16,"%d/%m/%y %H:%M:%S",tlocal);

    SuperBloque Sbloque;
    //SuperBloque Sbloque2;
    //fseek(archivo,inicio_P,SEEK_SET);


    Sbloque.s_filesystem_type=2;
    Sbloque.s_inodes_count=0;
    Sbloque.s_blocks_count=0;
    Sbloque.s_free_blocks_count = n*3;
    Sbloque.s_free_inodes_count=n;
    strcpy(Sbloque.s_mtime,fechaActual);
    strcpy(Sbloque.s_umtime,"");
    Sbloque.s_mnt_count=0;
    Sbloque.s_magic=0xEF53;
    Sbloque.s_inode_size=sizeof(Inodo);
    Sbloque.s_block_size=sizeof(BloqueArchivos);
    Sbloque.s_first_ino=2;
    Sbloque.s_first_blo=2;
    Sbloque.s_bm_inode_start=tam_P+sizeof(SuperBloque);
    Sbloque.s_bm_block_start=Sbloque.s_bm_inode_start+n;
    Sbloque.s_inode_start=Sbloque.s_bm_block_start+3*n;
    Sbloque.s_block_start=Sbloque.s_inode_start+n*sizeof(Inodo);

    fseek(archivo,inicio_P,SEEK_SET);
    fwrite(&Sbloque,sizeof(SuperBloque),1,archivo);
    //fclose(archivo);
    //archivo=fopen(exis.path.c_str(),"rb+");
    fseek(archivo,inicio_P+sizeof(SuperBloque),SEEK_SET);
    //char ino[n];
    //char blo[3*n];
    //fread(&ino, sizeof(ino), 1, archivo);
    char inodos[n];
    char bloques[3*n];
    for (int i = 0; i < n; i++)
    {
        inodos[i]='0';
    }
    inodos[0]='1';
    inodos[1]='1';
    fwrite(&inodos,sizeof(inodos),1,archivo);
    fclose(archivo);
    archivo=fopen(exis.path.c_str(),"rb+");

    for (int i = 0; i < 3*n; i++)
    {
        bloques[i]='0';
    }
    bloques[0]='1';
    bloques[1]='1';
    fseek(archivo,inicio_P+sizeof(SuperBloque)+n,SEEK_SET);
    fwrite(&bloques,sizeof(bloques),1,archivo);
    fclose(archivo);
    archivo=fopen(exis.path.c_str(),"rb+");
    char blo[n];
    fseek(archivo,inicio_P+sizeof(SuperBloque)+n, SEEK_SET);
    fread(&blo, sizeof(blo), 1, archivo);

    //Toca crear la tabla de inodos y bloque de carpetas
    SuperBloque aux;
    fseek(archivo,inicio_P,SEEK_SET);
    fread(&aux,sizeof(SuperBloque),1,archivo);
    Inodo tablainodos;

    tablainodos.i_uid=1;
    tablainodos.i_gid=1;
    tablainodos.i_size=0;
    strcpy(tablainodos.i_atime,fechaActual);
    strcpy(tablainodos.i_ctime,fechaActual);
    strcpy(tablainodos.i_mtime,fechaActual);
    for (int i = 0; i < 15; i++)
    {
        tablainodos.i_block[i]=-1;
    }
    tablainodos.i_block[0]=0;

    tablainodos.i_type='0';
    tablainodos.i_perm=664;

    fseek(archivo,aux.s_inode_start,SEEK_SET);
    fwrite(&tablainodos,sizeof(tablainodos),1,archivo);
    aux.s_free_inodes_count--;
    aux.s_inodes_count++;

    BloqueCarpetas raiz;
    raiz.b_content[0].b_inodo=0;
    strcpy(raiz.b_content[0].b_name,".");
    raiz.b_content[1].b_inodo=0;
    strcpy(raiz.b_content[1].b_name,"..");
    raiz.b_content[2].b_inodo=1;
    strcpy(raiz.b_content[2].b_name,"user.txt");
    raiz.b_content[3].b_inodo=-1;
    strcpy(raiz.b_content[3].b_name,"--");

    fseek(archivo,aux.s_block_start,SEEK_SET);
    fwrite(&raiz,64,1,archivo);
    aux.s_free_blocks_count--;
    aux.s_blocks_count++;

    string content="1,G,root\n1,U,root,root,123\n";
    Inodo Narch;

    Narch.i_uid=1;
    Narch.i_gid=1;
    Narch.i_size=sizeof(content);
    strcpy(Narch.i_atime,fechaActual);
    strcpy(Narch.i_ctime,fechaActual);
    strcpy(Narch.i_mtime,fechaActual);
    for (int i = 0; i < 15; i++)
    {
        Narch.i_block[i]=-1;
    }
    Narch.i_type='1';
    Narch.i_perm=664;
    Narch.i_block[0]=1;
    fseek(archivo,(aux.s_inode_start+sizeof(Inodo)*aux.s_inodes_count),SEEK_SET);
    fwrite(&Narch,sizeof(Narch),1,archivo);
    aux.s_free_inodes_count--;
    aux.s_inodes_count++;
    BloqueArchivos NuevoArch;
    strcpy(NuevoArch.b_content,content.c_str());
    //formula para saber donde va el bloque o inodo: inicio bloque+sizeof(bloque)*countblock
    fseek(archivo,(aux.s_block_start+64*aux.s_blocks_count),SEEK_SET);
    fwrite(&NuevoArch,64,1,archivo);
    aux.s_free_blocks_count--;
    aux.s_blocks_count++;
    fseek(archivo,inicio_P,SEEK_SET);
    fwrite(&aux,sizeof(SuperBloque),1,archivo);
    fclose(archivo);
    cout<<"Partcion formateada en EXT2 existosamente."<<endl;
}

void mkfs::Formato_ext3(string id, string tipo) {
    listMounted exis = mount::recorrerLista(id);

    if(exis.id == 500){
        cout<<"NO existe la particion indicada"<<endl;
        return;
    }

    FILE*archivo;
    archivo=fopen(exis.path.c_str(),"rb+");
    MBR mbr;
    rewind(archivo);
    fread(&mbr,sizeof(mbr),1,archivo);
    int inicio_P=0;
    int tam_P=0;
    string name;

    for (int i = 0; i < 4; i++)
    {
        if(mbr.mbr_partition[i].part_name==exis.listMountedPartitions[i].nombrePart){
            inicio_P=mbr.mbr_partition[i].part_start;
            tam_P=mbr.mbr_partition[i].part_size;
            name=mbr.mbr_partition[i].part_name;
            break;
        }
    }

    int n=0;
    cout<<"Se procedera a formatear la particion: "<<name<<endl;
    int SB = sizeof(SuperBloque);
    int njournaling = 100*sizeof(BloqueCarpetas);
    int Tinodos = sizeof(Inodo);
    n=(tam_P-SB-njournaling)/(4+Tinodos+(3*64));

    int Ninodos=n;
    int Nbloques=3*n;
    int Bitinodos=n;
    int Bitbloques=3*n;


    if(tipo=="full"){
        char nul='0';
        for (int i = 0; i < tam_P; i++)
        {
            fwrite(&nul,sizeof(nul),1,archivo);
            fseek(archivo,inicio_P+i,SEEK_SET);
        }

    }

    time_t tiempo = time(0);
    struct tm *tlocal = localtime(&tiempo);
    char fechaActual[16];
    strftime(fechaActual,16,"%d/%m/%y %H:%M:%S",tlocal);

    SuperBloque Sbloque;
    Sbloque.s_filesystem_type=2;
    Sbloque.s_inodes_count=0;
    Sbloque.s_blocks_count=0;
    Sbloque.s_free_blocks_count = n*3;
    Sbloque.s_free_inodes_count=n;
    strcpy(Sbloque.s_mtime,fechaActual);
    strcpy(Sbloque.s_umtime,"");
    Sbloque.s_mnt_count=0;
    Sbloque.s_magic=0xEF53;
    Sbloque.s_inode_size=sizeof(Inodo);
    Sbloque.s_block_size=sizeof(BloqueArchivos);
    Sbloque.s_first_ino=2;
    Sbloque.s_first_blo=2;
    Sbloque.s_bm_inode_start=tam_P+sizeof(SuperBloque);
    Sbloque.s_bm_block_start=Sbloque.s_bm_inode_start+n;
    Sbloque.s_inode_start=Sbloque.s_bm_block_start+3*n;
    Sbloque.s_block_start=Sbloque.s_inode_start+n*sizeof(Inodo);

    journaling  journal;
    journal.estado = 0;
    journal.fecha_op[0] = '\0';
    journal.path[0] = '\0';
    journal.tipo ='-1';
    strcpy(journal.contenido,"--");
    journal.tamanio = 0;
    journal.tipo_op[0] = '\0';

    fseek(archivo,inicio_P,SEEK_SET);
    fwrite(&Sbloque,sizeof(SuperBloque),1,archivo);

    fseek(archivo,inicio_P + sizeof(SuperBloque),SEEK_SET);

    journaling journalCarpeta;
    journalCarpeta.estado = 1;
    strcpy(journalCarpeta.tipo_op, "mkfs");
    strcpy(journalCarpeta.fecha_op, fechaActual);
    strcpy(journalCarpeta.path, "/");
    journalCarpeta.id_propietario = '1';
    strcpy(journalCarpeta.contenido, "-");
    journalCarpeta.tipo = '0';

    int journal_inic = inicio_P + sizeof(SuperBloque);

    journaling journalArchivo;
    journalArchivo.estado = 1;
    strcpy(journalArchivo.tipo_op, "mkfs");
    strcpy(journalArchivo.fecha_op, fechaActual);
    strcpy(journalArchivo.path, "/user.txt");
    journalArchivo.id_propietario = '1';
    strcpy(journalArchivo.contenido, "1,G,root\n1,U,root,root,123\n");
    journalArchivo.tipo = '1';

    for(int i = 0; i < njournaling;i++){
        if(i == 0){
            fseek(archivo,journal_inic,SEEK_SET);
            fwrite(&journalCarpeta,sizeof(journaling),1,archivo);
        }else if(i == 1){
            fseek(archivo,journal_inic,SEEK_SET);
            fwrite(&journalCarpeta,sizeof(journaling),1,archivo);
        }else if(i > 1){
            fseek(archivo,journal_inic+i*sizeof(journaling),SEEK_SET);
            fwrite(&journalCarpeta,sizeof(journaling),1,archivo);
        }
    }

    char inodos[n];
    char bloques[3*n];

    // lleno los inodos
    for(int i = 0; i < n; i++ ){
        inodos[i] = '0';
    }

    inodos[0] = '1';
    inodos[1] = '1';
    fseek(archivo, inicio_P + sizeof(SuperBloque)+njournaling*(sizeof(journaling)), SEEK_SET);
    fwrite(&inodos, sizeof(inodos), 1, archivo);


    for(int i = 0; i < 3*n; i++){
        bloques[i] = '0';
    }

    bloques[0] = '1';
    bloques[1] = '1';

    cout << " 3. " << inicio_P + sizeof(SuperBloque)+njournaling*sizeof(journaling)+Bitinodos*sizeof(char) << "\n";
    fseek(archivo, inicio_P + sizeof(SuperBloque)+njournaling*sizeof(journaling)+Bitinodos*sizeof(char), SEEK_SET);
    //fseek(archivo, super_b.s_bm_block_start, SEEK_SET);
    fwrite(&bloques, sizeof(bloques), 1, archivo);
    SuperBloque sb_aux;
    fseek(archivo, inicio_P, SEEK_SET);
    fread(&sb_aux, sizeof(SuperBloque), 1, archivo);

    // TABLA DE INODOS RAIZ
    Inodo tInodo;
    tInodo.i_uid = 1;
    tInodo.i_gid = 1;
    tInodo.i_size = 0;
    strcpy(tInodo.i_ctime, fechaActual);
    strcpy(tInodo.i_atime, fechaActual);
    strcpy(tInodo.i_mtime, fechaActual);
    for(int i = 0; i < 15; i++){
        tInodo.i_block[i] = -1;
        if(i == 14){
            tInodo.i_block[i] = -1;
        }
    }
    tInodo.i_type = '0';
    tInodo.i_perm = 664; // Guarda los permisos del archivo / carpeta
    tInodo.i_block[0] = 0;

    // ARREGLO DE BLOQUES

    BloqueCarpetas bl_carpeta;
    Content bl_content;
    bl_content.b_name[0] = '-';
    bl_content.b_inodo = 0;

    for(int i = 0; i < 4; i++){
        bl_carpeta.b_content[i] = bl_content;
    }

    // ESTRUCTURA DE LOS ARCHIVOS QUE VAN EN LA RAIZ
    BloqueCarpetas bloque_root;
    string nombre_archivo = "users.txt";
    string un_punto = ".";
    string dos_puntos = "..";
    string dir_raiz = "/";
    // primera posicion
    bloque_root.b_content[0].b_inodo = 0;
    strcpy(bloque_root.b_content[0].b_name, un_punto.c_str());
    // segunda posicion
    bloque_root.b_content[1].b_inodo = 0;
    strcpy(bloque_root.b_content[1].b_name, dos_puntos.c_str());
    // tercera posicion
    bloque_root.b_content[2].b_inodo = 1;
    strcpy(bloque_root.b_content[2].b_name, nombre_archivo.c_str());
    // cuarta posicion
    bloque_root.b_content[3].b_inodo = -1;
    strcpy(bloque_root.b_content[3].b_name, dir_raiz.c_str());

    fseek(archivo, sb_aux.s_inode_start, SEEK_SET);
    fwrite(&tInodo, sizeof(Inodo), 1, archivo); // escribiendo inodo raiz

    fseek(archivo, sb_aux.s_block_start, SEEK_SET);
    fwrite(&bloque_root, 64,1, archivo);

    // posicionarme al inicio de la particion
    fseek(archivo, inicio_P, SEEK_SET);
    // restar la cantidad de bloques e inodos libres
    //sb_aux.s_free_blocks_count--;
    sb_aux.s_free_inodes_count--;
    fwrite(&sb_aux, sizeof(SuperBloque), 1, archivo);


    //
    string contenido = "1,G,root\n1,U,root,root,123\n";
    Inodo archivo_usuarios;// inodo del archivo de usuarios
    archivo_usuarios.i_gid = 1;
    archivo_usuarios.i_uid = 1;
    archivo_usuarios.i_size = sizeof(contenido);
    strcpy(archivo_usuarios.i_atime, fechaActual);
    strcpy(archivo_usuarios.i_ctime, fechaActual);
    strcpy(archivo_usuarios.i_mtime, fechaActual);

    for(int i = 0; i < 15; i++){
        archivo_usuarios.i_block[i] = -1;
    }

    archivo_usuarios.i_perm = 664;
    archivo_usuarios.i_block[0] = 1;
    archivo_usuarios.i_type = '1';// inodo de tipo archivo


    BloqueArchivos bl_archivo;
    strcpy(bl_archivo.b_content, contenido.c_str());

    fseek(archivo, sb_aux.s_bm_inode_start+sizeof(Inodo), SEEK_SET);
    fwrite(&archivo_usuarios,sizeof(Inodo),1, archivo);

    fseek(archivo, sb_aux.s_block_start + 64, SEEK_SET);
    fwrite(&bl_archivo, 64, 1, archivo);

    fseek(archivo, inicio_P, SEEK_SET);
    // restar la cantidad de bloques e inodos libres
    sb_aux.s_free_inodes_count--;
    sb_aux.s_free_blocks_count--; // resto el bloque de carpeta
    sb_aux.s_free_blocks_count--; // resto el bloque de archivos
    fwrite(&sb_aux, sizeof(SuperBloque), 1, archivo);


    fseek(archivo, inicio_P, SEEK_SET);
    fread(&sb_aux, sizeof(SuperBloque), 1, archivo);
    journaling j;
    fseek(archivo, inicio_P+sizeof(SuperBloque), SEEK_SET);
    fread(&j, sizeof(journaling), 1, archivo);
    char in[n];
    fseek(archivo, inicio_P+sizeof(SuperBloque)+6400, SEEK_SET);
    fread(&in, sizeof(in), 1, archivo);
    cout << " >> Particion formateada en EXT3. \n";
    fclose(archivo);
}