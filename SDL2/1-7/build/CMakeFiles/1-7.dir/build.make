# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.0

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jordy/Projetos/Cpp/opengl/3.0+/SDL2/1-7

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jordy/Projetos/Cpp/opengl/3.0+/SDL2/1-7/build

# Include any dependencies generated for this target.
include CMakeFiles/1-7.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/1-7.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/1-7.dir/flags.make

CMakeFiles/1-7.dir/src/DisplaySDL2.cpp.o: CMakeFiles/1-7.dir/flags.make
CMakeFiles/1-7.dir/src/DisplaySDL2.cpp.o: ../src/DisplaySDL2.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/jordy/Projetos/Cpp/opengl/3.0+/SDL2/1-7/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/1-7.dir/src/DisplaySDL2.cpp.o"
	clang++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/1-7.dir/src/DisplaySDL2.cpp.o -c /home/jordy/Projetos/Cpp/opengl/3.0+/SDL2/1-7/src/DisplaySDL2.cpp

CMakeFiles/1-7.dir/src/DisplaySDL2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/1-7.dir/src/DisplaySDL2.cpp.i"
	clang++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/jordy/Projetos/Cpp/opengl/3.0+/SDL2/1-7/src/DisplaySDL2.cpp > CMakeFiles/1-7.dir/src/DisplaySDL2.cpp.i

CMakeFiles/1-7.dir/src/DisplaySDL2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/1-7.dir/src/DisplaySDL2.cpp.s"
	clang++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/jordy/Projetos/Cpp/opengl/3.0+/SDL2/1-7/src/DisplaySDL2.cpp -o CMakeFiles/1-7.dir/src/DisplaySDL2.cpp.s

CMakeFiles/1-7.dir/src/DisplaySDL2.cpp.o.requires:
.PHONY : CMakeFiles/1-7.dir/src/DisplaySDL2.cpp.o.requires

CMakeFiles/1-7.dir/src/DisplaySDL2.cpp.o.provides: CMakeFiles/1-7.dir/src/DisplaySDL2.cpp.o.requires
	$(MAKE) -f CMakeFiles/1-7.dir/build.make CMakeFiles/1-7.dir/src/DisplaySDL2.cpp.o.provides.build
.PHONY : CMakeFiles/1-7.dir/src/DisplaySDL2.cpp.o.provides

CMakeFiles/1-7.dir/src/DisplaySDL2.cpp.o.provides.build: CMakeFiles/1-7.dir/src/DisplaySDL2.cpp.o

CMakeFiles/1-7.dir/src/main.cpp.o: CMakeFiles/1-7.dir/flags.make
CMakeFiles/1-7.dir/src/main.cpp.o: ../src/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/jordy/Projetos/Cpp/opengl/3.0+/SDL2/1-7/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/1-7.dir/src/main.cpp.o"
	clang++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/1-7.dir/src/main.cpp.o -c /home/jordy/Projetos/Cpp/opengl/3.0+/SDL2/1-7/src/main.cpp

CMakeFiles/1-7.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/1-7.dir/src/main.cpp.i"
	clang++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/jordy/Projetos/Cpp/opengl/3.0+/SDL2/1-7/src/main.cpp > CMakeFiles/1-7.dir/src/main.cpp.i

CMakeFiles/1-7.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/1-7.dir/src/main.cpp.s"
	clang++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/jordy/Projetos/Cpp/opengl/3.0+/SDL2/1-7/src/main.cpp -o CMakeFiles/1-7.dir/src/main.cpp.s

CMakeFiles/1-7.dir/src/main.cpp.o.requires:
.PHONY : CMakeFiles/1-7.dir/src/main.cpp.o.requires

CMakeFiles/1-7.dir/src/main.cpp.o.provides: CMakeFiles/1-7.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/1-7.dir/build.make CMakeFiles/1-7.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/1-7.dir/src/main.cpp.o.provides

CMakeFiles/1-7.dir/src/main.cpp.o.provides.build: CMakeFiles/1-7.dir/src/main.cpp.o

CMakeFiles/1-7.dir/src/DisplaySFML.cpp.o: CMakeFiles/1-7.dir/flags.make
CMakeFiles/1-7.dir/src/DisplaySFML.cpp.o: ../src/DisplaySFML.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/jordy/Projetos/Cpp/opengl/3.0+/SDL2/1-7/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/1-7.dir/src/DisplaySFML.cpp.o"
	clang++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/1-7.dir/src/DisplaySFML.cpp.o -c /home/jordy/Projetos/Cpp/opengl/3.0+/SDL2/1-7/src/DisplaySFML.cpp

