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
CMAKE_SOURCE_DIR = /Users/allen/CLionProjects/edu67A

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/allen/CLionProjects/edu67A/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/edu67A.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/edu67A.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/edu67A.dir/flags.make

CMakeFiles/edu67A.dir/main.cpp.o: CMakeFiles/edu67A.dir/flags.make
CMakeFiles/edu67A.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/allen/CLionProjects/edu67A/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/edu67A.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/edu67A.dir/main.cpp.o -c /Users/allen/CLionProjects/edu67A/main.cpp

CMakeFiles/edu67A.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/edu67A.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/allen/CLionProjects/edu67A/main.cpp > CMakeFiles/edu67A.dir/main.cpp.i

CMakeFiles/edu67A.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/edu67A.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/allen/CLionProjects/edu67A/main.cpp -o CMakeFiles/edu67A.dir/main.cpp.s

# Object files for target edu67A
edu67A_OBJECTS = \
"CMakeFiles/edu67A.dir/main.cpp.o"

# External object files for target edu67A
edu67A_EXTERNAL_OBJECTS =

edu67A: CMakeFiles/edu67A.dir/main.cpp.o
edu67A: CMakeFiles/edu67A.dir/build.make
edu67A: CMakeFiles/edu67A.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/allen/CLionProjects/edu67A/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable edu67A"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/edu67A.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/edu67A.dir/build: edu67A

.PHONY : CMakeFiles/edu67A.dir/build

CMakeFiles/edu67A.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/edu67A.dir/cmake_clean.cmake
.PHONY : CMakeFiles/edu67A.dir/clean

CMakeFiles/edu67A.dir/depend:
	cd /Users/allen/CLionProjects/edu67A/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/allen/CLionProjects/edu67A /Users/allen/CLionProjects/edu67A /Users/allen/CLionProjects/edu67A/cmake-build-debug /Users/allen/CLionProjects/edu67A/cmake-build-debug /Users/allen/CLionProjects/edu67A/cmake-build-debug/CMakeFiles/edu67A.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/edu67A.dir/depend

