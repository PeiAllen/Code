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
CMAKE_SOURCE_DIR = "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Other\City Game II"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Other\City Game II\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/City_Game_II.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/City_Game_II.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/City_Game_II.dir/flags.make

CMakeFiles/City_Game_II.dir/main.cpp.obj: CMakeFiles/City_Game_II.dir/flags.make
CMakeFiles/City_Game_II.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Other\City Game II\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/City_Game_II.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\City_Game_II.dir\main.cpp.obj -c "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Other\City Game II\main.cpp"

CMakeFiles/City_Game_II.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/City_Game_II.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Other\City Game II\main.cpp" > CMakeFiles\City_Game_II.dir\main.cpp.i

CMakeFiles/City_Game_II.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/City_Game_II.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Other\City Game II\main.cpp" -o CMakeFiles\City_Game_II.dir\main.cpp.s

# Object files for target City_Game_II
City_Game_II_OBJECTS = \
"CMakeFiles/City_Game_II.dir/main.cpp.obj"

# External object files for target City_Game_II
City_Game_II_EXTERNAL_OBJECTS =

City_Game_II.exe: CMakeFiles/City_Game_II.dir/main.cpp.obj
City_Game_II.exe: CMakeFiles/City_Game_II.dir/build.make
City_Game_II.exe: CMakeFiles/City_Game_II.dir/linklibs.rsp
City_Game_II.exe: CMakeFiles/City_Game_II.dir/objects1.rsp
City_Game_II.exe: CMakeFiles/City_Game_II.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Other\City Game II\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable City_Game_II.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\City_Game_II.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/City_Game_II.dir/build: City_Game_II.exe

.PHONY : CMakeFiles/City_Game_II.dir/build

CMakeFiles/City_Game_II.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\City_Game_II.dir\cmake_clean.cmake
.PHONY : CMakeFiles/City_Game_II.dir/clean

CMakeFiles/City_Game_II.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Other\City Game II" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Other\City Game II" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Other\City Game II\cmake-build-debug" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Other\City Game II\cmake-build-debug" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Other\City Game II\cmake-build-debug\CMakeFiles\City_Game_II.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/City_Game_II.dir/depend

