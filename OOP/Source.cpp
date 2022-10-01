#define _CRT_SECURITY_NO_WARNINGS
#pragma warning(disable:4996)
#include <iostream> 
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;


class library {
public:
    int ReleaseYear;
    string BookName;
    string Author;

    library() {
        ReleaseYear = 0;
        BookName = "name";
        Author = "author";
    }

    library(int ReleaseYear, string BookName, string Author) {
        this->ReleaseYear = ReleaseYear;
        this->BookName = BookName;
        this->Author = Author;
    }

    void print() {
        cout << Author << "\t\t" << BookName << "\t\t" << ReleaseYear << endl;

    }
};
void newBook() {
    library book;
    ofstream fout;
    fout.open("records.dat", ofstream::app);
    if (!fout.is_open())
        cout << "������ �������� �����!" << endl;
    else {
        cout << "������� ������" << endl;
        cin >> book.Author;
        cout << "������� �������� �����" << endl;
        cin >> book.BookName;
        cout << "������� ��� �������" << endl;
        cin >> book.ReleaseYear;
        cout << "������ �������� �������" << endl;
        system("pause");
        fout.write((char*)&book, sizeof(library));
    }
    fout.close();
}
void deletebook() {
    library book;
    fstream f;
    string deleteName;
    f.open("records.dat");
    if (!f.is_open())
        cout << "������ �������� �����!" << endl;
    else {
        cout << "������� �������� ����� ��� ��������" << endl;
        cin >> deleteName;
        while (f.read((char*)&book, sizeof(library))) {
            if (deleteName == book.BookName) {
                //book.erase(book.begin()+;
            }

        }
    }
}



int Menu() {
    int x;
    library arr;
    ifstream fin;
    string searchName;

    while (1) {
        system("cls");
        cout << "�������� ����������� ��������:\n1-���������� ����� �����\n2-����� ���� ����\n3-����� �� ���������\n4-�����" << endl;
        cin >> x;

        switch (x)
        {
        case 1:newBook(); break;
        case 2:
            fin.open("records.dat");
            if (!fin.is_open())
                cout << "������ �������� �����!" << endl;
            else {
                cout << "\n" <<
                    "�����\t �������� �����\t ���� ������� " << endl;
                while (fin.read((char*)&arr, sizeof(library))) {
                    arr.print();
                }
            }
            system("pause");
            fin.close();
            break;
        case 3:
            fin.open("records.dat");
            if (!fin.is_open())
                cout << "������ �������� �����!" << endl;
            else {
                cout << "������� �������� ����� ��� ������" << endl;
                cin >> searchName;
                cout << "\n" <<
                    "�����\t �������� �����\t ���� ������� " << endl;
                while (fin.read((char*)&arr, sizeof(library))) {
                    if (searchName == arr.BookName)
                    {
                        arr.print();
                    }
                }
            }
            system("pause"); break;
        case 4: return 0; break;
        default:
            cout << "�������� ����" << endl << system("pause"); break;
        }
    }
}




void main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Menu();
}