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
CMAKE_SOURCE_DIR = /home/interview/MyTinyWeb/base

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/interview/MyTinyWeb/base

# Include any dependencies generated for this target.
include CMakeFiles/LogTest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/LogTest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/LogTest.dir/flags.make

CMakeFiles/LogTest.dir/LogTest.cpp.o: CMakeFiles/LogTest.dir/flags.make
CMakeFiles/LogTest.dir/LogTest.cpp.o: LogTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/interview/MyTinyWeb/base/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/LogTest.dir/LogTest.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LogTest.dir/LogTest.cpp.o -c /home/interview/MyTinyWeb/base/LogTest.cpp

CMakeFiles/LogTest.dir/LogTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LogTest.dir/LogTest.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/interview/MyTinyWeb/base/LogTest.cpp > CMakeFiles/LogTest.dir/LogTest.cpp.i

CMakeFiles/LogTest.dir/LogTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LogTest.dir/LogTest.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/interview/MyTinyWeb/base/LogTest.cpp -o CMakeFiles/LogTest.dir/LogTest.cpp.s

CMakeFiles/LogTest.dir/LogTest.cpp.o.requires:

.PHONY : CMakeFiles/LogTest.dir/LogTest.cpp.o.requires

CMakeFiles/LogTest.dir/LogTest.cpp.o.provides: CMakeFiles/LogTest.dir/LogTest.cpp.o.requires
	$(MAKE) -f CMakeFiles/LogTest.dir/build.make CMakeFiles/LogTest.dir/LogTest.cpp.o.provides.build
.PHONY : CMakeFiles/LogTest.dir/LogTest.cpp.o.provides

CMakeFiles/LogTest.dir/LogTest.cpp.o.provides.build: CMakeFiles/LogTest.dir/LogTest.cpp.o


# Object files for target LogTest
LogTest_OBJECTS = \
"CMakeFiles/LogTest.dir/LogTest.cpp.o"

# External object files for target LogTest
LogTest_EXTERNAL_OBJECTS =

LogTest: CMakeFiles/LogTest.dir/LogTest.cpp.o
LogTest: CMakeFiles/LogTest.dir/build.make
LogTest: libbase.a
LogTest: CMakeFiles/LogTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/interview/MyTinyWeb/base/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable LogTest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/LogTest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/LogTest.dir/build: LogTest

.PHONY : CMakeFiles/LogTest.dir/build

CMakeFiles/LogTest.dir/requires: CMakeFiles/LogTest.dir/LogTest.cpp.o.requires

.PHONY : CMakeFiles/LogTest.dir/requires

CMakeFiles/LogTest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/LogTest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/LogTest.dir/clean

CMakeFiles/LogTest.dir/depend:
	cd /home/interview/MyTinyWeb/base && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/interview/MyTinyWeb/base /home/interview/MyTinyWeb/base /home/interview/MyTinyWeb/base /home/interview/MyTinyWeb/base /home/interview/MyTinyWeb/base/CMakeFiles/LogTest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/LogTest.dir/depend

