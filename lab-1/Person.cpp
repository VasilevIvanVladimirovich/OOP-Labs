#include <iostream>
#include "Person.h"
#include "Money.h"
using namespace std;

Person::Person(const Money& balance) :balance_(balance)
{
     cout << "Конструктор Person " << this << endl; 
}

Person::~Person() { cout << "деструктор Person " << this << endl; }

void Person::Sum(int64_t rub, uint8_t kopeck)
{
    balance_.operationSum(rub, kopeck);
}

void Person::Minus(int64_t rub, uint8_t kopeck)
{
    balance_.operationMinus(rub, kopeck);
}

void Person::Division(int64_t divider)
{
    balance_.operationDivision(divider);
}

void Person::Multiplication(int64_t multiplier)
{
    balance_.operationMultiplication(multiplier);
}

int Person::getKopeck()
{
   return balance_.getKopeck();
}

int Person::getRub() 
{
    return balance_.getRub();
}

int Person::Сomparison(int64_t rub, uint8_t kopeck) 
{
    return balance_.operationСomparison(rub, kopeck);
}

void Person::getBalance()
{
    cout << "Баланс = " << balance_.getRub() << "," << balance_.getKopeck() << endl;
}
