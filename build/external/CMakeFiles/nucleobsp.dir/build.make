# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/sf/Downloads/TheTokenBox

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sf/Downloads/TheTokenBox/build

# Include any dependencies generated for this target.
include external/CMakeFiles/nucleobsp.dir/depend.make

# Include the progress variables for this target.
include external/CMakeFiles/nucleobsp.dir/progress.make

# Include the compile flags for this target's objects.
include external/CMakeFiles/nucleobsp.dir/flags.make

external/CMakeFiles/nucleobsp.dir/STM32Cube_FW_F1_V1.6.0/Drivers/BSP/STM32F1xx_Nucleo/stm32f1xx_nucleo.c.obj: external/CMakeFiles/nucleobsp.dir/flags.make
external/CMakeFiles/nucleobsp.dir/STM32Cube_FW_F1_V1.6.0/Drivers/BSP/STM32F1xx_Nucleo/stm32f1xx_nucleo.c.obj: ../external/STM32Cube_FW_F1_V1.6.0/Drivers/BSP/STM32F1xx_Nucleo/stm32f1xx_nucleo.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sf/Downloads/TheTokenBox/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object external/CMakeFiles/nucleobsp.dir/STM32Cube_FW_F1_V1.6.0/Drivers/BSP/STM32F1xx_Nucleo/stm32f1xx_nucleo.c.obj"
	cd /home/sf/Downloads/TheTokenBox/build/external && /usr/bin/arm-none-eabi-gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/nucleobsp.dir/STM32Cube_FW_F1_V1.6.0/Drivers/BSP/STM32F1xx_Nucleo/stm32f1xx_nucleo.c.obj   -c /home/sf/Downloads/TheTokenBox/external/STM32Cube_FW_F1_V1.6.0/Drivers/BSP/STM32F1xx_Nucleo/stm32f1xx_nucleo.c

external/CMakeFiles/nucleobsp.dir/STM32Cube_FW_F1_V1.6.0/Drivers/BSP/STM32F1xx_Nucleo/stm32f1xx_nucleo.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/nucleobsp.dir/STM32Cube_FW_F1_V1.6.0/Drivers/BSP/STM32F1xx_Nucleo/stm32f1xx_nucleo.c.i"
	cd /home/sf/Downloads/TheTokenBox/build/external && /usr/bin/arm-none-eabi-gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sf/Downloads/TheTokenBox/external/STM32Cube_FW_F1_V1.6.0/Drivers/BSP/STM32F1xx_Nucleo/stm32f1xx_nucleo.c > CMakeFiles/nucleobsp.dir/STM32Cube_FW_F1_V1.6.0/Drivers/BSP/STM32F1xx_Nucleo/stm32f1xx_nucleo.c.i

external/CMakeFiles/nucleobsp.dir/STM32Cube_FW_F1_V1.6.0/Drivers/BSP/STM32F1xx_Nucleo/stm32f1xx_nucleo.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/nucleobsp.dir/STM32Cube_FW_F1_V1.6.0/Drivers/BSP/STM32F1xx_Nucleo/stm32f1xx_nucleo.c.s"
	cd /home/sf/Downloads/TheTokenBox/build/external && /usr/bin/arm-none-eabi-gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sf/Downloads/TheTokenBox/external/STM32Cube_FW_F1_V1.6.0/Drivers/BSP/STM32F1xx_Nucleo/stm32f1xx_nucleo.c -o CMakeFiles/nucleobsp.dir/STM32Cube_FW_F1_V1.6.0/Drivers/BSP/STM32F1xx_Nucleo/stm32f1xx_nucleo.c.s

external/CMakeFiles/nucleobsp.dir/STM32Cube_FW_F1_V1.6.0/Drivers/BSP/STM32F1xx_Nucleo/stm32f1xx_nucleo.c.obj.requires:

