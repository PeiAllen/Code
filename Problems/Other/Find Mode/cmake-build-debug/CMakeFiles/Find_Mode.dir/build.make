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
CMAKE_SOURCE_DIR = "C:\Users\allen\CLionProjects\Find Mode"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\allen\CLionProjects\Find Mode\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Find_Mode.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Find_Mode.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Find_Mode.dir/flags.make

CMakeFiles/Find_Mode.dir/main.cpp.obj: CMakeFiles/Find_Mode.dir/flags.make
CMakeFiles/Find_Mode.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\allen\CLionProjects\Find Mode\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Find_Mode.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Find_Mode.dir\main.cpp.obj -c "C:\Users\allen\CLionProjects\Find Mode\main.cpp"

CMakeFiles/Find_Mode.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Find_Mode.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\allen\CLionProjects\Find Mode\main.cpp" > CMakeFiles\Find_Mode.dir\main.cpp.i

CMakeFiles/Find_Mode.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Find_Mode.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\allen\CLionProjects\Find Mode\main.cpp" -o CMakeFiles\Find_Mode.dir\main.cpp.s

# Object files for target Find_Mode
Find_Mode_OBJECTS = \
"CMakeFiles/Find_Mode.dir/main.cpp.obj"

# External object files for target Find_Mode
Find_Mode_EXTERNAL_OBJECTS =

Find_Mode.exe: CMakeFiles/Find_Mode.dir/main.cpp.obj
Find_Mode.exe: CMakeFiles/Find_Mode.dir/build.make
Find_Mode.exe: CMakeFiles/Find_Mode.dir/linklibs.rsp
Find_Mode.exe: CMakeFiles/Find_Mode.dir/objects1.rsp
Find_Mode.exe: CMakeFiles/Find_Mode.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\allen\CLionProjects\Find Mode\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Find_Mode.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Find_Mode.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Find_Mode.dir/build: Find_Mode.exe

.PHONY : CMakeFiles/Find_Mode.dir/build

CMakeFiles/Find_Mode.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Find_Mode.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Find_Mode.dir/clean

CMakeFiles/Find_Mode.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\allen\CLionProjects\Find Mode" "C:\Users\allen\CLionProjects\Find Mode" "C:\Users\allen\CLionProjects\Find Mode\cmake-build-debug" "C:\Users\allen\CLionProjects\Find Mode\cmake-build-debug" "C:\Users\allen\CLionProjects\Find Mode\cmake-build-debug\CMakeFiles\Find_Mode.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Find_Mode.dir/depend
