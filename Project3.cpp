#include "Project3.h"
using namespace std;

// Global Variables
vector<Account> accounts;
int Account::nextAccNum = 1000; //initializing the static variable to a 1000

// Functions
void printOptions()
{
    //Printing all options
    cout << "\n";
    cout << "+-----------------------------------------------+" << endl;
    cout << "| 1.\tOpen new account                        |" << endl;
    cout << "| 2.\tDeposit into account                    |" << endl;
    cout << "| 3.\tWithdraw from account                   |" << endl;
    cout << "| 4.\tFast transfer $40 into account          |" << endl;
    cout << "| 5.\tPrint a list of all accounts            |" << endl;
    cout << "| 6.\tEnd transaction (exit)                  |" << endl;
    cout << "+-----------------------------------------------+" << endl;
}

// Formating Function For Account Listing
void addSpaces(int numSpaces)
{
    // Function will output spaces only if the name is withing a certain length, otherwise there is no point in formating
    if (numSpaces > 0)
    {
        for (int i = 0; i < numSpaces; i++)
        {
            cout << " ";
        }
    }

    else
    {
        return;
    }
}

void openAccount()
{
    //User Input Variables
    string accName;
    float initDeposit;

    //Ignoring \n character in the buffer to avoid prompt skipping
    cin.ignore();
    cout << "Enter customer account name: ";
    getline(cin, accName);
    cout << "Enter initial deposit amount: $";
    cin >> initDeposit;

    //Checking initial deposit amount
    if(initDeposit < 0) {
        cout << "Error: Invalid deposit amount. Operation failed." << endl;
        return;
    }

    //Creating new instance(object) of the Account Class
    Account newCustomer = Account(accName, initDeposit);

    // Formating float output to 2 decimals
    cout << fixed << setprecision(2);
    cout << "Account openend: " << newCustomer.getAccNum() << " " << newCustomer.getAccName() << ": $" << newCustomer.getAccBalance();

    // Storing account into our "database"(vector) of created accounts
    accounts.push_back(newCustomer);
}

void makeDeposit()
{
    //User Input Variables
    int num;
    float amount;

    cout << "Enter account number: ";
    cin >> num;

    // Searching for account number inside vector
    for (vector<Account>::size_type i = 0; i < accounts.size(); i++)
    {
        //Checking whether the vector's element private variable accNum is equal to the searched account number
        if (accounts[i].getAccNum() == num)
        {
            cout << "Enter deposit amount: ";
            cin >> amount;

            //Checking the deposit amount
            if(amount < 0) {
                cout << "Error: Invalid deposit amount. Operation failed." << endl;
                return;
            }

            //Mutating accBalance variable if the condition is true.
            accounts[i].setAccBalance((accounts[i].getAccBalance() + amount));

            //Formating float output to 2 decimals
            cout << "Deposit accpeted for account " << accounts[i].getAccNum() << " : $" << fixed << setprecision(2) << accounts[i].getAccBalance() << endl;
            //Interrupting the function after successful deposit transaction
            return;
        }
    }
    //If the loop completed successfully, informing user that the account was not found
    cout << "Error: Account number not found. Operation failed.";
}

void makeWithdrawal()
{
    //User Input Variables
    int num;
    string name;
    float amount;

    cout << "Enter account number: ";
    cin >> num;
    cin.ignore();

    cout << "Enter account name for security purpose: ";
    getline(cin, name);

    for (vector<Account>::size_type i = 0; i < accounts.size(); i++)
    {
        //Checking whether the vector's element private variable accNum is equal to the search account number
        if (accounts[i].getAccNum() == num && accounts[i].getAccName() == name)
        {
            cout << "Enter withdrawal amount: $ ";
            cin >> amount;
            
            //Checking whether the difference of vector's private variable accBalance and user input is greater than or equal to zero
            if((accounts[i].getAccBalance() - amount) >= 0 and amount > 0) {
                //If the condition is true, mutating private variable accBalance
                accounts[i].setAccBalance((accounts[i].getAccBalance() - amount));

                // formating float output to 2 decimals
                cout << fixed << setprecision(2);
                cout << "Withdrawal processed for account " << accounts[i].getAccNum() << " : " << accounts[i].getAccBalance() << endl;
                //Interrupting function
                return;
            }

            //if the condition is false, informing user that there is not enough money on the balance
            else {
                cout << "Erro: Insufficient funds. Operation failed.";
                //Interrupting function
                return;
            }
        }
    }

    //If the loop completed successfully, informing user that the account was not found
    cout << "Error: Account number and name do not match or account not found.";
    cout << "Access denied.";
}

