# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/kryptokommunist/STM32CubeIDE/workspace_1.13.1/fsfw-example-stm32h7-freertos

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/kryptokommunist/STM32CubeIDE/workspace_1.13.1/fsfw-example-stm32h7-freertos/config_default

# Utility rule file for CMSIS_LD_H747XG_M7.

# Include any custom commands dependencies for this target.
include CMakeFiles/CMSIS_LD_H747XG_M7.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/CMSIS_LD_H747XG_M7.dir/progress.make

CMakeFiles/CMSIS_LD_H747XG_M7: H747XG_M7.ld

H747XG_M7.ld:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/kryptokommunist/STM32CubeIDE/workspace_1.13.1/fsfw-example-stm32h7-freertos/config_default/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating H747XG_M7.ld"
	/Applications/CMake.app/Contents/bin/cmake -DFLASH_ORIGIN="0x8000000" -DRAM_ORIGIN="0x20000000" -DCCRAM_ORIGIN="0x10000000" -DRAM_SHARE_ORIGIN="0x20030000" -DFLASH_SIZE="512K" -DRAM_SIZE="128K" -DCCRAM_SIZE="0K" -DRAM_SHARE_SIZE="NOTFOUND" -DSTACK_SIZE="0x400" -DHEAP_SIZE="0x200" -DLINKER_SCRIPT="/Users/kryptokommunist/STM32CubeIDE/workspace_1.13.1/fsfw-example-stm32h7-freertos/config_default/H747XG_M7.ld" -P /Users/kryptokommunist/STM32CubeIDE/workspace_1.13.1/fsfw-example-stm32h7-freertos/cmake/stm32-cmake/cmake/stm32/linker_ld.cmake

CMSIS_LD_H747XG_M7: CMakeFiles/CMSIS_LD_H747XG_M7
CMSIS_LD_H747XG_M7: H747XG_M7.ld
CMSIS_LD_H747XG_M7: CMakeFiles/CMSIS_LD_H747XG_M7.dir/build.make
.PHONY : CMSIS_LD_H747XG_M7

# Rule to build all files generated by this target.
CMakeFiles/CMSIS_LD_H747XG_M7.dir/build: CMSIS_LD_H747XG_M7
.PHONY : CMakeFiles/CMSIS_LD_H747XG_M7.dir/build

CMakeFiles/CMSIS_LD_H747XG_M7.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CMSIS_LD_H747XG_M7.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CMSIS_LD_H747XG_M7.dir/clean

CMakeFiles/CMSIS_LD_H747XG_M7.dir/depend:
	cd /Users/kryptokommunist/STM32CubeIDE/workspace_1.13.1/fsfw-example-stm32h7-freertos/config_default && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/kryptokommunist/STM32CubeIDE/workspace_1.13.1/fsfw-example-stm32h7-freertos /Users/kryptokommunist/STM32CubeIDE/workspace_1.13.1/fsfw-example-stm32h7-freertos /Users/kryptokommunist/STM32CubeIDE/workspace_1.13.1/fsfw-example-stm32h7-freertos/config_default /Users/kryptokommunist/STM32CubeIDE/workspace_1.13.1/fsfw-example-stm32h7-freertos/config_default /Users/kryptokommunist/STM32CubeIDE/workspace_1.13.1/fsfw-example-stm32h7-freertos/config_default/CMakeFiles/CMSIS_LD_H747XG_M7.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/CMSIS_LD_H747XG_M7.dir/depend

