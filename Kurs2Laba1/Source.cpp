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
		cout << "������� ������������: ";
		cin >> name;
		cout << "������� ����: ";
		cin >> price;
	}

	void getDiscountAmount() {
		cout << "������� ������� ������: ";
		cin >> discountPercent;
	}


	float getDiscountPrice()
	{
		discountAmount = price * discountPercent / 100;
		return price - discountAmount;
	}

	void printDescription()
	{
		cout << "��������: " << name << " ||����: " << price << " ||������: " << discountPercent << "% ||���� �� �������: " << getDiscountPrice();
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
		cout << "������� ������: ";
		cin >> author;
	}
	void printAuthor() {
		cout << "�����: " << author;
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
		cout << "������� ���: ";
		cin >> year;
	}
	void printYear() {
		cout << "���: " << year;
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
		cout << "1. ���� ���������� \n2. ����� ���������� \n3. ����� \n";
		cin >> k;
		switch (k) {
		case 1: 
			cout << "1. ���������� ����� \n2. ���������� ������ \n3. ������ \n";
			cin >> l;
			switch (l) {
			case 1: book.getData(); book.getDiscountAmount(); book.getAuthor(); system("pause"); break;
			case 2: movie.getData(); book.getDiscountAmount(); movie.getYear(); system("pause"); break;
			case 3: break;
			}
			break;
		case 2: 
			cout << "1. ����� ����� \n2. ����� ������ \n3. ������";
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