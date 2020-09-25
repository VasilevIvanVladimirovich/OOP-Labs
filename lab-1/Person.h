#pragma once
#include "Money.h"
using namespace std;

class Person {
public:

    Person(const Money balance);
   
    ~Person();
    
    void getBalance(const Money balance);
   
private:
    Money balance_;
};
