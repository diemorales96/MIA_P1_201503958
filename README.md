# MIA_P1_201503958
##Proyecto 1 Archivos 2021 Segundo Semestre
El proyecto consiste en la realización de un sistema de archivos, este es manejado por 
comandos en consola. En este se utilizó el lenguaje c++.

###MKDISK (Creacion de Discos):
para poder utilizar este comando es necesario tener en cuenta que se pueden utilizar ciertos parametros, el tipo de estos discos sera ".dsk". por ejemplo:

1. -size: se usa para indicar el tamaño del disco.
2. -f: se utiliza para indicar el fit del disco.
3. -u: se utiliza para indicar la unidad que tendra un disco (Megabytes, Kilobytes).
4. -path: se utiliza para indicar la direccion en donde se guardara el disco.

algunos ejemplos serian los siguientes:

####Mkdisk -Size=3000 -u=K -path=/home/user/Disco1.disk

Este comando crearia un disco de tamaño de 3000 Kibytes en la direccion y el nombre especificados en el parametro path.

####mkdisk -size=5 -u=M -path="/home/mis discos/Disco3.disk"

Este comando crea un disco de 5 Megabytes con el nombre y en la direccion especificada en el comando path.

###RMDISK (Eliminacion de Discos):
Este comando tiene como parametro unico el parametro path. Algunos ejemplos serian los siguientes:

####rmDisk -path="/home/mis discos/Disco4.d.isk"

este eliminarana el Disco4.

####rmDisk -path="/home/Disco3.disk" 

este eliminarana el Disco3.

###FDISK (Formato de un Disco):
Este comando sirve para crear particiones primarias/extendidas/logicas. Ademas de poder crear particiones se puede agregar tamaño a un a particion o bien se puede quitar tamaño de esta utilizando los diferentes parametros que tiene los cuales son:

1. -size: este parametro indica el tamaño que tendra la particion.
2. -u: este parametro indica la unidad de la particion (Megabytes,kilobytes).
3. -path: indida el disco en el que se va a crear la particion.
4. -type: este indica que tipo de particion a agregar (P/E/L).
5. -f: este indica el tipo de fit utilizado en la particion que se va a crear (FF,BF,WF).
6. -delete: este se usa para poder eliminar una particion.
7. -name: indica el nombre que tendra el disco que se va a crear.
8. -add: este comando se utiliza para agregar o para quitar espacio a una particion.

Algundo ejemplos son:

####fdisk –Size=300 –path=/home/Disco1.disk –name=Particion1

este comando crea una particion de tipo primaria por defecto y de espacio 300 megabytes con el nombre particion 1 en el disco 1


###MOUNT (Montar las particiones en memoria):
Este carga en memoria las particiones que se indique y les coloca un id. Coloca un correlativo con los primeros dos digitos del carnet, por ejemplo 581a.

Ejmeplo:

####mount -path=/home/Disco1.disk -name=Part1

esto deberia imprimir una salida de la siguiente manera:
/home/Disco1.disk|Part1|581a

###UNMOUNT (Desmontar particiones):
Este comando solamente elimina de la lista una particion montada. Por ejemplo:

####umount -id=581a

Desmonta la particion que esta montada en el 1a.

###MKFS (Formatear una particion):
Este comando formatea una particion en tipo ext2 o ext3, la diferencia es que una contiene journaling y la otra no lo tiene. por ejemplo:

####mkfs -type=fast -id=581a

Este comando formate de manera fast el disco 581a y usa un formato ext2 por defecto.

###Login (Ingreso a un disco con un usuario):
Este ingresa un usuario al sistema de un disco para poder realizar operaciones como crear carpetas o archivos.

####login -usr=root -pwd=123 -id= 581a

###Logout (Sale del sistema un usuario ingresado en el login):
