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
CMAKE_COMMAND = C:\Users\allen\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\212.4746.93\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\allen\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\212.4746.93\bin\cmake\win\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\allen\Documents\Github\Code\Problems\COCI\COCI '11 Contest 5 #6 Poplocavanje"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\allen\Documents\Github\Code\Problems\COCI\COCI '11 Contest 5 #6 Poplocavanje\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/COCI__11_Contest_5__6_Poplocavanje.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/COCI__11_Contest_5__6_Poplocavanje.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/COCI__11_Contest_5__6_Poplocavanje.dir/flags.make

CMakeFiles/COCI__11_Contest_5__6_Poplocavanje.dir/main.cpp.obj: CMakeFiles/COCI__11_Contest_5__6_Poplocavanje.dir/flags.make
CMakeFiles/COCI__11_Contest_5__6_Poplocavanje.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\allen\Documents\Github\Code\Problems\COCI\COCI '11 Contest 5 #6 Poplocavanje\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/COCI__11_Contest_5__6_Poplocavanje.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\COCI__11_Contest_5__6_Poplocavanje.dir\main.cpp.obj -c "C:\Users\allen\Documents\Github\Code\Problems\COCI\COCI '11 Contest 5 #6 Poplocavanje\main.cpp"

CMakeFiles/COCI__11_Contest_5__6_Poplocavanje.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/COCI__11_Contest_5__6_Poplocavanje.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\allen\Documents\Github\Code\Problems\COCI\COCI '11 Contest 5 #6 Poplocavanje\main.cpp" > CMakeFiles\COCI__11_Contest_5__6_Poplocavanje.dir\main.cpp.i

CMakeFiles/COCI__11_Contest_5__6_Poplocavanje.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/COCI__11_Contest_5__6_Poplocavanje.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\allen\Documents\Github\Code\Problems\COCI\COCI '11 Contest 5 #6 Poplocavanje\main.cpp" -o CMakeFiles\COCI__11_Contest_5__6_Poplocavanje.dir\main.cpp.s

# Object files for target COCI__11_Contest_5__6_Poplocavanje
COCI__11_Contest_5__6_Poplocavanje_OBJECTS = \
"CMakeFiles/COCI__11_Contest_5__6_Poplocavanje.dir/main.cpp.obj"

# External object files for target COCI__11_Contest_5__6_Poplocavanje
COCI__11_Contest_5__6_Poplocavanje_EXTERNAL_OBJECTS =

COCI__11_Contest_5__6_Poplocavanje.exe: CMakeFiles/COCI__11_Contest_5__6_Poplocavanje.dir/main.cpp.obj
COCI__11_Contest_5__6_Poplocavanje.exe: CMakeFiles/COCI__11_Contest_5__6_Poplocavanje.dir/build.make
COCI__11_Contest_5__6_Poplocavanje.exe: CMakeFiles/COCI__11_Contest_5__6_Poplocavanje.dir/linklibs.rsp
COCI__11_Contest_5__6_Poplocavanje.exe: CMakeFiles/COCI__11_Contest_5__6_Poplocavanje.dir/objects1.rsp
COCI__11_Contest_5__6_Poplocavanje.exe: CMakeFiles/COCI__11_Contest_5__6_Poplocavanje.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\allen\Documents\Github\Code\Problems\COCI\COCI '11 Contest 5 #6 Poplocavanje\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable COCI__11_Contest_5__6_Poplocavanje.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\COCI__11_Contest_5__6_Poplocavanje.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/COCI__11_Contest_5__6_Poplocavanje.dir/build: COCI__11_Contest_5__6_Poplocavanje.exe
.PHONY : CMakeFiles/COCI__11_Contest_5__6_Poplocavanje.dir/build

CMakeFiles/COCI__11_Contest_5__6_Poplocavanje.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\COCI__11_Contest_5__6_Poplocavanje.dir\cmake_clean.cmake
.PHONY : CMakeFiles/COCI__11_Contest_5__6_Poplocavanje.dir/clean

CMakeFiles/COCI__11_Contest_5__6_Poplocavanje.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\allen\Documents\Github\Code\Problems\COCI\COCI '11 Contest 5 #6 Poplocavanje" "C:\Users\allen\Documents\Github\Code\Problems\COCI\COCI '11 Contest 5 #6 Poplocavanje" "C:\Users\allen\Documents\Github\Code\Problems\COCI\COCI '11 Contest 5 #6 Poplocavanje\cmake-build-debug" "C:\Users\allen\Documents\Github\Code\Problems\COCI\COCI '11 Contest 5 #6 Poplocavanje\cmake-build-debug" "C:\Users\allen\Documents\Github\Code\Problems\COCI\COCI '11 Contest 5 #6 Poplocavanje\cmake-build-debug\CMakeFiles\COCI__11_Contest_5__6_Poplocavanje.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/COCI__11_Contest_5__6_Poplocavanje.dir/depend

