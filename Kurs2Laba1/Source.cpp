#include <iostream> 
#include <stdlib.h>
#include <iomanip>
#include <string>
#include <Windows.h>

using namespace std;


class Product {
public:
	string name;
	float price, discountAmount;
	int discountPercent;
	void getData() {
		cout << "Введите наименование: ";
		cin >> name;
		cout << "Введите цену: ";
		cin >> price;
	}

	void getDiscountAmount() {
		cout << "Введите процент скидки: ";
		cin >> discountPercent;
	}


	float getDiscountPrice()
	{
		discountAmount = price * discountPercent / 100;
		return price - discountAmount;
	}

	void printDescription()
	{
		cout << "Название: " << name << " ||Цена: " << price << " ||Скидка: " << discountPercent << "% ||Цена со скидкой: " << getDiscountPrice();
	}

	Product() {
		name = "none";
		price = 0.0;
		discountPercent = 0;
	}

	~Product() {};

};



class Book : public Product {
protected: 
	string author;

public:
	void getAuthor() {
		cout << "Введите автора: ";
		cin >> author;
	}
	void printAuthor() {
		cout << "Автор: " << author;
	}
	Book() {
		author = "none";
	}
	~Book() {};
};



class Movie : public Product {
protected:
	int year;

public:
	void getYear() {
		cout << "Введите год: ";
		cin >> year;
	}
	void printYear() {
		cout << "Год: " << year;
	}
	Movie() {
		year = 2022;
	}
	~Movie() {};
};


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int k,l;
	Movie movie;
	Book book;

	while (true) {
		system("cls");
		cout << "1. Ввод информации \n2. Вывод информации \n3. Выход \n";
		cin >> k;
		switch (k) {
		case 1: 
			cout << "1. Добавление книги \n2. Добавление фильма \n3. Отмена \n";
			cin >> l;
			switch (l) {
			case 1: book.getData(); book.getDiscountAmount(); book.getAuthor(); system("pause"); break;
			case 2: movie.getData(); book.getDiscountAmount(); movie.getYear(); system("pause"); break;
			case 3: break;
			}
			break;
		case 2: 
			cout << "1. Вывод книги \n2. Вывод фильма \n3. Отмена";
			cin >> l;
			switch (l) {
			case 1: book.printDescription(); book.printAuthor(); system("pause"); break;
			case 2: movie.printDescription(); movie.printYear(); system("pause"); break;
			case 3: break;
			}
			break;
		case 3: return 0;
		default: break;

		}

	}

	return 0;
}