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
CMAKE_SOURCE_DIR = C:\Users\allen\Documents\Code\Problems\Other\Lvl6biweeklyfeb8

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\allen\Documents\Code\Problems\Other\Lvl6biweeklyfeb8\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Lvl6biweeklyfeb8.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Lvl6biweeklyfeb8.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Lvl6biweeklyfeb8.dir/flags.make

CMakeFiles/Lvl6biweeklyfeb8.dir/main.cpp.obj: CMakeFiles/Lvl6biweeklyfeb8.dir/flags.make
CMakeFiles/Lvl6biweeklyfeb8.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\allen\Documents\Code\Problems\Other\Lvl6biweeklyfeb8\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Lvl6biweeklyfeb8.dir/main.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Lvl6biweeklyfeb8.dir\main.cpp.obj -c C:\Users\allen\Documents\Code\Problems\Other\Lvl6biweeklyfeb8\main.cpp

CMakeFiles/Lvl6biweeklyfeb8.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lvl6biweeklyfeb8.dir/main.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\allen\Documents\Code\Problems\Other\Lvl6biweeklyfeb8\main.cpp > CMakeFiles\Lvl6biweeklyfeb8.dir\main.cpp.i

CMakeFiles/Lvl6biweeklyfeb8.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lvl6biweeklyfeb8.dir/main.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\allen\Documents\Code\Problems\Other\Lvl6biweeklyfeb8\main.cpp -o CMakeFiles\Lvl6biweeklyfeb8.dir\main.cpp.s

# Object files for target Lvl6biweeklyfeb8
Lvl6biweeklyfeb8_OBJECTS = \
"CMakeFiles/Lvl6biweeklyfeb8.dir/main.cpp.obj"

# External object files for target Lvl6biweeklyfeb8
Lvl6biweeklyfeb8_EXTERNAL_OBJECTS =

Lvl6biweeklyfeb8.exe: CMakeFiles/Lvl6biweeklyfeb8.dir/main.cpp.obj
Lvl6biweeklyfeb8.exe: CMakeFiles/Lvl6biweeklyfeb8.dir/build.make
Lvl6biweeklyfeb8.exe: CMakeFiles/Lvl6biweeklyfeb8.dir/linklibs.rsp
Lvl6biweeklyfeb8.exe: CMakeFiles/Lvl6biweeklyfeb8.dir/objects1.rsp
Lvl6biweeklyfeb8.exe: CMakeFiles/Lvl6biweeklyfeb8.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\allen\Documents\Code\Problems\Other\Lvl6biweeklyfeb8\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Lvl6biweeklyfeb8.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Lvl6biweeklyfeb8.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Lvl6biweeklyfeb8.dir/build: Lvl6biweeklyfeb8.exe

.PHONY : CMakeFiles/Lvl6biweeklyfeb8.dir/build

CMakeFiles/Lvl6biweeklyfeb8.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Lvl6biweeklyfeb8.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Lvl6biweeklyfeb8.dir/clean

CMakeFiles/Lvl6biweeklyfeb8.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\allen\Documents\Code\Problems\Other\Lvl6biweeklyfeb8 C:\Users\allen\Documents\Code\Problems\Other\Lvl6biweeklyfeb8 C:\Users\allen\Documents\Code\Problems\Other\Lvl6biweeklyfeb8\cmake-build-debug C:\Users\allen\Documents\Code\Problems\Other\Lvl6biweeklyfeb8\cmake-build-debug C:\Users\allen\Documents\Code\Problems\Other\Lvl6biweeklyfeb8\cmake-build-debug\CMakeFiles\Lvl6biweeklyfeb8.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Lvl6biweeklyfeb8.dir/depend
