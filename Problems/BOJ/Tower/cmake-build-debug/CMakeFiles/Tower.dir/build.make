# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.2.5\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.2.5\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\allen\Documents\Github\Code\Problems\BOJ\Tower

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\allen\Documents\Github\Code\Problems\BOJ\Tower\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Tower.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Tower.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Tower.dir/flags.make

CMakeFiles/Tower.dir/main.cpp.obj: CMakeFiles/Tower.dir/flags.make
CMakeFiles/Tower.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\allen\Documents\Github\Code\Problems\BOJ\Tower\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Tower.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Tower.dir\main.cpp.obj -c C:\Users\allen\Documents\Github\Code\Problems\BOJ\Tower\main.cpp

CMakeFiles/Tower.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tower.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\allen\Documents\Github\Code\Problems\BOJ\Tower\main.cpp > CMakeFiles\Tower.dir\main.cpp.i

CMakeFiles/Tower.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tower.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\allen\Documents\Github\Code\Problems\BOJ\Tower\main.cpp -o CMakeFiles\Tower.dir\main.cpp.s

# Object files for target Tower
Tower_OBJECTS = \
"CMakeFiles/Tower.dir/main.cpp.obj"

# External object files for target Tower
Tower_EXTERNAL_OBJECTS =

Tower.exe: CMakeFiles/Tower.dir/main.cpp.obj
Tower.exe: CMakeFiles/Tower.dir/build.make
Tower.exe: CMakeFiles/Tower.dir/linklibs.rsp
Tower.exe: CMakeFiles/Tower.dir/objects1.rsp
Tower.exe: CMakeFiles/Tower.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\allen\Documents\Github\Code\Problems\BOJ\Tower\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Tower.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Tower.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Tower.dir/build: Tower.exe

.PHONY : CMakeFiles/Tower.dir/build

CMakeFiles/Tower.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Tower.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Tower.dir/clean

CMakeFiles/Tower.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\allen\Documents\Github\Code\Problems\BOJ\Tower C:\Users\allen\Documents\Github\Code\Problems\BOJ\Tower C:\Users\allen\Documents\Github\Code\Problems\BOJ\Tower\cmake-build-debug C:\Users\allen\Documents\Github\Code\Problems\BOJ\Tower\cmake-build-debug C:\Users\allen\Documents\Github\Code\Problems\BOJ\Tower\cmake-build-debug\CMakeFiles\Tower.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Tower.dir/depend

