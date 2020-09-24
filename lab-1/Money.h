#pragma once

using namespace std;

class Money {
public:

    Money(int64_t rub, uint8_t kopeck)
    { cout << "Конструктор Money " << this << endl;
    rub_ = rub;
    kopeck_ = kopeck;
    }

    ~Money() { cout << "Деструктор Money " << this << endl; }

    int getRub()
    {
        return rub_;
    }
    int getKopeck()
    {
        return kopeck_;
    }

    void setBalance(int64_t rub, uint8_t kopeck)
    {
        rub_ = rub;
        kopeck_ = kopeck;
    }
    void setRub(int64_t rub)
    {
        rub = rub_;
    }
    void setKopeck(uint8_t kopeck)
    {
        kopeck = kopeck_;
    }

    void rounding()
    {
        if (kopeck_ >= 100)
        {
            rub_ = rub_ + kopeck_ / 100;
            kopeck_ %= 100;
        }
    }

    void operationSum(int64_t rub, uint8_t kopeck)
    {
        rub_ += rub;
        kopeck_ += kopeck;
        rounding();
    }
    void operationMinus(int64_t rub, uint8_t kopeck)
    {
        cout << kopeck_ - kopeck << endl;
        if(rub_ - rub < 0)
        {
            
            throw invalid_argument("Нехватает денег в балансе для операции вычитания");
        }else rub_ -= rub;
        if (kopeck_ - kopeck < 0)
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
    void operationDivision(int64_t divider)
    {
        if (divider <= 0) throw invalid_argument("Нельзя делить на 0 ");
        rub_ /= divider;
        kopeck_ /= divider;
    }
    void operationMultiplication(int64_t multiplier)
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
    int operationСomparison(int64_t rub, uint8_t kopeck)
    {
        if (rub_ == rub && kopeck_ == kopeck) return 0;
        if (rub_ > rub) return 1;
        if (rub_ < rub) return 2;
        if (kopeck_ > kopeck) return 1;
        if (kopeck_ < kopeck) return 2;
    }

protected:
    int64_t rub_;
    uint8_t kopeck_;
};
