# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.2.5\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.2.5\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\allen\Documents\Github\Code\Problems\DMOPC\Petty Children"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\allen\Documents\Github\Code\Problems\DMOPC\Petty Children\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Petty_Children.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Petty_Children.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Petty_Children.dir/flags.make

CMakeFiles/Petty_Children.dir/main.cpp.obj: CMakeFiles/Petty_Children.dir/flags.make
CMakeFiles/Petty_Children.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\allen\Documents\Github\Code\Problems\DMOPC\Petty Children\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Petty_Children.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Petty_Children.dir\main.cpp.obj -c "C:\Users\allen\Documents\Github\Code\Problems\DMOPC\Petty Children\main.cpp"

CMakeFiles/Petty_Children.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Petty_Children.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\allen\Documents\Github\Code\Problems\DMOPC\Petty Children\main.cpp" > CMakeFiles\Petty_Children.dir\main.cpp.i

CMakeFiles/Petty_Children.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Petty_Children.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\allen\Documents\Github\Code\Problems\DMOPC\Petty Children\main.cpp" -o CMakeFiles\Petty_Children.dir\main.cpp.s

# Object files for target Petty_Children
Petty_Children_OBJECTS = \
"CMakeFiles/Petty_Children.dir/main.cpp.obj"

# External object files for target Petty_Children
Petty_Children_EXTERNAL_OBJECTS =

Petty_Children.exe: CMakeFiles/Petty_Children.dir/main.cpp.obj
Petty_Children.exe: CMakeFiles/Petty_Children.dir/build.make
Petty_Children.exe: CMakeFiles/Petty_Children.dir/linklibs.rsp
Petty_Children.exe: CMakeFiles/Petty_Children.dir/objects1.rsp
Petty_Children.exe: CMakeFiles/Petty_Children.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\allen\Documents\Github\Code\Problems\DMOPC\Petty Children\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Petty_Children.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Petty_Children.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Petty_Children.dir/build: Petty_Children.exe

.PHONY : CMakeFiles/Petty_Children.dir/build

CMakeFiles/Petty_Children.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Petty_Children.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Petty_Children.dir/clean

CMakeFiles/Petty_Children.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\allen\Documents\Github\Code\Problems\DMOPC\Petty Children" "C:\Users\allen\Documents\Github\Code\Problems\DMOPC\Petty Children" "C:\Users\allen\Documents\Github\Code\Problems\DMOPC\Petty Children\cmake-build-debug" "C:\Users\allen\Documents\Github\Code\Problems\DMOPC\Petty Children\cmake-build-debug" "C:\Users\allen\Documents\Github\Code\Problems\DMOPC\Petty Children\cmake-build-debug\CMakeFiles\Petty_Children.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Petty_Children.dir/depend

