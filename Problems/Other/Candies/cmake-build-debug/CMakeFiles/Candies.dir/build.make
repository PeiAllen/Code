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
CMAKE_SOURCE_DIR = C:\Users\allen\CLionProjects\Candies

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\allen\CLionProjects\Candies\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Candies.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Candies.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Candies.dir/flags.make

CMakeFiles/Candies.dir/main.cpp.obj: CMakeFiles/Candies.dir/flags.make
CMakeFiles/Candies.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\allen\CLionProjects\Candies\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Candies.dir/main.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Candies.dir\main.cpp.obj -c C:\Users\allen\CLionProjects\Candies\main.cpp

CMakeFiles/Candies.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Candies.dir/main.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\allen\CLionProjects\Candies\main.cpp > CMakeFiles\Candies.dir\main.cpp.i

CMakeFiles/Candies.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Candies.dir/main.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\allen\CLionProjects\Candies\main.cpp -o CMakeFiles\Candies.dir\main.cpp.s

# Object files for target Candies
Candies_OBJECTS = \
"CMakeFiles/Candies.dir/main.cpp.obj"

# External object files for target Candies
Candies_EXTERNAL_OBJECTS =

Candies.exe: CMakeFiles/Candies.dir/main.cpp.obj
Candies.exe: CMakeFiles/Candies.dir/build.make
Candies.exe: CMakeFiles/Candies.dir/linklibs.rsp
Candies.exe: CMakeFiles/Candies.dir/objects1.rsp
Candies.exe: CMakeFiles/Candies.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\allen\CLionProjects\Candies\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Candies.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Candies.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Candies.dir/build: Candies.exe

.PHONY : CMakeFiles/Candies.dir/build

CMakeFiles/Candies.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Candies.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Candies.dir/clean

CMakeFiles/Candies.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\allen\CLionProjects\Candies C:\Users\allen\CLionProjects\Candies C:\Users\allen\CLionProjects\Candies\cmake-build-debug C:\Users\allen\CLionProjects\Candies\cmake-build-debug C:\Users\allen\CLionProjects\Candies\cmake-build-debug\CMakeFiles\Candies.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Candies.dir/depend
