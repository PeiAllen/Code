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
CMAKE_SOURCE_DIR = "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Other\We Need To Talk About Fifty-Five"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Other\We Need To Talk About Fifty-Five\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/We_Need_To_Talk_About_Fifty_Five.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/We_Need_To_Talk_About_Fifty_Five.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/We_Need_To_Talk_About_Fifty_Five.dir/flags.make

CMakeFiles/We_Need_To_Talk_About_Fifty_Five.dir/main.cpp.obj: CMakeFiles/We_Need_To_Talk_About_Fifty_Five.dir/flags.make
CMakeFiles/We_Need_To_Talk_About_Fifty_Five.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Other\We Need To Talk About Fifty-Five\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/We_Need_To_Talk_About_Fifty_Five.dir/main.cpp.obj"
	C:\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\We_Need_To_Talk_About_Fifty_Five.dir\main.cpp.obj -c "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Other\We Need To Talk About Fifty-Five\main.cpp"

CMakeFiles/We_Need_To_Talk_About_Fifty_Five.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/We_Need_To_Talk_About_Fifty_Five.dir/main.cpp.i"
	C:\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Other\We Need To Talk About Fifty-Five\main.cpp" > CMakeFiles\We_Need_To_Talk_About_Fifty_Five.dir\main.cpp.i

CMakeFiles/We_Need_To_Talk_About_Fifty_Five.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/We_Need_To_Talk_About_Fifty_Five.dir/main.cpp.s"
	C:\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Other\We Need To Talk About Fifty-Five\main.cpp" -o CMakeFiles\We_Need_To_Talk_About_Fifty_Five.dir\main.cpp.s

# Object files for target We_Need_To_Talk_About_Fifty_Five
We_Need_To_Talk_About_Fifty_Five_OBJECTS = \
"CMakeFiles/We_Need_To_Talk_About_Fifty_Five.dir/main.cpp.obj"

# External object files for target We_Need_To_Talk_About_Fifty_Five
We_Need_To_Talk_About_Fifty_Five_EXTERNAL_OBJECTS =

We_Need_To_Talk_About_Fifty_Five.exe: CMakeFiles/We_Need_To_Talk_About_Fifty_Five.dir/main.cpp.obj
We_Need_To_Talk_About_Fifty_Five.exe: CMakeFiles/We_Need_To_Talk_About_Fifty_Five.dir/build.make
We_Need_To_Talk_About_Fifty_Five.exe: CMakeFiles/We_Need_To_Talk_About_Fifty_Five.dir/linklibs.rsp
We_Need_To_Talk_About_Fifty_Five.exe: CMakeFiles/We_Need_To_Talk_About_Fifty_Five.dir/objects1.rsp
We_Need_To_Talk_About_Fifty_Five.exe: CMakeFiles/We_Need_To_Talk_About_Fifty_Five.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Other\We Need To Talk About Fifty-Five\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable We_Need_To_Talk_About_Fifty_Five.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\We_Need_To_Talk_About_Fifty_Five.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/We_Need_To_Talk_About_Fifty_Five.dir/build: We_Need_To_Talk_About_Fifty_Five.exe

.PHONY : CMakeFiles/We_Need_To_Talk_About_Fifty_Five.dir/build

CMakeFiles/We_Need_To_Talk_About_Fifty_Five.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\We_Need_To_Talk_About_Fifty_Five.dir\cmake_clean.cmake
.PHONY : CMakeFiles/We_Need_To_Talk_About_Fifty_Five.dir/clean

CMakeFiles/We_Need_To_Talk_About_Fifty_Five.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Other\We Need To Talk About Fifty-Five" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Other\We Need To Talk About Fifty-Five" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Other\We Need To Talk About Fifty-Five\cmake-build-debug" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Other\We Need To Talk About Fifty-Five\cmake-build-debug" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Other\We Need To Talk About Fifty-Five\cmake-build-debug\CMakeFiles\We_Need_To_Talk_About_Fifty_Five.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/We_Need_To_Talk_About_Fifty_Five.dir/depend
