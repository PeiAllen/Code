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
CMAKE_SOURCE_DIR = "C:\Users\allen\CLionProjects\DMPG '17 G4 - Timeline"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\allen\CLionProjects\DMPG '17 G4 - Timeline\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/DMPG__17_G4___Timeline.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/DMPG__17_G4___Timeline.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DMPG__17_G4___Timeline.dir/flags.make

CMakeFiles/DMPG__17_G4___Timeline.dir/main.cpp.obj: CMakeFiles/DMPG__17_G4___Timeline.dir/flags.make
CMakeFiles/DMPG__17_G4___Timeline.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\allen\CLionProjects\DMPG '17 G4 - Timeline\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DMPG__17_G4___Timeline.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\DMPG__17_G4___Timeline.dir\main.cpp.obj -c "C:\Users\allen\CLionProjects\DMPG '17 G4 - Timeline\main.cpp"

CMakeFiles/DMPG__17_G4___Timeline.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DMPG__17_G4___Timeline.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\allen\CLionProjects\DMPG '17 G4 - Timeline\main.cpp" > CMakeFiles\DMPG__17_G4___Timeline.dir\main.cpp.i

CMakeFiles/DMPG__17_G4___Timeline.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DMPG__17_G4___Timeline.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\allen\CLionProjects\DMPG '17 G4 - Timeline\main.cpp" -o CMakeFiles\DMPG__17_G4___Timeline.dir\main.cpp.s

# Object files for target DMPG__17_G4___Timeline
DMPG__17_G4___Timeline_OBJECTS = \
"CMakeFiles/DMPG__17_G4___Timeline.dir/main.cpp.obj"

# External object files for target DMPG__17_G4___Timeline
DMPG__17_G4___Timeline_EXTERNAL_OBJECTS =

DMPG__17_G4___Timeline.exe: CMakeFiles/DMPG__17_G4___Timeline.dir/main.cpp.obj
DMPG__17_G4___Timeline.exe: CMakeFiles/DMPG__17_G4___Timeline.dir/build.make
DMPG__17_G4___Timeline.exe: CMakeFiles/DMPG__17_G4___Timeline.dir/linklibs.rsp
DMPG__17_G4___Timeline.exe: CMakeFiles/DMPG__17_G4___Timeline.dir/objects1.rsp
DMPG__17_G4___Timeline.exe: CMakeFiles/DMPG__17_G4___Timeline.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\allen\CLionProjects\DMPG '17 G4 - Timeline\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable DMPG__17_G4___Timeline.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\DMPG__17_G4___Timeline.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DMPG__17_G4___Timeline.dir/build: DMPG__17_G4___Timeline.exe

.PHONY : CMakeFiles/DMPG__17_G4___Timeline.dir/build

CMakeFiles/DMPG__17_G4___Timeline.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\DMPG__17_G4___Timeline.dir\cmake_clean.cmake
.PHONY : CMakeFiles/DMPG__17_G4___Timeline.dir/clean

CMakeFiles/DMPG__17_G4___Timeline.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\allen\CLionProjects\DMPG '17 G4 - Timeline" "C:\Users\allen\CLionProjects\DMPG '17 G4 - Timeline" "C:\Users\allen\CLionProjects\DMPG '17 G4 - Timeline\cmake-build-debug" "C:\Users\allen\CLionProjects\DMPG '17 G4 - Timeline\cmake-build-debug" "C:\Users\allen\CLionProjects\DMPG '17 G4 - Timeline\cmake-build-debug\CMakeFiles\DMPG__17_G4___Timeline.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/DMPG__17_G4___Timeline.dir/depend
