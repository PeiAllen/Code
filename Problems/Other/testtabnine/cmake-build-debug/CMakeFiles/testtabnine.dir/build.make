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
CMAKE_SOURCE_DIR = C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Other\testtabnine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Other\testtabnine\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/testtabnine.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/testtabnine.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/testtabnine.dir/flags.make

CMakeFiles/testtabnine.dir/main.cpp.obj: CMakeFiles/testtabnine.dir/flags.make
CMakeFiles/testtabnine.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Other\testtabnine\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/testtabnine.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\testtabnine.dir\main.cpp.obj -c C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Other\testtabnine\main.cpp

CMakeFiles/testtabnine.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testtabnine.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Other\testtabnine\main.cpp > CMakeFiles\testtabnine.dir\main.cpp.i

CMakeFiles/testtabnine.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testtabnine.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Other\testtabnine\main.cpp -o CMakeFiles\testtabnine.dir\main.cpp.s

# Object files for target testtabnine
testtabnine_OBJECTS = \
"CMakeFiles/testtabnine.dir/main.cpp.obj"

# External object files for target testtabnine
testtabnine_EXTERNAL_OBJECTS =

testtabnine.exe: CMakeFiles/testtabnine.dir/main.cpp.obj
testtabnine.exe: CMakeFiles/testtabnine.dir/build.make
testtabnine.exe: CMakeFiles/testtabnine.dir/linklibs.rsp
testtabnine.exe: CMakeFiles/testtabnine.dir/objects1.rsp
testtabnine.exe: CMakeFiles/testtabnine.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Other\testtabnine\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable testtabnine.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\testtabnine.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/testtabnine.dir/build: testtabnine.exe

.PHONY : CMakeFiles/testtabnine.dir/build

CMakeFiles/testtabnine.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\testtabnine.dir\cmake_clean.cmake
.PHONY : CMakeFiles/testtabnine.dir/clean

CMakeFiles/testtabnine.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Other\testtabnine C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Other\testtabnine C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Other\testtabnine\cmake-build-debug C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Other\testtabnine\cmake-build-debug C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Other\testtabnine\cmake-build-debug\CMakeFiles\testtabnine.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/testtabnine.dir/depend
