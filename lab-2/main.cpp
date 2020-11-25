#include <iostream>
#include <iomanip>
#include <string>
#include "stdint.h"
#include "Money.h"
#include "Person.h"
#include "Subscriptions.h"
#include "DateTime.h"
using namespace std;


int Read()
{
    int read;
    cout<<"Enter an action:"<<endl<<"0 - to continue the day"<<endl<<"1 - create a service"<<endl;
    cin>>read;
    return read;
}
 void tableServices(Subscriptions *buff)
 {
    for(int i=0;i<20;i++)
    {
        if(!buff[i].emptySubscriptions()) buff[i].printInfoSubscriptions();
    }
 }



int main()
{
    setlocale(LC_ALL, "rus");
    Money M1(1000,50);//создание кошелька
    Person P1(M1);//присвоение кошелька к персоне
    DateTime today_time(01,01,2020);
    Subscriptions buff_services[20];
  do
    {
        cout<<"Today " <<today_time.getDay()<<"."<<today_time.getMonth()<<"."<<today_time.getYear()<<endl<<"balance: " << P1.getRubBalanceMoney()<<"."<<P1.getKopeckBalanceMoney()<<endl;
        cout<<endl<<setw(20)<<left<<"Name services"<<setw(10)<<left<<"Prise"<<setw(10)<<left<<"Time of debiting"<<endl;
        tableServices(buff_services);
        cout<<endl;
       if(Read()==1)
       {
           for(int len=0;len<20;len++)
           {
               if(buff_services[len].emptySubscriptions())
               {
                   buff_services[len].setNameSubscriptions();
                   buff_services[len].setPrice();
                   buff_services[len].setKey();
                   buff_services[len].setTime();
                   break;
               }else continue;
           }
       } else
           {
           today_time.nextDay(1);
           for(int i=0;i<20;i++)
           {
               if(buff_services[i].getTime()==today_time.getTime())
               {
                   if(!buff_services[i].balanceOperation(&P1))
                   {
                       std::cout << "Your account doesn't have enough funds";
                       return 0;
                   }
               }
               else continue;
           }
            }
    }while (true);
}
