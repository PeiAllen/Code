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
CMAKE_SOURCE_DIR = "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Other\Experience Up"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Other\Experience Up\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Experience_Up.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Experience_Up.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Experience_Up.dir/flags.make

CMakeFiles/Experience_Up.dir/main.cpp.obj: CMakeFiles/Experience_Up.dir/flags.make
CMakeFiles/Experience_Up.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Other\Experience Up\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Experience_Up.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Experience_Up.dir\main.cpp.obj -c "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Other\Experience Up\main.cpp"

CMakeFiles/Experience_Up.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Experience_Up.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Other\Experience Up\main.cpp" > CMakeFiles\Experience_Up.dir\main.cpp.i

CMakeFiles/Experience_Up.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Experience_Up.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Other\Experience Up\main.cpp" -o CMakeFiles\Experience_Up.dir\main.cpp.s

# Object files for target Experience_Up
Experience_Up_OBJECTS = \
"CMakeFiles/Experience_Up.dir/main.cpp.obj"

# External object files for target Experience_Up
Experience_Up_EXTERNAL_OBJECTS =

Experience_Up.exe: CMakeFiles/Experience_Up.dir/main.cpp.obj
Experience_Up.exe: CMakeFiles/Experience_Up.dir/build.make
Experience_Up.exe: CMakeFiles/Experience_Up.dir/linklibs.rsp
Experience_Up.exe: CMakeFiles/Experience_Up.dir/objects1.rsp
Experience_Up.exe: CMakeFiles/Experience_Up.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Other\Experience Up\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Experience_Up.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Experience_Up.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Experience_Up.dir/build: Experience_Up.exe

.PHONY : CMakeFiles/Experience_Up.dir/build

CMakeFiles/Experience_Up.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Experience_Up.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Experience_Up.dir/clean

CMakeFiles/Experience_Up.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Other\Experience Up" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Other\Experience Up" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Other\Experience Up\cmake-build-debug" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Other\Experience Up\cmake-build-debug" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Other\Experience Up\cmake-build-debug\CMakeFiles\Experience_Up.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Experience_Up.dir/depend

