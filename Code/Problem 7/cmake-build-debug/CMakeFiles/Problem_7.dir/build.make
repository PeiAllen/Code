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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.1.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.1.3\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\allen\CLionProjects\Problem 7"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\allen\CLionProjects\Problem 7\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Problem_7.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Problem_7.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Problem_7.dir/flags.make

CMakeFiles/Problem_7.dir/main.cpp.obj: CMakeFiles/Problem_7.dir/flags.make
CMakeFiles/Problem_7.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\allen\CLionProjects\Problem 7\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Problem_7.dir/main.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Problem_7.dir\main.cpp.obj -c "C:\Users\allen\CLionProjects\Problem 7\main.cpp"

CMakeFiles/Problem_7.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Problem_7.dir/main.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\allen\CLionProjects\Problem 7\main.cpp" > CMakeFiles\Problem_7.dir\main.cpp.i

CMakeFiles/Problem_7.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Problem_7.dir/main.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\allen\CLionProjects\Problem 7\main.cpp" -o CMakeFiles\Problem_7.dir\main.cpp.s

# Object files for target Problem_7
Problem_7_OBJECTS = \
"CMakeFiles/Problem_7.dir/main.cpp.obj"

# External object files for target Problem_7
Problem_7_EXTERNAL_OBJECTS =

Problem_7.exe: CMakeFiles/Problem_7.dir/main.cpp.obj
Problem_7.exe: CMakeFiles/Problem_7.dir/build.make
Problem_7.exe: CMakeFiles/Problem_7.dir/linklibs.rsp
Problem_7.exe: CMakeFiles/Problem_7.dir/objects1.rsp
Problem_7.exe: CMakeFiles/Problem_7.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\allen\CLionProjects\Problem 7\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Problem_7.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Problem_7.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Problem_7.dir/build: Problem_7.exe

.PHONY : CMakeFiles/Problem_7.dir/build

CMakeFiles/Problem_7.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Problem_7.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Problem_7.dir/clean

CMakeFiles/Problem_7.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\allen\CLionProjects\Problem 7" "C:\Users\allen\CLionProjects\Problem 7" "C:\Users\allen\CLionProjects\Problem 7\cmake-build-debug" "C:\Users\allen\CLionProjects\Problem 7\cmake-build-debug" "C:\Users\allen\CLionProjects\Problem 7\cmake-build-debug\CMakeFiles\Problem_7.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Problem_7.dir/depend

