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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\allen\Documents\Github\Code\Problems\BOI\Baltic OI '05 P2 - LISP"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\allen\Documents\Github\Code\Problems\BOI\Baltic OI '05 P2 - LISP\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Baltic_OI__05_P2___LISP.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Baltic_OI__05_P2___LISP.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Baltic_OI__05_P2___LISP.dir/flags.make

CMakeFiles/Baltic_OI__05_P2___LISP.dir/main.cpp.obj: CMakeFiles/Baltic_OI__05_P2___LISP.dir/flags.make
CMakeFiles/Baltic_OI__05_P2___LISP.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\allen\Documents\Github\Code\Problems\BOI\Baltic OI '05 P2 - LISP\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Baltic_OI__05_P2___LISP.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Baltic_OI__05_P2___LISP.dir\main.cpp.obj -c "C:\Users\allen\Documents\Github\Code\Problems\BOI\Baltic OI '05 P2 - LISP\main.cpp"

CMakeFiles/Baltic_OI__05_P2___LISP.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Baltic_OI__05_P2___LISP.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\allen\Documents\Github\Code\Problems\BOI\Baltic OI '05 P2 - LISP\main.cpp" > CMakeFiles\Baltic_OI__05_P2___LISP.dir\main.cpp.i

CMakeFiles/Baltic_OI__05_P2___LISP.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Baltic_OI__05_P2___LISP.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\allen\Documents\Github\Code\Problems\BOI\Baltic OI '05 P2 - LISP\main.cpp" -o CMakeFiles\Baltic_OI__05_P2___LISP.dir\main.cpp.s

# Object files for target Baltic_OI__05_P2___LISP
Baltic_OI__05_P2___LISP_OBJECTS = \
"CMakeFiles/Baltic_OI__05_P2___LISP.dir/main.cpp.obj"

# External object files for target Baltic_OI__05_P2___LISP
Baltic_OI__05_P2___LISP_EXTERNAL_OBJECTS =

Baltic_OI__05_P2___LISP.exe: CMakeFiles/Baltic_OI__05_P2___LISP.dir/main.cpp.obj
Baltic_OI__05_P2___LISP.exe: CMakeFiles/Baltic_OI__05_P2___LISP.dir/build.make
Baltic_OI__05_P2___LISP.exe: CMakeFiles/Baltic_OI__05_P2___LISP.dir/linklibs.rsp
Baltic_OI__05_P2___LISP.exe: CMakeFiles/Baltic_OI__05_P2___LISP.dir/objects1.rsp
Baltic_OI__05_P2___LISP.exe: CMakeFiles/Baltic_OI__05_P2___LISP.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\allen\Documents\Github\Code\Problems\BOI\Baltic OI '05 P2 - LISP\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Baltic_OI__05_P2___LISP.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Baltic_OI__05_P2___LISP.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Baltic_OI__05_P2___LISP.dir/build: Baltic_OI__05_P2___LISP.exe

.PHONY : CMakeFiles/Baltic_OI__05_P2___LISP.dir/build

CMakeFiles/Baltic_OI__05_P2___LISP.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Baltic_OI__05_P2___LISP.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Baltic_OI__05_P2___LISP.dir/clean

CMakeFiles/Baltic_OI__05_P2___LISP.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\allen\Documents\Github\Code\Problems\BOI\Baltic OI '05 P2 - LISP" "C:\Users\allen\Documents\Github\Code\Problems\BOI\Baltic OI '05 P2 - LISP" "C:\Users\allen\Documents\Github\Code\Problems\BOI\Baltic OI '05 P2 - LISP\cmake-build-debug" "C:\Users\allen\Documents\Github\Code\Problems\BOI\Baltic OI '05 P2 - LISP\cmake-build-debug" "C:\Users\allen\Documents\Github\Code\Problems\BOI\Baltic OI '05 P2 - LISP\cmake-build-debug\CMakeFiles\Baltic_OI__05_P2___LISP.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Baltic_OI__05_P2___LISP.dir/depend

