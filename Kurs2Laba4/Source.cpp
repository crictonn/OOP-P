#include <iostream> 
#include <stdlib.h>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

string path1 = "book.txt", path2="mov.txt";

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
		cout << "��������: " << name << " ||����: " << price << " ||������: " << discountPercent << "% ||���� �� �������: " << getDiscountPrice() << "||";
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
		cout << "�����: " << author << endl;
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
		cout << "���: " << year << endl;
	}
	Movie() {
		year = 2022;
	}
	~Movie() {};
};


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int k, l;
	Movie movie, mv;
	Book book, bk;

	while (true) {
		system("cls");
		cout << "1. ���� ���������� \n2. ����� ���������� \n3. ����� \n";
		cin >> k;
		ofstream fout;
		ifstream fin;
		switch (k) {
		case 1:
			if (fout.good()) {	
				cout << "1. ���������� ����� \n2. ���������� ������ \n3. ������ \n";
				cin >> l;
				switch (l) {
				case 1:
					fout.open(path1, ios::binary);
					book.getData(); book.getDiscountAmount(); book.getAuthor(); system("pause"); fout.write(reinterpret_cast<char*>(&book), sizeof(Book));
					fout.close(); break;
				case 2: fout.open(path2, ios::binary);
					movie.getData(); movie.getDiscountAmount(); movie.getYear(); system("pause"); fout.write(reinterpret_cast<char*>(&movie), sizeof(Movie));
					fout.close(); break;
				case 3: break;
				}
			}
			fout.close();
			break;
		case 2:
			cout << "1. ����� ����� \n2. ����� ������ \n3. ������\n";
			cin >> l;
			switch (l) {
			case 1:
				fin.open(path1, ios::binary);
				if (!fin){ cout << "������ �������� �����\n" << endl; system("pause");
			}
				else {
					while (fin.read((char*)&bk, sizeof(Book)))
					{
						bk.printDescription(); bk.printAuthor();
					};
					system("pause");
					fin.close();
				}
				break;
			case 2:
				fin.open(path2, ios::binary);
				if (!fin) {
					cout << "������ �������� �����\n" << endl; system("pause");
			}
				else {
					while (fin.read((char*)&mv, sizeof(Movie)))
					{
						mv.printDescription(); mv.printYear();
					};
					system("pause");
					fin.close(); 
				}
				break;
			case 3: break;
			}
			break;
		case 3: return 0;
		default: break;

		}

	}

	return 0;
}