# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/diego/Escritorio/Clion/clion-2021.2/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/diego/Escritorio/Clion/clion-2021.2/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/diego/Escritorio/Proyectos/MIA_P1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/diego/Escritorio/Proyectos/MIA_P1/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/MIA_P1.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/MIA_P1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MIA_P1.dir/flags.make

CMakeFiles/MIA_P1.dir/main.cpp.o: CMakeFiles/MIA_P1.dir/flags.make
CMakeFiles/MIA_P1.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/diego/Escritorio/Proyectos/MIA_P1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MIA_P1.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MIA_P1.dir/main.cpp.o -c /home/diego/Escritorio/Proyectos/MIA_P1/main.cpp

CMakeFiles/MIA_P1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MIA_P1.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/diego/Escritorio/Proyectos/MIA_P1/main.cpp > CMakeFiles/MIA_P1.dir/main.cpp.i

CMakeFiles/MIA_P1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MIA_P1.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/diego/Escritorio/Proyectos/MIA_P1/main.cpp -o CMakeFiles/MIA_P1.dir/main.cpp.s

CMakeFiles/MIA_P1.dir/parser.cpp.o: CMakeFiles/MIA_P1.dir/flags.make
CMakeFiles/MIA_P1.dir/parser.cpp.o: ../parser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/diego/Escritorio/Proyectos/MIA_P1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/MIA_P1.dir/parser.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MIA_P1.dir/parser.cpp.o -c /home/diego/Escritorio/Proyectos/MIA_P1/parser.cpp

CMakeFiles/MIA_P1.dir/parser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MIA_P1.dir/parser.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/diego/Escritorio/Proyectos/MIA_P1/parser.cpp > CMakeFiles/MIA_P1.dir/parser.cpp.i

CMakeFiles/MIA_P1.dir/parser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MIA_P1.dir/parser.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/diego/Escritorio/Proyectos/MIA_P1/parser.cpp -o CMakeFiles/MIA_P1.dir/parser.cpp.s

CMakeFiles/MIA_P1.dir/scanner.cpp.o: CMakeFiles/MIA_P1.dir/flags.make
CMakeFiles/MIA_P1.dir/scanner.cpp.o: ../scanner.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/diego/Escritorio/Proyectos/MIA_P1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/MIA_P1.dir/scanner.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MIA_P1.dir/scanner.cpp.o -c /home/diego/Escritorio/Proyectos/MIA_P1/scanner.cpp

CMakeFiles/MIA_P1.dir/scanner.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MIA_P1.dir/scanner.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/diego/Escritorio/Proyectos/MIA_P1/scanner.cpp > CMakeFiles/MIA_P1.dir/scanner.cpp.i

CMakeFiles/MIA_P1.dir/scanner.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MIA_P1.dir/scanner.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/diego/Escritorio/Proyectos/MIA_P1/scanner.cpp -o CMakeFiles/MIA_P1.dir/scanner.cpp.s

CMakeFiles/MIA_P1.dir/disco.cpp.o: CMakeFiles/MIA_P1.dir/flags.make
CMakeFiles/MIA_P1.dir/disco.cpp.o: ../disco.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/diego/Escritorio/Proyectos/MIA_P1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/MIA_P1.dir/disco.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MIA_P1.dir/disco.cpp.o -c /home/diego/Escritorio/Proyectos/MIA_P1/disco.cpp

CMakeFiles/MIA_P1.dir/disco.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MIA_P1.dir/disco.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/diego/Escritorio/Proyectos/MIA_P1/disco.cpp > CMakeFiles/MIA_P1.dir/disco.cpp.i

CMakeFiles/MIA_P1.dir/disco.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MIA_P1.dir/disco.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/diego/Escritorio/Proyectos/MIA_P1/disco.cpp -o CMakeFiles/MIA_P1.dir/disco.cpp.s

CMakeFiles/MIA_P1.dir/fdisk.cpp.o: CMakeFiles/MIA_P1.dir/flags.make
CMakeFiles/MIA_P1.dir/fdisk.cpp.o: ../fdisk.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/diego/Escritorio/Proyectos/MIA_P1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/MIA_P1.dir/fdisk.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MIA_P1.dir/fdisk.cpp.o -c /home/diego/Escritorio/Proyectos/MIA_P1/fdisk.cpp

CMakeFiles/MIA_P1.dir/fdisk.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MIA_P1.dir/fdisk.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/diego/Escritorio/Proyectos/MIA_P1/fdisk.cpp > CMakeFiles/MIA_P1.dir/fdisk.cpp.i

