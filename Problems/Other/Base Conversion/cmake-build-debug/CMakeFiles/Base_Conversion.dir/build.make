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
CMAKE_SOURCE_DIR = "C:\Users\allen\Documents\Github\Code\Problems\Other\Base Conversion"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\allen\Documents\Github\Code\Problems\Other\Base Conversion\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Base_Conversion.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/Base_Conversion.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Base_Conversion.dir/flags.make

CMakeFiles/Base_Conversion.dir/main.cpp.obj: CMakeFiles/Base_Conversion.dir/flags.make
CMakeFiles/Base_Conversion.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\allen\Documents\Github\Code\Problems\Other\Base Conversion\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Base_Conversion.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Base_Conversion.dir\main.cpp.obj -c "C:\Users\allen\Documents\Github\Code\Problems\Other\Base Conversion\main.cpp"

CMakeFiles/Base_Conversion.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Base_Conversion.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\allen\Documents\Github\Code\Problems\Other\Base Conversion\main.cpp" > CMakeFiles\Base_Conversion.dir\main.cpp.i

CMakeFiles/Base_Conversion.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Base_Conversion.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\allen\Documents\Github\Code\Problems\Other\Base Conversion\main.cpp" -o CMakeFiles\Base_Conversion.dir\main.cpp.s

# Object files for target Base_Conversion
Base_Conversion_OBJECTS = \
"CMakeFiles/Base_Conversion.dir/main.cpp.obj"

# External object files for target Base_Conversion
Base_Conversion_EXTERNAL_OBJECTS =

Base_Conversion.exe: CMakeFiles/Base_Conversion.dir/main.cpp.obj
Base_Conversion.exe: CMakeFiles/Base_Conversion.dir/build.make
Base_Conversion.exe: CMakeFiles/Base_Conversion.dir/linklibs.rsp
Base_Conversion.exe: CMakeFiles/Base_Conversion.dir/objects1.rsp
Base_Conversion.exe: CMakeFiles/Base_Conversion.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\allen\Documents\Github\Code\Problems\Other\Base Conversion\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Base_Conversion.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Base_Conversion.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Base_Conversion.dir/build: Base_Conversion.exe
.PHONY : CMakeFiles/Base_Conversion.dir/build

CMakeFiles/Base_Conversion.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Base_Conversion.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Base_Conversion.dir/clean

CMakeFiles/Base_Conversion.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\allen\Documents\Github\Code\Problems\Other\Base Conversion" "C:\Users\allen\Documents\Github\Code\Problems\Other\Base Conversion" "C:\Users\allen\Documents\Github\Code\Problems\Other\Base Conversion\cmake-build-debug" "C:\Users\allen\Documents\Github\Code\Problems\Other\Base Conversion\cmake-build-debug" "C:\Users\allen\Documents\Github\Code\Problems\Other\Base Conversion\cmake-build-debug\CMakeFiles\Base_Conversion.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Base_Conversion.dir/depend
