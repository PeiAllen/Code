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
CMAKE_SOURCE_DIR = "C:\Users\allen\Documents\Github\Code\Problems\COCI\COCI '10 Contest 4 #5 Dugovi"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\allen\Documents\Github\Code\Problems\COCI\COCI '10 Contest 4 #5 Dugovi\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/COCI__10_Contest_4__5_Dugovi.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/COCI__10_Contest_4__5_Dugovi.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/COCI__10_Contest_4__5_Dugovi.dir/flags.make

CMakeFiles/COCI__10_Contest_4__5_Dugovi.dir/main.cpp.obj: CMakeFiles/COCI__10_Contest_4__5_Dugovi.dir/flags.make
CMakeFiles/COCI__10_Contest_4__5_Dugovi.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\allen\Documents\Github\Code\Problems\COCI\COCI '10 Contest 4 #5 Dugovi\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/COCI__10_Contest_4__5_Dugovi.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\COCI__10_Contest_4__5_Dugovi.dir\main.cpp.obj -c "C:\Users\allen\Documents\Github\Code\Problems\COCI\COCI '10 Contest 4 #5 Dugovi\main.cpp"

CMakeFiles/COCI__10_Contest_4__5_Dugovi.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/COCI__10_Contest_4__5_Dugovi.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\allen\Documents\Github\Code\Problems\COCI\COCI '10 Contest 4 #5 Dugovi\main.cpp" > CMakeFiles\COCI__10_Contest_4__5_Dugovi.dir\main.cpp.i

CMakeFiles/COCI__10_Contest_4__5_Dugovi.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/COCI__10_Contest_4__5_Dugovi.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\allen\Documents\Github\Code\Problems\COCI\COCI '10 Contest 4 #5 Dugovi\main.cpp" -o CMakeFiles\COCI__10_Contest_4__5_Dugovi.dir\main.cpp.s

# Object files for target COCI__10_Contest_4__5_Dugovi
COCI__10_Contest_4__5_Dugovi_OBJECTS = \
"CMakeFiles/COCI__10_Contest_4__5_Dugovi.dir/main.cpp.obj"

# External object files for target COCI__10_Contest_4__5_Dugovi
COCI__10_Contest_4__5_Dugovi_EXTERNAL_OBJECTS =

COCI__10_Contest_4__5_Dugovi.exe: CMakeFiles/COCI__10_Contest_4__5_Dugovi.dir/main.cpp.obj
COCI__10_Contest_4__5_Dugovi.exe: CMakeFiles/COCI__10_Contest_4__5_Dugovi.dir/build.make
COCI__10_Contest_4__5_Dugovi.exe: CMakeFiles/COCI__10_Contest_4__5_Dugovi.dir/linklibs.rsp
COCI__10_Contest_4__5_Dugovi.exe: CMakeFiles/COCI__10_Contest_4__5_Dugovi.dir/objects1.rsp
COCI__10_Contest_4__5_Dugovi.exe: CMakeFiles/COCI__10_Contest_4__5_Dugovi.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\allen\Documents\Github\Code\Problems\COCI\COCI '10 Contest 4 #5 Dugovi\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable COCI__10_Contest_4__5_Dugovi.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\COCI__10_Contest_4__5_Dugovi.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/COCI__10_Contest_4__5_Dugovi.dir/build: COCI__10_Contest_4__5_Dugovi.exe

.PHONY : CMakeFiles/COCI__10_Contest_4__5_Dugovi.dir/build

CMakeFiles/COCI__10_Contest_4__5_Dugovi.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\COCI__10_Contest_4__5_Dugovi.dir\cmake_clean.cmake
.PHONY : CMakeFiles/COCI__10_Contest_4__5_Dugovi.dir/clean

CMakeFiles/COCI__10_Contest_4__5_Dugovi.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\allen\Documents\Github\Code\Problems\COCI\COCI '10 Contest 4 #5 Dugovi" "C:\Users\allen\Documents\Github\Code\Problems\COCI\COCI '10 Contest 4 #5 Dugovi" "C:\Users\allen\Documents\Github\Code\Problems\COCI\COCI '10 Contest 4 #5 Dugovi\cmake-build-debug" "C:\Users\allen\Documents\Github\Code\Problems\COCI\COCI '10 Contest 4 #5 Dugovi\cmake-build-debug" "C:\Users\allen\Documents\Github\Code\Problems\COCI\COCI '10 Contest 4 #5 Dugovi\cmake-build-debug\CMakeFiles\COCI__10_Contest_4__5_Dugovi.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/COCI__10_Contest_4__5_Dugovi.dir/depend

