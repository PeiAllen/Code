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
CMAKE_SOURCE_DIR = "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Codeforces\B. Longest Common Substring"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Codeforces\B. Longest Common Substring\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/B__Longest_Common_Substring.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/B__Longest_Common_Substring.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/B__Longest_Common_Substring.dir/flags.make

CMakeFiles/B__Longest_Common_Substring.dir/main.cpp.obj: CMakeFiles/B__Longest_Common_Substring.dir/flags.make
CMakeFiles/B__Longest_Common_Substring.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Codeforces\B. Longest Common Substring\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/B__Longest_Common_Substring.dir/main.cpp.obj"
	C:\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\B__Longest_Common_Substring.dir\main.cpp.obj -c "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Codeforces\B. Longest Common Substring\main.cpp"

CMakeFiles/B__Longest_Common_Substring.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/B__Longest_Common_Substring.dir/main.cpp.i"
	C:\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Codeforces\B. Longest Common Substring\main.cpp" > CMakeFiles\B__Longest_Common_Substring.dir\main.cpp.i

CMakeFiles/B__Longest_Common_Substring.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/B__Longest_Common_Substring.dir/main.cpp.s"
	C:\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Codeforces\B. Longest Common Substring\main.cpp" -o CMakeFiles\B__Longest_Common_Substring.dir\main.cpp.s

# Object files for target B__Longest_Common_Substring
B__Longest_Common_Substring_OBJECTS = \
"CMakeFiles/B__Longest_Common_Substring.dir/main.cpp.obj"

# External object files for target B__Longest_Common_Substring
B__Longest_Common_Substring_EXTERNAL_OBJECTS =

B__Longest_Common_Substring.exe: CMakeFiles/B__Longest_Common_Substring.dir/main.cpp.obj
B__Longest_Common_Substring.exe: CMakeFiles/B__Longest_Common_Substring.dir/build.make
B__Longest_Common_Substring.exe: CMakeFiles/B__Longest_Common_Substring.dir/linklibs.rsp
B__Longest_Common_Substring.exe: CMakeFiles/B__Longest_Common_Substring.dir/objects1.rsp
B__Longest_Common_Substring.exe: CMakeFiles/B__Longest_Common_Substring.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Codeforces\B. Longest Common Substring\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable B__Longest_Common_Substring.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\B__Longest_Common_Substring.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/B__Longest_Common_Substring.dir/build: B__Longest_Common_Substring.exe

.PHONY : CMakeFiles/B__Longest_Common_Substring.dir/build

CMakeFiles/B__Longest_Common_Substring.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\B__Longest_Common_Substring.dir\cmake_clean.cmake
.PHONY : CMakeFiles/B__Longest_Common_Substring.dir/clean

CMakeFiles/B__Longest_Common_Substring.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Codeforces\B. Longest Common Substring" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Codeforces\B. Longest Common Substring" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Codeforces\B. Longest Common Substring\cmake-build-debug" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Codeforces\B. Longest Common Substring\cmake-build-debug" "C:\Users\allen\OneDrive\Documents\GitHub\Code\Problems\Codeforces\B. Longest Common Substring\cmake-build-debug\CMakeFiles\B__Longest_Common_Substring.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/B__Longest_Common_Substring.dir/depend
