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
include CMakeFiles/libbase.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/libbase.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/libbase.dir/flags.make

CMakeFiles/libbase.dir/MutexLock.cpp.o: CMakeFiles/libbase.dir/flags.make
CMakeFiles/libbase.dir/MutexLock.cpp.o: MutexLock.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/interview/MyTinyWeb/base/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/libbase.dir/MutexLock.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/libbase.dir/MutexLock.cpp.o -c /home/interview/MyTinyWeb/base/MutexLock.cpp

CMakeFiles/libbase.dir/MutexLock.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libbase.dir/MutexLock.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/interview/MyTinyWeb/base/MutexLock.cpp > CMakeFiles/libbase.dir/MutexLock.cpp.i

CMakeFiles/libbase.dir/MutexLock.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libbase.dir/MutexLock.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/interview/MyTinyWeb/base/MutexLock.cpp -o CMakeFiles/libbase.dir/MutexLock.cpp.s

CMakeFiles/libbase.dir/MutexLock.cpp.o.requires:

.PHONY : CMakeFiles/libbase.dir/MutexLock.cpp.o.requires

CMakeFiles/libbase.dir/MutexLock.cpp.o.provides: CMakeFiles/libbase.dir/MutexLock.cpp.o.requires
	$(MAKE) -f CMakeFiles/libbase.dir/build.make CMakeFiles/libbase.dir/MutexLock.cpp.o.provides.build
.PHONY : CMakeFiles/libbase.dir/MutexLock.cpp.o.provides

CMakeFiles/libbase.dir/MutexLock.cpp.o.provides.build: CMakeFiles/libbase.dir/MutexLock.cpp.o


CMakeFiles/libbase.dir/FileUtil.cpp.o: CMakeFiles/libbase.dir/flags.make
CMakeFiles/libbase.dir/FileUtil.cpp.o: FileUtil.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/interview/MyTinyWeb/base/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/libbase.dir/FileUtil.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/libbase.dir/FileUtil.cpp.o -c /home/interview/MyTinyWeb/base/FileUtil.cpp

CMakeFiles/libbase.dir/FileUtil.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libbase.dir/FileUtil.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/interview/MyTinyWeb/base/FileUtil.cpp > CMakeFiles/libbase.dir/FileUtil.cpp.i

CMakeFiles/libbase.dir/FileUtil.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libbase.dir/FileUtil.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/interview/MyTinyWeb/base/FileUtil.cpp -o CMakeFiles/libbase.dir/FileUtil.cpp.s

CMakeFiles/libbase.dir/FileUtil.cpp.o.requires:

.PHONY : CMakeFiles/libbase.dir/FileUtil.cpp.o.requires

CMakeFiles/libbase.dir/FileUtil.cpp.o.provides: CMakeFiles/libbase.dir/FileUtil.cpp.o.requires
	$(MAKE) -f CMakeFiles/libbase.dir/build.make CMakeFiles/libbase.dir/FileUtil.cpp.o.provides.build
.PHONY : CMakeFiles/libbase.dir/FileUtil.cpp.o.provides

CMakeFiles/libbase.dir/FileUtil.cpp.o.provides.build: CMakeFiles/libbase.dir/FileUtil.cpp.o


CMakeFiles/libbase.dir/LogFile.cpp.o: CMakeFiles/libbase.dir/flags.make
CMakeFiles/libbase.dir/LogFile.cpp.o: LogFile.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/interview/MyTinyWeb/base/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/libbase.dir/LogFile.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/libbase.dir/LogFile.cpp.o -c /home/interview/MyTinyWeb/base/LogFile.cpp

CMakeFiles/libbase.dir/LogFile.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libbase.dir/LogFile.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/interview/MyTinyWeb/base/LogFile.cpp > CMakeFiles/libbase.dir/LogFile.cpp.i

