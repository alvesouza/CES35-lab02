# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /home/pedro/Downloads/clion-2020.2.3/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/pedro/Downloads/clion-2020.2.3/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/pedro/Documents/github/CES35-lab02

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pedro/Documents/github/CES35-lab02/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ip_functions.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ip_functions.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ip_functions.dir/flags.make

CMakeFiles/ip_functions.dir/functions/ip/ip_functions.cpp.o: CMakeFiles/ip_functions.dir/flags.make
CMakeFiles/ip_functions.dir/functions/ip/ip_functions.cpp.o: ../functions/ip/ip_functions.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pedro/Documents/github/CES35-lab02/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ip_functions.dir/functions/ip/ip_functions.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ip_functions.dir/functions/ip/ip_functions.cpp.o -c /home/pedro/Documents/github/CES35-lab02/functions/ip/ip_functions.cpp

CMakeFiles/ip_functions.dir/functions/ip/ip_functions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ip_functions.dir/functions/ip/ip_functions.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pedro/Documents/github/CES35-lab02/functions/ip/ip_functions.cpp > CMakeFiles/ip_functions.dir/functions/ip/ip_functions.cpp.i

CMakeFiles/ip_functions.dir/functions/ip/ip_functions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ip_functions.dir/functions/ip/ip_functions.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pedro/Documents/github/CES35-lab02/functions/ip/ip_functions.cpp -o CMakeFiles/ip_functions.dir/functions/ip/ip_functions.cpp.s

# Object files for target ip_functions
ip_functions_OBJECTS = \
"CMakeFiles/ip_functions.dir/functions/ip/ip_functions.cpp.o"

# External object files for target ip_functions
ip_functions_EXTERNAL_OBJECTS =

libip_functions.a: CMakeFiles/ip_functions.dir/functions/ip/ip_functions.cpp.o
libip_functions.a: CMakeFiles/ip_functions.dir/build.make
libip_functions.a: CMakeFiles/ip_functions.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pedro/Documents/github/CES35-lab02/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libip_functions.a"
	$(CMAKE_COMMAND) -P CMakeFiles/ip_functions.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ip_functions.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ip_functions.dir/build: libip_functions.a

.PHONY : CMakeFiles/ip_functions.dir/build

CMakeFiles/ip_functions.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ip_functions.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ip_functions.dir/clean

CMakeFiles/ip_functions.dir/depend:
	cd /home/pedro/Documents/github/CES35-lab02/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pedro/Documents/github/CES35-lab02 /home/pedro/Documents/github/CES35-lab02 /home/pedro/Documents/github/CES35-lab02/cmake-build-debug /home/pedro/Documents/github/CES35-lab02/cmake-build-debug /home/pedro/Documents/github/CES35-lab02/cmake-build-debug/CMakeFiles/ip_functions.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ip_functions.dir/depend

