# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/markgagarine/CLionProjects/AmericanOptionsPricing

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/markgagarine/CLionProjects/AmericanOptionsPricing/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/AmericanOptionsPricing.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/AmericanOptionsPricing.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/AmericanOptionsPricing.dir/flags.make

CMakeFiles/AmericanOptionsPricing.dir/main.cpp.o: CMakeFiles/AmericanOptionsPricing.dir/flags.make
CMakeFiles/AmericanOptionsPricing.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/markgagarine/CLionProjects/AmericanOptionsPricing/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/AmericanOptionsPricing.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AmericanOptionsPricing.dir/main.cpp.o -c /Users/markgagarine/CLionProjects/AmericanOptionsPricing/main.cpp

CMakeFiles/AmericanOptionsPricing.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AmericanOptionsPricing.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/markgagarine/CLionProjects/AmericanOptionsPricing/main.cpp > CMakeFiles/AmericanOptionsPricing.dir/main.cpp.i

CMakeFiles/AmericanOptionsPricing.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AmericanOptionsPricing.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/markgagarine/CLionProjects/AmericanOptionsPricing/main.cpp -o CMakeFiles/AmericanOptionsPricing.dir/main.cpp.s

CMakeFiles/AmericanOptionsPricing.dir/Stock.cpp.o: CMakeFiles/AmericanOptionsPricing.dir/flags.make
CMakeFiles/AmericanOptionsPricing.dir/Stock.cpp.o: ../Stock.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/markgagarine/CLionProjects/AmericanOptionsPricing/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/AmericanOptionsPricing.dir/Stock.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AmericanOptionsPricing.dir/Stock.cpp.o -c /Users/markgagarine/CLionProjects/AmericanOptionsPricing/Stock.cpp

CMakeFiles/AmericanOptionsPricing.dir/Stock.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AmericanOptionsPricing.dir/Stock.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/markgagarine/CLionProjects/AmericanOptionsPricing/Stock.cpp > CMakeFiles/AmericanOptionsPricing.dir/Stock.cpp.i

CMakeFiles/AmericanOptionsPricing.dir/Stock.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AmericanOptionsPricing.dir/Stock.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/markgagarine/CLionProjects/AmericanOptionsPricing/Stock.cpp -o CMakeFiles/AmericanOptionsPricing.dir/Stock.cpp.s

CMakeFiles/AmericanOptionsPricing.dir/Option.cpp.o: CMakeFiles/AmericanOptionsPricing.dir/flags.make
CMakeFiles/AmericanOptionsPricing.dir/Option.cpp.o: ../Option.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/markgagarine/CLionProjects/AmericanOptionsPricing/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/AmericanOptionsPricing.dir/Option.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AmericanOptionsPricing.dir/Option.cpp.o -c /Users/markgagarine/CLionProjects/AmericanOptionsPricing/Option.cpp

CMakeFiles/AmericanOptionsPricing.dir/Option.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AmericanOptionsPricing.dir/Option.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/markgagarine/CLionProjects/AmericanOptionsPricing/Option.cpp > CMakeFiles/AmericanOptionsPricing.dir/Option.cpp.i

CMakeFiles/AmericanOptionsPricing.dir/Option.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AmericanOptionsPricing.dir/Option.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/markgagarine/CLionProjects/AmericanOptionsPricing/Option.cpp -o CMakeFiles/AmericanOptionsPricing.dir/Option.cpp.s

CMakeFiles/AmericanOptionsPricing.dir/Price_American_PSOR.cpp.o: CMakeFiles/AmericanOptionsPricing.dir/flags.make
CMakeFiles/AmericanOptionsPricing.dir/Price_American_PSOR.cpp.o: ../Price_American_PSOR.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/markgagarine/CLionProjects/AmericanOptionsPricing/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/AmericanOptionsPricing.dir/Price_American_PSOR.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AmericanOptionsPricing.dir/Price_American_PSOR.cpp.o -c /Users/markgagarine/CLionProjects/AmericanOptionsPricing/Price_American_PSOR.cpp

CMakeFiles/AmericanOptionsPricing.dir/Price_American_PSOR.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AmericanOptionsPricing.dir/Price_American_PSOR.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/markgagarine/CLionProjects/AmericanOptionsPricing/Price_American_PSOR.cpp > CMakeFiles/AmericanOptionsPricing.dir/Price_American_PSOR.cpp.i

CMakeFiles/AmericanOptionsPricing.dir/Price_American_PSOR.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AmericanOptionsPricing.dir/Price_American_PSOR.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/markgagarine/CLionProjects/AmericanOptionsPricing/Price_American_PSOR.cpp -o CMakeFiles/AmericanOptionsPricing.dir/Price_American_PSOR.cpp.s

# Object files for target AmericanOptionsPricing
AmericanOptionsPricing_OBJECTS = \
"CMakeFiles/AmericanOptionsPricing.dir/main.cpp.o" \
"CMakeFiles/AmericanOptionsPricing.dir/Stock.cpp.o" \
"CMakeFiles/AmericanOptionsPricing.dir/Option.cpp.o" \
"CMakeFiles/AmericanOptionsPricing.dir/Price_American_PSOR.cpp.o"

# External object files for target AmericanOptionsPricing
AmericanOptionsPricing_EXTERNAL_OBJECTS =

AmericanOptionsPricing: CMakeFiles/AmericanOptionsPricing.dir/main.cpp.o
AmericanOptionsPricing: CMakeFiles/AmericanOptionsPricing.dir/Stock.cpp.o
AmericanOptionsPricing: CMakeFiles/AmericanOptionsPricing.dir/Option.cpp.o
AmericanOptionsPricing: CMakeFiles/AmericanOptionsPricing.dir/Price_American_PSOR.cpp.o
AmericanOptionsPricing: CMakeFiles/AmericanOptionsPricing.dir/build.make
AmericanOptionsPricing: CMakeFiles/AmericanOptionsPricing.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/markgagarine/CLionProjects/AmericanOptionsPricing/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable AmericanOptionsPricing"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/AmericanOptionsPricing.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/AmericanOptionsPricing.dir/build: AmericanOptionsPricing
.PHONY : CMakeFiles/AmericanOptionsPricing.dir/build

CMakeFiles/AmericanOptionsPricing.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/AmericanOptionsPricing.dir/cmake_clean.cmake
.PHONY : CMakeFiles/AmericanOptionsPricing.dir/clean

CMakeFiles/AmericanOptionsPricing.dir/depend:
	cd /Users/markgagarine/CLionProjects/AmericanOptionsPricing/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/markgagarine/CLionProjects/AmericanOptionsPricing /Users/markgagarine/CLionProjects/AmericanOptionsPricing /Users/markgagarine/CLionProjects/AmericanOptionsPricing/cmake-build-debug /Users/markgagarine/CLionProjects/AmericanOptionsPricing/cmake-build-debug /Users/markgagarine/CLionProjects/AmericanOptionsPricing/cmake-build-debug/CMakeFiles/AmericanOptionsPricing.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/AmericanOptionsPricing.dir/depend

