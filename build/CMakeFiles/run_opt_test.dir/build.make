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
CMAKE_SOURCE_DIR = /home/staffnerluca/Dokumente/resh

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/staffnerluca/Dokumente/resh/build

# Include any dependencies generated for this target.
include CMakeFiles/run_opt_test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/run_opt_test.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/run_opt_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/run_opt_test.dir/flags.make

CMakeFiles/run_opt_test.dir/src/lexer.cpp.o: CMakeFiles/run_opt_test.dir/flags.make
CMakeFiles/run_opt_test.dir/src/lexer.cpp.o: ../src/lexer.cpp
CMakeFiles/run_opt_test.dir/src/lexer.cpp.o: CMakeFiles/run_opt_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/staffnerluca/Dokumente/resh/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/run_opt_test.dir/src/lexer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/run_opt_test.dir/src/lexer.cpp.o -MF CMakeFiles/run_opt_test.dir/src/lexer.cpp.o.d -o CMakeFiles/run_opt_test.dir/src/lexer.cpp.o -c /home/staffnerluca/Dokumente/resh/src/lexer.cpp

CMakeFiles/run_opt_test.dir/src/lexer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/run_opt_test.dir/src/lexer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/staffnerluca/Dokumente/resh/src/lexer.cpp > CMakeFiles/run_opt_test.dir/src/lexer.cpp.i

CMakeFiles/run_opt_test.dir/src/lexer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/run_opt_test.dir/src/lexer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/staffnerluca/Dokumente/resh/src/lexer.cpp -o CMakeFiles/run_opt_test.dir/src/lexer.cpp.s

CMakeFiles/run_opt_test.dir/tests/lexer-test.cpp.o: CMakeFiles/run_opt_test.dir/flags.make
CMakeFiles/run_opt_test.dir/tests/lexer-test.cpp.o: ../tests/lexer-test.cpp
CMakeFiles/run_opt_test.dir/tests/lexer-test.cpp.o: CMakeFiles/run_opt_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/staffnerluca/Dokumente/resh/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/run_opt_test.dir/tests/lexer-test.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/run_opt_test.dir/tests/lexer-test.cpp.o -MF CMakeFiles/run_opt_test.dir/tests/lexer-test.cpp.o.d -o CMakeFiles/run_opt_test.dir/tests/lexer-test.cpp.o -c /home/staffnerluca/Dokumente/resh/tests/lexer-test.cpp

CMakeFiles/run_opt_test.dir/tests/lexer-test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/run_opt_test.dir/tests/lexer-test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/staffnerluca/Dokumente/resh/tests/lexer-test.cpp > CMakeFiles/run_opt_test.dir/tests/lexer-test.cpp.i

CMakeFiles/run_opt_test.dir/tests/lexer-test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/run_opt_test.dir/tests/lexer-test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/staffnerluca/Dokumente/resh/tests/lexer-test.cpp -o CMakeFiles/run_opt_test.dir/tests/lexer-test.cpp.s

# Object files for target run_opt_test
run_opt_test_OBJECTS = \
"CMakeFiles/run_opt_test.dir/src/lexer.cpp.o" \
"CMakeFiles/run_opt_test.dir/tests/lexer-test.cpp.o"

# External object files for target run_opt_test
run_opt_test_EXTERNAL_OBJECTS =

run_opt_test: CMakeFiles/run_opt_test.dir/src/lexer.cpp.o
run_opt_test: CMakeFiles/run_opt_test.dir/tests/lexer-test.cpp.o
run_opt_test: CMakeFiles/run_opt_test.dir/build.make
run_opt_test: lib/libgtest_main.a
run_opt_test: lib/libgtest.a
run_opt_test: CMakeFiles/run_opt_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/staffnerluca/Dokumente/resh/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable run_opt_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/run_opt_test.dir/link.txt --verbose=$(VERBOSE)
	/usr/bin/cmake -D TEST_TARGET=run_opt_test -D TEST_EXECUTABLE=/home/staffnerluca/Dokumente/resh/build/run_opt_test -D TEST_EXECUTOR= -D TEST_WORKING_DIR=/home/staffnerluca/Dokumente/resh/build -D TEST_EXTRA_ARGS= -D TEST_PROPERTIES= -D TEST_PREFIX= -D TEST_SUFFIX= -D TEST_FILTER= -D NO_PRETTY_TYPES=FALSE -D NO_PRETTY_VALUES=FALSE -D TEST_LIST=run_opt_test_TESTS -D CTEST_FILE=/home/staffnerluca/Dokumente/resh/build/run_opt_test[1]_tests.cmake -D TEST_DISCOVERY_TIMEOUT=5 -D TEST_XML_OUTPUT_DIR= -P /usr/share/cmake-3.22/Modules/GoogleTestAddTests.cmake

# Rule to build all files generated by this target.
CMakeFiles/run_opt_test.dir/build: run_opt_test
.PHONY : CMakeFiles/run_opt_test.dir/build

CMakeFiles/run_opt_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/run_opt_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/run_opt_test.dir/clean

CMakeFiles/run_opt_test.dir/depend:
	cd /home/staffnerluca/Dokumente/resh/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/staffnerluca/Dokumente/resh /home/staffnerluca/Dokumente/resh /home/staffnerluca/Dokumente/resh/build /home/staffnerluca/Dokumente/resh/build /home/staffnerluca/Dokumente/resh/build/CMakeFiles/run_opt_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/run_opt_test.dir/depend
