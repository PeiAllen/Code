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
CMAKE_SOURCE_DIR = "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Codeforces\E. Count The Blocks"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Codeforces\E. Count The Blocks\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/E__Count_The_Blocks.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/E__Count_The_Blocks.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/E__Count_The_Blocks.dir/flags.make

CMakeFiles/E__Count_The_Blocks.dir/main.cpp.obj: CMakeFiles/E__Count_The_Blocks.dir/flags.make
CMakeFiles/E__Count_The_Blocks.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Codeforces\E. Count The Blocks\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/E__Count_The_Blocks.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\E__Count_The_Blocks.dir\main.cpp.obj -c "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Codeforces\E. Count The Blocks\main.cpp"

CMakeFiles/E__Count_The_Blocks.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/E__Count_The_Blocks.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Codeforces\E. Count The Blocks\main.cpp" > CMakeFiles\E__Count_The_Blocks.dir\main.cpp.i

CMakeFiles/E__Count_The_Blocks.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/E__Count_The_Blocks.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Codeforces\E. Count The Blocks\main.cpp" -o CMakeFiles\E__Count_The_Blocks.dir\main.cpp.s

# Object files for target E__Count_The_Blocks
E__Count_The_Blocks_OBJECTS = \
"CMakeFiles/E__Count_The_Blocks.dir/main.cpp.obj"

# External object files for target E__Count_The_Blocks
E__Count_The_Blocks_EXTERNAL_OBJECTS =

E__Count_The_Blocks.exe: CMakeFiles/E__Count_The_Blocks.dir/main.cpp.obj
E__Count_The_Blocks.exe: CMakeFiles/E__Count_The_Blocks.dir/build.make
E__Count_The_Blocks.exe: CMakeFiles/E__Count_The_Blocks.dir/linklibs.rsp
E__Count_The_Blocks.exe: CMakeFiles/E__Count_The_Blocks.dir/objects1.rsp
E__Count_The_Blocks.exe: CMakeFiles/E__Count_The_Blocks.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Codeforces\E. Count The Blocks\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable E__Count_The_Blocks.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\E__Count_The_Blocks.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/E__Count_The_Blocks.dir/build: E__Count_The_Blocks.exe

.PHONY : CMakeFiles/E__Count_The_Blocks.dir/build

CMakeFiles/E__Count_The_Blocks.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\E__Count_The_Blocks.dir\cmake_clean.cmake
.PHONY : CMakeFiles/E__Count_The_Blocks.dir/clean

CMakeFiles/E__Count_The_Blocks.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Codeforces\E. Count The Blocks" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Codeforces\E. Count The Blocks" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Codeforces\E. Count The Blocks\cmake-build-debug" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Codeforces\E. Count The Blocks\cmake-build-debug" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Codeforces\E. Count The Blocks\cmake-build-debug\CMakeFiles\E__Count_The_Blocks.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/E__Count_The_Blocks.dir/depend

