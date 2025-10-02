#include "lab2_functions.h"
#include <iostream>
#include <thread>

void min_max_thread() {
    find_min_max();
    std::lock_guard<std::mutex> lock(cout_mutex);
    std::cout << "min_max поток: минимальный элемент = " << min_value
        << ", максимальный элемент = " << max_value << std::endl;
}

void average_thread() {
    calculate_average();
    std::lock_guard<std::mutex> lock(cout_mutex);
    std::cout << "average поток: среднее арифметическое = " << average_value << std::endl;
}

int main() {
    setlocale(LC_ALL, "Russian");

    std::cout << "Лабораторная работа №2: Создание потоков" << std::endl;
    std::cout << "=========================================" << std::endl;

    int size;
    std::cout << "Введите размерность массива: ";
    std::cin >> size;

    if (size <= 0) {
        std::cout << "Ошибка: размерность массива должна быть положительным числом!" << std::endl;
        return 1;
    }

    numbers.resize(size);
    std::cout << "Введите " << size << " элементов массива:" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << "Элемент [" << i << "]: ";
        std::cin >> numbers[i];
    }

    std::cout << "\nИсходный массив: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "\nЗапуск потоков min_max и average..." << std::endl;

    std::thread min_max_th(min_max_thread);
    std::thread average_th(average_thread);

    min_max_th.join();
    average_th.join();

    std::cout << "\nОба потока завершили работу." << std::endl;

    if (!numbers.empty()) {
        int replaced_count = 0;
        std::vector<int> original_numbers = numbers;

        replace_min_max_with_average();

        for (size_t i = 0; i < numbers.size(); ++i) {
            if (original_numbers[i] != numbers[i]) {
                replaced_count++;
            }
        }

        std::cout << "\nРезультат после замены:" << std::endl;
        std::cout << "Заменено элементов: " << replaced_count << std::endl;
        std::cout << "Измененный массив: ";
        for (int num : numbers) {
            std::cout << num << " ";
        }
        std::cout << std::endl;

        std::cout << "Среднее значение: " << average_value << std::endl;
        std::cout << "Минимальное значение (было): " << min_value << std::endl;
        std::cout << "Максимальное значение (было): " << max_value << std::endl;
    }

    std::cout << "\nПрограмма завершена." << std::endl;
    return 0;
}