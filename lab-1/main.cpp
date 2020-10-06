#include <iostream>
#include "Money.h"
#include "Person.h"
#include "Service.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    Money M1(5,60);
    Person P1(M1);
    P1.Sum(5,51);
    try
    {
       P1.Minus(4,20); 
       //P1.Division(2);
    }
    catch (invalid_argument& e)
    {
        cerr << e.what() << endl;
        return -1;
    }
   // if (P1.Сomparison(30, 50)==0) cout << P1.getRub() << "," << P1.getKopeck() << " = " << 30 << "," << 50 << endl;
  //  else if(P1.Сomparison(30, 50)==1) cout << P1.getRub() << "," << P1.getKopeck() << " > " << 30 << "," << 50 << endl;
  //  else if(P1.Сomparison(30, 50) == 2) cout << P1.getRub() << "," << P1.getKopeck() << " < " << 30 << "," << 50 << endl;
    P1.getBalance();
    system("pause");
    return 0;
}
