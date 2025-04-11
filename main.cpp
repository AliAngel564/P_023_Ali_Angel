
#include <iostream>

class bank
{
    private:
    std::string propietary;
    std::string acctType;
    double balance;
    
    public:
    void setPropietary(std::string name)
    {
        propietary = name;
    }
    std::string getPropietary()
    {
        return propietary;
    }
    void setAcctType(std::string typeName,bool isAcctType)
    {
        acctType = typeName;
        isAcctType = true;
    }
    std::string getAcctType()
    {
        return acctType;
    }
    void setBalance(double usrBalance)
    {
        balance = usrBalance;
    }
    double getBalance()
    {
        return balance;
    }
    void makeDeposit(double depositAmount)
    {
        balance = balance + depositAmount;
    }
};


int main()
{


}