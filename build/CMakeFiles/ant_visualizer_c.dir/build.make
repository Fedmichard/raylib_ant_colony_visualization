# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.29

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\franc\Documents\Personal_Projects\raylib_ant_colony_visualization

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\franc\Documents\Personal_Projects\raylib_ant_colony_visualization\build

# Include any dependencies generated for this target.
include CMakeFiles/ant_visualizer_c.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ant_visualizer_c.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ant_visualizer_c.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ant_visualizer_c.dir/flags.make

CMakeFiles/ant_visualizer_c.dir/src/main.c.obj: CMakeFiles/ant_visualizer_c.dir/flags.make
CMakeFiles/ant_visualizer_c.dir/src/main.c.obj: CMakeFiles/ant_visualizer_c.dir/includes_C.rsp
CMakeFiles/ant_visualizer_c.dir/src/main.c.obj: C:/Users/franc/Documents/Personal_Projects/raylib_ant_colony_visualization/src/main.c
CMakeFiles/ant_visualizer_c.dir/src/main.c.obj: CMakeFiles/ant_visualizer_c.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\franc\Documents\Personal_Projects\raylib_ant_colony_visualization\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ant_visualizer_c.dir/src/main.c.obj"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/ant_visualizer_c.dir/src/main.c.obj -MF CMakeFiles\ant_visualizer_c.dir\src\main.c.obj.d -o CMakeFiles\ant_visualizer_c.dir\src\main.c.obj -c C:\Users\franc\Documents\Personal_Projects\raylib_ant_colony_visualization\src\main.c

CMakeFiles/ant_visualizer_c.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/ant_visualizer_c.dir/src/main.c.i"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\franc\Documents\Personal_Projects\raylib_ant_colony_visualization\src\main.c > CMakeFiles\ant_visualizer_c.dir\src\main.c.i

CMakeFiles/ant_visualizer_c.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/ant_visualizer_c.dir/src/main.c.s"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\franc\Documents\Personal_Projects\raylib_ant_colony_visualization\src\main.c -o CMakeFiles\ant_visualizer_c.dir\src\main.c.s

CMakeFiles/ant_visualizer_c.dir/src/ant.c.obj: CMakeFiles/ant_visualizer_c.dir/flags.make
CMakeFiles/ant_visualizer_c.dir/src/ant.c.obj: CMakeFiles/ant_visualizer_c.dir/includes_C.rsp
CMakeFiles/ant_visualizer_c.dir/src/ant.c.obj: C:/Users/franc/Documents/Personal_Projects/raylib_ant_colony_visualization/src/ant.c
CMakeFiles/ant_visualizer_c.dir/src/ant.c.obj: CMakeFiles/ant_visualizer_c.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\franc\Documents\Personal_Projects\raylib_ant_colony_visualization\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/ant_visualizer_c.dir/src/ant.c.obj"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/ant_visualizer_c.dir/src/ant.c.obj -MF CMakeFiles\ant_visualizer_c.dir\src\ant.c.obj.d -o CMakeFiles\ant_visualizer_c.dir\src\ant.c.obj -c C:\Users\franc\Documents\Personal_Projects\raylib_ant_colony_visualization\src\ant.c

CMakeFiles/ant_visualizer_c.dir/src/ant.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/ant_visualizer_c.dir/src/ant.c.i"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\franc\Documents\Personal_Projects\raylib_ant_colony_visualization\src\ant.c > CMakeFiles\ant_visualizer_c.dir\src\ant.c.i

CMakeFiles/ant_visualizer_c.dir/src/ant.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/ant_visualizer_c.dir/src/ant.c.s"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\franc\Documents\Personal_Projects\raylib_ant_colony_visualization\src\ant.c -o CMakeFiles\ant_visualizer_c.dir\src\ant.c.s

