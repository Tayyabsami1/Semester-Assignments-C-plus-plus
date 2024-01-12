#include <iostream>
#include <cstring>

using namespace std;

int accountsOpen = -1;

class SavingAccount
{
    // Member Variables
    char *name;
    float annualInterestRate;
    double savingBalance;

    char *accountNum;

public:
    // Constructor
    SavingAccount()
    {
        this->name = new char[1];
        name[0] = '\0';

        this->annualInterestRate = 0.0;
        this->savingBalance = 0.0;
    }

    // Getter and Setters

    void setInterestRate(float I)
    {
        this->annualInterestRate = I;
    }

    float getInterestRate()
    {
        return this->annualInterestRate;
    }

    void setBalance(double B)
    {
        this->savingBalance = B;
    }

    double getBalance()
    {
        return this->savingBalance;
    }

    char *getName()
    {
        return this->name;
    }

    void setName(char *name2)
    {
        this->name = name2;
    }

    char *getAccountNum()
    {
        return accountNum;
    }

    void setAccountNum(int n)
    {
        this->accountNum = new char[5];
        accountNum[0] = 'S';
        accountNum[1] = 'A';
        accountNum[2] = (n / 10) + 48;
        accountNum[3] = (n % 10) + 48;
        accountNum[4] = '\0';
    }
};

/*
 Open the Account of the Customer and setting its name and Balance and giving it a Account id 
in the constructor 
*/
void OpenCustomerAccount(SavingAccount *savers[], int AccountsOpen, char *NameVal, double balance)
{
    AccountsOpen = accountsOpen + 1;
    savers[AccountsOpen] = new SavingAccount();

    savers[AccountsOpen]->setAccountNum(accountsOpen);

    savers[AccountsOpen]->setName(NameVal);
    savers[AccountsOpen]->setBalance(balance);

    accountsOpen++;
}

float calculateMonthlyInterest(SavingAccount *saver)
{
     if ((accountsOpen) < 0)
    {
        cout << "No account is opened yet " << endl;
        return 0.0;
    }
    double B = saver[accountsOpen].getBalance();
    float I = saver[accountsOpen].getInterestRate();

    float MI = (B) * (I / 12);

    return MI;
}

void modifyInterestRate(SavingAccount *saver, float newValue)
{
    if ((accountsOpen) < 0)
    {
        cout << "No account is opened yet " << endl;
        return;
    }

    saver[accountsOpen].setInterestRate(newValue);
}
// Searching the customer with the required account number and returning its index 
int SearchCustomer(SavingAccount *savers[], int accountsOpen, char *accountNum)
{
    for (int i = 0; i < accountsOpen; i++)
    {
        char *A = savers[i]->getAccountNum();
        if (A = accountNum)
        {
            return i;
        }
    }

    return -1;
}

bool UpdateAccountBalance (SavingAccount * savers[], int accountsOpen, char 
*accountNumVal, double balanceVal)
{
    savers[accountsOpen]->setBalance(balanceVal);

    return true;
}

int main()
{
    // SavingAccount *savers[100];

    // char ptr[100];
    // cin.get(ptr, 100);

    // OpenCustomerAccount(savers, accountsOpen, ptr, 1000);

    // char *A1 = savers[accountsOpen]->getAccountNum();

    // modifyInterestRate(savers[accountsOpen], 454);

    // UpdateAccountBalance(savers,accountsOpen,A1,5000);

    return 0;
}