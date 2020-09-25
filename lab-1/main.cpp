#include <iostream>
#include "Money.h"
#include "Person.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    Money M1(1,11);
    Person P1(M1);
    //M1.setBalance(99,99);
    //M1.operationSum(9,9);
    try
    {
        M1.operationMinus(90,10);
  //     M1.operationDivision(0);
    }
    catch (invalid_argument& e)
    {
        cerr << e.what() << endl;
        return -1;
    }
 // M1.operationDivision(3);
 // if (M1.operationСomparison(30, 50)==0) cout << M1.getRub() << "," << M1.getKopeck() << " = " << 30 << "," << 50 << endl;
//  else if(M1.operationСomparison(30, 50)==1) cout << M1.getRub() << "," << M1.getKopeck() << " > " << 30 << "," << 50 << endl;
//  else if(M1.operationСomparison(30, 50) == 2) cout << M1.getRub() << "," << M1.getKopeck() << " < " << 30 << "," << 50 << endl;

    P1.getBalance(M1);
    system("pause");
    return 0;
}
