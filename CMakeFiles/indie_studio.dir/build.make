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
CMAKE_SOURCE_DIR = /home/adamier/indie/IndieStudio

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/adamier/indie/IndieStudio

# Include any dependencies generated for this target.
include CMakeFiles/indie_studio.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/indie_studio.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/indie_studio.dir/flags.make

CMakeFiles/indie_studio.dir/src/Bomb.cpp.o: CMakeFiles/indie_studio.dir/flags.make
CMakeFiles/indie_studio.dir/src/Bomb.cpp.o: src/Bomb.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adamier/indie/IndieStudio/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/indie_studio.dir/src/Bomb.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/indie_studio.dir/src/Bomb.cpp.o -c /home/adamier/indie/IndieStudio/src/Bomb.cpp

CMakeFiles/indie_studio.dir/src/Bomb.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/indie_studio.dir/src/Bomb.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adamier/indie/IndieStudio/src/Bomb.cpp > CMakeFiles/indie_studio.dir/src/Bomb.cpp.i

CMakeFiles/indie_studio.dir/src/Bomb.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/indie_studio.dir/src/Bomb.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adamier/indie/IndieStudio/src/Bomb.cpp -o CMakeFiles/indie_studio.dir/src/Bomb.cpp.s

CMakeFiles/indie_studio.dir/src/Bomb.cpp.o.requires:

.PHONY : CMakeFiles/indie_studio.dir/src/Bomb.cpp.o.requires

CMakeFiles/indie_studio.dir/src/Bomb.cpp.o.provides: CMakeFiles/indie_studio.dir/src/Bomb.cpp.o.requires
	$(MAKE) -f CMakeFiles/indie_studio.dir/build.make CMakeFiles/indie_studio.dir/src/Bomb.cpp.o.provides.build
.PHONY : CMakeFiles/indie_studio.dir/src/Bomb.cpp.o.provides

CMakeFiles/indie_studio.dir/src/Bomb.cpp.o.provides.build: CMakeFiles/indie_studio.dir/src/Bomb.cpp.o


CMakeFiles/indie_studio.dir/src/Bomberman.cpp.o: CMakeFiles/indie_studio.dir/flags.make
CMakeFiles/indie_studio.dir/src/Bomberman.cpp.o: src/Bomberman.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adamier/indie/IndieStudio/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/indie_studio.dir/src/Bomberman.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/indie_studio.dir/src/Bomberman.cpp.o -c /home/adamier/indie/IndieStudio/src/Bomberman.cpp

CMakeFiles/indie_studio.dir/src/Bomberman.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/indie_studio.dir/src/Bomberman.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adamier/indie/IndieStudio/src/Bomberman.cpp > CMakeFiles/indie_studio.dir/src/Bomberman.cpp.i

CMakeFiles/indie_studio.dir/src/Bomberman.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/indie_studio.dir/src/Bomberman.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adamier/indie/IndieStudio/src/Bomberman.cpp -o CMakeFiles/indie_studio.dir/src/Bomberman.cpp.s

CMakeFiles/indie_studio.dir/src/Bomberman.cpp.o.requires:

.PHONY : CMakeFiles/indie_studio.dir/src/Bomberman.cpp.o.requires

CMakeFiles/indie_studio.dir/src/Bomberman.cpp.o.provides: CMakeFiles/indie_studio.dir/src/Bomberman.cpp.o.requires
	$(MAKE) -f CMakeFiles/indie_studio.dir/build.make CMakeFiles/indie_studio.dir/src/Bomberman.cpp.o.provides.build
.PHONY : CMakeFiles/indie_studio.dir/src/Bomberman.cpp.o.provides

CMakeFiles/indie_studio.dir/src/Bomberman.cpp.o.provides.build: CMakeFiles/indie_studio.dir/src/Bomberman.cpp.o


CMakeFiles/indie_studio.dir/src/Bomberman_run.cpp.o: CMakeFiles/indie_studio.dir/flags.make
CMakeFiles/indie_studio.dir/src/Bomberman_run.cpp.o: src/Bomberman_run.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adamier/indie/IndieStudio/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/indie_studio.dir/src/Bomberman_run.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/indie_studio.dir/src/Bomberman_run.cpp.o -c /home/adamier/indie/IndieStudio/src/Bomberman_run.cpp

