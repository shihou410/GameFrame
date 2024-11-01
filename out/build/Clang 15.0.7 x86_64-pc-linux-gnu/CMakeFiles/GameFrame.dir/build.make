# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /root/myGame/GameFrame

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/root/myGame/GameFrame/out/build/Clang 15.0.7 x86_64-pc-linux-gnu"

# Include any dependencies generated for this target.
include CMakeFiles/GameFrame.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/GameFrame.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/GameFrame.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/GameFrame.dir/flags.make

CMakeFiles/GameFrame.dir/src/Animation.cpp.o: CMakeFiles/GameFrame.dir/flags.make
CMakeFiles/GameFrame.dir/src/Animation.cpp.o: ../../../src/Animation.cpp
CMakeFiles/GameFrame.dir/src/Animation.cpp.o: CMakeFiles/GameFrame.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/root/myGame/GameFrame/out/build/Clang 15.0.7 x86_64-pc-linux-gnu/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/GameFrame.dir/src/Animation.cpp.o"
	/usr/bin/clang++-15 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/GameFrame.dir/src/Animation.cpp.o -MF CMakeFiles/GameFrame.dir/src/Animation.cpp.o.d -o CMakeFiles/GameFrame.dir/src/Animation.cpp.o -c /root/myGame/GameFrame/src/Animation.cpp

CMakeFiles/GameFrame.dir/src/Animation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GameFrame.dir/src/Animation.cpp.i"
	/usr/bin/clang++-15 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/myGame/GameFrame/src/Animation.cpp > CMakeFiles/GameFrame.dir/src/Animation.cpp.i

CMakeFiles/GameFrame.dir/src/Animation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GameFrame.dir/src/Animation.cpp.s"
	/usr/bin/clang++-15 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/myGame/GameFrame/src/Animation.cpp -o CMakeFiles/GameFrame.dir/src/Animation.cpp.s

CMakeFiles/GameFrame.dir/src/Game.cpp.o: CMakeFiles/GameFrame.dir/flags.make
CMakeFiles/GameFrame.dir/src/Game.cpp.o: ../../../src/Game.cpp
CMakeFiles/GameFrame.dir/src/Game.cpp.o: CMakeFiles/GameFrame.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/root/myGame/GameFrame/out/build/Clang 15.0.7 x86_64-pc-linux-gnu/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/GameFrame.dir/src/Game.cpp.o"
	/usr/bin/clang++-15 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/GameFrame.dir/src/Game.cpp.o -MF CMakeFiles/GameFrame.dir/src/Game.cpp.o.d -o CMakeFiles/GameFrame.dir/src/Game.cpp.o -c /root/myGame/GameFrame/src/Game.cpp

CMakeFiles/GameFrame.dir/src/Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GameFrame.dir/src/Game.cpp.i"
	/usr/bin/clang++-15 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/myGame/GameFrame/src/Game.cpp > CMakeFiles/GameFrame.dir/src/Game.cpp.i

CMakeFiles/GameFrame.dir/src/Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GameFrame.dir/src/Game.cpp.s"
	/usr/bin/clang++-15 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/myGame/GameFrame/src/Game.cpp -o CMakeFiles/GameFrame.dir/src/Game.cpp.s

CMakeFiles/GameFrame.dir/src/GameCamera.cpp.o: CMakeFiles/GameFrame.dir/flags.make
CMakeFiles/GameFrame.dir/src/GameCamera.cpp.o: ../../../src/GameCamera.cpp
CMakeFiles/GameFrame.dir/src/GameCamera.cpp.o: CMakeFiles/GameFrame.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/root/myGame/GameFrame/out/build/Clang 15.0.7 x86_64-pc-linux-gnu/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/GameFrame.dir/src/GameCamera.cpp.o"
	/usr/bin/clang++-15 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/GameFrame.dir/src/GameCamera.cpp.o -MF CMakeFiles/GameFrame.dir/src/GameCamera.cpp.o.d -o CMakeFiles/GameFrame.dir/src/GameCamera.cpp.o -c /root/myGame/GameFrame/src/GameCamera.cpp