CMakeFiles/MIA_P1.dir/fdisk.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MIA_P1.dir/fdisk.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/diego/Escritorio/Proyectos/MIA_P1/fdisk.cpp -o CMakeFiles/MIA_P1.dir/fdisk.cpp.s

CMakeFiles/MIA_P1.dir/comexec.cpp.o: CMakeFiles/MIA_P1.dir/flags.make
CMakeFiles/MIA_P1.dir/comexec.cpp.o: ../comexec.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/diego/Escritorio/Proyectos/MIA_P1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/MIA_P1.dir/comexec.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MIA_P1.dir/comexec.cpp.o -c /home/diego/Escritorio/Proyectos/MIA_P1/comexec.cpp

CMakeFiles/MIA_P1.dir/comexec.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MIA_P1.dir/comexec.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/diego/Escritorio/Proyectos/MIA_P1/comexec.cpp > CMakeFiles/MIA_P1.dir/comexec.cpp.i

CMakeFiles/MIA_P1.dir/comexec.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MIA_P1.dir/comexec.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/diego/Escritorio/Proyectos/MIA_P1/comexec.cpp -o CMakeFiles/MIA_P1.dir/comexec.cpp.s

CMakeFiles/MIA_P1.dir/mount.cpp.o: CMakeFiles/MIA_P1.dir/flags.make
CMakeFiles/MIA_P1.dir/mount.cpp.o: ../mount.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/diego/Escritorio/Proyectos/MIA_P1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/MIA_P1.dir/mount.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MIA_P1.dir/mount.cpp.o -c /home/diego/Escritorio/Proyectos/MIA_P1/mount.cpp

CMakeFiles/MIA_P1.dir/mount.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MIA_P1.dir/mount.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/diego/Escritorio/Proyectos/MIA_P1/mount.cpp > CMakeFiles/MIA_P1.dir/mount.cpp.i

CMakeFiles/MIA_P1.dir/mount.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MIA_P1.dir/mount.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/diego/Escritorio/Proyectos/MIA_P1/mount.cpp -o CMakeFiles/MIA_P1.dir/mount.cpp.s

CMakeFiles/MIA_P1.dir/mkfs.cpp.o: CMakeFiles/MIA_P1.dir/flags.make
CMakeFiles/MIA_P1.dir/mkfs.cpp.o: ../mkfs.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/diego/Escritorio/Proyectos/MIA_P1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/MIA_P1.dir/mkfs.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MIA_P1.dir/mkfs.cpp.o -c /home/diego/Escritorio/Proyectos/MIA_P1/mkfs.cpp

CMakeFiles/MIA_P1.dir/mkfs.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MIA_P1.dir/mkfs.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/diego/Escritorio/Proyectos/MIA_P1/mkfs.cpp > CMakeFiles/MIA_P1.dir/mkfs.cpp.i

CMakeFiles/MIA_P1.dir/mkfs.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MIA_P1.dir/mkfs.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/diego/Escritorio/Proyectos/MIA_P1/mkfs.cpp -o CMakeFiles/MIA_P1.dir/mkfs.cpp.s

CMakeFiles/MIA_P1.dir/mkdir.cpp.o: CMakeFiles/MIA_P1.dir/flags.make
CMakeFiles/MIA_P1.dir/mkdir.cpp.o: ../mkdir.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/diego/Escritorio/Proyectos/MIA_P1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/MIA_P1.dir/mkdir.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MIA_P1.dir/mkdir.cpp.o -c /home/diego/Escritorio/Proyectos/MIA_P1/mkdir.cpp

CMakeFiles/MIA_P1.dir/mkdir.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MIA_P1.dir/mkdir.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/diego/Escritorio/Proyectos/MIA_P1/mkdir.cpp > CMakeFiles/MIA_P1.dir/mkdir.cpp.i

CMakeFiles/MIA_P1.dir/mkdir.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MIA_P1.dir/mkdir.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/diego/Escritorio/Proyectos/MIA_P1/mkdir.cpp -o CMakeFiles/MIA_P1.dir/mkdir.cpp.s

CMakeFiles/MIA_P1.dir/touch.cpp.o: CMakeFiles/MIA_P1.dir/flags.make
CMakeFiles/MIA_P1.dir/touch.cpp.o: ../touch.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/diego/Escritorio/Proyectos/MIA_P1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/MIA_P1.dir/touch.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MIA_P1.dir/touch.cpp.o -c /home/diego/Escritorio/Proyectos/MIA_P1/touch.cpp

