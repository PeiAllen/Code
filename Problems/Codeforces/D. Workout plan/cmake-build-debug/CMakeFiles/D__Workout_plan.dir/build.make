# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/allen/Documents/GitHub/Code/Problems/Codeforces/D. Workout plan"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/allen/Documents/GitHub/Code/Problems/Codeforces/D. Workout plan/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/D__Workout_plan.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/D__Workout_plan.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/D__Workout_plan.dir/flags.make

CMakeFiles/D__Workout_plan.dir/main.cpp.o: CMakeFiles/D__Workout_plan.dir/flags.make
CMakeFiles/D__Workout_plan.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/allen/Documents/GitHub/Code/Problems/Codeforces/D. Workout plan/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/D__Workout_plan.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/D__Workout_plan.dir/main.cpp.o -c "/Users/allen/Documents/GitHub/Code/Problems/Codeforces/D. Workout plan/main.cpp"

CMakeFiles/D__Workout_plan.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/D__Workout_plan.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/allen/Documents/GitHub/Code/Problems/Codeforces/D. Workout plan/main.cpp" > CMakeFiles/D__Workout_plan.dir/main.cpp.i

CMakeFiles/D__Workout_plan.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/D__Workout_plan.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/allen/Documents/GitHub/Code/Problems/Codeforces/D. Workout plan/main.cpp" -o CMakeFiles/D__Workout_plan.dir/main.cpp.s

# Object files for target D__Workout_plan
D__Workout_plan_OBJECTS = \
"CMakeFiles/D__Workout_plan.dir/main.cpp.o"

# External object files for target D__Workout_plan
D__Workout_plan_EXTERNAL_OBJECTS =

D__Workout_plan: CMakeFiles/D__Workout_plan.dir/main.cpp.o
D__Workout_plan: CMakeFiles/D__Workout_plan.dir/build.make
D__Workout_plan: CMakeFiles/D__Workout_plan.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/allen/Documents/GitHub/Code/Problems/Codeforces/D. Workout plan/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable D__Workout_plan"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/D__Workout_plan.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/D__Workout_plan.dir/build: D__Workout_plan

.PHONY : CMakeFiles/D__Workout_plan.dir/build

CMakeFiles/D__Workout_plan.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/D__Workout_plan.dir/cmake_clean.cmake
.PHONY : CMakeFiles/D__Workout_plan.dir/clean

CMakeFiles/D__Workout_plan.dir/depend:
	cd "/Users/allen/Documents/GitHub/Code/Problems/Codeforces/D. Workout plan/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/allen/Documents/GitHub/Code/Problems/Codeforces/D. Workout plan" "/Users/allen/Documents/GitHub/Code/Problems/Codeforces/D. Workout plan" "/Users/allen/Documents/GitHub/Code/Problems/Codeforces/D. Workout plan/cmake-build-debug" "/Users/allen/Documents/GitHub/Code/Problems/Codeforces/D. Workout plan/cmake-build-debug" "/Users/allen/Documents/GitHub/Code/Problems/Codeforces/D. Workout plan/cmake-build-debug/CMakeFiles/D__Workout_plan.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/D__Workout_plan.dir/depend

