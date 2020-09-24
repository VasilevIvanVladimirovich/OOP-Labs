#include <iostream>
using namespace std;

class Money  {
public:

    Money() { cout << "Конструктор Money " << this << endl; }

    ~Money() { cout << "деструктор Money " << this << endl; }

    int GetRub()
    {
        return rub_;
    }
    int GetKopeck()
    {
        return kopeck_;
    }

    void SetBalance(int64_t rub, uint8_t kopeck)
    {
        rub_ = rub;
        kopeck_ = kopeck;
    }
    void SetRub(int64_t rub)
    {
        rub = rub_;
    }
    void SetKopeck(uint8_t kopeck)
    {
        kopeck = kopeck_;
    }

    void Rouding()
    {
        if(kopeck_ >= 100)
        {
        rub_ = rub_ + kopeck_ / 100;
        kopeck_ %= 100;
        }
    }

    void OperationSum(int64_t rub, uint8_t kopeck)
    {
        rub_ += rub;
        kopeck_ += kopeck;
        Rouding();
    }
    void OperationMinus(int64_t rub, uint8_t kopeck)
    {
        rub_ -=  rub;
        if (kopeck_ - kopeck < 0)
        {
            if (rub_ - 1 < 0)
            {
                cout << "Нас счёте недостаточно средств" << endl;
            }else rub_ -= 1;
            kopeck_ = kopeck - kopeck_;
        }else kopeck_ -= kopeck;
   
    }
    void OperationDivision(int64_t divider)
    {
        rub_ /= divider;
        kopeck_ /= divider;
        if (divider <= 0) cout << "Ошибка" << endl;
    }
    void OperationMultiplication(int64_t multiplier)
    {
        if (kopeck_ * multiplier > 255)
        {
            rub_ *= multiplier;
            int kopeck;
            kopeck = kopeck_ * multiplier;
            rub_ = rub_ + kopeck / 100;
            kopeck_ = kopeck % 100;
        }
        else
        {
        rub_ *= multiplier;
        kopeck_ *= multiplier;
        Rouding();
        }

    }
    void OperationСomparison(int64_t rub, uint8_t kopeck)
    {
        if (rub_ == rub && kopeck_ == kopeck)
        {
            cout << rub_ << "," << (int)kopeck_ << " = " << rub << "," << (int)kopeck << endl;
            return;
        }
        if (rub_ > rub ) 
        {
            cout << rub_ << "," << (int)kopeck_ << " > "<<rub << "," << (int)kopeck << endl;
            return;
        }
        if (rub_ < rub ) 
        {
            cout << rub_ << "," << (int)kopeck_ << " < " << rub << "," << (int)kopeck << endl;
            return;
        }
        if (kopeck_ > kopeck) 
        {
            cout << rub_ << "," << (int)kopeck_ << " > " << rub << "," << (int)kopeck << endl;
            return;
        }
        if (kopeck_ < kopeck) 
        {
            cout << rub_ << "," << (int)kopeck_ << " < " << rub << "," << (int)kopeck << endl;
            return;
        }
    }
   
protected:
    int64_t rub_;
    uint8_t kopeck_;
};


class Person : public Money{
public:

    Person() :Money(){ cout << "Конструктор Person " << this << endl; }
    ~Person() { cout << "деструктор Person " << this << endl; }
   
    void GetBalance()
    {
        cout << "Balance = " << rub_ << "," << (int)kopeck_ << endl;
    }

private:
    string FirstName_;
    string LastName_;
};
int main()
{
    setlocale(LC_ALL, "rus");
    Person P1,P2;
    P1.SetBalance(50, 50);
    P2.SetBalance(30, 5);
    P1.OperationSum(P2.GetRub(), P2.GetKopeck());
    P1.OperationMinus(P2.GetRub(), P2.GetKopeck());
    P1.OperationDivision(3);
    P2.OperationDivision(3);
    P1.OperationMultiplication(50);
    P2.OperationMultiplication(50);
    P1.OperationСomparison(P2.GetRub(), P2.GetKopeck());
    P1.GetBalance();
    P2.GetBalance();
    system("pause");
    return 0;
}
