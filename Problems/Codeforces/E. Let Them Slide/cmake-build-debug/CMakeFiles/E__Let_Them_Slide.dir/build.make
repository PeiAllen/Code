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
CMAKE_SOURCE_DIR = "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Codeforces\E. Let Them Slide"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Codeforces\E. Let Them Slide\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/E__Let_Them_Slide.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/E__Let_Them_Slide.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/E__Let_Them_Slide.dir/flags.make

CMakeFiles/E__Let_Them_Slide.dir/main.cpp.obj: CMakeFiles/E__Let_Them_Slide.dir/flags.make
CMakeFiles/E__Let_Them_Slide.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Codeforces\E. Let Them Slide\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/E__Let_Them_Slide.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\E__Let_Them_Slide.dir\main.cpp.obj -c "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Codeforces\E. Let Them Slide\main.cpp"

CMakeFiles/E__Let_Them_Slide.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/E__Let_Them_Slide.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Codeforces\E. Let Them Slide\main.cpp" > CMakeFiles\E__Let_Them_Slide.dir\main.cpp.i

CMakeFiles/E__Let_Them_Slide.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/E__Let_Them_Slide.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Codeforces\E. Let Them Slide\main.cpp" -o CMakeFiles\E__Let_Them_Slide.dir\main.cpp.s

# Object files for target E__Let_Them_Slide
E__Let_Them_Slide_OBJECTS = \
"CMakeFiles/E__Let_Them_Slide.dir/main.cpp.obj"

# External object files for target E__Let_Them_Slide
E__Let_Them_Slide_EXTERNAL_OBJECTS =

E__Let_Them_Slide.exe: CMakeFiles/E__Let_Them_Slide.dir/main.cpp.obj
E__Let_Them_Slide.exe: CMakeFiles/E__Let_Them_Slide.dir/build.make
E__Let_Them_Slide.exe: CMakeFiles/E__Let_Them_Slide.dir/linklibs.rsp
E__Let_Them_Slide.exe: CMakeFiles/E__Let_Them_Slide.dir/objects1.rsp
E__Let_Them_Slide.exe: CMakeFiles/E__Let_Them_Slide.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Codeforces\E. Let Them Slide\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable E__Let_Them_Slide.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\E__Let_Them_Slide.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/E__Let_Them_Slide.dir/build: E__Let_Them_Slide.exe

.PHONY : CMakeFiles/E__Let_Them_Slide.dir/build

CMakeFiles/E__Let_Them_Slide.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\E__Let_Them_Slide.dir\cmake_clean.cmake
.PHONY : CMakeFiles/E__Let_Them_Slide.dir/clean

CMakeFiles/E__Let_Them_Slide.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Codeforces\E. Let Them Slide" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Codeforces\E. Let Them Slide" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Codeforces\E. Let Them Slide\cmake-build-debug" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Codeforces\E. Let Them Slide\cmake-build-debug" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Codeforces\E. Let Them Slide\cmake-build-debug\CMakeFiles\E__Let_Them_Slide.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/E__Let_Them_Slide.dir/depend

