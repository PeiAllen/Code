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
CMAKE_SOURCE_DIR = "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\WAC\Wesley's Anger Contest 2 Problem 5"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\WAC\Wesley's Anger Contest 2 Problem 5\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Wesley_s_Anger_Contest_2_Problem_5.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Wesley_s_Anger_Contest_2_Problem_5.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Wesley_s_Anger_Contest_2_Problem_5.dir/flags.make

CMakeFiles/Wesley_s_Anger_Contest_2_Problem_5.dir/main.cpp.obj: CMakeFiles/Wesley_s_Anger_Contest_2_Problem_5.dir/flags.make
CMakeFiles/Wesley_s_Anger_Contest_2_Problem_5.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\WAC\Wesley's Anger Contest 2 Problem 5\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Wesley_s_Anger_Contest_2_Problem_5.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Wesley_s_Anger_Contest_2_Problem_5.dir\main.cpp.obj -c "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\WAC\Wesley's Anger Contest 2 Problem 5\main.cpp"

CMakeFiles/Wesley_s_Anger_Contest_2_Problem_5.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Wesley_s_Anger_Contest_2_Problem_5.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\WAC\Wesley's Anger Contest 2 Problem 5\main.cpp" > CMakeFiles\Wesley_s_Anger_Contest_2_Problem_5.dir\main.cpp.i

CMakeFiles/Wesley_s_Anger_Contest_2_Problem_5.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Wesley_s_Anger_Contest_2_Problem_5.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\WAC\Wesley's Anger Contest 2 Problem 5\main.cpp" -o CMakeFiles\Wesley_s_Anger_Contest_2_Problem_5.dir\main.cpp.s

# Object files for target Wesley_s_Anger_Contest_2_Problem_5
Wesley_s_Anger_Contest_2_Problem_5_OBJECTS = \
"CMakeFiles/Wesley_s_Anger_Contest_2_Problem_5.dir/main.cpp.obj"

# External object files for target Wesley_s_Anger_Contest_2_Problem_5
Wesley_s_Anger_Contest_2_Problem_5_EXTERNAL_OBJECTS =

Wesley_s_Anger_Contest_2_Problem_5.exe: CMakeFiles/Wesley_s_Anger_Contest_2_Problem_5.dir/main.cpp.obj
Wesley_s_Anger_Contest_2_Problem_5.exe: CMakeFiles/Wesley_s_Anger_Contest_2_Problem_5.dir/build.make
Wesley_s_Anger_Contest_2_Problem_5.exe: CMakeFiles/Wesley_s_Anger_Contest_2_Problem_5.dir/linklibs.rsp
Wesley_s_Anger_Contest_2_Problem_5.exe: CMakeFiles/Wesley_s_Anger_Contest_2_Problem_5.dir/objects1.rsp
Wesley_s_Anger_Contest_2_Problem_5.exe: CMakeFiles/Wesley_s_Anger_Contest_2_Problem_5.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\WAC\Wesley's Anger Contest 2 Problem 5\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Wesley_s_Anger_Contest_2_Problem_5.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Wesley_s_Anger_Contest_2_Problem_5.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Wesley_s_Anger_Contest_2_Problem_5.dir/build: Wesley_s_Anger_Contest_2_Problem_5.exe

.PHONY : CMakeFiles/Wesley_s_Anger_Contest_2_Problem_5.dir/build

CMakeFiles/Wesley_s_Anger_Contest_2_Problem_5.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Wesley_s_Anger_Contest_2_Problem_5.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Wesley_s_Anger_Contest_2_Problem_5.dir/clean

CMakeFiles/Wesley_s_Anger_Contest_2_Problem_5.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\WAC\Wesley's Anger Contest 2 Problem 5" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\WAC\Wesley's Anger Contest 2 Problem 5" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\WAC\Wesley's Anger Contest 2 Problem 5\cmake-build-debug" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\WAC\Wesley's Anger Contest 2 Problem 5\cmake-build-debug" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\WAC\Wesley's Anger Contest 2 Problem 5\cmake-build-debug\CMakeFiles\Wesley_s_Anger_Contest_2_Problem_5.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Wesley_s_Anger_Contest_2_Problem_5.dir/depend

