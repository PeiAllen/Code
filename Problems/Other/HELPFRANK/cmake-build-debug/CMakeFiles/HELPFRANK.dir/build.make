# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\allen\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\212.5457.51\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\allen\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\212.5457.51\bin\cmake\win\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Other\HELPFRANK

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Other\HELPFRANK\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/HELPFRANK.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/HELPFRANK.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/HELPFRANK.dir/flags.make

CMakeFiles/HELPFRANK.dir/main.cpp.obj: CMakeFiles/HELPFRANK.dir/flags.make
CMakeFiles/HELPFRANK.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Other\HELPFRANK\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/HELPFRANK.dir/main.cpp.obj"
	C:\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\HELPFRANK.dir\main.cpp.obj -c C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Other\HELPFRANK\main.cpp

CMakeFiles/HELPFRANK.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HELPFRANK.dir/main.cpp.i"
	C:\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Other\HELPFRANK\main.cpp > CMakeFiles\HELPFRANK.dir\main.cpp.i

CMakeFiles/HELPFRANK.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HELPFRANK.dir/main.cpp.s"
	C:\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Other\HELPFRANK\main.cpp -o CMakeFiles\HELPFRANK.dir\main.cpp.s

# Object files for target HELPFRANK
HELPFRANK_OBJECTS = \
"CMakeFiles/HELPFRANK.dir/main.cpp.obj"

# External object files for target HELPFRANK
HELPFRANK_EXTERNAL_OBJECTS =

HELPFRANK.exe: CMakeFiles/HELPFRANK.dir/main.cpp.obj
HELPFRANK.exe: CMakeFiles/HELPFRANK.dir/build.make
HELPFRANK.exe: CMakeFiles/HELPFRANK.dir/linklibs.rsp
HELPFRANK.exe: CMakeFiles/HELPFRANK.dir/objects1.rsp
HELPFRANK.exe: CMakeFiles/HELPFRANK.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Other\HELPFRANK\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable HELPFRANK.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\HELPFRANK.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/HELPFRANK.dir/build: HELPFRANK.exe
.PHONY : CMakeFiles/HELPFRANK.dir/build

CMakeFiles/HELPFRANK.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\HELPFRANK.dir\cmake_clean.cmake
.PHONY : CMakeFiles/HELPFRANK.dir/clean

CMakeFiles/HELPFRANK.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Other\HELPFRANK C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Other\HELPFRANK C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Other\HELPFRANK\cmake-build-debug C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Other\HELPFRANK\cmake-build-debug C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Other\HELPFRANK\cmake-build-debug\CMakeFiles\HELPFRANK.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/HELPFRANK.dir/depend

