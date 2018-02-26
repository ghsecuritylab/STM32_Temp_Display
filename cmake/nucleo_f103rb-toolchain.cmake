# Nucleo F103RB

set(CMAKE_ASM_COMPILER "arm-none-eabi-gcc")
set(CMAKE_C_COMPILER "arm-none-eabi-gcc")
set(CMAKE_CXX_COMPILER "arm-none-eabi-g++")

# Instead of the Forcing the compiler, just force it to pass the
# compile/link test.  This lets CMake do most of the magic it does to
# gather information about the toolchain.
set(CMAKE_C_COMPILER_WORKS 1)
set(CMAKE_CXX_COMPILER_WORKS 1)

# Targetting an embedded system, no OS.
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR cortex-m3)

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

set(CMAKE_C_FLAGS "-fno-common -ffunction-sections -fdata-sections -fexceptions -fomit-frame-pointer")

# Allow some optimization in debug builds (more optimization -> smaller binary)
set(CMAKE_C_FLAGS_DEBUG_INIT "-Og")
set(CMAKE_CXX_FLAGS_DEBUG_INIT "-Og")
set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -fno-rtti")

set(CMAKE_EXE_LINKER_FLAGS_INIT "--specs=nosys.specs --specs=nano.specs -Wl,-Map,output.map -Wl,--gc-sections" CACHE INTERNAL "")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS_INIT} -Wl,-T${CMAKE_CURRENT_LIST_DIR}/../nucleo_f103rb/STM32F103RBTx_FLASH.ld")

set(ARCH_FLAGS "-mcpu=cortex-m3 -march=armv7-m -mthumb -msoft-float")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}" "${ARCH_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}" "${ARCH_FLAGS}")

# When we break up long strings in CMake we get semicolon
# separated lists, undo this here.
string(REGEX REPLACE ";" " " CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")
string(REGEX REPLACE ";" " " CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}" CACHE STRING "")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}" CACHE STRING "")

set(BUILD_SHARED_LIBS OFF)
