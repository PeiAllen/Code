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
CMAKE_SOURCE_DIR = "C:\Users\allen\Documents\Code\Problems\Codeforces\#623DIv1"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\allen\Documents\Code\Problems\Codeforces\#623DIv1\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/_623DIv1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/_623DIv1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/_623DIv1.dir/flags.make

CMakeFiles/_623DIv1.dir/main.cpp.obj: CMakeFiles/_623DIv1.dir/flags.make
CMakeFiles/_623DIv1.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\allen\Documents\Code\Problems\Codeforces\#623DIv1\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/_623DIv1.dir/main.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\_623DIv1.dir\main.cpp.obj -c "C:\Users\allen\Documents\Code\Problems\Codeforces\#623DIv1\main.cpp"

CMakeFiles/_623DIv1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/_623DIv1.dir/main.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\allen\Documents\Code\Problems\Codeforces\#623DIv1\main.cpp" > CMakeFiles\_623DIv1.dir\main.cpp.i

CMakeFiles/_623DIv1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/_623DIv1.dir/main.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\allen\Documents\Code\Problems\Codeforces\#623DIv1\main.cpp" -o CMakeFiles\_623DIv1.dir\main.cpp.s

# Object files for target _623DIv1
_623DIv1_OBJECTS = \
"CMakeFiles/_623DIv1.dir/main.cpp.obj"

# External object files for target _623DIv1
_623DIv1_EXTERNAL_OBJECTS =

_623DIv1.exe: CMakeFiles/_623DIv1.dir/main.cpp.obj
_623DIv1.exe: CMakeFiles/_623DIv1.dir/build.make
_623DIv1.exe: CMakeFiles/_623DIv1.dir/linklibs.rsp
_623DIv1.exe: CMakeFiles/_623DIv1.dir/objects1.rsp
_623DIv1.exe: CMakeFiles/_623DIv1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\allen\Documents\Code\Problems\Codeforces\#623DIv1\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable _623DIv1.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\_623DIv1.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/_623DIv1.dir/build: _623DIv1.exe

.PHONY : CMakeFiles/_623DIv1.dir/build

CMakeFiles/_623DIv1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\_623DIv1.dir\cmake_clean.cmake
.PHONY : CMakeFiles/_623DIv1.dir/clean

CMakeFiles/_623DIv1.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\allen\Documents\Code\Problems\Codeforces\#623DIv1" "C:\Users\allen\Documents\Code\Problems\Codeforces\#623DIv1" "C:\Users\allen\Documents\Code\Problems\Codeforces\#623DIv1\cmake-build-debug" "C:\Users\allen\Documents\Code\Problems\Codeforces\#623DIv1\cmake-build-debug" "C:\Users\allen\Documents\Code\Problems\Codeforces\#623DIv1\cmake-build-debug\CMakeFiles\_623DIv1.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/_623DIv1.dir/depend

