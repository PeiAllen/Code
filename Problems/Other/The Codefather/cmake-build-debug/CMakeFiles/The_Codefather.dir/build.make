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
CMAKE_SOURCE_DIR = "C:\Users\allen\Documents\Github\Code\Problems\Other\The Codefather"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\allen\Documents\Github\Code\Problems\Other\The Codefather\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/The_Codefather.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/The_Codefather.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/The_Codefather.dir/flags.make

CMakeFiles/The_Codefather.dir/main.cpp.obj: CMakeFiles/The_Codefather.dir/flags.make
CMakeFiles/The_Codefather.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\allen\Documents\Github\Code\Problems\Other\The Codefather\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/The_Codefather.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\The_Codefather.dir\main.cpp.obj -c "C:\Users\allen\Documents\Github\Code\Problems\Other\The Codefather\main.cpp"

CMakeFiles/The_Codefather.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/The_Codefather.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\allen\Documents\Github\Code\Problems\Other\The Codefather\main.cpp" > CMakeFiles\The_Codefather.dir\main.cpp.i

CMakeFiles/The_Codefather.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/The_Codefather.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\allen\Documents\Github\Code\Problems\Other\The Codefather\main.cpp" -o CMakeFiles\The_Codefather.dir\main.cpp.s

# Object files for target The_Codefather
The_Codefather_OBJECTS = \
"CMakeFiles/The_Codefather.dir/main.cpp.obj"

# External object files for target The_Codefather
The_Codefather_EXTERNAL_OBJECTS =

The_Codefather.exe: CMakeFiles/The_Codefather.dir/main.cpp.obj
The_Codefather.exe: CMakeFiles/The_Codefather.dir/build.make
The_Codefather.exe: CMakeFiles/The_Codefather.dir/linklibs.rsp
The_Codefather.exe: CMakeFiles/The_Codefather.dir/objects1.rsp
The_Codefather.exe: CMakeFiles/The_Codefather.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\allen\Documents\Github\Code\Problems\Other\The Codefather\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable The_Codefather.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\The_Codefather.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/The_Codefather.dir/build: The_Codefather.exe

.PHONY : CMakeFiles/The_Codefather.dir/build

CMakeFiles/The_Codefather.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\The_Codefather.dir\cmake_clean.cmake
.PHONY : CMakeFiles/The_Codefather.dir/clean

CMakeFiles/The_Codefather.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\allen\Documents\Github\Code\Problems\Other\The Codefather" "C:\Users\allen\Documents\Github\Code\Problems\Other\The Codefather" "C:\Users\allen\Documents\Github\Code\Problems\Other\The Codefather\cmake-build-debug" "C:\Users\allen\Documents\Github\Code\Problems\Other\The Codefather\cmake-build-debug" "C:\Users\allen\Documents\Github\Code\Problems\Other\The Codefather\cmake-build-debug\CMakeFiles\The_Codefather.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/The_Codefather.dir/depend