CMakeFiles/MIA_P1.dir/touch.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MIA_P1.dir/touch.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/diego/Escritorio/Proyectos/MIA_P1/touch.cpp > CMakeFiles/MIA_P1.dir/touch.cpp.i

CMakeFiles/MIA_P1.dir/touch.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MIA_P1.dir/touch.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/diego/Escritorio/Proyectos/MIA_P1/touch.cpp -o CMakeFiles/MIA_P1.dir/touch.cpp.s

CMakeFiles/MIA_P1.dir/chmod.cpp.o: CMakeFiles/MIA_P1.dir/flags.make
CMakeFiles/MIA_P1.dir/chmod.cpp.o: ../chmod.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/diego/Escritorio/Proyectos/MIA_P1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/MIA_P1.dir/chmod.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MIA_P1.dir/chmod.cpp.o -c /home/diego/Escritorio/Proyectos/MIA_P1/chmod.cpp

CMakeFiles/MIA_P1.dir/chmod.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MIA_P1.dir/chmod.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/diego/Escritorio/Proyectos/MIA_P1/chmod.cpp > CMakeFiles/MIA_P1.dir/chmod.cpp.i

CMakeFiles/MIA_P1.dir/chmod.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MIA_P1.dir/chmod.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/diego/Escritorio/Proyectos/MIA_P1/chmod.cpp -o CMakeFiles/MIA_P1.dir/chmod.cpp.s

CMakeFiles/MIA_P1.dir/ren.cpp.o: CMakeFiles/MIA_P1.dir/flags.make
CMakeFiles/MIA_P1.dir/ren.cpp.o: ../ren.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/diego/Escritorio/Proyectos/MIA_P1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/MIA_P1.dir/ren.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MIA_P1.dir/ren.cpp.o -c /home/diego/Escritorio/Proyectos/MIA_P1/ren.cpp

CMakeFiles/MIA_P1.dir/ren.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MIA_P1.dir/ren.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/diego/Escritorio/Proyectos/MIA_P1/ren.cpp > CMakeFiles/MIA_P1.dir/ren.cpp.i

CMakeFiles/MIA_P1.dir/ren.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MIA_P1.dir/ren.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/diego/Escritorio/Proyectos/MIA_P1/ren.cpp -o CMakeFiles/MIA_P1.dir/ren.cpp.s

CMakeFiles/MIA_P1.dir/move.cpp.o: CMakeFiles/MIA_P1.dir/flags.make
CMakeFiles/MIA_P1.dir/move.cpp.o: ../move.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/diego/Escritorio/Proyectos/MIA_P1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/MIA_P1.dir/move.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MIA_P1.dir/move.cpp.o -c /home/diego/Escritorio/Proyectos/MIA_P1/move.cpp

CMakeFiles/MIA_P1.dir/move.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MIA_P1.dir/move.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/diego/Escritorio/Proyectos/MIA_P1/move.cpp > CMakeFiles/MIA_P1.dir/move.cpp.i

CMakeFiles/MIA_P1.dir/move.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MIA_P1.dir/move.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/diego/Escritorio/Proyectos/MIA_P1/move.cpp -o CMakeFiles/MIA_P1.dir/move.cpp.s

CMakeFiles/MIA_P1.dir/cat.cpp.o: CMakeFiles/MIA_P1.dir/flags.make
CMakeFiles/MIA_P1.dir/cat.cpp.o: ../cat.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/diego/Escritorio/Proyectos/MIA_P1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/MIA_P1.dir/cat.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MIA_P1.dir/cat.cpp.o -c /home/diego/Escritorio/Proyectos/MIA_P1/cat.cpp

CMakeFiles/MIA_P1.dir/cat.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MIA_P1.dir/cat.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/diego/Escritorio/Proyectos/MIA_P1/cat.cpp > CMakeFiles/MIA_P1.dir/cat.cpp.i

CMakeFiles/MIA_P1.dir/cat.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MIA_P1.dir/cat.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/diego/Escritorio/Proyectos/MIA_P1/cat.cpp -o CMakeFiles/MIA_P1.dir/cat.cpp.s

