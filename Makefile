# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_COMMAND = /snap/cmake/599/bin/cmake

# The command to remove a file.
RM = /snap/cmake/599/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/pedro/Documents/github/CES35-lab02

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pedro/Documents/github/CES35-lab02

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/snap/cmake/599/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/snap/cmake/599/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/pedro/Documents/github/CES35-lab02/CMakeFiles /home/pedro/Documents/github/CES35-lab02//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/pedro/Documents/github/CES35-lab02/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named CES35_lab02

# Build rule for target.
CES35_lab02: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 CES35_lab02
.PHONY : CES35_lab02

# fast build rule for target.
CES35_lab02/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/CES35_lab02.dir/build.make CMakeFiles/CES35_lab02.dir/build
.PHONY : CES35_lab02/fast

HTTPReq.o: HTTPReq.cpp.o

.PHONY : HTTPReq.o

# target to build an object file
HTTPReq.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/CES35_lab02.dir/build.make CMakeFiles/CES35_lab02.dir/HTTPReq.cpp.o
.PHONY : HTTPReq.cpp.o

HTTPReq.i: HTTPReq.cpp.i

.PHONY : HTTPReq.i

# target to preprocess a source file
HTTPReq.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/CES35_lab02.dir/build.make CMakeFiles/CES35_lab02.dir/HTTPReq.cpp.i
.PHONY : HTTPReq.cpp.i

HTTPReq.s: HTTPReq.cpp.s

.PHONY : HTTPReq.s

# target to generate assembly for a file
HTTPReq.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/CES35_lab02.dir/build.make CMakeFiles/CES35_lab02.dir/HTTPReq.cpp.s
.PHONY : HTTPReq.cpp.s

HTTPResp.o: HTTPResp.cpp.o

.PHONY : HTTPResp.o

# target to build an object file
HTTPResp.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/CES35_lab02.dir/build.make CMakeFiles/CES35_lab02.dir/HTTPResp.cpp.o
.PHONY : HTTPResp.cpp.o

HTTPResp.i: HTTPResp.cpp.i

.PHONY : HTTPResp.i

# target to preprocess a source file
HTTPResp.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/CES35_lab02.dir/build.make CMakeFiles/CES35_lab02.dir/HTTPResp.cpp.i
.PHONY : HTTPResp.cpp.i

HTTPResp.s: HTTPResp.cpp.s

.PHONY : HTTPResp.s

# target to generate assembly for a file
HTTPResp.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/CES35_lab02.dir/build.make CMakeFiles/CES35_lab02.dir/HTTPResp.cpp.s
.PHONY : HTTPResp.cpp.s

echo-client.o: echo-client.cpp.o

.PHONY : echo-client.o

# target to build an object file
echo-client.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/CES35_lab02.dir/build.make CMakeFiles/CES35_lab02.dir/echo-client.cpp.o
.PHONY : echo-client.cpp.o

echo-client.i: echo-client.cpp.i

.PHONY : echo-client.i

# target to preprocess a source file
echo-client.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/CES35_lab02.dir/build.make CMakeFiles/CES35_lab02.dir/echo-client.cpp.i
.PHONY : echo-client.cpp.i

echo-client.s: echo-client.cpp.s

.PHONY : echo-client.s

# target to generate assembly for a file
echo-client.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/CES35_lab02.dir/build.make CMakeFiles/CES35_lab02.dir/echo-client.cpp.s
.PHONY : echo-client.cpp.s

echo-server.o: echo-server.cpp.o

.PHONY : echo-server.o

# target to build an object file
echo-server.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/CES35_lab02.dir/build.make CMakeFiles/CES35_lab02.dir/echo-server.cpp.o
.PHONY : echo-server.cpp.o

echo-server.i: echo-server.cpp.i

.PHONY : echo-server.i

# target to preprocess a source file
echo-server.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/CES35_lab02.dir/build.make CMakeFiles/CES35_lab02.dir/echo-server.cpp.i
.PHONY : echo-server.cpp.i

echo-server.s: echo-server.cpp.s

.PHONY : echo-server.s

# target to generate assembly for a file
echo-server.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/CES35_lab02.dir/build.make CMakeFiles/CES35_lab02.dir/echo-server.cpp.s
.PHONY : echo-server.cpp.s

ip_functions.o: ip_functions.cpp.o

.PHONY : ip_functions.o

