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
CMAKE_SOURCE_DIR = /home/interview/MyTinyWeb/base/net

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/interview/MyTinyWeb/base/net

# Include any dependencies generated for this target.
include CMakeFiles/EventLoop_Test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/EventLoop_Test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/EventLoop_Test.dir/flags.make

CMakeFiles/EventLoop_Test.dir/EventLoop_Test.cpp.o: CMakeFiles/EventLoop_Test.dir/flags.make
CMakeFiles/EventLoop_Test.dir/EventLoop_Test.cpp.o: EventLoop_Test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/interview/MyTinyWeb/base/net/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/EventLoop_Test.dir/EventLoop_Test.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/EventLoop_Test.dir/EventLoop_Test.cpp.o -c /home/interview/MyTinyWeb/base/net/EventLoop_Test.cpp

CMakeFiles/EventLoop_Test.dir/EventLoop_Test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/EventLoop_Test.dir/EventLoop_Test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/interview/MyTinyWeb/base/net/EventLoop_Test.cpp > CMakeFiles/EventLoop_Test.dir/EventLoop_Test.cpp.i

CMakeFiles/EventLoop_Test.dir/EventLoop_Test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/EventLoop_Test.dir/EventLoop_Test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/interview/MyTinyWeb/base/net/EventLoop_Test.cpp -o CMakeFiles/EventLoop_Test.dir/EventLoop_Test.cpp.s

CMakeFiles/EventLoop_Test.dir/EventLoop_Test.cpp.o.requires:

.PHONY : CMakeFiles/EventLoop_Test.dir/EventLoop_Test.cpp.o.requires

CMakeFiles/EventLoop_Test.dir/EventLoop_Test.cpp.o.provides: CMakeFiles/EventLoop_Test.dir/EventLoop_Test.cpp.o.requires
	$(MAKE) -f CMakeFiles/EventLoop_Test.dir/build.make CMakeFiles/EventLoop_Test.dir/EventLoop_Test.cpp.o.provides.build
.PHONY : CMakeFiles/EventLoop_Test.dir/EventLoop_Test.cpp.o.provides

CMakeFiles/EventLoop_Test.dir/EventLoop_Test.cpp.o.provides.build: CMakeFiles/EventLoop_Test.dir/EventLoop_Test.cpp.o


# Object files for target EventLoop_Test
EventLoop_Test_OBJECTS = \
"CMakeFiles/EventLoop_Test.dir/EventLoop_Test.cpp.o"

# External object files for target EventLoop_Test
EventLoop_Test_EXTERNAL_OBJECTS =

EventLoop_Test: CMakeFiles/EventLoop_Test.dir/EventLoop_Test.cpp.o
EventLoop_Test: CMakeFiles/EventLoop_Test.dir/build.make
EventLoop_Test: libnet.a
EventLoop_Test: CMakeFiles/EventLoop_Test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/interview/MyTinyWeb/base/net/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable EventLoop_Test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/EventLoop_Test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/EventLoop_Test.dir/build: EventLoop_Test

.PHONY : CMakeFiles/EventLoop_Test.dir/build

CMakeFiles/EventLoop_Test.dir/requires: CMakeFiles/EventLoop_Test.dir/EventLoop_Test.cpp.o.requires

.PHONY : CMakeFiles/EventLoop_Test.dir/requires

CMakeFiles/EventLoop_Test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/EventLoop_Test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/EventLoop_Test.dir/clean

CMakeFiles/EventLoop_Test.dir/depend:
	cd /home/interview/MyTinyWeb/base/net && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/interview/MyTinyWeb/base/net /home/interview/MyTinyWeb/base/net /home/interview/MyTinyWeb/base/net /home/interview/MyTinyWeb/base/net /home/interview/MyTinyWeb/base/net/CMakeFiles/EventLoop_Test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/EventLoop_Test.dir/depend