CMakeFiles/GameFrame.dir/src/GameCamera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GameFrame.dir/src/GameCamera.cpp.i"
	/usr/bin/clang++-15 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/myGame/GameFrame/src/GameCamera.cpp > CMakeFiles/GameFrame.dir/src/GameCamera.cpp.i

CMakeFiles/GameFrame.dir/src/GameCamera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GameFrame.dir/src/GameCamera.cpp.s"
	/usr/bin/clang++-15 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/myGame/GameFrame/src/GameCamera.cpp -o CMakeFiles/GameFrame.dir/src/GameCamera.cpp.s

CMakeFiles/GameFrame.dir/src/GameEntity.cpp.o: CMakeFiles/GameFrame.dir/flags.make
CMakeFiles/GameFrame.dir/src/GameEntity.cpp.o: ../../../src/GameEntity.cpp
CMakeFiles/GameFrame.dir/src/GameEntity.cpp.o: CMakeFiles/GameFrame.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/root/myGame/GameFrame/out/build/Clang 15.0.7 x86_64-pc-linux-gnu/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/GameFrame.dir/src/GameEntity.cpp.o"
	/usr/bin/clang++-15 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/GameFrame.dir/src/GameEntity.cpp.o -MF CMakeFiles/GameFrame.dir/src/GameEntity.cpp.o.d -o CMakeFiles/GameFrame.dir/src/GameEntity.cpp.o -c /root/myGame/GameFrame/src/GameEntity.cpp

CMakeFiles/GameFrame.dir/src/GameEntity.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GameFrame.dir/src/GameEntity.cpp.i"
	/usr/bin/clang++-15 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/myGame/GameFrame/src/GameEntity.cpp > CMakeFiles/GameFrame.dir/src/GameEntity.cpp.i

CMakeFiles/GameFrame.dir/src/GameEntity.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GameFrame.dir/src/GameEntity.cpp.s"
	/usr/bin/clang++-15 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/myGame/GameFrame/src/GameEntity.cpp -o CMakeFiles/GameFrame.dir/src/GameEntity.cpp.s

CMakeFiles/GameFrame.dir/src/GameMap.cpp.o: CMakeFiles/GameFrame.dir/flags.make
CMakeFiles/GameFrame.dir/src/GameMap.cpp.o: ../../../src/GameMap.cpp
CMakeFiles/GameFrame.dir/src/GameMap.cpp.o: CMakeFiles/GameFrame.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/root/myGame/GameFrame/out/build/Clang 15.0.7 x86_64-pc-linux-gnu/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/GameFrame.dir/src/GameMap.cpp.o"
	/usr/bin/clang++-15 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/GameFrame.dir/src/GameMap.cpp.o -MF CMakeFiles/GameFrame.dir/src/GameMap.cpp.o.d -o CMakeFiles/GameFrame.dir/src/GameMap.cpp.o -c /root/myGame/GameFrame/src/GameMap.cpp

CMakeFiles/GameFrame.dir/src/GameMap.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GameFrame.dir/src/GameMap.cpp.i"
	/usr/bin/clang++-15 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/myGame/GameFrame/src/GameMap.cpp > CMakeFiles/GameFrame.dir/src/GameMap.cpp.i

CMakeFiles/GameFrame.dir/src/GameMap.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GameFrame.dir/src/GameMap.cpp.s"
	/usr/bin/clang++-15 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/myGame/GameFrame/src/GameMap.cpp -o CMakeFiles/GameFrame.dir/src/GameMap.cpp.s

CMakeFiles/GameFrame.dir/src/MgrAnima.cpp.o: CMakeFiles/GameFrame.dir/flags.make
CMakeFiles/GameFrame.dir/src/MgrAnima.cpp.o: ../../../src/MgrAnima.cpp
CMakeFiles/GameFrame.dir/src/MgrAnima.cpp.o: CMakeFiles/GameFrame.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/root/myGame/GameFrame/out/build/Clang 15.0.7 x86_64-pc-linux-gnu/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/GameFrame.dir/src/MgrAnima.cpp.o"
	/usr/bin/clang++-15 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/GameFrame.dir/src/MgrAnima.cpp.o -MF CMakeFiles/GameFrame.dir/src/MgrAnima.cpp.o.d -o CMakeFiles/GameFrame.dir/src/MgrAnima.cpp.o -c /root/myGame/GameFrame/src/MgrAnima.cpp

