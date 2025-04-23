/*
Amerike University
Author: Ali Angel
Work #: 23
Date: 22/04/25
Description: This program will act as a bank application that, through the use of classes and class functions 
makes it available to set an user, show the info of the bank account and alter the money stored in it.
*/

#include <iostream>
#include <conio.h>

void pressAnyKey();

class Bank
{
    private:
    std::string propietary;
    std::string acctType;
    double balance;
    bool savings = false;
    bool checking = false;
    bool payroll = false;

   

    public:
    void setPropietary(std::string name)
    {
        propietary = name;
    }
    std::string getPropietary()
    {
        return propietary;
    }
    void setAcctToSavings()
    {
        acctType = "Savings";
        savings = true;
    }
    void setAcctToChecking()
    {
        acctType = "Checking";
        checking = true;
    }
    void setAcctToPayroll()
    {
        acctType = "Payroll";
        payroll = true;
    }
    std::string getAcctType()
    {
        return acctType;
    }
    double getBalance()
    {
        return balance;
    }
    void setBalance(double usrBalance)
    {
        balance = usrBalance;
    }
    void makeDeposit(double depositAmount)
    {
        std::cout<<"You have deposited: $" << depositAmount << " to your " << getAcctType() << " account\n";
        balance = balance + depositAmount;
        consultBalance();
    }
    void makeWithdrawal(double withdrawalAmount)
    {
        if(balance-withdrawalAmount < 0 && checking !=true)
        {
            std::cout<<"Withdrawal exceeds available money in account, try with a different sum\n";
            consultBalance();
        }else if(savings == true || payroll == true)
            {
                std::cout<<"You have whitdrawn: $" << withdrawalAmount << " from your " << getAcctType() << " account\n";
                balance = balance - withdrawalAmount;
                consultBalance();
            }else
            {
                std::cout<<"You can't make a withdrawal on a Checking account\n";
                pressAnyKey();
            }
    }
    void consultBalance()
    {
        std::cout<<"The current balance in your "<< getAcctType() << " account is: $" << getBalance()<<"\n";
        pressAnyKey();
    }
    void getAcctInfo()
    {
        std::cout<<"This " << getAcctType() <<" account is registered under: " << getPropietary();
        std::cout<<"\n";
        pressAnyKey();
    }
};


int main()
{
    Bank firstAccount;
    Bank secondAccount;
    firstAccount.setPropietary("Juan Manuel Vicente");
    firstAccount.setBalance(0);
    firstAccount.setAcctToChecking();
    firstAccount.makeDeposit(1200);
    firstAccount.makeWithdrawal(500);
    firstAccount.makeDeposit(200);
    firstAccount.makeWithdrawal(5000);
    firstAccount.getAcctInfo();
    pressAnyKey();
    secondAccount.setPropietary("Pedro Esteban Lopez");
    secondAccount.setBalance(0);
    secondAccount.setAcctToPayroll();
    secondAccount.makeDeposit(1200);
    secondAccount.makeWithdrawal(500);
    secondAccount.makeDeposit(200);
    secondAccount.makeWithdrawal(5000);
    secondAccount.getAcctInfo();

    return 0;
}

void pressAnyKey()
{
    std::cout<<"PRESS ANY KEY TO CONTINUE";
    getch();
    system("cls");
}