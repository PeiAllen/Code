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
CMAKE_SOURCE_DIR = "C:\Users\allen\Documents\Github\Code\Problems\USACO\2019\February\Gold\USACO 2019 February Gold P2 - Dishwashing"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\allen\Documents\Github\Code\Problems\USACO\2019\February\Gold\USACO 2019 February Gold P2 - Dishwashing\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/USACO_2019_February_Gold_P2___Dishwashing.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/USACO_2019_February_Gold_P2___Dishwashing.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/USACO_2019_February_Gold_P2___Dishwashing.dir/flags.make

CMakeFiles/USACO_2019_February_Gold_P2___Dishwashing.dir/main.cpp.obj: CMakeFiles/USACO_2019_February_Gold_P2___Dishwashing.dir/flags.make
CMakeFiles/USACO_2019_February_Gold_P2___Dishwashing.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\allen\Documents\Github\Code\Problems\USACO\2019\February\Gold\USACO 2019 February Gold P2 - Dishwashing\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/USACO_2019_February_Gold_P2___Dishwashing.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\USACO_2019_February_Gold_P2___Dishwashing.dir\main.cpp.obj -c "C:\Users\allen\Documents\Github\Code\Problems\USACO\2019\February\Gold\USACO 2019 February Gold P2 - Dishwashing\main.cpp"

CMakeFiles/USACO_2019_February_Gold_P2___Dishwashing.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/USACO_2019_February_Gold_P2___Dishwashing.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\allen\Documents\Github\Code\Problems\USACO\2019\February\Gold\USACO 2019 February Gold P2 - Dishwashing\main.cpp" > CMakeFiles\USACO_2019_February_Gold_P2___Dishwashing.dir\main.cpp.i

CMakeFiles/USACO_2019_February_Gold_P2___Dishwashing.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/USACO_2019_February_Gold_P2___Dishwashing.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\allen\Documents\Github\Code\Problems\USACO\2019\February\Gold\USACO 2019 February Gold P2 - Dishwashing\main.cpp" -o CMakeFiles\USACO_2019_February_Gold_P2___Dishwashing.dir\main.cpp.s

# Object files for target USACO_2019_February_Gold_P2___Dishwashing
USACO_2019_February_Gold_P2___Dishwashing_OBJECTS = \
"CMakeFiles/USACO_2019_February_Gold_P2___Dishwashing.dir/main.cpp.obj"

# External object files for target USACO_2019_February_Gold_P2___Dishwashing
USACO_2019_February_Gold_P2___Dishwashing_EXTERNAL_OBJECTS =

USACO_2019_February_Gold_P2___Dishwashing.exe: CMakeFiles/USACO_2019_February_Gold_P2___Dishwashing.dir/main.cpp.obj
USACO_2019_February_Gold_P2___Dishwashing.exe: CMakeFiles/USACO_2019_February_Gold_P2___Dishwashing.dir/build.make
USACO_2019_February_Gold_P2___Dishwashing.exe: CMakeFiles/USACO_2019_February_Gold_P2___Dishwashing.dir/linklibs.rsp
USACO_2019_February_Gold_P2___Dishwashing.exe: CMakeFiles/USACO_2019_February_Gold_P2___Dishwashing.dir/objects1.rsp
USACO_2019_February_Gold_P2___Dishwashing.exe: CMakeFiles/USACO_2019_February_Gold_P2___Dishwashing.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\allen\Documents\Github\Code\Problems\USACO\2019\February\Gold\USACO 2019 February Gold P2 - Dishwashing\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable USACO_2019_February_Gold_P2___Dishwashing.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\USACO_2019_February_Gold_P2___Dishwashing.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/USACO_2019_February_Gold_P2___Dishwashing.dir/build: USACO_2019_February_Gold_P2___Dishwashing.exe

.PHONY : CMakeFiles/USACO_2019_February_Gold_P2___Dishwashing.dir/build

CMakeFiles/USACO_2019_February_Gold_P2___Dishwashing.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\USACO_2019_February_Gold_P2___Dishwashing.dir\cmake_clean.cmake
.PHONY : CMakeFiles/USACO_2019_February_Gold_P2___Dishwashing.dir/clean

CMakeFiles/USACO_2019_February_Gold_P2___Dishwashing.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\allen\Documents\Github\Code\Problems\USACO\2019\February\Gold\USACO 2019 February Gold P2 - Dishwashing" "C:\Users\allen\Documents\Github\Code\Problems\USACO\2019\February\Gold\USACO 2019 February Gold P2 - Dishwashing" "C:\Users\allen\Documents\Github\Code\Problems\USACO\2019\February\Gold\USACO 2019 February Gold P2 - Dishwashing\cmake-build-debug" "C:\Users\allen\Documents\Github\Code\Problems\USACO\2019\February\Gold\USACO 2019 February Gold P2 - Dishwashing\cmake-build-debug" "C:\Users\allen\Documents\Github\Code\Problems\USACO\2019\February\Gold\USACO 2019 February Gold P2 - Dishwashing\cmake-build-debug\CMakeFiles\USACO_2019_February_Gold_P2___Dishwashing.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/USACO_2019_February_Gold_P2___Dishwashing.dir/depend

