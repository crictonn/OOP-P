//������� list � map ��� ���������� ���������� ����������� 

#include <iostream>
#include <limits>
#include <map>
#include <list>
#include <iterator>
#include <Windows.h>
#include <stdlib.h>
#include <string>

using namespace std;

class Particapants {
public:
    int age;
    string fio, activity;

    void getData() {
        cout << "������� �������: ";
        cin.ignore(32767, '\n');
        getline(cin, fio);
        cout << "������� �������: ";
        cin >> age;
        cout << "������� ��� ������: ";
        cin.ignore(32767, '\n');
        getline(cin, activity);
    }

    Particapants() {
        age = 0;
        fio = "N/A";
        activity = "N/A";
    }
};

std::ostream& operator << (std::ostream& os, const Particapants& p)
{
    return os << p.fio << " " << p.age << " " << p.activity;
}

bool operator<(const Particapants& p1, const Particapants& p2)
{
    return (p1.fio < p2.fio) && (p1.activity < p2.activity) && (p1.age < p2.age);
}


int main() {

    int count = 0;
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    map<Particapants, int> group;
    list<Particapants> lst;
    Particapants a;


    
    while (true) {
        system("cls");
        int choice;
        cout << "������� ��� �����: \n1. ���������� ������ \n2. ����� ������ \n3. ����� �����" << endl;
        cin >> choice;

        map<Particapants, int> ::iterator it = group.begin();
        list<Particapants>::iterator listPtr = lst.begin();


        switch (choice) {
        case 1:
            a.getData();
            lst.push_back(a);
            group[a] = count;
            count++;
            system("pause");
            break;
        case 2:
            while (listPtr != lst.end()) {
                cout << *listPtr << endl;
                listPtr++;
            }
            system("pause");
            break;
        case 3:
            it = group.begin();
            for (it = group.begin(); it != group.end(); it++) {
                cout << "���� " << it->first << ", �������� " << it->second << endl;
            }
            system("pause");
            break;
        case 4:
            return 0; break;

        }
    }
}