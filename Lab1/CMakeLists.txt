cmake_minimum_required(VERSION 3.10)
project(NumberToTurkish)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/release-1.12.1.tar.gz
)
FetchContent_MakeAvailable(googletest)

# Библиотека с логикой
add_library(NumberToTurkishLib src/number_to_turkish.cpp)

# Основная программа
add_executable(NumberToTurkish src/solution.cpp)
target_link_libraries(NumberToTurkish NumberToTurkishLib)

# Тесты
enable_testing()
add_executable(NumberToTurkishTests tests/test_number_to_turkish.cpp)
target_include_directories(NumberToTurkishTests PRIVATE ${CMAKE_SOURCE_DIR}/src)  # Указываем путь к src
target_link_libraries(NumberToTurkishTests NumberToTurkishLib gtest_main)

include(GoogleTest)
gtest_discover_tests(NumberToTurkishTests)