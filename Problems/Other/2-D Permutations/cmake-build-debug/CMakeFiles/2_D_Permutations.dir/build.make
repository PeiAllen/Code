# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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
CMAKE_SOURCE_DIR = "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Other\2-D Permutations"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Other\2-D Permutations\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/2_D_Permutations.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/2_D_Permutations.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/2_D_Permutations.dir/flags.make

CMakeFiles/2_D_Permutations.dir/main.cpp.obj: CMakeFiles/2_D_Permutations.dir/flags.make
CMakeFiles/2_D_Permutations.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Other\2-D Permutations\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/2_D_Permutations.dir/main.cpp.obj"
	C:\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\2_D_Permutations.dir\main.cpp.obj -c "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Other\2-D Permutations\main.cpp"

CMakeFiles/2_D_Permutations.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/2_D_Permutations.dir/main.cpp.i"
	C:\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Other\2-D Permutations\main.cpp" > CMakeFiles\2_D_Permutations.dir\main.cpp.i

CMakeFiles/2_D_Permutations.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/2_D_Permutations.dir/main.cpp.s"
	C:\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Other\2-D Permutations\main.cpp" -o CMakeFiles\2_D_Permutations.dir\main.cpp.s

# Object files for target 2_D_Permutations
2_D_Permutations_OBJECTS = \
"CMakeFiles/2_D_Permutations.dir/main.cpp.obj"

# External object files for target 2_D_Permutations
2_D_Permutations_EXTERNAL_OBJECTS =

2_D_Permutations.exe: CMakeFiles/2_D_Permutations.dir/main.cpp.obj
2_D_Permutations.exe: CMakeFiles/2_D_Permutations.dir/build.make
2_D_Permutations.exe: CMakeFiles/2_D_Permutations.dir/linklibs.rsp
2_D_Permutations.exe: CMakeFiles/2_D_Permutations.dir/objects1.rsp
2_D_Permutations.exe: CMakeFiles/2_D_Permutations.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Other\2-D Permutations\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 2_D_Permutations.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\2_D_Permutations.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/2_D_Permutations.dir/build: 2_D_Permutations.exe

.PHONY : CMakeFiles/2_D_Permutations.dir/build

CMakeFiles/2_D_Permutations.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\2_D_Permutations.dir\cmake_clean.cmake
.PHONY : CMakeFiles/2_D_Permutations.dir/clean

CMakeFiles/2_D_Permutations.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Other\2-D Permutations" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Other\2-D Permutations" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Other\2-D Permutations\cmake-build-debug" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Other\2-D Permutations\cmake-build-debug" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Other\2-D Permutations\cmake-build-debug\CMakeFiles\2_D_Permutations.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/2_D_Permutations.dir/depend

