# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/gerardd/Desktop/PW-Shamans

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/gerardd/Desktop/PW-Shamans

# Include any dependencies generated for this target.
include src/tests/CMakeFiles/crystalSelectionTest.dir/depend.make

# Include the progress variables for this target.
include src/tests/CMakeFiles/crystalSelectionTest.dir/progress.make

# Include the compile flags for this target's objects.
include src/tests/CMakeFiles/crystalSelectionTest.dir/flags.make

src/tests/CMakeFiles/crystalSelectionTest.dir/crystalSelectionTest.cpp.o: src/tests/CMakeFiles/crystalSelectionTest.dir/flags.make
src/tests/CMakeFiles/crystalSelectionTest.dir/crystalSelectionTest.cpp.o: src/tests/crystalSelectionTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gerardd/Desktop/PW-Shamans/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/tests/CMakeFiles/crystalSelectionTest.dir/crystalSelectionTest.cpp.o"
	cd /home/gerardd/Desktop/PW-Shamans/src/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/crystalSelectionTest.dir/crystalSelectionTest.cpp.o -c /home/gerardd/Desktop/PW-Shamans/src/tests/crystalSelectionTest.cpp

src/tests/CMakeFiles/crystalSelectionTest.dir/crystalSelectionTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/crystalSelectionTest.dir/crystalSelectionTest.cpp.i"
	cd /home/gerardd/Desktop/PW-Shamans/src/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gerardd/Desktop/PW-Shamans/src/tests/crystalSelectionTest.cpp > CMakeFiles/crystalSelectionTest.dir/crystalSelectionTest.cpp.i

src/tests/CMakeFiles/crystalSelectionTest.dir/crystalSelectionTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/crystalSelectionTest.dir/crystalSelectionTest.cpp.s"
	cd /home/gerardd/Desktop/PW-Shamans/src/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gerardd/Desktop/PW-Shamans/src/tests/crystalSelectionTest.cpp -o CMakeFiles/crystalSelectionTest.dir/crystalSelectionTest.cpp.s

# Object files for target crystalSelectionTest
crystalSelectionTest_OBJECTS = \
"CMakeFiles/crystalSelectionTest.dir/crystalSelectionTest.cpp.o"

# External object files for target crystalSelectionTest
crystalSelectionTest_EXTERNAL_OBJECTS =

src/tests/crystalSelectionTest: src/tests/CMakeFiles/crystalSelectionTest.dir/crystalSelectionTest.cpp.o
src/tests/crystalSelectionTest: src/tests/CMakeFiles/crystalSelectionTest.dir/build.make
src/tests/crystalSelectionTest: src/tests/CMakeFiles/crystalSelectionTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/gerardd/Desktop/PW-Shamans/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable crystalSelectionTest"
	cd /home/gerardd/Desktop/PW-Shamans/src/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/crystalSelectionTest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/tests/CMakeFiles/crystalSelectionTest.dir/build: src/tests/crystalSelectionTest

.PHONY : src/tests/CMakeFiles/crystalSelectionTest.dir/build

src/tests/CMakeFiles/crystalSelectionTest.dir/clean:
	cd /home/gerardd/Desktop/PW-Shamans/src/tests && $(CMAKE_COMMAND) -P CMakeFiles/crystalSelectionTest.dir/cmake_clean.cmake
.PHONY : src/tests/CMakeFiles/crystalSelectionTest.dir/clean

src/tests/CMakeFiles/crystalSelectionTest.dir/depend:
	cd /home/gerardd/Desktop/PW-Shamans && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/gerardd/Desktop/PW-Shamans /home/gerardd/Desktop/PW-Shamans/src/tests /home/gerardd/Desktop/PW-Shamans /home/gerardd/Desktop/PW-Shamans/src/tests /home/gerardd/Desktop/PW-Shamans/src/tests/CMakeFiles/crystalSelectionTest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/tests/CMakeFiles/crystalSelectionTest.dir/depend
