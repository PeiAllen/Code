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
CMAKE_SOURCE_DIR = "C:\Users\allen\Documents\Code\Problems\CEOI\CEOI '17 P1 - One-Way Streets"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\allen\Documents\Code\Problems\CEOI\CEOI '17 P1 - One-Way Streets\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/CEOI__17_P1___One_Way_Streets.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CEOI__17_P1___One_Way_Streets.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CEOI__17_P1___One_Way_Streets.dir/flags.make

CMakeFiles/CEOI__17_P1___One_Way_Streets.dir/main.cpp.obj: CMakeFiles/CEOI__17_P1___One_Way_Streets.dir/flags.make
CMakeFiles/CEOI__17_P1___One_Way_Streets.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\allen\Documents\Code\Problems\CEOI\CEOI '17 P1 - One-Way Streets\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CEOI__17_P1___One_Way_Streets.dir/main.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\CEOI__17_P1___One_Way_Streets.dir\main.cpp.obj -c "C:\Users\allen\Documents\Code\Problems\CEOI\CEOI '17 P1 - One-Way Streets\main.cpp"

CMakeFiles/CEOI__17_P1___One_Way_Streets.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CEOI__17_P1___One_Way_Streets.dir/main.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\allen\Documents\Code\Problems\CEOI\CEOI '17 P1 - One-Way Streets\main.cpp" > CMakeFiles\CEOI__17_P1___One_Way_Streets.dir\main.cpp.i

CMakeFiles/CEOI__17_P1___One_Way_Streets.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CEOI__17_P1___One_Way_Streets.dir/main.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\allen\Documents\Code\Problems\CEOI\CEOI '17 P1 - One-Way Streets\main.cpp" -o CMakeFiles\CEOI__17_P1___One_Way_Streets.dir\main.cpp.s

# Object files for target CEOI__17_P1___One_Way_Streets
CEOI__17_P1___One_Way_Streets_OBJECTS = \
"CMakeFiles/CEOI__17_P1___One_Way_Streets.dir/main.cpp.obj"

# External object files for target CEOI__17_P1___One_Way_Streets
CEOI__17_P1___One_Way_Streets_EXTERNAL_OBJECTS =

CEOI__17_P1___One_Way_Streets.exe: CMakeFiles/CEOI__17_P1___One_Way_Streets.dir/main.cpp.obj
CEOI__17_P1___One_Way_Streets.exe: CMakeFiles/CEOI__17_P1___One_Way_Streets.dir/build.make
CEOI__17_P1___One_Way_Streets.exe: CMakeFiles/CEOI__17_P1___One_Way_Streets.dir/linklibs.rsp
CEOI__17_P1___One_Way_Streets.exe: CMakeFiles/CEOI__17_P1___One_Way_Streets.dir/objects1.rsp
CEOI__17_P1___One_Way_Streets.exe: CMakeFiles/CEOI__17_P1___One_Way_Streets.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\allen\Documents\Code\Problems\CEOI\CEOI '17 P1 - One-Way Streets\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable CEOI__17_P1___One_Way_Streets.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\CEOI__17_P1___One_Way_Streets.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CEOI__17_P1___One_Way_Streets.dir/build: CEOI__17_P1___One_Way_Streets.exe

.PHONY : CMakeFiles/CEOI__17_P1___One_Way_Streets.dir/build

CMakeFiles/CEOI__17_P1___One_Way_Streets.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\CEOI__17_P1___One_Way_Streets.dir\cmake_clean.cmake
.PHONY : CMakeFiles/CEOI__17_P1___One_Way_Streets.dir/clean

CMakeFiles/CEOI__17_P1___One_Way_Streets.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\allen\Documents\Code\Problems\CEOI\CEOI '17 P1 - One-Way Streets" "C:\Users\allen\Documents\Code\Problems\CEOI\CEOI '17 P1 - One-Way Streets" "C:\Users\allen\Documents\Code\Problems\CEOI\CEOI '17 P1 - One-Way Streets\cmake-build-debug" "C:\Users\allen\Documents\Code\Problems\CEOI\CEOI '17 P1 - One-Way Streets\cmake-build-debug" "C:\Users\allen\Documents\Code\Problems\CEOI\CEOI '17 P1 - One-Way Streets\cmake-build-debug\CMakeFiles\CEOI__17_P1___One_Way_Streets.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/CEOI__17_P1___One_Way_Streets.dir/depend