CMakeFiles/indie_studio.dir/src/Bomberman_run.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/indie_studio.dir/src/Bomberman_run.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adamier/indie/IndieStudio/src/Bomberman_run.cpp > CMakeFiles/indie_studio.dir/src/Bomberman_run.cpp.i

CMakeFiles/indie_studio.dir/src/Bomberman_run.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/indie_studio.dir/src/Bomberman_run.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adamier/indie/IndieStudio/src/Bomberman_run.cpp -o CMakeFiles/indie_studio.dir/src/Bomberman_run.cpp.s

CMakeFiles/indie_studio.dir/src/Bomberman_run.cpp.o.requires:

.PHONY : CMakeFiles/indie_studio.dir/src/Bomberman_run.cpp.o.requires

CMakeFiles/indie_studio.dir/src/Bomberman_run.cpp.o.provides: CMakeFiles/indie_studio.dir/src/Bomberman_run.cpp.o.requires
	$(MAKE) -f CMakeFiles/indie_studio.dir/build.make CMakeFiles/indie_studio.dir/src/Bomberman_run.cpp.o.provides.build
.PHONY : CMakeFiles/indie_studio.dir/src/Bomberman_run.cpp.o.provides

CMakeFiles/indie_studio.dir/src/Bomberman_run.cpp.o.provides.build: CMakeFiles/indie_studio.dir/src/Bomberman_run.cpp.o


CMakeFiles/indie_studio.dir/src/Debug.cpp.o: CMakeFiles/indie_studio.dir/flags.make
CMakeFiles/indie_studio.dir/src/Debug.cpp.o: src/Debug.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adamier/indie/IndieStudio/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/indie_studio.dir/src/Debug.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/indie_studio.dir/src/Debug.cpp.o -c /home/adamier/indie/IndieStudio/src/Debug.cpp

CMakeFiles/indie_studio.dir/src/Debug.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/indie_studio.dir/src/Debug.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adamier/indie/IndieStudio/src/Debug.cpp > CMakeFiles/indie_studio.dir/src/Debug.cpp.i

CMakeFiles/indie_studio.dir/src/Debug.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/indie_studio.dir/src/Debug.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adamier/indie/IndieStudio/src/Debug.cpp -o CMakeFiles/indie_studio.dir/src/Debug.cpp.s

CMakeFiles/indie_studio.dir/src/Debug.cpp.o.requires:

.PHONY : CMakeFiles/indie_studio.dir/src/Debug.cpp.o.requires

CMakeFiles/indie_studio.dir/src/Debug.cpp.o.provides: CMakeFiles/indie_studio.dir/src/Debug.cpp.o.requires
	$(MAKE) -f CMakeFiles/indie_studio.dir/build.make CMakeFiles/indie_studio.dir/src/Debug.cpp.o.provides.build
.PHONY : CMakeFiles/indie_studio.dir/src/Debug.cpp.o.provides

CMakeFiles/indie_studio.dir/src/Debug.cpp.o.provides.build: CMakeFiles/indie_studio.dir/src/Debug.cpp.o


CMakeFiles/indie_studio.dir/src/EventListener.cpp.o: CMakeFiles/indie_studio.dir/flags.make
CMakeFiles/indie_studio.dir/src/EventListener.cpp.o: src/EventListener.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adamier/indie/IndieStudio/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/indie_studio.dir/src/EventListener.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/indie_studio.dir/src/EventListener.cpp.o -c /home/adamier/indie/IndieStudio/src/EventListener.cpp

CMakeFiles/indie_studio.dir/src/EventListener.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/indie_studio.dir/src/EventListener.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adamier/indie/IndieStudio/src/EventListener.cpp > CMakeFiles/indie_studio.dir/src/EventListener.cpp.i

CMakeFiles/indie_studio.dir/src/EventListener.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/indie_studio.dir/src/EventListener.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adamier/indie/IndieStudio/src/EventListener.cpp -o CMakeFiles/indie_studio.dir/src/EventListener.cpp.s

CMakeFiles/indie_studio.dir/src/EventListener.cpp.o.requires:

.PHONY : CMakeFiles/indie_studio.dir/src/EventListener.cpp.o.requires

CMakeFiles/indie_studio.dir/src/EventListener.cpp.o.provides: CMakeFiles/indie_studio.dir/src/EventListener.cpp.o.requires
	$(MAKE) -f CMakeFiles/indie_studio.dir/build.make CMakeFiles/indie_studio.dir/src/EventListener.cpp.o.provides.build
