# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/dominic/Projects/CppProjects/Poker

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dominic/Projects/CppProjects/Poker/build

# Include any dependencies generated for this target.
include CMakeFiles/poker.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/poker.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/poker.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/poker.dir/flags.make

CMakeFiles/poker.dir/src/main.cpp.o: CMakeFiles/poker.dir/flags.make
CMakeFiles/poker.dir/src/main.cpp.o: /home/dominic/Projects/CppProjects/Poker/src/main.cpp
CMakeFiles/poker.dir/src/main.cpp.o: CMakeFiles/poker.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/dominic/Projects/CppProjects/Poker/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/poker.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/poker.dir/src/main.cpp.o -MF CMakeFiles/poker.dir/src/main.cpp.o.d -o CMakeFiles/poker.dir/src/main.cpp.o -c /home/dominic/Projects/CppProjects/Poker/src/main.cpp

CMakeFiles/poker.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/poker.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dominic/Projects/CppProjects/Poker/src/main.cpp > CMakeFiles/poker.dir/src/main.cpp.i

CMakeFiles/poker.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/poker.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dominic/Projects/CppProjects/Poker/src/main.cpp -o CMakeFiles/poker.dir/src/main.cpp.s

# Object files for target poker
poker_OBJECTS = \
"CMakeFiles/poker.dir/src/main.cpp.o"

# External object files for target poker
poker_EXTERNAL_OBJECTS =

poker: CMakeFiles/poker.dir/src/main.cpp.o
poker: CMakeFiles/poker.dir/build.make
poker: CMakeFiles/poker.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/dominic/Projects/CppProjects/Poker/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable poker"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/poker.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/poker.dir/build: poker
.PHONY : CMakeFiles/poker.dir/build

CMakeFiles/poker.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/poker.dir/cmake_clean.cmake
.PHONY : CMakeFiles/poker.dir/clean

CMakeFiles/poker.dir/depend:
	cd /home/dominic/Projects/CppProjects/Poker/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dominic/Projects/CppProjects/Poker /home/dominic/Projects/CppProjects/Poker /home/dominic/Projects/CppProjects/Poker/build /home/dominic/Projects/CppProjects/Poker/build /home/dominic/Projects/CppProjects/Poker/build/CMakeFiles/poker.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/poker.dir/depend

