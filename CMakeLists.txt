cmake_minimum_required(VERSION 3.10)  # Specify the minimum version for CMake

project(OptionPricingLib)  # Name your project

# Allow the user to specify the compiler using the -DCOMPILER option
set(COMPILER "g++" CACHE STRING "Select the C++ compiler (g++ or clang++)")

include_directories(include)

set(SOURCES
    main.cpp
    src/RandomWalkGenerator.cpp
    src/Date.cpp
    src/DateCompact.cpp
    src/GenericOption.cpp
)

# Create a library for the project's code
add_library(OptionPricingLib STATIC ${SOURCES})

add_executable(OptionPricingApp ${SOURCES})

# Set the C++ compiler based on the COMPILER variable
if(COMPILER STREQUAL "g++")
  # Using g++
  set(CMAKE_CXX_COMPILER "g++")
  target_compile_options(OptionPricingLib PRIVATE -Wall -Wextra -Werror -Wpedantic -Wconversion -Wshadow -g)
elseif(COMPILER STREQUAL "clang++")
  # Using clang++
  set(CMAKE_CXX_COMPILER "clang++")
  target_compile_options(OptionPricingLib PRIVATE -Wall -Wextra -Werror -Wpedantic -Wconversion -Wshadow -g)
else()
  message(FATAL_ERROR "Invalid compiler specified. Use 'g++' or 'clang++'")
endif()

message(STATUS "Using compiler: ${CMAKE_CXX_COMPILER}")

enable_testing()

add_subdirectory(test)

# cmake -B build -DCOMPILER=g++
# cmake -B build -DCOMPILER=clang++
