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
CMAKE_SOURCE_DIR = C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Lockout\Contest1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Lockout\Contest1\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Contest1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Contest1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Contest1.dir/flags.make

CMakeFiles/Contest1.dir/main.cpp.obj: CMakeFiles/Contest1.dir/flags.make
CMakeFiles/Contest1.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Lockout\Contest1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Contest1.dir/main.cpp.obj"
	C:\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Contest1.dir\main.cpp.obj -c C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Lockout\Contest1\main.cpp

CMakeFiles/Contest1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Contest1.dir/main.cpp.i"
	C:\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Lockout\Contest1\main.cpp > CMakeFiles\Contest1.dir\main.cpp.i

CMakeFiles/Contest1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Contest1.dir/main.cpp.s"
	C:\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Lockout\Contest1\main.cpp -o CMakeFiles\Contest1.dir\main.cpp.s

# Object files for target Contest1
Contest1_OBJECTS = \
"CMakeFiles/Contest1.dir/main.cpp.obj"

# External object files for target Contest1
Contest1_EXTERNAL_OBJECTS =

Contest1.exe: CMakeFiles/Contest1.dir/main.cpp.obj
Contest1.exe: CMakeFiles/Contest1.dir/build.make
Contest1.exe: CMakeFiles/Contest1.dir/linklibs.rsp
Contest1.exe: CMakeFiles/Contest1.dir/objects1.rsp
Contest1.exe: CMakeFiles/Contest1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Lockout\Contest1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Contest1.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Contest1.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Contest1.dir/build: Contest1.exe

.PHONY : CMakeFiles/Contest1.dir/build

CMakeFiles/Contest1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Contest1.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Contest1.dir/clean

CMakeFiles/Contest1.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Lockout\Contest1 C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Lockout\Contest1 C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Lockout\Contest1\cmake-build-debug C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Lockout\Contest1\cmake-build-debug C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Lockout\Contest1\cmake-build-debug\CMakeFiles\Contest1.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Contest1.dir/depend
