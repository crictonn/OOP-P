#include <windows.h>
#include <iostream>
#include <exception>

using namespace std;

enum State { begin, middle };
// классс, который конвертируют
template <class T>
class User {
    T number;
public:
    User() : number(0) {}
    void setNumber(int number) { this->number = number; }
    T getNumber() { return number; }
};
// класс конвертации
template <class T>
class Auto {
    T* currentState; //текущее значение пользователя класса
    T* prevState; //предыдущее состояние пользователя
public:
    Auto() :prevState(NULL), currentState(new T)
    {}
    Auto(const Auto& obj) : currentState(new
        T(*(obj.currentState))), prevState(NULL) {}
    ~Auto() {
        delete currentState; delete prevState;
    }
    Auto& operator=(const Auto& obj);
    void showState(State state);
    int beginAutos(int UserNumber); // начала конвертации
    void commit(); // подтверждения конвертации
    void deleteAutos(); // отката конвертации
    T* operator->();
};
template <class T>
Auto<T>& Auto<T>::operator=(const Auto<T>&
    obj) {
    if (this != &obj) { //проверка
        delete currentState; //удаление
        currentState = new T(*(obj.currentState));
    }
    return *this;
}
template <class T>
T* Auto<T>::operator->() {
    return currentState;
}
template <class T>
void Auto<T>::showState(State state) { // отображение состояния пользователя
    cout << "User state: ";
    if (!state) cout << "before Auto " << endl;
    else cout << "having done the Auto " << endl;
    if (prevState) cout << "previousValue = " << prevState->getNumber() << endl; // предыдущее состояние
    else cout << "previousValue = NULL" << endl;
    cout << "currentValue = " << currentState->getNumber() <<
        endl;
}
template <class T>
int Auto<T>::beginAutos(int UserNumber) { // начало конвертации
    delete prevState;
    prevState = currentState;
    currentState = new T(*prevState);
    if (!currentState) return 0;
    currentState->setNumber(UserNumber);
    return 1;
}
template <class T>
void Auto<T>::commit() {
    delete prevState;
    prevState = NULL;
}
template <class T>
void Auto<T>::deleteAutos() {
    if (prevState != NULL) {
        delete currentState;
        currentState = prevState;
        prevState = NULL;
    }
}
template <class T>
struct Status {
    T* ptr;//указатель на объект
    int counter;// количество ссылок на объект
};
template <class T>
class SmartPointer {
    Status<T>* smartPtr;// указатель на объект
public:
    SmartPointer(T* ptr);
    SmartPointer(const SmartPointer& obj);
    ~SmartPointer();//деструктор
    SmartPointer& operator=(const SmartPointer& obj);
    T* operator->() const;
    void showCounter() {
        cout << "Значение счетчика для объекта "
            << smartPtr << " равно: " << smartPtr->counter << endl;
    }
};
template <class T>
SmartPointer<T>::SmartPointer(T* ptr) {
    if (!ptr)
        smartPtr = NULL;
    else {
        smartPtr = new Status<T>();
        smartPtr->ptr = ptr;
        smartPtr->counter = 1;
    }
}
template <class T>
SmartPointer<T>::SmartPointer(const SmartPointer& obj)
    :smartPtr(obj.smartPtr) {
    if (smartPtr) smartPtr->counter++;
}
template <class T>
SmartPointer<T>::~SmartPointer() {
    if (smartPtr) {
        smartPtr->counter--;
        if (smartPtr->counter == 0) {
            delete smartPtr->ptr;
            delete smartPtr;
        }
    }
}
template <class T>
T* SmartPointer<T>::operator->() const {
    if (smartPtr) return smartPtr->ptr;
    else return NULL;
}
template <class T>
SmartPointer<T>& SmartPointer<T>::operator=(const SmartPointer&
    obj) {
    if (smartPtr) {
        smartPtr->counter--;
        if (smartPtr->counter == 0) {
            delete smartPtr->ptr;
            delete smartPtr;
        }
    }
    smartPtr = obj.smartPtr;
    if (smartPtr) smartPtr->counter++;
    return *this;
}
void main() {
    Auto<User<int>> firstUser;
    int balance;
    cout << "Enter initial balance" << endl;
    cin >> balance;
    try {
        if (balance <= 0) throw "Error";
    }
    catch (...) {
        cout << "Balance is lower than 0" << endl;
    }
    firstUser->setNumber(balance); //начальный баланс пользователя 
    firstUser.showState(State::begin);
    cout << "Initialization finished successfully!" << endl;
    cout << "--------------------------------------------------"
        << endl;
    int initBalance;
    cout << "Enter amount of money" << endl;
    cin >> initBalance;
    try {
        if (initBalance <= 0) throw "Error";
    }
    catch (...) {
        cout << "Amount of money is lower than 0" << endl;
    }
    cout << "First Auto started with the value of" << initBalance << endl;
    if (firstUser.beginAutos(initBalance)) { // конвертация 
        firstUser.showState(State::middle);
    }
    cout << "First Auto has finished successfully" << endl;
    cout << endl;
    cout << "--------------------------------------------------"
        << endl;
    firstUser.deleteAutos(); //отмена при ошибках
    cout << "First Auto has been cancelled" << endl;
    firstUser.commit();
    firstUser.showState(State::middle);
    cout << "--------------------------------------------------"
        << endl;
    int endBalance;
    cout << "Enter initial balance" << endl;
    cin >> endBalance;
    try {
        if (endBalance <= 0) throw "Error";
    }
    catch (...) {
        cout << "End balance is lower than 0" << endl;
    }
    cout << "Second Auto started with the value of" << endBalance << endl;
    if (firstUser.beginAutos(endBalance)) { //начало конвертации
        firstUser.showState(State::begin);
        firstUser.commit();
    }
    cout << "--------------------------------------------------"
        << endl;
    cout << "First Auto has finished successfully" << endl;
    firstUser.showState(State::middle);
}