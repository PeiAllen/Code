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
CMAKE_SOURCE_DIR = "/Users/allen/Documents/GitHub/Code/Problems/Other/GlobeX Cup '18 S5 - Math Bash"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/allen/Documents/GitHub/Code/Problems/Other/GlobeX Cup '18 S5 - Math Bash/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/GlobeX_Cup__18_S5___Math_Bash.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/GlobeX_Cup__18_S5___Math_Bash.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/GlobeX_Cup__18_S5___Math_Bash.dir/flags.make

CMakeFiles/GlobeX_Cup__18_S5___Math_Bash.dir/main.cpp.o: CMakeFiles/GlobeX_Cup__18_S5___Math_Bash.dir/flags.make
CMakeFiles/GlobeX_Cup__18_S5___Math_Bash.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/allen/Documents/GitHub/Code/Problems/Other/GlobeX Cup '18 S5 - Math Bash/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/GlobeX_Cup__18_S5___Math_Bash.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GlobeX_Cup__18_S5___Math_Bash.dir/main.cpp.o -c "/Users/allen/Documents/GitHub/Code/Problems/Other/GlobeX Cup '18 S5 - Math Bash/main.cpp"

CMakeFiles/GlobeX_Cup__18_S5___Math_Bash.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GlobeX_Cup__18_S5___Math_Bash.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/allen/Documents/GitHub/Code/Problems/Other/GlobeX Cup '18 S5 - Math Bash/main.cpp" > CMakeFiles/GlobeX_Cup__18_S5___Math_Bash.dir/main.cpp.i

CMakeFiles/GlobeX_Cup__18_S5___Math_Bash.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GlobeX_Cup__18_S5___Math_Bash.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/allen/Documents/GitHub/Code/Problems/Other/GlobeX Cup '18 S5 - Math Bash/main.cpp" -o CMakeFiles/GlobeX_Cup__18_S5___Math_Bash.dir/main.cpp.s

# Object files for target GlobeX_Cup__18_S5___Math_Bash
GlobeX_Cup__18_S5___Math_Bash_OBJECTS = \
"CMakeFiles/GlobeX_Cup__18_S5___Math_Bash.dir/main.cpp.o"

# External object files for target GlobeX_Cup__18_S5___Math_Bash
GlobeX_Cup__18_S5___Math_Bash_EXTERNAL_OBJECTS =

GlobeX_Cup__18_S5___Math_Bash: CMakeFiles/GlobeX_Cup__18_S5___Math_Bash.dir/main.cpp.o
GlobeX_Cup__18_S5___Math_Bash: CMakeFiles/GlobeX_Cup__18_S5___Math_Bash.dir/build.make
GlobeX_Cup__18_S5___Math_Bash: CMakeFiles/GlobeX_Cup__18_S5___Math_Bash.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/allen/Documents/GitHub/Code/Problems/Other/GlobeX Cup '18 S5 - Math Bash/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable GlobeX_Cup__18_S5___Math_Bash"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/GlobeX_Cup__18_S5___Math_Bash.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/GlobeX_Cup__18_S5___Math_Bash.dir/build: GlobeX_Cup__18_S5___Math_Bash

.PHONY : CMakeFiles/GlobeX_Cup__18_S5___Math_Bash.dir/build

CMakeFiles/GlobeX_Cup__18_S5___Math_Bash.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/GlobeX_Cup__18_S5___Math_Bash.dir/cmake_clean.cmake
.PHONY : CMakeFiles/GlobeX_Cup__18_S5___Math_Bash.dir/clean

CMakeFiles/GlobeX_Cup__18_S5___Math_Bash.dir/depend:
	cd "/Users/allen/Documents/GitHub/Code/Problems/Other/GlobeX Cup '18 S5 - Math Bash/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/allen/Documents/GitHub/Code/Problems/Other/GlobeX Cup '18 S5 - Math Bash" "/Users/allen/Documents/GitHub/Code/Problems/Other/GlobeX Cup '18 S5 - Math Bash" "/Users/allen/Documents/GitHub/Code/Problems/Other/GlobeX Cup '18 S5 - Math Bash/cmake-build-debug" "/Users/allen/Documents/GitHub/Code/Problems/Other/GlobeX Cup '18 S5 - Math Bash/cmake-build-debug" "/Users/allen/Documents/GitHub/Code/Problems/Other/GlobeX Cup '18 S5 - Math Bash/cmake-build-debug/CMakeFiles/GlobeX_Cup__18_S5___Math_Bash.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/GlobeX_Cup__18_S5___Math_Bash.dir/depend
