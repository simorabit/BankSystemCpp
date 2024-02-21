#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsDepositScreen : protected clsScreen
{

private:
    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.GetFirstName();
        cout << "\nLastName    : " << Client.GetLastName();
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.GetEmail();
        cout << "\nPhone       : " << Client.GetPhone();
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nPassword    : " << Client.GetPinCode();
        cout << "\nBalance     : " << Client.GetAccountBalance();
        cout << "\n___________________\n";
    }

    static string ReadAccountNumber()
    {
        string accountNumber = "";
        cout << "\nPlease enter account number";
        cin >> accountNumber;
        return accountNumber;
    }
public:
    static void ShowDepositScreen()
    {
        _DrawScreenHeader("\t Deposit screen");
        string accountNum = ReadAccountNumber();
        while(!clsBankClient::IsClientExist(accountNum))
        {
            cout << "\n Client with [" << accountNum <<"] does not exist";
            accountNum = ReadAccountNumber();
        }
        clsBankClient client = clsBankClient::Find(accountNum);
        _PrintClient(client);
        double amount = 0;
        cout << "\nPlease enter deposit amount?";
        amount = clsInputValidate::ReadDblNumber();
        cout << "\nAre you sure you want to deposit this amount";
        char answer = 'n';
        cin >> answer;
        if(answer == 'y' || answer == 'Y')
        {
            client.Deposit(amount);
                 cout << "\nAmount Deposited Successfully.\n";
            cout << "\nNew Balance Is: " << client.GetAccountBalance();
        }
        else
        {
            cout << "\nOperation was cancelled.\n";
        }
    }    
};