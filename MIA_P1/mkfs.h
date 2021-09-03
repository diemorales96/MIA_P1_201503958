
#ifndef MIA_P1_MKFS_H
#define MIA_P1_MKFS_H
#include <iostream>
#include "string.h"
#include <time.h>

using namespace std;

typedef struct SuperBloque{
    int s_filesystem_type = 0;
    int s_inodes_count = 0;
    int s_blocks_count = 0;
    int s_free_blocks_count = 0;
    int s_free_inodes_count = 0;
    char s_mtime [25];
    char s_umtime [25];
    int  s_mnt_count = 0;
    int s_magic = 0;
    int s_inode_size = 0;
    int s_block_size = 0;
    int s_first_ino = 0;
    int s_first_blo = 0;
    int s_bm_inode_start = 0;
    int s_bm_block_start = 0;
    int s_inode_start = 0;
    int s_block_start = 0;
}SuperBloque;

typedef struct Inodo{
    int i_uid = 0;
    int i_gid = 0;
    int i_size  = 0;
    char i_atime [25];
    char i_ctime [25];
    char i_mtime [25];
    int i_block [15];
    char i_type;
    int i_perm = 0;
}Inodo;

typedef struct Content{
    char b_name [12];
    int b_inodo;
}Content;

typedef struct BloqueCarpetas{
    Content b_content [4];
}BloqueCarpetas;

typedef struct BloqueArchivos{
    char b_content [64];
}BloqueArchivos;

typedef struct BloqueApuntadores{
    int b_pointers [16];
}BloqueApuntadores;

typedef struct {
    int estado;
    char tipo_op[10];
    char tipo;
    char path[100];
    char fecha_op[25];
    char contenido[100];
    char id_propietario;
    int tamanio;
} journaling;


class mkfs {
public:
    static void Formato_ext2(string id,string tipo);
    static void Formato_ext3(string id,string tipo);
};



#endif //MIA_P1_MKFS_H
