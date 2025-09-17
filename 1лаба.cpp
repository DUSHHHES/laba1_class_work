#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm> // <-- НУЖЕН ДЛЯ std::replace
#include "TruckingCompany.h"

int main() {
    setlocale(LC_ALL, "Russian");

    TruckingCompany myCompany;
    myCompany.setCompanyName("Быстрые перевозки");

    double cost, weight;
    std::string inputLine;

    // --- Ввод стоимости за тонну ---
    while (true) {
        std::cout << "Введите стоимость перевозки за тонну (не более 15000): ";
        std::getline(std::cin, inputLine);

        // --- НОВОЕ УЛУЧШЕНИЕ: Заменяем точку на запятую для корректной работы stod в русской локали ---
        size_t dot_pos = inputLine.find('.');
        if (dot_pos != std::string::npos) {
            inputLine.replace(dot_pos, 1, ",");
        }
        // --- КОНЕЦ УЛУЧШЕНИЯ ---

        // Проверка на количество знаков после запятой
        size_t decimal_pos = inputLine.find(','); // Теперь ищем запятую
        if (decimal_pos != std::string::npos) {
            if (inputLine.length() - decimal_pos - 1 > 2) {
                std::cout << "Ошибка: Можно вводить не более двух знаков после запятой.\n";
                continue;
            }
        }

        try {
            size_t processedChars;
            cost = std::stod(inputLine, &processedChars);

            if (processedChars != inputLine.length()) {
                std::cout << "Ошибка: Ввод содержит недопустимые символы. Попробуйте снова.\n";
                continue;
            }

            if (cost <= 0 || cost > 15000) {
                std::cout << "Ошибка: Стоимость должна быть положительной и не превышать 15000.\n";
                continue;
            }

            break;

        }
        catch (const std::invalid_argument& e) {
            std::cout << "Ошибка: Введено не число. Попробуйте снова.\n";
        }
        catch (const std::out_of_range& e) {
            std::cout << "Ошибка: Введенное число слишком большое. Попробуйте снова.\n";
        }
    }
    myCompany.setCostPerTon(cost);

    // --- Ввод массы груза (с такими же исправлениями) ---
    while (true) {
        std::cout << "Введите массу перевезенных грузов (не более 500): ";
        std::getline(std::cin, inputLine);

        // --- НОВОЕ УЛУЧШЕНИЕ: Заменяем точку на запятую ---
        size_t dot_pos = inputLine.find('.');
        if (dot_pos != std::string::npos) {
            inputLine.replace(dot_pos, 1, ",");
        }
        // --- КОНЕЦ УЛУЧШЕНИЯ ---

        size_t decimal_pos = inputLine.find(',');
        if (decimal_pos != std::string::npos) {
            if (inputLine.length() - decimal_pos - 1 > 2) {
                std::cout << "Ошибка: Можно вводить не более двух знаков после запятой.\n";
                continue;
            }
        }

        try {
            size_t processedChars;
            weight = std::stod(inputLine, &processedChars);

            if (processedChars != inputLine.length()) {
                std::cout << "Ошибка: Ввод содержит недопустимые символы. Попробуйте снова.\n";
                continue;
            }

            if (weight <= 0 || weight > 500) {
                std::cout << "Ошибка: Масса должна быть положительной и не превышать 500 тонн.\n";
                continue;
            }

            break;

        }
        catch (const std::invalid_argument& e) {
            std::cout << "Ошибка: Введено не число. Попробуйте снова.\n";
        }
        catch (const std::out_of_range& e) {
            std::cout << "Ошибка: Введенное число слишком большое. Попробуйте снова.\n";
        }
    }
    myCompany.setTotalWeight(weight);


    // --- Расчет и вывод результата ---
    std::cout << "\nИнформация о фирме" << std::endl;
    std::cout << "--------------------" << std::endl;
    std::cout << "Наименование: " << myCompany.getCompanyName() << std::endl;

    double totalRevenue = myCompany.calculateRevenue();

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Общая выручка фирмы: " << totalRevenue << " руб." << std::endl;

    return 0;
}