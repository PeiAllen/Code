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
CMAKE_SOURCE_DIR = C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Codeforces\cc

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Codeforces\cc\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/cc.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cc.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cc.dir/flags.make

CMakeFiles/cc.dir/main.cpp.obj: CMakeFiles/cc.dir/flags.make
CMakeFiles/cc.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Codeforces\cc\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cc.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\cc.dir\main.cpp.obj -c C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Codeforces\cc\main.cpp

CMakeFiles/cc.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cc.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Codeforces\cc\main.cpp > CMakeFiles\cc.dir\main.cpp.i

CMakeFiles/cc.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cc.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Codeforces\cc\main.cpp -o CMakeFiles\cc.dir\main.cpp.s

# Object files for target cc
cc_OBJECTS = \
"CMakeFiles/cc.dir/main.cpp.obj"

# External object files for target cc
cc_EXTERNAL_OBJECTS =

cc.exe: CMakeFiles/cc.dir/main.cpp.obj
cc.exe: CMakeFiles/cc.dir/build.make
cc.exe: CMakeFiles/cc.dir/linklibs.rsp
cc.exe: CMakeFiles/cc.dir/objects1.rsp
cc.exe: CMakeFiles/cc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Codeforces\cc\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable cc.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\cc.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cc.dir/build: cc.exe

.PHONY : CMakeFiles/cc.dir/build

CMakeFiles/cc.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\cc.dir\cmake_clean.cmake
.PHONY : CMakeFiles/cc.dir/clean

CMakeFiles/cc.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Codeforces\cc C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Codeforces\cc C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Codeforces\cc\cmake-build-debug C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Codeforces\cc\cmake-build-debug C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Codeforces\cc\cmake-build-debug\CMakeFiles\cc.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cc.dir/depend

