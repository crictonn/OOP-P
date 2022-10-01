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
        cout << "Ошибка открытия файла!" << endl;
    else {
        cout << "Введите автора" << endl;
        cin >> book.Author;
        cout << "Введите название книги" << endl;
        cin >> book.BookName;
        cout << "Введите год издания" << endl;
        cin >> book.ReleaseYear;
        cout << "Данные записаны успешно" << endl;
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
        cout << "Ошибка открытия файла!" << endl;
    else {
        cout << "Введите название книги для удаления" << endl;
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
        cout << "Выберите необходимое действие:\n1-Добавление новой книги\n2-Вывод всех книг\n3-Поиск по параметру\n4-Выход" << endl;
        cin >> x;

        switch (x)
        {
        case 1:newBook(); break;
        case 2:
            fin.open("records.dat");
            if (!fin.is_open())
                cout << "Ошибка открытия файла!" << endl;
            else {
                cout << "\n" <<
                    "Автор\t Название книги\t Дата издания " << endl;
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
                cout << "Ошибка открытия файла!" << endl;
            else {
                cout << "Введите название книги для поиска" << endl;
                cin >> searchName;
                cout << "\n" <<
                    "Автор\t Название книги\t Дата издания " << endl;
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
            cout << "Неверный ввод" << endl << system("pause"); break;
        }
    }
}




void main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Menu();
}