CMakeFiles/MIA_P1.dir/find.cpp.o: CMakeFiles/MIA_P1.dir/flags.make
CMakeFiles/MIA_P1.dir/find.cpp.o: ../find.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/diego/Escritorio/Proyectos/MIA_P1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/MIA_P1.dir/find.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MIA_P1.dir/find.cpp.o -c /home/diego/Escritorio/Proyectos/MIA_P1/find.cpp

CMakeFiles/MIA_P1.dir/find.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MIA_P1.dir/find.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/diego/Escritorio/Proyectos/MIA_P1/find.cpp > CMakeFiles/MIA_P1.dir/find.cpp.i

CMakeFiles/MIA_P1.dir/find.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MIA_P1.dir/find.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/diego/Escritorio/Proyectos/MIA_P1/find.cpp -o CMakeFiles/MIA_P1.dir/find.cpp.s

CMakeFiles/MIA_P1.dir/arbol.cpp.o: CMakeFiles/MIA_P1.dir/flags.make
CMakeFiles/MIA_P1.dir/arbol.cpp.o: ../arbol.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/diego/Escritorio/Proyectos/MIA_P1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object CMakeFiles/MIA_P1.dir/arbol.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MIA_P1.dir/arbol.cpp.o -c /home/diego/Escritorio/Proyectos/MIA_P1/arbol.cpp

CMakeFiles/MIA_P1.dir/arbol.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MIA_P1.dir/arbol.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/diego/Escritorio/Proyectos/MIA_P1/arbol.cpp > CMakeFiles/MIA_P1.dir/arbol.cpp.i

CMakeFiles/MIA_P1.dir/arbol.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MIA_P1.dir/arbol.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/diego/Escritorio/Proyectos/MIA_P1/arbol.cpp -o CMakeFiles/MIA_P1.dir/arbol.cpp.s

CMakeFiles/MIA_P1.dir/inodos.cpp.o: CMakeFiles/MIA_P1.dir/flags.make
CMakeFiles/MIA_P1.dir/inodos.cpp.o: ../inodos.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/diego/Escritorio/Proyectos/MIA_P1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building CXX object CMakeFiles/MIA_P1.dir/inodos.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MIA_P1.dir/inodos.cpp.o -c /home/diego/Escritorio/Proyectos/MIA_P1/inodos.cpp

CMakeFiles/MIA_P1.dir/inodos.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MIA_P1.dir/inodos.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/diego/Escritorio/Proyectos/MIA_P1/inodos.cpp > CMakeFiles/MIA_P1.dir/inodos.cpp.i

CMakeFiles/MIA_P1.dir/inodos.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MIA_P1.dir/inodos.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/diego/Escritorio/Proyectos/MIA_P1/inodos.cpp -o CMakeFiles/MIA_P1.dir/inodos.cpp.s

CMakeFiles/MIA_P1.dir/edit.cpp.o: CMakeFiles/MIA_P1.dir/flags.make
CMakeFiles/MIA_P1.dir/edit.cpp.o: ../edit.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/diego/Escritorio/Proyectos/MIA_P1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Building CXX object CMakeFiles/MIA_P1.dir/edit.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MIA_P1.dir/edit.cpp.o -c /home/diego/Escritorio/Proyectos/MIA_P1/edit.cpp

CMakeFiles/MIA_P1.dir/edit.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MIA_P1.dir/edit.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/diego/Escritorio/Proyectos/MIA_P1/edit.cpp > CMakeFiles/MIA_P1.dir/edit.cpp.i

CMakeFiles/MIA_P1.dir/edit.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MIA_P1.dir/edit.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/diego/Escritorio/Proyectos/MIA_P1/edit.cpp -o CMakeFiles/MIA_P1.dir/edit.cpp.s

CMakeFiles/MIA_P1.dir/remove.cpp.o: CMakeFiles/MIA_P1.dir/flags.make
CMakeFiles/MIA_P1.dir/remove.cpp.o: ../remove.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/diego/Escritorio/Proyectos/MIA_P1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_19) "Building CXX object CMakeFiles/MIA_P1.dir/remove.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MIA_P1.dir/remove.cpp.o -c /home/diego/Escritorio/Proyectos/MIA_P1/remove.cpp

CMakeFiles/MIA_P1.dir/remove.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MIA_P1.dir/remove.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/diego/Escritorio/Proyectos/MIA_P1/remove.cpp > CMakeFiles/MIA_P1.dir/remove.cpp.i

