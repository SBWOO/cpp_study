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
CMAKE_SOURCE_DIR = /home/maverick64/c++_ws/cpp_study/multithread_design/worker_dispatcher

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/maverick64/c++_ws/cpp_study/multithread_design/worker_dispatcher/build

# Include any dependencies generated for this target.
include CMakeFiles/'dispatch_main'.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/'dispatch_main'.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/'dispatch_main'.dir/flags.make

CMakeFiles/'dispatch_main'.dir/pipeline_main.cpp.o: CMakeFiles/'dispatch_main'.dir/flags.make
CMakeFiles/'dispatch_main'.dir/pipeline_main.cpp.o: ../pipeline_main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/maverick64/c++_ws/cpp_study/multithread_design/worker_dispatcher/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/'dispatch_main'.dir/pipeline_main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o "CMakeFiles/'dispatch_main'.dir/pipeline_main.cpp.o" -c /home/maverick64/c++_ws/cpp_study/multithread_design/worker_dispatcher/pipeline_main.cpp

CMakeFiles/'dispatch_main'.dir/pipeline_main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/'dispatch_main'.dir/pipeline_main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/maverick64/c++_ws/cpp_study/multithread_design/worker_dispatcher/pipeline_main.cpp > "CMakeFiles/'dispatch_main'.dir/pipeline_main.cpp.i"

CMakeFiles/'dispatch_main'.dir/pipeline_main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/'dispatch_main'.dir/pipeline_main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/maverick64/c++_ws/cpp_study/multithread_design/worker_dispatcher/pipeline_main.cpp -o "CMakeFiles/'dispatch_main'.dir/pipeline_main.cpp.s"

CMakeFiles/'dispatch_main'.dir/dispatcher.cpp.o: CMakeFiles/'dispatch_main'.dir/flags.make
CMakeFiles/'dispatch_main'.dir/dispatcher.cpp.o: ../dispatcher.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/maverick64/c++_ws/cpp_study/multithread_design/worker_dispatcher/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/'dispatch_main'.dir/dispatcher.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o "CMakeFiles/'dispatch_main'.dir/dispatcher.cpp.o" -c /home/maverick64/c++_ws/cpp_study/multithread_design/worker_dispatcher/dispatcher.cpp

CMakeFiles/'dispatch_main'.dir/dispatcher.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/'dispatch_main'.dir/dispatcher.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/maverick64/c++_ws/cpp_study/multithread_design/worker_dispatcher/dispatcher.cpp > "CMakeFiles/'dispatch_main'.dir/dispatcher.cpp.i"

CMakeFiles/'dispatch_main'.dir/dispatcher.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/'dispatch_main'.dir/dispatcher.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/maverick64/c++_ws/cpp_study/multithread_design/worker_dispatcher/dispatcher.cpp -o "CMakeFiles/'dispatch_main'.dir/dispatcher.cpp.s"

# Object files for target 'dispatch_main'
'dispatch_main'_OBJECTS = \
"CMakeFiles/'dispatch_main'.dir/pipeline_main.cpp.o" \
"CMakeFiles/'dispatch_main'.dir/dispatcher.cpp.o"

# External object files for target 'dispatch_main'
'dispatch_main'_EXTERNAL_OBJECTS =

'dispatch_main': CMakeFiles/'dispatch_main'.dir/pipeline_main.cpp.o
'dispatch_main': CMakeFiles/'dispatch_main'.dir/dispatcher.cpp.o
'dispatch_main': CMakeFiles/'dispatch_main'.dir/build.make
'dispatch_main': CMakeFiles/'dispatch_main'.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/maverick64/c++_ws/cpp_study/multithread_design/worker_dispatcher/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable \"'dispatch_main'\""
	$(CMAKE_COMMAND) -E cmake_link_script "CMakeFiles/'dispatch_main'.dir/link.txt" --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/'dispatch_main'.dir/build: 'dispatch_main'

.PHONY : CMakeFiles/'dispatch_main'.dir/build

CMakeFiles/'dispatch_main'.dir/clean:
	$(CMAKE_COMMAND) -P "CMakeFiles/'dispatch_main'.dir/cmake_clean.cmake"
.PHONY : CMakeFiles/'dispatch_main'.dir/clean

CMakeFiles/'dispatch_main'.dir/depend:
	cd /home/maverick64/c++_ws/cpp_study/multithread_design/worker_dispatcher/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/maverick64/c++_ws/cpp_study/multithread_design/worker_dispatcher /home/maverick64/c++_ws/cpp_study/multithread_design/worker_dispatcher /home/maverick64/c++_ws/cpp_study/multithread_design/worker_dispatcher/build /home/maverick64/c++_ws/cpp_study/multithread_design/worker_dispatcher/build "/home/maverick64/c++_ws/cpp_study/multithread_design/worker_dispatcher/build/CMakeFiles/'dispatch_main'.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/'dispatch_main'.dir/depend

