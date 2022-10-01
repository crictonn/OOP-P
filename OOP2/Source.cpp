#define _CRT_SECURITY_NO_WARNINGS
#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;
class ArrayFloat {

private:
    int size;
    float* pnt;

public:

    ArrayFloat()
    {
        size = 0;
        pnt = new float[size];

    }

    ArrayFloat(int size)
    {
        this->size = size;
        this->pnt = new float[size];

    }

    ArrayFloat(const ArrayFloat& mass) :size(mass.size), pnt(mass.pnt)
    {
        size = mass.size;
        pnt = new float[size];
        for (int i = 0; i < size; i++) {
            pnt[i] = mass.pnt[i];
            cout << "Copy constructor worked here!\n";
        }
    }

    ~ArrayFloat() {
        delete[]pnt;
    }

    void setter(int x) {
        size = x;
        for (int i = 0; i < size; i++) {
            std::cout << "������� " << i + 1 << " ������� �������: ";
            std::cin >> pnt[i];
        }
        system("pause");
    }
    int getSize() {
        return size;
    }
    float getMass() {
        return *pnt;
    }

    void printmass() {
        std::cout << "\n";
        for (int i = 0; i < size; i++)
        {
            std::cout << pnt[i] << "\t";
        }
        system("pause");
    }

    void printnumelement() {
        int a;
        cout << "\n������� ����� �������� ��� ������: ";
        cin >> a;
        cout << a << " �������� ����� " << pnt[a - 1];
    }

    friend ArrayFloat operator / (const ArrayFloat& mass, const ArrayFloat& mass1);
};

ArrayFloat operator / (const ArrayFloat& mass, const ArrayFloat& mass1)
{
    return ArrayFloat(mass.pnt[0] / mass1.pnt[0]);
}


int menu() {
    int a, x, size1, i, n;
    ArrayFloat mass(0), mass1(0), massDel(0);
    massDel = mass / mass1;
    while (true) {
        system("cls");
        cout << "������� �����: \n1) C������� �������\n2) ����� �������\n3) ����� ������������� ��������\n";
        cin >> a;
        switch (a)
        {
        case 1:cout << "������� ����� �������: ";
            cin >> x;
            mass.setter(x); break;
        case 2: mass.printmass(); break;
        case 3: mass.printnumelement(); break;
        case 4:
            cout << "������� ����� ������� �������: ";
            cin >> size1;
            mass1.setter(size1);
            if (size1 > mass.getSize()) {
                n = mass.getSize();
                for (i = 0; i < n; i++) {
                    massDel = mass / mass1;
                    massDel.printmass();
                }
            }
            break;
        case 5: return 0;
        default:
            cout << "�������� ����" << endl;
            break;
        }
    }
}

void main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    menu();
}