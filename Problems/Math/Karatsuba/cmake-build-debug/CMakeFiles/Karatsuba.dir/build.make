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
CMAKE_SOURCE_DIR = C:\Users\allen\Documents\Code\Problems\Math\Karatsuba

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\allen\Documents\Code\Problems\Math\Karatsuba\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Karatsuba.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Karatsuba.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Karatsuba.dir/flags.make

CMakeFiles/Karatsuba.dir/main.cpp.obj: CMakeFiles/Karatsuba.dir/flags.make
CMakeFiles/Karatsuba.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\allen\Documents\Code\Problems\Math\Karatsuba\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Karatsuba.dir/main.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Karatsuba.dir\main.cpp.obj -c C:\Users\allen\Documents\Code\Problems\Math\Karatsuba\main.cpp

CMakeFiles/Karatsuba.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Karatsuba.dir/main.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\allen\Documents\Code\Problems\Math\Karatsuba\main.cpp > CMakeFiles\Karatsuba.dir\main.cpp.i

CMakeFiles/Karatsuba.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Karatsuba.dir/main.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\allen\Documents\Code\Problems\Math\Karatsuba\main.cpp -o CMakeFiles\Karatsuba.dir\main.cpp.s

# Object files for target Karatsuba
Karatsuba_OBJECTS = \
"CMakeFiles/Karatsuba.dir/main.cpp.obj"

# External object files for target Karatsuba
Karatsuba_EXTERNAL_OBJECTS =

Karatsuba.exe: CMakeFiles/Karatsuba.dir/main.cpp.obj
Karatsuba.exe: CMakeFiles/Karatsuba.dir/build.make
Karatsuba.exe: CMakeFiles/Karatsuba.dir/linklibs.rsp
Karatsuba.exe: CMakeFiles/Karatsuba.dir/objects1.rsp
Karatsuba.exe: CMakeFiles/Karatsuba.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\allen\Documents\Code\Problems\Math\Karatsuba\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Karatsuba.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Karatsuba.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Karatsuba.dir/build: Karatsuba.exe

.PHONY : CMakeFiles/Karatsuba.dir/build

CMakeFiles/Karatsuba.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Karatsuba.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Karatsuba.dir/clean

CMakeFiles/Karatsuba.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\allen\Documents\Code\Problems\Math\Karatsuba C:\Users\allen\Documents\Code\Problems\Math\Karatsuba C:\Users\allen\Documents\Code\Problems\Math\Karatsuba\cmake-build-debug C:\Users\allen\Documents\Code\Problems\Math\Karatsuba\cmake-build-debug C:\Users\allen\Documents\Code\Problems\Math\Karatsuba\cmake-build-debug\CMakeFiles\Karatsuba.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Karatsuba.dir/depend
