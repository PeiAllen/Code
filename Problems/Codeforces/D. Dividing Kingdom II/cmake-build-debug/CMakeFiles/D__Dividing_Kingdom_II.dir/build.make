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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\allen\Documents\Github\Code\Problems\Codeforces\D. Dividing Kingdom II"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\allen\Documents\Github\Code\Problems\Codeforces\D. Dividing Kingdom II\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/D__Dividing_Kingdom_II.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/D__Dividing_Kingdom_II.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/D__Dividing_Kingdom_II.dir/flags.make

CMakeFiles/D__Dividing_Kingdom_II.dir/main.cpp.obj: CMakeFiles/D__Dividing_Kingdom_II.dir/flags.make
CMakeFiles/D__Dividing_Kingdom_II.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\allen\Documents\Github\Code\Problems\Codeforces\D. Dividing Kingdom II\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/D__Dividing_Kingdom_II.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\D__Dividing_Kingdom_II.dir\main.cpp.obj -c "C:\Users\allen\Documents\Github\Code\Problems\Codeforces\D. Dividing Kingdom II\main.cpp"

CMakeFiles/D__Dividing_Kingdom_II.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/D__Dividing_Kingdom_II.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\allen\Documents\Github\Code\Problems\Codeforces\D. Dividing Kingdom II\main.cpp" > CMakeFiles\D__Dividing_Kingdom_II.dir\main.cpp.i

CMakeFiles/D__Dividing_Kingdom_II.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/D__Dividing_Kingdom_II.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\allen\Documents\Github\Code\Problems\Codeforces\D. Dividing Kingdom II\main.cpp" -o CMakeFiles\D__Dividing_Kingdom_II.dir\main.cpp.s

# Object files for target D__Dividing_Kingdom_II
D__Dividing_Kingdom_II_OBJECTS = \
"CMakeFiles/D__Dividing_Kingdom_II.dir/main.cpp.obj"

# External object files for target D__Dividing_Kingdom_II
D__Dividing_Kingdom_II_EXTERNAL_OBJECTS =

D__Dividing_Kingdom_II.exe: CMakeFiles/D__Dividing_Kingdom_II.dir/main.cpp.obj
D__Dividing_Kingdom_II.exe: CMakeFiles/D__Dividing_Kingdom_II.dir/build.make
D__Dividing_Kingdom_II.exe: CMakeFiles/D__Dividing_Kingdom_II.dir/linklibs.rsp
D__Dividing_Kingdom_II.exe: CMakeFiles/D__Dividing_Kingdom_II.dir/objects1.rsp
D__Dividing_Kingdom_II.exe: CMakeFiles/D__Dividing_Kingdom_II.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\allen\Documents\Github\Code\Problems\Codeforces\D. Dividing Kingdom II\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable D__Dividing_Kingdom_II.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\D__Dividing_Kingdom_II.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/D__Dividing_Kingdom_II.dir/build: D__Dividing_Kingdom_II.exe

.PHONY : CMakeFiles/D__Dividing_Kingdom_II.dir/build

CMakeFiles/D__Dividing_Kingdom_II.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\D__Dividing_Kingdom_II.dir\cmake_clean.cmake
.PHONY : CMakeFiles/D__Dividing_Kingdom_II.dir/clean

CMakeFiles/D__Dividing_Kingdom_II.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\allen\Documents\Github\Code\Problems\Codeforces\D. Dividing Kingdom II" "C:\Users\allen\Documents\Github\Code\Problems\Codeforces\D. Dividing Kingdom II" "C:\Users\allen\Documents\Github\Code\Problems\Codeforces\D. Dividing Kingdom II\cmake-build-debug" "C:\Users\allen\Documents\Github\Code\Problems\Codeforces\D. Dividing Kingdom II\cmake-build-debug" "C:\Users\allen\Documents\Github\Code\Problems\Codeforces\D. Dividing Kingdom II\cmake-build-debug\CMakeFiles\D__Dividing_Kingdom_II.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/D__Dividing_Kingdom_II.dir/depend