.PHONY : CMakeFiles/indie_studio.dir/src/EventListener.cpp.o.provides

CMakeFiles/indie_studio.dir/src/EventListener.cpp.o.provides.build: CMakeFiles/indie_studio.dir/src/EventListener.cpp.o


CMakeFiles/indie_studio.dir/src/Exception.cpp.o: CMakeFiles/indie_studio.dir/flags.make
CMakeFiles/indie_studio.dir/src/Exception.cpp.o: src/Exception.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adamier/indie/IndieStudio/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/indie_studio.dir/src/Exception.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/indie_studio.dir/src/Exception.cpp.o -c /home/adamier/indie/IndieStudio/src/Exception.cpp

CMakeFiles/indie_studio.dir/src/Exception.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/indie_studio.dir/src/Exception.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adamier/indie/IndieStudio/src/Exception.cpp > CMakeFiles/indie_studio.dir/src/Exception.cpp.i

CMakeFiles/indie_studio.dir/src/Exception.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/indie_studio.dir/src/Exception.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adamier/indie/IndieStudio/src/Exception.cpp -o CMakeFiles/indie_studio.dir/src/Exception.cpp.s

CMakeFiles/indie_studio.dir/src/Exception.cpp.o.requires:

.PHONY : CMakeFiles/indie_studio.dir/src/Exception.cpp.o.requires

CMakeFiles/indie_studio.dir/src/Exception.cpp.o.provides: CMakeFiles/indie_studio.dir/src/Exception.cpp.o.requires
	$(MAKE) -f CMakeFiles/indie_studio.dir/build.make CMakeFiles/indie_studio.dir/src/Exception.cpp.o.provides.build
.PHONY : CMakeFiles/indie_studio.dir/src/Exception.cpp.o.provides

CMakeFiles/indie_studio.dir/src/Exception.cpp.o.provides.build: CMakeFiles/indie_studio.dir/src/Exception.cpp.o


CMakeFiles/indie_studio.dir/src/IGUI.cpp.o: CMakeFiles/indie_studio.dir/flags.make
CMakeFiles/indie_studio.dir/src/IGUI.cpp.o: src/IGUI.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adamier/indie/IndieStudio/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/indie_studio.dir/src/IGUI.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/indie_studio.dir/src/IGUI.cpp.o -c /home/adamier/indie/IndieStudio/src/IGUI.cpp

CMakeFiles/indie_studio.dir/src/IGUI.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/indie_studio.dir/src/IGUI.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adamier/indie/IndieStudio/src/IGUI.cpp > CMakeFiles/indie_studio.dir/src/IGUI.cpp.i

CMakeFiles/indie_studio.dir/src/IGUI.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/indie_studio.dir/src/IGUI.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adamier/indie/IndieStudio/src/IGUI.cpp -o CMakeFiles/indie_studio.dir/src/IGUI.cpp.s

CMakeFiles/indie_studio.dir/src/IGUI.cpp.o.requires:

.PHONY : CMakeFiles/indie_studio.dir/src/IGUI.cpp.o.requires

CMakeFiles/indie_studio.dir/src/IGUI.cpp.o.provides: CMakeFiles/indie_studio.dir/src/IGUI.cpp.o.requires
	$(MAKE) -f CMakeFiles/indie_studio.dir/build.make CMakeFiles/indie_studio.dir/src/IGUI.cpp.o.provides.build
.PHONY : CMakeFiles/indie_studio.dir/src/IGUI.cpp.o.provides

CMakeFiles/indie_studio.dir/src/IGUI.cpp.o.provides.build: CMakeFiles/indie_studio.dir/src/IGUI.cpp.o


CMakeFiles/indie_studio.dir/src/main.cpp.o: CMakeFiles/indie_studio.dir/flags.make
CMakeFiles/indie_studio.dir/src/main.cpp.o: src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adamier/indie/IndieStudio/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/indie_studio.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/indie_studio.dir/src/main.cpp.o -c /home/adamier/indie/IndieStudio/src/main.cpp

CMakeFiles/indie_studio.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/indie_studio.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adamier/indie/IndieStudio/src/main.cpp > CMakeFiles/indie_studio.dir/src/main.cpp.i

CMakeFiles/indie_studio.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/indie_studio.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adamier/indie/IndieStudio/src/main.cpp -o CMakeFiles/indie_studio.dir/src/main.cpp.s

