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
CMAKE_SOURCE_DIR = "C:\Users\allen\Documents\Code\Problems\Codeforces\E. Helping Hiasat"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\allen\Documents\Code\Problems\Codeforces\E. Helping Hiasat\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/E__Helping_Hiasat.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/E__Helping_Hiasat.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/E__Helping_Hiasat.dir/flags.make

CMakeFiles/E__Helping_Hiasat.dir/main.cpp.obj: CMakeFiles/E__Helping_Hiasat.dir/flags.make
CMakeFiles/E__Helping_Hiasat.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\allen\Documents\Code\Problems\Codeforces\E. Helping Hiasat\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/E__Helping_Hiasat.dir/main.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\E__Helping_Hiasat.dir\main.cpp.obj -c "C:\Users\allen\Documents\Code\Problems\Codeforces\E. Helping Hiasat\main.cpp"

CMakeFiles/E__Helping_Hiasat.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/E__Helping_Hiasat.dir/main.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\allen\Documents\Code\Problems\Codeforces\E. Helping Hiasat\main.cpp" > CMakeFiles\E__Helping_Hiasat.dir\main.cpp.i

CMakeFiles/E__Helping_Hiasat.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/E__Helping_Hiasat.dir/main.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\allen\Documents\Code\Problems\Codeforces\E. Helping Hiasat\main.cpp" -o CMakeFiles\E__Helping_Hiasat.dir\main.cpp.s

# Object files for target E__Helping_Hiasat
E__Helping_Hiasat_OBJECTS = \
"CMakeFiles/E__Helping_Hiasat.dir/main.cpp.obj"

# External object files for target E__Helping_Hiasat
E__Helping_Hiasat_EXTERNAL_OBJECTS =

E__Helping_Hiasat.exe: CMakeFiles/E__Helping_Hiasat.dir/main.cpp.obj
E__Helping_Hiasat.exe: CMakeFiles/E__Helping_Hiasat.dir/build.make
E__Helping_Hiasat.exe: CMakeFiles/E__Helping_Hiasat.dir/linklibs.rsp
E__Helping_Hiasat.exe: CMakeFiles/E__Helping_Hiasat.dir/objects1.rsp
E__Helping_Hiasat.exe: CMakeFiles/E__Helping_Hiasat.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\allen\Documents\Code\Problems\Codeforces\E. Helping Hiasat\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable E__Helping_Hiasat.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\E__Helping_Hiasat.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/E__Helping_Hiasat.dir/build: E__Helping_Hiasat.exe

.PHONY : CMakeFiles/E__Helping_Hiasat.dir/build

CMakeFiles/E__Helping_Hiasat.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\E__Helping_Hiasat.dir\cmake_clean.cmake
.PHONY : CMakeFiles/E__Helping_Hiasat.dir/clean

CMakeFiles/E__Helping_Hiasat.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\allen\Documents\Code\Problems\Codeforces\E. Helping Hiasat" "C:\Users\allen\Documents\Code\Problems\Codeforces\E. Helping Hiasat" "C:\Users\allen\Documents\Code\Problems\Codeforces\E. Helping Hiasat\cmake-build-debug" "C:\Users\allen\Documents\Code\Problems\Codeforces\E. Helping Hiasat\cmake-build-debug" "C:\Users\allen\Documents\Code\Problems\Codeforces\E. Helping Hiasat\cmake-build-debug\CMakeFiles\E__Helping_Hiasat.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/E__Helping_Hiasat.dir/depend

