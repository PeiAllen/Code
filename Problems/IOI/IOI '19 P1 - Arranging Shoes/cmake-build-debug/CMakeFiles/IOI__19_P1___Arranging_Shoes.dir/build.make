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
CMAKE_SOURCE_DIR = "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\IOI\IOI '19 P1 - Arranging Shoes"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\IOI\IOI '19 P1 - Arranging Shoes\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/IOI__19_P1___Arranging_Shoes.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/IOI__19_P1___Arranging_Shoes.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/IOI__19_P1___Arranging_Shoes.dir/flags.make

CMakeFiles/IOI__19_P1___Arranging_Shoes.dir/main.cpp.obj: CMakeFiles/IOI__19_P1___Arranging_Shoes.dir/flags.make
CMakeFiles/IOI__19_P1___Arranging_Shoes.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\IOI\IOI '19 P1 - Arranging Shoes\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/IOI__19_P1___Arranging_Shoes.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\IOI__19_P1___Arranging_Shoes.dir\main.cpp.obj -c "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\IOI\IOI '19 P1 - Arranging Shoes\main.cpp"

CMakeFiles/IOI__19_P1___Arranging_Shoes.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/IOI__19_P1___Arranging_Shoes.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\IOI\IOI '19 P1 - Arranging Shoes\main.cpp" > CMakeFiles\IOI__19_P1___Arranging_Shoes.dir\main.cpp.i

CMakeFiles/IOI__19_P1___Arranging_Shoes.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/IOI__19_P1___Arranging_Shoes.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\IOI\IOI '19 P1 - Arranging Shoes\main.cpp" -o CMakeFiles\IOI__19_P1___Arranging_Shoes.dir\main.cpp.s

# Object files for target IOI__19_P1___Arranging_Shoes
IOI__19_P1___Arranging_Shoes_OBJECTS = \
"CMakeFiles/IOI__19_P1___Arranging_Shoes.dir/main.cpp.obj"

# External object files for target IOI__19_P1___Arranging_Shoes
IOI__19_P1___Arranging_Shoes_EXTERNAL_OBJECTS =

IOI__19_P1___Arranging_Shoes.exe: CMakeFiles/IOI__19_P1___Arranging_Shoes.dir/main.cpp.obj
IOI__19_P1___Arranging_Shoes.exe: CMakeFiles/IOI__19_P1___Arranging_Shoes.dir/build.make
IOI__19_P1___Arranging_Shoes.exe: CMakeFiles/IOI__19_P1___Arranging_Shoes.dir/linklibs.rsp
IOI__19_P1___Arranging_Shoes.exe: CMakeFiles/IOI__19_P1___Arranging_Shoes.dir/objects1.rsp
IOI__19_P1___Arranging_Shoes.exe: CMakeFiles/IOI__19_P1___Arranging_Shoes.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\IOI\IOI '19 P1 - Arranging Shoes\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable IOI__19_P1___Arranging_Shoes.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\IOI__19_P1___Arranging_Shoes.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/IOI__19_P1___Arranging_Shoes.dir/build: IOI__19_P1___Arranging_Shoes.exe

.PHONY : CMakeFiles/IOI__19_P1___Arranging_Shoes.dir/build

CMakeFiles/IOI__19_P1___Arranging_Shoes.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\IOI__19_P1___Arranging_Shoes.dir\cmake_clean.cmake
.PHONY : CMakeFiles/IOI__19_P1___Arranging_Shoes.dir/clean

CMakeFiles/IOI__19_P1___Arranging_Shoes.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\IOI\IOI '19 P1 - Arranging Shoes" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\IOI\IOI '19 P1 - Arranging Shoes" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\IOI\IOI '19 P1 - Arranging Shoes\cmake-build-debug" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\IOI\IOI '19 P1 - Arranging Shoes\cmake-build-debug" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\IOI\IOI '19 P1 - Arranging Shoes\cmake-build-debug\CMakeFiles\IOI__19_P1___Arranging_Shoes.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/IOI__19_P1___Arranging_Shoes.dir/depend

