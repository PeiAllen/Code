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
CMAKE_SOURCE_DIR = "/Users/allen/Documents/GitHub/Code/Code/Other/Allen's Segments "

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/allen/Documents/GitHub/Code/Code/Other/Allen's Segments /cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Allen_s_Segments_.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Allen_s_Segments_.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Allen_s_Segments_.dir/flags.make

CMakeFiles/Allen_s_Segments_.dir/main.cpp.o: CMakeFiles/Allen_s_Segments_.dir/flags.make
CMakeFiles/Allen_s_Segments_.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/allen/Documents/GitHub/Code/Code/Other/Allen's Segments /cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Allen_s_Segments_.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Allen_s_Segments_.dir/main.cpp.o -c "/Users/allen/Documents/GitHub/Code/Code/Other/Allen's Segments /main.cpp"

CMakeFiles/Allen_s_Segments_.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Allen_s_Segments_.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/allen/Documents/GitHub/Code/Code/Other/Allen's Segments /main.cpp" > CMakeFiles/Allen_s_Segments_.dir/main.cpp.i

CMakeFiles/Allen_s_Segments_.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Allen_s_Segments_.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/allen/Documents/GitHub/Code/Code/Other/Allen's Segments /main.cpp" -o CMakeFiles/Allen_s_Segments_.dir/main.cpp.s

# Object files for target Allen_s_Segments_
Allen_s_Segments__OBJECTS = \
"CMakeFiles/Allen_s_Segments_.dir/main.cpp.o"

# External object files for target Allen_s_Segments_
Allen_s_Segments__EXTERNAL_OBJECTS =

Allen_s_Segments_: CMakeFiles/Allen_s_Segments_.dir/main.cpp.o
Allen_s_Segments_: CMakeFiles/Allen_s_Segments_.dir/build.make
Allen_s_Segments_: CMakeFiles/Allen_s_Segments_.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/allen/Documents/GitHub/Code/Code/Other/Allen's Segments /cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Allen_s_Segments_"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Allen_s_Segments_.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Allen_s_Segments_.dir/build: Allen_s_Segments_

.PHONY : CMakeFiles/Allen_s_Segments_.dir/build

CMakeFiles/Allen_s_Segments_.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Allen_s_Segments_.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Allen_s_Segments_.dir/clean

CMakeFiles/Allen_s_Segments_.dir/depend:
	cd "/Users/allen/Documents/GitHub/Code/Code/Other/Allen's Segments /cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/allen/Documents/GitHub/Code/Code/Other/Allen's Segments " "/Users/allen/Documents/GitHub/Code/Code/Other/Allen's Segments " "/Users/allen/Documents/GitHub/Code/Code/Other/Allen's Segments /cmake-build-debug" "/Users/allen/Documents/GitHub/Code/Code/Other/Allen's Segments /cmake-build-debug" "/Users/allen/Documents/GitHub/Code/Code/Other/Allen's Segments /cmake-build-debug/CMakeFiles/Allen_s_Segments_.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Allen_s_Segments_.dir/depend

