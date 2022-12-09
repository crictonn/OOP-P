/*Создать возможность конструирования в приложении 5 различных
типов объектов с использованием подходов «фабрика», «фабричный метод с
аргументами», «фабричный конструктор», «полиморфная фабрика»,
«полиморфное копирование».
21. «Спортивные соревнования»
*/

#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

class Person {};
class Swimmer : public Person {};
class Runner : public Person {};    //Вот это все приколы для полиморфного метода
class Fighter : public Person {};

class Clone {
public:
    string status;
    virtual Clone* clone() const = 0;
    Clone() {
        status = "Copy worked";
    }
};
//Классы для полиморфного копирования
class Derived : public Clone {
public:
    Derived* clone() const { return new Derived(*this); }
};

enum Events { SWIMMING, MARAPHONE, MARTIALARTS };
class Event {
public:
    int amount;
    string meme;
    virtual Person* makePerson() const = 0;
    ~Event() {}
};

class Swimming : public Event {
public:
    Swimmer* makePerson() const { return new Swimmer; }
    Swimming() {
        amount = 10;
        meme = "Funny";
    };
    //Swimming(const EventSpec*) {};
};
class Maraphone : public Event {
public:
    Runner* makePerson() const { return new Runner; }   
    Maraphone() {
        amount = 100;
        meme = "Not Funny";
    };
    //Maraphone(const EventSpec*) {};
};
class Martial : public Event {
public:
    Fighter* makePerson() const { return new Fighter; }
    Martial() {
        amount = 10;
        meme = "Funny. Or is it?";
    };
    //Martial(const EventSpec*) {};
};

class EventSpec {
public:
    virtual ~EventSpec() {};
    virtual Events eventType() const = 0;
};

class SwimSpec : public EventSpec {
public:
    Events eventType() const { return SWIMMING; }
    int particapAmount;
    string name;
};

class MaraphoneSpec : public EventSpec {
public:
    Events eventType() const { return MARAPHONE; }
    int particapAmount;
    string name;
};

class MartialSpec : public EventSpec {
public:
    Events eventType() const { return MARTIALARTS; }
    int particapAmount;
    string name;
};


//Вот ето фабричный метод
Event* makeEvent(Events eventType) {
    switch (eventType) {
    case SWIMMING: return new Swimming;
    case MARAPHONE: return new Maraphone;
    case MARTIALARTS: return new Martial;
    }
}


//А воть ето фабричный метод с аргументами
//Event* makeEvent(const EventSpec* eventSpec) {
//    switch (eventSpec->eventType()) {
//    case SWIMMING: return new Swimming(static_cast<const SwimSpec*>(eventSpec));
//    case MARAPHONE: return new Maraphone(static_cast<const MaraphoneSpec*>(eventSpec));
//    case MARTIALARTS: return new Martial(static_cast<const MartialSpec*>(eventSpec));
//    }
//}




void main() {
    //SwimSpec* ss;
    MaraphoneSpec* mars;
    MartialSpec* mals;
    Event* newEvent1, * newEvent2;

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Выберите тип соревнований: \n"
        "1. Плавание\n"
        "2. Марафон\n"
        "3. Боевые искусства\n" << endl;
    int ch;
    cin >> ch;
    switch (ch)
    {
    case 1:
        newEvent1 = makeEvent(SWIMMING);
        //newEvent2 = makeEvent(ss);
        cout << newEvent1->amount << " " << newEvent1->meme << endl;
        //cout << newEvent2->amount << " " << newEvent2->meme << endl;
        break;
    case 2:
        newEvent1 = makeEvent(MARAPHONE);
        cout << newEvent1->amount << " " << newEvent1->meme << endl;
        break;
    case 3:
        newEvent1 = makeEvent(MARTIALARTS);
        cout << newEvent1->amount << " " << newEvent1->meme << endl;
        break;
    default:
        cout << "Wrong input" << endl;
        break;
    }

    Clone* b = new Derived;//получить объект
    Clone* b1 = b->clone();// создать копию объекта (полиморфное копирование)
    cout << b1->status << endl;
}
//Предположим что я что-то обновил