# target to build an object file
ip_functions.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/CES35_lab02.dir/build.make CMakeFiles/CES35_lab02.dir/ip_functions.cpp.o
.PHONY : ip_functions.cpp.o

ip_functions.i: ip_functions.cpp.i

.PHONY : ip_functions.i

# target to preprocess a source file
ip_functions.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/CES35_lab02.dir/build.make CMakeFiles/CES35_lab02.dir/ip_functions.cpp.i
.PHONY : ip_functions.cpp.i

ip_functions.s: ip_functions.cpp.s

.PHONY : ip_functions.s

# target to generate assembly for a file
ip_functions.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/CES35_lab02.dir/build.make CMakeFiles/CES35_lab02.dir/ip_functions.cpp.s
.PHONY : ip_functions.cpp.s

main.o: main.cpp.o

.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/CES35_lab02.dir/build.make CMakeFiles/CES35_lab02.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i

.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/CES35_lab02.dir/build.make CMakeFiles/CES35_lab02.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s

.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/CES35_lab02.dir/build.make CMakeFiles/CES35_lab02.dir/main.cpp.s
.PHONY : main.cpp.s

multi-thread.o: multi-thread.cpp.o

.PHONY : multi-thread.o

# target to build an object file
multi-thread.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/CES35_lab02.dir/build.make CMakeFiles/CES35_lab02.dir/multi-thread.cpp.o
.PHONY : multi-thread.cpp.o

multi-thread.i: multi-thread.cpp.i

.PHONY : multi-thread.i

# target to preprocess a source file
multi-thread.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/CES35_lab02.dir/build.make CMakeFiles/CES35_lab02.dir/multi-thread.cpp.i
.PHONY : multi-thread.cpp.i

multi-thread.s: multi-thread.cpp.s

.PHONY : multi-thread.s

# target to generate assembly for a file
multi-thread.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/CES35_lab02.dir/build.make CMakeFiles/CES35_lab02.dir/multi-thread.cpp.s
.PHONY : multi-thread.cpp.s

showip.o: showip.cpp.o

.PHONY : showip.o

# target to build an object file
showip.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/CES35_lab02.dir/build.make CMakeFiles/CES35_lab02.dir/showip.cpp.o
.PHONY : showip.cpp.o

showip.i: showip.cpp.i

.PHONY : showip.i

# target to preprocess a source file
showip.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/CES35_lab02.dir/build.make CMakeFiles/CES35_lab02.dir/showip.cpp.i
.PHONY : showip.cpp.i

showip.s: showip.cpp.s

.PHONY : showip.s

# target to generate assembly for a file
showip.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/CES35_lab02.dir/build.make CMakeFiles/CES35_lab02.dir/showip.cpp.s
.PHONY : showip.cpp.s

web-server.o: web-server.cpp.o

.PHONY : web-server.o

# target to build an object file
web-server.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/CES35_lab02.dir/build.make CMakeFiles/CES35_lab02.dir/web-server.cpp.o
.PHONY : web-server.cpp.o

web-server.i: web-server.cpp.i

.PHONY : web-server.i

# target to preprocess a source file
web-server.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/CES35_lab02.dir/build.make CMakeFiles/CES35_lab02.dir/web-server.cpp.i
.PHONY : web-server.cpp.i

web-server.s: web-server.cpp.s

.PHONY : web-server.s

# target to generate assembly for a file
web-server.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/CES35_lab02.dir/build.make CMakeFiles/CES35_lab02.dir/web-server.cpp.s
.PHONY : web-server.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... CES35_lab02"
	@echo "... HTTPReq.o"
	@echo "... HTTPReq.i"
	@echo "... HTTPReq.s"
	@echo "... HTTPResp.o"
	@echo "... HTTPResp.i"
	@echo "... HTTPResp.s"
	@echo "... echo-client.o"
	@echo "... echo-client.i"
	@echo "... echo-client.s"
	@echo "... echo-server.o"
	@echo "... echo-server.i"
	@echo "... echo-server.s"
	@echo "... ip_functions.o"
	@echo "... ip_functions.i"
	@echo "... ip_functions.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
	@echo "... multi-thread.o"
	@echo "... multi-thread.i"
	@echo "... multi-thread.s"
	@echo "... showip.o"
	@echo "... showip.i"
	@echo "... showip.s"
	@echo "... web-server.o"
	@echo "... web-server.i"
	@echo "... web-server.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

