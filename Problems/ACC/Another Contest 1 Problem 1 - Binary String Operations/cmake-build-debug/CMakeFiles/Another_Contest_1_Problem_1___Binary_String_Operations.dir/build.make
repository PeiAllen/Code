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
CMAKE_SOURCE_DIR = "C:\Users\allen\CLionProjects\Another Contest 1 Problem 1 - Binary String Operations"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\allen\CLionProjects\Another Contest 1 Problem 1 - Binary String Operations\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Another_Contest_1_Problem_1___Binary_String_Operations.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Another_Contest_1_Problem_1___Binary_String_Operations.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Another_Contest_1_Problem_1___Binary_String_Operations.dir/flags.make

CMakeFiles/Another_Contest_1_Problem_1___Binary_String_Operations.dir/main.cpp.obj: CMakeFiles/Another_Contest_1_Problem_1___Binary_String_Operations.dir/flags.make
CMakeFiles/Another_Contest_1_Problem_1___Binary_String_Operations.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\allen\CLionProjects\Another Contest 1 Problem 1 - Binary String Operations\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Another_Contest_1_Problem_1___Binary_String_Operations.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Another_Contest_1_Problem_1___Binary_String_Operations.dir\main.cpp.obj -c "C:\Users\allen\CLionProjects\Another Contest 1 Problem 1 - Binary String Operations\main.cpp"

CMakeFiles/Another_Contest_1_Problem_1___Binary_String_Operations.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Another_Contest_1_Problem_1___Binary_String_Operations.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\allen\CLionProjects\Another Contest 1 Problem 1 - Binary String Operations\main.cpp" > CMakeFiles\Another_Contest_1_Problem_1___Binary_String_Operations.dir\main.cpp.i

CMakeFiles/Another_Contest_1_Problem_1___Binary_String_Operations.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Another_Contest_1_Problem_1___Binary_String_Operations.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\allen\CLionProjects\Another Contest 1 Problem 1 - Binary String Operations\main.cpp" -o CMakeFiles\Another_Contest_1_Problem_1___Binary_String_Operations.dir\main.cpp.s

# Object files for target Another_Contest_1_Problem_1___Binary_String_Operations
Another_Contest_1_Problem_1___Binary_String_Operations_OBJECTS = \
"CMakeFiles/Another_Contest_1_Problem_1___Binary_String_Operations.dir/main.cpp.obj"

# External object files for target Another_Contest_1_Problem_1___Binary_String_Operations
Another_Contest_1_Problem_1___Binary_String_Operations_EXTERNAL_OBJECTS =

Another_Contest_1_Problem_1___Binary_String_Operations.exe: CMakeFiles/Another_Contest_1_Problem_1___Binary_String_Operations.dir/main.cpp.obj
Another_Contest_1_Problem_1___Binary_String_Operations.exe: CMakeFiles/Another_Contest_1_Problem_1___Binary_String_Operations.dir/build.make
Another_Contest_1_Problem_1___Binary_String_Operations.exe: CMakeFiles/Another_Contest_1_Problem_1___Binary_String_Operations.dir/linklibs.rsp
Another_Contest_1_Problem_1___Binary_String_Operations.exe: CMakeFiles/Another_Contest_1_Problem_1___Binary_String_Operations.dir/objects1.rsp
Another_Contest_1_Problem_1___Binary_String_Operations.exe: CMakeFiles/Another_Contest_1_Problem_1___Binary_String_Operations.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\allen\CLionProjects\Another Contest 1 Problem 1 - Binary String Operations\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Another_Contest_1_Problem_1___Binary_String_Operations.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Another_Contest_1_Problem_1___Binary_String_Operations.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Another_Contest_1_Problem_1___Binary_String_Operations.dir/build: Another_Contest_1_Problem_1___Binary_String_Operations.exe

.PHONY : CMakeFiles/Another_Contest_1_Problem_1___Binary_String_Operations.dir/build

CMakeFiles/Another_Contest_1_Problem_1___Binary_String_Operations.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Another_Contest_1_Problem_1___Binary_String_Operations.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Another_Contest_1_Problem_1___Binary_String_Operations.dir/clean

CMakeFiles/Another_Contest_1_Problem_1___Binary_String_Operations.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\allen\CLionProjects\Another Contest 1 Problem 1 - Binary String Operations" "C:\Users\allen\CLionProjects\Another Contest 1 Problem 1 - Binary String Operations" "C:\Users\allen\CLionProjects\Another Contest 1 Problem 1 - Binary String Operations\cmake-build-debug" "C:\Users\allen\CLionProjects\Another Contest 1 Problem 1 - Binary String Operations\cmake-build-debug" "C:\Users\allen\CLionProjects\Another Contest 1 Problem 1 - Binary String Operations\cmake-build-debug\CMakeFiles\Another_Contest_1_Problem_1___Binary_String_Operations.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Another_Contest_1_Problem_1___Binary_String_Operations.dir/depend
