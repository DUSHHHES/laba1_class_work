#pragma once
#ifndef TRUCKINGCOMPANY_H
#define TRUCKINGCOMPANY_H

#include <string>

class TruckingCompany {
private:
    // ���� ������
    std::string companyName;
    double costPerTon;
    double totalWeight;

public:
    TruckingCompany() : costPerTon(0.0), totalWeight(0.0) {}

    //����� �������� ��� ������/������
    void setCompanyName(const std::string& name) {
        companyName = name;
    }


    std::string getCompanyName() const {
        return companyName;
    }


    //����� ������� �������� ������ ��� ������, ����� ������.
    void setCostPerTon(double cost) {
        if (cost > 0) { //�������� ������������ ������
            costPerTon = cost;
        }
    }


    void setTotalWeight(double weight) {
        if (weight >= 0) {
            totalWeight = weight;
        }
    }


    //�������=� �����
    double calculateRevenue() const {
        return costPerTon * totalWeight;
    }
};

#endif