#include <iostream>
#include <iomanip>
#include <string>
#include "stdint.h"
#include "Subscriptions.h"
#include "Money.h"
#include "Person.h"
#include "DateTime.h"
#include<vector>


using namespace std;


int Read() {
    int read;
    cout << "Enter an action:" << endl << "0 - to continue the day" << endl << "1 - create a service" << endl;
    cin >> read;
    return read;
}

int main() {
    Money M1(1000, 50);
    Subscriptions S1;
    Person P1(M1);
    DateTime today_time(01, 01, 2020);

    do{
        cout << "Today " << today_time.getDay() << "." << today_time.getMonth() << "." << today_time.getYear() << endl
             << "balance: " << P1.getRubBalanceMoney() << "." << P1.getKopeckBalanceMoney() << endl;
        cout << endl << setw(20) << left << "Name services" << setw(10) << left << "Prise" << setw(10) << left
             << "Time of debiting" << endl;
        P1.PrintSubscriptions();
        cout << endl;
        if (Read() == 1) P1.setSubscriptionsPersons();
        else{
            today_time.nextDay(1);
            if(!P1.OperationSubscriptions(today_time)) cout<<"Your account doesn't have enough funds"<<endl;
        }
    } while (true);
}