CMakeFiles/ant_visualizer_c.dir/src/foods.c.obj: CMakeFiles/ant_visualizer_c.dir/flags.make
CMakeFiles/ant_visualizer_c.dir/src/foods.c.obj: CMakeFiles/ant_visualizer_c.dir/includes_C.rsp
CMakeFiles/ant_visualizer_c.dir/src/foods.c.obj: C:/Users/franc/Documents/Personal_Projects/raylib_ant_colony_visualization/src/foods.c
CMakeFiles/ant_visualizer_c.dir/src/foods.c.obj: CMakeFiles/ant_visualizer_c.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\franc\Documents\Personal_Projects\raylib_ant_colony_visualization\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/ant_visualizer_c.dir/src/foods.c.obj"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/ant_visualizer_c.dir/src/foods.c.obj -MF CMakeFiles\ant_visualizer_c.dir\src\foods.c.obj.d -o CMakeFiles\ant_visualizer_c.dir\src\foods.c.obj -c C:\Users\franc\Documents\Personal_Projects\raylib_ant_colony_visualization\src\foods.c

CMakeFiles/ant_visualizer_c.dir/src/foods.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/ant_visualizer_c.dir/src/foods.c.i"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\franc\Documents\Personal_Projects\raylib_ant_colony_visualization\src\foods.c > CMakeFiles\ant_visualizer_c.dir\src\foods.c.i

CMakeFiles/ant_visualizer_c.dir/src/foods.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/ant_visualizer_c.dir/src/foods.c.s"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\franc\Documents\Personal_Projects\raylib_ant_colony_visualization\src\foods.c -o CMakeFiles\ant_visualizer_c.dir\src\foods.c.s

CMakeFiles/ant_visualizer_c.dir/src/pheromones.c.obj: CMakeFiles/ant_visualizer_c.dir/flags.make
CMakeFiles/ant_visualizer_c.dir/src/pheromones.c.obj: CMakeFiles/ant_visualizer_c.dir/includes_C.rsp
CMakeFiles/ant_visualizer_c.dir/src/pheromones.c.obj: C:/Users/franc/Documents/Personal_Projects/raylib_ant_colony_visualization/src/pheromones.c
CMakeFiles/ant_visualizer_c.dir/src/pheromones.c.obj: CMakeFiles/ant_visualizer_c.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\franc\Documents\Personal_Projects\raylib_ant_colony_visualization\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/ant_visualizer_c.dir/src/pheromones.c.obj"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/ant_visualizer_c.dir/src/pheromones.c.obj -MF CMakeFiles\ant_visualizer_c.dir\src\pheromones.c.obj.d -o CMakeFiles\ant_visualizer_c.dir\src\pheromones.c.obj -c C:\Users\franc\Documents\Personal_Projects\raylib_ant_colony_visualization\src\pheromones.c

CMakeFiles/ant_visualizer_c.dir/src/pheromones.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/ant_visualizer_c.dir/src/pheromones.c.i"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\franc\Documents\Personal_Projects\raylib_ant_colony_visualization\src\pheromones.c > CMakeFiles\ant_visualizer_c.dir\src\pheromones.c.i

CMakeFiles/ant_visualizer_c.dir/src/pheromones.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/ant_visualizer_c.dir/src/pheromones.c.s"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\franc\Documents\Personal_Projects\raylib_ant_colony_visualization\src\pheromones.c -o CMakeFiles\ant_visualizer_c.dir\src\pheromones.c.s

CMakeFiles/ant_visualizer_c.dir/src/grid.c.obj: CMakeFiles/ant_visualizer_c.dir/flags.make
CMakeFiles/ant_visualizer_c.dir/src/grid.c.obj: CMakeFiles/ant_visualizer_c.dir/includes_C.rsp
CMakeFiles/ant_visualizer_c.dir/src/grid.c.obj: C:/Users/franc/Documents/Personal_Projects/raylib_ant_colony_visualization/src/grid.c
CMakeFiles/ant_visualizer_c.dir/src/grid.c.obj: CMakeFiles/ant_visualizer_c.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\franc\Documents\Personal_Projects\raylib_ant_colony_visualization\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/ant_visualizer_c.dir/src/grid.c.obj"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/ant_visualizer_c.dir/src/grid.c.obj -MF CMakeFiles\ant_visualizer_c.dir\src\grid.c.obj.d -o CMakeFiles\ant_visualizer_c.dir\src\grid.c.obj -c C:\Users\franc\Documents\Personal_Projects\raylib_ant_colony_visualization\src\grid.c