CMakeFiles/indie_studio.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/indie_studio.dir/src/main.cpp.o.requires

CMakeFiles/indie_studio.dir/src/main.cpp.o.provides: CMakeFiles/indie_studio.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/indie_studio.dir/build.make CMakeFiles/indie_studio.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/indie_studio.dir/src/main.cpp.o.provides

CMakeFiles/indie_studio.dir/src/main.cpp.o.provides.build: CMakeFiles/indie_studio.dir/src/main.cpp.o


CMakeFiles/indie_studio.dir/src/Player.cpp.o: CMakeFiles/indie_studio.dir/flags.make
CMakeFiles/indie_studio.dir/src/Player.cpp.o: src/Player.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adamier/indie/IndieStudio/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/indie_studio.dir/src/Player.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/indie_studio.dir/src/Player.cpp.o -c /home/adamier/indie/IndieStudio/src/Player.cpp

CMakeFiles/indie_studio.dir/src/Player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/indie_studio.dir/src/Player.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adamier/indie/IndieStudio/src/Player.cpp > CMakeFiles/indie_studio.dir/src/Player.cpp.i

CMakeFiles/indie_studio.dir/src/Player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/indie_studio.dir/src/Player.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adamier/indie/IndieStudio/src/Player.cpp -o CMakeFiles/indie_studio.dir/src/Player.cpp.s

CMakeFiles/indie_studio.dir/src/Player.cpp.o.requires:

.PHONY : CMakeFiles/indie_studio.dir/src/Player.cpp.o.requires

CMakeFiles/indie_studio.dir/src/Player.cpp.o.provides: CMakeFiles/indie_studio.dir/src/Player.cpp.o.requires
	$(MAKE) -f CMakeFiles/indie_studio.dir/build.make CMakeFiles/indie_studio.dir/src/Player.cpp.o.provides.build
.PHONY : CMakeFiles/indie_studio.dir/src/Player.cpp.o.provides

CMakeFiles/indie_studio.dir/src/Player.cpp.o.provides.build: CMakeFiles/indie_studio.dir/src/Player.cpp.o


CMakeFiles/indie_studio.dir/src/Menu.cpp.o: CMakeFiles/indie_studio.dir/flags.make
CMakeFiles/indie_studio.dir/src/Menu.cpp.o: src/Menu.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adamier/indie/IndieStudio/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/indie_studio.dir/src/Menu.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/indie_studio.dir/src/Menu.cpp.o -c /home/adamier/indie/IndieStudio/src/Menu.cpp

CMakeFiles/indie_studio.dir/src/Menu.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/indie_studio.dir/src/Menu.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adamier/indie/IndieStudio/src/Menu.cpp > CMakeFiles/indie_studio.dir/src/Menu.cpp.i

CMakeFiles/indie_studio.dir/src/Menu.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/indie_studio.dir/src/Menu.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adamier/indie/IndieStudio/src/Menu.cpp -o CMakeFiles/indie_studio.dir/src/Menu.cpp.s

CMakeFiles/indie_studio.dir/src/Menu.cpp.o.requires:

.PHONY : CMakeFiles/indie_studio.dir/src/Menu.cpp.o.requires

CMakeFiles/indie_studio.dir/src/Menu.cpp.o.provides: CMakeFiles/indie_studio.dir/src/Menu.cpp.o.requires
	$(MAKE) -f CMakeFiles/indie_studio.dir/build.make CMakeFiles/indie_studio.dir/src/Menu.cpp.o.provides.build
.PHONY : CMakeFiles/indie_studio.dir/src/Menu.cpp.o.provides

CMakeFiles/indie_studio.dir/src/Menu.cpp.o.provides.build: CMakeFiles/indie_studio.dir/src/Menu.cpp.o


CMakeFiles/indie_studio.dir/src/Option.cpp.o: CMakeFiles/indie_studio.dir/flags.make
CMakeFiles/indie_studio.dir/src/Option.cpp.o: src/Option.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adamier/indie/IndieStudio/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/indie_studio.dir/src/Option.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/indie_studio.dir/src/Option.cpp.o -c /home/adamier/indie/IndieStudio/src/Option.cpp

CMakeFiles/indie_studio.dir/src/Option.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/indie_studio.dir/src/Option.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adamier/indie/IndieStudio/src/Option.cpp > CMakeFiles/indie_studio.dir/src/Option.cpp.i

