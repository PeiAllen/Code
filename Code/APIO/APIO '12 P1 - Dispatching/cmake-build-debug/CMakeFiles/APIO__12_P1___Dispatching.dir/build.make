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
CMAKE_SOURCE_DIR = "C:\Users\allen\CLionProjects\APIO '12 P1 - Dispatching"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\allen\CLionProjects\APIO '12 P1 - Dispatching\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/APIO__12_P1___Dispatching.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/APIO__12_P1___Dispatching.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/APIO__12_P1___Dispatching.dir/flags.make

CMakeFiles/APIO__12_P1___Dispatching.dir/main.cpp.obj: CMakeFiles/APIO__12_P1___Dispatching.dir/flags.make
CMakeFiles/APIO__12_P1___Dispatching.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\allen\CLionProjects\APIO '12 P1 - Dispatching\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/APIO__12_P1___Dispatching.dir/main.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\APIO__12_P1___Dispatching.dir\main.cpp.obj -c "C:\Users\allen\CLionProjects\APIO '12 P1 - Dispatching\main.cpp"

CMakeFiles/APIO__12_P1___Dispatching.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/APIO__12_P1___Dispatching.dir/main.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\allen\CLionProjects\APIO '12 P1 - Dispatching\main.cpp" > CMakeFiles\APIO__12_P1___Dispatching.dir\main.cpp.i

CMakeFiles/APIO__12_P1___Dispatching.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/APIO__12_P1___Dispatching.dir/main.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\allen\CLionProjects\APIO '12 P1 - Dispatching\main.cpp" -o CMakeFiles\APIO__12_P1___Dispatching.dir\main.cpp.s

# Object files for target APIO__12_P1___Dispatching
APIO__12_P1___Dispatching_OBJECTS = \
"CMakeFiles/APIO__12_P1___Dispatching.dir/main.cpp.obj"

# External object files for target APIO__12_P1___Dispatching
APIO__12_P1___Dispatching_EXTERNAL_OBJECTS =

APIO__12_P1___Dispatching.exe: CMakeFiles/APIO__12_P1___Dispatching.dir/main.cpp.obj
APIO__12_P1___Dispatching.exe: CMakeFiles/APIO__12_P1___Dispatching.dir/build.make
APIO__12_P1___Dispatching.exe: CMakeFiles/APIO__12_P1___Dispatching.dir/linklibs.rsp
APIO__12_P1___Dispatching.exe: CMakeFiles/APIO__12_P1___Dispatching.dir/objects1.rsp
APIO__12_P1___Dispatching.exe: CMakeFiles/APIO__12_P1___Dispatching.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\allen\CLionProjects\APIO '12 P1 - Dispatching\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable APIO__12_P1___Dispatching.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\APIO__12_P1___Dispatching.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/APIO__12_P1___Dispatching.dir/build: APIO__12_P1___Dispatching.exe

.PHONY : CMakeFiles/APIO__12_P1___Dispatching.dir/build

CMakeFiles/APIO__12_P1___Dispatching.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\APIO__12_P1___Dispatching.dir\cmake_clean.cmake
.PHONY : CMakeFiles/APIO__12_P1___Dispatching.dir/clean

CMakeFiles/APIO__12_P1___Dispatching.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\allen\CLionProjects\APIO '12 P1 - Dispatching" "C:\Users\allen\CLionProjects\APIO '12 P1 - Dispatching" "C:\Users\allen\CLionProjects\APIO '12 P1 - Dispatching\cmake-build-debug" "C:\Users\allen\CLionProjects\APIO '12 P1 - Dispatching\cmake-build-debug" "C:\Users\allen\CLionProjects\APIO '12 P1 - Dispatching\cmake-build-debug\CMakeFiles\APIO__12_P1___Dispatching.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/APIO__12_P1___Dispatching.dir/depend