CMakeFiles/libbase.dir/LogFile.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libbase.dir/LogFile.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/interview/MyTinyWeb/base/LogFile.cpp -o CMakeFiles/libbase.dir/LogFile.cpp.s

CMakeFiles/libbase.dir/LogFile.cpp.o.requires:

.PHONY : CMakeFiles/libbase.dir/LogFile.cpp.o.requires

CMakeFiles/libbase.dir/LogFile.cpp.o.provides: CMakeFiles/libbase.dir/LogFile.cpp.o.requires
	$(MAKE) -f CMakeFiles/libbase.dir/build.make CMakeFiles/libbase.dir/LogFile.cpp.o.provides.build
.PHONY : CMakeFiles/libbase.dir/LogFile.cpp.o.provides

CMakeFiles/libbase.dir/LogFile.cpp.o.provides.build: CMakeFiles/libbase.dir/LogFile.cpp.o


CMakeFiles/libbase.dir/Logger.cpp.o: CMakeFiles/libbase.dir/flags.make
CMakeFiles/libbase.dir/Logger.cpp.o: Logger.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/interview/MyTinyWeb/base/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/libbase.dir/Logger.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/libbase.dir/Logger.cpp.o -c /home/interview/MyTinyWeb/base/Logger.cpp

CMakeFiles/libbase.dir/Logger.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libbase.dir/Logger.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/interview/MyTinyWeb/base/Logger.cpp > CMakeFiles/libbase.dir/Logger.cpp.i

CMakeFiles/libbase.dir/Logger.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libbase.dir/Logger.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/interview/MyTinyWeb/base/Logger.cpp -o CMakeFiles/libbase.dir/Logger.cpp.s

CMakeFiles/libbase.dir/Logger.cpp.o.requires:

.PHONY : CMakeFiles/libbase.dir/Logger.cpp.o.requires

CMakeFiles/libbase.dir/Logger.cpp.o.provides: CMakeFiles/libbase.dir/Logger.cpp.o.requires
	$(MAKE) -f CMakeFiles/libbase.dir/build.make CMakeFiles/libbase.dir/Logger.cpp.o.provides.build
.PHONY : CMakeFiles/libbase.dir/Logger.cpp.o.provides

CMakeFiles/libbase.dir/Logger.cpp.o.provides.build: CMakeFiles/libbase.dir/Logger.cpp.o


CMakeFiles/libbase.dir/Thread.cpp.o: CMakeFiles/libbase.dir/flags.make
CMakeFiles/libbase.dir/Thread.cpp.o: Thread.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/interview/MyTinyWeb/base/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/libbase.dir/Thread.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/libbase.dir/Thread.cpp.o -c /home/interview/MyTinyWeb/base/Thread.cpp

CMakeFiles/libbase.dir/Thread.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libbase.dir/Thread.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/interview/MyTinyWeb/base/Thread.cpp > CMakeFiles/libbase.dir/Thread.cpp.i

CMakeFiles/libbase.dir/Thread.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libbase.dir/Thread.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/interview/MyTinyWeb/base/Thread.cpp -o CMakeFiles/libbase.dir/Thread.cpp.s

CMakeFiles/libbase.dir/Thread.cpp.o.requires:

.PHONY : CMakeFiles/libbase.dir/Thread.cpp.o.requires

CMakeFiles/libbase.dir/Thread.cpp.o.provides: CMakeFiles/libbase.dir/Thread.cpp.o.requires
	$(MAKE) -f CMakeFiles/libbase.dir/build.make CMakeFiles/libbase.dir/Thread.cpp.o.provides.build
.PHONY : CMakeFiles/libbase.dir/Thread.cpp.o.provides

CMakeFiles/libbase.dir/Thread.cpp.o.provides.build: CMakeFiles/libbase.dir/Thread.cpp.o


