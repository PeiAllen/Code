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
CMAKE_SOURCE_DIR = "/Users/allen/Documents/GitHub/Code/Problems/COCI/COCI '18 Contest 1 #4 Strah"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/allen/Documents/GitHub/Code/Problems/COCI/COCI '18 Contest 1 #4 Strah/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/COCI__18_Contest_1__4_Strah.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/COCI__18_Contest_1__4_Strah.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/COCI__18_Contest_1__4_Strah.dir/flags.make

CMakeFiles/COCI__18_Contest_1__4_Strah.dir/main.cpp.o: CMakeFiles/COCI__18_Contest_1__4_Strah.dir/flags.make
CMakeFiles/COCI__18_Contest_1__4_Strah.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/allen/Documents/GitHub/Code/Problems/COCI/COCI '18 Contest 1 #4 Strah/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/COCI__18_Contest_1__4_Strah.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/COCI__18_Contest_1__4_Strah.dir/main.cpp.o -c "/Users/allen/Documents/GitHub/Code/Problems/COCI/COCI '18 Contest 1 #4 Strah/main.cpp"

CMakeFiles/COCI__18_Contest_1__4_Strah.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/COCI__18_Contest_1__4_Strah.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/allen/Documents/GitHub/Code/Problems/COCI/COCI '18 Contest 1 #4 Strah/main.cpp" > CMakeFiles/COCI__18_Contest_1__4_Strah.dir/main.cpp.i

CMakeFiles/COCI__18_Contest_1__4_Strah.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/COCI__18_Contest_1__4_Strah.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/allen/Documents/GitHub/Code/Problems/COCI/COCI '18 Contest 1 #4 Strah/main.cpp" -o CMakeFiles/COCI__18_Contest_1__4_Strah.dir/main.cpp.s

# Object files for target COCI__18_Contest_1__4_Strah
COCI__18_Contest_1__4_Strah_OBJECTS = \
"CMakeFiles/COCI__18_Contest_1__4_Strah.dir/main.cpp.o"

# External object files for target COCI__18_Contest_1__4_Strah
COCI__18_Contest_1__4_Strah_EXTERNAL_OBJECTS =

COCI__18_Contest_1__4_Strah: CMakeFiles/COCI__18_Contest_1__4_Strah.dir/main.cpp.o
COCI__18_Contest_1__4_Strah: CMakeFiles/COCI__18_Contest_1__4_Strah.dir/build.make
COCI__18_Contest_1__4_Strah: CMakeFiles/COCI__18_Contest_1__4_Strah.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/allen/Documents/GitHub/Code/Problems/COCI/COCI '18 Contest 1 #4 Strah/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable COCI__18_Contest_1__4_Strah"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/COCI__18_Contest_1__4_Strah.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/COCI__18_Contest_1__4_Strah.dir/build: COCI__18_Contest_1__4_Strah

.PHONY : CMakeFiles/COCI__18_Contest_1__4_Strah.dir/build

CMakeFiles/COCI__18_Contest_1__4_Strah.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/COCI__18_Contest_1__4_Strah.dir/cmake_clean.cmake
.PHONY : CMakeFiles/COCI__18_Contest_1__4_Strah.dir/clean

CMakeFiles/COCI__18_Contest_1__4_Strah.dir/depend:
	cd "/Users/allen/Documents/GitHub/Code/Problems/COCI/COCI '18 Contest 1 #4 Strah/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/allen/Documents/GitHub/Code/Problems/COCI/COCI '18 Contest 1 #4 Strah" "/Users/allen/Documents/GitHub/Code/Problems/COCI/COCI '18 Contest 1 #4 Strah" "/Users/allen/Documents/GitHub/Code/Problems/COCI/COCI '18 Contest 1 #4 Strah/cmake-build-debug" "/Users/allen/Documents/GitHub/Code/Problems/COCI/COCI '18 Contest 1 #4 Strah/cmake-build-debug" "/Users/allen/Documents/GitHub/Code/Problems/COCI/COCI '18 Contest 1 #4 Strah/cmake-build-debug/CMakeFiles/COCI__18_Contest_1__4_Strah.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/COCI__18_Contest_1__4_Strah.dir/depend
