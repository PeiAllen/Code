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
CMAKE_SOURCE_DIR = "/Users/allen/CLionProjects/1095. Nikifor 3 "

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/allen/CLionProjects/1095. Nikifor 3 /cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/1095__Nikifor_3_.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/1095__Nikifor_3_.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/1095__Nikifor_3_.dir/flags.make

CMakeFiles/1095__Nikifor_3_.dir/main.cpp.o: CMakeFiles/1095__Nikifor_3_.dir/flags.make
CMakeFiles/1095__Nikifor_3_.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/allen/CLionProjects/1095. Nikifor 3 /cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/1095__Nikifor_3_.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/1095__Nikifor_3_.dir/main.cpp.o -c "/Users/allen/CLionProjects/1095. Nikifor 3 /main.cpp"

CMakeFiles/1095__Nikifor_3_.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/1095__Nikifor_3_.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/allen/CLionProjects/1095. Nikifor 3 /main.cpp" > CMakeFiles/1095__Nikifor_3_.dir/main.cpp.i

CMakeFiles/1095__Nikifor_3_.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/1095__Nikifor_3_.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/allen/CLionProjects/1095. Nikifor 3 /main.cpp" -o CMakeFiles/1095__Nikifor_3_.dir/main.cpp.s

# Object files for target 1095__Nikifor_3_
1095__Nikifor_3__OBJECTS = \
"CMakeFiles/1095__Nikifor_3_.dir/main.cpp.o"

# External object files for target 1095__Nikifor_3_
1095__Nikifor_3__EXTERNAL_OBJECTS =

1095__Nikifor_3_: CMakeFiles/1095__Nikifor_3_.dir/main.cpp.o
1095__Nikifor_3_: CMakeFiles/1095__Nikifor_3_.dir/build.make
1095__Nikifor_3_: CMakeFiles/1095__Nikifor_3_.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/allen/CLionProjects/1095. Nikifor 3 /cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 1095__Nikifor_3_"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/1095__Nikifor_3_.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/1095__Nikifor_3_.dir/build: 1095__Nikifor_3_

.PHONY : CMakeFiles/1095__Nikifor_3_.dir/build

CMakeFiles/1095__Nikifor_3_.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/1095__Nikifor_3_.dir/cmake_clean.cmake
.PHONY : CMakeFiles/1095__Nikifor_3_.dir/clean

CMakeFiles/1095__Nikifor_3_.dir/depend:
	cd "/Users/allen/CLionProjects/1095. Nikifor 3 /cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/allen/CLionProjects/1095. Nikifor 3 " "/Users/allen/CLionProjects/1095. Nikifor 3 " "/Users/allen/CLionProjects/1095. Nikifor 3 /cmake-build-debug" "/Users/allen/CLionProjects/1095. Nikifor 3 /cmake-build-debug" "/Users/allen/CLionProjects/1095. Nikifor 3 /cmake-build-debug/CMakeFiles/1095__Nikifor_3_.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/1095__Nikifor_3_.dir/depend

