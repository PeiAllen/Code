# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.14

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.1.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.1.3\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\allen\Documents\Code\Problems\CEOI\CEOI '17 P4 - Building Bridges"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\allen\Documents\Code\Problems\CEOI\CEOI '17 P4 - Building Bridges\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/CEOI__17_P4___Building_Bridges.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CEOI__17_P4___Building_Bridges.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CEOI__17_P4___Building_Bridges.dir/flags.make

CMakeFiles/CEOI__17_P4___Building_Bridges.dir/main.cpp.obj: CMakeFiles/CEOI__17_P4___Building_Bridges.dir/flags.make
CMakeFiles/CEOI__17_P4___Building_Bridges.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\allen\Documents\Code\Problems\CEOI\CEOI '17 P4 - Building Bridges\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CEOI__17_P4___Building_Bridges.dir/main.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\CEOI__17_P4___Building_Bridges.dir\main.cpp.obj -c "C:\Users\allen\Documents\Code\Problems\CEOI\CEOI '17 P4 - Building Bridges\main.cpp"

CMakeFiles/CEOI__17_P4___Building_Bridges.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CEOI__17_P4___Building_Bridges.dir/main.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\allen\Documents\Code\Problems\CEOI\CEOI '17 P4 - Building Bridges\main.cpp" > CMakeFiles\CEOI__17_P4___Building_Bridges.dir\main.cpp.i

CMakeFiles/CEOI__17_P4___Building_Bridges.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CEOI__17_P4___Building_Bridges.dir/main.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\allen\Documents\Code\Problems\CEOI\CEOI '17 P4 - Building Bridges\main.cpp" -o CMakeFiles\CEOI__17_P4___Building_Bridges.dir\main.cpp.s

# Object files for target CEOI__17_P4___Building_Bridges
CEOI__17_P4___Building_Bridges_OBJECTS = \
"CMakeFiles/CEOI__17_P4___Building_Bridges.dir/main.cpp.obj"

# External object files for target CEOI__17_P4___Building_Bridges
CEOI__17_P4___Building_Bridges_EXTERNAL_OBJECTS =

CEOI__17_P4___Building_Bridges.exe: CMakeFiles/CEOI__17_P4___Building_Bridges.dir/main.cpp.obj
CEOI__17_P4___Building_Bridges.exe: CMakeFiles/CEOI__17_P4___Building_Bridges.dir/build.make
CEOI__17_P4___Building_Bridges.exe: CMakeFiles/CEOI__17_P4___Building_Bridges.dir/linklibs.rsp
CEOI__17_P4___Building_Bridges.exe: CMakeFiles/CEOI__17_P4___Building_Bridges.dir/objects1.rsp
CEOI__17_P4___Building_Bridges.exe: CMakeFiles/CEOI__17_P4___Building_Bridges.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\allen\Documents\Code\Problems\CEOI\CEOI '17 P4 - Building Bridges\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable CEOI__17_P4___Building_Bridges.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\CEOI__17_P4___Building_Bridges.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CEOI__17_P4___Building_Bridges.dir/build: CEOI__17_P4___Building_Bridges.exe

.PHONY : CMakeFiles/CEOI__17_P4___Building_Bridges.dir/build

CMakeFiles/CEOI__17_P4___Building_Bridges.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\CEOI__17_P4___Building_Bridges.dir\cmake_clean.cmake
.PHONY : CMakeFiles/CEOI__17_P4___Building_Bridges.dir/clean

CMakeFiles/CEOI__17_P4___Building_Bridges.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\allen\Documents\Code\Problems\CEOI\CEOI '17 P4 - Building Bridges" "C:\Users\allen\Documents\Code\Problems\CEOI\CEOI '17 P4 - Building Bridges" "C:\Users\allen\Documents\Code\Problems\CEOI\CEOI '17 P4 - Building Bridges\cmake-build-debug" "C:\Users\allen\Documents\Code\Problems\CEOI\CEOI '17 P4 - Building Bridges\cmake-build-debug" "C:\Users\allen\Documents\Code\Problems\CEOI\CEOI '17 P4 - Building Bridges\cmake-build-debug\CMakeFiles\CEOI__17_P4___Building_Bridges.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/CEOI__17_P4___Building_Bridges.dir/depend

