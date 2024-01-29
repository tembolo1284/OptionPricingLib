cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_COMPILER "/usr/bin/g++")

project(OptionPricingTests)
add_subdirectory(googletest)

include_directories(
  ${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR}
)

set(TEST_SOURCES
    testGenericOption.cpp
    testRandomWalkGenerator.cpp
    testDate.cpp
    testDateCompact.cpp
    testRunner.cpp
)

add_executable(OptionPricingTests ${TEST_SOURCES})

target_link_libraries(OptionPricingTests OptionPricingLib gtest gtest_main)

include(GoogleTest)
gtest_discover_tests(OptionPricingTests)
