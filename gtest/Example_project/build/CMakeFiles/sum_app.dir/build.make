# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/maverick64/c++_ws/c++_std/design_pattern/gtest/Example_project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/maverick64/c++_ws/c++_std/design_pattern/gtest/Example_project/build

# Include any dependencies generated for this target.
include CMakeFiles/sum_app.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sum_app.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sum_app.dir/flags.make

CMakeFiles/sum_app.dir/main.o: CMakeFiles/sum_app.dir/flags.make
CMakeFiles/sum_app.dir/main.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/maverick64/c++_ws/c++_std/design_pattern/gtest/Example_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sum_app.dir/main.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sum_app.dir/main.o -c /home/maverick64/c++_ws/c++_std/design_pattern/gtest/Example_project/main.cpp

CMakeFiles/sum_app.dir/main.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sum_app.dir/main.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/maverick64/c++_ws/c++_std/design_pattern/gtest/Example_project/main.cpp > CMakeFiles/sum_app.dir/main.i

CMakeFiles/sum_app.dir/main.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sum_app.dir/main.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/maverick64/c++_ws/c++_std/design_pattern/gtest/Example_project/main.cpp -o CMakeFiles/sum_app.dir/main.s

# Object files for target sum_app
sum_app_OBJECTS = \
"CMakeFiles/sum_app.dir/main.o"

# External object files for target sum_app
sum_app_EXTERNAL_OBJECTS =

sum_app: CMakeFiles/sum_app.dir/main.o
sum_app: CMakeFiles/sum_app.dir/build.make
sum_app: libsum.so
sum_app: CMakeFiles/sum_app.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/maverick64/c++_ws/c++_std/design_pattern/gtest/Example_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable sum_app"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sum_app.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sum_app.dir/build: sum_app

.PHONY : CMakeFiles/sum_app.dir/build

CMakeFiles/sum_app.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sum_app.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sum_app.dir/clean

CMakeFiles/sum_app.dir/depend:
	cd /home/maverick64/c++_ws/c++_std/design_pattern/gtest/Example_project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/maverick64/c++_ws/c++_std/design_pattern/gtest/Example_project /home/maverick64/c++_ws/c++_std/design_pattern/gtest/Example_project /home/maverick64/c++_ws/c++_std/design_pattern/gtest/Example_project/build /home/maverick64/c++_ws/c++_std/design_pattern/gtest/Example_project/build /home/maverick64/c++_ws/c++_std/design_pattern/gtest/Example_project/build/CMakeFiles/sum_app.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sum_app.dir/depend

