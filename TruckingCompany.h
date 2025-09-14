#pragma once
#ifndef TRUCKINGCOMPANY_H
#define TRUCKINGCOMPANY_H

#include <string>

class TruckingCompany {
private:
    // поля класса
    std::string companyName;
    double costPerTon;
    double totalWeight;

public:
    TruckingCompany() : costPerTon(0.0), totalWeight(0.0) {}

    //часть свойства для чтения/записи
    void setCompanyName(const std::string& name) {
        companyName = name;
    }


    std::string getCompanyName() const {
        return companyName;
    }


    //чтобы сделать свойство только для записи, нуежн сеттер.
    void setCostPerTon(double cost) {
        if (cost > 0) { //проверка корректности данных
            costPerTon = cost;
        }
    }


    void setTotalWeight(double weight) {
        if (weight >= 0) {
            totalWeight = weight;
        }
    }


    //выручки=а фирмы
    double calculateRevenue() const {
        return costPerTon * totalWeight;
    }
};

#endif