CMakeFiles/GameFrame.dir/src/MgrAnima.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GameFrame.dir/src/MgrAnima.cpp.i"
	/usr/bin/clang++-15 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/myGame/GameFrame/src/MgrAnima.cpp > CMakeFiles/GameFrame.dir/src/MgrAnima.cpp.i

CMakeFiles/GameFrame.dir/src/MgrAnima.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GameFrame.dir/src/MgrAnima.cpp.s"
	/usr/bin/clang++-15 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/myGame/GameFrame/src/MgrAnima.cpp -o CMakeFiles/GameFrame.dir/src/MgrAnima.cpp.s

CMakeFiles/GameFrame.dir/src/MgrEntity.cpp.o: CMakeFiles/GameFrame.dir/flags.make
CMakeFiles/GameFrame.dir/src/MgrEntity.cpp.o: ../../../src/MgrEntity.cpp
CMakeFiles/GameFrame.dir/src/MgrEntity.cpp.o: CMakeFiles/GameFrame.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/root/myGame/GameFrame/out/build/Clang 15.0.7 x86_64-pc-linux-gnu/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/GameFrame.dir/src/MgrEntity.cpp.o"
	/usr/bin/clang++-15 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/GameFrame.dir/src/MgrEntity.cpp.o -MF CMakeFiles/GameFrame.dir/src/MgrEntity.cpp.o.d -o CMakeFiles/GameFrame.dir/src/MgrEntity.cpp.o -c /root/myGame/GameFrame/src/MgrEntity.cpp

CMakeFiles/GameFrame.dir/src/MgrEntity.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GameFrame.dir/src/MgrEntity.cpp.i"
	/usr/bin/clang++-15 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/myGame/GameFrame/src/MgrEntity.cpp > CMakeFiles/GameFrame.dir/src/MgrEntity.cpp.i

CMakeFiles/GameFrame.dir/src/MgrEntity.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GameFrame.dir/src/MgrEntity.cpp.s"
	/usr/bin/clang++-15 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/myGame/GameFrame/src/MgrEntity.cpp -o CMakeFiles/GameFrame.dir/src/MgrEntity.cpp.s

CMakeFiles/GameFrame.dir/src/MgrInput.cpp.o: CMakeFiles/GameFrame.dir/flags.make
CMakeFiles/GameFrame.dir/src/MgrInput.cpp.o: ../../../src/MgrInput.cpp
CMakeFiles/GameFrame.dir/src/MgrInput.cpp.o: CMakeFiles/GameFrame.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/root/myGame/GameFrame/out/build/Clang 15.0.7 x86_64-pc-linux-gnu/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/GameFrame.dir/src/MgrInput.cpp.o"
	/usr/bin/clang++-15 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/GameFrame.dir/src/MgrInput.cpp.o -MF CMakeFiles/GameFrame.dir/src/MgrInput.cpp.o.d -o CMakeFiles/GameFrame.dir/src/MgrInput.cpp.o -c /root/myGame/GameFrame/src/MgrInput.cpp

CMakeFiles/GameFrame.dir/src/MgrInput.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GameFrame.dir/src/MgrInput.cpp.i"
	/usr/bin/clang++-15 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/myGame/GameFrame/src/MgrInput.cpp > CMakeFiles/GameFrame.dir/src/MgrInput.cpp.i

CMakeFiles/GameFrame.dir/src/MgrInput.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GameFrame.dir/src/MgrInput.cpp.s"
	/usr/bin/clang++-15 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/myGame/GameFrame/src/MgrInput.cpp -o CMakeFiles/GameFrame.dir/src/MgrInput.cpp.s

CMakeFiles/GameFrame.dir/src/MgrMap.cpp.o: CMakeFiles/GameFrame.dir/flags.make
CMakeFiles/GameFrame.dir/src/MgrMap.cpp.o: ../../../src/MgrMap.cpp
CMakeFiles/GameFrame.dir/src/MgrMap.cpp.o: CMakeFiles/GameFrame.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/root/myGame/GameFrame/out/build/Clang 15.0.7 x86_64-pc-linux-gnu/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/GameFrame.dir/src/MgrMap.cpp.o"
	/usr/bin/clang++-15 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/GameFrame.dir/src/MgrMap.cpp.o -MF CMakeFiles/GameFrame.dir/src/MgrMap.cpp.o.d -o CMakeFiles/GameFrame.dir/src/MgrMap.cpp.o -c /root/myGame/GameFrame/src/MgrMap.cpp

