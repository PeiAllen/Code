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
CMAKE_SOURCE_DIR = "C:\Users\allen\Documents\Code\Problems\Codeforces\A. Mezo Playing Zoma"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\allen\Documents\Code\Problems\Codeforces\A. Mezo Playing Zoma\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/A__Mezo_Playing_Zoma.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/A__Mezo_Playing_Zoma.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/A__Mezo_Playing_Zoma.dir/flags.make

CMakeFiles/A__Mezo_Playing_Zoma.dir/main.cpp.obj: CMakeFiles/A__Mezo_Playing_Zoma.dir/flags.make
CMakeFiles/A__Mezo_Playing_Zoma.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\allen\Documents\Code\Problems\Codeforces\A. Mezo Playing Zoma\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/A__Mezo_Playing_Zoma.dir/main.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\A__Mezo_Playing_Zoma.dir\main.cpp.obj -c "C:\Users\allen\Documents\Code\Problems\Codeforces\A. Mezo Playing Zoma\main.cpp"

CMakeFiles/A__Mezo_Playing_Zoma.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/A__Mezo_Playing_Zoma.dir/main.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\allen\Documents\Code\Problems\Codeforces\A. Mezo Playing Zoma\main.cpp" > CMakeFiles\A__Mezo_Playing_Zoma.dir\main.cpp.i

CMakeFiles/A__Mezo_Playing_Zoma.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/A__Mezo_Playing_Zoma.dir/main.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\allen\Documents\Code\Problems\Codeforces\A. Mezo Playing Zoma\main.cpp" -o CMakeFiles\A__Mezo_Playing_Zoma.dir\main.cpp.s

# Object files for target A__Mezo_Playing_Zoma
A__Mezo_Playing_Zoma_OBJECTS = \
"CMakeFiles/A__Mezo_Playing_Zoma.dir/main.cpp.obj"

# External object files for target A__Mezo_Playing_Zoma
A__Mezo_Playing_Zoma_EXTERNAL_OBJECTS =

A__Mezo_Playing_Zoma.exe: CMakeFiles/A__Mezo_Playing_Zoma.dir/main.cpp.obj
A__Mezo_Playing_Zoma.exe: CMakeFiles/A__Mezo_Playing_Zoma.dir/build.make
A__Mezo_Playing_Zoma.exe: CMakeFiles/A__Mezo_Playing_Zoma.dir/linklibs.rsp
A__Mezo_Playing_Zoma.exe: CMakeFiles/A__Mezo_Playing_Zoma.dir/objects1.rsp
A__Mezo_Playing_Zoma.exe: CMakeFiles/A__Mezo_Playing_Zoma.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\allen\Documents\Code\Problems\Codeforces\A. Mezo Playing Zoma\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable A__Mezo_Playing_Zoma.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\A__Mezo_Playing_Zoma.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/A__Mezo_Playing_Zoma.dir/build: A__Mezo_Playing_Zoma.exe

.PHONY : CMakeFiles/A__Mezo_Playing_Zoma.dir/build

CMakeFiles/A__Mezo_Playing_Zoma.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\A__Mezo_Playing_Zoma.dir\cmake_clean.cmake
.PHONY : CMakeFiles/A__Mezo_Playing_Zoma.dir/clean

CMakeFiles/A__Mezo_Playing_Zoma.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\allen\Documents\Code\Problems\Codeforces\A. Mezo Playing Zoma" "C:\Users\allen\Documents\Code\Problems\Codeforces\A. Mezo Playing Zoma" "C:\Users\allen\Documents\Code\Problems\Codeforces\A. Mezo Playing Zoma\cmake-build-debug" "C:\Users\allen\Documents\Code\Problems\Codeforces\A. Mezo Playing Zoma\cmake-build-debug" "C:\Users\allen\Documents\Code\Problems\Codeforces\A. Mezo Playing Zoma\cmake-build-debug\CMakeFiles\A__Mezo_Playing_Zoma.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/A__Mezo_Playing_Zoma.dir/depend
