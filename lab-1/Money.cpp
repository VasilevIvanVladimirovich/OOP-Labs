#include <iostream>
#include "Money.h"

using namespace std;

Money::Money(int64_t rub, uint8_t kopeck)
{
    cout << "Конструктор Money " << this << endl;
    rub_ = rub;
    kopeck_ = kopeck;
}

Money::~Money() { cout << "Деструктор Money " << this << endl; }

int Money::getRub() 
{
    return rub_;
}
int Money::getKopeck() 
{
    return kopeck_;
}

void Money::setBalance(int64_t rub, uint8_t kopeck)
{
    rub_ = rub;
    kopeck_ = kopeck;
}
void Money::setRub(int64_t rub)
{
    rub = rub_;
}
void Money::setKopeck(uint8_t kopeck)
{
    kopeck = kopeck_;
}

void Money::rounding()
{
    if (kopeck_ >= 100)
    {
        rub_ = rub_ + kopeck_ / 100;
        kopeck_ %= 100;
    }
}

void Money::operationSum(int64_t rub, uint8_t kopeck)
{
    rub_ += rub;
    kopeck_ += kopeck;
    rounding();
}
void Money::operationMinus(int64_t rub, uint8_t kopeck)
{
    if (rub_ - rub < 0)
    {

        throw invalid_argument("Нехватает денег в балансе для операции вычитания");
    }
    else rub_ -= rub;
    if (kopeck_ < kopeck)
    {
        if (rub_ - 1 < 0)
        {
            throw invalid_argument("Нехватает денег в балансе для операции вычитания");
        }
        else rub_ -= 1;
        kopeck_ = 100 - (kopeck - kopeck_);

    }
    else kopeck_ -= kopeck;

}
void Money::operationDivision(int64_t divider)
{
    if (divider <= 0) throw invalid_argument("Нельзя делить на 0 ");
    rub_ /= divider;
    kopeck_ /= divider;
}
void Money::operationMultiplication(int64_t multiplier)
{
    if (kopeck_ * multiplier > 255)
    {
        rub_ *= multiplier;
        int kopeck;
        kopeck = kopeck_ * multiplier;
        rub_ = rub_ + kopeck / 100;
        kopeck_ = kopeck % 100;
    }
    else
    {
        rub_ *= multiplier;
        kopeck_ *= multiplier;
        rounding();
    }

}
int Money::operationСomparison(int64_t rub, uint8_t kopeck)
{
    if (rub_ == rub && kopeck_ == kopeck) return 0;
    if (rub_ > rub) return 1;
    if (rub_ < rub) return 2;
    if (kopeck_ > kopeck) return 1;
    if (kopeck_ < kopeck) return 2;
}