CMakeFiles/ant_visualizer_c.dir/src/grid.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/ant_visualizer_c.dir/src/grid.c.i"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\franc\Documents\Personal_Projects\raylib_ant_colony_visualization\src\grid.c > CMakeFiles\ant_visualizer_c.dir\src\grid.c.i

CMakeFiles/ant_visualizer_c.dir/src/grid.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/ant_visualizer_c.dir/src/grid.c.s"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\franc\Documents\Personal_Projects\raylib_ant_colony_visualization\src\grid.c -o CMakeFiles\ant_visualizer_c.dir\src\grid.c.s

# Object files for target ant_visualizer_c
ant_visualizer_c_OBJECTS = \
"CMakeFiles/ant_visualizer_c.dir/src/main.c.obj" \
"CMakeFiles/ant_visualizer_c.dir/src/ant.c.obj" \
"CMakeFiles/ant_visualizer_c.dir/src/foods.c.obj" \
"CMakeFiles/ant_visualizer_c.dir/src/pheromones.c.obj" \
"CMakeFiles/ant_visualizer_c.dir/src/grid.c.obj"

# External object files for target ant_visualizer_c
ant_visualizer_c_EXTERNAL_OBJECTS =

ant_visualizer_c.exe: CMakeFiles/ant_visualizer_c.dir/src/main.c.obj
ant_visualizer_c.exe: CMakeFiles/ant_visualizer_c.dir/src/ant.c.obj
ant_visualizer_c.exe: CMakeFiles/ant_visualizer_c.dir/src/foods.c.obj
ant_visualizer_c.exe: CMakeFiles/ant_visualizer_c.dir/src/pheromones.c.obj
ant_visualizer_c.exe: CMakeFiles/ant_visualizer_c.dir/src/grid.c.obj
ant_visualizer_c.exe: CMakeFiles/ant_visualizer_c.dir/build.make
ant_visualizer_c.exe: C:/Users/franc/Documents/Personal_Projects/raylib_ant_colony_visualization/raylib/libraylib.a
ant_visualizer_c.exe: CMakeFiles/ant_visualizer_c.dir/linkLibs.rsp
ant_visualizer_c.exe: CMakeFiles/ant_visualizer_c.dir/objects1.rsp
ant_visualizer_c.exe: CMakeFiles/ant_visualizer_c.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\franc\Documents\Personal_Projects\raylib_ant_colony_visualization\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking C executable ant_visualizer_c.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\ant_visualizer_c.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ant_visualizer_c.dir/build: ant_visualizer_c.exe
.PHONY : CMakeFiles/ant_visualizer_c.dir/build

CMakeFiles/ant_visualizer_c.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ant_visualizer_c.dir\cmake_clean.cmake
.PHONY : CMakeFiles/ant_visualizer_c.dir/clean

CMakeFiles/ant_visualizer_c.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\franc\Documents\Personal_Projects\raylib_ant_colony_visualization C:\Users\franc\Documents\Personal_Projects\raylib_ant_colony_visualization C:\Users\franc\Documents\Personal_Projects\raylib_ant_colony_visualization\build C:\Users\franc\Documents\Personal_Projects\raylib_ant_colony_visualization\build C:\Users\franc\Documents\Personal_Projects\raylib_ant_colony_visualization\build\CMakeFiles\ant_visualizer_c.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/ant_visualizer_c.dir/depend