CMakeFiles/libbase.dir/AsyncLogger.cpp.o: CMakeFiles/libbase.dir/flags.make
CMakeFiles/libbase.dir/AsyncLogger.cpp.o: AsyncLogger.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/interview/MyTinyWeb/base/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/libbase.dir/AsyncLogger.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/libbase.dir/AsyncLogger.cpp.o -c /home/interview/MyTinyWeb/base/AsyncLogger.cpp

CMakeFiles/libbase.dir/AsyncLogger.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libbase.dir/AsyncLogger.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/interview/MyTinyWeb/base/AsyncLogger.cpp > CMakeFiles/libbase.dir/AsyncLogger.cpp.i

CMakeFiles/libbase.dir/AsyncLogger.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libbase.dir/AsyncLogger.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/interview/MyTinyWeb/base/AsyncLogger.cpp -o CMakeFiles/libbase.dir/AsyncLogger.cpp.s

CMakeFiles/libbase.dir/AsyncLogger.cpp.o.requires:

.PHONY : CMakeFiles/libbase.dir/AsyncLogger.cpp.o.requires

CMakeFiles/libbase.dir/AsyncLogger.cpp.o.provides: CMakeFiles/libbase.dir/AsyncLogger.cpp.o.requires
	$(MAKE) -f CMakeFiles/libbase.dir/build.make CMakeFiles/libbase.dir/AsyncLogger.cpp.o.provides.build
.PHONY : CMakeFiles/libbase.dir/AsyncLogger.cpp.o.provides

CMakeFiles/libbase.dir/AsyncLogger.cpp.o.provides.build: CMakeFiles/libbase.dir/AsyncLogger.cpp.o


CMakeFiles/libbase.dir/Semaphore.cpp.o: CMakeFiles/libbase.dir/flags.make
CMakeFiles/libbase.dir/Semaphore.cpp.o: Semaphore.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/interview/MyTinyWeb/base/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/libbase.dir/Semaphore.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/libbase.dir/Semaphore.cpp.o -c /home/interview/MyTinyWeb/base/Semaphore.cpp

CMakeFiles/libbase.dir/Semaphore.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libbase.dir/Semaphore.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/interview/MyTinyWeb/base/Semaphore.cpp > CMakeFiles/libbase.dir/Semaphore.cpp.i

CMakeFiles/libbase.dir/Semaphore.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libbase.dir/Semaphore.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/interview/MyTinyWeb/base/Semaphore.cpp -o CMakeFiles/libbase.dir/Semaphore.cpp.s

CMakeFiles/libbase.dir/Semaphore.cpp.o.requires:

.PHONY : CMakeFiles/libbase.dir/Semaphore.cpp.o.requires

CMakeFiles/libbase.dir/Semaphore.cpp.o.provides: CMakeFiles/libbase.dir/Semaphore.cpp.o.requires
	$(MAKE) -f CMakeFiles/libbase.dir/build.make CMakeFiles/libbase.dir/Semaphore.cpp.o.provides.build
.PHONY : CMakeFiles/libbase.dir/Semaphore.cpp.o.provides

CMakeFiles/libbase.dir/Semaphore.cpp.o.provides.build: CMakeFiles/libbase.dir/Semaphore.cpp.o


CMakeFiles/libbase.dir/LogLevel.cpp.o: CMakeFiles/libbase.dir/flags.make
CMakeFiles/libbase.dir/LogLevel.cpp.o: LogLevel.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/interview/MyTinyWeb/base/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/libbase.dir/LogLevel.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/libbase.dir/LogLevel.cpp.o -c /home/interview/MyTinyWeb/base/LogLevel.cpp

CMakeFiles/libbase.dir/LogLevel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libbase.dir/LogLevel.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/interview/MyTinyWeb/base/LogLevel.cpp > CMakeFiles/libbase.dir/LogLevel.cpp.i

CMakeFiles/libbase.dir/LogLevel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libbase.dir/LogLevel.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/interview/MyTinyWeb/base/LogLevel.cpp -o CMakeFiles/libbase.dir/LogLevel.cpp.s

