# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/allen/Documents/GitHub/Code/Problems/Other/A Knapsack Problem"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/allen/Documents/GitHub/Code/Problems/Other/A Knapsack Problem/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/A_Knapsack_Problem.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/A_Knapsack_Problem.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/A_Knapsack_Problem.dir/flags.make

CMakeFiles/A_Knapsack_Problem.dir/main.cpp.o: CMakeFiles/A_Knapsack_Problem.dir/flags.make
CMakeFiles/A_Knapsack_Problem.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/allen/Documents/GitHub/Code/Problems/Other/A Knapsack Problem/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/A_Knapsack_Problem.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/A_Knapsack_Problem.dir/main.cpp.o -c "/Users/allen/Documents/GitHub/Code/Problems/Other/A Knapsack Problem/main.cpp"

CMakeFiles/A_Knapsack_Problem.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/A_Knapsack_Problem.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/allen/Documents/GitHub/Code/Problems/Other/A Knapsack Problem/main.cpp" > CMakeFiles/A_Knapsack_Problem.dir/main.cpp.i

CMakeFiles/A_Knapsack_Problem.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/A_Knapsack_Problem.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/allen/Documents/GitHub/Code/Problems/Other/A Knapsack Problem/main.cpp" -o CMakeFiles/A_Knapsack_Problem.dir/main.cpp.s

# Object files for target A_Knapsack_Problem
A_Knapsack_Problem_OBJECTS = \
"CMakeFiles/A_Knapsack_Problem.dir/main.cpp.o"

# External object files for target A_Knapsack_Problem
A_Knapsack_Problem_EXTERNAL_OBJECTS =

A_Knapsack_Problem: CMakeFiles/A_Knapsack_Problem.dir/main.cpp.o
A_Knapsack_Problem: CMakeFiles/A_Knapsack_Problem.dir/build.make
A_Knapsack_Problem: CMakeFiles/A_Knapsack_Problem.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/allen/Documents/GitHub/Code/Problems/Other/A Knapsack Problem/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable A_Knapsack_Problem"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/A_Knapsack_Problem.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/A_Knapsack_Problem.dir/build: A_Knapsack_Problem

.PHONY : CMakeFiles/A_Knapsack_Problem.dir/build

CMakeFiles/A_Knapsack_Problem.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/A_Knapsack_Problem.dir/cmake_clean.cmake
.PHONY : CMakeFiles/A_Knapsack_Problem.dir/clean

CMakeFiles/A_Knapsack_Problem.dir/depend:
	cd "/Users/allen/Documents/GitHub/Code/Problems/Other/A Knapsack Problem/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/allen/Documents/GitHub/Code/Problems/Other/A Knapsack Problem" "/Users/allen/Documents/GitHub/Code/Problems/Other/A Knapsack Problem" "/Users/allen/Documents/GitHub/Code/Problems/Other/A Knapsack Problem/cmake-build-debug" "/Users/allen/Documents/GitHub/Code/Problems/Other/A Knapsack Problem/cmake-build-debug" "/Users/allen/Documents/GitHub/Code/Problems/Other/A Knapsack Problem/cmake-build-debug/CMakeFiles/A_Knapsack_Problem.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/A_Knapsack_Problem.dir/depend

