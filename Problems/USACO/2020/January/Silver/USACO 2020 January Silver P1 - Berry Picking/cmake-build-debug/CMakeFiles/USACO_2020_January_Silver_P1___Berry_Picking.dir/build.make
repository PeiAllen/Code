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
CMAKE_SOURCE_DIR = "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\USACO\2020\January\Silver\USACO 2020 January Silver P1 - Berry Picking"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\USACO\2020\January\Silver\USACO 2020 January Silver P1 - Berry Picking\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/USACO_2020_January_Silver_P1___Berry_Picking.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/USACO_2020_January_Silver_P1___Berry_Picking.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/USACO_2020_January_Silver_P1___Berry_Picking.dir/flags.make

CMakeFiles/USACO_2020_January_Silver_P1___Berry_Picking.dir/main.cpp.obj: CMakeFiles/USACO_2020_January_Silver_P1___Berry_Picking.dir/flags.make
CMakeFiles/USACO_2020_January_Silver_P1___Berry_Picking.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\USACO\2020\January\Silver\USACO 2020 January Silver P1 - Berry Picking\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/USACO_2020_January_Silver_P1___Berry_Picking.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\USACO_2020_January_Silver_P1___Berry_Picking.dir\main.cpp.obj -c "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\USACO\2020\January\Silver\USACO 2020 January Silver P1 - Berry Picking\main.cpp"

CMakeFiles/USACO_2020_January_Silver_P1___Berry_Picking.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/USACO_2020_January_Silver_P1___Berry_Picking.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\USACO\2020\January\Silver\USACO 2020 January Silver P1 - Berry Picking\main.cpp" > CMakeFiles\USACO_2020_January_Silver_P1___Berry_Picking.dir\main.cpp.i

CMakeFiles/USACO_2020_January_Silver_P1___Berry_Picking.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/USACO_2020_January_Silver_P1___Berry_Picking.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\USACO\2020\January\Silver\USACO 2020 January Silver P1 - Berry Picking\main.cpp" -o CMakeFiles\USACO_2020_January_Silver_P1___Berry_Picking.dir\main.cpp.s

# Object files for target USACO_2020_January_Silver_P1___Berry_Picking
USACO_2020_January_Silver_P1___Berry_Picking_OBJECTS = \
"CMakeFiles/USACO_2020_January_Silver_P1___Berry_Picking.dir/main.cpp.obj"

# External object files for target USACO_2020_January_Silver_P1___Berry_Picking
USACO_2020_January_Silver_P1___Berry_Picking_EXTERNAL_OBJECTS =

USACO_2020_January_Silver_P1___Berry_Picking.exe: CMakeFiles/USACO_2020_January_Silver_P1___Berry_Picking.dir/main.cpp.obj
USACO_2020_January_Silver_P1___Berry_Picking.exe: CMakeFiles/USACO_2020_January_Silver_P1___Berry_Picking.dir/build.make
USACO_2020_January_Silver_P1___Berry_Picking.exe: CMakeFiles/USACO_2020_January_Silver_P1___Berry_Picking.dir/linklibs.rsp
USACO_2020_January_Silver_P1___Berry_Picking.exe: CMakeFiles/USACO_2020_January_Silver_P1___Berry_Picking.dir/objects1.rsp
USACO_2020_January_Silver_P1___Berry_Picking.exe: CMakeFiles/USACO_2020_January_Silver_P1___Berry_Picking.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\USACO\2020\January\Silver\USACO 2020 January Silver P1 - Berry Picking\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable USACO_2020_January_Silver_P1___Berry_Picking.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\USACO_2020_January_Silver_P1___Berry_Picking.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/USACO_2020_January_Silver_P1___Berry_Picking.dir/build: USACO_2020_January_Silver_P1___Berry_Picking.exe

.PHONY : CMakeFiles/USACO_2020_January_Silver_P1___Berry_Picking.dir/build

CMakeFiles/USACO_2020_January_Silver_P1___Berry_Picking.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\USACO_2020_January_Silver_P1___Berry_Picking.dir\cmake_clean.cmake
.PHONY : CMakeFiles/USACO_2020_January_Silver_P1___Berry_Picking.dir/clean

CMakeFiles/USACO_2020_January_Silver_P1___Berry_Picking.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\USACO\2020\January\Silver\USACO 2020 January Silver P1 - Berry Picking" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\USACO\2020\January\Silver\USACO 2020 January Silver P1 - Berry Picking" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\USACO\2020\January\Silver\USACO 2020 January Silver P1 - Berry Picking\cmake-build-debug" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\USACO\2020\January\Silver\USACO 2020 January Silver P1 - Berry Picking\cmake-build-debug" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\USACO\2020\January\Silver\USACO 2020 January Silver P1 - Berry Picking\cmake-build-debug\CMakeFiles\USACO_2020_January_Silver_P1___Berry_Picking.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/USACO_2020_January_Silver_P1___Berry_Picking.dir/depend

