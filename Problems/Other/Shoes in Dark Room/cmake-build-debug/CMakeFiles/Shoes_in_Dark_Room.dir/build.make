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
CMAKE_SOURCE_DIR = "C:\Users\allen\Documents\Github\Code\Problems\Other\Shoes in Dark Room"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\allen\Documents\Github\Code\Problems\Other\Shoes in Dark Room\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Shoes_in_Dark_Room.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Shoes_in_Dark_Room.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Shoes_in_Dark_Room.dir/flags.make

CMakeFiles/Shoes_in_Dark_Room.dir/main.cpp.obj: CMakeFiles/Shoes_in_Dark_Room.dir/flags.make
CMakeFiles/Shoes_in_Dark_Room.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\allen\Documents\Github\Code\Problems\Other\Shoes in Dark Room\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Shoes_in_Dark_Room.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Shoes_in_Dark_Room.dir\main.cpp.obj -c "C:\Users\allen\Documents\Github\Code\Problems\Other\Shoes in Dark Room\main.cpp"

CMakeFiles/Shoes_in_Dark_Room.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Shoes_in_Dark_Room.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\allen\Documents\Github\Code\Problems\Other\Shoes in Dark Room\main.cpp" > CMakeFiles\Shoes_in_Dark_Room.dir\main.cpp.i

CMakeFiles/Shoes_in_Dark_Room.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Shoes_in_Dark_Room.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\allen\Documents\Github\Code\Problems\Other\Shoes in Dark Room\main.cpp" -o CMakeFiles\Shoes_in_Dark_Room.dir\main.cpp.s

# Object files for target Shoes_in_Dark_Room
Shoes_in_Dark_Room_OBJECTS = \
"CMakeFiles/Shoes_in_Dark_Room.dir/main.cpp.obj"

# External object files for target Shoes_in_Dark_Room
Shoes_in_Dark_Room_EXTERNAL_OBJECTS =

Shoes_in_Dark_Room.exe: CMakeFiles/Shoes_in_Dark_Room.dir/main.cpp.obj
Shoes_in_Dark_Room.exe: CMakeFiles/Shoes_in_Dark_Room.dir/build.make
Shoes_in_Dark_Room.exe: CMakeFiles/Shoes_in_Dark_Room.dir/linklibs.rsp
Shoes_in_Dark_Room.exe: CMakeFiles/Shoes_in_Dark_Room.dir/objects1.rsp
Shoes_in_Dark_Room.exe: CMakeFiles/Shoes_in_Dark_Room.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\allen\Documents\Github\Code\Problems\Other\Shoes in Dark Room\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Shoes_in_Dark_Room.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Shoes_in_Dark_Room.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Shoes_in_Dark_Room.dir/build: Shoes_in_Dark_Room.exe

.PHONY : CMakeFiles/Shoes_in_Dark_Room.dir/build

CMakeFiles/Shoes_in_Dark_Room.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Shoes_in_Dark_Room.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Shoes_in_Dark_Room.dir/clean

CMakeFiles/Shoes_in_Dark_Room.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\allen\Documents\Github\Code\Problems\Other\Shoes in Dark Room" "C:\Users\allen\Documents\Github\Code\Problems\Other\Shoes in Dark Room" "C:\Users\allen\Documents\Github\Code\Problems\Other\Shoes in Dark Room\cmake-build-debug" "C:\Users\allen\Documents\Github\Code\Problems\Other\Shoes in Dark Room\cmake-build-debug" "C:\Users\allen\Documents\Github\Code\Problems\Other\Shoes in Dark Room\cmake-build-debug\CMakeFiles\Shoes_in_Dark_Room.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Shoes_in_Dark_Room.dir/depend

