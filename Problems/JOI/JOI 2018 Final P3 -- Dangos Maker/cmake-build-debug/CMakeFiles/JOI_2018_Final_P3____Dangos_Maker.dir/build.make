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
CMAKE_SOURCE_DIR = "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\JOI\JOI 2018 Final P3 -- Dangos Maker"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\JOI\JOI 2018 Final P3 -- Dangos Maker\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/JOI_2018_Final_P3____Dangos_Maker.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/JOI_2018_Final_P3____Dangos_Maker.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/JOI_2018_Final_P3____Dangos_Maker.dir/flags.make

CMakeFiles/JOI_2018_Final_P3____Dangos_Maker.dir/main.cpp.obj: CMakeFiles/JOI_2018_Final_P3____Dangos_Maker.dir/flags.make
CMakeFiles/JOI_2018_Final_P3____Dangos_Maker.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\JOI\JOI 2018 Final P3 -- Dangos Maker\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/JOI_2018_Final_P3____Dangos_Maker.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\JOI_2018_Final_P3____Dangos_Maker.dir\main.cpp.obj -c "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\JOI\JOI 2018 Final P3 -- Dangos Maker\main.cpp"

CMakeFiles/JOI_2018_Final_P3____Dangos_Maker.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/JOI_2018_Final_P3____Dangos_Maker.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\JOI\JOI 2018 Final P3 -- Dangos Maker\main.cpp" > CMakeFiles\JOI_2018_Final_P3____Dangos_Maker.dir\main.cpp.i

CMakeFiles/JOI_2018_Final_P3____Dangos_Maker.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/JOI_2018_Final_P3____Dangos_Maker.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\JOI\JOI 2018 Final P3 -- Dangos Maker\main.cpp" -o CMakeFiles\JOI_2018_Final_P3____Dangos_Maker.dir\main.cpp.s

# Object files for target JOI_2018_Final_P3____Dangos_Maker
JOI_2018_Final_P3____Dangos_Maker_OBJECTS = \
"CMakeFiles/JOI_2018_Final_P3____Dangos_Maker.dir/main.cpp.obj"

# External object files for target JOI_2018_Final_P3____Dangos_Maker
JOI_2018_Final_P3____Dangos_Maker_EXTERNAL_OBJECTS =

JOI_2018_Final_P3____Dangos_Maker.exe: CMakeFiles/JOI_2018_Final_P3____Dangos_Maker.dir/main.cpp.obj
JOI_2018_Final_P3____Dangos_Maker.exe: CMakeFiles/JOI_2018_Final_P3____Dangos_Maker.dir/build.make
JOI_2018_Final_P3____Dangos_Maker.exe: CMakeFiles/JOI_2018_Final_P3____Dangos_Maker.dir/linklibs.rsp
JOI_2018_Final_P3____Dangos_Maker.exe: CMakeFiles/JOI_2018_Final_P3____Dangos_Maker.dir/objects1.rsp
JOI_2018_Final_P3____Dangos_Maker.exe: CMakeFiles/JOI_2018_Final_P3____Dangos_Maker.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\JOI\JOI 2018 Final P3 -- Dangos Maker\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable JOI_2018_Final_P3____Dangos_Maker.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\JOI_2018_Final_P3____Dangos_Maker.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/JOI_2018_Final_P3____Dangos_Maker.dir/build: JOI_2018_Final_P3____Dangos_Maker.exe

.PHONY : CMakeFiles/JOI_2018_Final_P3____Dangos_Maker.dir/build

CMakeFiles/JOI_2018_Final_P3____Dangos_Maker.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\JOI_2018_Final_P3____Dangos_Maker.dir\cmake_clean.cmake
.PHONY : CMakeFiles/JOI_2018_Final_P3____Dangos_Maker.dir/clean

CMakeFiles/JOI_2018_Final_P3____Dangos_Maker.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\JOI\JOI 2018 Final P3 -- Dangos Maker" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\JOI\JOI 2018 Final P3 -- Dangos Maker" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\JOI\JOI 2018 Final P3 -- Dangos Maker\cmake-build-debug" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\JOI\JOI 2018 Final P3 -- Dangos Maker\cmake-build-debug" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\JOI\JOI 2018 Final P3 -- Dangos Maker\cmake-build-debug\CMakeFiles\JOI_2018_Final_P3____Dangos_Maker.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/JOI_2018_Final_P3____Dangos_Maker.dir/depend

