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
CMAKE_SOURCE_DIR = /home/zaf/MyTinyMuduo/src/base

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zaf/MyTinyMuduo/src/base

# Include any dependencies generated for this target.
include CMakeFiles/my_tiny_muduo_base.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/my_tiny_muduo_base.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/my_tiny_muduo_base.dir/flags.make

CMakeFiles/my_tiny_muduo_base.dir/MutexLock.cpp.o: CMakeFiles/my_tiny_muduo_base.dir/flags.make
CMakeFiles/my_tiny_muduo_base.dir/MutexLock.cpp.o: MutexLock.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zaf/MyTinyMuduo/src/base/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/my_tiny_muduo_base.dir/MutexLock.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/my_tiny_muduo_base.dir/MutexLock.cpp.o -c /home/zaf/MyTinyMuduo/src/base/MutexLock.cpp

CMakeFiles/my_tiny_muduo_base.dir/MutexLock.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/my_tiny_muduo_base.dir/MutexLock.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zaf/MyTinyMuduo/src/base/MutexLock.cpp > CMakeFiles/my_tiny_muduo_base.dir/MutexLock.cpp.i

CMakeFiles/my_tiny_muduo_base.dir/MutexLock.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/my_tiny_muduo_base.dir/MutexLock.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zaf/MyTinyMuduo/src/base/MutexLock.cpp -o CMakeFiles/my_tiny_muduo_base.dir/MutexLock.cpp.s

CMakeFiles/my_tiny_muduo_base.dir/MutexLock.cpp.o.requires:

.PHONY : CMakeFiles/my_tiny_muduo_base.dir/MutexLock.cpp.o.requires

CMakeFiles/my_tiny_muduo_base.dir/MutexLock.cpp.o.provides: CMakeFiles/my_tiny_muduo_base.dir/MutexLock.cpp.o.requires
	$(MAKE) -f CMakeFiles/my_tiny_muduo_base.dir/build.make CMakeFiles/my_tiny_muduo_base.dir/MutexLock.cpp.o.provides.build
.PHONY : CMakeFiles/my_tiny_muduo_base.dir/MutexLock.cpp.o.provides

CMakeFiles/my_tiny_muduo_base.dir/MutexLock.cpp.o.provides.build: CMakeFiles/my_tiny_muduo_base.dir/MutexLock.cpp.o


CMakeFiles/my_tiny_muduo_base.dir/Logger.cpp.o: CMakeFiles/my_tiny_muduo_base.dir/flags.make
CMakeFiles/my_tiny_muduo_base.dir/Logger.cpp.o: Logger.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zaf/MyTinyMuduo/src/base/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/my_tiny_muduo_base.dir/Logger.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/my_tiny_muduo_base.dir/Logger.cpp.o -c /home/zaf/MyTinyMuduo/src/base/Logger.cpp

CMakeFiles/my_tiny_muduo_base.dir/Logger.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/my_tiny_muduo_base.dir/Logger.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zaf/MyTinyMuduo/src/base/Logger.cpp > CMakeFiles/my_tiny_muduo_base.dir/Logger.cpp.i

CMakeFiles/my_tiny_muduo_base.dir/Logger.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/my_tiny_muduo_base.dir/Logger.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zaf/MyTinyMuduo/src/base/Logger.cpp -o CMakeFiles/my_tiny_muduo_base.dir/Logger.cpp.s

CMakeFiles/my_tiny_muduo_base.dir/Logger.cpp.o.requires:

.PHONY : CMakeFiles/my_tiny_muduo_base.dir/Logger.cpp.o.requires

CMakeFiles/my_tiny_muduo_base.dir/Logger.cpp.o.provides: CMakeFiles/my_tiny_muduo_base.dir/Logger.cpp.o.requires
	$(MAKE) -f CMakeFiles/my_tiny_muduo_base.dir/build.make CMakeFiles/my_tiny_muduo_base.dir/Logger.cpp.o.provides.build
