#include <iostream>
#include <string>
#include <iomanip>
#include "TruckingCompany.h"

int main() {
    setlocale(LC_ALL, "Russian");

    TruckingCompany myCompany;

    myCompany.setCompanyName("Быстрые перевозки");

    //только для записи
    myCompany.setCostPerTon(1500.5);
    myCompany.setTotalWeight(120.5);

    //получение данных и вызов метода для расчета
    std::cout << "Информация о фирме" << std::endl;
    std::cout << "--------------------" << std::endl;
    std::cout << "Наименование: " << myCompany.getCompanyName() << std::endl;


    double totalRevenue = myCompany.calculateRevenue();

    //вывод
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Общая выручка фирмы: " << totalRevenue << " руб." << std::endl;

    return 0;
}