CMakeFiles/indie_studio.dir/src/Option.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/indie_studio.dir/src/Option.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adamier/indie/IndieStudio/src/Option.cpp -o CMakeFiles/indie_studio.dir/src/Option.cpp.s

CMakeFiles/indie_studio.dir/src/Option.cpp.o.requires:

.PHONY : CMakeFiles/indie_studio.dir/src/Option.cpp.o.requires

CMakeFiles/indie_studio.dir/src/Option.cpp.o.provides: CMakeFiles/indie_studio.dir/src/Option.cpp.o.requires
	$(MAKE) -f CMakeFiles/indie_studio.dir/build.make CMakeFiles/indie_studio.dir/src/Option.cpp.o.provides.build
.PHONY : CMakeFiles/indie_studio.dir/src/Option.cpp.o.provides

CMakeFiles/indie_studio.dir/src/Option.cpp.o.provides.build: CMakeFiles/indie_studio.dir/src/Option.cpp.o


CMakeFiles/indie_studio.dir/src/GameGUI.cpp.o: CMakeFiles/indie_studio.dir/flags.make
CMakeFiles/indie_studio.dir/src/GameGUI.cpp.o: src/GameGUI.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adamier/indie/IndieStudio/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/indie_studio.dir/src/GameGUI.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/indie_studio.dir/src/GameGUI.cpp.o -c /home/adamier/indie/IndieStudio/src/GameGUI.cpp

CMakeFiles/indie_studio.dir/src/GameGUI.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/indie_studio.dir/src/GameGUI.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adamier/indie/IndieStudio/src/GameGUI.cpp > CMakeFiles/indie_studio.dir/src/GameGUI.cpp.i

CMakeFiles/indie_studio.dir/src/GameGUI.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/indie_studio.dir/src/GameGUI.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adamier/indie/IndieStudio/src/GameGUI.cpp -o CMakeFiles/indie_studio.dir/src/GameGUI.cpp.s

CMakeFiles/indie_studio.dir/src/GameGUI.cpp.o.requires:

.PHONY : CMakeFiles/indie_studio.dir/src/GameGUI.cpp.o.requires

CMakeFiles/indie_studio.dir/src/GameGUI.cpp.o.provides: CMakeFiles/indie_studio.dir/src/GameGUI.cpp.o.requires
	$(MAKE) -f CMakeFiles/indie_studio.dir/build.make CMakeFiles/indie_studio.dir/src/GameGUI.cpp.o.provides.build
.PHONY : CMakeFiles/indie_studio.dir/src/GameGUI.cpp.o.provides

CMakeFiles/indie_studio.dir/src/GameGUI.cpp.o.provides.build: CMakeFiles/indie_studio.dir/src/GameGUI.cpp.o


CMakeFiles/indie_studio.dir/src/SceneManager.cpp.o: CMakeFiles/indie_studio.dir/flags.make
CMakeFiles/indie_studio.dir/src/SceneManager.cpp.o: src/SceneManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adamier/indie/IndieStudio/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/indie_studio.dir/src/SceneManager.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/indie_studio.dir/src/SceneManager.cpp.o -c /home/adamier/indie/IndieStudio/src/SceneManager.cpp

CMakeFiles/indie_studio.dir/src/SceneManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/indie_studio.dir/src/SceneManager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adamier/indie/IndieStudio/src/SceneManager.cpp > CMakeFiles/indie_studio.dir/src/SceneManager.cpp.i

CMakeFiles/indie_studio.dir/src/SceneManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/indie_studio.dir/src/SceneManager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adamier/indie/IndieStudio/src/SceneManager.cpp -o CMakeFiles/indie_studio.dir/src/SceneManager.cpp.s

CMakeFiles/indie_studio.dir/src/SceneManager.cpp.o.requires:

.PHONY : CMakeFiles/indie_studio.dir/src/SceneManager.cpp.o.requires

CMakeFiles/indie_studio.dir/src/SceneManager.cpp.o.provides: CMakeFiles/indie_studio.dir/src/SceneManager.cpp.o.requires
	$(MAKE) -f CMakeFiles/indie_studio.dir/build.make CMakeFiles/indie_studio.dir/src/SceneManager.cpp.o.provides.build
.PHONY : CMakeFiles/indie_studio.dir/src/SceneManager.cpp.o.provides

