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
CMAKE_SOURCE_DIR = "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Codeforces\#629Div3"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Codeforces\#629Div3\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/_629Div3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/_629Div3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/_629Div3.dir/flags.make

CMakeFiles/_629Div3.dir/main.cpp.obj: CMakeFiles/_629Div3.dir/flags.make
CMakeFiles/_629Div3.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Codeforces\#629Div3\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/_629Div3.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\_629Div3.dir\main.cpp.obj -c "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Codeforces\#629Div3\main.cpp"

CMakeFiles/_629Div3.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/_629Div3.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Codeforces\#629Div3\main.cpp" > CMakeFiles\_629Div3.dir\main.cpp.i

CMakeFiles/_629Div3.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/_629Div3.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Codeforces\#629Div3\main.cpp" -o CMakeFiles\_629Div3.dir\main.cpp.s

# Object files for target _629Div3
_629Div3_OBJECTS = \
"CMakeFiles/_629Div3.dir/main.cpp.obj"

# External object files for target _629Div3
_629Div3_EXTERNAL_OBJECTS =

_629Div3.exe: CMakeFiles/_629Div3.dir/main.cpp.obj
_629Div3.exe: CMakeFiles/_629Div3.dir/build.make
_629Div3.exe: CMakeFiles/_629Div3.dir/linklibs.rsp
_629Div3.exe: CMakeFiles/_629Div3.dir/objects1.rsp
_629Div3.exe: CMakeFiles/_629Div3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Codeforces\#629Div3\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable _629Div3.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\_629Div3.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/_629Div3.dir/build: _629Div3.exe

.PHONY : CMakeFiles/_629Div3.dir/build

CMakeFiles/_629Div3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\_629Div3.dir\cmake_clean.cmake
.PHONY : CMakeFiles/_629Div3.dir/clean

CMakeFiles/_629Div3.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Codeforces\#629Div3" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Codeforces\#629Div3" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Codeforces\#629Div3\cmake-build-debug" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Codeforces\#629Div3\cmake-build-debug" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Codeforces\#629Div3\cmake-build-debug\CMakeFiles\_629Div3.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/_629Div3.dir/depend