.PHONY : CMakeFiles/my_tiny_muduo_base.dir/Logger.cpp.o.provides

CMakeFiles/my_tiny_muduo_base.dir/Logger.cpp.o.provides.build: CMakeFiles/my_tiny_muduo_base.dir/Logger.cpp.o


CMakeFiles/my_tiny_muduo_base.dir/Thread.cpp.o: CMakeFiles/my_tiny_muduo_base.dir/flags.make
CMakeFiles/my_tiny_muduo_base.dir/Thread.cpp.o: Thread.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zaf/MyTinyMuduo/src/base/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/my_tiny_muduo_base.dir/Thread.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/my_tiny_muduo_base.dir/Thread.cpp.o -c /home/zaf/MyTinyMuduo/src/base/Thread.cpp

CMakeFiles/my_tiny_muduo_base.dir/Thread.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/my_tiny_muduo_base.dir/Thread.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zaf/MyTinyMuduo/src/base/Thread.cpp > CMakeFiles/my_tiny_muduo_base.dir/Thread.cpp.i

CMakeFiles/my_tiny_muduo_base.dir/Thread.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/my_tiny_muduo_base.dir/Thread.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zaf/MyTinyMuduo/src/base/Thread.cpp -o CMakeFiles/my_tiny_muduo_base.dir/Thread.cpp.s

CMakeFiles/my_tiny_muduo_base.dir/Thread.cpp.o.requires:

.PHONY : CMakeFiles/my_tiny_muduo_base.dir/Thread.cpp.o.requires

CMakeFiles/my_tiny_muduo_base.dir/Thread.cpp.o.provides: CMakeFiles/my_tiny_muduo_base.dir/Thread.cpp.o.requires
	$(MAKE) -f CMakeFiles/my_tiny_muduo_base.dir/build.make CMakeFiles/my_tiny_muduo_base.dir/Thread.cpp.o.provides.build
.PHONY : CMakeFiles/my_tiny_muduo_base.dir/Thread.cpp.o.provides

CMakeFiles/my_tiny_muduo_base.dir/Thread.cpp.o.provides.build: CMakeFiles/my_tiny_muduo_base.dir/Thread.cpp.o


CMakeFiles/my_tiny_muduo_base.dir/Semaphore.cpp.o: CMakeFiles/my_tiny_muduo_base.dir/flags.make
CMakeFiles/my_tiny_muduo_base.dir/Semaphore.cpp.o: Semaphore.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zaf/MyTinyMuduo/src/base/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/my_tiny_muduo_base.dir/Semaphore.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/my_tiny_muduo_base.dir/Semaphore.cpp.o -c /home/zaf/MyTinyMuduo/src/base/Semaphore.cpp

CMakeFiles/my_tiny_muduo_base.dir/Semaphore.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/my_tiny_muduo_base.dir/Semaphore.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zaf/MyTinyMuduo/src/base/Semaphore.cpp > CMakeFiles/my_tiny_muduo_base.dir/Semaphore.cpp.i

CMakeFiles/my_tiny_muduo_base.dir/Semaphore.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/my_tiny_muduo_base.dir/Semaphore.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zaf/MyTinyMuduo/src/base/Semaphore.cpp -o CMakeFiles/my_tiny_muduo_base.dir/Semaphore.cpp.s

CMakeFiles/my_tiny_muduo_base.dir/Semaphore.cpp.o.requires:

.PHONY : CMakeFiles/my_tiny_muduo_base.dir/Semaphore.cpp.o.requires

CMakeFiles/my_tiny_muduo_base.dir/Semaphore.cpp.o.provides: CMakeFiles/my_tiny_muduo_base.dir/Semaphore.cpp.o.requires
	$(MAKE) -f CMakeFiles/my_tiny_muduo_base.dir/build.make CMakeFiles/my_tiny_muduo_base.dir/Semaphore.cpp.o.provides.build