CMakeFiles/indie_studio.dir/src/SceneManager.cpp.o.provides.build: CMakeFiles/indie_studio.dir/src/SceneManager.cpp.o


CMakeFiles/indie_studio.dir/src/Renderer.cpp.o: CMakeFiles/indie_studio.dir/flags.make
CMakeFiles/indie_studio.dir/src/Renderer.cpp.o: src/Renderer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adamier/indie/IndieStudio/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/indie_studio.dir/src/Renderer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/indie_studio.dir/src/Renderer.cpp.o -c /home/adamier/indie/IndieStudio/src/Renderer.cpp

CMakeFiles/indie_studio.dir/src/Renderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/indie_studio.dir/src/Renderer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adamier/indie/IndieStudio/src/Renderer.cpp > CMakeFiles/indie_studio.dir/src/Renderer.cpp.i

CMakeFiles/indie_studio.dir/src/Renderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/indie_studio.dir/src/Renderer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adamier/indie/IndieStudio/src/Renderer.cpp -o CMakeFiles/indie_studio.dir/src/Renderer.cpp.s

CMakeFiles/indie_studio.dir/src/Renderer.cpp.o.requires:

.PHONY : CMakeFiles/indie_studio.dir/src/Renderer.cpp.o.requires

CMakeFiles/indie_studio.dir/src/Renderer.cpp.o.provides: CMakeFiles/indie_studio.dir/src/Renderer.cpp.o.requires
	$(MAKE) -f CMakeFiles/indie_studio.dir/build.make CMakeFiles/indie_studio.dir/src/Renderer.cpp.o.provides.build
.PHONY : CMakeFiles/indie_studio.dir/src/Renderer.cpp.o.provides

CMakeFiles/indie_studio.dir/src/Renderer.cpp.o.provides.build: CMakeFiles/indie_studio.dir/src/Renderer.cpp.o


CMakeFiles/indie_studio.dir/src/Map.cpp.o: CMakeFiles/indie_studio.dir/flags.make
CMakeFiles/indie_studio.dir/src/Map.cpp.o: src/Map.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adamier/indie/IndieStudio/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/indie_studio.dir/src/Map.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/indie_studio.dir/src/Map.cpp.o -c /home/adamier/indie/IndieStudio/src/Map.cpp

CMakeFiles/indie_studio.dir/src/Map.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/indie_studio.dir/src/Map.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adamier/indie/IndieStudio/src/Map.cpp > CMakeFiles/indie_studio.dir/src/Map.cpp.i

CMakeFiles/indie_studio.dir/src/Map.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/indie_studio.dir/src/Map.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adamier/indie/IndieStudio/src/Map.cpp -o CMakeFiles/indie_studio.dir/src/Map.cpp.s

CMakeFiles/indie_studio.dir/src/Map.cpp.o.requires:

.PHONY : CMakeFiles/indie_studio.dir/src/Map.cpp.o.requires

CMakeFiles/indie_studio.dir/src/Map.cpp.o.provides: CMakeFiles/indie_studio.dir/src/Map.cpp.o.requires
	$(MAKE) -f CMakeFiles/indie_studio.dir/build.make CMakeFiles/indie_studio.dir/src/Map.cpp.o.provides.build
.PHONY : CMakeFiles/indie_studio.dir/src/Map.cpp.o.provides

CMakeFiles/indie_studio.dir/src/Map.cpp.o.provides.build: CMakeFiles/indie_studio.dir/src/Map.cpp.o


CMakeFiles/indie_studio.dir/src/Splash.cpp.o: CMakeFiles/indie_studio.dir/flags.make
CMakeFiles/indie_studio.dir/src/Splash.cpp.o: src/Splash.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adamier/indie/IndieStudio/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object CMakeFiles/indie_studio.dir/src/Splash.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/indie_studio.dir/src/Splash.cpp.o -c /home/adamier/indie/IndieStudio/src/Splash.cpp

CMakeFiles/indie_studio.dir/src/Splash.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/indie_studio.dir/src/Splash.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adamier/indie/IndieStudio/src/Splash.cpp > CMakeFiles/indie_studio.dir/src/Splash.cpp.i

CMakeFiles/indie_studio.dir/src/Splash.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/indie_studio.dir/src/Splash.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adamier/indie/IndieStudio/src/Splash.cpp -o CMakeFiles/indie_studio.dir/src/Splash.cpp.s

