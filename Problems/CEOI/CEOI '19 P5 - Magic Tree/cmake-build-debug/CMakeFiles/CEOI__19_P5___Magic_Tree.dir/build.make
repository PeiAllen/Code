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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.1.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.1.2\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\CEOI\CEOI '19 P5 - Magic Tree"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\CEOI\CEOI '19 P5 - Magic Tree\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/CEOI__19_P5___Magic_Tree.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CEOI__19_P5___Magic_Tree.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CEOI__19_P5___Magic_Tree.dir/flags.make

CMakeFiles/CEOI__19_P5___Magic_Tree.dir/main.cpp.obj: CMakeFiles/CEOI__19_P5___Magic_Tree.dir/flags.make
CMakeFiles/CEOI__19_P5___Magic_Tree.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\CEOI\CEOI '19 P5 - Magic Tree\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CEOI__19_P5___Magic_Tree.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\CEOI__19_P5___Magic_Tree.dir\main.cpp.obj -c "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\CEOI\CEOI '19 P5 - Magic Tree\main.cpp"

CMakeFiles/CEOI__19_P5___Magic_Tree.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CEOI__19_P5___Magic_Tree.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\CEOI\CEOI '19 P5 - Magic Tree\main.cpp" > CMakeFiles\CEOI__19_P5___Magic_Tree.dir\main.cpp.i

CMakeFiles/CEOI__19_P5___Magic_Tree.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CEOI__19_P5___Magic_Tree.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\CEOI\CEOI '19 P5 - Magic Tree\main.cpp" -o CMakeFiles\CEOI__19_P5___Magic_Tree.dir\main.cpp.s

# Object files for target CEOI__19_P5___Magic_Tree
CEOI__19_P5___Magic_Tree_OBJECTS = \
"CMakeFiles/CEOI__19_P5___Magic_Tree.dir/main.cpp.obj"

# External object files for target CEOI__19_P5___Magic_Tree
CEOI__19_P5___Magic_Tree_EXTERNAL_OBJECTS =

CEOI__19_P5___Magic_Tree.exe: CMakeFiles/CEOI__19_P5___Magic_Tree.dir/main.cpp.obj
CEOI__19_P5___Magic_Tree.exe: CMakeFiles/CEOI__19_P5___Magic_Tree.dir/build.make
CEOI__19_P5___Magic_Tree.exe: CMakeFiles/CEOI__19_P5___Magic_Tree.dir/linklibs.rsp
CEOI__19_P5___Magic_Tree.exe: CMakeFiles/CEOI__19_P5___Magic_Tree.dir/objects1.rsp
CEOI__19_P5___Magic_Tree.exe: CMakeFiles/CEOI__19_P5___Magic_Tree.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\CEOI\CEOI '19 P5 - Magic Tree\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable CEOI__19_P5___Magic_Tree.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\CEOI__19_P5___Magic_Tree.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CEOI__19_P5___Magic_Tree.dir/build: CEOI__19_P5___Magic_Tree.exe

.PHONY : CMakeFiles/CEOI__19_P5___Magic_Tree.dir/build

CMakeFiles/CEOI__19_P5___Magic_Tree.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\CEOI__19_P5___Magic_Tree.dir\cmake_clean.cmake
.PHONY : CMakeFiles/CEOI__19_P5___Magic_Tree.dir/clean

CMakeFiles/CEOI__19_P5___Magic_Tree.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\CEOI\CEOI '19 P5 - Magic Tree" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\CEOI\CEOI '19 P5 - Magic Tree" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\CEOI\CEOI '19 P5 - Magic Tree\cmake-build-debug" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\CEOI\CEOI '19 P5 - Magic Tree\cmake-build-debug" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\CEOI\CEOI '19 P5 - Magic Tree\cmake-build-debug\CMakeFiles\CEOI__19_P5___Magic_Tree.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/CEOI__19_P5___Magic_Tree.dir/depend
