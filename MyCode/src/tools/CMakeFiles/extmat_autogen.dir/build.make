# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jxt/ModalSoundGen/ModalSound

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jxt/ModalSoundGen/ModalSound

# Utility rule file for extmat_autogen.

# Include the progress variables for this target.
include src/tools/CMakeFiles/extmat_autogen.dir/progress.make

src/tools/CMakeFiles/extmat_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/jxt/ModalSoundGen/ModalSound/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic UIC and RCC for target extmat"
	cd /home/jxt/ModalSoundGen/ModalSound/src/tools && /usr/local/bin/cmake -E cmake_autogen /home/jxt/ModalSoundGen/ModalSound/src/tools/CMakeFiles/extmat_autogen.dir Release

extmat_autogen: src/tools/CMakeFiles/extmat_autogen
extmat_autogen: src/tools/CMakeFiles/extmat_autogen.dir/build.make

.PHONY : extmat_autogen

# Rule to build all files generated by this target.
src/tools/CMakeFiles/extmat_autogen.dir/build: extmat_autogen

.PHONY : src/tools/CMakeFiles/extmat_autogen.dir/build

src/tools/CMakeFiles/extmat_autogen.dir/clean:
	cd /home/jxt/ModalSoundGen/ModalSound/src/tools && $(CMAKE_COMMAND) -P CMakeFiles/extmat_autogen.dir/cmake_clean.cmake
.PHONY : src/tools/CMakeFiles/extmat_autogen.dir/clean

src/tools/CMakeFiles/extmat_autogen.dir/depend:
	cd /home/jxt/ModalSoundGen/ModalSound && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jxt/ModalSoundGen/ModalSound /home/jxt/ModalSoundGen/ModalSound/src/tools /home/jxt/ModalSoundGen/ModalSound /home/jxt/ModalSoundGen/ModalSound/src/tools /home/jxt/ModalSoundGen/ModalSound/src/tools/CMakeFiles/extmat_autogen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/tools/CMakeFiles/extmat_autogen.dir/depend
