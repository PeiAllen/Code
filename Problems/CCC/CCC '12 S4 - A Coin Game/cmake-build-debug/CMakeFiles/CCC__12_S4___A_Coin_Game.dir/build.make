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
CMAKE_SOURCE_DIR = "C:\Users\allen\Documents\Code\Problems\CCC\CCC '12 S4 - A Coin Game"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\allen\Documents\Code\Problems\CCC\CCC '12 S4 - A Coin Game\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/CCC__12_S4___A_Coin_Game.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CCC__12_S4___A_Coin_Game.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CCC__12_S4___A_Coin_Game.dir/flags.make

CMakeFiles/CCC__12_S4___A_Coin_Game.dir/main.cpp.obj: CMakeFiles/CCC__12_S4___A_Coin_Game.dir/flags.make
CMakeFiles/CCC__12_S4___A_Coin_Game.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\allen\Documents\Code\Problems\CCC\CCC '12 S4 - A Coin Game\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CCC__12_S4___A_Coin_Game.dir/main.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\CCC__12_S4___A_Coin_Game.dir\main.cpp.obj -c "C:\Users\allen\Documents\Code\Problems\CCC\CCC '12 S4 - A Coin Game\main.cpp"

CMakeFiles/CCC__12_S4___A_Coin_Game.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CCC__12_S4___A_Coin_Game.dir/main.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\allen\Documents\Code\Problems\CCC\CCC '12 S4 - A Coin Game\main.cpp" > CMakeFiles\CCC__12_S4___A_Coin_Game.dir\main.cpp.i

CMakeFiles/CCC__12_S4___A_Coin_Game.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CCC__12_S4___A_Coin_Game.dir/main.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\allen\Documents\Code\Problems\CCC\CCC '12 S4 - A Coin Game\main.cpp" -o CMakeFiles\CCC__12_S4___A_Coin_Game.dir\main.cpp.s

# Object files for target CCC__12_S4___A_Coin_Game
CCC__12_S4___A_Coin_Game_OBJECTS = \
"CMakeFiles/CCC__12_S4___A_Coin_Game.dir/main.cpp.obj"

# External object files for target CCC__12_S4___A_Coin_Game
CCC__12_S4___A_Coin_Game_EXTERNAL_OBJECTS =

CCC__12_S4___A_Coin_Game.exe: CMakeFiles/CCC__12_S4___A_Coin_Game.dir/main.cpp.obj
CCC__12_S4___A_Coin_Game.exe: CMakeFiles/CCC__12_S4___A_Coin_Game.dir/build.make
CCC__12_S4___A_Coin_Game.exe: CMakeFiles/CCC__12_S4___A_Coin_Game.dir/linklibs.rsp
CCC__12_S4___A_Coin_Game.exe: CMakeFiles/CCC__12_S4___A_Coin_Game.dir/objects1.rsp
CCC__12_S4___A_Coin_Game.exe: CMakeFiles/CCC__12_S4___A_Coin_Game.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\allen\Documents\Code\Problems\CCC\CCC '12 S4 - A Coin Game\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable CCC__12_S4___A_Coin_Game.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\CCC__12_S4___A_Coin_Game.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CCC__12_S4___A_Coin_Game.dir/build: CCC__12_S4___A_Coin_Game.exe

.PHONY : CMakeFiles/CCC__12_S4___A_Coin_Game.dir/build

CMakeFiles/CCC__12_S4___A_Coin_Game.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\CCC__12_S4___A_Coin_Game.dir\cmake_clean.cmake
.PHONY : CMakeFiles/CCC__12_S4___A_Coin_Game.dir/clean

CMakeFiles/CCC__12_S4___A_Coin_Game.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\allen\Documents\Code\Problems\CCC\CCC '12 S4 - A Coin Game" "C:\Users\allen\Documents\Code\Problems\CCC\CCC '12 S4 - A Coin Game" "C:\Users\allen\Documents\Code\Problems\CCC\CCC '12 S4 - A Coin Game\cmake-build-debug" "C:\Users\allen\Documents\Code\Problems\CCC\CCC '12 S4 - A Coin Game\cmake-build-debug" "C:\Users\allen\Documents\Code\Problems\CCC\CCC '12 S4 - A Coin Game\cmake-build-debug\CMakeFiles\CCC__12_S4___A_Coin_Game.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/CCC__12_S4___A_Coin_Game.dir/depend
