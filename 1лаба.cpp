#include <iostream>
#include <string>
#include <iomanip>
#include "TruckingCompany.h"

int main() {
    setlocale(LC_ALL, "Russian");

    TruckingCompany myCompany;

    myCompany.setCompanyName("������� ���������");

    //������ ��� ������
    myCompany.setCostPerTon(1500.5);
    myCompany.setTotalWeight(120.5);

    //��������� ������ � ����� ������ ��� �������
    std::cout << "���������� � �����" << std::endl;
    std::cout << "--------------------" << std::endl;
    std::cout << "������������: " << myCompany.getCompanyName() << std::endl;


    double totalRevenue = myCompany.calculateRevenue();

    //�����
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "����� ������� �����: " << totalRevenue << " ���." << std::endl;

    return 0;
}