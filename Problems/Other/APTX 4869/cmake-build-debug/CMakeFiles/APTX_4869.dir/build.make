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
CMAKE_SOURCE_DIR = "/Users/allen/Documents/GitHub/Code/Problems/Other/APTX 4869"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/allen/Documents/GitHub/Code/Problems/Other/APTX 4869/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/APTX_4869.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/APTX_4869.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/APTX_4869.dir/flags.make

CMakeFiles/APTX_4869.dir/main.cpp.o: CMakeFiles/APTX_4869.dir/flags.make
CMakeFiles/APTX_4869.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/allen/Documents/GitHub/Code/Problems/Other/APTX 4869/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/APTX_4869.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/APTX_4869.dir/main.cpp.o -c "/Users/allen/Documents/GitHub/Code/Problems/Other/APTX 4869/main.cpp"

CMakeFiles/APTX_4869.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/APTX_4869.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/allen/Documents/GitHub/Code/Problems/Other/APTX 4869/main.cpp" > CMakeFiles/APTX_4869.dir/main.cpp.i

CMakeFiles/APTX_4869.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/APTX_4869.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/allen/Documents/GitHub/Code/Problems/Other/APTX 4869/main.cpp" -o CMakeFiles/APTX_4869.dir/main.cpp.s

# Object files for target APTX_4869
APTX_4869_OBJECTS = \
"CMakeFiles/APTX_4869.dir/main.cpp.o"

# External object files for target APTX_4869
APTX_4869_EXTERNAL_OBJECTS =

APTX_4869: CMakeFiles/APTX_4869.dir/main.cpp.o
APTX_4869: CMakeFiles/APTX_4869.dir/build.make
APTX_4869: CMakeFiles/APTX_4869.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/allen/Documents/GitHub/Code/Problems/Other/APTX 4869/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable APTX_4869"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/APTX_4869.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/APTX_4869.dir/build: APTX_4869

.PHONY : CMakeFiles/APTX_4869.dir/build

CMakeFiles/APTX_4869.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/APTX_4869.dir/cmake_clean.cmake
.PHONY : CMakeFiles/APTX_4869.dir/clean

CMakeFiles/APTX_4869.dir/depend:
	cd "/Users/allen/Documents/GitHub/Code/Problems/Other/APTX 4869/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/allen/Documents/GitHub/Code/Problems/Other/APTX 4869" "/Users/allen/Documents/GitHub/Code/Problems/Other/APTX 4869" "/Users/allen/Documents/GitHub/Code/Problems/Other/APTX 4869/cmake-build-debug" "/Users/allen/Documents/GitHub/Code/Problems/Other/APTX 4869/cmake-build-debug" "/Users/allen/Documents/GitHub/Code/Problems/Other/APTX 4869/cmake-build-debug/CMakeFiles/APTX_4869.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/APTX_4869.dir/depend
