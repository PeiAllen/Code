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
CMAKE_SOURCE_DIR = C:\Users\allen\CLionProjects\SMTreap

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\allen\CLionProjects\SMTreap\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/SMTreap.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SMTreap.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SMTreap.dir/flags.make

CMakeFiles/SMTreap.dir/main.cpp.obj: CMakeFiles/SMTreap.dir/flags.make
CMakeFiles/SMTreap.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\allen\CLionProjects\SMTreap\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SMTreap.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\SMTreap.dir\main.cpp.obj -c C:\Users\allen\CLionProjects\SMTreap\main.cpp

CMakeFiles/SMTreap.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SMTreap.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\allen\CLionProjects\SMTreap\main.cpp > CMakeFiles\SMTreap.dir\main.cpp.i

CMakeFiles/SMTreap.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SMTreap.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\allen\CLionProjects\SMTreap\main.cpp -o CMakeFiles\SMTreap.dir\main.cpp.s

# Object files for target SMTreap
SMTreap_OBJECTS = \
"CMakeFiles/SMTreap.dir/main.cpp.obj"

# External object files for target SMTreap
SMTreap_EXTERNAL_OBJECTS =

SMTreap.exe: CMakeFiles/SMTreap.dir/main.cpp.obj
SMTreap.exe: CMakeFiles/SMTreap.dir/build.make
SMTreap.exe: CMakeFiles/SMTreap.dir/linklibs.rsp
SMTreap.exe: CMakeFiles/SMTreap.dir/objects1.rsp
SMTreap.exe: CMakeFiles/SMTreap.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\allen\CLionProjects\SMTreap\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable SMTreap.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\SMTreap.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SMTreap.dir/build: SMTreap.exe

.PHONY : CMakeFiles/SMTreap.dir/build

CMakeFiles/SMTreap.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\SMTreap.dir\cmake_clean.cmake
.PHONY : CMakeFiles/SMTreap.dir/clean

CMakeFiles/SMTreap.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\allen\CLionProjects\SMTreap C:\Users\allen\CLionProjects\SMTreap C:\Users\allen\CLionProjects\SMTreap\cmake-build-debug C:\Users\allen\CLionProjects\SMTreap\cmake-build-debug C:\Users\allen\CLionProjects\SMTreap\cmake-build-debug\CMakeFiles\SMTreap.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SMTreap.dir/depend
