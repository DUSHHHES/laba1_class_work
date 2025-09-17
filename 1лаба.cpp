#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm> // <-- ����� ��� std::replace
#include "TruckingCompany.h"

int main() {
    setlocale(LC_ALL, "Russian");

    TruckingCompany myCompany;
    myCompany.setCompanyName("������� ���������");

    double cost, weight;
    std::string inputLine;

    // --- ���� ��������� �� ����� ---
    while (true) {
        std::cout << "������� ��������� ��������� �� ����� (�� ����� 15000): ";
        std::getline(std::cin, inputLine);

        // --- ����� ���������: �������� ����� �� ������� ��� ���������� ������ stod � ������� ������ ---
        size_t dot_pos = inputLine.find('.');
        if (dot_pos != std::string::npos) {
            inputLine.replace(dot_pos, 1, ",");
        }
        // --- ����� ��������� ---

        // �������� �� ���������� ������ ����� �������
        size_t decimal_pos = inputLine.find(','); // ������ ���� �������
        if (decimal_pos != std::string::npos) {
            if (inputLine.length() - decimal_pos - 1 > 2) {
                std::cout << "������: ����� ������� �� ����� ���� ������ ����� �������.\n";
                continue;
            }
        }

        try {
            size_t processedChars;
            cost = std::stod(inputLine, &processedChars);

            if (processedChars != inputLine.length()) {
                std::cout << "������: ���� �������� ������������ �������. ���������� �����.\n";
                continue;
            }

            if (cost <= 0 || cost > 15000) {
                std::cout << "������: ��������� ������ ���� ������������� � �� ��������� 15000.\n";
                continue;
            }

            break;

        }
        catch (const std::invalid_argument& e) {
            std::cout << "������: ������� �� �����. ���������� �����.\n";
        }
        catch (const std::out_of_range& e) {
            std::cout << "������: ��������� ����� ������� �������. ���������� �����.\n";
        }
    }
    myCompany.setCostPerTon(cost);

    // --- ���� ����� ����� (� ������ �� �������������) ---
    while (true) {
        std::cout << "������� ����� ������������ ������ (�� ����� 500): ";
        std::getline(std::cin, inputLine);

        // --- ����� ���������: �������� ����� �� ������� ---
        size_t dot_pos = inputLine.find('.');
        if (dot_pos != std::string::npos) {
            inputLine.replace(dot_pos, 1, ",");
        }
        // --- ����� ��������� ---

        size_t decimal_pos = inputLine.find(',');
        if (decimal_pos != std::string::npos) {
            if (inputLine.length() - decimal_pos - 1 > 2) {
                std::cout << "������: ����� ������� �� ����� ���� ������ ����� �������.\n";
                continue;
            }
        }

        try {
            size_t processedChars;
            weight = std::stod(inputLine, &processedChars);

            if (processedChars != inputLine.length()) {
                std::cout << "������: ���� �������� ������������ �������. ���������� �����.\n";
                continue;
            }

            if (weight <= 0 || weight > 500) {
                std::cout << "������: ����� ������ ���� ������������� � �� ��������� 500 ����.\n";
                continue;
            }

            break;

        }
        catch (const std::invalid_argument& e) {
            std::cout << "������: ������� �� �����. ���������� �����.\n";
        }
        catch (const std::out_of_range& e) {
            std::cout << "������: ��������� ����� ������� �������. ���������� �����.\n";
        }
    }
    myCompany.setTotalWeight(weight);


    // --- ������ � ����� ���������� ---
    std::cout << "\n���������� � �����" << std::endl;
    std::cout << "--------------------" << std::endl;
    std::cout << "������������: " << myCompany.getCompanyName() << std::endl;

    double totalRevenue = myCompany.calculateRevenue();

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "����� ������� �����: " << totalRevenue << " ���." << std::endl;

    return 0;
}