CMakeFiles/GameFrame.dir/src/MgrMap.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GameFrame.dir/src/MgrMap.cpp.i"
	/usr/bin/clang++-15 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/myGame/GameFrame/src/MgrMap.cpp > CMakeFiles/GameFrame.dir/src/MgrMap.cpp.i

CMakeFiles/GameFrame.dir/src/MgrMap.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GameFrame.dir/src/MgrMap.cpp.s"
	/usr/bin/clang++-15 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/myGame/GameFrame/src/MgrMap.cpp -o CMakeFiles/GameFrame.dir/src/MgrMap.cpp.s

CMakeFiles/GameFrame.dir/src/MgrTex.cpp.o: CMakeFiles/GameFrame.dir/flags.make
CMakeFiles/GameFrame.dir/src/MgrTex.cpp.o: ../../../src/MgrTex.cpp
CMakeFiles/GameFrame.dir/src/MgrTex.cpp.o: CMakeFiles/GameFrame.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/root/myGame/GameFrame/out/build/Clang 15.0.7 x86_64-pc-linux-gnu/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/GameFrame.dir/src/MgrTex.cpp.o"
	/usr/bin/clang++-15 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/GameFrame.dir/src/MgrTex.cpp.o -MF CMakeFiles/GameFrame.dir/src/MgrTex.cpp.o.d -o CMakeFiles/GameFrame.dir/src/MgrTex.cpp.o -c /root/myGame/GameFrame/src/MgrTex.cpp

CMakeFiles/GameFrame.dir/src/MgrTex.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GameFrame.dir/src/MgrTex.cpp.i"
	/usr/bin/clang++-15 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/myGame/GameFrame/src/MgrTex.cpp > CMakeFiles/GameFrame.dir/src/MgrTex.cpp.i

CMakeFiles/GameFrame.dir/src/MgrTex.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GameFrame.dir/src/MgrTex.cpp.s"
	/usr/bin/clang++-15 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/myGame/GameFrame/src/MgrTex.cpp -o CMakeFiles/GameFrame.dir/src/MgrTex.cpp.s

CMakeFiles/GameFrame.dir/src/Utils.cpp.o: CMakeFiles/GameFrame.dir/flags.make
CMakeFiles/GameFrame.dir/src/Utils.cpp.o: ../../../src/Utils.cpp
CMakeFiles/GameFrame.dir/src/Utils.cpp.o: CMakeFiles/GameFrame.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/root/myGame/GameFrame/out/build/Clang 15.0.7 x86_64-pc-linux-gnu/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/GameFrame.dir/src/Utils.cpp.o"
	/usr/bin/clang++-15 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/GameFrame.dir/src/Utils.cpp.o -MF CMakeFiles/GameFrame.dir/src/Utils.cpp.o.d -o CMakeFiles/GameFrame.dir/src/Utils.cpp.o -c /root/myGame/GameFrame/src/Utils.cpp

CMakeFiles/GameFrame.dir/src/Utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GameFrame.dir/src/Utils.cpp.i"
	/usr/bin/clang++-15 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/myGame/GameFrame/src/Utils.cpp > CMakeFiles/GameFrame.dir/src/Utils.cpp.i

CMakeFiles/GameFrame.dir/src/Utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GameFrame.dir/src/Utils.cpp.s"
	/usr/bin/clang++-15 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/myGame/GameFrame/src/Utils.cpp -o CMakeFiles/GameFrame.dir/src/Utils.cpp.s

CMakeFiles/GameFrame.dir/main.cpp.o: CMakeFiles/GameFrame.dir/flags.make
CMakeFiles/GameFrame.dir/main.cpp.o: ../../../main.cpp
CMakeFiles/GameFrame.dir/main.cpp.o: CMakeFiles/GameFrame.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/root/myGame/GameFrame/out/build/Clang 15.0.7 x86_64-pc-linux-gnu/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/GameFrame.dir/main.cpp.o"
	/usr/bin/clang++-15 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/GameFrame.dir/main.cpp.o -MF CMakeFiles/GameFrame.dir/main.cpp.o.d -o CMakeFiles/GameFrame.dir/main.cpp.o -c /root/myGame/GameFrame/main.cpp

