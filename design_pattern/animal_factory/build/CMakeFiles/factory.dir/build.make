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
CMAKE_SOURCE_DIR = /home/maverick64/c++_ws/c++_std/design_pattern/animal_factory

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/maverick64/c++_ws/c++_std/design_pattern/animal_factory/build

# Include any dependencies generated for this target.
include CMakeFiles/factory.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/factory.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/factory.dir/flags.make

CMakeFiles/factory.dir/main.cpp.o: CMakeFiles/factory.dir/flags.make
CMakeFiles/factory.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/maverick64/c++_ws/c++_std/design_pattern/animal_factory/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/factory.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/factory.dir/main.cpp.o -c /home/maverick64/c++_ws/c++_std/design_pattern/animal_factory/main.cpp

CMakeFiles/factory.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/factory.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/maverick64/c++_ws/c++_std/design_pattern/animal_factory/main.cpp > CMakeFiles/factory.dir/main.cpp.i

CMakeFiles/factory.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/factory.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/maverick64/c++_ws/c++_std/design_pattern/animal_factory/main.cpp -o CMakeFiles/factory.dir/main.cpp.s

# Object files for target factory
factory_OBJECTS = \
"CMakeFiles/factory.dir/main.cpp.o"

# External object files for target factory
factory_EXTERNAL_OBJECTS =

factory: CMakeFiles/factory.dir/main.cpp.o
factory: CMakeFiles/factory.dir/build.make
factory: CMakeFiles/factory.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/maverick64/c++_ws/c++_std/design_pattern/animal_factory/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable factory"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/factory.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/factory.dir/build: factory

.PHONY : CMakeFiles/factory.dir/build

CMakeFiles/factory.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/factory.dir/cmake_clean.cmake
.PHONY : CMakeFiles/factory.dir/clean

CMakeFiles/factory.dir/depend:
	cd /home/maverick64/c++_ws/c++_std/design_pattern/animal_factory/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/maverick64/c++_ws/c++_std/design_pattern/animal_factory /home/maverick64/c++_ws/c++_std/design_pattern/animal_factory /home/maverick64/c++_ws/c++_std/design_pattern/animal_factory/build /home/maverick64/c++_ws/c++_std/design_pattern/animal_factory/build /home/maverick64/c++_ws/c++_std/design_pattern/animal_factory/build/CMakeFiles/factory.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/factory.dir/depend

