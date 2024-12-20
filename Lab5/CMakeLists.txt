cmake_minimum_required(VERSION 3.10)
project(Lab5)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Sources
set(SRC_FILES
    src/memory_resource.h
    src/bidirectional_list.h
)

# Tests
set(TEST_FILES
    tests/tests.cpp
)

# Add main executable
add_executable(main main.cpp ${SRC_FILES})

# Add test executable
add_executable(tests ${TEST_FILES} ${SRC_FILES})

# Link libraries
target_link_libraries(tests GTest::GTest GTest::Main)

enable_testing()
add_test(NAME MemoryResourceTests COMMAND tests)