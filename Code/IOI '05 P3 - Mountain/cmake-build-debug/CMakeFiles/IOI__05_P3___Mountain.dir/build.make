# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.14

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.1.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.1.3\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\allen\CLionProjects\IOI '05 P3 - Mountain"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\allen\CLionProjects\IOI '05 P3 - Mountain\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/IOI__05_P3___Mountain.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/IOI__05_P3___Mountain.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/IOI__05_P3___Mountain.dir/flags.make

CMakeFiles/IOI__05_P3___Mountain.dir/main.cpp.obj: CMakeFiles/IOI__05_P3___Mountain.dir/flags.make
CMakeFiles/IOI__05_P3___Mountain.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\allen\CLionProjects\IOI '05 P3 - Mountain\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/IOI__05_P3___Mountain.dir/main.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\IOI__05_P3___Mountain.dir\main.cpp.obj -c "C:\Users\allen\CLionProjects\IOI '05 P3 - Mountain\main.cpp"

CMakeFiles/IOI__05_P3___Mountain.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/IOI__05_P3___Mountain.dir/main.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\allen\CLionProjects\IOI '05 P3 - Mountain\main.cpp" > CMakeFiles\IOI__05_P3___Mountain.dir\main.cpp.i

CMakeFiles/IOI__05_P3___Mountain.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/IOI__05_P3___Mountain.dir/main.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\allen\CLionProjects\IOI '05 P3 - Mountain\main.cpp" -o CMakeFiles\IOI__05_P3___Mountain.dir\main.cpp.s

# Object files for target IOI__05_P3___Mountain
IOI__05_P3___Mountain_OBJECTS = \
"CMakeFiles/IOI__05_P3___Mountain.dir/main.cpp.obj"

# External object files for target IOI__05_P3___Mountain
IOI__05_P3___Mountain_EXTERNAL_OBJECTS =

IOI__05_P3___Mountain.exe: CMakeFiles/IOI__05_P3___Mountain.dir/main.cpp.obj
IOI__05_P3___Mountain.exe: CMakeFiles/IOI__05_P3___Mountain.dir/build.make
IOI__05_P3___Mountain.exe: CMakeFiles/IOI__05_P3___Mountain.dir/linklibs.rsp
IOI__05_P3___Mountain.exe: CMakeFiles/IOI__05_P3___Mountain.dir/objects1.rsp
IOI__05_P3___Mountain.exe: CMakeFiles/IOI__05_P3___Mountain.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\allen\CLionProjects\IOI '05 P3 - Mountain\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable IOI__05_P3___Mountain.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\IOI__05_P3___Mountain.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/IOI__05_P3___Mountain.dir/build: IOI__05_P3___Mountain.exe

.PHONY : CMakeFiles/IOI__05_P3___Mountain.dir/build

CMakeFiles/IOI__05_P3___Mountain.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\IOI__05_P3___Mountain.dir\cmake_clean.cmake
.PHONY : CMakeFiles/IOI__05_P3___Mountain.dir/clean

CMakeFiles/IOI__05_P3___Mountain.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\allen\CLionProjects\IOI '05 P3 - Mountain" "C:\Users\allen\CLionProjects\IOI '05 P3 - Mountain" "C:\Users\allen\CLionProjects\IOI '05 P3 - Mountain\cmake-build-debug" "C:\Users\allen\CLionProjects\IOI '05 P3 - Mountain\cmake-build-debug" "C:\Users\allen\CLionProjects\IOI '05 P3 - Mountain\cmake-build-debug\CMakeFiles\IOI__05_P3___Mountain.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/IOI__05_P3___Mountain.dir/depend