CMakeFiles/GameFrame.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GameFrame.dir/main.cpp.i"
	/usr/bin/clang++-15 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/myGame/GameFrame/main.cpp > CMakeFiles/GameFrame.dir/main.cpp.i

CMakeFiles/GameFrame.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GameFrame.dir/main.cpp.s"
	/usr/bin/clang++-15 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/myGame/GameFrame/main.cpp -o CMakeFiles/GameFrame.dir/main.cpp.s

# Object files for target GameFrame
GameFrame_OBJECTS = \
"CMakeFiles/GameFrame.dir/src/Animation.cpp.o" \
"CMakeFiles/GameFrame.dir/src/Game.cpp.o" \
"CMakeFiles/GameFrame.dir/src/GameCamera.cpp.o" \
"CMakeFiles/GameFrame.dir/src/GameEntity.cpp.o" \
"CMakeFiles/GameFrame.dir/src/GameMap.cpp.o" \
"CMakeFiles/GameFrame.dir/src/MgrAnima.cpp.o" \
"CMakeFiles/GameFrame.dir/src/MgrEntity.cpp.o" \
"CMakeFiles/GameFrame.dir/src/MgrInput.cpp.o" \
"CMakeFiles/GameFrame.dir/src/MgrMap.cpp.o" \
"CMakeFiles/GameFrame.dir/src/MgrTex.cpp.o" \
"CMakeFiles/GameFrame.dir/src/Utils.cpp.o" \
"CMakeFiles/GameFrame.dir/main.cpp.o"

# External object files for target GameFrame
GameFrame_EXTERNAL_OBJECTS =

GameFrame: CMakeFiles/GameFrame.dir/src/Animation.cpp.o
GameFrame: CMakeFiles/GameFrame.dir/src/Game.cpp.o
GameFrame: CMakeFiles/GameFrame.dir/src/GameCamera.cpp.o
GameFrame: CMakeFiles/GameFrame.dir/src/GameEntity.cpp.o
GameFrame: CMakeFiles/GameFrame.dir/src/GameMap.cpp.o
GameFrame: CMakeFiles/GameFrame.dir/src/MgrAnima.cpp.o
GameFrame: CMakeFiles/GameFrame.dir/src/MgrEntity.cpp.o
GameFrame: CMakeFiles/GameFrame.dir/src/MgrInput.cpp.o
GameFrame: CMakeFiles/GameFrame.dir/src/MgrMap.cpp.o
GameFrame: CMakeFiles/GameFrame.dir/src/MgrTex.cpp.o
GameFrame: CMakeFiles/GameFrame.dir/src/Utils.cpp.o
GameFrame: CMakeFiles/GameFrame.dir/main.cpp.o
GameFrame: CMakeFiles/GameFrame.dir/build.make
GameFrame: CMakeFiles/GameFrame.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/root/myGame/GameFrame/out/build/Clang 15.0.7 x86_64-pc-linux-gnu/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_13) "Linking CXX executable GameFrame"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/GameFrame.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/GameFrame.dir/build: GameFrame
.PHONY : CMakeFiles/GameFrame.dir/build

CMakeFiles/GameFrame.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/GameFrame.dir/cmake_clean.cmake
.PHONY : CMakeFiles/GameFrame.dir/clean

CMakeFiles/GameFrame.dir/depend:
	cd "/root/myGame/GameFrame/out/build/Clang 15.0.7 x86_64-pc-linux-gnu" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/myGame/GameFrame /root/myGame/GameFrame "/root/myGame/GameFrame/out/build/Clang 15.0.7 x86_64-pc-linux-gnu" "/root/myGame/GameFrame/out/build/Clang 15.0.7 x86_64-pc-linux-gnu" "/root/myGame/GameFrame/out/build/Clang 15.0.7 x86_64-pc-linux-gnu/CMakeFiles/GameFrame.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/GameFrame.dir/depend
