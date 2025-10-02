#include "lab2_functions.h"
#include <iostream>
#include <algorithm>

std::mutex cout_mutex;
std::vector<int> numbers;
int min_value, max_value;
double average_value;

void find_min_max() {
    if (numbers.empty()) {
        std::lock_guard<std::mutex> lock(cout_mutex);
        std::cout << "min_max: Массив пуст!" << std::endl;
        return;
    }

    min_value = numbers[0];
    max_value = numbers[0];

    for (size_t i = 1; i < numbers.size(); ++i) {
        if (numbers[i] < min_value) {
            min_value = numbers[i];
        }
        if (numbers[i] > max_value) {
            max_value = numbers[i];
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(7));
    }
}

void calculate_average() {
    if (numbers.empty()) {
        std::lock_guard<std::mutex> lock(cout_mutex);
        std::cout << "average: Массив пуст!" << std::endl;
        return;
    }

    long long sum = 0;
    for (size_t i = 0; i < numbers.size(); ++i) {
        sum += numbers[i];
        std::this_thread::sleep_for(std::chrono::milliseconds(12));
    }
    average_value = static_cast<double>(sum) / numbers.size();
}

void replace_min_max_with_average() {
    if (!numbers.empty()) {
        for (int& num : numbers) {
            if (num == min_value || num == max_value) {
                num = static_cast<int>(average_value);
            }
        }
    }
}