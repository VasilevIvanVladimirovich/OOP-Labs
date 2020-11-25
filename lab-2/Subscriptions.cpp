#include <iostream>
#include <iomanip>
#include <string>
#include "stdint.h"
#include <cstdlib>
#include "Subscriptions.h"

void Subscriptions::setNameSubscriptions()
{

        std::cout<<"Enter a subscription name: ";
        std::cin>>name_subscriptions;
        std::cout<<std::endl;
}

void Subscriptions::setPrice()
{
    int r;
    int k;
    std::cout<<"Enter you price services"<<std::endl<<"Enter rub:";
    std::cin>>r;
    std::cout<<"Enter Kopeck:";
    std::cin>>k;
    price.setBalance(r,k);
    std::cout<<std::endl;
}

void Subscriptions::setKey()
{
    std::cout<<"Enter action operation"<<std::endl<<"If you want add money to your account write 1 "<<std::endl<<"If you want to winthdraw from your account write 2"<<std::endl;
    std::cin>>key;
    std::cout<<std::endl;
}


void Subscriptions::setTime()
{
    int d;
    std::cout<<"Enter Day: ";
    std::cin>>d;
    std::cout<<std::endl;
    time.setDay(d);

    std::cout<<"Enter Month: ";
    std::cin>>d;
    std::cout<<std::endl;
    time.setMonth(d);

    std::cout<<"Enter year: ";
    std::cin>>d;
    std::cout<<std::endl;
    time.setYear(d);

    std::cout<<"Enter the service frequency: "<<std::endl<<"Enter 1 if the service is daily"<<std::endl<<"Enter 2 if the service is monthly"<<std::endl<<"Enter 3 if the service is year-round"<<std::endl;
    std::cin>>frequency_sub;
    std::cout<<std::endl;
}


Subscriptions::Subscriptions():price(0,0)
{
    name_subscriptions="-";
}

std::string Subscriptions::getNameSubscriptions()
{
    return name_subscriptions;
}

std::string Subscriptions::getPrice()
{
    std::string price;
    if(key==1)
    {
        return price="+"+std::to_string(this->price.getRub())+"."+std::to_string(this->price.getKopeck());
    }else if(key==2) return price="-"+std::to_string(this->price.getRub())+"."+std::to_string(this->price.getKopeck());
}

void Subscriptions::printInfoSubscriptions()
{
    std::cout<<std::endl<<std::setw(20)<<std::left<<getNameSubscriptions()<<std::setw(10)<<std::left<<getPrice()<<time.getDay()<<"."<<time.getMonth()<<"."<<time.getYear()<<std::endl;
}

int Subscriptions::emptySubscriptions()
{
    if(name_subscriptions=="-") return 1;
    else return 0;
}
std::string Subscriptions::getTime()
{
    std::string str,day=std::to_string(time.getDay()),month=std::to_string(time.getMonth()),year=std::to_string(time.getYear());
    str=day+"."+month+"."+year;
    return str;
}

int Subscriptions::balanceOperation(Person *P1)
{
    if(frequency_sub==1) time.nextDay(1);
    else if(frequency_sub==2) time.nextDay(30);
    else if(frequency_sub==3) time.nextDay(360);
        if(key==1)
        {
            P1->OperationSumMoney(price.getRub(),price.getKopeck());
            return 1;
        }else if(key==2)
        {
            if(P1->OperationComparisonMoney(price.getRub(),price.getKopeck())==1)
            {
                P1->OperationMinusMoney(price.getRub(), price.getKopeck());
                return 1;
            }
            else if(P1->OperationComparisonMoney(price.getRub(),price.getKopeck())==2) return 0;
        }else P1->OperationMinusMoney(price.getRub(), price.getKopeck());
}
