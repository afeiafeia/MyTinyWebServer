# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/zaf/MyTinyMuduo/src/net

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zaf/MyTinyMuduo/src/net

# Include any dependencies generated for this target.
include test/CMakeFiles/test_echo_main.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/test_echo_main.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/test_echo_main.dir/flags.make

test/CMakeFiles/test_echo_main.dir/test_echo_main.cpp.o: test/CMakeFiles/test_echo_main.dir/flags.make
test/CMakeFiles/test_echo_main.dir/test_echo_main.cpp.o: test/test_echo_main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zaf/MyTinyMuduo/src/net/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/test_echo_main.dir/test_echo_main.cpp.o"
	cd /home/zaf/MyTinyMuduo/src/net/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_echo_main.dir/test_echo_main.cpp.o -c /home/zaf/MyTinyMuduo/src/net/test/test_echo_main.cpp

test/CMakeFiles/test_echo_main.dir/test_echo_main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_echo_main.dir/test_echo_main.cpp.i"
	cd /home/zaf/MyTinyMuduo/src/net/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zaf/MyTinyMuduo/src/net/test/test_echo_main.cpp > CMakeFiles/test_echo_main.dir/test_echo_main.cpp.i

test/CMakeFiles/test_echo_main.dir/test_echo_main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_echo_main.dir/test_echo_main.cpp.s"
	cd /home/zaf/MyTinyMuduo/src/net/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zaf/MyTinyMuduo/src/net/test/test_echo_main.cpp -o CMakeFiles/test_echo_main.dir/test_echo_main.cpp.s

test/CMakeFiles/test_echo_main.dir/test_echo_main.cpp.o.requires:

.PHONY : test/CMakeFiles/test_echo_main.dir/test_echo_main.cpp.o.requires

test/CMakeFiles/test_echo_main.dir/test_echo_main.cpp.o.provides: test/CMakeFiles/test_echo_main.dir/test_echo_main.cpp.o.requires
	$(MAKE) -f test/CMakeFiles/test_echo_main.dir/build.make test/CMakeFiles/test_echo_main.dir/test_echo_main.cpp.o.provides.build
.PHONY : test/CMakeFiles/test_echo_main.dir/test_echo_main.cpp.o.provides

test/CMakeFiles/test_echo_main.dir/test_echo_main.cpp.o.provides.build: test/CMakeFiles/test_echo_main.dir/test_echo_main.cpp.o


# Object files for target test_echo_main
test_echo_main_OBJECTS = \
"CMakeFiles/test_echo_main.dir/test_echo_main.cpp.o"

# External object files for target test_echo_main
test_echo_main_EXTERNAL_OBJECTS =

test/test_echo_main: test/CMakeFiles/test_echo_main.dir/test_echo_main.cpp.o
test/test_echo_main: test/CMakeFiles/test_echo_main.dir/build.make
test/test_echo_main: libmy_tiny_muduo_net.a
test/test_echo_main: test/CMakeFiles/test_echo_main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zaf/MyTinyMuduo/src/net/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test_echo_main"
	cd /home/zaf/MyTinyMuduo/src/net/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_echo_main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/test_echo_main.dir/build: test/test_echo_main

.PHONY : test/CMakeFiles/test_echo_main.dir/build

test/CMakeFiles/test_echo_main.dir/requires: test/CMakeFiles/test_echo_main.dir/test_echo_main.cpp.o.requires

.PHONY : test/CMakeFiles/test_echo_main.dir/requires

test/CMakeFiles/test_echo_main.dir/clean:
	cd /home/zaf/MyTinyMuduo/src/net/test && $(CMAKE_COMMAND) -P CMakeFiles/test_echo_main.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/test_echo_main.dir/clean

test/CMakeFiles/test_echo_main.dir/depend:
	cd /home/zaf/MyTinyMuduo/src/net && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zaf/MyTinyMuduo/src/net /home/zaf/MyTinyMuduo/src/net/test /home/zaf/MyTinyMuduo/src/net /home/zaf/MyTinyMuduo/src/net/test /home/zaf/MyTinyMuduo/src/net/test/CMakeFiles/test_echo_main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/test_echo_main.dir/depend
