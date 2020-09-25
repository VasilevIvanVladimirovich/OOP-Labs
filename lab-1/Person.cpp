#include <iostream>
#include "Person.h"
#include "Money.h"
using namespace std;

Person::Person(const Money balance) :balance_(balance)
{
     cout << "Конструктор Person " << this << endl; 
}

Person::~Person() { cout << "деструктор Person " << this << endl; }

void Person::getBalance(const Money balance)
{
    this->balance_ = balance;
    cout << "Баланс = " << balance_.getRub() << "," << balance_.getKopeck() << endl;
}