.PHONY : CMakeFiles/my_tiny_muduo_base.dir/Semaphore.cpp.o.provides

CMakeFiles/my_tiny_muduo_base.dir/Semaphore.cpp.o.provides.build: CMakeFiles/my_tiny_muduo_base.dir/Semaphore.cpp.o


CMakeFiles/my_tiny_muduo_base.dir/LogLevel.cpp.o: CMakeFiles/my_tiny_muduo_base.dir/flags.make
CMakeFiles/my_tiny_muduo_base.dir/LogLevel.cpp.o: LogLevel.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zaf/MyTinyMuduo/src/base/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/my_tiny_muduo_base.dir/LogLevel.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/my_tiny_muduo_base.dir/LogLevel.cpp.o -c /home/zaf/MyTinyMuduo/src/base/LogLevel.cpp

CMakeFiles/my_tiny_muduo_base.dir/LogLevel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/my_tiny_muduo_base.dir/LogLevel.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zaf/MyTinyMuduo/src/base/LogLevel.cpp > CMakeFiles/my_tiny_muduo_base.dir/LogLevel.cpp.i

CMakeFiles/my_tiny_muduo_base.dir/LogLevel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/my_tiny_muduo_base.dir/LogLevel.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zaf/MyTinyMuduo/src/base/LogLevel.cpp -o CMakeFiles/my_tiny_muduo_base.dir/LogLevel.cpp.s

CMakeFiles/my_tiny_muduo_base.dir/LogLevel.cpp.o.requires:

.PHONY : CMakeFiles/my_tiny_muduo_base.dir/LogLevel.cpp.o.requires

CMakeFiles/my_tiny_muduo_base.dir/LogLevel.cpp.o.provides: CMakeFiles/my_tiny_muduo_base.dir/LogLevel.cpp.o.requires
	$(MAKE) -f CMakeFiles/my_tiny_muduo_base.dir/build.make CMakeFiles/my_tiny_muduo_base.dir/LogLevel.cpp.o.provides.build
.PHONY : CMakeFiles/my_tiny_muduo_base.dir/LogLevel.cpp.o.provides

CMakeFiles/my_tiny_muduo_base.dir/LogLevel.cpp.o.provides.build: CMakeFiles/my_tiny_muduo_base.dir/LogLevel.cpp.o


CMakeFiles/my_tiny_muduo_base.dir/LogEvent.cpp.o: CMakeFiles/my_tiny_muduo_base.dir/flags.make
CMakeFiles/my_tiny_muduo_base.dir/LogEvent.cpp.o: LogEvent.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zaf/MyTinyMuduo/src/base/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/my_tiny_muduo_base.dir/LogEvent.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/my_tiny_muduo_base.dir/LogEvent.cpp.o -c /home/zaf/MyTinyMuduo/src/base/LogEvent.cpp

CMakeFiles/my_tiny_muduo_base.dir/LogEvent.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/my_tiny_muduo_base.dir/LogEvent.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zaf/MyTinyMuduo/src/base/LogEvent.cpp > CMakeFiles/my_tiny_muduo_base.dir/LogEvent.cpp.i

CMakeFiles/my_tiny_muduo_base.dir/LogEvent.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/my_tiny_muduo_base.dir/LogEvent.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zaf/MyTinyMuduo/src/base/LogEvent.cpp -o CMakeFiles/my_tiny_muduo_base.dir/LogEvent.cpp.s

CMakeFiles/my_tiny_muduo_base.dir/LogEvent.cpp.o.requires:

.PHONY : CMakeFiles/my_tiny_muduo_base.dir/LogEvent.cpp.o.requires

CMakeFiles/my_tiny_muduo_base.dir/LogEvent.cpp.o.provides: CMakeFiles/my_tiny_muduo_base.dir/LogEvent.cpp.o.requires
	$(MAKE) -f CMakeFiles/my_tiny_muduo_base.dir/build.make CMakeFiles/my_tiny_muduo_base.dir/LogEvent.cpp.o.provides.build
