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
CMAKE_SOURCE_DIR = C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Codeforces\Edu84Div2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Codeforces\Edu84Div2\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Edu84Div2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Edu84Div2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Edu84Div2.dir/flags.make

CMakeFiles/Edu84Div2.dir/main.cpp.obj: CMakeFiles/Edu84Div2.dir/flags.make
CMakeFiles/Edu84Div2.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Codeforces\Edu84Div2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Edu84Div2.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Edu84Div2.dir\main.cpp.obj -c C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Codeforces\Edu84Div2\main.cpp

CMakeFiles/Edu84Div2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Edu84Div2.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Codeforces\Edu84Div2\main.cpp > CMakeFiles\Edu84Div2.dir\main.cpp.i

CMakeFiles/Edu84Div2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Edu84Div2.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Codeforces\Edu84Div2\main.cpp -o CMakeFiles\Edu84Div2.dir\main.cpp.s

# Object files for target Edu84Div2
Edu84Div2_OBJECTS = \
"CMakeFiles/Edu84Div2.dir/main.cpp.obj"

# External object files for target Edu84Div2
Edu84Div2_EXTERNAL_OBJECTS =

Edu84Div2.exe: CMakeFiles/Edu84Div2.dir/main.cpp.obj
Edu84Div2.exe: CMakeFiles/Edu84Div2.dir/build.make
Edu84Div2.exe: CMakeFiles/Edu84Div2.dir/linklibs.rsp
Edu84Div2.exe: CMakeFiles/Edu84Div2.dir/objects1.rsp
Edu84Div2.exe: CMakeFiles/Edu84Div2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Codeforces\Edu84Div2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Edu84Div2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Edu84Div2.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Edu84Div2.dir/build: Edu84Div2.exe

.PHONY : CMakeFiles/Edu84Div2.dir/build

CMakeFiles/Edu84Div2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Edu84Div2.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Edu84Div2.dir/clean

CMakeFiles/Edu84Div2.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Codeforces\Edu84Div2 C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Codeforces\Edu84Div2 C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Codeforces\Edu84Div2\cmake-build-debug C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Codeforces\Edu84Div2\cmake-build-debug C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Codeforces\Edu84Div2\cmake-build-debug\CMakeFiles\Edu84Div2.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Edu84Div2.dir/depend
