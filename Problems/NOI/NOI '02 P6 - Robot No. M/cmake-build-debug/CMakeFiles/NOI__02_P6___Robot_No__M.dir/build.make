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
CMAKE_SOURCE_DIR = "C:\Users\allen\Documents\Github\Code\Problems\NOI\NOI '02 P6 - Robot No. M"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\allen\Documents\Github\Code\Problems\NOI\NOI '02 P6 - Robot No. M\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/NOI__02_P6___Robot_No__M.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/NOI__02_P6___Robot_No__M.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/NOI__02_P6___Robot_No__M.dir/flags.make

CMakeFiles/NOI__02_P6___Robot_No__M.dir/main.cpp.obj: CMakeFiles/NOI__02_P6___Robot_No__M.dir/flags.make
CMakeFiles/NOI__02_P6___Robot_No__M.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\allen\Documents\Github\Code\Problems\NOI\NOI '02 P6 - Robot No. M\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/NOI__02_P6___Robot_No__M.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\NOI__02_P6___Robot_No__M.dir\main.cpp.obj -c "C:\Users\allen\Documents\Github\Code\Problems\NOI\NOI '02 P6 - Robot No. M\main.cpp"

CMakeFiles/NOI__02_P6___Robot_No__M.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NOI__02_P6___Robot_No__M.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\allen\Documents\Github\Code\Problems\NOI\NOI '02 P6 - Robot No. M\main.cpp" > CMakeFiles\NOI__02_P6___Robot_No__M.dir\main.cpp.i

CMakeFiles/NOI__02_P6___Robot_No__M.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NOI__02_P6___Robot_No__M.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\allen\Documents\Github\Code\Problems\NOI\NOI '02 P6 - Robot No. M\main.cpp" -o CMakeFiles\NOI__02_P6___Robot_No__M.dir\main.cpp.s

# Object files for target NOI__02_P6___Robot_No__M
NOI__02_P6___Robot_No__M_OBJECTS = \
"CMakeFiles/NOI__02_P6___Robot_No__M.dir/main.cpp.obj"

# External object files for target NOI__02_P6___Robot_No__M
NOI__02_P6___Robot_No__M_EXTERNAL_OBJECTS =

NOI__02_P6___Robot_No__M.exe: CMakeFiles/NOI__02_P6___Robot_No__M.dir/main.cpp.obj
NOI__02_P6___Robot_No__M.exe: CMakeFiles/NOI__02_P6___Robot_No__M.dir/build.make
NOI__02_P6___Robot_No__M.exe: CMakeFiles/NOI__02_P6___Robot_No__M.dir/linklibs.rsp
NOI__02_P6___Robot_No__M.exe: CMakeFiles/NOI__02_P6___Robot_No__M.dir/objects1.rsp
NOI__02_P6___Robot_No__M.exe: CMakeFiles/NOI__02_P6___Robot_No__M.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\allen\Documents\Github\Code\Problems\NOI\NOI '02 P6 - Robot No. M\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable NOI__02_P6___Robot_No__M.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\NOI__02_P6___Robot_No__M.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/NOI__02_P6___Robot_No__M.dir/build: NOI__02_P6___Robot_No__M.exe
.PHONY : CMakeFiles/NOI__02_P6___Robot_No__M.dir/build

CMakeFiles/NOI__02_P6___Robot_No__M.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\NOI__02_P6___Robot_No__M.dir\cmake_clean.cmake
.PHONY : CMakeFiles/NOI__02_P6___Robot_No__M.dir/clean

CMakeFiles/NOI__02_P6___Robot_No__M.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\allen\Documents\Github\Code\Problems\NOI\NOI '02 P6 - Robot No. M" "C:\Users\allen\Documents\Github\Code\Problems\NOI\NOI '02 P6 - Robot No. M" "C:\Users\allen\Documents\Github\Code\Problems\NOI\NOI '02 P6 - Robot No. M\cmake-build-debug" "C:\Users\allen\Documents\Github\Code\Problems\NOI\NOI '02 P6 - Robot No. M\cmake-build-debug" "C:\Users\allen\Documents\Github\Code\Problems\NOI\NOI '02 P6 - Robot No. M\cmake-build-debug\CMakeFiles\NOI__02_P6___Robot_No__M.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/NOI__02_P6___Robot_No__M.dir/depend

