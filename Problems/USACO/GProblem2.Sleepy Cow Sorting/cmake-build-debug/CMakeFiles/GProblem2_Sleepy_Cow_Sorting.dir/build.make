# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.14

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.1.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.1.2\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\USACO\GProblem2.Sleepy Cow Sorting"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\USACO\GProblem2.Sleepy Cow Sorting\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/GProblem2_Sleepy_Cow_Sorting.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/GProblem2_Sleepy_Cow_Sorting.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/GProblem2_Sleepy_Cow_Sorting.dir/flags.make

CMakeFiles/GProblem2_Sleepy_Cow_Sorting.dir/main.cpp.obj: CMakeFiles/GProblem2_Sleepy_Cow_Sorting.dir/flags.make
CMakeFiles/GProblem2_Sleepy_Cow_Sorting.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\USACO\GProblem2.Sleepy Cow Sorting\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/GProblem2_Sleepy_Cow_Sorting.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\GProblem2_Sleepy_Cow_Sorting.dir\main.cpp.obj -c "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\USACO\GProblem2.Sleepy Cow Sorting\main.cpp"

CMakeFiles/GProblem2_Sleepy_Cow_Sorting.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GProblem2_Sleepy_Cow_Sorting.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\USACO\GProblem2.Sleepy Cow Sorting\main.cpp" > CMakeFiles\GProblem2_Sleepy_Cow_Sorting.dir\main.cpp.i

CMakeFiles/GProblem2_Sleepy_Cow_Sorting.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GProblem2_Sleepy_Cow_Sorting.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\USACO\GProblem2.Sleepy Cow Sorting\main.cpp" -o CMakeFiles\GProblem2_Sleepy_Cow_Sorting.dir\main.cpp.s

# Object files for target GProblem2_Sleepy_Cow_Sorting
GProblem2_Sleepy_Cow_Sorting_OBJECTS = \
"CMakeFiles/GProblem2_Sleepy_Cow_Sorting.dir/main.cpp.obj"

# External object files for target GProblem2_Sleepy_Cow_Sorting
GProblem2_Sleepy_Cow_Sorting_EXTERNAL_OBJECTS =

GProblem2_Sleepy_Cow_Sorting.exe: CMakeFiles/GProblem2_Sleepy_Cow_Sorting.dir/main.cpp.obj
GProblem2_Sleepy_Cow_Sorting.exe: CMakeFiles/GProblem2_Sleepy_Cow_Sorting.dir/build.make
GProblem2_Sleepy_Cow_Sorting.exe: CMakeFiles/GProblem2_Sleepy_Cow_Sorting.dir/linklibs.rsp
GProblem2_Sleepy_Cow_Sorting.exe: CMakeFiles/GProblem2_Sleepy_Cow_Sorting.dir/objects1.rsp
GProblem2_Sleepy_Cow_Sorting.exe: CMakeFiles/GProblem2_Sleepy_Cow_Sorting.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\USACO\GProblem2.Sleepy Cow Sorting\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable GProblem2_Sleepy_Cow_Sorting.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\GProblem2_Sleepy_Cow_Sorting.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/GProblem2_Sleepy_Cow_Sorting.dir/build: GProblem2_Sleepy_Cow_Sorting.exe

.PHONY : CMakeFiles/GProblem2_Sleepy_Cow_Sorting.dir/build

CMakeFiles/GProblem2_Sleepy_Cow_Sorting.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\GProblem2_Sleepy_Cow_Sorting.dir\cmake_clean.cmake
.PHONY : CMakeFiles/GProblem2_Sleepy_Cow_Sorting.dir/clean

CMakeFiles/GProblem2_Sleepy_Cow_Sorting.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\USACO\GProblem2.Sleepy Cow Sorting" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\USACO\GProblem2.Sleepy Cow Sorting" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\USACO\GProblem2.Sleepy Cow Sorting\cmake-build-debug" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\USACO\GProblem2.Sleepy Cow Sorting\cmake-build-debug" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\USACO\GProblem2.Sleepy Cow Sorting\cmake-build-debug\CMakeFiles\GProblem2_Sleepy_Cow_Sorting.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/GProblem2_Sleepy_Cow_Sorting.dir/depend