CMakeFiles/indie_studio.dir/src/Splash.cpp.o.requires:

.PHONY : CMakeFiles/indie_studio.dir/src/Splash.cpp.o.requires

CMakeFiles/indie_studio.dir/src/Splash.cpp.o.provides: CMakeFiles/indie_studio.dir/src/Splash.cpp.o.requires
	$(MAKE) -f CMakeFiles/indie_studio.dir/build.make CMakeFiles/indie_studio.dir/src/Splash.cpp.o.provides.build
.PHONY : CMakeFiles/indie_studio.dir/src/Splash.cpp.o.provides

CMakeFiles/indie_studio.dir/src/Splash.cpp.o.provides.build: CMakeFiles/indie_studio.dir/src/Splash.cpp.o


CMakeFiles/indie_studio.dir/src/Flame.cpp.o: CMakeFiles/indie_studio.dir/flags.make
CMakeFiles/indie_studio.dir/src/Flame.cpp.o: src/Flame.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adamier/indie/IndieStudio/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building CXX object CMakeFiles/indie_studio.dir/src/Flame.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/indie_studio.dir/src/Flame.cpp.o -c /home/adamier/indie/IndieStudio/src/Flame.cpp

CMakeFiles/indie_studio.dir/src/Flame.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/indie_studio.dir/src/Flame.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adamier/indie/IndieStudio/src/Flame.cpp > CMakeFiles/indie_studio.dir/src/Flame.cpp.i

CMakeFiles/indie_studio.dir/src/Flame.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/indie_studio.dir/src/Flame.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adamier/indie/IndieStudio/src/Flame.cpp -o CMakeFiles/indie_studio.dir/src/Flame.cpp.s

CMakeFiles/indie_studio.dir/src/Flame.cpp.o.requires:

.PHONY : CMakeFiles/indie_studio.dir/src/Flame.cpp.o.requires

CMakeFiles/indie_studio.dir/src/Flame.cpp.o.provides: CMakeFiles/indie_studio.dir/src/Flame.cpp.o.requires
	$(MAKE) -f CMakeFiles/indie_studio.dir/build.make CMakeFiles/indie_studio.dir/src/Flame.cpp.o.provides.build
.PHONY : CMakeFiles/indie_studio.dir/src/Flame.cpp.o.provides

CMakeFiles/indie_studio.dir/src/Flame.cpp.o.provides.build: CMakeFiles/indie_studio.dir/src/Flame.cpp.o


# Object files for target indie_studio
indie_studio_OBJECTS = \
"CMakeFiles/indie_studio.dir/src/Bomb.cpp.o" \
"CMakeFiles/indie_studio.dir/src/Bomberman.cpp.o" \
"CMakeFiles/indie_studio.dir/src/Bomberman_run.cpp.o" \
"CMakeFiles/indie_studio.dir/src/Debug.cpp.o" \
"CMakeFiles/indie_studio.dir/src/EventListener.cpp.o" \
"CMakeFiles/indie_studio.dir/src/Exception.cpp.o" \
"CMakeFiles/indie_studio.dir/src/IGUI.cpp.o" \
"CMakeFiles/indie_studio.dir/src/main.cpp.o" \
"CMakeFiles/indie_studio.dir/src/Player.cpp.o" \
"CMakeFiles/indie_studio.dir/src/Menu.cpp.o" \
"CMakeFiles/indie_studio.dir/src/Option.cpp.o" \
"CMakeFiles/indie_studio.dir/src/GameGUI.cpp.o" \
"CMakeFiles/indie_studio.dir/src/SceneManager.cpp.o" \
"CMakeFiles/indie_studio.dir/src/Renderer.cpp.o" \
"CMakeFiles/indie_studio.dir/src/Map.cpp.o" \
"CMakeFiles/indie_studio.dir/src/Splash.cpp.o" \
"CMakeFiles/indie_studio.dir/src/Flame.cpp.o"

# External object files for target indie_studio
indie_studio_EXTERNAL_OBJECTS =

