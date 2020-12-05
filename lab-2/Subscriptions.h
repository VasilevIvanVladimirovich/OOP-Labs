#ifndef LAB_OOP_SUBSCRIPTIONS_H
#define LAB_OOP_SUBSCRIPTIONS_H
#include <iostream>
#include <string>
#include "stdint.h"
#include "DateTime.h"
#include "Money.h"
#include <vector>
#pragma once

class Subscriptions
{
public:

    void setNameSubscriptions();

   void setPrice();

   void setKey();

   void setTime();

   void setTime(int day);

   void printInfoSubscriptions();

   std::string getNameSubscriptions();

   std::string getPrice();

   std::string getTime();

    Subscriptions();

    ~Subscriptions();

    int getFrequency_sub();

    int getKey();

    int emptySubscriptions();

    int64_t getRubPriceSubscriptions();

    uint8_t getKopeckPriceSubscriptions();

    void setSubscriptions();


private:
    std::string name_subscriptions;
    DateTime time;
    Money price = Money(0, 0);
    int key;
    int frequency_sub;
};
#endif //LAB_OOP_SUBSCRIPTIONS_H
