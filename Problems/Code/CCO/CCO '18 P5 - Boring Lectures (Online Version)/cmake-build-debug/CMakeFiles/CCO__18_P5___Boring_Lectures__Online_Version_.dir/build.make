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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.1.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.1.3\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\allen\CLionProjects\CCO '18 P5 - Boring Lectures (Online Version)"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\allen\CLionProjects\CCO '18 P5 - Boring Lectures (Online Version)\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/CCO__18_P5___Boring_Lectures__Online_Version_.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CCO__18_P5___Boring_Lectures__Online_Version_.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CCO__18_P5___Boring_Lectures__Online_Version_.dir/flags.make

CMakeFiles/CCO__18_P5___Boring_Lectures__Online_Version_.dir/main.cpp.obj: CMakeFiles/CCO__18_P5___Boring_Lectures__Online_Version_.dir/flags.make
CMakeFiles/CCO__18_P5___Boring_Lectures__Online_Version_.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\allen\CLionProjects\CCO '18 P5 - Boring Lectures (Online Version)\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CCO__18_P5___Boring_Lectures__Online_Version_.dir/main.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\CCO__18_P5___Boring_Lectures__Online_Version_.dir\main.cpp.obj -c "C:\Users\allen\CLionProjects\CCO '18 P5 - Boring Lectures (Online Version)\main.cpp"

CMakeFiles/CCO__18_P5___Boring_Lectures__Online_Version_.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CCO__18_P5___Boring_Lectures__Online_Version_.dir/main.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\allen\CLionProjects\CCO '18 P5 - Boring Lectures (Online Version)\main.cpp" > CMakeFiles\CCO__18_P5___Boring_Lectures__Online_Version_.dir\main.cpp.i

CMakeFiles/CCO__18_P5___Boring_Lectures__Online_Version_.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CCO__18_P5___Boring_Lectures__Online_Version_.dir/main.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\allen\CLionProjects\CCO '18 P5 - Boring Lectures (Online Version)\main.cpp" -o CMakeFiles\CCO__18_P5___Boring_Lectures__Online_Version_.dir\main.cpp.s

# Object files for target CCO__18_P5___Boring_Lectures__Online_Version_
CCO__18_P5___Boring_Lectures__Online_Version__OBJECTS = \
"CMakeFiles/CCO__18_P5___Boring_Lectures__Online_Version_.dir/main.cpp.obj"

# External object files for target CCO__18_P5___Boring_Lectures__Online_Version_
CCO__18_P5___Boring_Lectures__Online_Version__EXTERNAL_OBJECTS =

CCO__18_P5___Boring_Lectures__Online_Version_.exe: CMakeFiles/CCO__18_P5___Boring_Lectures__Online_Version_.dir/main.cpp.obj
CCO__18_P5___Boring_Lectures__Online_Version_.exe: CMakeFiles/CCO__18_P5___Boring_Lectures__Online_Version_.dir/build.make
CCO__18_P5___Boring_Lectures__Online_Version_.exe: CMakeFiles/CCO__18_P5___Boring_Lectures__Online_Version_.dir/linklibs.rsp
CCO__18_P5___Boring_Lectures__Online_Version_.exe: CMakeFiles/CCO__18_P5___Boring_Lectures__Online_Version_.dir/objects1.rsp
CCO__18_P5___Boring_Lectures__Online_Version_.exe: CMakeFiles/CCO__18_P5___Boring_Lectures__Online_Version_.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\allen\CLionProjects\CCO '18 P5 - Boring Lectures (Online Version)\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable CCO__18_P5___Boring_Lectures__Online_Version_.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\CCO__18_P5___Boring_Lectures__Online_Version_.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CCO__18_P5___Boring_Lectures__Online_Version_.dir/build: CCO__18_P5___Boring_Lectures__Online_Version_.exe

.PHONY : CMakeFiles/CCO__18_P5___Boring_Lectures__Online_Version_.dir/build

CMakeFiles/CCO__18_P5___Boring_Lectures__Online_Version_.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\CCO__18_P5___Boring_Lectures__Online_Version_.dir\cmake_clean.cmake
.PHONY : CMakeFiles/CCO__18_P5___Boring_Lectures__Online_Version_.dir/clean

CMakeFiles/CCO__18_P5___Boring_Lectures__Online_Version_.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\allen\CLionProjects\CCO '18 P5 - Boring Lectures (Online Version)" "C:\Users\allen\CLionProjects\CCO '18 P5 - Boring Lectures (Online Version)" "C:\Users\allen\CLionProjects\CCO '18 P5 - Boring Lectures (Online Version)\cmake-build-debug" "C:\Users\allen\CLionProjects\CCO '18 P5 - Boring Lectures (Online Version)\cmake-build-debug" "C:\Users\allen\CLionProjects\CCO '18 P5 - Boring Lectures (Online Version)\cmake-build-debug\CMakeFiles\CCO__18_P5___Boring_Lectures__Online_Version_.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/CCO__18_P5___Boring_Lectures__Online_Version_.dir/depend
