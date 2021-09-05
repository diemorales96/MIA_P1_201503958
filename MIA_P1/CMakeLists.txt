cmake_minimum_required(VERSION 3.20)
project(MIA_P1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(MIA_P1
        main.cpp
        parser.cpp
        parser.h
        scanner.cpp
        scanner.h disco.cpp disco.h fdisk.cpp fdisk.h comexec.cpp comexec.h mount.cpp mount.h mkfs.cpp mkfs.h mkdir.cpp mkdir.h touch.cpp touch.h chmod.cpp chmod.h ren.cpp ren.h move.cpp move.h cat.cpp cat.h login.cpp login.h find.cpp find.h arbol.cpp arbol.h)
