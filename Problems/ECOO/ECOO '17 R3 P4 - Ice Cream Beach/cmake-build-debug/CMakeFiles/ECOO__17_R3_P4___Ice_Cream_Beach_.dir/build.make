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
CMAKE_SOURCE_DIR = "/Users/allen/Documents/GitHub/Code/Problems/ECOO/ECOO '17 R3 P4 - Ice Cream Beach"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/allen/Documents/GitHub/Code/Problems/ECOO/ECOO '17 R3 P4 - Ice Cream Beach/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/ECOO__17_R3_P4___Ice_Cream_Beach_.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ECOO__17_R3_P4___Ice_Cream_Beach_.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ECOO__17_R3_P4___Ice_Cream_Beach_.dir/flags.make

CMakeFiles/ECOO__17_R3_P4___Ice_Cream_Beach_.dir/main.cpp.o: CMakeFiles/ECOO__17_R3_P4___Ice_Cream_Beach_.dir/flags.make
CMakeFiles/ECOO__17_R3_P4___Ice_Cream_Beach_.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/allen/Documents/GitHub/Code/Problems/ECOO/ECOO '17 R3 P4 - Ice Cream Beach/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ECOO__17_R3_P4___Ice_Cream_Beach_.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ECOO__17_R3_P4___Ice_Cream_Beach_.dir/main.cpp.o -c "/Users/allen/Documents/GitHub/Code/Problems/ECOO/ECOO '17 R3 P4 - Ice Cream Beach/main.cpp"

CMakeFiles/ECOO__17_R3_P4___Ice_Cream_Beach_.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ECOO__17_R3_P4___Ice_Cream_Beach_.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/allen/Documents/GitHub/Code/Problems/ECOO/ECOO '17 R3 P4 - Ice Cream Beach/main.cpp" > CMakeFiles/ECOO__17_R3_P4___Ice_Cream_Beach_.dir/main.cpp.i

CMakeFiles/ECOO__17_R3_P4___Ice_Cream_Beach_.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ECOO__17_R3_P4___Ice_Cream_Beach_.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/allen/Documents/GitHub/Code/Problems/ECOO/ECOO '17 R3 P4 - Ice Cream Beach/main.cpp" -o CMakeFiles/ECOO__17_R3_P4___Ice_Cream_Beach_.dir/main.cpp.s

# Object files for target ECOO__17_R3_P4___Ice_Cream_Beach_
ECOO__17_R3_P4___Ice_Cream_Beach__OBJECTS = \
"CMakeFiles/ECOO__17_R3_P4___Ice_Cream_Beach_.dir/main.cpp.o"

# External object files for target ECOO__17_R3_P4___Ice_Cream_Beach_
ECOO__17_R3_P4___Ice_Cream_Beach__EXTERNAL_OBJECTS =

ECOO__17_R3_P4___Ice_Cream_Beach_: CMakeFiles/ECOO__17_R3_P4___Ice_Cream_Beach_.dir/main.cpp.o
ECOO__17_R3_P4___Ice_Cream_Beach_: CMakeFiles/ECOO__17_R3_P4___Ice_Cream_Beach_.dir/build.make
ECOO__17_R3_P4___Ice_Cream_Beach_: CMakeFiles/ECOO__17_R3_P4___Ice_Cream_Beach_.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/allen/Documents/GitHub/Code/Problems/ECOO/ECOO '17 R3 P4 - Ice Cream Beach/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ECOO__17_R3_P4___Ice_Cream_Beach_"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ECOO__17_R3_P4___Ice_Cream_Beach_.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ECOO__17_R3_P4___Ice_Cream_Beach_.dir/build: ECOO__17_R3_P4___Ice_Cream_Beach_

.PHONY : CMakeFiles/ECOO__17_R3_P4___Ice_Cream_Beach_.dir/build

CMakeFiles/ECOO__17_R3_P4___Ice_Cream_Beach_.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ECOO__17_R3_P4___Ice_Cream_Beach_.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ECOO__17_R3_P4___Ice_Cream_Beach_.dir/clean

CMakeFiles/ECOO__17_R3_P4___Ice_Cream_Beach_.dir/depend:
	cd "/Users/allen/Documents/GitHub/Code/Problems/ECOO/ECOO '17 R3 P4 - Ice Cream Beach/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/allen/Documents/GitHub/Code/Problems/ECOO/ECOO '17 R3 P4 - Ice Cream Beach" "/Users/allen/Documents/GitHub/Code/Problems/ECOO/ECOO '17 R3 P4 - Ice Cream Beach" "/Users/allen/Documents/GitHub/Code/Problems/ECOO/ECOO '17 R3 P4 - Ice Cream Beach/cmake-build-debug" "/Users/allen/Documents/GitHub/Code/Problems/ECOO/ECOO '17 R3 P4 - Ice Cream Beach/cmake-build-debug" "/Users/allen/Documents/GitHub/Code/Problems/ECOO/ECOO '17 R3 P4 - Ice Cream Beach/cmake-build-debug/CMakeFiles/ECOO__17_R3_P4___Ice_Cream_Beach_.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/ECOO__17_R3_P4___Ice_Cream_Beach_.dir/depend

