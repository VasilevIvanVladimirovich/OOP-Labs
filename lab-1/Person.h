#pragma once

using namespace std;

class Person {
public:

    Person() { cout << "Конструктор Person " << this << endl; }

    ~Person() { cout << "деструктор Person " << this << endl; }

    void setBalance(int64_t rub, uint8_t kopeck)
    {
        double D_kopeck;
        D_kopeck = (double)kopeck / 100;
        balance_ = (double)rub + D_kopeck;
        
    }
    double getBalance()
    {
        return balance_;
    }

private:
    double balance_;
};