CMakeFiles/libbase.dir/LogLevel.cpp.o.requires:

.PHONY : CMakeFiles/libbase.dir/LogLevel.cpp.o.requires

CMakeFiles/libbase.dir/LogLevel.cpp.o.provides: CMakeFiles/libbase.dir/LogLevel.cpp.o.requires
	$(MAKE) -f CMakeFiles/libbase.dir/build.make CMakeFiles/libbase.dir/LogLevel.cpp.o.provides.build
.PHONY : CMakeFiles/libbase.dir/LogLevel.cpp.o.provides

CMakeFiles/libbase.dir/LogLevel.cpp.o.provides.build: CMakeFiles/libbase.dir/LogLevel.cpp.o


CMakeFiles/libbase.dir/LogEvent.cpp.o: CMakeFiles/libbase.dir/flags.make
CMakeFiles/libbase.dir/LogEvent.cpp.o: LogEvent.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/interview/MyTinyWeb/base/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/libbase.dir/LogEvent.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/libbase.dir/LogEvent.cpp.o -c /home/interview/MyTinyWeb/base/LogEvent.cpp

CMakeFiles/libbase.dir/LogEvent.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libbase.dir/LogEvent.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/interview/MyTinyWeb/base/LogEvent.cpp > CMakeFiles/libbase.dir/LogEvent.cpp.i

CMakeFiles/libbase.dir/LogEvent.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libbase.dir/LogEvent.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/interview/MyTinyWeb/base/LogEvent.cpp -o CMakeFiles/libbase.dir/LogEvent.cpp.s

CMakeFiles/libbase.dir/LogEvent.cpp.o.requires:

.PHONY : CMakeFiles/libbase.dir/LogEvent.cpp.o.requires

CMakeFiles/libbase.dir/LogEvent.cpp.o.provides: CMakeFiles/libbase.dir/LogEvent.cpp.o.requires
	$(MAKE) -f CMakeFiles/libbase.dir/build.make CMakeFiles/libbase.dir/LogEvent.cpp.o.provides.build
.PHONY : CMakeFiles/libbase.dir/LogEvent.cpp.o.provides

CMakeFiles/libbase.dir/LogEvent.cpp.o.provides.build: CMakeFiles/libbase.dir/LogEvent.cpp.o


CMakeFiles/libbase.dir/LogFormatter.cpp.o: CMakeFiles/libbase.dir/flags.make
CMakeFiles/libbase.dir/LogFormatter.cpp.o: LogFormatter.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/interview/MyTinyWeb/base/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/libbase.dir/LogFormatter.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/libbase.dir/LogFormatter.cpp.o -c /home/interview/MyTinyWeb/base/LogFormatter.cpp

CMakeFiles/libbase.dir/LogFormatter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libbase.dir/LogFormatter.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/interview/MyTinyWeb/base/LogFormatter.cpp > CMakeFiles/libbase.dir/LogFormatter.cpp.i

CMakeFiles/libbase.dir/LogFormatter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libbase.dir/LogFormatter.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/interview/MyTinyWeb/base/LogFormatter.cpp -o CMakeFiles/libbase.dir/LogFormatter.cpp.s

CMakeFiles/libbase.dir/LogFormatter.cpp.o.requires:

.PHONY : CMakeFiles/libbase.dir/LogFormatter.cpp.o.requires

CMakeFiles/libbase.dir/LogFormatter.cpp.o.provides: CMakeFiles/libbase.dir/LogFormatter.cpp.o.requires
	$(MAKE) -f CMakeFiles/libbase.dir/build.make CMakeFiles/libbase.dir/LogFormatter.cpp.o.provides.build
.PHONY : CMakeFiles/libbase.dir/LogFormatter.cpp.o.provides

CMakeFiles/libbase.dir/LogFormatter.cpp.o.provides.build: CMakeFiles/libbase.dir/LogFormatter.cpp.o


