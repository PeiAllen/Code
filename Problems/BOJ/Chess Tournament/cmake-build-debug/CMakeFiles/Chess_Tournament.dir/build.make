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
CMAKE_SOURCE_DIR = "C:\Users\allen\Documents\Github\Code\Problems\BOJ\Chess Tournament"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\allen\Documents\Github\Code\Problems\BOJ\Chess Tournament\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Chess_Tournament.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Chess_Tournament.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Chess_Tournament.dir/flags.make

CMakeFiles/Chess_Tournament.dir/main.cpp.obj: CMakeFiles/Chess_Tournament.dir/flags.make
CMakeFiles/Chess_Tournament.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\allen\Documents\Github\Code\Problems\BOJ\Chess Tournament\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Chess_Tournament.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Chess_Tournament.dir\main.cpp.obj -c "C:\Users\allen\Documents\Github\Code\Problems\BOJ\Chess Tournament\main.cpp"

CMakeFiles/Chess_Tournament.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Chess_Tournament.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\allen\Documents\Github\Code\Problems\BOJ\Chess Tournament\main.cpp" > CMakeFiles\Chess_Tournament.dir\main.cpp.i

CMakeFiles/Chess_Tournament.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Chess_Tournament.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\allen\Documents\Github\Code\Problems\BOJ\Chess Tournament\main.cpp" -o CMakeFiles\Chess_Tournament.dir\main.cpp.s

# Object files for target Chess_Tournament
Chess_Tournament_OBJECTS = \
"CMakeFiles/Chess_Tournament.dir/main.cpp.obj"

# External object files for target Chess_Tournament
Chess_Tournament_EXTERNAL_OBJECTS =

Chess_Tournament.exe: CMakeFiles/Chess_Tournament.dir/main.cpp.obj
Chess_Tournament.exe: CMakeFiles/Chess_Tournament.dir/build.make
Chess_Tournament.exe: CMakeFiles/Chess_Tournament.dir/linklibs.rsp
Chess_Tournament.exe: CMakeFiles/Chess_Tournament.dir/objects1.rsp
Chess_Tournament.exe: CMakeFiles/Chess_Tournament.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\allen\Documents\Github\Code\Problems\BOJ\Chess Tournament\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Chess_Tournament.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Chess_Tournament.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Chess_Tournament.dir/build: Chess_Tournament.exe

.PHONY : CMakeFiles/Chess_Tournament.dir/build

CMakeFiles/Chess_Tournament.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Chess_Tournament.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Chess_Tournament.dir/clean

CMakeFiles/Chess_Tournament.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\allen\Documents\Github\Code\Problems\BOJ\Chess Tournament" "C:\Users\allen\Documents\Github\Code\Problems\BOJ\Chess Tournament" "C:\Users\allen\Documents\Github\Code\Problems\BOJ\Chess Tournament\cmake-build-debug" "C:\Users\allen\Documents\Github\Code\Problems\BOJ\Chess Tournament\cmake-build-debug" "C:\Users\allen\Documents\Github\Code\Problems\BOJ\Chess Tournament\cmake-build-debug\CMakeFiles\Chess_Tournament.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Chess_Tournament.dir/depend

