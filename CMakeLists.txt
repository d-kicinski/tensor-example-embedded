cmake_minimum_required(VERSION 3.16)

# specify toolchain
set(CMAKE_C_COMPILER arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER arm-none-eabi-g++)
set(CMAKE_ASM_COMPILER  arm-none-eabi-gcc)
set(CMAKE_AR arm-none-eabi-ar)
set(CMAKE_OBJCOPY arm-none-eabi-objcopy)
set(CMAKE_OBJDUMP arm-none-eabi-objdump)
set(SIZE arm-none-eabi-size)
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

# project settings
project(tensor-example-embedded LANGUAGES CXX C ASM VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)

# compile options specific to targeted platform
if ("${CMAKE_BUILD_TYPE}" STREQUAL "Release")
    message(STATUS "Maximum optimization for speed")
    add_compile_options(-Ofast)
elseif ("${CMAKE_BUILD_TYPE}" STREQUAL "RelWithDebInfo")
    message(STATUS "Maximum optimization for speed, debug info included")
    add_compile_options(-Ofast -g)
elseif ("${CMAKE_BUILD_TYPE}" STREQUAL "MinSizeRel")
    message(STATUS "Maximum optimization for size")
    add_compile_options(-Os)
else ()
    message(STATUS "Minimal optimization, debug info included")
    add_compile_options(-Og -g)
endif ()
add_compile_options(-mcpu=cortex-m4 -mthumb -mthumb-interwork)
add_compile_options(-ffunction-sections -fdata-sections -fno-common -fmessage-length=0)

# note: linker options are set in stm32f4 subdirectory

# Configure options
set(TENSOR_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(TENSOR_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(TENSOR_BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)

add_subdirectory(third-party/tensor)
add_subdirectory(compute)
add_subdirectory(stm32f4)
