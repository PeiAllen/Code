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
CMAKE_SOURCE_DIR = "C:\Users\allen\Documents\Github\Code\Problems\CSES\Creating Strings"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\allen\Documents\Github\Code\Problems\CSES\Creating Strings\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Creating_Strings.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/Creating_Strings.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Creating_Strings.dir/flags.make

CMakeFiles/Creating_Strings.dir/main.cpp.obj: CMakeFiles/Creating_Strings.dir/flags.make
CMakeFiles/Creating_Strings.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\allen\Documents\Github\Code\Problems\CSES\Creating Strings\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Creating_Strings.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Creating_Strings.dir\main.cpp.obj -c "C:\Users\allen\Documents\Github\Code\Problems\CSES\Creating Strings\main.cpp"

CMakeFiles/Creating_Strings.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Creating_Strings.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\allen\Documents\Github\Code\Problems\CSES\Creating Strings\main.cpp" > CMakeFiles\Creating_Strings.dir\main.cpp.i

CMakeFiles/Creating_Strings.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Creating_Strings.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\allen\Documents\Github\Code\Problems\CSES\Creating Strings\main.cpp" -o CMakeFiles\Creating_Strings.dir\main.cpp.s

# Object files for target Creating_Strings
Creating_Strings_OBJECTS = \
"CMakeFiles/Creating_Strings.dir/main.cpp.obj"

# External object files for target Creating_Strings
Creating_Strings_EXTERNAL_OBJECTS =

Creating_Strings.exe: CMakeFiles/Creating_Strings.dir/main.cpp.obj
Creating_Strings.exe: CMakeFiles/Creating_Strings.dir/build.make
Creating_Strings.exe: CMakeFiles/Creating_Strings.dir/linklibs.rsp
Creating_Strings.exe: CMakeFiles/Creating_Strings.dir/objects1.rsp
Creating_Strings.exe: CMakeFiles/Creating_Strings.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\allen\Documents\Github\Code\Problems\CSES\Creating Strings\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Creating_Strings.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Creating_Strings.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Creating_Strings.dir/build: Creating_Strings.exe
.PHONY : CMakeFiles/Creating_Strings.dir/build

CMakeFiles/Creating_Strings.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Creating_Strings.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Creating_Strings.dir/clean

CMakeFiles/Creating_Strings.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\allen\Documents\Github\Code\Problems\CSES\Creating Strings" "C:\Users\allen\Documents\Github\Code\Problems\CSES\Creating Strings" "C:\Users\allen\Documents\Github\Code\Problems\CSES\Creating Strings\cmake-build-debug" "C:\Users\allen\Documents\Github\Code\Problems\CSES\Creating Strings\cmake-build-debug" "C:\Users\allen\Documents\Github\Code\Problems\CSES\Creating Strings\cmake-build-debug\CMakeFiles\Creating_Strings.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Creating_Strings.dir/depend
