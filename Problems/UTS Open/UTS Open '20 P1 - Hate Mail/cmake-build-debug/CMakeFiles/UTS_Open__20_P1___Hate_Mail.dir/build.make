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
CMAKE_SOURCE_DIR = "C:\Users\allen\Documents\Code\Problems\UTS Open\UTS Open '20 P1 - Hate Mail"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\allen\Documents\Code\Problems\UTS Open\UTS Open '20 P1 - Hate Mail\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/UTS_Open__20_P1___Hate_Mail.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/UTS_Open__20_P1___Hate_Mail.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/UTS_Open__20_P1___Hate_Mail.dir/flags.make

CMakeFiles/UTS_Open__20_P1___Hate_Mail.dir/main.cpp.obj: CMakeFiles/UTS_Open__20_P1___Hate_Mail.dir/flags.make
CMakeFiles/UTS_Open__20_P1___Hate_Mail.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\allen\Documents\Code\Problems\UTS Open\UTS Open '20 P1 - Hate Mail\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/UTS_Open__20_P1___Hate_Mail.dir/main.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\UTS_Open__20_P1___Hate_Mail.dir\main.cpp.obj -c "C:\Users\allen\Documents\Code\Problems\UTS Open\UTS Open '20 P1 - Hate Mail\main.cpp"

CMakeFiles/UTS_Open__20_P1___Hate_Mail.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/UTS_Open__20_P1___Hate_Mail.dir/main.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\allen\Documents\Code\Problems\UTS Open\UTS Open '20 P1 - Hate Mail\main.cpp" > CMakeFiles\UTS_Open__20_P1___Hate_Mail.dir\main.cpp.i

CMakeFiles/UTS_Open__20_P1___Hate_Mail.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/UTS_Open__20_P1___Hate_Mail.dir/main.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\allen\Documents\Code\Problems\UTS Open\UTS Open '20 P1 - Hate Mail\main.cpp" -o CMakeFiles\UTS_Open__20_P1___Hate_Mail.dir\main.cpp.s

# Object files for target UTS_Open__20_P1___Hate_Mail
UTS_Open__20_P1___Hate_Mail_OBJECTS = \
"CMakeFiles/UTS_Open__20_P1___Hate_Mail.dir/main.cpp.obj"

# External object files for target UTS_Open__20_P1___Hate_Mail
UTS_Open__20_P1___Hate_Mail_EXTERNAL_OBJECTS =

UTS_Open__20_P1___Hate_Mail.exe: CMakeFiles/UTS_Open__20_P1___Hate_Mail.dir/main.cpp.obj
UTS_Open__20_P1___Hate_Mail.exe: CMakeFiles/UTS_Open__20_P1___Hate_Mail.dir/build.make
UTS_Open__20_P1___Hate_Mail.exe: CMakeFiles/UTS_Open__20_P1___Hate_Mail.dir/linklibs.rsp
UTS_Open__20_P1___Hate_Mail.exe: CMakeFiles/UTS_Open__20_P1___Hate_Mail.dir/objects1.rsp
UTS_Open__20_P1___Hate_Mail.exe: CMakeFiles/UTS_Open__20_P1___Hate_Mail.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\allen\Documents\Code\Problems\UTS Open\UTS Open '20 P1 - Hate Mail\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable UTS_Open__20_P1___Hate_Mail.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\UTS_Open__20_P1___Hate_Mail.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/UTS_Open__20_P1___Hate_Mail.dir/build: UTS_Open__20_P1___Hate_Mail.exe

.PHONY : CMakeFiles/UTS_Open__20_P1___Hate_Mail.dir/build

CMakeFiles/UTS_Open__20_P1___Hate_Mail.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\UTS_Open__20_P1___Hate_Mail.dir\cmake_clean.cmake
.PHONY : CMakeFiles/UTS_Open__20_P1___Hate_Mail.dir/clean

CMakeFiles/UTS_Open__20_P1___Hate_Mail.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\allen\Documents\Code\Problems\UTS Open\UTS Open '20 P1 - Hate Mail" "C:\Users\allen\Documents\Code\Problems\UTS Open\UTS Open '20 P1 - Hate Mail" "C:\Users\allen\Documents\Code\Problems\UTS Open\UTS Open '20 P1 - Hate Mail\cmake-build-debug" "C:\Users\allen\Documents\Code\Problems\UTS Open\UTS Open '20 P1 - Hate Mail\cmake-build-debug" "C:\Users\allen\Documents\Code\Problems\UTS Open\UTS Open '20 P1 - Hate Mail\cmake-build-debug\CMakeFiles\UTS_Open__20_P1___Hate_Mail.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/UTS_Open__20_P1___Hate_Mail.dir/depend