CMakeFiles/1-7.dir/src/DisplaySFML.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/1-7.dir/src/DisplaySFML.cpp.i"
	clang++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/jordy/Projetos/Cpp/opengl/3.0+/SDL2/1-7/src/DisplaySFML.cpp > CMakeFiles/1-7.dir/src/DisplaySFML.cpp.i

CMakeFiles/1-7.dir/src/DisplaySFML.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/1-7.dir/src/DisplaySFML.cpp.s"
	clang++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/jordy/Projetos/Cpp/opengl/3.0+/SDL2/1-7/src/DisplaySFML.cpp -o CMakeFiles/1-7.dir/src/DisplaySFML.cpp.s

CMakeFiles/1-7.dir/src/DisplaySFML.cpp.o.requires:
.PHONY : CMakeFiles/1-7.dir/src/DisplaySFML.cpp.o.requires

CMakeFiles/1-7.dir/src/DisplaySFML.cpp.o.provides: CMakeFiles/1-7.dir/src/DisplaySFML.cpp.o.requires
	$(MAKE) -f CMakeFiles/1-7.dir/build.make CMakeFiles/1-7.dir/src/DisplaySFML.cpp.o.provides.build
.PHONY : CMakeFiles/1-7.dir/src/DisplaySFML.cpp.o.provides

CMakeFiles/1-7.dir/src/DisplaySFML.cpp.o.provides.build: CMakeFiles/1-7.dir/src/DisplaySFML.cpp.o

# Object files for target 1-7
1__7_OBJECTS = \
"CMakeFiles/1-7.dir/src/DisplaySDL2.cpp.o" \
"CMakeFiles/1-7.dir/src/main.cpp.o" \
"CMakeFiles/1-7.dir/src/DisplaySFML.cpp.o"

# External object files for target 1-7
1__7_EXTERNAL_OBJECTS =

1-7: CMakeFiles/1-7.dir/src/DisplaySDL2.cpp.o
1-7: CMakeFiles/1-7.dir/src/main.cpp.o
1-7: CMakeFiles/1-7.dir/src/DisplaySFML.cpp.o
1-7: CMakeFiles/1-7.dir/build.make
1-7: /usr/lib64/libGLEW.so
1-7: /usr/lib64/libSDL2.so
1-7: /usr/lib64/libGLU.so
1-7: /usr/lib64/libGL.so
1-7: /usr/lib64/libSM.so
1-7: /usr/lib64/libICE.so
1-7: /usr/lib64/libX11.so
1-7: /usr/lib64/libXext.so
1-7: /usr/lib64/libsfml-system.so
1-7: /usr/lib64/libsfml-window.so
1-7: /usr/lib64/libsfml-graphics.so
1-7: /usr/lib64/libsfml-network.so
1-7: /usr/lib64/libsfml-audio.so
1-7: /usr/lib64/libSDL2_image.so
1-7: CMakeFiles/1-7.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable 1-7"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/1-7.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/1-7.dir/build: 1-7
.PHONY : CMakeFiles/1-7.dir/build

CMakeFiles/1-7.dir/requires: CMakeFiles/1-7.dir/src/DisplaySDL2.cpp.o.requires
CMakeFiles/1-7.dir/requires: CMakeFiles/1-7.dir/src/main.cpp.o.requires
CMakeFiles/1-7.dir/requires: CMakeFiles/1-7.dir/src/DisplaySFML.cpp.o.requires
.PHONY : CMakeFiles/1-7.dir/requires

CMakeFiles/1-7.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/1-7.dir/cmake_clean.cmake
.PHONY : CMakeFiles/1-7.dir/clean

CMakeFiles/1-7.dir/depend:
	cd /home/jordy/Projetos/Cpp/opengl/3.0+/SDL2/1-7/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jordy/Projetos/Cpp/opengl/3.0+/SDL2/1-7 /home/jordy/Projetos/Cpp/opengl/3.0+/SDL2/1-7 /home/jordy/Projetos/Cpp/opengl/3.0+/SDL2/1-7/build /home/jordy/Projetos/Cpp/opengl/3.0+/SDL2/1-7/build /home/jordy/Projetos/Cpp/opengl/3.0+/SDL2/1-7/build/CMakeFiles/1-7.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/1-7.dir/depend