.PHONY : CMakeFiles/my_tiny_muduo_base.dir/LogEvent.cpp.o.provides

CMakeFiles/my_tiny_muduo_base.dir/LogEvent.cpp.o.provides.build: CMakeFiles/my_tiny_muduo_base.dir/LogEvent.cpp.o


CMakeFiles/my_tiny_muduo_base.dir/LogFormatter.cpp.o: CMakeFiles/my_tiny_muduo_base.dir/flags.make
CMakeFiles/my_tiny_muduo_base.dir/LogFormatter.cpp.o: LogFormatter.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zaf/MyTinyMuduo/src/base/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/my_tiny_muduo_base.dir/LogFormatter.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/my_tiny_muduo_base.dir/LogFormatter.cpp.o -c /home/zaf/MyTinyMuduo/src/base/LogFormatter.cpp

CMakeFiles/my_tiny_muduo_base.dir/LogFormatter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/my_tiny_muduo_base.dir/LogFormatter.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zaf/MyTinyMuduo/src/base/LogFormatter.cpp > CMakeFiles/my_tiny_muduo_base.dir/LogFormatter.cpp.i

CMakeFiles/my_tiny_muduo_base.dir/LogFormatter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/my_tiny_muduo_base.dir/LogFormatter.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zaf/MyTinyMuduo/src/base/LogFormatter.cpp -o CMakeFiles/my_tiny_muduo_base.dir/LogFormatter.cpp.s

CMakeFiles/my_tiny_muduo_base.dir/LogFormatter.cpp.o.requires:

.PHONY : CMakeFiles/my_tiny_muduo_base.dir/LogFormatter.cpp.o.requires

CMakeFiles/my_tiny_muduo_base.dir/LogFormatter.cpp.o.provides: CMakeFiles/my_tiny_muduo_base.dir/LogFormatter.cpp.o.requires
	$(MAKE) -f CMakeFiles/my_tiny_muduo_base.dir/build.make CMakeFiles/my_tiny_muduo_base.dir/LogFormatter.cpp.o.provides.build
.PHONY : CMakeFiles/my_tiny_muduo_base.dir/LogFormatter.cpp.o.provides

CMakeFiles/my_tiny_muduo_base.dir/LogFormatter.cpp.o.provides.build: CMakeFiles/my_tiny_muduo_base.dir/LogFormatter.cpp.o


CMakeFiles/my_tiny_muduo_base.dir/LogFileAppender.cpp.o: CMakeFiles/my_tiny_muduo_base.dir/flags.make
CMakeFiles/my_tiny_muduo_base.dir/LogFileAppender.cpp.o: LogFileAppender.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zaf/MyTinyMuduo/src/base/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/my_tiny_muduo_base.dir/LogFileAppender.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/my_tiny_muduo_base.dir/LogFileAppender.cpp.o -c /home/zaf/MyTinyMuduo/src/base/LogFileAppender.cpp

CMakeFiles/my_tiny_muduo_base.dir/LogFileAppender.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/my_tiny_muduo_base.dir/LogFileAppender.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zaf/MyTinyMuduo/src/base/LogFileAppender.cpp > CMakeFiles/my_tiny_muduo_base.dir/LogFileAppender.cpp.i

CMakeFiles/my_tiny_muduo_base.dir/LogFileAppender.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/my_tiny_muduo_base.dir/LogFileAppender.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zaf/MyTinyMuduo/src/base/LogFileAppender.cpp -o CMakeFiles/my_tiny_muduo_base.dir/LogFileAppender.cpp.s

CMakeFiles/my_tiny_muduo_base.dir/LogFileAppender.cpp.o.requires:

.PHONY : CMakeFiles/my_tiny_muduo_base.dir/LogFileAppender.cpp.o.requires