CMakeFiles/libbase.dir/FileLogAppender.cpp.o: CMakeFiles/libbase.dir/flags.make
CMakeFiles/libbase.dir/FileLogAppender.cpp.o: FileLogAppender.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/interview/MyTinyWeb/base/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/libbase.dir/FileLogAppender.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/libbase.dir/FileLogAppender.cpp.o -c /home/interview/MyTinyWeb/base/FileLogAppender.cpp

CMakeFiles/libbase.dir/FileLogAppender.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libbase.dir/FileLogAppender.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/interview/MyTinyWeb/base/FileLogAppender.cpp > CMakeFiles/libbase.dir/FileLogAppender.cpp.i

CMakeFiles/libbase.dir/FileLogAppender.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libbase.dir/FileLogAppender.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/interview/MyTinyWeb/base/FileLogAppender.cpp -o CMakeFiles/libbase.dir/FileLogAppender.cpp.s

CMakeFiles/libbase.dir/FileLogAppender.cpp.o.requires:

.PHONY : CMakeFiles/libbase.dir/FileLogAppender.cpp.o.requires

CMakeFiles/libbase.dir/FileLogAppender.cpp.o.provides: CMakeFiles/libbase.dir/FileLogAppender.cpp.o.requires
	$(MAKE) -f CMakeFiles/libbase.dir/build.make CMakeFiles/libbase.dir/FileLogAppender.cpp.o.provides.build
.PHONY : CMakeFiles/libbase.dir/FileLogAppender.cpp.o.provides

CMakeFiles/libbase.dir/FileLogAppender.cpp.o.provides.build: CMakeFiles/libbase.dir/FileLogAppender.cpp.o


CMakeFiles/libbase.dir/LogEventWarp.cpp.o: CMakeFiles/libbase.dir/flags.make
CMakeFiles/libbase.dir/LogEventWarp.cpp.o: LogEventWarp.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/interview/MyTinyWeb/base/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/libbase.dir/LogEventWarp.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/libbase.dir/LogEventWarp.cpp.o -c /home/interview/MyTinyWeb/base/LogEventWarp.cpp

CMakeFiles/libbase.dir/LogEventWarp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libbase.dir/LogEventWarp.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/interview/MyTinyWeb/base/LogEventWarp.cpp > CMakeFiles/libbase.dir/LogEventWarp.cpp.i

CMakeFiles/libbase.dir/LogEventWarp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libbase.dir/LogEventWarp.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/interview/MyTinyWeb/base/LogEventWarp.cpp -o CMakeFiles/libbase.dir/LogEventWarp.cpp.s

CMakeFiles/libbase.dir/LogEventWarp.cpp.o.requires:

.PHONY : CMakeFiles/libbase.dir/LogEventWarp.cpp.o.requires

CMakeFiles/libbase.dir/LogEventWarp.cpp.o.provides: CMakeFiles/libbase.dir/LogEventWarp.cpp.o.requires
	$(MAKE) -f CMakeFiles/libbase.dir/build.make CMakeFiles/libbase.dir/LogEventWarp.cpp.o.provides.build
.PHONY : CMakeFiles/libbase.dir/LogEventWarp.cpp.o.provides

CMakeFiles/libbase.dir/LogEventWarp.cpp.o.provides.build: CMakeFiles/libbase.dir/LogEventWarp.cpp.o


# Object files for target libbase
libbase_OBJECTS = \
"CMakeFiles/libbase.dir/MutexLock.cpp.o" \
"CMakeFiles/libbase.dir/FileUtil.cpp.o" \
"CMakeFiles/libbase.dir/LogFile.cpp.o" \
"CMakeFiles/libbase.dir/Logger.cpp.o" \
"CMakeFiles/libbase.dir/Thread.cpp.o" \
"CMakeFiles/libbase.dir/AsyncLogger.cpp.o" \
"CMakeFiles/libbase.dir/Semaphore.cpp.o" \
"CMakeFiles/libbase.dir/LogLevel.cpp.o" \
"CMakeFiles/libbase.dir/LogEvent.cpp.o" \
"CMakeFiles/libbase.dir/LogFormatter.cpp.o" \
"CMakeFiles/libbase.dir/FileLogAppender.cpp.o" \
"CMakeFiles/libbase.dir/LogEventWarp.cpp.o"

