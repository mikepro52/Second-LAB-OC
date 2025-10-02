#include <iostream>
#include <vector>
#include <cassert>
#include "../lab2_functions.h"

void test_find_min_max() {
    std::cout << "Test 1 min/max..." << std::endl;

    
    numbers = { 5, 2, 8, 1, 9 };
    find_min_max();
    assert(min_value == 1);
    assert(max_value == 9);
    std::cout << "✓ Min/Max right: min=" << min_value << ", max=" << max_value << std::endl;

    
    numbers = { -5, -2, -8, -1, -9 };
    find_min_max();
    assert(min_value == -9);
    assert(max_value == -1);
    std::cout << "✓ - correct" << std::endl;
    
    numbers = { 42 };
    find_min_max();
    assert(min_value == 42);
    assert(max_value == 42);
    std::cout << "✓ 1 element mass right" << std::endl;
}

void test_calculate_average() {
    std::cout << "\nTest 2 average" << std::endl;

    
    numbers = { 1, 2, 3, 4, 5 };
    calculate_average();
    assert(average_value == 3.0);
    std::cout << "✓ average right: " << average_value << std::endl;

    
    numbers = { 1, 2, 3, 4 };
    calculate_average();
    assert(average_value == 2.5);
    std::cout << "✓ drobn average right: " << average_value << std::endl;

    // Тест с отрицательными числами
    numbers = { -2, -1, 0, 1, 2 };
    calculate_average();
    assert(average_value == 0.0);
    std::cout << "✓ average minus right:" << std::endl;
}

void test_replace_min_max() {
    std::cout << "\nTest 3: min/max on average..." << std::endl;

    numbers = { 1, 2, 3, 4, 5 };
    find_min_max();
    calculate_average();

    std::vector<int> original = numbers;
    replace_min_max_with_average();

    assert(numbers[0] == 3);  
    assert(numbers[4] == 3);  
    assert(numbers[1] == 2);  
    assert(numbers[2] == 3);
    assert(numbers[3] == 4);

    std::cout << "✓ Change right" << std::endl;
    std::cout << "  Исходный массив: ";
    for (int n : original) std::cout << n << " ";
    std::cout << "\n  После замены: ";
    for (int n : numbers) std::cout << n << " ";
    std::cout << std::endl;
}

void test_edge_cases() {
    std::cout << "\nТест 4: Граничные случаи..." << std::endl;

    
    numbers = {};
    find_min_max();
    calculate_average();
    replace_min_max_with_average();
    std::cout << "✓ Пустой массив обработан" << std::endl;

    
    numbers = { 5, 5, 5, 5 };
    find_min_max();
    calculate_average();
    replace_min_max_with_average();
    assert(numbers[0] == 5);
    assert(numbers[1] == 5);
    std::cout << "✓ Массив с одинаковыми элементами обработан" << std::endl;
}

int main() {
    std::cout << "=== Запуск Unit Tests для LAB_2_OC ===" << std::endl;

    try {
        test_find_min_max();
        test_calculate_average();
        test_replace_min_max();
        test_edge_cases();

        std::cout << "\n=== Все тесты пройдены успешно! ===" << std::endl;
        return 0;
    }
    catch (const std::exception& e) {
        std::cout << "\n=== Тест провален: " << e.what() << " ===" << std::endl;
        return 1;
    }
}