CMakeFiles/MIA_P1.dir/remove.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MIA_P1.dir/remove.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/diego/Escritorio/Proyectos/MIA_P1/remove.cpp -o CMakeFiles/MIA_P1.dir/remove.cpp.s

# Object files for target MIA_P1
MIA_P1_OBJECTS = \
"CMakeFiles/MIA_P1.dir/main.cpp.o" \
"CMakeFiles/MIA_P1.dir/parser.cpp.o" \
"CMakeFiles/MIA_P1.dir/scanner.cpp.o" \
"CMakeFiles/MIA_P1.dir/disco.cpp.o" \
"CMakeFiles/MIA_P1.dir/fdisk.cpp.o" \
"CMakeFiles/MIA_P1.dir/comexec.cpp.o" \
"CMakeFiles/MIA_P1.dir/mount.cpp.o" \
"CMakeFiles/MIA_P1.dir/mkfs.cpp.o" \
"CMakeFiles/MIA_P1.dir/mkdir.cpp.o" \
"CMakeFiles/MIA_P1.dir/touch.cpp.o" \
"CMakeFiles/MIA_P1.dir/chmod.cpp.o" \
"CMakeFiles/MIA_P1.dir/ren.cpp.o" \
"CMakeFiles/MIA_P1.dir/move.cpp.o" \
"CMakeFiles/MIA_P1.dir/cat.cpp.o" \
"CMakeFiles/MIA_P1.dir/find.cpp.o" \
"CMakeFiles/MIA_P1.dir/arbol.cpp.o" \
"CMakeFiles/MIA_P1.dir/inodos.cpp.o" \
"CMakeFiles/MIA_P1.dir/edit.cpp.o" \
"CMakeFiles/MIA_P1.dir/remove.cpp.o"

# External object files for target MIA_P1
MIA_P1_EXTERNAL_OBJECTS =

MIA_P1: CMakeFiles/MIA_P1.dir/main.cpp.o
MIA_P1: CMakeFiles/MIA_P1.dir/parser.cpp.o
MIA_P1: CMakeFiles/MIA_P1.dir/scanner.cpp.o
MIA_P1: CMakeFiles/MIA_P1.dir/disco.cpp.o
MIA_P1: CMakeFiles/MIA_P1.dir/fdisk.cpp.o
MIA_P1: CMakeFiles/MIA_P1.dir/comexec.cpp.o
MIA_P1: CMakeFiles/MIA_P1.dir/mount.cpp.o
MIA_P1: CMakeFiles/MIA_P1.dir/mkfs.cpp.o
MIA_P1: CMakeFiles/MIA_P1.dir/mkdir.cpp.o
MIA_P1: CMakeFiles/MIA_P1.dir/touch.cpp.o
MIA_P1: CMakeFiles/MIA_P1.dir/chmod.cpp.o
MIA_P1: CMakeFiles/MIA_P1.dir/ren.cpp.o
MIA_P1: CMakeFiles/MIA_P1.dir/move.cpp.o
MIA_P1: CMakeFiles/MIA_P1.dir/cat.cpp.o
MIA_P1: CMakeFiles/MIA_P1.dir/find.cpp.o
MIA_P1: CMakeFiles/MIA_P1.dir/arbol.cpp.o
MIA_P1: CMakeFiles/MIA_P1.dir/inodos.cpp.o
MIA_P1: CMakeFiles/MIA_P1.dir/edit.cpp.o
MIA_P1: CMakeFiles/MIA_P1.dir/remove.cpp.o
MIA_P1: CMakeFiles/MIA_P1.dir/build.make
MIA_P1: CMakeFiles/MIA_P1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/diego/Escritorio/Proyectos/MIA_P1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_20) "Linking CXX executable MIA_P1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MIA_P1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MIA_P1.dir/build: MIA_P1
.PHONY : CMakeFiles/MIA_P1.dir/build

CMakeFiles/MIA_P1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MIA_P1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MIA_P1.dir/clean

CMakeFiles/MIA_P1.dir/depend:
	cd /home/diego/Escritorio/Proyectos/MIA_P1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/diego/Escritorio/Proyectos/MIA_P1 /home/diego/Escritorio/Proyectos/MIA_P1 /home/diego/Escritorio/Proyectos/MIA_P1/cmake-build-debug /home/diego/Escritorio/Proyectos/MIA_P1/cmake-build-debug /home/diego/Escritorio/Proyectos/MIA_P1/cmake-build-debug/CMakeFiles/MIA_P1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MIA_P1.dir/depend

