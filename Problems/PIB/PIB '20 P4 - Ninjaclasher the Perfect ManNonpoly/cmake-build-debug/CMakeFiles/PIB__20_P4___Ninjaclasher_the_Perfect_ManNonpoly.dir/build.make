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
CMAKE_SOURCE_DIR = "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\PIB\PIB '20 P4 - Ninjaclasher the Perfect ManNonpoly"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\PIB\PIB '20 P4 - Ninjaclasher the Perfect ManNonpoly\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/PIB__20_P4___Ninjaclasher_the_Perfect_ManNonpoly.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/PIB__20_P4___Ninjaclasher_the_Perfect_ManNonpoly.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PIB__20_P4___Ninjaclasher_the_Perfect_ManNonpoly.dir/flags.make

CMakeFiles/PIB__20_P4___Ninjaclasher_the_Perfect_ManNonpoly.dir/main.cpp.obj: CMakeFiles/PIB__20_P4___Ninjaclasher_the_Perfect_ManNonpoly.dir/flags.make
CMakeFiles/PIB__20_P4___Ninjaclasher_the_Perfect_ManNonpoly.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\PIB\PIB '20 P4 - Ninjaclasher the Perfect ManNonpoly\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/PIB__20_P4___Ninjaclasher_the_Perfect_ManNonpoly.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\PIB__20_P4___Ninjaclasher_the_Perfect_ManNonpoly.dir\main.cpp.obj -c "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\PIB\PIB '20 P4 - Ninjaclasher the Perfect ManNonpoly\main.cpp"

CMakeFiles/PIB__20_P4___Ninjaclasher_the_Perfect_ManNonpoly.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PIB__20_P4___Ninjaclasher_the_Perfect_ManNonpoly.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\PIB\PIB '20 P4 - Ninjaclasher the Perfect ManNonpoly\main.cpp" > CMakeFiles\PIB__20_P4___Ninjaclasher_the_Perfect_ManNonpoly.dir\main.cpp.i

CMakeFiles/PIB__20_P4___Ninjaclasher_the_Perfect_ManNonpoly.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PIB__20_P4___Ninjaclasher_the_Perfect_ManNonpoly.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\PIB\PIB '20 P4 - Ninjaclasher the Perfect ManNonpoly\main.cpp" -o CMakeFiles\PIB__20_P4___Ninjaclasher_the_Perfect_ManNonpoly.dir\main.cpp.s

# Object files for target PIB__20_P4___Ninjaclasher_the_Perfect_ManNonpoly
PIB__20_P4___Ninjaclasher_the_Perfect_ManNonpoly_OBJECTS = \
"CMakeFiles/PIB__20_P4___Ninjaclasher_the_Perfect_ManNonpoly.dir/main.cpp.obj"

# External object files for target PIB__20_P4___Ninjaclasher_the_Perfect_ManNonpoly
PIB__20_P4___Ninjaclasher_the_Perfect_ManNonpoly_EXTERNAL_OBJECTS =

PIB__20_P4___Ninjaclasher_the_Perfect_ManNonpoly.exe: CMakeFiles/PIB__20_P4___Ninjaclasher_the_Perfect_ManNonpoly.dir/main.cpp.obj
PIB__20_P4___Ninjaclasher_the_Perfect_ManNonpoly.exe: CMakeFiles/PIB__20_P4___Ninjaclasher_the_Perfect_ManNonpoly.dir/build.make
PIB__20_P4___Ninjaclasher_the_Perfect_ManNonpoly.exe: CMakeFiles/PIB__20_P4___Ninjaclasher_the_Perfect_ManNonpoly.dir/linklibs.rsp
PIB__20_P4___Ninjaclasher_the_Perfect_ManNonpoly.exe: CMakeFiles/PIB__20_P4___Ninjaclasher_the_Perfect_ManNonpoly.dir/objects1.rsp
PIB__20_P4___Ninjaclasher_the_Perfect_ManNonpoly.exe: CMakeFiles/PIB__20_P4___Ninjaclasher_the_Perfect_ManNonpoly.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\PIB\PIB '20 P4 - Ninjaclasher the Perfect ManNonpoly\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable PIB__20_P4___Ninjaclasher_the_Perfect_ManNonpoly.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\PIB__20_P4___Ninjaclasher_the_Perfect_ManNonpoly.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PIB__20_P4___Ninjaclasher_the_Perfect_ManNonpoly.dir/build: PIB__20_P4___Ninjaclasher_the_Perfect_ManNonpoly.exe

.PHONY : CMakeFiles/PIB__20_P4___Ninjaclasher_the_Perfect_ManNonpoly.dir/build

CMakeFiles/PIB__20_P4___Ninjaclasher_the_Perfect_ManNonpoly.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\PIB__20_P4___Ninjaclasher_the_Perfect_ManNonpoly.dir\cmake_clean.cmake
.PHONY : CMakeFiles/PIB__20_P4___Ninjaclasher_the_Perfect_ManNonpoly.dir/clean

CMakeFiles/PIB__20_P4___Ninjaclasher_the_Perfect_ManNonpoly.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\PIB\PIB '20 P4 - Ninjaclasher the Perfect ManNonpoly" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\PIB\PIB '20 P4 - Ninjaclasher the Perfect ManNonpoly" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\PIB\PIB '20 P4 - Ninjaclasher the Perfect ManNonpoly\cmake-build-debug" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\PIB\PIB '20 P4 - Ninjaclasher the Perfect ManNonpoly\cmake-build-debug" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\PIB\PIB '20 P4 - Ninjaclasher the Perfect ManNonpoly\cmake-build-debug\CMakeFiles\PIB__20_P4___Ninjaclasher_the_Perfect_ManNonpoly.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/PIB__20_P4___Ninjaclasher_the_Perfect_ManNonpoly.dir/depend

