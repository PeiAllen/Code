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
CMAKE_SOURCE_DIR = "C:\Users\allen\Documents\Github\Code\Problems\COCI\COCI '16 Contest 7 #6 Klavir"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\allen\Documents\Github\Code\Problems\COCI\COCI '16 Contest 7 #6 Klavir\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/COCI__16_Contest_7__6_Klavir.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/COCI__16_Contest_7__6_Klavir.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/COCI__16_Contest_7__6_Klavir.dir/flags.make

CMakeFiles/COCI__16_Contest_7__6_Klavir.dir/main.cpp.obj: CMakeFiles/COCI__16_Contest_7__6_Klavir.dir/flags.make
CMakeFiles/COCI__16_Contest_7__6_Klavir.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\allen\Documents\Github\Code\Problems\COCI\COCI '16 Contest 7 #6 Klavir\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/COCI__16_Contest_7__6_Klavir.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\COCI__16_Contest_7__6_Klavir.dir\main.cpp.obj -c "C:\Users\allen\Documents\Github\Code\Problems\COCI\COCI '16 Contest 7 #6 Klavir\main.cpp"

CMakeFiles/COCI__16_Contest_7__6_Klavir.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/COCI__16_Contest_7__6_Klavir.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\allen\Documents\Github\Code\Problems\COCI\COCI '16 Contest 7 #6 Klavir\main.cpp" > CMakeFiles\COCI__16_Contest_7__6_Klavir.dir\main.cpp.i

CMakeFiles/COCI__16_Contest_7__6_Klavir.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/COCI__16_Contest_7__6_Klavir.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\allen\Documents\Github\Code\Problems\COCI\COCI '16 Contest 7 #6 Klavir\main.cpp" -o CMakeFiles\COCI__16_Contest_7__6_Klavir.dir\main.cpp.s

# Object files for target COCI__16_Contest_7__6_Klavir
COCI__16_Contest_7__6_Klavir_OBJECTS = \
"CMakeFiles/COCI__16_Contest_7__6_Klavir.dir/main.cpp.obj"

# External object files for target COCI__16_Contest_7__6_Klavir
COCI__16_Contest_7__6_Klavir_EXTERNAL_OBJECTS =

COCI__16_Contest_7__6_Klavir.exe: CMakeFiles/COCI__16_Contest_7__6_Klavir.dir/main.cpp.obj
COCI__16_Contest_7__6_Klavir.exe: CMakeFiles/COCI__16_Contest_7__6_Klavir.dir/build.make
COCI__16_Contest_7__6_Klavir.exe: CMakeFiles/COCI__16_Contest_7__6_Klavir.dir/linklibs.rsp
COCI__16_Contest_7__6_Klavir.exe: CMakeFiles/COCI__16_Contest_7__6_Klavir.dir/objects1.rsp
COCI__16_Contest_7__6_Klavir.exe: CMakeFiles/COCI__16_Contest_7__6_Klavir.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\allen\Documents\Github\Code\Problems\COCI\COCI '16 Contest 7 #6 Klavir\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable COCI__16_Contest_7__6_Klavir.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\COCI__16_Contest_7__6_Klavir.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/COCI__16_Contest_7__6_Klavir.dir/build: COCI__16_Contest_7__6_Klavir.exe
.PHONY : CMakeFiles/COCI__16_Contest_7__6_Klavir.dir/build

CMakeFiles/COCI__16_Contest_7__6_Klavir.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\COCI__16_Contest_7__6_Klavir.dir\cmake_clean.cmake
.PHONY : CMakeFiles/COCI__16_Contest_7__6_Klavir.dir/clean

CMakeFiles/COCI__16_Contest_7__6_Klavir.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\allen\Documents\Github\Code\Problems\COCI\COCI '16 Contest 7 #6 Klavir" "C:\Users\allen\Documents\Github\Code\Problems\COCI\COCI '16 Contest 7 #6 Klavir" "C:\Users\allen\Documents\Github\Code\Problems\COCI\COCI '16 Contest 7 #6 Klavir\cmake-build-debug" "C:\Users\allen\Documents\Github\Code\Problems\COCI\COCI '16 Contest 7 #6 Klavir\cmake-build-debug" "C:\Users\allen\Documents\Github\Code\Problems\COCI\COCI '16 Contest 7 #6 Klavir\cmake-build-debug\CMakeFiles\COCI__16_Contest_7__6_Klavir.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/COCI__16_Contest_7__6_Klavir.dir/depend
