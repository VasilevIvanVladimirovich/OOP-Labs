#include <iostream>
#include <iomanip>
#include <string>
#include "Subscriptions.h"
#include "stdint.h"
#include "Person.h"
#include "Money.h"
#include "DateTime.h"
#include<vector>
using namespace std;

Person::Person(const Money& balance) :balance_(balance){}

Person::~Person(){}

void Person::OperationSumMoney(int64_t rub, uint8_t kopeck)
{
    balance_.operationSum(rub, kopeck);
}

void Person::OperationMinusMoney(int64_t rub, uint8_t kopeck)
{
    balance_.operationMinus(rub, kopeck);
}

void Person::OperationDivisionMoney(int64_t divider)
{
    balance_.operationDivision(divider);
}

void Person::OperationMultiplicationMoney(int64_t multiplier)
{
    balance_.operationMultiplication(multiplier);
}

int Person::getKopeckBalanceMoney()
{
    return balance_.getKopeck();
}

int Person::getRubBalanceMoney()
{
    return balance_.getRub();
}

int Person::OperationComparisonMoney(int64_t rub, uint8_t kopeck)
{
    return balance_.operationComparison(rub, kopeck);
}

void Person::getBalance()
{
    cout << "Баланс = " << balance_.getRub() << "," << balance_.getKopeck() << endl;
}

void Person::setSubscriptionsPersons()
{
    subscriptions_person.push_back(Subscriptions());
    subscriptions_person[size_sub].setNameSubscriptions();
    subscriptions_person[size_sub].setPrice();
    subscriptions_person[size_sub].setKey();
    subscriptions_person[size_sub].setTime();
    size_sub++;
}

void Person::PrintSubscriptions()
{
    for(int i=0;i<size_sub;i++)
    {
        subscriptions_person[i].printInfoSubscriptions();
    }
}

bool Person::OperationSubscriptions(DateTime today_time)
{
    for(int i=0;i<size_sub;i++)
    {
        if(subscriptions_person[i].getTime()==today_time.getTime())
        {
            if(subscriptions_person[i].getFrequency_sub()==1)  subscriptions_person[i].setTime(1);
            else if(subscriptions_person[i].getFrequency_sub()==2) subscriptions_person[i].setTime(30);
            else if(subscriptions_person[i].getFrequency_sub()==3) subscriptions_person[i].setTime(360);
            if(subscriptions_person[i].getKey()==1)
            {
                OperationSumMoney(subscriptions_person[i].getRubPriceSubscriptions(),subscriptions_person[i].getKopeckPriceSubscriptions());
                return true;
            }else if(subscriptions_person[i].getKey()==2)
            {
                if(OperationComparisonMoney(subscriptions_person[i].getRubPriceSubscriptions(),subscriptions_person[i].getKopeckPriceSubscriptions())==1)
                {
                    OperationMinusMoney(subscriptions_person[i].getRubPriceSubscriptions(), subscriptions_person[i].getKopeckPriceSubscriptions());
                    return true;
                }
                else if(OperationComparisonMoney(subscriptions_person[i].getRubPriceSubscriptions(),subscriptions_person[i].getKopeckPriceSubscriptions())==2) return false;
            }else OperationMinusMoney(subscriptions_person[i].getRubPriceSubscriptions(), subscriptions_person[i].getKopeckPriceSubscriptions());
        }continue;
    }
}
