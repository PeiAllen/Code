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
CMAKE_SOURCE_DIR = "C:\Users\allen\Documents\Github\Code\Problems\Other\Summer Institute '17 Contest 3 P4 - Customs"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\allen\Documents\Github\Code\Problems\Other\Summer Institute '17 Contest 3 P4 - Customs\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Summer_Institute__17_Contest_3_P4___Customs.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Summer_Institute__17_Contest_3_P4___Customs.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Summer_Institute__17_Contest_3_P4___Customs.dir/flags.make

CMakeFiles/Summer_Institute__17_Contest_3_P4___Customs.dir/main.cpp.obj: CMakeFiles/Summer_Institute__17_Contest_3_P4___Customs.dir/flags.make
CMakeFiles/Summer_Institute__17_Contest_3_P4___Customs.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\allen\Documents\Github\Code\Problems\Other\Summer Institute '17 Contest 3 P4 - Customs\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Summer_Institute__17_Contest_3_P4___Customs.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Summer_Institute__17_Contest_3_P4___Customs.dir\main.cpp.obj -c "C:\Users\allen\Documents\Github\Code\Problems\Other\Summer Institute '17 Contest 3 P4 - Customs\main.cpp"

CMakeFiles/Summer_Institute__17_Contest_3_P4___Customs.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Summer_Institute__17_Contest_3_P4___Customs.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\allen\Documents\Github\Code\Problems\Other\Summer Institute '17 Contest 3 P4 - Customs\main.cpp" > CMakeFiles\Summer_Institute__17_Contest_3_P4___Customs.dir\main.cpp.i

CMakeFiles/Summer_Institute__17_Contest_3_P4___Customs.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Summer_Institute__17_Contest_3_P4___Customs.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\allen\Documents\Github\Code\Problems\Other\Summer Institute '17 Contest 3 P4 - Customs\main.cpp" -o CMakeFiles\Summer_Institute__17_Contest_3_P4___Customs.dir\main.cpp.s

# Object files for target Summer_Institute__17_Contest_3_P4___Customs
Summer_Institute__17_Contest_3_P4___Customs_OBJECTS = \
"CMakeFiles/Summer_Institute__17_Contest_3_P4___Customs.dir/main.cpp.obj"

# External object files for target Summer_Institute__17_Contest_3_P4___Customs
Summer_Institute__17_Contest_3_P4___Customs_EXTERNAL_OBJECTS =

Summer_Institute__17_Contest_3_P4___Customs.exe: CMakeFiles/Summer_Institute__17_Contest_3_P4___Customs.dir/main.cpp.obj
Summer_Institute__17_Contest_3_P4___Customs.exe: CMakeFiles/Summer_Institute__17_Contest_3_P4___Customs.dir/build.make
Summer_Institute__17_Contest_3_P4___Customs.exe: CMakeFiles/Summer_Institute__17_Contest_3_P4___Customs.dir/linklibs.rsp
Summer_Institute__17_Contest_3_P4___Customs.exe: CMakeFiles/Summer_Institute__17_Contest_3_P4___Customs.dir/objects1.rsp
Summer_Institute__17_Contest_3_P4___Customs.exe: CMakeFiles/Summer_Institute__17_Contest_3_P4___Customs.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\allen\Documents\Github\Code\Problems\Other\Summer Institute '17 Contest 3 P4 - Customs\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Summer_Institute__17_Contest_3_P4___Customs.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Summer_Institute__17_Contest_3_P4___Customs.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Summer_Institute__17_Contest_3_P4___Customs.dir/build: Summer_Institute__17_Contest_3_P4___Customs.exe

.PHONY : CMakeFiles/Summer_Institute__17_Contest_3_P4___Customs.dir/build

CMakeFiles/Summer_Institute__17_Contest_3_P4___Customs.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Summer_Institute__17_Contest_3_P4___Customs.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Summer_Institute__17_Contest_3_P4___Customs.dir/clean

CMakeFiles/Summer_Institute__17_Contest_3_P4___Customs.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\allen\Documents\Github\Code\Problems\Other\Summer Institute '17 Contest 3 P4 - Customs" "C:\Users\allen\Documents\Github\Code\Problems\Other\Summer Institute '17 Contest 3 P4 - Customs" "C:\Users\allen\Documents\Github\Code\Problems\Other\Summer Institute '17 Contest 3 P4 - Customs\cmake-build-debug" "C:\Users\allen\Documents\Github\Code\Problems\Other\Summer Institute '17 Contest 3 P4 - Customs\cmake-build-debug" "C:\Users\allen\Documents\Github\Code\Problems\Other\Summer Institute '17 Contest 3 P4 - Customs\cmake-build-debug\CMakeFiles\Summer_Institute__17_Contest_3_P4___Customs.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Summer_Institute__17_Contest_3_P4___Customs.dir/depend