CMakeFiles/my_tiny_muduo_base.dir/LogFileAppender.cpp.o.provides: CMakeFiles/my_tiny_muduo_base.dir/LogFileAppender.cpp.o.requires
	$(MAKE) -f CMakeFiles/my_tiny_muduo_base.dir/build.make CMakeFiles/my_tiny_muduo_base.dir/LogFileAppender.cpp.o.provides.build
.PHONY : CMakeFiles/my_tiny_muduo_base.dir/LogFileAppender.cpp.o.provides

CMakeFiles/my_tiny_muduo_base.dir/LogFileAppender.cpp.o.provides.build: CMakeFiles/my_tiny_muduo_base.dir/LogFileAppender.cpp.o


CMakeFiles/my_tiny_muduo_base.dir/LogEventWarp.cpp.o: CMakeFiles/my_tiny_muduo_base.dir/flags.make
CMakeFiles/my_tiny_muduo_base.dir/LogEventWarp.cpp.o: LogEventWarp.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zaf/MyTinyMuduo/src/base/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/my_tiny_muduo_base.dir/LogEventWarp.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/my_tiny_muduo_base.dir/LogEventWarp.cpp.o -c /home/zaf/MyTinyMuduo/src/base/LogEventWarp.cpp

CMakeFiles/my_tiny_muduo_base.dir/LogEventWarp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/my_tiny_muduo_base.dir/LogEventWarp.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zaf/MyTinyMuduo/src/base/LogEventWarp.cpp > CMakeFiles/my_tiny_muduo_base.dir/LogEventWarp.cpp.i

CMakeFiles/my_tiny_muduo_base.dir/LogEventWarp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/my_tiny_muduo_base.dir/LogEventWarp.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zaf/MyTinyMuduo/src/base/LogEventWarp.cpp -o CMakeFiles/my_tiny_muduo_base.dir/LogEventWarp.cpp.s

CMakeFiles/my_tiny_muduo_base.dir/LogEventWarp.cpp.o.requires:

.PHONY : CMakeFiles/my_tiny_muduo_base.dir/LogEventWarp.cpp.o.requires

CMakeFiles/my_tiny_muduo_base.dir/LogEventWarp.cpp.o.provides: CMakeFiles/my_tiny_muduo_base.dir/LogEventWarp.cpp.o.requires
	$(MAKE) -f CMakeFiles/my_tiny_muduo_base.dir/build.make CMakeFiles/my_tiny_muduo_base.dir/LogEventWarp.cpp.o.provides.build
.PHONY : CMakeFiles/my_tiny_muduo_base.dir/LogEventWarp.cpp.o.provides

CMakeFiles/my_tiny_muduo_base.dir/LogEventWarp.cpp.o.provides.build: CMakeFiles/my_tiny_muduo_base.dir/LogEventWarp.cpp.o


# Object files for target my_tiny_muduo_base
my_tiny_muduo_base_OBJECTS = \
"CMakeFiles/my_tiny_muduo_base.dir/MutexLock.cpp.o" \
"CMakeFiles/my_tiny_muduo_base.dir/Logger.cpp.o" \
"CMakeFiles/my_tiny_muduo_base.dir/Thread.cpp.o" \
"CMakeFiles/my_tiny_muduo_base.dir/Semaphore.cpp.o" \
"CMakeFiles/my_tiny_muduo_base.dir/LogLevel.cpp.o" \
"CMakeFiles/my_tiny_muduo_base.dir/LogEvent.cpp.o" \
"CMakeFiles/my_tiny_muduo_base.dir/LogFormatter.cpp.o" \
"CMakeFiles/my_tiny_muduo_base.dir/LogFileAppender.cpp.o" \
"CMakeFiles/my_tiny_muduo_base.dir/LogEventWarp.cpp.o"

# External object files for target my_tiny_muduo_base
my_tiny_muduo_base_EXTERNAL_OBJECTS =

