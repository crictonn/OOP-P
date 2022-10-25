#include <iostream>
#include <windows.h>

using namespace std;


int get_int()
{
	int ch;
	while (true) {
		cin >> ch;
		if (cin.good())
		{
			cin.ignore(10, '\n');
			break;
		}
		cin.clear();
		cout << "Некорректный ввод! Введите ещё раз:" << endl;
		cin.ignore(10, '\n');
	}
	return ch;
}

class Converter {
	string extension;
public:
	void setExtension (string extension) {
		this->extension = extension;
	}
	void showExtension() {
		cout << "Расширение файла: " << this->extension << endl;
	}
};

template <class T>
class FileInfo : public Converter {
	T fileName;
	int quality;
public:
	void setFileName(T fileName) {
		this->fileName = fileName;
	}
	void setQuality(int quality) {
		this->quality = quality;
	}
	void showQuality() {
		cout << "Качество файла: " << this->quality << endl;
	}
	void showFileName() {
		cout << "Имя файла: " << this->fileName << endl;
	}
};

template <class T>
class Transaction
{
	T* currentState;
	T* prevState;
public:
	Transaction() :prevState(NULL), currentState(new T)
	{}
	Transaction(const Transaction& obj) : currentState(new T(*(obj.currentState))), prevState(NULL) {}
	~Transaction() {
		delete currentState; delete prevState;
	}
	int beginTransactions(string fileName, string extension, int quality);
	void showState();
	T* operator->();
	void deleteTransactions();
};

template <class T>
T* Transaction<T>::operator->() {
	return currentState;
}

template <class T>
int Transaction<T>::beginTransactions(string fileName, string extension, int quality) {
	delete prevState;
	prevState = currentState;
	currentState = new T(*prevState);
	if (!currentState) return 0;

	currentState->setFileName(fileName);
	currentState->setExtension(extension);
	currentState->setQuality(quality);

	return 1;
}

template <class T>
void Transaction<T>::deleteTransactions() {
	if (prevState != NULL) {
		delete currentState;
		currentState = prevState;
		prevState = NULL;
	}
}

template <class T>
void Transaction<T>::showState() {
	cout << "Состояние объекта:" << endl;
	if (prevState) {
		cout << "prevState = ";
		prevState->showFileName();
		prevState->showExtension();
		prevState->showQuality();
		cout << endl;

		cout << "currentState = ";
		currentState->showFileName();
		currentState->showExtension();
		currentState->showQuality();
		cout << endl;
	}
	else {
		cout << "prevState = NULL" << endl;
		cout << "currentState = ";
		currentState->showFileName();
		currentState->showExtension();
		currentState->showQuality();
		cout << endl;
	}
}

template<class T>
class SmartPointer
{
	T* smartPtr;
public:
	SmartPointer(T* ptr);
	SmartPointer(const SmartPointer& obj);
	~SmartPointer();
	T* operator->() const;
};

template<class T>
SmartPointer<T>::SmartPointer(T* ptr) {
	smartPtr = ptr;

}

template<class T>
SmartPointer<T>::~SmartPointer() {
	delete smartPtr;
}

template<class T>
SmartPointer<T>::SmartPointer(const SmartPointer& obj) {
	cout << "Конструктор копирования вызван" << endl;
}

template <class T>
T* SmartPointer<T>::operator->() const {
	if (smartPtr) return smartPtr;
	else return NULL;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	SmartPointer<FileInfo<string>> converter = new FileInfo<string>();
	Transaction<FileInfo<string>> convTrans;
	string fileName;
	string extension;
	int quality;

	cout << "Введите имя изменяемого файла: " << endl << "> ";
	cin >> fileName;

	cout << "Введите расширение файла: " << endl << "> ";
	cin >> extension;

	cout << "Введите качество файла: " << endl << "> ";
	cin >> quality;

	converter->setFileName(fileName);
	converter->setExtension(extension);
	converter->setQuality(quality);

	convTrans->setFileName(fileName);
	convTrans->setExtension(extension);
	convTrans->setQuality(quality);


	int choice;
	cout << "Хотите ли вы выполнить изменение:" << endl;
	cout << "1. Да" << endl;
	cout << "2. Нет" << endl;

	choice = get_int();
	while (true) {
		if (choice == 1 || choice == 2) {
			break;
		}
		else {
			choice = get_int();
		}
	}

	if (choice == 2) return 1;
	else {
		cout << "Введите имя изменяемого файла: " << endl << "> ";
		cin >> fileName;

		cout << "Введите расширение файла: " << endl << "> ";
		cin >> extension;

		cout << "Введите качество файла: " << endl << "> ";
		cin >> quality;
		convTrans.beginTransactions(fileName, extension, quality);
		convTrans.showState();

		cout << "Хотите ли вы выполнить отмену транзакции:" << endl;
		cout << "1. Да" << endl;
		cout << "2. Нет" << endl;
		choice = get_int();
		while (true) {
			if (choice == 1 || choice == 2) {
				break;
			}
			else {
				choice = get_int();
			}
		}
		if (choice == 2) {
			return 1;
		}
		else {
			convTrans.deleteTransactions();
			convTrans.showState();
		}
	}
}
