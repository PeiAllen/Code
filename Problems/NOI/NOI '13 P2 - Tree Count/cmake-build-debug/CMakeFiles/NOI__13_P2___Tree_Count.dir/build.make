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
CMAKE_SOURCE_DIR = "C:\Users\allen\Documents\Github\Code\Problems\NOI\NOI '13 P2 - Tree Count"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\allen\Documents\Github\Code\Problems\NOI\NOI '13 P2 - Tree Count\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/NOI__13_P2___Tree_Count.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/NOI__13_P2___Tree_Count.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/NOI__13_P2___Tree_Count.dir/flags.make

CMakeFiles/NOI__13_P2___Tree_Count.dir/main.cpp.obj: CMakeFiles/NOI__13_P2___Tree_Count.dir/flags.make
CMakeFiles/NOI__13_P2___Tree_Count.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\allen\Documents\Github\Code\Problems\NOI\NOI '13 P2 - Tree Count\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/NOI__13_P2___Tree_Count.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\NOI__13_P2___Tree_Count.dir\main.cpp.obj -c "C:\Users\allen\Documents\Github\Code\Problems\NOI\NOI '13 P2 - Tree Count\main.cpp"

CMakeFiles/NOI__13_P2___Tree_Count.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NOI__13_P2___Tree_Count.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\allen\Documents\Github\Code\Problems\NOI\NOI '13 P2 - Tree Count\main.cpp" > CMakeFiles\NOI__13_P2___Tree_Count.dir\main.cpp.i

CMakeFiles/NOI__13_P2___Tree_Count.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NOI__13_P2___Tree_Count.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\allen\Documents\Github\Code\Problems\NOI\NOI '13 P2 - Tree Count\main.cpp" -o CMakeFiles\NOI__13_P2___Tree_Count.dir\main.cpp.s

# Object files for target NOI__13_P2___Tree_Count
NOI__13_P2___Tree_Count_OBJECTS = \
"CMakeFiles/NOI__13_P2___Tree_Count.dir/main.cpp.obj"

# External object files for target NOI__13_P2___Tree_Count
NOI__13_P2___Tree_Count_EXTERNAL_OBJECTS =

NOI__13_P2___Tree_Count.exe: CMakeFiles/NOI__13_P2___Tree_Count.dir/main.cpp.obj
NOI__13_P2___Tree_Count.exe: CMakeFiles/NOI__13_P2___Tree_Count.dir/build.make
NOI__13_P2___Tree_Count.exe: CMakeFiles/NOI__13_P2___Tree_Count.dir/linklibs.rsp
NOI__13_P2___Tree_Count.exe: CMakeFiles/NOI__13_P2___Tree_Count.dir/objects1.rsp
NOI__13_P2___Tree_Count.exe: CMakeFiles/NOI__13_P2___Tree_Count.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\allen\Documents\Github\Code\Problems\NOI\NOI '13 P2 - Tree Count\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable NOI__13_P2___Tree_Count.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\NOI__13_P2___Tree_Count.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/NOI__13_P2___Tree_Count.dir/build: NOI__13_P2___Tree_Count.exe

.PHONY : CMakeFiles/NOI__13_P2___Tree_Count.dir/build

CMakeFiles/NOI__13_P2___Tree_Count.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\NOI__13_P2___Tree_Count.dir\cmake_clean.cmake
.PHONY : CMakeFiles/NOI__13_P2___Tree_Count.dir/clean

CMakeFiles/NOI__13_P2___Tree_Count.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\allen\Documents\Github\Code\Problems\NOI\NOI '13 P2 - Tree Count" "C:\Users\allen\Documents\Github\Code\Problems\NOI\NOI '13 P2 - Tree Count" "C:\Users\allen\Documents\Github\Code\Problems\NOI\NOI '13 P2 - Tree Count\cmake-build-debug" "C:\Users\allen\Documents\Github\Code\Problems\NOI\NOI '13 P2 - Tree Count\cmake-build-debug" "C:\Users\allen\Documents\Github\Code\Problems\NOI\NOI '13 P2 - Tree Count\cmake-build-debug\CMakeFiles\NOI__13_P2___Tree_Count.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/NOI__13_P2___Tree_Count.dir/depend

