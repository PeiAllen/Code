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
CMAKE_SOURCE_DIR = "/Users/allen/Documents/GitHub/Code/Problems/Other/Dynamic Range K-th Number Query 2"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/allen/Documents/GitHub/Code/Problems/Other/Dynamic Range K-th Number Query 2/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Dynamic_Range_K_th_Number_Query_2_.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Dynamic_Range_K_th_Number_Query_2_.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Dynamic_Range_K_th_Number_Query_2_.dir/flags.make

CMakeFiles/Dynamic_Range_K_th_Number_Query_2_.dir/main.cpp.o: CMakeFiles/Dynamic_Range_K_th_Number_Query_2_.dir/flags.make
CMakeFiles/Dynamic_Range_K_th_Number_Query_2_.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/allen/Documents/GitHub/Code/Problems/Other/Dynamic Range K-th Number Query 2/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Dynamic_Range_K_th_Number_Query_2_.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Dynamic_Range_K_th_Number_Query_2_.dir/main.cpp.o -c "/Users/allen/Documents/GitHub/Code/Problems/Other/Dynamic Range K-th Number Query 2/main.cpp"

CMakeFiles/Dynamic_Range_K_th_Number_Query_2_.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Dynamic_Range_K_th_Number_Query_2_.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/allen/Documents/GitHub/Code/Problems/Other/Dynamic Range K-th Number Query 2/main.cpp" > CMakeFiles/Dynamic_Range_K_th_Number_Query_2_.dir/main.cpp.i

CMakeFiles/Dynamic_Range_K_th_Number_Query_2_.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Dynamic_Range_K_th_Number_Query_2_.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/allen/Documents/GitHub/Code/Problems/Other/Dynamic Range K-th Number Query 2/main.cpp" -o CMakeFiles/Dynamic_Range_K_th_Number_Query_2_.dir/main.cpp.s

# Object files for target Dynamic_Range_K_th_Number_Query_2_
Dynamic_Range_K_th_Number_Query_2__OBJECTS = \
"CMakeFiles/Dynamic_Range_K_th_Number_Query_2_.dir/main.cpp.o"

# External object files for target Dynamic_Range_K_th_Number_Query_2_
Dynamic_Range_K_th_Number_Query_2__EXTERNAL_OBJECTS =

Dynamic_Range_K_th_Number_Query_2_: CMakeFiles/Dynamic_Range_K_th_Number_Query_2_.dir/main.cpp.o
Dynamic_Range_K_th_Number_Query_2_: CMakeFiles/Dynamic_Range_K_th_Number_Query_2_.dir/build.make
Dynamic_Range_K_th_Number_Query_2_: CMakeFiles/Dynamic_Range_K_th_Number_Query_2_.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/allen/Documents/GitHub/Code/Problems/Other/Dynamic Range K-th Number Query 2/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Dynamic_Range_K_th_Number_Query_2_"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Dynamic_Range_K_th_Number_Query_2_.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Dynamic_Range_K_th_Number_Query_2_.dir/build: Dynamic_Range_K_th_Number_Query_2_

.PHONY : CMakeFiles/Dynamic_Range_K_th_Number_Query_2_.dir/build

CMakeFiles/Dynamic_Range_K_th_Number_Query_2_.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Dynamic_Range_K_th_Number_Query_2_.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Dynamic_Range_K_th_Number_Query_2_.dir/clean

CMakeFiles/Dynamic_Range_K_th_Number_Query_2_.dir/depend:
	cd "/Users/allen/Documents/GitHub/Code/Problems/Other/Dynamic Range K-th Number Query 2/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/allen/Documents/GitHub/Code/Problems/Other/Dynamic Range K-th Number Query 2" "/Users/allen/Documents/GitHub/Code/Problems/Other/Dynamic Range K-th Number Query 2" "/Users/allen/Documents/GitHub/Code/Problems/Other/Dynamic Range K-th Number Query 2/cmake-build-debug" "/Users/allen/Documents/GitHub/Code/Problems/Other/Dynamic Range K-th Number Query 2/cmake-build-debug" "/Users/allen/Documents/GitHub/Code/Problems/Other/Dynamic Range K-th Number Query 2/cmake-build-debug/CMakeFiles/Dynamic_Range_K_th_Number_Query_2_.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Dynamic_Range_K_th_Number_Query_2_.dir/depend

