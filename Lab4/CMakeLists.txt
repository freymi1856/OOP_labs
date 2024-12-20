cmake_minimum_required(VERSION 3.10)

project(Figures)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/release-1.12.1.tar.gz
)
FetchContent_MakeAvailable(googletest)

enable_testing()

# Source files
add_library(figures STATIC src/figure.cpp)
target_include_directories(figures PUBLIC src)

# Main executable
add_executable(main src/solution.cpp)
target_link_libraries(main figures)

# Tests
add_executable(TestFigures tests/test_figures.cpp)
target_link_libraries(TestFigures figures gtest_main)
include(GoogleTest)
gtest_discover_tests(TestFigures)