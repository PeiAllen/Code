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
CMAKE_COMMAND = C:\Users\allen\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\212.5080.54\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\allen\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\212.5080.54\bin\cmake\win\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\allen\Documents\Github\Code\Problems\Codeforces\E. PermutationForces II"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\allen\Documents\Github\Code\Problems\Codeforces\E. PermutationForces II\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/E__PermutationForces_II.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/E__PermutationForces_II.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/E__PermutationForces_II.dir/flags.make

CMakeFiles/E__PermutationForces_II.dir/main.cpp.obj: CMakeFiles/E__PermutationForces_II.dir/flags.make
CMakeFiles/E__PermutationForces_II.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\allen\Documents\Github\Code\Problems\Codeforces\E. PermutationForces II\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/E__PermutationForces_II.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\E__PermutationForces_II.dir\main.cpp.obj -c "C:\Users\allen\Documents\Github\Code\Problems\Codeforces\E. PermutationForces II\main.cpp"

CMakeFiles/E__PermutationForces_II.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/E__PermutationForces_II.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\allen\Documents\Github\Code\Problems\Codeforces\E. PermutationForces II\main.cpp" > CMakeFiles\E__PermutationForces_II.dir\main.cpp.i

CMakeFiles/E__PermutationForces_II.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/E__PermutationForces_II.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\allen\Documents\Github\Code\Problems\Codeforces\E. PermutationForces II\main.cpp" -o CMakeFiles\E__PermutationForces_II.dir\main.cpp.s

# Object files for target E__PermutationForces_II
E__PermutationForces_II_OBJECTS = \
"CMakeFiles/E__PermutationForces_II.dir/main.cpp.obj"

# External object files for target E__PermutationForces_II
E__PermutationForces_II_EXTERNAL_OBJECTS =

E__PermutationForces_II.exe: CMakeFiles/E__PermutationForces_II.dir/main.cpp.obj
E__PermutationForces_II.exe: CMakeFiles/E__PermutationForces_II.dir/build.make
E__PermutationForces_II.exe: CMakeFiles/E__PermutationForces_II.dir/linklibs.rsp
E__PermutationForces_II.exe: CMakeFiles/E__PermutationForces_II.dir/objects1.rsp
E__PermutationForces_II.exe: CMakeFiles/E__PermutationForces_II.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\allen\Documents\Github\Code\Problems\Codeforces\E. PermutationForces II\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable E__PermutationForces_II.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\E__PermutationForces_II.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/E__PermutationForces_II.dir/build: E__PermutationForces_II.exe
.PHONY : CMakeFiles/E__PermutationForces_II.dir/build

CMakeFiles/E__PermutationForces_II.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\E__PermutationForces_II.dir\cmake_clean.cmake
.PHONY : CMakeFiles/E__PermutationForces_II.dir/clean

CMakeFiles/E__PermutationForces_II.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\allen\Documents\Github\Code\Problems\Codeforces\E. PermutationForces II" "C:\Users\allen\Documents\Github\Code\Problems\Codeforces\E. PermutationForces II" "C:\Users\allen\Documents\Github\Code\Problems\Codeforces\E. PermutationForces II\cmake-build-debug" "C:\Users\allen\Documents\Github\Code\Problems\Codeforces\E. PermutationForces II\cmake-build-debug" "C:\Users\allen\Documents\Github\Code\Problems\Codeforces\E. PermutationForces II\cmake-build-debug\CMakeFiles\E__PermutationForces_II.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/E__PermutationForces_II.dir/depend
