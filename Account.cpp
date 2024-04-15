#include "Account.h"

using namespace std;

//Default constructor
Account::Account() {
    accNum = nextAccNum++; //If the user doesn't input anything the account will still receive a number
    accName = "";
    accBalance = 1.0;
}

//Constructor Overload
Account::Account(string name, float balance) {
    accNum = nextAccNum++; //first account will receive a number of 1000
    accName = name;
    accBalance = balance;
}

//Destructor
Account::~Account() {}

//Accessors
int Account::getAccNum() {
    return accNum;
}

string Account::getAccName() {
    return accName;
}

float Account::getAccBalance() {
    return accBalance;
}

//Mutators
void Account::setAccNum(int num) {
    accNum = num;
}

void Account::setAccName(string name) {
    accName = name;
}

void Account::setAccBalance(float balance) {
    accBalance = balance;
}