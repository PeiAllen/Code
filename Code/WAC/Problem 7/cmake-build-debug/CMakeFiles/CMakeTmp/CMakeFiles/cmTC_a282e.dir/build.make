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


# Produce verbose output by default.
VERBOSE = 1

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.1.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.1.3\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\allen\Documents\GitHub\Code\Code\Problem 7\cmake-build-debug\CMakeFiles\CMakeTmp"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\allen\Documents\GitHub\Code\Code\Problem 7\cmake-build-debug\CMakeFiles\CMakeTmp"

# Include any dependencies generated for this target.
include CMakeFiles/cmTC_a282e.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cmTC_a282e.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cmTC_a282e.dir/flags.make

CMakeFiles/cmTC_a282e.dir/feature_tests.cxx.obj: CMakeFiles/cmTC_a282e.dir/flags.make
CMakeFiles/cmTC_a282e.dir/feature_tests.cxx.obj: C:/Users/allen/Documents/GitHub/Code/Code/Problem\ 7/cmake-build-debug/CMakeFiles/feature_tests.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --progress-dir="C:\Users\allen\Documents\GitHub\Code\Code\Problem 7\cmake-build-debug\CMakeFiles\CMakeTmp\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cmTC_a282e.dir/feature_tests.cxx.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\cmTC_a282e.dir\feature_tests.cxx.obj -c "C:\Users\allen\Documents\GitHub\Code\Code\Problem 7\cmake-build-debug\CMakeFiles\feature_tests.cxx"

CMakeFiles/cmTC_a282e.dir/feature_tests.cxx.i: cmake_force
	@echo Preprocessing CXX source to CMakeFiles/cmTC_a282e.dir/feature_tests.cxx.i
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\allen\Documents\GitHub\Code\Code\Problem 7\cmake-build-debug\CMakeFiles\feature_tests.cxx" > CMakeFiles\cmTC_a282e.dir\feature_tests.cxx.i

CMakeFiles/cmTC_a282e.dir/feature_tests.cxx.s: cmake_force
	@echo Compiling CXX source to assembly CMakeFiles/cmTC_a282e.dir/feature_tests.cxx.s
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\allen\Documents\GitHub\Code\Code\Problem 7\cmake-build-debug\CMakeFiles\feature_tests.cxx" -o CMakeFiles\cmTC_a282e.dir\feature_tests.cxx.s

# Object files for target cmTC_a282e
cmTC_a282e_OBJECTS = \
"CMakeFiles/cmTC_a282e.dir/feature_tests.cxx.obj"

# External object files for target cmTC_a282e
cmTC_a282e_EXTERNAL_OBJECTS =

cmTC_a282e.exe: CMakeFiles/cmTC_a282e.dir/feature_tests.cxx.obj
cmTC_a282e.exe: CMakeFiles/cmTC_a282e.dir/build.make
cmTC_a282e.exe: CMakeFiles/cmTC_a282e.dir/linklibs.rsp
cmTC_a282e.exe: CMakeFiles/cmTC_a282e.dir/objects1.rsp
cmTC_a282e.exe: CMakeFiles/cmTC_a282e.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --progress-dir="C:\Users\allen\Documents\GitHub\Code\Code\Problem 7\cmake-build-debug\CMakeFiles\CMakeTmp\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable cmTC_a282e.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\cmTC_a282e.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cmTC_a282e.dir/build: cmTC_a282e.exe

.PHONY : CMakeFiles/cmTC_a282e.dir/build

CMakeFiles/cmTC_a282e.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\cmTC_a282e.dir\cmake_clean.cmake
.PHONY : CMakeFiles/cmTC_a282e.dir/clean

CMakeFiles/cmTC_a282e.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\allen\Documents\GitHub\Code\Code\Problem 7\cmake-build-debug\CMakeFiles\CMakeTmp" "C:\Users\allen\Documents\GitHub\Code\Code\Problem 7\cmake-build-debug\CMakeFiles\CMakeTmp" "C:\Users\allen\Documents\GitHub\Code\Code\Problem 7\cmake-build-debug\CMakeFiles\CMakeTmp" "C:\Users\allen\Documents\GitHub\Code\Code\Problem 7\cmake-build-debug\CMakeFiles\CMakeTmp" "C:\Users\allen\Documents\GitHub\Code\Code\Problem 7\cmake-build-debug\CMakeFiles\CMakeTmp\CMakeFiles\cmTC_a282e.dir\DependInfo.cmake"
.PHONY : CMakeFiles/cmTC_a282e.dir/depend