# External object files for target libbase
libbase_EXTERNAL_OBJECTS =

libbase.a: CMakeFiles/libbase.dir/MutexLock.cpp.o
libbase.a: CMakeFiles/libbase.dir/FileUtil.cpp.o
libbase.a: CMakeFiles/libbase.dir/LogFile.cpp.o
libbase.a: CMakeFiles/libbase.dir/Logger.cpp.o
libbase.a: CMakeFiles/libbase.dir/Thread.cpp.o
libbase.a: CMakeFiles/libbase.dir/AsyncLogger.cpp.o
libbase.a: CMakeFiles/libbase.dir/Semaphore.cpp.o
libbase.a: CMakeFiles/libbase.dir/LogLevel.cpp.o
libbase.a: CMakeFiles/libbase.dir/LogEvent.cpp.o
libbase.a: CMakeFiles/libbase.dir/LogFormatter.cpp.o
libbase.a: CMakeFiles/libbase.dir/FileLogAppender.cpp.o
libbase.a: CMakeFiles/libbase.dir/LogEventWarp.cpp.o
libbase.a: CMakeFiles/libbase.dir/build.make
libbase.a: CMakeFiles/libbase.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/interview/MyTinyWeb/base/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Linking CXX static library libbase.a"
	$(CMAKE_COMMAND) -P CMakeFiles/libbase.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/libbase.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/libbase.dir/build: libbase.a

.PHONY : CMakeFiles/libbase.dir/build

CMakeFiles/libbase.dir/requires: CMakeFiles/libbase.dir/MutexLock.cpp.o.requires
CMakeFiles/libbase.dir/requires: CMakeFiles/libbase.dir/FileUtil.cpp.o.requires
CMakeFiles/libbase.dir/requires: CMakeFiles/libbase.dir/LogFile.cpp.o.requires
CMakeFiles/libbase.dir/requires: CMakeFiles/libbase.dir/Logger.cpp.o.requires
CMakeFiles/libbase.dir/requires: CMakeFiles/libbase.dir/Thread.cpp.o.requires
CMakeFiles/libbase.dir/requires: CMakeFiles/libbase.dir/AsyncLogger.cpp.o.requires
CMakeFiles/libbase.dir/requires: CMakeFiles/libbase.dir/Semaphore.cpp.o.requires
CMakeFiles/libbase.dir/requires: CMakeFiles/libbase.dir/LogLevel.cpp.o.requires
CMakeFiles/libbase.dir/requires: CMakeFiles/libbase.dir/LogEvent.cpp.o.requires
CMakeFiles/libbase.dir/requires: CMakeFiles/libbase.dir/LogFormatter.cpp.o.requires
CMakeFiles/libbase.dir/requires: CMakeFiles/libbase.dir/FileLogAppender.cpp.o.requires
CMakeFiles/libbase.dir/requires: CMakeFiles/libbase.dir/LogEventWarp.cpp.o.requires

.PHONY : CMakeFiles/libbase.dir/requires

CMakeFiles/libbase.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/libbase.dir/cmake_clean.cmake
.PHONY : CMakeFiles/libbase.dir/clean

CMakeFiles/libbase.dir/depend:
	cd /home/interview/MyTinyWeb/base && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/interview/MyTinyWeb/base /home/interview/MyTinyWeb/base /home/interview/MyTinyWeb/base /home/interview/MyTinyWeb/base /home/interview/MyTinyWeb/base/CMakeFiles/libbase.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/libbase.dir/depend
