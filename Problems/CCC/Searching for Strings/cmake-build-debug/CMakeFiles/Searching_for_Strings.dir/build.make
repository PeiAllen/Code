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
CMAKE_SOURCE_DIR = "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\CCC\Searching for Strings"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\CCC\Searching for Strings\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Searching_for_Strings.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Searching_for_Strings.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Searching_for_Strings.dir/flags.make

CMakeFiles/Searching_for_Strings.dir/main.cpp.obj: CMakeFiles/Searching_for_Strings.dir/flags.make
CMakeFiles/Searching_for_Strings.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\CCC\Searching for Strings\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Searching_for_Strings.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Searching_for_Strings.dir\main.cpp.obj -c "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\CCC\Searching for Strings\main.cpp"

CMakeFiles/Searching_for_Strings.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Searching_for_Strings.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\CCC\Searching for Strings\main.cpp" > CMakeFiles\Searching_for_Strings.dir\main.cpp.i

CMakeFiles/Searching_for_Strings.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Searching_for_Strings.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\CCC\Searching for Strings\main.cpp" -o CMakeFiles\Searching_for_Strings.dir\main.cpp.s

# Object files for target Searching_for_Strings
Searching_for_Strings_OBJECTS = \
"CMakeFiles/Searching_for_Strings.dir/main.cpp.obj"

# External object files for target Searching_for_Strings
Searching_for_Strings_EXTERNAL_OBJECTS =

Searching_for_Strings.exe: CMakeFiles/Searching_for_Strings.dir/main.cpp.obj
Searching_for_Strings.exe: CMakeFiles/Searching_for_Strings.dir/build.make
Searching_for_Strings.exe: CMakeFiles/Searching_for_Strings.dir/linklibs.rsp
Searching_for_Strings.exe: CMakeFiles/Searching_for_Strings.dir/objects1.rsp
Searching_for_Strings.exe: CMakeFiles/Searching_for_Strings.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\CCC\Searching for Strings\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Searching_for_Strings.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Searching_for_Strings.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Searching_for_Strings.dir/build: Searching_for_Strings.exe

.PHONY : CMakeFiles/Searching_for_Strings.dir/build

CMakeFiles/Searching_for_Strings.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Searching_for_Strings.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Searching_for_Strings.dir/clean

CMakeFiles/Searching_for_Strings.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\CCC\Searching for Strings" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\CCC\Searching for Strings" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\CCC\Searching for Strings\cmake-build-debug" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\CCC\Searching for Strings\cmake-build-debug" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\CCC\Searching for Strings\cmake-build-debug\CMakeFiles\Searching_for_Strings.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Searching_for_Strings.dir/depend

