#pragma once
#include <vector>
#include <thread>
#include <chrono>
#include <mutex>

extern std::mutex cout_mutex;
extern std::vector<int> numbers;
extern int min_value, max_value;
extern double average_value;

// Функции для тестирования
void find_min_max();
void calculate_average();
void replace_min_max_with_average();