indie_studio: CMakeFiles/indie_studio.dir/src/Bomb.cpp.o
indie_studio: CMakeFiles/indie_studio.dir/src/Bomberman.cpp.o
indie_studio: CMakeFiles/indie_studio.dir/src/Bomberman_run.cpp.o
indie_studio: CMakeFiles/indie_studio.dir/src/Debug.cpp.o
indie_studio: CMakeFiles/indie_studio.dir/src/EventListener.cpp.o
indie_studio: CMakeFiles/indie_studio.dir/src/Exception.cpp.o
indie_studio: CMakeFiles/indie_studio.dir/src/IGUI.cpp.o
indie_studio: CMakeFiles/indie_studio.dir/src/main.cpp.o
indie_studio: CMakeFiles/indie_studio.dir/src/Player.cpp.o
indie_studio: CMakeFiles/indie_studio.dir/src/Menu.cpp.o
indie_studio: CMakeFiles/indie_studio.dir/src/Option.cpp.o
indie_studio: CMakeFiles/indie_studio.dir/src/GameGUI.cpp.o
indie_studio: CMakeFiles/indie_studio.dir/src/SceneManager.cpp.o
indie_studio: CMakeFiles/indie_studio.dir/src/Renderer.cpp.o
indie_studio: CMakeFiles/indie_studio.dir/src/Map.cpp.o
indie_studio: CMakeFiles/indie_studio.dir/src/Splash.cpp.o
indie_studio: CMakeFiles/indie_studio.dir/src/Flame.cpp.o
indie_studio: CMakeFiles/indie_studio.dir/build.make
indie_studio: CMakeFiles/indie_studio.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/adamier/indie/IndieStudio/CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Linking CXX executable indie_studio"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/indie_studio.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/indie_studio.dir/build: indie_studio

.PHONY : CMakeFiles/indie_studio.dir/build

CMakeFiles/indie_studio.dir/requires: CMakeFiles/indie_studio.dir/src/Bomb.cpp.o.requires
CMakeFiles/indie_studio.dir/requires: CMakeFiles/indie_studio.dir/src/Bomberman.cpp.o.requires
CMakeFiles/indie_studio.dir/requires: CMakeFiles/indie_studio.dir/src/Bomberman_run.cpp.o.requires
CMakeFiles/indie_studio.dir/requires: CMakeFiles/indie_studio.dir/src/Debug.cpp.o.requires
CMakeFiles/indie_studio.dir/requires: CMakeFiles/indie_studio.dir/src/EventListener.cpp.o.requires
CMakeFiles/indie_studio.dir/requires: CMakeFiles/indie_studio.dir/src/Exception.cpp.o.requires
CMakeFiles/indie_studio.dir/requires: CMakeFiles/indie_studio.dir/src/IGUI.cpp.o.requires
CMakeFiles/indie_studio.dir/requires: CMakeFiles/indie_studio.dir/src/main.cpp.o.requires
CMakeFiles/indie_studio.dir/requires: CMakeFiles/indie_studio.dir/src/Player.cpp.o.requires
CMakeFiles/indie_studio.dir/requires: CMakeFiles/indie_studio.dir/src/Menu.cpp.o.requires
CMakeFiles/indie_studio.dir/requires: CMakeFiles/indie_studio.dir/src/Option.cpp.o.requires
CMakeFiles/indie_studio.dir/requires: CMakeFiles/indie_studio.dir/src/GameGUI.cpp.o.requires
CMakeFiles/indie_studio.dir/requires: CMakeFiles/indie_studio.dir/src/SceneManager.cpp.o.requires
CMakeFiles/indie_studio.dir/requires: CMakeFiles/indie_studio.dir/src/Renderer.cpp.o.requires
CMakeFiles/indie_studio.dir/requires: CMakeFiles/indie_studio.dir/src/Map.cpp.o.requires
CMakeFiles/indie_studio.dir/requires: CMakeFiles/indie_studio.dir/src/Splash.cpp.o.requires
CMakeFiles/indie_studio.dir/requires: CMakeFiles/indie_studio.dir/src/Flame.cpp.o.requires

.PHONY : CMakeFiles/indie_studio.dir/requires

CMakeFiles/indie_studio.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/indie_studio.dir/cmake_clean.cmake
.PHONY : CMakeFiles/indie_studio.dir/clean

CMakeFiles/indie_studio.dir/depend:
	cd /home/adamier/indie/IndieStudio && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/adamier/indie/IndieStudio /home/adamier/indie/IndieStudio /home/adamier/indie/IndieStudio /home/adamier/indie/IndieStudio /home/adamier/indie/IndieStudio/CMakeFiles/indie_studio.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/indie_studio.dir/depend