libmy_tiny_muduo_base.a: CMakeFiles/my_tiny_muduo_base.dir/MutexLock.cpp.o
libmy_tiny_muduo_base.a: CMakeFiles/my_tiny_muduo_base.dir/Logger.cpp.o
libmy_tiny_muduo_base.a: CMakeFiles/my_tiny_muduo_base.dir/Thread.cpp.o
libmy_tiny_muduo_base.a: CMakeFiles/my_tiny_muduo_base.dir/Semaphore.cpp.o
libmy_tiny_muduo_base.a: CMakeFiles/my_tiny_muduo_base.dir/LogLevel.cpp.o
libmy_tiny_muduo_base.a: CMakeFiles/my_tiny_muduo_base.dir/LogEvent.cpp.o
libmy_tiny_muduo_base.a: CMakeFiles/my_tiny_muduo_base.dir/LogFormatter.cpp.o
libmy_tiny_muduo_base.a: CMakeFiles/my_tiny_muduo_base.dir/LogFileAppender.cpp.o
libmy_tiny_muduo_base.a: CMakeFiles/my_tiny_muduo_base.dir/LogEventWarp.cpp.o
libmy_tiny_muduo_base.a: CMakeFiles/my_tiny_muduo_base.dir/build.make
libmy_tiny_muduo_base.a: CMakeFiles/my_tiny_muduo_base.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zaf/MyTinyMuduo/src/base/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX static library libmy_tiny_muduo_base.a"
	$(CMAKE_COMMAND) -P CMakeFiles/my_tiny_muduo_base.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/my_tiny_muduo_base.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/my_tiny_muduo_base.dir/build: libmy_tiny_muduo_base.a

.PHONY : CMakeFiles/my_tiny_muduo_base.dir/build

CMakeFiles/my_tiny_muduo_base.dir/requires: CMakeFiles/my_tiny_muduo_base.dir/MutexLock.cpp.o.requires
CMakeFiles/my_tiny_muduo_base.dir/requires: CMakeFiles/my_tiny_muduo_base.dir/Logger.cpp.o.requires
CMakeFiles/my_tiny_muduo_base.dir/requires: CMakeFiles/my_tiny_muduo_base.dir/Thread.cpp.o.requires
CMakeFiles/my_tiny_muduo_base.dir/requires: CMakeFiles/my_tiny_muduo_base.dir/Semaphore.cpp.o.requires
CMakeFiles/my_tiny_muduo_base.dir/requires: CMakeFiles/my_tiny_muduo_base.dir/LogLevel.cpp.o.requires
CMakeFiles/my_tiny_muduo_base.dir/requires: CMakeFiles/my_tiny_muduo_base.dir/LogEvent.cpp.o.requires
CMakeFiles/my_tiny_muduo_base.dir/requires: CMakeFiles/my_tiny_muduo_base.dir/LogFormatter.cpp.o.requires
CMakeFiles/my_tiny_muduo_base.dir/requires: CMakeFiles/my_tiny_muduo_base.dir/LogFileAppender.cpp.o.requires
CMakeFiles/my_tiny_muduo_base.dir/requires: CMakeFiles/my_tiny_muduo_base.dir/LogEventWarp.cpp.o.requires

.PHONY : CMakeFiles/my_tiny_muduo_base.dir/requires

CMakeFiles/my_tiny_muduo_base.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/my_tiny_muduo_base.dir/cmake_clean.cmake
.PHONY : CMakeFiles/my_tiny_muduo_base.dir/clean

CMakeFiles/my_tiny_muduo_base.dir/depend:
	cd /home/zaf/MyTinyMuduo/src/base && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zaf/MyTinyMuduo/src/base /home/zaf/MyTinyMuduo/src/base /home/zaf/MyTinyMuduo/src/base /home/zaf/MyTinyMuduo/src/base /home/zaf/MyTinyMuduo/src/base/CMakeFiles/my_tiny_muduo_base.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/my_tiny_muduo_base.dir/depend
