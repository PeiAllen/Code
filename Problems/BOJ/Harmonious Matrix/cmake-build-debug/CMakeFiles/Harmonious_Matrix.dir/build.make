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
CMAKE_SOURCE_DIR = "C:\Users\allen\Documents\Github\Code\Problems\BOJ\Harmonious Matrix"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\allen\Documents\Github\Code\Problems\BOJ\Harmonious Matrix\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Harmonious_Matrix.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Harmonious_Matrix.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Harmonious_Matrix.dir/flags.make

CMakeFiles/Harmonious_Matrix.dir/main.cpp.obj: CMakeFiles/Harmonious_Matrix.dir/flags.make
CMakeFiles/Harmonious_Matrix.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\allen\Documents\Github\Code\Problems\BOJ\Harmonious Matrix\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Harmonious_Matrix.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Harmonious_Matrix.dir\main.cpp.obj -c "C:\Users\allen\Documents\Github\Code\Problems\BOJ\Harmonious Matrix\main.cpp"

CMakeFiles/Harmonious_Matrix.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Harmonious_Matrix.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\allen\Documents\Github\Code\Problems\BOJ\Harmonious Matrix\main.cpp" > CMakeFiles\Harmonious_Matrix.dir\main.cpp.i

CMakeFiles/Harmonious_Matrix.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Harmonious_Matrix.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\allen\Documents\Github\Code\Problems\BOJ\Harmonious Matrix\main.cpp" -o CMakeFiles\Harmonious_Matrix.dir\main.cpp.s

# Object files for target Harmonious_Matrix
Harmonious_Matrix_OBJECTS = \
"CMakeFiles/Harmonious_Matrix.dir/main.cpp.obj"

# External object files for target Harmonious_Matrix
Harmonious_Matrix_EXTERNAL_OBJECTS =

Harmonious_Matrix.exe: CMakeFiles/Harmonious_Matrix.dir/main.cpp.obj
Harmonious_Matrix.exe: CMakeFiles/Harmonious_Matrix.dir/build.make
Harmonious_Matrix.exe: CMakeFiles/Harmonious_Matrix.dir/linklibs.rsp
Harmonious_Matrix.exe: CMakeFiles/Harmonious_Matrix.dir/objects1.rsp
Harmonious_Matrix.exe: CMakeFiles/Harmonious_Matrix.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\allen\Documents\Github\Code\Problems\BOJ\Harmonious Matrix\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Harmonious_Matrix.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Harmonious_Matrix.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Harmonious_Matrix.dir/build: Harmonious_Matrix.exe

.PHONY : CMakeFiles/Harmonious_Matrix.dir/build

CMakeFiles/Harmonious_Matrix.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Harmonious_Matrix.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Harmonious_Matrix.dir/clean

CMakeFiles/Harmonious_Matrix.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\allen\Documents\Github\Code\Problems\BOJ\Harmonious Matrix" "C:\Users\allen\Documents\Github\Code\Problems\BOJ\Harmonious Matrix" "C:\Users\allen\Documents\Github\Code\Problems\BOJ\Harmonious Matrix\cmake-build-debug" "C:\Users\allen\Documents\Github\Code\Problems\BOJ\Harmonious Matrix\cmake-build-debug" "C:\Users\allen\Documents\Github\Code\Problems\BOJ\Harmonious Matrix\cmake-build-debug\CMakeFiles\Harmonious_Matrix.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Harmonious_Matrix.dir/depend
