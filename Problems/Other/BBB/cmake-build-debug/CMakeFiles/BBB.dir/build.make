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
CMAKE_SOURCE_DIR = C:\Users\allen\Documents\Github\Code\Problems\Other\BBB

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\allen\Documents\Github\Code\Problems\Other\BBB\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/BBB.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/BBB.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BBB.dir/flags.make

CMakeFiles/BBB.dir/main.cpp.obj: CMakeFiles/BBB.dir/flags.make
CMakeFiles/BBB.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\allen\Documents\Github\Code\Problems\Other\BBB\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/BBB.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\BBB.dir\main.cpp.obj -c C:\Users\allen\Documents\Github\Code\Problems\Other\BBB\main.cpp

CMakeFiles/BBB.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BBB.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\allen\Documents\Github\Code\Problems\Other\BBB\main.cpp > CMakeFiles\BBB.dir\main.cpp.i

CMakeFiles/BBB.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BBB.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\allen\Documents\Github\Code\Problems\Other\BBB\main.cpp -o CMakeFiles\BBB.dir\main.cpp.s

# Object files for target BBB
BBB_OBJECTS = \
"CMakeFiles/BBB.dir/main.cpp.obj"

# External object files for target BBB
BBB_EXTERNAL_OBJECTS =

BBB.exe: CMakeFiles/BBB.dir/main.cpp.obj
BBB.exe: CMakeFiles/BBB.dir/build.make
BBB.exe: CMakeFiles/BBB.dir/linklibs.rsp
BBB.exe: CMakeFiles/BBB.dir/objects1.rsp
BBB.exe: CMakeFiles/BBB.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\allen\Documents\Github\Code\Problems\Other\BBB\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable BBB.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\BBB.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BBB.dir/build: BBB.exe

.PHONY : CMakeFiles/BBB.dir/build

CMakeFiles/BBB.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\BBB.dir\cmake_clean.cmake
.PHONY : CMakeFiles/BBB.dir/clean

CMakeFiles/BBB.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\allen\Documents\Github\Code\Problems\Other\BBB C:\Users\allen\Documents\Github\Code\Problems\Other\BBB C:\Users\allen\Documents\Github\Code\Problems\Other\BBB\cmake-build-debug C:\Users\allen\Documents\Github\Code\Problems\Other\BBB\cmake-build-debug C:\Users\allen\Documents\Github\Code\Problems\Other\BBB\cmake-build-debug\CMakeFiles\BBB.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/BBB.dir/depend
