#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>

using namespace std;

class Account {
private:
    //account Number
    int accNum;
    //account Name
    string accName;
    //account Balance
    float accBalance;
public:
    //Next Available Account Number
    static int nextAccNum;

    //Constructor
    Account();

    //Constructor Overload
    Account(string name, float balance);
    
    //Destructor
    ~Account();
    
    //Public Accessors
    int getAccNum();
    string getAccName();
    float getAccBalance();

    //Public Mutators
    void setAccNum(int num);
    void setAccName(string name);
    void setAccBalance(float balance); 

};

#endif