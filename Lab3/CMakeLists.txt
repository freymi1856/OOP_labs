cmake_minimum_required(VERSION 3.10)

project(FigureProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Указываем путь к заголовочным файлам
include_directories(src)

# Добавляем исходные файлы для сборки
add_library(FigureLib
    src/figure.cpp
)

# Добавляем исполняемый файл для основной программы
add_executable(Solution src/solution.cpp)

# Линкуем библиотеку с основным исполняемым файлом
target_link_libraries(Solution PRIVATE FigureLib)

# Подключаем Google Test для тестов
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/release-1.12.1.tar.gz
)
# Загружаем Google Test
FetchContent_MakeAvailable(googletest)

enable_testing()

# Добавляем тесты
add_executable(TestFigures tests/test_figures.cpp)

# Линкуем библиотеку с тестами
target_link_libraries(TestFigures PRIVATE FigureLib gtest gtest_main)

# Добавляем тесты в проект
add_test(NAME FiguresTests COMMAND TestFigures)