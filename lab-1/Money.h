#pragma once

using namespace std;

class Money {
public:

    Money(int64_t rub, uint8_t kopeck);

    ~Money(); 

    int getRub();

    int getKopeck();
   
    void setBalance(int64_t rub, uint8_t kopeck);
  
    void setRub(int64_t rub);

    void setKopeck(uint8_t kopeck);

    void rounding();
 
    void operationSum(int64_t rub, uint8_t kopeck);

    void operationMinus(int64_t rub, uint8_t kopeck);
   
    void operationDivision(int64_t divider);
  
    void operationMultiplication(int64_t multiplier);

    int operationСomparison(int64_t rub, uint8_t kopeck);

private:
    int64_t rub_;
    uint8_t kopeck_;
};
