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
CMAKE_SOURCE_DIR = /Users/allen/Documents/GitHub/Code/Problems/CCC/CCC2020Senior

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/allen/Documents/GitHub/Code/Problems/CCC/CCC2020Senior/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/CCC2020Senior.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CCC2020Senior.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CCC2020Senior.dir/flags.make

CMakeFiles/CCC2020Senior.dir/main.cpp.o: CMakeFiles/CCC2020Senior.dir/flags.make
CMakeFiles/CCC2020Senior.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/allen/Documents/GitHub/Code/Problems/CCC/CCC2020Senior/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CCC2020Senior.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CCC2020Senior.dir/main.cpp.o -c /Users/allen/Documents/GitHub/Code/Problems/CCC/CCC2020Senior/main.cpp

CMakeFiles/CCC2020Senior.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CCC2020Senior.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/allen/Documents/GitHub/Code/Problems/CCC/CCC2020Senior/main.cpp > CMakeFiles/CCC2020Senior.dir/main.cpp.i

CMakeFiles/CCC2020Senior.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CCC2020Senior.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/allen/Documents/GitHub/Code/Problems/CCC/CCC2020Senior/main.cpp -o CMakeFiles/CCC2020Senior.dir/main.cpp.s

# Object files for target CCC2020Senior
CCC2020Senior_OBJECTS = \
"CMakeFiles/CCC2020Senior.dir/main.cpp.o"

# External object files for target CCC2020Senior
CCC2020Senior_EXTERNAL_OBJECTS =

CCC2020Senior: CMakeFiles/CCC2020Senior.dir/main.cpp.o
CCC2020Senior: CMakeFiles/CCC2020Senior.dir/build.make
CCC2020Senior: CMakeFiles/CCC2020Senior.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/allen/Documents/GitHub/Code/Problems/CCC/CCC2020Senior/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable CCC2020Senior"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CCC2020Senior.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CCC2020Senior.dir/build: CCC2020Senior

.PHONY : CMakeFiles/CCC2020Senior.dir/build

CMakeFiles/CCC2020Senior.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CCC2020Senior.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CCC2020Senior.dir/clean

CMakeFiles/CCC2020Senior.dir/depend:
	cd /Users/allen/Documents/GitHub/Code/Problems/CCC/CCC2020Senior/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/allen/Documents/GitHub/Code/Problems/CCC/CCC2020Senior /Users/allen/Documents/GitHub/Code/Problems/CCC/CCC2020Senior /Users/allen/Documents/GitHub/Code/Problems/CCC/CCC2020Senior/cmake-build-debug /Users/allen/Documents/GitHub/Code/Problems/CCC/CCC2020Senior/cmake-build-debug /Users/allen/Documents/GitHub/Code/Problems/CCC/CCC2020Senior/cmake-build-debug/CMakeFiles/CCC2020Senior.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CCC2020Senior.dir/depend
