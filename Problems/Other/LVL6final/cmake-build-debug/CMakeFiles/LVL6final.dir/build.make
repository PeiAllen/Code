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
CMAKE_SOURCE_DIR = /Users/allen/Documents/GitHub/Code/Problems/Other/LVL6final

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/allen/Documents/GitHub/Code/Problems/Other/LVL6final/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/LVL6final.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/LVL6final.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/LVL6final.dir/flags.make

CMakeFiles/LVL6final.dir/main.cpp.o: CMakeFiles/LVL6final.dir/flags.make
CMakeFiles/LVL6final.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/allen/Documents/GitHub/Code/Problems/Other/LVL6final/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/LVL6final.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LVL6final.dir/main.cpp.o -c /Users/allen/Documents/GitHub/Code/Problems/Other/LVL6final/main.cpp

CMakeFiles/LVL6final.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LVL6final.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/allen/Documents/GitHub/Code/Problems/Other/LVL6final/main.cpp > CMakeFiles/LVL6final.dir/main.cpp.i

CMakeFiles/LVL6final.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LVL6final.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/allen/Documents/GitHub/Code/Problems/Other/LVL6final/main.cpp -o CMakeFiles/LVL6final.dir/main.cpp.s

# Object files for target LVL6final
LVL6final_OBJECTS = \
"CMakeFiles/LVL6final.dir/main.cpp.o"

# External object files for target LVL6final
LVL6final_EXTERNAL_OBJECTS =

LVL6final: CMakeFiles/LVL6final.dir/main.cpp.o
LVL6final: CMakeFiles/LVL6final.dir/build.make
LVL6final: CMakeFiles/LVL6final.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/allen/Documents/GitHub/Code/Problems/Other/LVL6final/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable LVL6final"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/LVL6final.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/LVL6final.dir/build: LVL6final

.PHONY : CMakeFiles/LVL6final.dir/build

CMakeFiles/LVL6final.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/LVL6final.dir/cmake_clean.cmake
.PHONY : CMakeFiles/LVL6final.dir/clean

CMakeFiles/LVL6final.dir/depend:
	cd /Users/allen/Documents/GitHub/Code/Problems/Other/LVL6final/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/allen/Documents/GitHub/Code/Problems/Other/LVL6final /Users/allen/Documents/GitHub/Code/Problems/Other/LVL6final /Users/allen/Documents/GitHub/Code/Problems/Other/LVL6final/cmake-build-debug /Users/allen/Documents/GitHub/Code/Problems/Other/LVL6final/cmake-build-debug /Users/allen/Documents/GitHub/Code/Problems/Other/LVL6final/cmake-build-debug/CMakeFiles/LVL6final.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/LVL6final.dir/depend
