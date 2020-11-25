ifndef LAB_OOP_MONEY_H
#define LAB_OOP_MONEY_H
#pragma once
#include "stdint.h"

class Money {
public:

    Money(int64_t rub, uint8_t kopeck);

    ~Money();

    int getRub();

    int getKopeck();

    void setBalance(int64_t rub, uint8_t kopeck);

    void setRub(int64_t rub);

    void setKopeck(uint8_t kopeck);

    void rounding();

    void operationSum(int64_t rub, uint8_t kopeck);

    void operationMinus(int64_t rub, uint8_t kopeck);

    void operationDivision(int64_t divider);

    void operationMultiplication(int64_t multiplier);

    int operationComparison(int64_t rub, uint8_t kopeck);

protected:
    int64_t rub_;
    uint8_t kopeck_;
};

#endif //LAB_OOP_MONEY_H
