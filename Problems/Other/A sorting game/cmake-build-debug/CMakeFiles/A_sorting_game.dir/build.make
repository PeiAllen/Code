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
CMAKE_SOURCE_DIR = "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Other\A sorting game"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Other\A sorting game\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/A_sorting_game.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/A_sorting_game.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/A_sorting_game.dir/flags.make

CMakeFiles/A_sorting_game.dir/main.cpp.obj: CMakeFiles/A_sorting_game.dir/flags.make
CMakeFiles/A_sorting_game.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Other\A sorting game\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/A_sorting_game.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\A_sorting_game.dir\main.cpp.obj -c "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Other\A sorting game\main.cpp"

CMakeFiles/A_sorting_game.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/A_sorting_game.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Other\A sorting game\main.cpp" > CMakeFiles\A_sorting_game.dir\main.cpp.i

CMakeFiles/A_sorting_game.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/A_sorting_game.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Other\A sorting game\main.cpp" -o CMakeFiles\A_sorting_game.dir\main.cpp.s

# Object files for target A_sorting_game
A_sorting_game_OBJECTS = \
"CMakeFiles/A_sorting_game.dir/main.cpp.obj"

# External object files for target A_sorting_game
A_sorting_game_EXTERNAL_OBJECTS =

A_sorting_game.exe: CMakeFiles/A_sorting_game.dir/main.cpp.obj
A_sorting_game.exe: CMakeFiles/A_sorting_game.dir/build.make
A_sorting_game.exe: CMakeFiles/A_sorting_game.dir/linklibs.rsp
A_sorting_game.exe: CMakeFiles/A_sorting_game.dir/objects1.rsp
A_sorting_game.exe: CMakeFiles/A_sorting_game.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Other\A sorting game\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable A_sorting_game.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\A_sorting_game.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/A_sorting_game.dir/build: A_sorting_game.exe

.PHONY : CMakeFiles/A_sorting_game.dir/build

CMakeFiles/A_sorting_game.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\A_sorting_game.dir\cmake_clean.cmake
.PHONY : CMakeFiles/A_sorting_game.dir/clean

CMakeFiles/A_sorting_game.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Other\A sorting game" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Other\A sorting game" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Other\A sorting game\cmake-build-debug" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Other\A sorting game\cmake-build-debug" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Other\A sorting game\cmake-build-debug\CMakeFiles\A_sorting_game.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/A_sorting_game.dir/depend
