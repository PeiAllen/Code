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
CMAKE_SOURCE_DIR = "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\BOI\Baltic OI '18 P6 - Paths"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\BOI\Baltic OI '18 P6 - Paths\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Baltic_OI__18_P6___Paths.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Baltic_OI__18_P6___Paths.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Baltic_OI__18_P6___Paths.dir/flags.make

CMakeFiles/Baltic_OI__18_P6___Paths.dir/main.cpp.obj: CMakeFiles/Baltic_OI__18_P6___Paths.dir/flags.make
CMakeFiles/Baltic_OI__18_P6___Paths.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\BOI\Baltic OI '18 P6 - Paths\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Baltic_OI__18_P6___Paths.dir/main.cpp.obj"
	C:\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Baltic_OI__18_P6___Paths.dir\main.cpp.obj -c "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\BOI\Baltic OI '18 P6 - Paths\main.cpp"

CMakeFiles/Baltic_OI__18_P6___Paths.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Baltic_OI__18_P6___Paths.dir/main.cpp.i"
	C:\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\BOI\Baltic OI '18 P6 - Paths\main.cpp" > CMakeFiles\Baltic_OI__18_P6___Paths.dir\main.cpp.i

CMakeFiles/Baltic_OI__18_P6___Paths.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Baltic_OI__18_P6___Paths.dir/main.cpp.s"
	C:\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\BOI\Baltic OI '18 P6 - Paths\main.cpp" -o CMakeFiles\Baltic_OI__18_P6___Paths.dir\main.cpp.s

# Object files for target Baltic_OI__18_P6___Paths
Baltic_OI__18_P6___Paths_OBJECTS = \
"CMakeFiles/Baltic_OI__18_P6___Paths.dir/main.cpp.obj"

# External object files for target Baltic_OI__18_P6___Paths
Baltic_OI__18_P6___Paths_EXTERNAL_OBJECTS =

Baltic_OI__18_P6___Paths.exe: CMakeFiles/Baltic_OI__18_P6___Paths.dir/main.cpp.obj
Baltic_OI__18_P6___Paths.exe: CMakeFiles/Baltic_OI__18_P6___Paths.dir/build.make
Baltic_OI__18_P6___Paths.exe: CMakeFiles/Baltic_OI__18_P6___Paths.dir/linklibs.rsp
Baltic_OI__18_P6___Paths.exe: CMakeFiles/Baltic_OI__18_P6___Paths.dir/objects1.rsp
Baltic_OI__18_P6___Paths.exe: CMakeFiles/Baltic_OI__18_P6___Paths.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\BOI\Baltic OI '18 P6 - Paths\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Baltic_OI__18_P6___Paths.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Baltic_OI__18_P6___Paths.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Baltic_OI__18_P6___Paths.dir/build: Baltic_OI__18_P6___Paths.exe

.PHONY : CMakeFiles/Baltic_OI__18_P6___Paths.dir/build

CMakeFiles/Baltic_OI__18_P6___Paths.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Baltic_OI__18_P6___Paths.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Baltic_OI__18_P6___Paths.dir/clean

CMakeFiles/Baltic_OI__18_P6___Paths.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\BOI\Baltic OI '18 P6 - Paths" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\BOI\Baltic OI '18 P6 - Paths" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\BOI\Baltic OI '18 P6 - Paths\cmake-build-debug" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\BOI\Baltic OI '18 P6 - Paths\cmake-build-debug" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\BOI\Baltic OI '18 P6 - Paths\cmake-build-debug\CMakeFiles\Baltic_OI__18_P6___Paths.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Baltic_OI__18_P6___Paths.dir/depend