void fastTransfer() {
    int source;
    int destination;
    int sourceId;
    int destinationId;

    //User Prompt
    cout << "\n$40 Fast Transfer: source -> destination" << endl;
    cout << "Enter source account number: ";
    cin >> source;
    cout << "Enter destination account number: ";
    cin >> destination;

    //Ensuring that user didn't enter the same account numbers
    if(source == destination) {
        cout << "Error: Unable to transfer money from the account to itself. Operation failed." << endl;
        return;
    }

    try {
        //Verifying the existance of both accounts
        accounts.at(source - 1000);
        accounts.at(destination - 1000);
        //Storing the accounts
        sourceId = source - 1000;
        destinationId = destination - 1000;

    }
    //If the ".at" function throws exception, we consider that the account is not found.
    catch(const out_of_range& e) {
        cout << "Error: source or destination account number not found. Operation failed." << endl;
        return;
    }

    //Informing user about insufficient amount, if it is a case.
    if(accounts[sourceId].getAccBalance() < 40) {
        cout << "Error: Insufficient funds. Operation failed.";
        return;
    }

    //If everything is ok, changing balance on both accounts
    accounts[sourceId].setAccBalance(accounts[sourceId].getAccBalance() - 40);
    accounts[destinationId].setAccBalance(accounts[destinationId].getAccBalance() + 40);
    //Informing user 
    cout << "$40 Fast Transfer processed: " << accounts[destinationId].getAccNum() << " -> " << accounts[sourceId].getAccNum() << endl;

}

void printAccounts()
{
    //Ensuring that there is at least one account in the vector
    if (accounts.size() > 0)
    {
        //Static part of the table
        cout << "+-----------------------------------------------+" << endl;
        cout << "| Account number | Name\t\t| Balance\t|" << endl;
        cout << "+-----------------------------------------------+" << endl;

        //Iterating over each account in the vector
        for (vector<Account>::size_type i = 0; i < accounts.size(); i++)
        {
            //Outputing current vector's element info
            cout << "|           " << accounts[i].getAccNum() << " | " << accounts[i].getAccName();
            // Adding a certain amount of spaces based on the length of the account name
            addSpaces((12 - accounts[i].getAccName().length()));
            cout << " | $ " << fixed << setprecision(2) << accounts[i].getAccBalance();
            // Adding a certain amount of spaces based on the length of the account balance casted to a string
            addSpaces((16 - to_string(accounts[i].getAccBalance()).length()));
            cout << "|" << endl;
        }

        //Static part of the table
        cout << "+-----------------------------------------------+" << endl;
    }

    else {
        //If there are no accounts, informing user
        cout << "The accounts list is empty.";
    }
}

int main()
{
    //Header
    cout << "+-------------------------------------------------+" << endl;
    cout << "|         Computer Science and Engineering        |" << endl;
    cout << "|        CSCE 1040 - Computer Programming II      |" << endl;
    cout << "|    Anzhel Pak   ap1847   anzhelpak@my.unt.edu   |" << endl;
    cout << "+-------------------------------------------------+" << endl;

    int choice = 0;

    // User Interactive Interface Iterative Logic
    while (true)
    {
        printOptions();
        cin >> choice;

        //Using switch-case in order to achive menu prompt functionality
        switch (choice)
        {
        case 1:
            openAccount();
            continue; //Instead of exiting the loop we go back to the beginning
        case 2:
            makeDeposit();
            continue;
        case 3:
            makeWithdrawal();
            continue;
        case 4:
            fastTransfer();
            continue;
        case 5:
            printAccounts();
            continue;
        case 6:
            // exiting the Swtich-Case block
            cout << "Thank you for your business!" << endl;
            break;
        default:
            cout << "Invalid option, please try again." << endl;
            continue;
        }

        // Exiting the loop
        break;
    }

    return 0;
}