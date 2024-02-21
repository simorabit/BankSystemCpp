#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
class clsUpdateClientScreen : protected clsScreen
{
private:
    static void PrintClient(clsBankClient Client)
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
    static void ReadClientInfo(clsBankClient client)
    {
        cout << "\nEnter FirstName: ";
        client.SetFirstName(clsInputValidate::ReadString());
        cout << "\nEnter LastName: ";
        client.SetLastName(clsInputValidate::ReadString());
        cout << "\nEnter Email: ";
        client.SetEmail(clsInputValidate::ReadString());
        cout << "\nEnter Phone: ";
        client.SetPhone(clsInputValidate::ReadString());
        cout << "\nEnter PinCode: ";
        client.SetPinCode(clsInputValidate::ReadString());
        cout << "\nEnter Account Balance: ";
        client.SetAccountBalance(clsInputValidate::ReadFloatNumber());
    }

public:
    static void ShowUpdateClientScreen()
    {
        _DrawScreenHeader("\tUpdate Client Screen");
        string accountNumber = "";
        cout << "\nPlease enter Account Number ";
        accountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(accountNumber))
        {
            cout << "\nClient Not Found, Enter again. ";
            accountNumber = clsInputValidate::ReadString();
        }
        clsBankClient client2 = clsBankClient::Find(accountNumber);
        PrintClient(client2);

        cout << "\nAre you sure you want to update this client y/n? ";

        char Answer = 'n';
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            cout << "\n\n Update Client Info";
            cout << "\n____________________\n";
            ReadClientInfo(client2);
            clsBankClient::enSaveResults saveRes;
            saveRes = client2.Save();
            switch (saveRes)
            {
            case clsBankClient::enSaveResults::svSucceeded:
            {
                cout << "\nAccount updated successfully";
                PrintClient(client2);
                break;
            }
            case clsBankClient::enSaveResults::svFaildEmptyObject:
            {
                cout << "\nError account was not saved";
                break;
            }
            }
        }
    }
};