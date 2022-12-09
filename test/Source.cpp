#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <list>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

class StudyWork
{

public:

    virtual string printWork() const = 0;

};

class Essay : public StudyWork//эссе
{

public:

    string printWork() const override
    {

        return "(литературное описание) " + this->work;

    }

    string work;

};

class Research : public StudyWork//исследование
{

public:

    string printWork() const override
    {

        return "(научное описание) " + this->work;

    }

    string work;
    int scientific_facts_amount;

};

class Creator {

public:

    virtual ~Creator() {};

    virtual StudyWork* FactoryMethod() const = 0;


    string doResearch() const
    {

        StudyWork* product = this->FactoryMethod();

        string result = "Creator: (работа переписана) " + product->printWork();

        delete product;

        return result;

    }

};

class Writer : public Creator
{

public:

    StudyWork* FactoryMethod() const override
    {

        return new Essay();

    }

};

class Scientist : public Creator
{

public:

    StudyWork* FactoryMethod() const override
    {

        Research research = Research();

        research.scientific_facts_amount++;

        return new Research(research);

    }

};

void ClientCode(const Creator& creator)
{

    cout << creator.doResearch() << endl;

}

void main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Писатель: \n";

    Creator* creator = new Writer();

    ClientCode(*creator);

    cout << std::endl;

    cout << "Ученый: \n";

    Creator* creator2 = new Scientist();

    ClientCode(*creator2);

    delete creator;
    delete creator2;

}