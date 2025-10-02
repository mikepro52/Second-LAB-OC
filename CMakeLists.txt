cmake_minimum_required(VERSION 3.15)
project("LAB_2_OC")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Основная программа
add_executable(LAB_2_OC 
    "CMakeProject1.cpp"
    "lab2_functions.cpp"
)  

if(MSVC)
    target_compile_options(LAB_2_OC PRIVATE /W4)
endif()

# Тесты
enable_testing()

# Тестовый исполняемый файл
add_executable(LAB_2_OC_Tests 
    "test/test_main.cpp"
    "lab2_functions.cpp"
)

if(MSVC)
    target_compile_options(LAB_2_OC_Tests PRIVATE /W4)
endif()

# Добавить тест
add_test(NAME LAB_2_OC_Tests COMMAND LAB_2_OC_Tests)