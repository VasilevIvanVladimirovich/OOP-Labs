#pragma once
#include "Money.h"
#include "Service.h"
using namespace std;

class Person {
public:

    Person(const Money& balance);
   
    ~Person();
    
    void Sum(int64_t rub, uint8_t kopeck);

    void Minus(int64_t rub, uint8_t kopeck);

    void Division(int64_t divider);

    void Multiplication(int64_t multiplier);

    int Сomparison(int64_t rub, uint8_t kopeck);

    void getBalance();

    int getKopeck();

    int getRub();
   
private:
    Money balance_;
};
