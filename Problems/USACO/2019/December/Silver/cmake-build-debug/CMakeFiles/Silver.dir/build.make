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
CMAKE_SOURCE_DIR = /Users/allen/Documents/GitHub/Code/Problems/USACO/2019/December/Silver

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/allen/Documents/GitHub/Code/Problems/USACO/2019/December/Silver/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Silver.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Silver.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Silver.dir/flags.make

CMakeFiles/Silver.dir/main.cpp.o: CMakeFiles/Silver.dir/flags.make
CMakeFiles/Silver.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/allen/Documents/GitHub/Code/Problems/USACO/2019/December/Silver/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Silver.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Silver.dir/main.cpp.o -c /Users/allen/Documents/GitHub/Code/Problems/USACO/2019/December/Silver/main.cpp

CMakeFiles/Silver.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Silver.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/allen/Documents/GitHub/Code/Problems/USACO/2019/December/Silver/main.cpp > CMakeFiles/Silver.dir/main.cpp.i

CMakeFiles/Silver.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Silver.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/allen/Documents/GitHub/Code/Problems/USACO/2019/December/Silver/main.cpp -o CMakeFiles/Silver.dir/main.cpp.s

# Object files for target Silver
Silver_OBJECTS = \
"CMakeFiles/Silver.dir/main.cpp.o"

# External object files for target Silver
Silver_EXTERNAL_OBJECTS =

Silver: CMakeFiles/Silver.dir/main.cpp.o
Silver: CMakeFiles/Silver.dir/build.make
Silver: CMakeFiles/Silver.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/allen/Documents/GitHub/Code/Problems/USACO/2019/December/Silver/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Silver"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Silver.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Silver.dir/build: Silver

.PHONY : CMakeFiles/Silver.dir/build

CMakeFiles/Silver.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Silver.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Silver.dir/clean

CMakeFiles/Silver.dir/depend:
	cd /Users/allen/Documents/GitHub/Code/Problems/USACO/2019/December/Silver/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/allen/Documents/GitHub/Code/Problems/USACO/2019/December/Silver /Users/allen/Documents/GitHub/Code/Problems/USACO/2019/December/Silver /Users/allen/Documents/GitHub/Code/Problems/USACO/2019/December/Silver/cmake-build-debug /Users/allen/Documents/GitHub/Code/Problems/USACO/2019/December/Silver/cmake-build-debug /Users/allen/Documents/GitHub/Code/Problems/USACO/2019/December/Silver/cmake-build-debug/CMakeFiles/Silver.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Silver.dir/depend