.PHONY : external/CMakeFiles/nucleobsp.dir/STM32Cube_FW_F1_V1.6.0/Drivers/BSP/STM32F1xx_Nucleo/stm32f1xx_nucleo.c.obj.requires

external/CMakeFiles/nucleobsp.dir/STM32Cube_FW_F1_V1.6.0/Drivers/BSP/STM32F1xx_Nucleo/stm32f1xx_nucleo.c.obj.provides: external/CMakeFiles/nucleobsp.dir/STM32Cube_FW_F1_V1.6.0/Drivers/BSP/STM32F1xx_Nucleo/stm32f1xx_nucleo.c.obj.requires
	$(MAKE) -f external/CMakeFiles/nucleobsp.dir/build.make external/CMakeFiles/nucleobsp.dir/STM32Cube_FW_F1_V1.6.0/Drivers/BSP/STM32F1xx_Nucleo/stm32f1xx_nucleo.c.obj.provides.build
.PHONY : external/CMakeFiles/nucleobsp.dir/STM32Cube_FW_F1_V1.6.0/Drivers/BSP/STM32F1xx_Nucleo/stm32f1xx_nucleo.c.obj.provides

external/CMakeFiles/nucleobsp.dir/STM32Cube_FW_F1_V1.6.0/Drivers/BSP/STM32F1xx_Nucleo/stm32f1xx_nucleo.c.obj.provides.build: external/CMakeFiles/nucleobsp.dir/STM32Cube_FW_F1_V1.6.0/Drivers/BSP/STM32F1xx_Nucleo/stm32f1xx_nucleo.c.obj


# Object files for target nucleobsp
nucleobsp_OBJECTS = \
"CMakeFiles/nucleobsp.dir/STM32Cube_FW_F1_V1.6.0/Drivers/BSP/STM32F1xx_Nucleo/stm32f1xx_nucleo.c.obj"

# External object files for target nucleobsp
nucleobsp_EXTERNAL_OBJECTS =

external/libnucleobsp.a: external/CMakeFiles/nucleobsp.dir/STM32Cube_FW_F1_V1.6.0/Drivers/BSP/STM32F1xx_Nucleo/stm32f1xx_nucleo.c.obj
external/libnucleobsp.a: external/CMakeFiles/nucleobsp.dir/build.make
external/libnucleobsp.a: external/CMakeFiles/nucleobsp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sf/Downloads/TheTokenBox/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libnucleobsp.a"
	cd /home/sf/Downloads/TheTokenBox/build/external && $(CMAKE_COMMAND) -P CMakeFiles/nucleobsp.dir/cmake_clean_target.cmake
	cd /home/sf/Downloads/TheTokenBox/build/external && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/nucleobsp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
external/CMakeFiles/nucleobsp.dir/build: external/libnucleobsp.a

.PHONY : external/CMakeFiles/nucleobsp.dir/build

external/CMakeFiles/nucleobsp.dir/requires: external/CMakeFiles/nucleobsp.dir/STM32Cube_FW_F1_V1.6.0/Drivers/BSP/STM32F1xx_Nucleo/stm32f1xx_nucleo.c.obj.requires

.PHONY : external/CMakeFiles/nucleobsp.dir/requires

external/CMakeFiles/nucleobsp.dir/clean:
	cd /home/sf/Downloads/TheTokenBox/build/external && $(CMAKE_COMMAND) -P CMakeFiles/nucleobsp.dir/cmake_clean.cmake
.PHONY : external/CMakeFiles/nucleobsp.dir/clean

external/CMakeFiles/nucleobsp.dir/depend:
	cd /home/sf/Downloads/TheTokenBox/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sf/Downloads/TheTokenBox /home/sf/Downloads/TheTokenBox/external /home/sf/Downloads/TheTokenBox/build /home/sf/Downloads/TheTokenBox/build/external /home/sf/Downloads/TheTokenBox/build/external/CMakeFiles/nucleobsp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : external/CMakeFiles/nucleobsp.dir/depend

