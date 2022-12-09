//21. queue, stack, priority_queue          Учет объектов недвижимости

#include <iostream>
#include <limits>
#include <queue>
#include <stack>
#include <iterator>
#include <Windows.h>
#include <string>

using namespace std;

class RealEstate {
public:
    string name, adress;
    float price;

    RealEstate() {
        name = adress = "N/A";
        price = 0;
    }
};

bool operator< (const RealEstate& st1, const RealEstate& st2) {
    return st1.price > st2.price;
}

bool operator> (const RealEstate& st1, const RealEstate& st2) {
    return st1.price < st2.price;
}


std::ostream& operator << (std::ostream& os, const RealEstate& p)
{
    return os << p.name << " " << p.adress << " " << p.price;
}

int main() {

    int ch = 0;
    RealEstate est, elem;
    queue <RealEstate> queueRE, tempQueue;
    stack <RealEstate> stRE, tempSt;
    priority_queue <RealEstate> pqRE, tempPq;

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    while (TRUE) {
        cout << "1. Создание" << endl;
        cout << "2. Вывод" << endl;
        cout << "3. Выход" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Введите название недвижимости: ";
            getchar();
            getline(cin, est.name);
            cout << "Адрес ";
            getline(cin, est.adress);
            cout << "Цена ";
            cin >> est.price;
            queueRE.push(est);
            stRE.push(est);
            pqRE.push(est);
            break;
        case 2:
            system("cls");
            tempQueue = queueRE;
            cout << "Queue: " << endl;
            while (!tempQueue.empty()) {
                cout << tempQueue.front() << endl;
                tempQueue.pop();
            }
            cout << '\n';

            tempSt = stRE;
            cout << "Stack: " << endl;
            while (!tempSt.empty()) {
                cout << tempSt.top() << endl;
                tempSt.pop();
            }
            cout << '\n';

            tempPq = pqRE;
            cout << "Priority queue: " << endl;
            while (!tempPq.empty()) {
                cout << tempPq.top() << endl;
                tempPq.pop();
            }
            cout << '\n';
            break;
        case 3: return 0; break;
        default:
            cout << "Неверный ввод\n";
            break;
        }
    }
}