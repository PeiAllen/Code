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
CMAKE_SOURCE_DIR = C:\Users\allen\CLionProjects\Slimes

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\allen\CLionProjects\Slimes\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Slimes.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Slimes.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Slimes.dir/flags.make

CMakeFiles/Slimes.dir/main.cpp.obj: CMakeFiles/Slimes.dir/flags.make
CMakeFiles/Slimes.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\allen\CLionProjects\Slimes\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Slimes.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Slimes.dir\main.cpp.obj -c C:\Users\allen\CLionProjects\Slimes\main.cpp

CMakeFiles/Slimes.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Slimes.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\allen\CLionProjects\Slimes\main.cpp > CMakeFiles\Slimes.dir\main.cpp.i

CMakeFiles/Slimes.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Slimes.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\allen\CLionProjects\Slimes\main.cpp -o CMakeFiles\Slimes.dir\main.cpp.s

# Object files for target Slimes
Slimes_OBJECTS = \
"CMakeFiles/Slimes.dir/main.cpp.obj"

# External object files for target Slimes
Slimes_EXTERNAL_OBJECTS =

Slimes.exe: CMakeFiles/Slimes.dir/main.cpp.obj
Slimes.exe: CMakeFiles/Slimes.dir/build.make
Slimes.exe: CMakeFiles/Slimes.dir/linklibs.rsp
Slimes.exe: CMakeFiles/Slimes.dir/objects1.rsp
Slimes.exe: CMakeFiles/Slimes.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\allen\CLionProjects\Slimes\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Slimes.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Slimes.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Slimes.dir/build: Slimes.exe

.PHONY : CMakeFiles/Slimes.dir/build

CMakeFiles/Slimes.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Slimes.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Slimes.dir/clean

CMakeFiles/Slimes.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\allen\CLionProjects\Slimes C:\Users\allen\CLionProjects\Slimes C:\Users\allen\CLionProjects\Slimes\cmake-build-debug C:\Users\allen\CLionProjects\Slimes\cmake-build-debug C:\Users\allen\CLionProjects\Slimes\cmake-build-debug\CMakeFiles\Slimes.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Slimes.dir/depend

