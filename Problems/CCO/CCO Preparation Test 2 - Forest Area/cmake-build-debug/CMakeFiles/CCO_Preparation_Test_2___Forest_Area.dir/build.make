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
CMAKE_SOURCE_DIR = "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\CCO\CCO Preparation Test 2 - Forest Area"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\CCO\CCO Preparation Test 2 - Forest Area\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/CCO_Preparation_Test_2___Forest_Area.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CCO_Preparation_Test_2___Forest_Area.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CCO_Preparation_Test_2___Forest_Area.dir/flags.make

CMakeFiles/CCO_Preparation_Test_2___Forest_Area.dir/main.cpp.obj: CMakeFiles/CCO_Preparation_Test_2___Forest_Area.dir/flags.make
CMakeFiles/CCO_Preparation_Test_2___Forest_Area.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\CCO\CCO Preparation Test 2 - Forest Area\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CCO_Preparation_Test_2___Forest_Area.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\CCO_Preparation_Test_2___Forest_Area.dir\main.cpp.obj -c "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\CCO\CCO Preparation Test 2 - Forest Area\main.cpp"

CMakeFiles/CCO_Preparation_Test_2___Forest_Area.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CCO_Preparation_Test_2___Forest_Area.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\CCO\CCO Preparation Test 2 - Forest Area\main.cpp" > CMakeFiles\CCO_Preparation_Test_2___Forest_Area.dir\main.cpp.i

CMakeFiles/CCO_Preparation_Test_2___Forest_Area.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CCO_Preparation_Test_2___Forest_Area.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\CCO\CCO Preparation Test 2 - Forest Area\main.cpp" -o CMakeFiles\CCO_Preparation_Test_2___Forest_Area.dir\main.cpp.s

# Object files for target CCO_Preparation_Test_2___Forest_Area
CCO_Preparation_Test_2___Forest_Area_OBJECTS = \
"CMakeFiles/CCO_Preparation_Test_2___Forest_Area.dir/main.cpp.obj"

# External object files for target CCO_Preparation_Test_2___Forest_Area
CCO_Preparation_Test_2___Forest_Area_EXTERNAL_OBJECTS =

CCO_Preparation_Test_2___Forest_Area.exe: CMakeFiles/CCO_Preparation_Test_2___Forest_Area.dir/main.cpp.obj
CCO_Preparation_Test_2___Forest_Area.exe: CMakeFiles/CCO_Preparation_Test_2___Forest_Area.dir/build.make
CCO_Preparation_Test_2___Forest_Area.exe: CMakeFiles/CCO_Preparation_Test_2___Forest_Area.dir/linklibs.rsp
CCO_Preparation_Test_2___Forest_Area.exe: CMakeFiles/CCO_Preparation_Test_2___Forest_Area.dir/objects1.rsp
CCO_Preparation_Test_2___Forest_Area.exe: CMakeFiles/CCO_Preparation_Test_2___Forest_Area.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\CCO\CCO Preparation Test 2 - Forest Area\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable CCO_Preparation_Test_2___Forest_Area.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\CCO_Preparation_Test_2___Forest_Area.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CCO_Preparation_Test_2___Forest_Area.dir/build: CCO_Preparation_Test_2___Forest_Area.exe

.PHONY : CMakeFiles/CCO_Preparation_Test_2___Forest_Area.dir/build

CMakeFiles/CCO_Preparation_Test_2___Forest_Area.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\CCO_Preparation_Test_2___Forest_Area.dir\cmake_clean.cmake
.PHONY : CMakeFiles/CCO_Preparation_Test_2___Forest_Area.dir/clean

CMakeFiles/CCO_Preparation_Test_2___Forest_Area.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\CCO\CCO Preparation Test 2 - Forest Area" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\CCO\CCO Preparation Test 2 - Forest Area" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\CCO\CCO Preparation Test 2 - Forest Area\cmake-build-debug" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\CCO\CCO Preparation Test 2 - Forest Area\cmake-build-debug" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\CCO\CCO Preparation Test 2 - Forest Area\cmake-build-debug\CMakeFiles\CCO_Preparation_Test_2___Forest_Area.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/CCO_Preparation_Test_2___Forest_Area.dir/depend
