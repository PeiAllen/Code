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
CMAKE_SOURCE_DIR = /Users/allen/Documents/GitHub/Code/Problems/Other/cyclefinder

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/allen/Documents/GitHub/Code/Problems/Other/cyclefinder/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/cyclefinder.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cyclefinder.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cyclefinder.dir/flags.make

CMakeFiles/cyclefinder.dir/main.cpp.o: CMakeFiles/cyclefinder.dir/flags.make
CMakeFiles/cyclefinder.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/allen/Documents/GitHub/Code/Problems/Other/cyclefinder/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cyclefinder.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cyclefinder.dir/main.cpp.o -c /Users/allen/Documents/GitHub/Code/Problems/Other/cyclefinder/main.cpp

CMakeFiles/cyclefinder.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cyclefinder.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/allen/Documents/GitHub/Code/Problems/Other/cyclefinder/main.cpp > CMakeFiles/cyclefinder.dir/main.cpp.i

CMakeFiles/cyclefinder.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cyclefinder.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/allen/Documents/GitHub/Code/Problems/Other/cyclefinder/main.cpp -o CMakeFiles/cyclefinder.dir/main.cpp.s

# Object files for target cyclefinder
cyclefinder_OBJECTS = \
"CMakeFiles/cyclefinder.dir/main.cpp.o"

# External object files for target cyclefinder
cyclefinder_EXTERNAL_OBJECTS =

cyclefinder: CMakeFiles/cyclefinder.dir/main.cpp.o
cyclefinder: CMakeFiles/cyclefinder.dir/build.make
cyclefinder: CMakeFiles/cyclefinder.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/allen/Documents/GitHub/Code/Problems/Other/cyclefinder/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable cyclefinder"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cyclefinder.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cyclefinder.dir/build: cyclefinder

.PHONY : CMakeFiles/cyclefinder.dir/build

CMakeFiles/cyclefinder.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cyclefinder.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cyclefinder.dir/clean

CMakeFiles/cyclefinder.dir/depend:
	cd /Users/allen/Documents/GitHub/Code/Problems/Other/cyclefinder/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/allen/Documents/GitHub/Code/Problems/Other/cyclefinder /Users/allen/Documents/GitHub/Code/Problems/Other/cyclefinder /Users/allen/Documents/GitHub/Code/Problems/Other/cyclefinder/cmake-build-debug /Users/allen/Documents/GitHub/Code/Problems/Other/cyclefinder/cmake-build-debug /Users/allen/Documents/GitHub/Code/Problems/Other/cyclefinder/cmake-build-debug/CMakeFiles/cyclefinder.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cyclefinder.dir/depend
