#ifndef LAB_OOP_PERSON_H
#define LAB_OOP_PERSON_H
#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include "stdint.h"
#include "Subscriptions.h"
#include "Money.h"
#include "Person.h"
#include "DateTime.h"
#include <vector>

class Person {
public:

    Person(const Money& balance);

    ~Person();

    void OperationSumMoney(int64_t rub, uint8_t kopeck);

    void OperationMinusMoney(int64_t rub, uint8_t kopeck);

    void OperationDivisionMoney(int64_t divider);

    void OperationMultiplicationMoney(int64_t multiplier);

    int OperationComparisonMoney(int64_t rub, uint8_t kopeck);

    void getBalance();

    int getKopeckBalanceMoney();

    int getRubBalanceMoney();

    void setSubscriptionsPersons();

    void PrintSubscriptions();

    bool OperationSubscriptions(DateTime today_time);

private:
    Money balance_;
    int size_sub=0;
    std::vector<Subscriptions> subscriptions_person;
};

#endif //LAB_OOP_PERSON_H
