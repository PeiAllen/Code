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
CMAKE_SOURCE_DIR = "/Users/allen/Documents/GitHub/Code/Problems/CEOI/CEOI '19 Practice P3 - Tower Defense"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/allen/Documents/GitHub/Code/Problems/CEOI/CEOI '19 Practice P3 - Tower Defense/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/CEOI__19_Practice_P3___Tower_Defense.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CEOI__19_Practice_P3___Tower_Defense.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CEOI__19_Practice_P3___Tower_Defense.dir/flags.make

CMakeFiles/CEOI__19_Practice_P3___Tower_Defense.dir/main.cpp.o: CMakeFiles/CEOI__19_Practice_P3___Tower_Defense.dir/flags.make
CMakeFiles/CEOI__19_Practice_P3___Tower_Defense.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/allen/Documents/GitHub/Code/Problems/CEOI/CEOI '19 Practice P3 - Tower Defense/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CEOI__19_Practice_P3___Tower_Defense.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CEOI__19_Practice_P3___Tower_Defense.dir/main.cpp.o -c "/Users/allen/Documents/GitHub/Code/Problems/CEOI/CEOI '19 Practice P3 - Tower Defense/main.cpp"

CMakeFiles/CEOI__19_Practice_P3___Tower_Defense.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CEOI__19_Practice_P3___Tower_Defense.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/allen/Documents/GitHub/Code/Problems/CEOI/CEOI '19 Practice P3 - Tower Defense/main.cpp" > CMakeFiles/CEOI__19_Practice_P3___Tower_Defense.dir/main.cpp.i

CMakeFiles/CEOI__19_Practice_P3___Tower_Defense.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CEOI__19_Practice_P3___Tower_Defense.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/allen/Documents/GitHub/Code/Problems/CEOI/CEOI '19 Practice P3 - Tower Defense/main.cpp" -o CMakeFiles/CEOI__19_Practice_P3___Tower_Defense.dir/main.cpp.s

# Object files for target CEOI__19_Practice_P3___Tower_Defense
CEOI__19_Practice_P3___Tower_Defense_OBJECTS = \
"CMakeFiles/CEOI__19_Practice_P3___Tower_Defense.dir/main.cpp.o"

# External object files for target CEOI__19_Practice_P3___Tower_Defense
CEOI__19_Practice_P3___Tower_Defense_EXTERNAL_OBJECTS =

CEOI__19_Practice_P3___Tower_Defense: CMakeFiles/CEOI__19_Practice_P3___Tower_Defense.dir/main.cpp.o
CEOI__19_Practice_P3___Tower_Defense: CMakeFiles/CEOI__19_Practice_P3___Tower_Defense.dir/build.make
CEOI__19_Practice_P3___Tower_Defense: CMakeFiles/CEOI__19_Practice_P3___Tower_Defense.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/allen/Documents/GitHub/Code/Problems/CEOI/CEOI '19 Practice P3 - Tower Defense/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable CEOI__19_Practice_P3___Tower_Defense"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CEOI__19_Practice_P3___Tower_Defense.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CEOI__19_Practice_P3___Tower_Defense.dir/build: CEOI__19_Practice_P3___Tower_Defense

.PHONY : CMakeFiles/CEOI__19_Practice_P3___Tower_Defense.dir/build

CMakeFiles/CEOI__19_Practice_P3___Tower_Defense.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CEOI__19_Practice_P3___Tower_Defense.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CEOI__19_Practice_P3___Tower_Defense.dir/clean

CMakeFiles/CEOI__19_Practice_P3___Tower_Defense.dir/depend:
	cd "/Users/allen/Documents/GitHub/Code/Problems/CEOI/CEOI '19 Practice P3 - Tower Defense/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/allen/Documents/GitHub/Code/Problems/CEOI/CEOI '19 Practice P3 - Tower Defense" "/Users/allen/Documents/GitHub/Code/Problems/CEOI/CEOI '19 Practice P3 - Tower Defense" "/Users/allen/Documents/GitHub/Code/Problems/CEOI/CEOI '19 Practice P3 - Tower Defense/cmake-build-debug" "/Users/allen/Documents/GitHub/Code/Problems/CEOI/CEOI '19 Practice P3 - Tower Defense/cmake-build-debug" "/Users/allen/Documents/GitHub/Code/Problems/CEOI/CEOI '19 Practice P3 - Tower Defense/cmake-build-debug/CMakeFiles/CEOI__19_Practice_P3___Tower_Defense.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/CEOI__19_Practice_P3___Tower_Defense.dir/depend

