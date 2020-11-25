#ifndef LAB_OOP_PERSON_H
#define LAB_OOP_PERSON_H
#pragma once
#include "Money.h"
#include "stdint.h"


class Person {
public:

    Person(const Money& balance);

    Person();

    ~Person();

    void OperationSumMoney(int64_t rub, uint8_t kopeck);

    void OperationMinusMoney(int64_t rub, uint8_t kopeck);

    void OperationDivisionMoney(int64_t divider);

    void OperationMultiplicationMoney(int64_t multiplier);

    int OperationComparisonMoney(int64_t rub, uint8_t kopeck);

    void getBalance();

    int getKopeckBalanceMoney();

    int getRubBalanceMoney();

private:
    Money balance_;
};





#endif //LAB_OOP_PERSON_H
