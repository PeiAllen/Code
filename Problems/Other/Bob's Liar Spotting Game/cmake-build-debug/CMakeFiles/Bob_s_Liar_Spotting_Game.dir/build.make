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
CMAKE_SOURCE_DIR = "C:\Users\allen\Documents\Github\Code\Problems\Other\Bob's Liar Spotting Game"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\allen\Documents\Github\Code\Problems\Other\Bob's Liar Spotting Game\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Bob_s_Liar_Spotting_Game.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Bob_s_Liar_Spotting_Game.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Bob_s_Liar_Spotting_Game.dir/flags.make

CMakeFiles/Bob_s_Liar_Spotting_Game.dir/main.cpp.obj: CMakeFiles/Bob_s_Liar_Spotting_Game.dir/flags.make
CMakeFiles/Bob_s_Liar_Spotting_Game.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\allen\Documents\Github\Code\Problems\Other\Bob's Liar Spotting Game\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Bob_s_Liar_Spotting_Game.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Bob_s_Liar_Spotting_Game.dir\main.cpp.obj -c "C:\Users\allen\Documents\Github\Code\Problems\Other\Bob's Liar Spotting Game\main.cpp"

CMakeFiles/Bob_s_Liar_Spotting_Game.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Bob_s_Liar_Spotting_Game.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\allen\Documents\Github\Code\Problems\Other\Bob's Liar Spotting Game\main.cpp" > CMakeFiles\Bob_s_Liar_Spotting_Game.dir\main.cpp.i

CMakeFiles/Bob_s_Liar_Spotting_Game.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Bob_s_Liar_Spotting_Game.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\allen\Documents\Github\Code\Problems\Other\Bob's Liar Spotting Game\main.cpp" -o CMakeFiles\Bob_s_Liar_Spotting_Game.dir\main.cpp.s

# Object files for target Bob_s_Liar_Spotting_Game
Bob_s_Liar_Spotting_Game_OBJECTS = \
"CMakeFiles/Bob_s_Liar_Spotting_Game.dir/main.cpp.obj"

# External object files for target Bob_s_Liar_Spotting_Game
Bob_s_Liar_Spotting_Game_EXTERNAL_OBJECTS =

Bob_s_Liar_Spotting_Game.exe: CMakeFiles/Bob_s_Liar_Spotting_Game.dir/main.cpp.obj
Bob_s_Liar_Spotting_Game.exe: CMakeFiles/Bob_s_Liar_Spotting_Game.dir/build.make
Bob_s_Liar_Spotting_Game.exe: CMakeFiles/Bob_s_Liar_Spotting_Game.dir/linklibs.rsp
Bob_s_Liar_Spotting_Game.exe: CMakeFiles/Bob_s_Liar_Spotting_Game.dir/objects1.rsp
Bob_s_Liar_Spotting_Game.exe: CMakeFiles/Bob_s_Liar_Spotting_Game.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\allen\Documents\Github\Code\Problems\Other\Bob's Liar Spotting Game\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Bob_s_Liar_Spotting_Game.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Bob_s_Liar_Spotting_Game.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Bob_s_Liar_Spotting_Game.dir/build: Bob_s_Liar_Spotting_Game.exe

.PHONY : CMakeFiles/Bob_s_Liar_Spotting_Game.dir/build

CMakeFiles/Bob_s_Liar_Spotting_Game.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Bob_s_Liar_Spotting_Game.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Bob_s_Liar_Spotting_Game.dir/clean

CMakeFiles/Bob_s_Liar_Spotting_Game.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\allen\Documents\Github\Code\Problems\Other\Bob's Liar Spotting Game" "C:\Users\allen\Documents\Github\Code\Problems\Other\Bob's Liar Spotting Game" "C:\Users\allen\Documents\Github\Code\Problems\Other\Bob's Liar Spotting Game\cmake-build-debug" "C:\Users\allen\Documents\Github\Code\Problems\Other\Bob's Liar Spotting Game\cmake-build-debug" "C:\Users\allen\Documents\Github\Code\Problems\Other\Bob's Liar Spotting Game\cmake-build-debug\CMakeFiles\Bob_s_Liar_Spotting_Game.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Bob_s_Liar_Spotting_Game.dir/depend

