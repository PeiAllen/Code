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
CMAKE_SOURCE_DIR = "C:\Users\allen\Documents\Code\Problems\Other\Magic Multiplication"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\allen\Documents\Code\Problems\Other\Magic Multiplication\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Magic_Multiplication.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Magic_Multiplication.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Magic_Multiplication.dir/flags.make

CMakeFiles/Magic_Multiplication.dir/main.cpp.obj: CMakeFiles/Magic_Multiplication.dir/flags.make
CMakeFiles/Magic_Multiplication.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\allen\Documents\Code\Problems\Other\Magic Multiplication\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Magic_Multiplication.dir/main.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Magic_Multiplication.dir\main.cpp.obj -c "C:\Users\allen\Documents\Code\Problems\Other\Magic Multiplication\main.cpp"

CMakeFiles/Magic_Multiplication.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Magic_Multiplication.dir/main.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\allen\Documents\Code\Problems\Other\Magic Multiplication\main.cpp" > CMakeFiles\Magic_Multiplication.dir\main.cpp.i

CMakeFiles/Magic_Multiplication.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Magic_Multiplication.dir/main.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\allen\Documents\Code\Problems\Other\Magic Multiplication\main.cpp" -o CMakeFiles\Magic_Multiplication.dir\main.cpp.s

# Object files for target Magic_Multiplication
Magic_Multiplication_OBJECTS = \
"CMakeFiles/Magic_Multiplication.dir/main.cpp.obj"

# External object files for target Magic_Multiplication
Magic_Multiplication_EXTERNAL_OBJECTS =

Magic_Multiplication.exe: CMakeFiles/Magic_Multiplication.dir/main.cpp.obj
Magic_Multiplication.exe: CMakeFiles/Magic_Multiplication.dir/build.make
Magic_Multiplication.exe: CMakeFiles/Magic_Multiplication.dir/linklibs.rsp
Magic_Multiplication.exe: CMakeFiles/Magic_Multiplication.dir/objects1.rsp
Magic_Multiplication.exe: CMakeFiles/Magic_Multiplication.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\allen\Documents\Code\Problems\Other\Magic Multiplication\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Magic_Multiplication.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Magic_Multiplication.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Magic_Multiplication.dir/build: Magic_Multiplication.exe

.PHONY : CMakeFiles/Magic_Multiplication.dir/build

CMakeFiles/Magic_Multiplication.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Magic_Multiplication.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Magic_Multiplication.dir/clean

CMakeFiles/Magic_Multiplication.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\allen\Documents\Code\Problems\Other\Magic Multiplication" "C:\Users\allen\Documents\Code\Problems\Other\Magic Multiplication" "C:\Users\allen\Documents\Code\Problems\Other\Magic Multiplication\cmake-build-debug" "C:\Users\allen\Documents\Code\Problems\Other\Magic Multiplication\cmake-build-debug" "C:\Users\allen\Documents\Code\Problems\Other\Magic Multiplication\cmake-build-debug\CMakeFiles\Magic_Multiplication.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Magic_Multiplication.dir/depend

