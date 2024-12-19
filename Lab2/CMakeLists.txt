cmake_minimum_required(VERSION 3.10)
project(ThreeProject)

# Установка стандартов C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Добавление Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/release-1.12.1.zip
)
# Для упрощения отключаем установку gtest
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Установка исходников
add_library(ThreeLib src/three.cpp)

# Основная программа (если требуется)
add_executable(ThreeApp src/solution.cpp)
target_link_libraries(ThreeApp PRIVATE ThreeLib)

# Тесты
enable_testing()
add_executable(ThreeTests tests/test_three.cpp)
target_include_directories(ThreeTests PRIVATE ${CMAKE_SOURCE_DIR}/src)
target_link_libraries(ThreeTests PRIVATE ThreeLib gtest_main)

include(GoogleTest)
gtest_discover_tests(ThreeTests)