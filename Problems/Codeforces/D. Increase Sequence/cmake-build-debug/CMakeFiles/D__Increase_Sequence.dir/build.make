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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.1.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.1.2\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Codeforces\D. Increase Sequence"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Codeforces\D. Increase Sequence\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/D__Increase_Sequence.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/D__Increase_Sequence.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/D__Increase_Sequence.dir/flags.make

CMakeFiles/D__Increase_Sequence.dir/main.cpp.obj: CMakeFiles/D__Increase_Sequence.dir/flags.make
CMakeFiles/D__Increase_Sequence.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Codeforces\D. Increase Sequence\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/D__Increase_Sequence.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\D__Increase_Sequence.dir\main.cpp.obj -c "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Codeforces\D. Increase Sequence\main.cpp"

CMakeFiles/D__Increase_Sequence.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/D__Increase_Sequence.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Codeforces\D. Increase Sequence\main.cpp" > CMakeFiles\D__Increase_Sequence.dir\main.cpp.i

CMakeFiles/D__Increase_Sequence.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/D__Increase_Sequence.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Codeforces\D. Increase Sequence\main.cpp" -o CMakeFiles\D__Increase_Sequence.dir\main.cpp.s

# Object files for target D__Increase_Sequence
D__Increase_Sequence_OBJECTS = \
"CMakeFiles/D__Increase_Sequence.dir/main.cpp.obj"

# External object files for target D__Increase_Sequence
D__Increase_Sequence_EXTERNAL_OBJECTS =

D__Increase_Sequence.exe: CMakeFiles/D__Increase_Sequence.dir/main.cpp.obj
D__Increase_Sequence.exe: CMakeFiles/D__Increase_Sequence.dir/build.make
D__Increase_Sequence.exe: CMakeFiles/D__Increase_Sequence.dir/linklibs.rsp
D__Increase_Sequence.exe: CMakeFiles/D__Increase_Sequence.dir/objects1.rsp
D__Increase_Sequence.exe: CMakeFiles/D__Increase_Sequence.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Codeforces\D. Increase Sequence\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable D__Increase_Sequence.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\D__Increase_Sequence.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/D__Increase_Sequence.dir/build: D__Increase_Sequence.exe

.PHONY : CMakeFiles/D__Increase_Sequence.dir/build

CMakeFiles/D__Increase_Sequence.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\D__Increase_Sequence.dir\cmake_clean.cmake
.PHONY : CMakeFiles/D__Increase_Sequence.dir/clean

CMakeFiles/D__Increase_Sequence.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Codeforces\D. Increase Sequence" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Codeforces\D. Increase Sequence" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Codeforces\D. Increase Sequence\cmake-build-debug" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Codeforces\D. Increase Sequence\cmake-build-debug" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Codeforces\D. Increase Sequence\cmake-build-debug\CMakeFiles\D__Increase_Sequence.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/D__Increase_Sequence.dir/depend

