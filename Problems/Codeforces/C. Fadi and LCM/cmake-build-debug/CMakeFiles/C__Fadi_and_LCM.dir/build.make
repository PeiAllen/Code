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
CMAKE_SOURCE_DIR = "C:\Users\allen\Documents\Code\Problems\Codeforces\C. Fadi and LCM"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\allen\Documents\Code\Problems\Codeforces\C. Fadi and LCM\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/C__Fadi_and_LCM.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/C__Fadi_and_LCM.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/C__Fadi_and_LCM.dir/flags.make

CMakeFiles/C__Fadi_and_LCM.dir/main.cpp.obj: CMakeFiles/C__Fadi_and_LCM.dir/flags.make
CMakeFiles/C__Fadi_and_LCM.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\allen\Documents\Code\Problems\Codeforces\C. Fadi and LCM\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/C__Fadi_and_LCM.dir/main.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\C__Fadi_and_LCM.dir\main.cpp.obj -c "C:\Users\allen\Documents\Code\Problems\Codeforces\C. Fadi and LCM\main.cpp"

CMakeFiles/C__Fadi_and_LCM.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/C__Fadi_and_LCM.dir/main.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\allen\Documents\Code\Problems\Codeforces\C. Fadi and LCM\main.cpp" > CMakeFiles\C__Fadi_and_LCM.dir\main.cpp.i

CMakeFiles/C__Fadi_and_LCM.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/C__Fadi_and_LCM.dir/main.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\allen\Documents\Code\Problems\Codeforces\C. Fadi and LCM\main.cpp" -o CMakeFiles\C__Fadi_and_LCM.dir\main.cpp.s

# Object files for target C__Fadi_and_LCM
C__Fadi_and_LCM_OBJECTS = \
"CMakeFiles/C__Fadi_and_LCM.dir/main.cpp.obj"

# External object files for target C__Fadi_and_LCM
C__Fadi_and_LCM_EXTERNAL_OBJECTS =

C__Fadi_and_LCM.exe: CMakeFiles/C__Fadi_and_LCM.dir/main.cpp.obj
C__Fadi_and_LCM.exe: CMakeFiles/C__Fadi_and_LCM.dir/build.make
C__Fadi_and_LCM.exe: CMakeFiles/C__Fadi_and_LCM.dir/linklibs.rsp
C__Fadi_and_LCM.exe: CMakeFiles/C__Fadi_and_LCM.dir/objects1.rsp
C__Fadi_and_LCM.exe: CMakeFiles/C__Fadi_and_LCM.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\allen\Documents\Code\Problems\Codeforces\C. Fadi and LCM\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable C__Fadi_and_LCM.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\C__Fadi_and_LCM.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/C__Fadi_and_LCM.dir/build: C__Fadi_and_LCM.exe

.PHONY : CMakeFiles/C__Fadi_and_LCM.dir/build

CMakeFiles/C__Fadi_and_LCM.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\C__Fadi_and_LCM.dir\cmake_clean.cmake
.PHONY : CMakeFiles/C__Fadi_and_LCM.dir/clean

CMakeFiles/C__Fadi_and_LCM.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\allen\Documents\Code\Problems\Codeforces\C. Fadi and LCM" "C:\Users\allen\Documents\Code\Problems\Codeforces\C. Fadi and LCM" "C:\Users\allen\Documents\Code\Problems\Codeforces\C. Fadi and LCM\cmake-build-debug" "C:\Users\allen\Documents\Code\Problems\Codeforces\C. Fadi and LCM\cmake-build-debug" "C:\Users\allen\Documents\Code\Problems\Codeforces\C. Fadi and LCM\cmake-build-debug\CMakeFiles\C__Fadi_and_LCM.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/C__Fadi_and_LCM.dir/depend

