#ifndef LAB_OOP_SUBSCRIPTIONS_H
#define LAB_OOP_SUBSCRIPTIONS_H
#include <iostream>
#include <string>
#include "stdint.h"
#include "DateTime.h"
#include "Person.h"
#include "Money.h"
#pragma once

class Subscriptions
{
public:
   void setNameSubscriptions();

   void setPrice();

   void setKey();

   void setTime();

   void printInfoSubscriptions();

   std::string getNameSubscriptions();

   std::string getPrice();

   std::string getTime();

    Subscriptions();

    int emptySubscriptions();

    int balanceOperation(Person *P1);

private:
    std::string name_subscriptions;
    DateTime time;
    Money price;
    int key;
    int frequency_sub;
};
#endif //LAB_OOP_SUBSCRIPTIONS_H
