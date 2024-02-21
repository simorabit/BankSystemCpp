#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsTransactionScreen.h"
#include "clsFindClientScreen.h"
#include "clsManageUsers.h"
using namespace std;
//g++ -std=c++11 mainBankSystem.cpp
class clsMainScreen : protected clsScreen
{

private:
    enum enMainMenueOptions
    {
        eListClients = 1,
        eAddNewClient = 2,
        eDeleteClient = 3,
        eUpdateClient = 4,
        eFindClient = 5,
        eShowTransactionsMenue = 6,
        eManageUsers = 7,
        eExit = 8
    };

    static short _ReadMainMenueOption()
    {
        cout << setw(37) << left << ""
             << "Choose what do you want to do? [1 to 8]? ";
        short Choice = clsInputValidate::ReadIntNumberBetween(1, 8, "Enter Number between 1 to 8? ");
        return Choice;
    }

    static void _GoBackToMainMenue()
    {
        cout << setw(37) << left << ""
             << "\n\tPress any key to go back to Main Menue...\n";
        std::cin.ignore();
        std::cin.get();
        ShowMainMenue();
    }

    static void _ShowAllClientsScreen()
    {
        clsClientListScreen::ShowClientsList();
    }

    static void _ShowAddNewClientsScreen()
    {
        clsAddNewClientScreen::ShowAddNewClientScreen();
    }

    static void _ShowDeleteClientScreen()
    {
        clsDeleteClientScreen::ShowDeleteClientScreen();   
    }

    static void _ShowUpdateClientScreen()
    {
        clsUpdateClientScreen::ShowUpdateClientScreen();
    }

    static void _ShowFindClientScreen()
    {
        clsFindClientScreen::ShowFindClientScreen();
    }

    static void _ShowTransactionsMenue()
    {
        clsTransactionsScreen::ShowTransactionsMenue();
    }

    static void _ShowManageUsersMenue()
    {
        clsManageUsersScreen::ShowManageUsersMenue();
    }

    static void _ShowEndScreen()
    {
        cout << "\nEnd Screen Will be here...\n";
    }

    static void _PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
    {
        switch (MainMenueOption)
        {
        case enMainMenueOptions::eListClients:
        {
            system("clear");
            _ShowAllClientsScreen();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOptions::eAddNewClient:
            system("clear");
            _ShowAddNewClientsScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eDeleteClient:
            system("clear");
            _ShowDeleteClientScreen();
            _GoBackToMainMenue();
            break;
        case enMainMenueOptions::eUpdateClient:
            system("clear");
            _ShowUpdateClientScreen();
            _GoBackToMainMenue();
            break;
        case enMainMenueOptions::eFindClient:
            system("clear");
            _ShowFindClientScreen();
            _GoBackToMainMenue();
            break;
        case enMainMenueOptions::eShowTransactionsMenue:
           system("clear");
            _ShowTransactionsMenue();
            break;
        case enMainMenueOptions::eManageUsers:
            system("clear");
            _ShowManageUsersMenue();
            break;
        case enMainMenueOptions::eExit:
            system("clear");
            _ShowEndScreen();
            break;
        }
    }

public:
    static void ShowMainMenue()
    {

        system("clear");
        _DrawScreenHeader("\t\tMain Screen");

        cout << setw(37) << left << ""
             << "===========================================\n";
        cout << setw(37) << left << ""
             << "\t\t\tMain Menue\n";
        cout << setw(37) << left << ""
             << "===========================================\n";
        cout << setw(37) << left << ""
             << "\t[1] Show Client List.\n";
        cout << setw(37) << left << ""
             << "\t[2] Add New Client.\n";
        cout << setw(37) << left << ""
             << "\t[3] Delete Client.\n";
        cout << setw(37) << left << ""
             << "\t[4] Update Client Info.\n";
        cout << setw(37) << left << ""
             << "\t[5] Find Client.\n";
        cout << setw(37) << left << ""
             << "\t[6] Transactions.\n";
        cout << setw(37) << left << ""
             << "\t[7] Manage Users.\n";
        cout << setw(37) << left << ""
             << "\t[8] Logout.\n";
        cout << setw(37) << left << ""
             << "===========================================\n";
        _PerfromMainMenueOption((enMainMenueOptions)_ReadMainMenueOption());
    }
};
