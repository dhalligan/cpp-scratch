# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.1

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/halligan/cpp-project-template

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/halligan/cpp-project-template/build

# Utility rule file for docs.

# Include the progress variables for this target.
include CMakeFiles/docs.dir/progress.make

CMakeFiles/docs:
	$(CMAKE_COMMAND) -E cmake_progress_report /home/halligan/cpp-project-template/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating doxygen project documentation."
	cd /home/halligan/cpp-project-template && /usr/local/bin/doxygen Doxyfile

docs: CMakeFiles/docs
docs: CMakeFiles/docs.dir/build.make
.PHONY : docs

# Rule to build all files generated by this target.
CMakeFiles/docs.dir/build: docs
.PHONY : CMakeFiles/docs.dir/build

CMakeFiles/docs.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/docs.dir/cmake_clean.cmake
.PHONY : CMakeFiles/docs.dir/clean

CMakeFiles/docs.dir/depend:
	cd /home/halligan/cpp-project-template/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/halligan/cpp-project-template /home/halligan/cpp-project-template /home/halligan/cpp-project-template/build /home/halligan/cpp-project-template/build /home/halligan/cpp-project-template/build/CMakeFiles/docs.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/docs.dir/depend
